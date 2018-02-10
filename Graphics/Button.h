#ifndef EJF_BUTTON
#define EJF_BUTTON

#include "Sprite.h"
#include "../Physics/Rigidbody.h"

#include "Text2D.h"


class Button
{
public:
	Button();
	Button(Sprite _sprite, Text2D _text);

	void Initialize(Vector3 v);

	void Update();
	void Render();

	void SetPressedFunction(void(*_function)());
	void SetDownFunciton(void(*_function)());
	void SetUpFunciton(void(*_function)());

	bool GetPressedUp();
	bool GetPressedDown();
	bool GetPressed();

	Sprite& GetSprite();
	Rigidbody& GetRB();
	Text2D& GetText();


private:

	Sprite sprite;
	Rigidbody rb;
	Text2D txt;

	bool pressed;
	bool pressedDown; //Only when pressed down for first time
	bool pressedUp; //When released;

	void(*pressedFunction)();
	void(*downFunction)();
	void(*upFunction)();
};

#endif