#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class PianoButton
{
private:
	std::string soundFile;
	std::string file;
	std::string file2;
	sf::Image buttonImage[2];
	sf::Texture buttonTexture[2];
	sf::Sprite buttonSprite;
	sf::SoundBuffer soundBuffer;
	sf::Sound buttonSound;
	static int widthSize;
	char buttonKey;



public:
	static void init();
	sf::Sprite getSprite();

	void setPosition(int X, int Y);

	void setTexture(std::string s);

	PianoButton(std::string f1, std::string f2, std::string sf1);

	void setButtonKey(char key);
	char getButtonKey();
	void buttonPlay();
	void buttonStop();
	bool buttonStatus();
};