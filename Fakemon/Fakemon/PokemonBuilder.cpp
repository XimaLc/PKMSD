#include "PokemonBuilder.h"

PokemonBuilder::PokemonBuilder()
{
	font.loadFromFile("../Files/Font/Pokemon.ttf");

	typeTexture.loadFromFile("../Files/Textures/Types.png");

	pkmName.setFillColor(sf::Color::Black);

	pokemon = new Pokemon();

	shape.setFillColor(sf::Color::Green);
	shape.setSize({ 870.f, 840.f });
	shape.setPosition(1030.f, 160.f);

	pkmSprite.setPosition(1035, 165);
	pkmSprite.setScale(0.2, 0.2);


	type1Sprite.setPosition(1280, 230);
	type2Sprite.setPosition(1520, 230);

	pkmName.setPosition(1300, 180);
}

void PokemonBuilder::changePokemon(Pokemon* _p)
{
	pokemon = _p;
	
	if (pokemon->getName() != "")
	{
		pkmName.setString(pokemon->getName());

		pkmTexture = DB::getTexture(pokemon->getPath());
		
		type1Sprite.setTextureRect({ 0, 44 * (pokemon->getType1() - 1), 200,44 });
		type2Sprite.setTextureRect({ 0, 44 * (pokemon->getType2() - 1), 200,44 });
	}
}

void PokemonBuilder::draw(sf::RenderWindow* _window)
{
	pkmSprite.setTexture(*pkmTexture);
	type1Sprite.setTexture(typeTexture);
	type2Sprite.setTexture(typeTexture);
	pkmName.setFont(font);


	_window->draw(shape);
	_window->draw(pkmSprite);
	_window->draw(type1Sprite);
	_window->draw(type2Sprite);
	_window->draw(pkmName);
}
