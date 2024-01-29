#pragma once
#include "Pokemon.h"

class PokemonSafari : public Pokemon
{
private:
	sf::Vector2f pos;
	sf::Vector2f velocity;
	sf::Vector2f steering_force;
	sf::Vector2f acceleration;
	float masse;
	float max_force;
	float vit_max;
	sf::Sprite spr;
	sf::Texture txt;
	sf::RectangleShape collisionDetector;
	int steering;

public:
	PokemonSafari();
	PokemonSafari(Pokemon _pokemon);
	~PokemonSafari();

	inline sf::Vector2f getPos() { return pos; }
	inline sf::Vector2f getVelocity() { return velocity; }
	inline sf::Vector2f getSteering_force() { return steering_force; }
	inline sf::Vector2f getAcceleration() { return acceleration; }
	inline float getMasse() { return masse; }
	inline float getMaxForce() { return max_force; }
	inline float getVitMax() { return vit_max; }
	inline sf::Sprite* getSpr() { return &spr; }
	inline sf::Texture* getTxt() { return &txt; }
	inline sf::RectangleShape* getCollisionDetector() { return &collisionDetector; }
	inline int getSteering() { return steering; }

	inline void setPos(sf::Vector2f _pos) { pos = _pos; }
	inline void setVelocity(sf::Vector2f _velocity) { velocity = _velocity; }
	inline void setSteering_force(sf::Vector2f _steering_force) { steering_force = _steering_force; }
	inline void setAcceleration(sf::Vector2f _acceleration) { acceleration = _acceleration; }
	inline void setMasse(float _f) { masse = _f; }
	inline void setMaxForce(float _f) { max_force = _f; }
	inline void setVitMax(float _f) { vit_max = _f; }
	inline void setSpr(sf::Sprite _spr) { spr = _spr; }
	inline void setTxt(sf::Texture _txt) { txt = _txt; }

	void update(sf::Vector2f _steering);
	void draw(sf::RenderWindow* _window);
};