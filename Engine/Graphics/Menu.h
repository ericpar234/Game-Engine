#ifndef EJF_MENU
#define EJF_MENU
#include "../Math/Vector3.h"
#include "Text2D.h"
#include "Sprite.h"
#include <vector>




class Menu
{
public:
	Menu();
	Menu(std::vector<Text2D> _texts, std::vector<void(*)()> _functions);

	void AddEntry(Text2D text, void(*function)());




private:
	Vector3 pos;
	float ySpacing;
	std::vector<Text2D> texts;
	std::vector<void(*)()> functions;
	





};




#endif 
