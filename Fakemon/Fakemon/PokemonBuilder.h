#pragma once
#include "DB.h"
#include "MoveSlot.h"

class PokemonBuilder
{
private:
	std::vector<MoveSlot> moveSlots;

	Pokemon* pokemon;

	sf::Texture* pkmTexture;
	sf::Texture typeTexture;

	sf::Sprite pkmSprite;
	sf::Sprite type1Sprite;
	sf::Sprite type2Sprite;

	sf::RectangleShape shape;

	sf::Font font;
	sf::Text pkmName;

	std::vector<Move> movePool;

	std::map < std::string, sf::Text> statsTexts;
public:
	PokemonBuilder();

	inline std::vector<MoveSlot>* getMoveSlots() { return &moveSlots; };

	bool isMoveSlotPressed();

	void update(const sf::Vector2f mousePos);
	void changePokemon(Pokemon* _p);
	void draw(sf::RenderWindow * _window);
};

