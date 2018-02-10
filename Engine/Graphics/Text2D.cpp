#include "Text2D.h"
#include "../Engine.h"

Text2D::Text2D()
{
	pos = Vector3(0);
	rot = 0;
	scale = Vector3(1);
	size = Vector3(0);
	speed = 100;
	texture = Texture();
	str = "Hello World";
}

Text2D::Text2D(std::string imagePath)
{
	texture = Texture(imagePath);
	pos = Vector3(0);
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetHeight(), 1);
	rot = 0;
	speed = 100;
	str = "Hello World";
	characterSpacing = 1;
}

Text2D::Text2D(string imagePath, Vector3 v)
{
	texture = Texture(imagePath);
	pos = v;
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetHeight(), 1);
	rot = 0;
	speed = 100;
	str = "Hello World";
	characterSpacing = 1;
}

void Text2D::Update()
{
}

void Text2D::Render()
{
	//for (unsigned int i = 0; i<LENGTH; i++) {
	float cntrOffst = str.size() / 2;
	for (int i = 0; i < str.size(); i++)
	{
		int in = str[i];
		int letter = 255 - in;
		float xCoord = (float)((15 - letter % 16));
		float yCoord = round((letter) / 16);

		float xCoord1 = xCoord / 16;
		float xCoord2 = (xCoord + .5) / 16;

		float yCoord1 = (yCoord) / 16;
		float yCoord2 = (yCoord + 1) / 16;


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture.GetID());
		glLoadIdentity();

		//TRANSLATE -> ROTATE -> SCALE

		glTranslatef(pos.x + ((i   - cntrOffst)* scale.x * characterSpacing * texture.GetWidth()/32), pos.y, 0);
		glRotatef(rot, 0, 0, 1);
		glScalef(scale.x, scale.y, 1);

		//glRotatef

		//Rendering
		glColor4f(.5, 1, 1, 1);
		glBegin(GL_QUADS);
		{
			glTexCoord2f(xCoord1, yCoord1);	glVertex2i(0, 0);
			glTexCoord2f(xCoord2, yCoord1);	glVertex2i(texture.GetWidth() / 32, 0);
			glTexCoord2f(xCoord2, yCoord2);	glVertex2i(texture.GetWidth() / 32, texture.GetHeight() / 16);
			glTexCoord2f(xCoord1, yCoord2);	glVertex2i(0, texture.GetHeight() / 16);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}

void Text2D::SpeedTo(float x)
{
	speed = x;
}

void Text2D::SpeedBy(float x)
{
	speed += x;
}
void Text2D::MoveTo(Vector3 v)
{
	pos = v;
}

void Text2D::MoveBy(Vector3 v)
{
	pos = pos + v * Engine::GetDT();
}

void Text2D::MoveLeft()
{
	pos = pos - Vector3((speed * Engine::GetDT()), 0, 0);
}
void Text2D::MoveRight()
{
	pos = pos + Vector3((speed * Engine::GetDT()), 0, 0);
}
void Text2D::MoveUp()
{
	pos = pos + Vector3(0, (speed * Engine::GetDT()), 0);
}
void Text2D::MoveDown()
{
	pos = pos - Vector3(0, (speed * Engine::GetDT()), 0);

}

void Text2D::RotateTo(float x)
{
	rot = x;
}

void Text2D::RotateBy(float x)
{
	rot = rot + x * Engine::GetDT();
}

void Text2D::SetScale(float x)
{
	scale = Vector3(x);
}

void Text2D::SetScale(Vector3 v)
{
	scale = v;
}

void Text2D::SetString(string _string)
{
	str = _string;
}

Vector3* Text2D::GetPos()
{
	return &pos;
}
float* Text2D::GetRot()
{
	return &rot;
}
Vector3* Text2D::GetScale()
{
	return &scale;
}
Vector3* Text2D::GetSize()
{
	return &size;
}

void Text2D::CalculateVectors()
{

}

