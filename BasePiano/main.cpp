﻿/**
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
#include <Windows.h>
#include "mmsystem.h"



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

	PlaySound("SoundName", NULL, SND_RESOURCE | SND_ASYNC);


	while (renderWindow.isOpen())
	{
		while (renderWindow.pollEvent(event))
		{
			if (event.type == Event::EventType::Closed)
				renderWindow.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::A) && !piano.MyButton[0].buttonStatus())
		{
			
				//PlaySound(TEXT("sounds/noty-1.wav"), NULL, SND_ASYNC);
				piano.MyButton[0].buttonPlay();
			
			
		}

		if (Keyboard::isKeyPressed(Keyboard::S) && !piano.MyButton[1].buttonStatus())
		{			
			piano.MyButton[1].buttonPlay();
		}
		if (Keyboard::isKeyPressed(Keyboard::D) && !piano.MyButton[2].buttonStatus())
		{			
			piano.MyButton[2].buttonPlay();
		}
		if (Keyboard::isKeyPressed(Keyboard::F) && !piano.MyButton[3].buttonStatus())
		{
			piano.MyButton[3].buttonPlay();
		}
		if (Keyboard::isKeyPressed(Keyboard::J) && !piano.MyButton[4].buttonStatus())
		{
			piano.MyButton[4].buttonPlay();
		}
		if (Keyboard::isKeyPressed(Keyboard::K) && !piano.MyButton[5].buttonStatus())
		{
			piano.MyButton[5].buttonPlay();
		}
		if (Keyboard::isKeyPressed(Keyboard::L) && !piano.MyButton[6].buttonStatus())
		{
			piano.MyButton[6].buttonPlay();
		}
		
		renderWindow.clear();
		if (event.type == Event::KeyReleased){
		for (int i = 0; i < COUNT_OF_KEYS; i++) { 
				//PlaySound(NULL, NULL, SND_SYNC);
				if (piano.MyButton[i].getButtonKey() == event.key.code + 65) {
					piano.MyButton[i].buttonStop();
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
