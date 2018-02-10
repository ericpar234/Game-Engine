#ifndef EJF_ENGINE
#define EJF_ENGINE

#include "GLFW/glfw3.h"
#include "GL\freeglut.h"
#pragma comment(lib, "opengl32.lib")

#include <iostream>

using namespace std;


class Engine
{
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static float GetDT();
	Engine();
	~Engine();

	bool Initialize(char * windowTitle, int argc, char * argv[]);

	void Update();
	void BeginRender();
	void EndRender();

private:
	static GLFWwindow* window;
	static float dt;
	float lastTime;
};

#endif