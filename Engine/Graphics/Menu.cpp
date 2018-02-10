#include "Menu.h"

Menu::Menu(std::vector<Text2D> _texts, std::vector<void(*)()> _functions)
{
	texts = _texts;
	functions = _functions;
}

void Menu::AddEntry(Text2D text, void(*function)())
{
	texts.push_back(text);
	functions.push_back(function);
}
