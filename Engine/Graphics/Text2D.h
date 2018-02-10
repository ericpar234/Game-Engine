#ifndef EJF_TEXT2D
#define EJF_TEXT2D

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Math/Vector3.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Text2D
{
public:
	Text2D();
	Text2D(string imagePath);
	Text2D(string imagePath, Vector3 pos);

	void Update();
	void Render();

	void SpeedTo(float x);
	void SpeedBy(float x);

	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void RotateTo(float x);
	void RotateBy(float x);

	void SetScale(float x);
	void SetScale(Vector3 v);
	void SetString(string _string);

	Vector3* GetPos();
	float* GetRot();
	Vector3* GetScale();
	Vector3* GetSize();

private:
	Texture texture;

	float speed;

	Vector3 pos;
	float rot;
	Vector3 scale;
	Vector3 size;
	string str;

	std::vector<Vector3> verticies;
	std::vector<Vector3> UVs;

	float characterSpacing;

	void CalculateVectors();



};

#endif