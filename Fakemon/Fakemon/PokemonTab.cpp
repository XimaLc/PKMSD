#include "PokemonTab.h"

PokemonTab::PokemonTab() {
	pokemonTexture = nullptr;
}

PokemonTab::PokemonTab(Pokemon _pokemon)
{
	pokemon = _pokemon;

	color = sf::Color::Red;

	shape.setSize({ 1000, 90 });
	shape.setFillColor(color);

	pokemonTexture = DB::getTexture(pokemon.getPath());
	typeTexture.loadFromFile("../Files/Textures/Types.png");

	font.loadFromFile("../Files/Font/Pokemon.ttf");
	
	pokemonSprite.setScale({ 0.1, 0.1 });

	type1Sprite.setTextureRect({ 0, 44 * (_pokemon.getType1() - 1), 200,44});
	type1Sprite.setScale(0.6, 0.6);
	type2Sprite.setTextureRect({ 0, 44 * (_pokemon.getType2() - 1), 200,44});
	type2Sprite.setScale(0.6, 0.6);


	text.setString(_pokemon.getName());
	text.setFillColor(sf::Color::Black);
	
	std::map<std::string, int> stats = _pokemon.getStats();
	std::string statsString = "PV." + std::to_string(stats["hp"])
							+ " Atk." + std::to_string(stats["atk"]) +
							+ " Def." + std::to_string(stats["def"]) +
							+ " Spe A." + std::to_string(stats["spA"]) +
							+ " Spe D." + std::to_string(stats["spD"]) +
							+ " Spd." + std::to_string(stats["spd"]) +
							+ " BST." + std::to_string(stats["bst"]);
	statsText.setString(statsString);
	statsText.setFillColor(sf::Color::Black);
	statsText.setCharacterSize(20);
}

const bool PokemonTab::isPressed() const
{
	if (buttonState == tabPRESSED)
	{
		return true;
	}
	return false;
}

void PokemonTab::setPosition(sf::Vector2f _pos)
{
	pokemonSprite.setPosition(_pos);
	shape.setPosition(_pos.x - 5, _pos.y + 5);
	text.setPosition(_pos.x + 100, _pos.y + 25);
	statsText.setPosition(_pos.x + 440, _pos.y + 30);
	type1Sprite.setPosition(_pos.x + 300, _pos.y + 20);
	type2Sprite.setPosition(_pos.x + 300, _pos.y + 55);
}

void PokemonTab::update(const sf::Vector2f mousePos)
{
	timer += GetDeltaTime();

	if (this->shape.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		color.a = 100;
		this->shape.setFillColor(color);

		this->buttonState = tabPRESSED;

		timer = 0;
	}
	else if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = tabHOVER;
		color.a = 200;
		this->shape.setFillColor(color);
	}
	else
	{
		this->buttonState = tabIDLE;;
		color.a = 255;
		this->shape.setFillColor(color);
	}
}

void PokemonTab::draw(sf::RenderWindow* _window)
{
	_window->draw(shape);

	pokemonSprite.setTexture(*pokemonTexture);
	_window->draw(pokemonSprite);
	
	type1Sprite.setTexture(typeTexture);
	_window->draw(type1Sprite);

	type2Sprite.setTexture(typeTexture);
	_window->draw(type2Sprite);
	
	statsText.setFont(font);
	_window->draw(statsText);

	text.setFont(font);
	_window->draw(text);
}