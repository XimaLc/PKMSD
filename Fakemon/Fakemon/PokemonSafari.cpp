#include "PokemonSafari.h"

PokemonSafari::PokemonSafari()
{
	
}

PokemonSafari::PokemonSafari(Pokemon _pokemon)
{
	id = _pokemon.getId();
	path = _pokemon.getPath();
	name = _pokemon.getName();
	type1 = _pokemon.getType1();
	type2 = _pokemon.getType2();
	evolution_state = _pokemon.getEvolutionState();
	stats = _pokemon.getStats();
	movePool = _pokemon.getMovePool();
	shiny = _pokemon.getSiny();

	pos = { fRand(-1824.f, 1824.f), fRand(-945.f, 945.f) };
	velocity = { 0.f, 0.f };
	masse = 0.1f;
	max_force = 50.f;
	vit_max = 50.f;
	if (shiny)
		txt.loadFromFile(TexturePath"Pokemons/Shiny/" + path + ".png");
	else
		txt.loadFromFile(TexturePath"Pokemons/Base/" + path + ".png");
	spr.setTexture(txt);
	spr.setOrigin(spr.getGlobalBounds().width / 2, spr.getGlobalBounds().height / 2);
	spr.setScale(0.15f, 0.15f);

	collisionDetector.setSize({ 100.f, spr.getGlobalBounds().height });
	collisionDetector.setOrigin(0.f, spr.getGlobalBounds().height / 2);
	collisionDetector.setFillColor({ 255, 0, 0, 50 });

	steering = iRand(1, 4);
	if (steering == 3)
	{
		pathFollowingIndex = 0;
		for (int i = 0; i < 4; i++)
		{
			pathFollowing.push_back(sf::Vector2f(fRand(pos.x - 500.f, pos.x + 500.f), fRand(pos.y - 500.f, pos.y + 500.f)));
		}
	}
	despawnTimer = 0.f;
}

PokemonSafari::~PokemonSafari()
{
}

void PokemonSafari::update(sf::Vector2f _steering)
{
	acceleration = _steering / masse;
	velocity = Truncate(velocity + acceleration * GetDeltaTime(), vit_max);
	pos += velocity * GetDeltaTime();
	collisionDetector.setPosition(pos);
	collisionDetector.setRotation(GetAngle({ 1.0f, 0.f }, velocity) * RAD2DEG);
}

void PokemonSafari::draw(sf::RenderWindow* _window)
{
	spr.setTexture(txt);
	spr.setPosition(pos);
	_window->draw(spr);
	//_window->draw(collisionDetector);
}