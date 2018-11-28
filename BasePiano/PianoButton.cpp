#define _CRT_SECURE_NO_WARNINGS
#include "PianoButton.h"
#include <iostream>
int PianoButton::widthSize;
void PianoButton::init()
{
	widthSize = 0;
}

sf::Sprite PianoButton::getSprite()
{
	return buttonSprite;
}

void PianoButton::setPosition(int X, int Y)
{
	static int widthSize = 0;
	buttonSprite.setPosition(X + widthSize, Y);
	widthSize += 63;
}
void PianoButton::setTexture(std::string s)
{
	if (s == "pressed")
		buttonSprite.setTexture(buttonTexture[1]);
	else
		buttonSprite.setTexture(buttonTexture[0]);
}


PianoButton::PianoButton(std::string f1, std::string f2, std::string sf1) : file(f1), file2(f2), soundFile(sf1)
{
	buttonImage[0].loadFromFile("images/" + file);
	buttonImage[1].loadFromFile("images/" + file2); //pressed
	buttonTexture[0].loadFromImage(buttonImage[0]);
	buttonTexture[1].loadFromImage(buttonImage[1]); //pressed
	this->setTexture("released");			//released as 

	/////converting from string to char array
	std::string s = "sounds/" + sf1 + ".wav";
	char * tab2 = new char[s.length() + 1];
	strcpy(tab2, s.c_str());
	
	sound = OpenSound(audioDevice, (tab2), false); //создаем поток для нашего звука
	if (!sound) {
		std::cout << "opening sound file error...";
		system("pause");
	}
}

void PianoButton::changeState() {
	this->state = !this->state;
}
void PianoButton::setButtonKey(char key) {
	this->buttonKey = key;
}
char PianoButton::getButtonKey(){
	return this->buttonKey;
}

bool PianoButton::getState() {
	return this->state;
}

void PianoButton::buttonPlay() {
	this->sound->play();
	this->setTexture("pressed");
	this->changeState();
}
void PianoButton::buttonStop() {
	this->sound->stop();
	this->setTexture("released");
	this->changeState();
}