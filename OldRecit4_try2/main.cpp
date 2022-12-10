#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

int main()
{
	if (!glfwInit())
		return -1;

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", NULL, NULL);

	if (!window) 
	{
		glfwTerminate(); 
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		cout << "Failed to initialize GLAD" << endl;
		return -1; 
	}

	const float positions[9] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	unsigned int buffer; //has to be unsigned
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
	glEnableVertexAttribArray(0);

	while (!glfwWindowShouldClose(window)) //runs until window is closed
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);//clear the prev image and put an background color based on your OS

		glDrawArrays(GL_TRIANGLES, 0, 3);//once enable vertex attribute pointer, we can call this func

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents(); 
	}

	glfwTerminate();



	return 0;
}