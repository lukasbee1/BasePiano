#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "audiere.h"
class PianoButton
{
private:
	std::string soundFile;
	std::string file;
	std::string file2;
	sf::Image buttonImage[2];
	sf::Texture buttonTexture[2];
	sf::Sprite buttonSprite;
	static int widthSize;
	bool state = false;
	char buttonKey;
	
	audiere::AudioDevicePtr audioDevice = audiere::OpenDevice(); //Для начала нужно открыть AudioDevice 
	audiere::OutputStreamPtr sound;

public:
	static void init();
	sf::Sprite getSprite();

	void setPosition(int X, int Y);

	void setTexture(std::string s);

	PianoButton(std::string f1, std::string f2, std::string sf1);

	void changeState();
	void setButtonKey(char key);
	char getButtonKey();
	bool getState();
	void buttonPlay();
	void buttonStop();
};