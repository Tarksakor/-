//#include<SFML/Graphics.hpp>
//#include<SFML/Audio.hpp>
//#include<time.h>
//#include<iostream>
//
//using namespace sf;
//using namespace std;
//
//
//bool isCollide(Sprite s1, Sprite s2)
//{
//	return(s1.getGlobalBounds().intersects(s2.getGlobalBounds()));
//}
//
//class Objects
//{
//public:
//	Sprite background, sBall, sPlatform, sblocks,
//		menuBG, block[1000];
//};
//
//class Game
//{
//public:
//	bool start = false;
//	bool play = false;
//
//};
//
//class Menu
//{
//public:
//
//	bool mainMenu = false;
//};
//
//
//
//
//
//
//int main()
//{
//	setlocale(LC_ALL, "RUS");
//	RenderWindow window(VideoMode(1040, 650), "ARCANOID!!!");
//	window.setFramerateLimit(80);  // частотой обновления устанавливаем скорость игры ( движения мяча)
//	srand(time(0));
//	Objects obj;
//	Game game;
//	Menu menu;
//	Texture ball, platform, blocks, background, menuBG; // создаём текстуры
//
//	background.loadFromFile("images/background.jpg"); obj.background.setTexture(background);
//	ball.loadFromFile("images/ball.png"); obj.sBall.setTexture(ball);
//	platform.loadFromFile("images/platform.png"); obj.sPlatform.setTexture(platform);
//	blocks.loadFromFile("images/blocks.png"); obj.sblocks.setTexture(blocks);
//	menuBG.loadFromFile("images/menu.jpg"); obj.menuBG.setTexture(menuBG);
//
//
//	obj.sPlatform.setPosition(460, 600);  // начальная позиция платформы
//	obj.sBall.setPosition(510, 580); // начальная позиция мяча
//	int dirX = 1, dirY = 1;
//
//	int n = 0;
//
//	//for (size_t i = 1; i < 19; i++)
//	//{
//	//	for (size_t j = 1; j < 12; j++)
//	//	{
//	//		block[n].setTexture(block);
//	//		block[n].setPosition(i * 50, j * 25); blocks[n].setPosition(i * 53, j * 28);
//	//		n++;
//	//	}
//	//}
//
//
//
//
//
//
//	while (window.isOpen())
//	{
//		Event playing;
//
//		while (window.pollEvent(playing))
//		{
//			if (playing.type == Event::Closed)
//				window.close();
//		}
//
//
//		if (menu.mainMenu)       // отображение меню
//		{
//			window.clear();
//			window.draw(obj.background);
//			window.display();
//		}
//		game.start = true;
//		if (game.start)
//		{
//			game.play = true;
//
//			for (size_t i = 0; i < n; i++)
//			{
//				window.draw(blocks[i]);
//			}
//			obj.sPlatform.setPosition(460, 600);
//			obj.sBall.setPosition(510, 580);
//			dirX = 1;
//			dirY = 1;
//			game.start = false;
//		}
//
//		if (game.play)
//		{
//			window.clear();
//			window.draw(obj.background);
//			window.draw(obj.sPlatform);
//			window.draw(obj.sBall);
//			for (size_t i = 0; i < 30; i++)
//			{
//				window.draw(obj.block[i]);
//			}
//		}
//		window.display();
//
//	}
//
//	return 0;
//}