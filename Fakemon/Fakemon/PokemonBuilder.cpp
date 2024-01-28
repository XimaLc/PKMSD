#include "PokemonBuilder.h"

PokemonBuilder::PokemonBuilder()
{
	font.loadFromFile("../Files/Font/Pokemon.ttf");

	typeTexture.loadFromFile("../Files/Textures/Types.png");

	pokemon = new Pokemon();

	shape.setFillColor(sf::Color::Green);
	shape.setSize({ 870.f, 840.f });
	shape.setPosition(1030.f, 160.f);

	pkmSprite.setPosition(1035, 165);
	pkmSprite.setScale(0.3, 0.3);

	type1Sprite.setPosition(1280, 230);
	type2Sprite.setPosition(1520, 230);

	pkmName.setPosition(1300, 180);
	pkmName.setFillColor(sf::Color::Black);

	statsTexts["hp"].setPosition(1050, 450);
	statsTexts["hp"].setFillColor(sf::Color::Black);

	statsTexts["atk"].setPosition(1050, 490);
	statsTexts["atk"].setFillColor(sf::Color::Black);

	statsTexts["def"].setPosition(1050, 530);
	statsTexts["def"].setFillColor(sf::Color::Black);

	statsTexts["spA"].setPosition(1050, 570);
	statsTexts["spA"].setFillColor(sf::Color::Black);

	statsTexts["spD"].setPosition(1050, 610);
	statsTexts["spD"].setFillColor(sf::Color::Black);

	statsTexts["spd"].setPosition(1050, 650);
	statsTexts["spd"].setFillColor(sf::Color::Black);

	int x{ 0 };
	MoveSlot tmpMs;
	for (auto i : pokemon->getMoves())
	{
		tmpMs = MoveSlot();
		tmpMs.setIndex(x);
		tmpMs.setPosition(1300, 350 + (x * 125));
		moveSlots.push_back(tmpMs);
		x++;
	}
}

void PokemonBuilder::update(const sf::Vector2f mousePos)
{
	for (auto i : moveSlots)
	{
		i.update(mousePos);
	}
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

		statsTexts["hp"].setString("PV : " + std::to_string(pokemon->getStat("hp")));
		statsTexts["atk"].setString("ATK : " + std::to_string(pokemon->getStat("atk")));
		statsTexts["def"].setString("DEF : " + std::to_string(pokemon->getStat("def")));
		statsTexts["spA"].setString("Spe ATK : " + std::to_string(pokemon->getStat("spA")));
		statsTexts["spD"].setString("Spe DEF : " + std::to_string(pokemon->getStat("spD")));
		statsTexts["spd"].setString("Spd : " + std::to_string(pokemon->getStat("spd")));
	
		movePool = DB::getMovePool(pokemon->getMovePool());
	}
	else
	{
		pkmTexture = nullptr;
		type1Sprite.setTextureRect({ 0, 44 * (20 - 1), 200,44 });
		type2Sprite.setTextureRect({ 0, 44 * (20 - 1), 200,44 });

		pkmName.setString("");
		statsTexts["hp"].setString("");
		statsTexts["atk"].setString("");
		statsTexts["def"].setString("");
		statsTexts["spA"].setString("");
		statsTexts["spD"].setString("");
		statsTexts["spd"].setString("");
	}
}

void PokemonBuilder::draw(sf::RenderWindow* _window)
{
	type1Sprite.setTexture(typeTexture);
	type2Sprite.setTexture(typeTexture);
	pkmName.setFont(font);

	_window->draw(shape);
	
	if (pkmTexture != nullptr)
	{
		pkmSprite.setTexture(*pkmTexture);
		_window->draw(pkmSprite);
	}

	_window->draw(type1Sprite);
	_window->draw(type2Sprite);
	_window->draw(pkmName);

	for (auto i : statsTexts)
	{
		i.second.setFont(font);
		_window->draw(i.second);
	}

	for (auto i : moveSlots)
	{
		i.draw(_window);
	}

}
