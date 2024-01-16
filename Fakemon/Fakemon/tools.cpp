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
double frand(float min, float max)
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