#include "Player.h"

Player::Player()
{
	frameX = 1;
	animTime = 0.f;
	dir = DOWN;
	pos = { 0.f, 0.f };
	txt.loadFromFile(TexturePath"Red.png");
	rect = { 16, 0, 16 ,20 };
	spr.setTexture(txt);
	spr.setTextureRect(rect); 
	spr.setOrigin({ 8.f, 10.f });
	spr.setScale({ 3.f, 3.f });
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

void Player::update(sf::RenderWindow* _window, sf::View* _view, vector<Obstacle> _obs)
{
	movePlayer(_view, _obs);

	playerAnim();
}

void Player::movePlayer(sf::View* _view, vector<Obstacle> _obs)
{
	canMove = true;
	for (auto obs : _obs)
	{
		if (Rectangle_Collision({ spr.getGlobalBounds().left, spr.getGlobalBounds().top - (200.f * GetDeltaTime()),
			spr.getGlobalBounds().width, 1 }, ObstacleRect) || 
			Rectangle_Collision({ spr.getGlobalBounds().left, spr.getGlobalBounds().top - (200.f * GetDeltaTime()),
			spr.getGlobalBounds().width, 1 }, { -28.f, -240.f, 42.f, 60.f}))
			canMove = false;
	}
	if (Key(Z) && pos.y >= -945.f)
	{
		dir = UP;
		if (canMove)
		{
			pos.y -= 200.f * GetDeltaTime();
			if (pos.y >= -540.f && pos.y <= 540.f)
				_view->move({ 0.f, -200.f * GetDeltaTime() });

			if (Key(LShift))
			{
				pos.y -= 100.f * GetDeltaTime();
				if (pos.y >= -540.f && pos.y <= 540.f)
					_view->move({ 0.f, -100.f * GetDeltaTime() });
			}
		}
	}
	canMove = true;
	for (auto obs : _obs)
	{
		if (Rectangle_Collision({ spr.getGlobalBounds().left, spr.getGlobalBounds().top + spr.getGlobalBounds().height + (200.f * GetDeltaTime()),
			spr.getGlobalBounds().width, 1 }, ObstacleRect) ||
			Rectangle_Collision({ spr.getGlobalBounds().left, spr.getGlobalBounds().top + spr.getGlobalBounds().height + (200.f * GetDeltaTime()),
			spr.getGlobalBounds().width, 1 }, { -28.f, -240.f, 42.f, 60.f }))
			canMove = false;
	}
	if (Key(S) && pos.y <= 920.f)
	{
		dir = DOWN;
		if (canMove)
		{
			pos.y += 200.f * GetDeltaTime();
			if (pos.y >= -540.f && pos.y <= 540.f)
				_view->move({ 0.f, 200.f * GetDeltaTime() });

			if (Key(LShift))
			{
				pos.y += 100.f * GetDeltaTime();
				if (pos.y >= -540.f && pos.y <= 540.f)
					_view->move({ 0.f, 100.f * GetDeltaTime() });
			}
		}
	}
	canMove = true;
	for (auto obs : _obs)
	{
		if (Rectangle_Collision({ spr.getGlobalBounds().left - (200.f * GetDeltaTime()), spr.getGlobalBounds().top,
			1, spr.getGlobalBounds().height }, ObstacleRect) ||
			Rectangle_Collision({ spr.getGlobalBounds().left - (200.f * GetDeltaTime()), spr.getGlobalBounds().top,
			1, spr.getGlobalBounds().height }, { -28.f, -240.f, 42.f, 60.f }))
			canMove = false;
	}
	if (Key(Q) && pos.x >= -1810.f)
	{
		dir = LEFT;
		if (canMove)
		{
			pos.x -= 200.f * GetDeltaTime();
			if (pos.x >= -960.f && pos.x <= 960.f)
				_view->move({ -200.f * GetDeltaTime(), 0.f });

			if (Key(LShift))
			{
				pos.x -= 100.f * GetDeltaTime();
				if (pos.x >= -960.f && pos.x <= 960.f)
					_view->move({ -100.f * GetDeltaTime(), 0.f });
			}
		}
	}
	canMove = true;
	for (auto obs : _obs)
	{
		if (Rectangle_Collision({ spr.getGlobalBounds().left + spr.getGlobalBounds().width + (200.f * GetDeltaTime()), spr.getGlobalBounds().top,
			1, spr.getGlobalBounds().height }, ObstacleRect) ||
			Rectangle_Collision({ spr.getGlobalBounds().left + spr.getGlobalBounds().width + (200.f * GetDeltaTime()), spr.getGlobalBounds().top,
			1, spr.getGlobalBounds().height }, { -28.f, -240.f, 42.f, 60.f }))
			canMove = false;
	}
	if (Key(D) && pos.x <= 1810.f)
	{
		dir = RIGHT;
		if (canMove)
		{
			pos.x += 200.f * GetDeltaTime();
			if (pos.x >= -960.f && pos.x <= 960.f)
				_view->move({ 200.f * GetDeltaTime(), 0.f });

			if (Key(LShift))
			{
				pos.x += 100.f * GetDeltaTime();
				if (pos.x >= -960.f && pos.x <= 960.f)
					_view->move({ 100.f * GetDeltaTime(), 0.f });
			}
		}
	}

	if (!Key(Z) && !Key(S) && !Key(Q) && !Key(D))
	{
		dir = IDLE;
		frameX = 1;
		if (rect.top >= 80)
			rect.top -= 80;
		animTime = 0;
	}
}

void Player::draw(sf::RenderWindow* _window)
{
	spr.setPosition(pos);
	spr.setTextureRect(rect);
	_window->draw(spr);
}
