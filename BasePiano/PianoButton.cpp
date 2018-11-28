#include "PianoButton.h"

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


PianoButton::PianoButton(std::string f1, std::string f2, std::string bf1) : file(f1), file2(f2), soundFile(bf1)
{
	buttonImage[0].loadFromFile("images/" + file);
	buttonImage[1].loadFromFile("images/" + file2); //pressed
	
	soundBuffer.loadFromFile("sounds/" + soundFile + ".wav");
	buttonSound.setBuffer(soundBuffer);	
	buttonTexture[0].loadFromImage(buttonImage[0]);
	buttonTexture[1].loadFromImage(buttonImage[1]); //pressed
	this->setTexture("released");			//released as 

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
	buttonSound.setBuffer(soundBuffer);
	buttonSound.play();
	this->setTexture("pressed");
	this->changeState();
}
void PianoButton::buttonStop() {
	buttonSound.setBuffer(soundBuffer);
	buttonSound.stop();
	this->setTexture("released");
	this->changeState();
}