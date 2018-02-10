#include "Engine.h"
#include "IO\Mouse.h"
#include "IO\Keyboard.h"


int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = NULL;
float Engine::dt = 0;

Engine::Engine()
{


}

Engine::~Engine()
{

}



bool Engine::Initialize(char* windowTitle, int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);



	if (!glfwInit())
	{
		cout << "Error Initizlizing GLFW" << endl;
		return false;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);

	if (window == NULL)
	{
		cout << "Error Creating Window" << endl;
		return false;
	}


	//OpenGL Setup
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);
	

	glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
	glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);

	glfwSetKeyCallback(window, Keyboard::KeyCallback);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCREEN_WIDTH) / 2;
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	//GL Setup
	//viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);

	//Alpha Blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	lastTime = (float)glfwGetTime();

	return true;
}

void Engine::Update()
{
	float now = (float)glfwGetTime();
	dt = (now - lastTime);
	lastTime = now;
	glfwPollEvents();
}

void Engine::BeginRender()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Draw Here

}

void Engine::EndRender()
{
	//glutMainLoop();
	glfwSwapBuffers(window);
}

float Engine::GetDT()
{
	return dt;
}