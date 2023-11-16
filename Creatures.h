#pragma once
#include <string>

using namespace std;
extern void* hConsole;
class Heros;

class Creatures {
private:
	string nom;
	int16_t pv;
	uint16_t atk;
	uint16_t lv;
	uint8_t id;
	static uint16_t nbCreatures;
public:
	Creatures(string name, int16_t pointVie ,uint16_t attaque, uint16_t niveau, uint8_t id);
	void affiche(int i);
	void attaque(Heros& h);
	void subitDegat(int degat);
	bool estMort();
	static int getNbCreatures();
	static int valeurHasardEnnemi();
	int recupID();
	static vector<Creatures> creaturesList;  // Déclaration de la liste de type vector<Creatures>
	static Creatures getCreatureById(int id);
	static void eraseCreaturesInList(int id);
	bool operator==(const Creatures& other) const;
	void giveXP(Heros& h);
};