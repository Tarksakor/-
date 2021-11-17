#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<time.h>
#include<iostream>

using namespace sf;


bool isCollide(Sprite s1, Sprite s2)
{
	return(s1.getGlobalBounds().intersects(s2.getGlobalBounds()));
}


struct Game
{
	int score;
	int attempt;
	bool ball_out;
	bool started;
	bool restarted;
	bool cont;
};

int main()
{
	setlocale(LC_ALL, "RUS");
	RenderWindow window(VideoMode(1040, 650), "ARCANOID!!!");
	window.setFramerateLimit(80);  // частотой обновления устанавливаем скорость игры ( движения шарика)
	srand(time(0));
	// создаём экземпляры класса texture : ball, rblock, gblock, bblock, background, и указываем пути к изображениям
	Texture ball, platform, rblock, gblock, bblock, background;
	ball.loadFromFile("images/ball.png");
	platform.loadFromFile("images/platform.png");
	rblock.loadFromFile("images/rblock.png");
	gblock.loadFromFile("images/gblock.png");
	bblock.loadFromFile("images/bblock.png");
	background.loadFromFile("images/background.jpg");
	// 


	Sprite sBackground(background), sBall(ball), sPlatform(platform);

	sPlatform.setPosition(470, 600);
	sBall.setPosition(510, 580);
	Sprite sBlock[1000];

	// расставляем блоки 
	int n = 0;

	for (size_t i = 1; i < 19; i++)
	{
		for (size_t j = 1; j < 12; j++)
		{
			sBlock[n].setTexture(rblock);
			sBlock[n].setPosition(i * 50, j * 25); sBlock[n].setPosition(i * 53, j * 28);
			n++;
		}
	}
	//
	float dx = 6, dy = 5;

	Game game;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		sBall.move(dx, 0);   // движение мяча по оси х
		for (size_t i = 0; i < n; i++)
		{
			if (isCollide(sBall, sBlock[i]))
			{
				sBlock[i].setPosition(-100, 0); // при столкновении с блоком направление мяча меняется напротивоположное dx=-dx по оси х
				dx = -dx;
			}
		}
		sBall.move(0, dy);
		for (size_t i = 0; i < n; i++)
		{
			if (isCollide(sBall, sBlock[i]))
			{
				sBlock[i].setPosition(-100, 0); // при столкновении с блоком направление мяча меняется напротивоположное dy=-dy по оси y
				dy = -dy;
			}
		}
		Vector2f p = sPlatform.getPosition();
		Vector2f b = sBall.getPosition();
		if (b.x < 0 || b.x > 1040) dx = -dx;
		if (b.y < 0 || b.y >650) dy = -dy;
		if (b.y > 640)     // если мяч пролетел ниже платформы
		{
			dy = 650;      // он "прячется" за пределами нижней границы окна
			game.ball_out = true;
		}

		if (p.x < 0) sPlatform.setPosition(0, 600);
		if (p.x > 920) sPlatform.setPosition(920, 600);

		//if (!game.started || game.restarted)
		//{
		//	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))sPlatform.move(10, 0), sBall.move(10, 0);
		//	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) sPlatform.move(-10, 0), sBall.move(-10, 0);
		//	if (Keyboard::isKeyPressed(Keyboard::Space)) game.started = true;

		//}
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))sPlatform.move(10, 0);
		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) sPlatform.move(-10, 0);

		if (isCollide(sPlatform, sBall)) dy = -(rand() % 5 + 2);

		window.clear();
		window.draw(sBackground);
		window.draw(sPlatform);
		window.draw(sBall);
		for (size_t i = 0; i < n; i++)
		{
			window.draw(sBlock[i]);
		}
		window.display();
	}

	return 0;
}