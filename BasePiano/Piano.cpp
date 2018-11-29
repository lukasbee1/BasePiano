#include "Piano.h"

sf::Sprite Piano::getSprite(int i)
{
	return MyButton[i].getSprite();
}

Piano::Piano(int n, sf::RenderWindow & renderWindow)
{
	MyButton.reserve(n);
	
	for (int i = 0; i < n; i++)
	{

		MyButton.push_back(PianoButton(("pianoNum" + std::to_string(i + 1) + ".jpg"), ("pianoPressedNum" + std::to_string(i + 1) + ".jpg"), ("noty-" + std::to_string(i + 1))));
		MyButton[i].setPosition(150, 668);
		MyButton[i].setButtonKey(keyArray[i]);

	}
	for (int i = 0; i < n; i++) {
		this->MyButton[i].setTexture("released");
		renderWindow.draw(this->getSprite(i));
	}
}

// You should to name your textures as 'file + 1,2,3,...., n + .jpg' and enter X,Y positions
Piano::Piano(int n, std::string f1, std::string f2, std::string sf1, int X, int Y, sf::RenderWindow & renderWindow)
{
	MyButton.reserve(n);
	for (int i = 0, j = 0; j < n; i++, j++)
	{
		if (i > 6) i = 0;
		MyButton.push_back(PianoButton((f1 + std::to_string(i + 1) + ".jpg"), (f2 + std::to_string(i + 1) + ".jpg"), (sf1 + std::to_string(i + 1))));
		MyButton[j].setPosition(X, Y);
		MyButton[j].setButtonKey(keyArray[j]);
	}



	for (int i = 0; i < n; i++) {
		this->MyButton[i].setTexture("released");
		renderWindow.draw(this->getSprite(i));

	}
	renderWindow.display();
}

void Piano::buttonPlay(int i) {
	MyButton[i]->buttonSound.play();
}