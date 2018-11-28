/**
 * Course work
 *
 * Piano emulator
 *
 *
 * @author Lukashevich Maksim
 *
 * begin    - 8 November 2018
 * end      - ..... before 25 december
 *
 **/
#include "Piano.h"
#include "iostream"


using namespace sf;
//using namespace audiere;
using std::string;
const short COUNT_OF_KEYS = 7;



int main(int argc, char **argv)
{

	RenderWindow renderWindow(VideoMode(1800, 980), "SFML Demo");
	Event event;
	//Piano piano1(COUNT_OF_KEYS*3, "pianoNum", "pianoPressedNum", "noty-", 0, 10, renderWindow);
	//Piano piano2(COUNT_OF_KEYS, "pianoNum", "pianoPressedNum", "noty-", 0, 10, renderWindow);
	Piano piano(COUNT_OF_KEYS, renderWindow);


	

	while (renderWindow.isOpen())
	{
		while (renderWindow.pollEvent(event))
		{
			if (event.type == Event::EventType::Closed)
				renderWindow.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::A) && !piano.MyButton[0].getState())
		{
			piano.MyButton[0].buttonPlay();
		}

		if (Keyboard::isKeyPressed(Keyboard::S) && !piano.MyButton[1].getState())
		{
			piano.MyButton[1].buttonPlay();
		}
		if (Keyboard::isKeyPressed(Keyboard::D) && !piano.MyButton[2].getState())
		{
			piano.MyButton[2].buttonPlay();
		}
		if (Keyboard::isKeyPressed(Keyboard::F) && !piano.MyButton[3].getState())
		{
			piano.MyButton[3].buttonPlay();
		}
		if (Keyboard::isKeyPressed(Keyboard::J) && !piano.MyButton[4].getState())
		{
			piano.MyButton[4].buttonPlay();
		}
		if (Keyboard::isKeyPressed(Keyboard::K) && !piano.MyButton[5].getState())
		{
			piano.MyButton[5].buttonPlay();
		}
		if (Keyboard::isKeyPressed(Keyboard::L) && !piano.MyButton[6].getState())
		{
			piano.MyButton[6].buttonPlay();
		}


		renderWindow.clear();
		for (int i = 0; i < COUNT_OF_KEYS; i++) {
			if (event.type == Event::KeyReleased) {
				if (piano.MyButton[i].getButtonKey() == event.key.code + 65) {
					piano.MyButton[i].buttonStop();
					renderWindow.draw(piano.getSprite(i));
				}
			}
		}

		
		for (int i = 0; i < COUNT_OF_KEYS; i++) {
			renderWindow.draw(piano.getSprite(i));
//			renderWindow.draw(piano2.getSprite(i));
		}

		renderWindow.display();
	}
	return 0;
}
