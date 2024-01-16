#include "Showdown.h"

Showdown::Showdown()
{
	this->boutons["teamCreate"] = new Button(false,10, 10, 400, 80, "Creer une equipe", 50);
	this->boutons["teamEdit"] = new Button(false, 10, 100, 400, 80, "Modifier une equipe", 50);
	this->boutons["teamDelete"] = new Button(false, 10, 190, 400, 80, "Supprimer une equipe", 50);
	this->boutons["fightRandom"] = new Button(false, 10, 280, 400, 80, "Trouver un adversaire", 50);
	this->boutons["findFriend"] = new Button(false, 10, 370, 400, 80, "Rechercher un adversaire", 50);
	this->boutons["quit"] = new Button(false, 10, 460, 400, 80, "Quitter", 50);
}

void Showdown::update()
{	

}

void Showdown::draw(sf::RenderWindow * _window)
{
	for (auto& it : this->boutons)
		it.second->render(_window);
}