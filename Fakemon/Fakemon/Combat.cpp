#include "Combat.h"

Combat::Combat(Client& _client) : client(_client)
{
	team.load();

	font.loadFromFile("../Files/Font/Pokemon.ttf");

	backgroundTexture.loadFromFile("../Files/Textures/BattleBackgrounds.png");
	backgroundSprite.setScale({ 8.f, 8.f });

	actionBarTexture.loadFromFile("../Files/Textures/ActionBar.png");
	actionBarSprite.setPosition({ 0.f, 896.f });

	pokeBarTexture.loadFromFile("../Files/Textures/pokeBar.png");

	pokeBarSprite.setPosition({ 210.f, 95.f });
	pokeBarSprite.setScale({ 6.f, 6.f });

	pokeBarSprite2.setPosition({ 1300.f, 700.f });
	pokeBarSprite2.setScale({ 6.f, 6.f });

	trainerBackTexture.loadFromFile("../Files/Textures/TrainerBack.png");
	trainerBackRect = { 0, 0, 64, 64 };
	trainerBackSprite.setScale({ 8.f, 8.f });
	trainerBackSprite.setPosition({ 200.f, 384.f });
	trainerBackSprite.setTextureRect(trainerBackRect);

	for (auto i : team.getPokemons())
		actualHp.push_back(i.getStat("hp"));
	
	pokemonName.setFillColor(sf::Color::Black);
	pokemonName.setPosition(240.f, 130.f);
	pokemonName.setString("---");

	pokemonHp.setFillColor(sf::Color::Black);
	pokemonHp.setPosition(440.f, 165.f);
	pokemonHp.setString("- / -");
	
	pokemonName2.setFillColor(sf::Color::Black);
	pokemonName2.setPosition(1330.f, 735.f);
	pokemonName2.setString(team.getPokemons()[0].getName());

	pokemonHp2.setFillColor(sf::Color::Black);
	pokemonHp2.setPosition(1530.f, 770.f);
	pokemonHp2.setString(std::to_string(actualHp[0]) + " / " + std::to_string(team.getPokemons()[0].getStat("hp")));
	
	pokemonTexture2 = DB::getTexture(team.getPokemons()[0].getPath());

	pokemonSprite2.setPosition(200.f, 500.f);
	pokemonSprite2.setScale({ 0.5, 0.5 });

	pokemonText.setString("Pokemon");
	pokemonText.setFillColor(sf::Color::Black);
	pokemonText.setPosition(1600.f, 1000.f);

	attaquerText.setString("Attaquer");
	attaquerText.setFillColor(sf::Color::Black);
	attaquerText.setPosition(1600.f, 925.f);


	for (int i = 0; i < 4; i++)
	{
		sf::Text* text = new Text();
		text->setString(team.getPokemons()[0].getMoves()[i].getName());
		text->setFillColor(sf::Color::Black);
		text->setPosition(100 + (i * 380), 970);
		moves.push_back(*text);
	}
	
	for (int i = 0; i < 6; i++)
	{
		sf::Text* text = new Text();
		text->setString(team.getPokemons()[i].getName());
		text->setFillColor(sf::Color::Black);
		if(i < 3)
			text->setPosition(100 + (i * 380), 930);
		else
			text->setPosition(100 + ((i-3) * 380), 990);

		pokemons.push_back(*text);
	}

	isChoosingAction = true;
	isChoosingMove = false;
	isChoosingPokemon = false;

	currentMove = 0;
}

void Combat::switchPokemon(int index)
{
	pokemonName2.setString(team.getPokemons()[index].getName());
	pokemonHp2.setString(std::to_string(actualHp[index]) + " / " + std::to_string(team.getPokemons()[index].getStat("hp")));
	pokemonTexture2 = DB::getTexture(team.getPokemons()[index].getPath());
	moves.clear();
	for (int i = 0; i < 4; i++)
	{
		sf::Text* text = new Text();
		text->setString(team.getPokemons()[index].getMoves()[i].getName());
		text->setFillColor(sf::Color::Black);
		text->setPosition(100 + (i * 380), 970);
		moves.push_back(*text);
	}

	isChoosingAction = true;
	isChoosingMove = false;
	isChoosingPokemon = false;
}

