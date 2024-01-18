#include "Player.h"

Player::Player()
{
	frameX = 1;
	animTime = 0.f;
	dir = DOWN;
	pos = { 100.f, 100.f };
	txt.loadFromFile(TexturePath"Red.png");
	rect = { 16, 0, 16 ,20 };
	spr.setTexture(txt);
	spr.setTextureRect(rect); 
	spr.setOrigin({ 8.f, 10.f });
	spr.setScale({ 2.f, 2.f });
}

Player::~Player()
{
}

void Player::playerAnim()
{
	if (dir != IDLE)
	{
		animTime += GetDeltaTime();

		if (animTime > 0.2f)
		{
			animTime = 0.f;
			frameX++;

			if (frameX == 3)
				frameX = 0;
		}

		if (Key(LShift))
			rect.top = dir * 20 + 80;
		else
			rect.top = dir * 20;
	}
	
	rect.left = frameX * 16;
}

void Player::update(sf::RenderWindow* _window)
{
	if (Key(Z))
	{
		pos.y -= 200.f * GetDeltaTime();
		dir = UP;
		if (Key(LShift))
			pos.y -= 100.f * GetDeltaTime();
	}
	if (Key(S))
	{
		pos.y += 200.f * GetDeltaTime();
		dir = DOWN;
		if (Key(LShift))
			pos.y += 100.f * GetDeltaTime();
	}
	if (Key(Q))
	{
		pos.x -= 200.f * GetDeltaTime();
		dir = LEFT;
		if (Key(LShift))
			pos.x -= 100.f * GetDeltaTime();
	}
	if (Key(D))
	{
		pos.x += 200.f * GetDeltaTime();
		dir = RIGHT;
		if (Key(LShift))
			pos.x += 100.f * GetDeltaTime();
	}

	if (!Key(Z) && !Key(S) && !Key(Q) && !Key(D))
	{
		dir = IDLE;
		frameX = 1;
		if (rect.top >= 80)
			rect.top -= 80;
		animTime = 0;
	}

	playerAnim();
}

void Player::draw(sf::RenderWindow* _window)
{
	spr.setPosition(pos);
	spr.setTextureRect(rect);
	_window->draw(spr);
}
