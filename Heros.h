#pragma once
#include <string>

using namespace std;

class Creatures;

class Heros {
private:
	string nom;
	int16_t pv;
	uint16_t atk;
	float lv;
public:
	Heros(string name, int16_t pointVie, uint16_t attaque, float level);
	void affiche(int i);
	void attaque(Creatures& c);
	void subitDegat(int degat);
	bool chanceEchecAtk();
	bool estMort();
	void levelUp(int level);
};