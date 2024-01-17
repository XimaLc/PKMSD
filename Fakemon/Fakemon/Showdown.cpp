#include "Showdown.h"

Showdown::Showdown()
{
	this->boutons["teamCreate"] = new Button(false, 250, 280, 400, 80, "Creer une equipe", 30);
	this->boutons["teamEdit"] = new Button(false, 250, 380, 400, 80, "Modifier une equipe", 30);
	this->boutons["teamDelete"] = new Button(false, 250, 480, 400, 80, "Supprimer une equipe", 30);
	this->boutons["fightRandom"] = new Button(false, 1270, 280, 400, 80, "Trouver un adversaire", 30);
	this->boutons["findFriend"] = new Button(false, 1270, 380, 400, 80, "Rechercher un adversaire", 30);
	this->boutons["quit"] = new Button(false, 100, 950, 400, 80, "Quitter", 30);
}

void Showdown::update()
{	

}

void Showdown::draw(sf::RenderWindow * _window)
{
	for (auto& it : this->boutons)
		it.second->render(_window);
}