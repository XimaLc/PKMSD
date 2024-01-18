#pragma once
#include <iostream>
#include <vector>
#include"fstream"
#include"iomanip"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;
using namespace std;

#define Key(x) sf::Keyboard::isKeyPressed(sf::Keyboard::x)
#define Mouse(x) sf::Mouse::isButtonPressed(sf::Mouse::x)
#define TexturePath "..//Files//Textures//"
#define FontsPath "..//Files//Font//"
#define DBPath "..//Files//DB//"

enum Direction { DOWN, LEFT, RIGHT, UP, IDLE };

void restartClock();
float GetDeltaTime();

int iRand(int min, int max);
double frand(float min, float max);

bool Circle_Collision(Vector2f pos1, Vector2f pos2, float rayon1, float rayon2);
bool Rectangle_Collision(FloatRect box1, FloatRect box2);

float lerp(float a, float b, float t);
float lerp2(float a, float b, float f);
Color color_lerp(Color a, Color b, float t);
Vector2f vec2f_lerp(Vector2f a, Vector2f b, float t);
Vector3f vec3f_lerp(Vector3f a, Vector3f b, float t);







