#include "Overworld.h"
#include "GameState.h"
#include "Safari.h"

Overworld::Overworld()
{
	fondTxt.loadFromFile(TexturePath"fond_herbe.png");
	fondSpr.setPosition({ -1920.f, -1080.f });
	fondSpr.setTextureRect({ 0, 0, 3840, 2160 });
	fondSpr.setTexture(fondTxt);
	viewOverworld.setSize({ 1920.f, 1080.f });
	viewOverworld.setCenter({ 0.f, 0.f });
	spawnTimer = 0.f;
	hitPokemon = false;
	pnjShape.setPosition({ -28.f, -240.f });
	pnjText.loadFromFile(TexturePath"pnj.png");
	pnjShape.setScale({ 3.f, 3.f });
	pnjShape.setTexture(pnjText);
	obstacleTxt.loadFromFile(TexturePath"tree.png");
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			obstacles.push_back(Obstacle({ -1202.f + 608.f * i, -315.f + 630.f * j }, { 32.f, 45.f }, obstacleTxt));
		}
	}
}

Overworld::~Overworld()
{

}

void Overworld::update(sf::RenderWindow* _window)
{
	if (!hitPokemon)
	{
		spawnTimer += GetDeltaTime();

		player.update(_window, &viewOverworld, obstacles);

		if (GetDistance(player.getPos(), pnjShape.getPosition()) <= 100.f && Key(Enter))
			GameState::setState(menu);

		if (spawnTimer > 2.f && wildPokemons.size() < 10)
		{
			spawnTimer = 0.f;
			wildPokemons.push_back(DB::getPokemonById(iRand(1, 148)));
		}

		list<PokemonSafari>::iterator it1 = wildPokemons.begin();
		bool despawn = false;
		for (auto& it : wildPokemons)
		{
			it.despawnTimer += GetDeltaTime();
			if (it.despawnTimer >= 180.f)
				despawn = true;
			if (!despawn)
				it1++;

			if (it.getSteering() == 1)
			{
				if (GetDistance(player.getPos(), it.getPos()) <= 400.f)
				{
					it.update(seek(&it, player.getPos()));
					it.update(obstacleAvoidance(&it, obstacles));
					it.update(wander(&it));
				}
			}
			else if (it.getSteering() == 2)
			{
				if (GetDistance(player.getPos(), it.getPos()) <= 400.f)
				{
					it.update(flee(&it, player.getPos()));
					it.update(obstacleAvoidance(&it, obstacles));
					it.update(wander(&it));
				}
			}
			else if (it.getSteering() == 3)
			{
				it.update(seek(&it, it.getPathFollowing()[it.getPathFollowingIndex()]));
				if (GetDistance(it.getPos(), it.getPathFollowing()[it.getPathFollowingIndex()]) < 10.f)
					it.setPathFollowingIndex(it.getPathFollowingIndex() + 1);
				if (it.getPathFollowingIndex() == 4)
					it.setPathFollowingIndex(0);
				it.update(obstacleAvoidance(&it, obstacles));
			}

			if (GetDistance(player.getPos(), it.getPos()) <= 75.f)
			{
				hitPokemon = true;
				capture = Capture(it);
			}
		}

		if (despawn)
		{
			wildPokemons.erase(it1);
			despawn = false;
		}
	}
	else
	{
		capture.update(_window);
		if (capture.getFinished())
		{
			hitPokemon = false;
			list<PokemonSafari>::iterator it1 = wildPokemons.begin();

			for (auto it : wildPokemons)
			{
				if (it.getId() != capture.getPokemonEnemy().getId())
					it1++;
				else
					break;
			}
			it1 = wildPokemons.erase(it1);
		}
	}
}

void Overworld::draw(sf::RenderWindow* _window)
{
	if (!hitPokemon)
	{
		_window->setView(viewOverworld);

		_window->draw(fondSpr);

		for (auto tree : obstacles)
		{
			tree.draw(_window, obstacleTxt);
		}

		for (auto i : wildPokemons)
			i.draw(_window);

		player.draw(_window);
		_window->draw(pnjShape);

		for (auto tree : obstacles)
		{
			if (tree.getPos().y + tree.getSpr().getGlobalBounds().height / 2 > player.getPos().y)
				tree.draw(_window, obstacleTxt);
		}
	}
	else
	{
		_window->setView(_window->getDefaultView());
		capture.draw(_window);
	}
}

sf::Vector2f Overworld::seek(PokemonSafari* agent, sf::Vector2f _targetPos)
{
	sf::Vector2f newVelocity = Normalize(_targetPos - agent->getPos()) * agent->getVitMax();
	agent->setSteering_force(newVelocity - agent->getVelocity());
	agent->setSteering_force(Truncate(agent->getSteering_force(), agent->getMaxForce()));
	return agent->getSteering_force();
}

sf::Vector2f Overworld::flee(PokemonSafari* agent, sf::Vector2f _targetPos)
{
	sf::Vector2f newVelocity = Normalize(agent->getPos() - _targetPos) * agent->getVitMax();
	agent->setSteering_force(newVelocity - agent->getVelocity());
	agent->setSteering_force(Truncate(agent->getSteering_force(), agent->getMaxForce()));
	return agent->getSteering_force();
}

sf::Vector2f Overworld::pursuit(PokemonSafari* agent, sf::Vector2f _targetPos, sf::Vector2f _targetVel)
{
	float T = min(0.5f, GetNorme(_targetPos - agent->getPos()) / agent->getVitMax());
	sf::Vector2f pos = _targetPos + _targetVel * T;
	return seek(agent, pos);
}

sf::Vector2f Overworld::evasion(PokemonSafari* agent, sf::Vector2f _targetPos, sf::Vector2f _targetVel)
{
	float T = min(0.5f, GetNorme(_targetPos - agent->getPos()) / agent->getVitMax());
	sf::Vector2f pos = _targetPos + _targetVel * T;
	return flee(agent, pos);
}

sf::Vector2f Overworld::arrival(PokemonSafari* agent, sf::Vector2f _targetPos)
{
	float dist = GetNorme(_targetPos - agent->getPos());

	return sf::Vector2f();
}

sf::Vector2f Overworld::obstacleAvoidance(PokemonSafari* agent, vector<Obstacle> _obstacles)
{
	for (auto obs : _obstacles)
	{
		if (Rectangle_Collision(agent->getCollisionDetector()->getGlobalBounds(), ObstacleRect))
		{
			sf::Vector2f avoidance_force = (agent->getPos() + Normalize(agent->getVelocity()) * 100.f) - obs.getCenter();
			avoidance_force = Normalize(avoidance_force) * 100.f;
			return avoidance_force;
		}
	}

	return sf::Vector2f();
}

sf::Vector2f Overworld::wander(PokemonSafari* agent)
{
	sf::Vector2f circleCenter;
	circleCenter = Normalize(agent->getVelocity() * 100.f);

	sf::Vector2f displacement;
	displacement = sf::Vector2f(0.f, 1.f) * 10.f;

	float mWanderAngle = fRand(-10.f, 10.f);

	float length = GetNorme(displacement);
	displacement.x = cos(mWanderAngle) * length;
	displacement.y = sin(mWanderAngle) * length;

	
	sf::Vector2f wanderForce;
	wanderForce = circleCenter + displacement;
	return wanderForce;
}
