#pragma once
#include <iostream>
#include <vector>
#include"fstream"
#include"iomanip"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;
using namespace std;

#define RAD2DEG 57.295779f
//RAD2DEG multiplier par DEG2RAD pour avoir les radiants
#define DEG2RAD 0.017453f
//DEG2RAD multiplier par RAD2DEG pour avoir les degrés
#define PI 3.14159265358979323846

#define Key(x) sf::Keyboard::isKeyPressed(sf::Keyboard::x)
#define Mouse(x) sf::Mouse::isButtonPressed(sf::Mouse::x)
#define TexturePath "../Files/Textures/"
#define FontsPath "../Files/Font/"
#define DBPath "../Files/DB/"

enum Direction { DOWN, UP, LEFT, RIGHT, IDLE };

void restartClock();
float GetDeltaTime();

int iRand(int min, int max);
float fRand(float min, float max);

bool Circle_Collision(Vector2f pos1, Vector2f pos2, float rayon1, float rayon2);
bool Rectangle_Collision(FloatRect box1, FloatRect box2);

float lerp(float a, float b, float t);
float lerp2(float a, float b, float f);
Color color_lerp(Color a, Color b, float t);
Vector2f vec2f_lerp(Vector2f a, Vector2f b, float t);
Vector3f vec3f_lerp(Vector3f a, Vector3f b, float t);

float GetDistance(sf::Vector2f a_, sf::Vector2f b_);

sf::Vector2f SubstractVector2f(sf::Vector2f a, sf::Vector2f b);

sf::Vector2f DivideVector2f(sf::Vector2f a, float b);

float DotProduct(sf::Vector2f a, sf::Vector2f b);

float GetNorme(sf::Vector2f a);

sf::Vector2f Normalize(sf::Vector2f v);

float GetSignedAngleBetween(sf::Vector2f a, sf::Vector2f b);

float GetAngleBetween(sf::Vector2f a, sf::Vector2f b);

float GetAngle(sf::Vector2f a, sf::Vector2f b);

sf::Vector2f Truncate(const sf::Vector2f& v, float max);






