#pragma once
#include "PianoButton.h"
#include <vector>
#include <string>

class Piano{
private:
	char keyArray[14] = {'A','S','D','F','J','K','L','Z','X','C','V','M',',','.'};
public:
	std::vector<PianoButton> MyButton;
	sf::Sprite getSprite(int i);
	Piano(int n, sf::RenderWindow & renderWindow);
	Piano(int n, std::string f1, std::string f2, std::string sf1, int X, int Y, sf::RenderWindow & renderWindow);
	
};