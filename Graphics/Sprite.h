#ifndef EJF_SPRITE
#define EJF_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Math/Vector3.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3 pos);

	void Initialize(Vector3 v);

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

	Vector3* GetPos();
	float* GetRot();
	Vector3* GetScale();
	Vector3* GetSize();

	void SetPos(Vector3 _pos);

	int GetState();

	void SetState(int s);

	int PushTexture(string imagePath);

private:
	vector<Texture> textures;

	float speed;

	Vector3 pos;
	float rot;
	Vector3 scale;
	Vector3 size;

	int state;

};

#endif