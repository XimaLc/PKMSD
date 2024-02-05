#include "Capture.h"

Capture::Capture()
{
	
}

Capture::Capture(PokemonSafari _poke)
{
	pokemonEnemy = _poke;
	catchChance = 30.f;
	fleeChance = 20.f;
	catched = false;
	fleed = false;
	finished = false;
	click = false;
	fondTxt.loadFromFile(TexturePath"BattleBackgrounds.png");
	fondSpr.setTexture(fondTxt);
	fondSpr.setScale({ 8.f, 8.f });
	trainerTxt.loadFromFile(TexturePath"TrainerBack.png");
	trainerRect = { 0, 0, 64, 64 };
	trainerSpr.setTexture(trainerTxt);
	trainerSpr.setScale({ 8.f, 8.f });
	trainerSpr.setPosition({ 200.f, 384.f });
	trainerSpr.setTextureRect(trainerRect);
	pokeBarTxt.loadFromFile(TexturePath"pokeBar.png");
	pokeBarSpr.setTexture(pokeBarTxt);
	pokeBarSpr.setPosition({ 210.f, 95.f });
	pokeBarSpr.setScale({ 6.f, 6.f });
	actionBarTxt.loadFromFile(TexturePath"ActionBar.png");
	actionBarSpr.setTexture(actionBarTxt);
	actionBarSpr.setPosition({ 0.f, 896.f });

	pokemonEnemy.setPos({ 1380.f, 380.f });
	pokemonEnemy.getSpr()->setScale({ 0.5f, 0.5f });

	font.loadFromFile(FontsPath"Pokemon.ttf");

	pkmName.setPosition(280.f, 150.f);
	pkmName.setCharacterSize(50);
	pkmName.setFillColor(sf::Color::Black);
	pkmName.setString(pokemonEnemy.getName());

	actionText.setPosition(100.f, 950.f);
	actionText.setCharacterSize(50);
	actionText.setFillColor(sf::Color::Black);
	actionText.setString("Un " + pokemonEnemy.getName() + " sauvage apparait !");

	buttons["BALL"] = new Button("../Files/Textures/button.png", 1500, 930, 185, 60, "Ball", 30);
	buttons["ROCK"] = new Button("../Files/Textures/button.png", 1685, 930, 185, 60, "Rock", 30);
	buttons["MUD"] = new Button("../Files/Textures/button.png", 1500, 990, 185, 60, "Mud", 30);
	buttons["RUN"] = new Button("../Files/Textures/button.png", 1685, 990, 185, 60, "Run", 30);
}

Capture::~Capture()
{

}

void Capture::update(sf::RenderWindow* _window)
{
	sf::Vector2f mousePos(static_cast<float>(sf::Mouse::getPosition(*_window).x), static_cast<float>(sf::Mouse::getPosition(*_window).y));

	for (auto& it : this->buttons)
		it.second->update(mousePos);

	if ((fleed || catched) && !click && Mouse(Left))
		finished = true;

	if (!click && Mouse(Left))
	{
		actionText.setString("Le " + pokemonEnemy.getName() + " vous regarde.");
		if (buttons["RUN"]->isPressed())
		{
			fleed = true;
			actionText.setString("Vous prenez la fuite !");
		}

		if (buttons["BALL"]->isPressed())
		{
			if (fRand(0.f, 100.f) <= catchChance)
			{
				catched = true;
				actionText.setString(pokemonEnemy.getName() + " a ete attrape !");
			}
			else
			{
				if (fRand(0.f, 100.f) <= fleeChance)
				{
					fleed = true;
					actionText.setString(pokemonEnemy.getName() + " a pris la fuite !");
				}
				else
					actionText.setString(pokemonEnemy.getName() + " est sorti de la ball !");
			}
		}

		if (buttons["ROCK"]->isPressed())
		{
			catchChance += 20.f;
			fleeChance += 20.f;
			actionText.setString(pokemonEnemy.getName() + " est en colere !");
		}

		if (buttons["MUD"]->isPressed())
		{
			catchChance -= 10.f;
			fleeChance -= 10.f;
			actionText.setString(pokemonEnemy.getName() + " est couvert de boue !");
		}
	}

	if (Mouse(Left))
		click = true;
	else
		click = false;
}

void Capture::draw(sf::RenderWindow* _window)
{
	fondSpr.setTexture(fondTxt);
	_window->draw(fondSpr);
	trainerSpr.setTextureRect(trainerRect);
	trainerSpr.setTexture(trainerTxt);
	_window->draw(trainerSpr);
	pokeBarSpr.setTexture(pokeBarTxt);
	_window->draw(pokeBarSpr);
	actionBarSpr.setTexture(actionBarTxt);
	_window->draw(actionBarSpr);
	pokemonEnemy.draw(_window);
	pkmName.setFont(font);
	_window->draw(pkmName);
	actionText.setFont(font);
	_window->draw(actionText);

	for (auto& it : this->buttons)
		it.second->render(_window);
}