#include "Overworld.h"

Overworld::Overworld()
{
	fondTxt.loadFromFile(TexturePath"fond_herbe.png");
	fondSpr.setPosition({ -1920.f, -1080.f });
	fondSpr.setTextureRect({ 0, 0, 3840, 2160 });
	fondSpr.setTexture(fondTxt);
	viewOverworld.setSize({ 1920.f, 1080.f });
	viewOverworld.setCenter({ 0.f, 0.f });
	spawnTimer = 0.f;

}

Overworld::~Overworld()
{

}

void Overworld::update(sf::RenderWindow* _window)
{
	spawnTimer += GetDeltaTime();

	player.update(_window, &viewOverworld);

	if (spawnTimer > 2.f && wildPokemons.size() < 10)
	{
		spawnTimer = 0.f;
		wildPokemons.push_back(DB::getPokemonById(iRand(1, 148)));
	}

	for (auto& it : wildPokemons)
	{
		//it.update(seek(&it, player.getPos()));
	}
}

void Overworld::draw(sf::RenderWindow* _window)
{
	_window->setView(viewOverworld);

	_window->draw(fondSpr);

	for (auto i : wildPokemons)
		i.draw(_window);

	player.draw(_window);
}

sf::Vector2f Overworld::seek(PokemonSafari* agent, sf::Vector2f _targetPos)
{
	sf::Vector2f newVelocity = Normalize(_targetPos - agent->getPos()) * agent->getVitMax();
	agent->setSteering_force(newVelocity - agent->getVelocity());
	agent->setSteering_force(Truncate(agent->getSteering_force(), agent->getMaxForce()));
	return agent->getSteering_force();
}

sf::Vector2f Overworld::flee(PokemonSafari* agent, sf::Vector2f _targetPos)
{
	sf::Vector2f newVelocity = Normalize(agent->getPos() - _targetPos) * agent->getVitMax();
	agent->setSteering_force(newVelocity - agent->getVelocity());
	agent->setSteering_force(Truncate(agent->getSteering_force(), agent->getMaxForce()));
	return agent->getSteering_force();
}

sf::Vector2f Overworld::pursuit(PokemonSafari* agent, sf::Vector2f _targetPos, sf::Vector2f _targetVel)
{
	float T = min(0.5f, GetNorme(_targetPos - agent->getPos()) / agent->getVitMax());
	sf::Vector2f pos = _targetPos + _targetVel * T;
	return seek(agent, pos);
}

sf::Vector2f Overworld::evasion(PokemonSafari* agent, sf::Vector2f _targetPos, sf::Vector2f _targetVel)
{
	float T = min(0.5f, GetNorme(_targetPos - agent->getPos()) / agent->getVitMax());
	sf::Vector2f pos = _targetPos + _targetVel * T;
	return flee(agent, pos);
}

sf::Vector2f Overworld::arrival(PokemonSafari* agent, sf::Vector2f _targetPos)
{
	float dist = GetNorme(_targetPos - agent->getPos());

	return sf::Vector2f();
}