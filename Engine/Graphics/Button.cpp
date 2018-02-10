#include "Button.h"

#include "../IO/Mouse.h"
#include "../Engine.h"
#include "../Math/Rect.h"
//#include "../Engine.h"


//TODO: Make Rigidbody and Sprite children of Flapper
Button::Button()
{
}

Button::Button(Sprite _sprite, Text2D _text) : Button()
{
	sprite = _sprite;
	txt = _text;
}

void Button::Initialize(Vector3 _pos)
{
	sprite.Initialize(_pos);
	Rect boundingRect(*sprite.GetSize() * *sprite.GetScale());
	rb.Initialize(0, 0, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize(), boundingRect);
}

void Button::Update()
{
	float yTop = sprite.GetPos()->y + (sprite.GetSize()->y * sprite.GetScale()->y) / 2;
	float yBot = sprite.GetPos()->y - (sprite.GetSize()->y * sprite.GetScale()->y) / 2;
	float xTop = sprite.GetPos()->x + (sprite.GetSize()->x * sprite.GetScale()->x) / 2;
	float xBot = sprite.GetPos()->x - (sprite.GetSize()->x * sprite.GetScale()->x) / 2;

	pressed = false;
	pressedDown = false;
	pressedUp = false;
	if (Mouse::GetMouseX() >= xBot && Mouse::GetMouseX() <= xTop && Mouse::GetMouseY() >= yBot && Mouse::GetMouseY() <= yTop)
	{

		if (Mouse::Button(GLFW_MOUSE_BUTTON_LEFT))
		{

			pressed = true;
			if (pressedFunction != NULL)
			{
				pressedFunction();
			}
		}
		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
		{
			pressedDown = true;
			if (downFunction != NULL)
			{
				downFunction();
			}

		}
		if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_LEFT))
		{
			pressedUp = true;
			if (upFunction != NULL)
			{
				upFunction();
			}
		}
	}


	sprite.Update();
	txt.Update();
	rb.Update();
}

void Button::Render()
{
	sprite.Render();
	txt.Render();
	//rb.Render(Vector3(0, 0, 0));
}

void Button::SetPressedFunction(void(*_function)())
{
	pressedFunction = _function;
}

void Button::SetDownFunciton(void(*_function)())
{
	downFunction = _function;
}

void Button::SetUpFunciton(void(*_function)())
{
	upFunction = _function;
}

bool Button::GetPressedUp()
{
	return pressedUp;
}

bool Button::GetPressedDown()
{
	return pressedDown;
}

bool Button::GetPressed()
{
	return pressed;
}


Sprite& Button::GetSprite()
{
	return sprite;
}

Rigidbody& Button::GetRB()
{
	return rb;
}

Text2D& Button::GetText()
{
	return txt;
}