#include "tools.h"

sf::Clock sfclock;
sf::Time sfTime;

void restartClock()
{
	sfTime = sfclock.restart();
}
float GetDeltaTime()
{
	return sfTime.asSeconds();
}

int iRand(int min, int max)
{ 
	return rand() % (max - min) + min;
}
float fRand(float min, float max)
{
	return ((rand() / (double)RAND_MAX) * ((double)max - (double)min) + (double)min);
}

bool Circle_Collision(Vector2f pos1, Vector2f pos2, float rayon1, float rayon2)
{
	if ((pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) * (pos1.y - pos2.y) < (rayon1 + rayon2) * (rayon1 + rayon2))
		return true;
	else return false;
}
bool Rectangle_Collision(FloatRect box1, FloatRect box2)
{
	if ((box2.left >= box1.left + box1.width) || (box2.left + box2.width <= box1.left) || (box2.top >= box1.top + box1.height) || (box2.top + box2.height <= box1.top)) 
		return false;
	else
		return true;
}

float lerp(float a, float b, float t)
{
	return (1 - t) * a + t * b;
}
float lerp2(float a, float b, float f)
{
	return a * (1.0 - f) + (b * f);
}
Color color_lerp(Color a, Color b, float t)
{
	Color tmp;
	tmp.r = (1 - t) * a.r + t * b.r;
	tmp.g = (1 - t) * a.g + t * b.g;
	tmp.b = (1 - t) * a.b + t * b.b;
	tmp.a = (1 - t) * a.a + t * b.a;
	return tmp;
}
Vector2f vec2f_lerp(Vector2f a, Vector2f b, float t)
{
	Vector2f tmp;
	tmp.x = (1 - t) * a.x + t * b.x;
	tmp.y = (1 - t) * a.y + t * b.y;
	return tmp;
}
Vector3f vec3f_lerp(Vector3f a, Vector3f b, float t)
{
	Vector3f tmp;
	tmp.x = (1 - t) * a.x + t * b.x;
	tmp.y = (1 - t) * a.y + t * b.y;
	tmp.z = (1 - t) * a.z + t * b.z;
	return tmp;
}

float GetDistance(sf::Vector2f a_, sf::Vector2f b_)
{
	return sqrt((b_.x - a_.x) * (b_.x - a_.x) + (b_.y - a_.y) * (b_.y - a_.y));
}

sf::Vector2f SubstractVector2f(sf::Vector2f a, sf::Vector2f b)
{
	sf::Vector2f substractVector2 = { a.x - b.x, a.y - b.y };
	return substractVector2;
}

sf::Vector2f DivideVector2f(sf::Vector2f a, float b)
{
	sf::Vector2f divideVector2 = { a.x / b, a.y / b };
	return divideVector2;
}

float DotProduct(sf::Vector2f a, sf::Vector2f b)
{
	return b.x * a.x + b.y * a.y;
}

float GetNorme(sf::Vector2f a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

sf::Vector2f Normalize(sf::Vector2f v)
{
	return DivideVector2f(v, GetNorme(v));
}

float GetSignedAngleBetween(sf::Vector2f a, sf::Vector2f b)
{
	return atan2(a.x * b.y - a.y * b.x, a.x * b.x + a.y * b.y);
}

float GetAngleBetween(sf::Vector2f a, sf::Vector2f b)
{
	return fabs(GetSignedAngleBetween(a, b));
}

float GetAngle(sf::Vector2f a, sf::Vector2f b)
{
	return atan2(a.x * b.y - a.y * b.x, DotProduct(a, b));
}

sf::Vector2f Truncate(const sf::Vector2f& v, float max)
{
	sf::Vector2f truncated = sf::Vector2f(v.x, v.y);
	if (sqrt(v.x * v.x + v.y * v.y) > max)
	{
		truncated = Normalize(truncated) * max;
	}
	return truncated;
}