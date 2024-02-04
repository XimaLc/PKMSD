#pragma once
#include "Showdown.h"
#include "teamBuilder.h"
#include "safari.h"
#include "Combat.h"

enum STATE {menu, teamBuilder, combat, safariMode};

class GameState : public State
{
private:
	Showdown showdown;
	TeamBuilder tb;
	Safari safari;
	Combat cb;
	static int state;
public:
	GameState(Client& _client);
	~GameState() {}

	inline static void setState(int id) { state = id; }

	void updateScene(sf::RenderWindow* _window)override;
	void drawScene(sf::RenderWindow* _window)override;
};

