#include "Menu.h"
#include "Client.h"

sf::Font Menu::fonts;

Menu::Menu(Client& _client) : client(_client)
{
	this->boutons["PSEUDO_BOUTTON"] = new Button("../Files/Textures/button.png", 750, 470, 400, 80, "PSEUDO", 30, true);
	this->boutons["PASSWORD_BOUTTON"] = new Button("../Files/Textures/button.png", 750, 600, 400, 80, "PASSWORD", 30, true);
	this->boutons["LOGIN_BOUTTON"] = new Button("../Files/Textures/button.png",  850, 750, 200, 80, "LOGIN", 50);
	this->boutons["REGISTER_BOUTTON"] = new Button("../Files/Textures/button.png", 1500, 950, 300, 80, "REGISTER", 50);
	this->boutons["EXIT_BOUTTON"] = new Button("../Files/Textures/button.png", 100, 950, 200, 80, "EXIT", 50);

	if (fondTex.loadFromFile("../Files/Textures/fond.png"))
	{
		fondSpr.setTexture(fondTex);
		fondSpr.setPosition(0, 0);
	}
	if (fogTex.loadFromFile("../Files/Textures/smoge.png"))
	{
		fogSpr.setTexture(fogTex);
		fogSpr.setPosition(0,300);
		fogSpr.setScale(0.5, 0.5);
	}
	if (fogTex2.loadFromFile("../Files/Textures/smoge1.png"))
	{
		fogSpr2.setTexture(fogTex2);
		fogSpr2.setPosition(-1920, 300);
		fogSpr2.setScale(0.5, 0.5);
	}
	if (TitreTex.loadFromFile("../Files/Textures/FAKEMON.png"))
	{
		TitreSpr.setTexture(TitreTex);
		TitreSpr.setPosition(580,80);
		TitreSpr.setScale(0.7,0.7);
	}
	if (fonts.getInfo().family.empty())
	{
		if (!fonts.loadFromFile("../Files/Font/Pokemon.ttf"))
		{
			std::cerr << "Erreur lors du chargement de la police." << std::endl;
		}
	}
	this->notif.setFont(fonts);
	this->notif.setPosition(sf::Vector2f(850, 430));
	this->notif.setCharacterSize(20);
	this->notif.setFillColor(sf::Color(255, 204, 1, 255));
	this->notif.setOutlineThickness(3);
	this->notif.setOutlineColor(sf::Color(11, 75, 137, 255));

	if (transitionTexture.loadFromFile("../Files/Textures/transi.png"))
	{
		transitionSprite.setTexture(transitionTexture);
	}
	transitionSprite.setTextureRect(sf::IntRect(0,0,320,180));

	login = LOGIN;
	timer = 0;
}

