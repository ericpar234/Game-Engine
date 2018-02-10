#include "Sprite.h"
#include "../Engine.h"

Sprite::Sprite()
{
	state = 0;
	pos = Vector3(0);
	rot = 0;
	scale = Vector3(1);
	size = Vector3(0);
	speed = 100;
	textures.push_back(Texture());


}

Sprite::Sprite(string imagePath)
{
	state = 0;
	textures.push_back(Texture(imagePath));
	pos = Vector3(0);
	scale = Vector3(1);
	size = Vector3((float)textures[state].GetWidth(), (float)textures[state].GetHeight(), 1);
	rot = 0;
	speed = 100;
}

Sprite::Sprite(string imagePath, Vector3 v)
{
	textures.push_back(Texture(imagePath));
	Initialize(v);
}

void Sprite::Initialize(Vector3 v)
{
	state = 0;
	pos = v;
	scale = Vector3(1);
	size = Vector3((float)textures[state].GetWidth(), (float)textures[state].GetHeight(), 1);
	rot = 0;
	speed = 100;
}


void Sprite::Update()
{
}

void Sprite::Render()
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[state].GetID());
	glLoadIdentity();

	//TRANSLATE -> ROTATE -> SCALE
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);
	//glRotatef
	//glasdfasd

	//Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0);	glVertex2i(-textures[state].GetWidth()/2, -textures[state].GetHeight()/ 2);
		glTexCoord2f(1, 0);	glVertex2i(textures[state].GetWidth()/2, -textures[state].GetHeight() / 2);
		glTexCoord2f(1, 1);	glVertex2i(textures[state].GetWidth()/2, textures[state].GetHeight() / 2);
		glTexCoord2f(0, 1);	glVertex2i(-textures[state].GetWidth() / 2, textures[state].GetHeight() / 2);
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::SpeedTo(float x)
{
	speed = x;
}

void Sprite::SpeedBy(float x)
{
	speed += x;
}
void Sprite::MoveTo(Vector3 v)
{
	pos = v;
}

void Sprite::MoveBy(Vector3 v)
{
	pos = pos + v * Engine::GetDT();
}

void Sprite::MoveLeft()
{
	pos = pos - Vector3((speed * Engine::GetDT()), 0, 0);
}
void Sprite::MoveRight()
{
	pos = pos + Vector3((speed * Engine::GetDT()), 0, 0);
}
void Sprite::MoveUp()
{
	pos = pos + Vector3(0, (speed * Engine::GetDT()), 0);
}
void Sprite::MoveDown()
{
	pos = pos - Vector3(0, (speed * Engine::GetDT()), 0);

}

void Sprite::RotateTo(float x)
{
	rot = x;
}

void Sprite::RotateBy(float x)
{
	rot = rot + x * Engine::GetDT();
}

void Sprite::SetScale(float x)
{
	scale = Vector3(x);
}

void Sprite::SetScale(Vector3 v)
{
	scale = v;
}

Vector3* Sprite::GetPos()
{
	return &pos;
}
float* Sprite::GetRot()
{
	return &rot;
}
Vector3* Sprite::GetScale()
{
	return &scale;
}
Vector3* Sprite::GetSize()
{
	return &size;
}
void Sprite::SetPos(Vector3 _pos)
{
	pos = _pos;
}
int Sprite::GetState()
{
	return state;
}
void Sprite::SetState(int s)
{
	state = s;
}

int Sprite::PushTexture(string imagePath)
{
	textures.push_back(Texture(imagePath));
}