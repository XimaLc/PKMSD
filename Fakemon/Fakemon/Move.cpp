#include "Move.h"

Move::Move()
{
}

Move::Move(int _id, std::string _name, int _type, int _category, int _pp, int _power, int _accuracy)
{
	id = _id;
	name = _name;
	type = _type;
	category = _category;
	pp = _pp;
	power = _power;
	accuracy = _accuracy;
}