void Combat::update(sf::RenderWindow* _window)
{
	timer += GetDeltaTime();

	if (isChoosingAction)
	{
		if (actionChoice == ATTAQUER)
		{
			attaquerText.setString("> Attaquer");
			pokemonText.setString("Pokemon");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timer >= 0.5f)
			{
				isChoosingAction = false;
				isChoosingMove = true;
				isChoosingPokemon = false;
				timer = 0;
			}
		}
		else if (actionChoice == POKEMON)
		{
			attaquerText.setString("Attaquer");
			pokemonText.setString("> Pokemon");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timer >= 0.5f)
			{
				isChoosingAction = false;
				isChoosingMove = false;
				isChoosingPokemon = true;
				timer = 0;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			actionChoice = POKEMON;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			actionChoice = ATTAQUER;
	}
	else if (isChoosingMove)
	{ 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && currentMove < 3 && timer > 0.5f)
		{
			currentMove++;
			timer = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && currentMove > 0 && timer > 0.5f)
		{
			currentMove--;
			timer = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timer > 0.5f)
		{
			isChoosingAction = true;
			isChoosingMove = false;
			isChoosingPokemon = false;
			currentMove = 0;
			timer = 0;
		}

		for (int i = 0; i < 4; i++)
		{
			if (i == currentMove)
			{
				moves[i].setString("> " + team.getPokemons()[0].getMoves()[i].getName());
			}
			else if (i != currentMove)
			{
				moves[i].setString(team.getPokemons()[0].getMoves()[i].getName());
			}
		}

		
	}
	else if (isChoosingPokemon)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && currentPokemon < 6 && timer > 0.5f)
		{
			currentPokemon++;
			timer = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && currentPokemon > 0 && timer > 0.5f)
		{
			currentPokemon--;
			timer = 0;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && currentPokemon > 2 && timer > 0.5f)
		{
			currentPokemon -= 3;
			timer = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && currentPokemon < 3 && timer > 0.5f)
		{
			currentPokemon += 3;
			timer = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timer > 0.5f)
		{
			switchPokemon(currentPokemon);
			timer = 0;
		}

		for (int i = 0; i < 6; i++)
		{
			if (i == currentPokemon)
			{
				pokemons[i].setString("> " + team.getPokemons()[i].getName());
			}
			else if (i != currentPokemon)
			{
				pokemons[i].setString(team.getPokemons()[i].getName());
			}
		}
	}


	//sendPacket << client.MATCHMAKING;
	//
	//if (client.socket.send(sendPacket) == sf::Socket::Done)
	//	std::cerr << "send connection\n";
	//else
	//	std::cerr << "Failed to send connection\n";

	if(!matchmaking)
	{
		bool suu;
		sendPacket << client.MATCHMAKING;

		if (client.socket.send(sendPacket) == sf::Socket::Done)
			std::cerr << "send connection\n";
		else
			std::cerr << "Failed to send connection\n";

		if (client.socket.receive(receivePacket) == sf::Socket::Done)
			receivePacket >> suu;

		if (!suu)
			std::cerr << "pas assez de joueur";
		else
			std::cerr << "letsgoooo";

	}
}

void Combat::draw(sf::RenderWindow* _window)
{
	backgroundSprite.setTexture(backgroundTexture);
	_window->draw(backgroundSprite);

	pokeBarSprite.setTexture(pokeBarTexture);
	_window->draw(pokeBarSprite);

	pokeBarSprite2.setTexture(pokeBarTexture);
	_window->draw(pokeBarSprite2);

	pokemonSprite2.setTexture(*pokemonTexture2);
	_window->draw(pokemonSprite2);

	actionBarSprite.setTexture(actionBarTexture);
	_window->draw(actionBarSprite);

	pokemonName2.setFont(font);
	_window->draw(pokemonName2);
	
	pokemonHp2.setFont(font);
	_window->draw(pokemonHp2);
	
	pokemonName.setFont(font);
	_window->draw(pokemonName);

	pokemonHp.setFont(font);
	_window->draw(pokemonHp);

	attaquerText.setFont(font);
	_window->draw(attaquerText);

	pokemonText.setFont(font);
	_window->draw(pokemonText);

	if(isChoosingMove)
	{
		for (auto i : moves)
		{
			i.setFont(font);
			_window->draw(i);
		}
	}
	else if(isChoosingPokemon)
	{
		for (auto i : pokemons)
		{
			i.setFont(font);
			_window->draw(i);
		}
	}
}