void Menu::updateMenu(sf::RenderWindow* _window)
{
	timer += GetDeltaTime();

	fogSpr.setPosition(sf::Vector2f(fogSpr.getPosition().x + 200 * GetDeltaTime(), fogSpr.getPosition().y));
	fogSpr2.setPosition(sf::Vector2f(fogSpr2.getPosition().x + 200 * GetDeltaTime(), fogSpr2.getPosition().y));
	if(fogSpr.getPosition().x > 1920)
		fogSpr.setPosition(sf::Vector2f(-1920, fogSpr.getPosition().y));
	else if(fogSpr2.getPosition().x > 1920)
		fogSpr2.setPosition(sf::Vector2f(-1920, fogSpr2.getPosition().y));

	sf::Vector2f mousePos(static_cast<float>(sf::Mouse::getPosition(*_window).x), static_cast<float>(sf::Mouse::getPosition(*_window).y));

	for (auto& it : this->boutons)
		it.second->update(mousePos);
  
	for (auto& it : this->boutons)
		it.second->handleTextInput();

	if (boutons["EXIT_BOUTTON"]->isPressed() && timer >= 0.2f)
	{
		_window->close();
	}

	if (activNotif)
	{
		timeNotif += GetDeltaTime();
		if (timeNotif >= 1)
		{
			activNotif = false;
			timeNotif = 0;
		}
	}

	if(login == LOGIN)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		{
			verifAccount = true;
		}
		boutons["LOGIN_BOUTTON"]->setPosition(sf::Vector2f(850, 750));
		boutons["REGISTER_BOUTTON"]->setPosition(sf::Vector2f(1500, 950));

		if (boutons["LOGIN_BOUTTON"]->isPressed() && timer >= 0.2f)
		{
			verifAccount = true;
		}
		//	if (client.socket.connect("192.168.10.129", 8888) != sf::Socket::Done)
		//	{
		//		std::cerr << "Failed to connect to server\n";
		//	}

		//	// Send username / password
		//	username = boutons["PSEUDO_BOUTTON"]->getText();
		//	password = boutons["PASSWORD_BOUTTON"]->getText();
		//	sendPacket << client.LOGIN << username << password;
		//	
		//	if (client.socket.send(sendPacket) == sf::Socket::Done)
		//		std::cerr << "send username / password succesfull\n";
		//	else
		//		std::cerr << "Failed to send username / password\n";

		//	if (client.socket.receive(receivePacket) == sf::Socket::Done)
		//	{
		//		int pType;
		//		receivePacket >> pType;
		//		if (pType == client.LOGIN)
		//		{
		//			receivePacket >> isAuthenticated;
		//		}
		//	}

		//	std::cout << "-----------------------\n";

		//	if (isAuthenticated)
		//	{
		//		std::cout << "Connexion reussie\n";
		//		verifAccount = true;
		//	}
		//	else
		//	{
		//		std::cout << "Connexion echouer\n";
		//		this->notif.setPosition(sf::Vector2f(890, 430));
		//		this->notif.setString(std::string("ID unknow"));
		//		activNotif = true;
		//		client.socket.disconnect();
		//	}

		//	sendPacket.clear();
		//	receivePacket.clear();
		//	
		//	timer = 0;
		/*}
		else if (boutons["REGISTER_BOUTTON"]->isPressed() && timer >= 0.2f)
		{
			login = REGISTER;
			timer = 0;
		}*/
	}
	if (login == REGISTER)
	{
		boutons["LOGIN_BOUTTON"]->setPosition(sf::Vector2f(1550, 950));
		boutons["REGISTER_BOUTTON"]->setPosition(sf::Vector2f(800, 750));

		if (boutons["REGISTER_BOUTTON"]->isPressed() && timer >= 0.2f)
		{
			if (client.socket.connect("192.168.10.129", 8888) != sf::Socket::Done)
			{
				std::cerr << "Failed to connect to server\n";
			}

			// Send username
			username = boutons["PSEUDO_BOUTTON"]->getText();
			password = boutons["PASSWORD_BOUTTON"]->getText();
			sendPacket << client.REGISTER << username << password;

			if (client.socket.send(sendPacket) == sf::Socket::Done)
				std::cerr << "send username / password succesfull\n";
			else
				std::cerr << "Failed to send username / password\n";

			if (client.socket.receive(receivePacket) == sf::Socket::Done)
			{
				int pType;
				receivePacket >> pType;
				if (pType == client.REGISTER)
				{
					receivePacket >> isRegister;
				}
			}

			std::cout << "-----------------------\n";
			sendPacket.clear();
			receivePacket.clear();
			timer = 0;

			if (isRegister)
			{
				std::cout << "Register reussie\n";
				this->notif.setPosition(sf::Vector2f(860, 430));
				this->notif.setString(std::string("Inscription reussie"));
				activNotif = true;
				client.socket.disconnect();
				login = LOGIN;
			}
			else
			{
				this->notif.setPosition(sf::Vector2f(790, 430));
				this->notif.setString(std::string("Le nom d'utilisateur existe deja"));
				activNotif = true;
				client.socket.disconnect();
			}

			
		}
		if (boutons["LOGIN_BOUTTON"]->isPressed() && timer >= 0.2f)
		{
			login = LOGIN;
			timer = 0;
		}
	}

	if(verifAccount == true)
	{
		timerAnim += GetDeltaTime();

		if (timerAnim > 0.03)
		{
			frameX++;
			if (frameX > 3)
			{
				frameX = 0;
				frameY++;
			}
			timerAnim = 0.0f;
		}
		sourceRect.top = frameY * 180;
		sourceRect.left = frameX * 320;
		sourceRect.width = 320;
		sourceRect.height = 180;
		transitionSprite.setTextureRect(sourceRect);
		transitionSprite.setScale(sf::Vector2f(6, 6));
		if (frameY >= 9)
		{
			frameY = 0;
			frameX = 0;
			verifAccount = false;
			isAuthenticated = false;
			StateManager::getInstance()->switchToGame();
		}
	}
}

void Menu::drawMenu(sf::RenderWindow * _window)
{
	_window->draw(fondSpr);
	_window->draw(fogSpr);
	_window->draw(fogSpr2);
	_window->draw(TitreSpr);
	for (auto& it : this->boutons)
		it.second->render(_window);
	if(activNotif)
		_window->draw(notif);
	if (verifAccount == true)
		_window->draw(transitionSprite);
}


