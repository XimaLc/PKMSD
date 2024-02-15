#pragma once
#include "StateManager.h"
#include "Overworld.h"
#include "Capture.h"
#include "Shop.h"

enum StateSafari {overworldS, shopS};

class Safari
{
private:
	Overworld overworld;
	Shop shop;
	static int stateSafari;
public:
	Safari();
	~Safari();

	inline static void setStateSafari(int id) { stateSafari = id; }

	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);
};

