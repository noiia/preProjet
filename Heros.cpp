#include <iostream>
#include <random>
#include <algorithm>
#include <Windows.h>
#include <string>
#include "Heros.h"
#include "Creatures.h"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Heros::Heros(string name, int16_t pointVie, uint16_t attaque, float level) : nom(name), pv(pointVie), atk(attaque), lv(level) {}

// fonctions d'affichage
void Heros::affiche(int i) {
	switch (i) {
	case 0: // présentation du héros
		cout << "Enchante " << this->nom << ", tu possedes donc " << this->pv << " points de vie et " << this->atk << " points d\'attaque." << endl;
		break;
	case 1: // stats en direct
		cout << "(" << this->pv << ", " << this->atk << ", " << this->lv << ")" << endl;
		break;
	case 2:
		cout << endl << endl << "Bien " << this->nom << ", tu possedes maintenant " << this->pv << " points de vie et " << this->atk << " points d\'attaque." << endl;
	case 3:
		cout << this->nom;
	}
}

// Fonctions d'attaque 

void Heros::attaque(Creatures& c) {
	int copyAtk = this->atk ;
	if (chanceEchecAtk() == true) {
		cout << this->nom << ", tu n'attaque donc pas à ce tour." << endl;
		this->atk = copyAtk;
	}
	else {
		int degats = this->atk;
		c.subitDegat(degats);

		SetConsoleTextAttribute(hConsole, 12);
		cout << this->nom << " attaque la creature et lui inflige " << degats << " degats." << endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
}

// fonction de déduction des points de vie perdus durant l'attaque

void Heros::subitDegat(int degat) {
	pv -= degat;
	if (pv < 0) {
		pv = 0;
	}
}

bool Heros::chanceEchecAtk()
{
	// Utiliser un moteur de génération de nombres aléatoires
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> distribution(0, 10); // écart créé entre 0 et le nombre de creatures en jeu
	float copyAtk = this->atk;
	if (distribution(gen) < 2) {
		this->atk = 0;
		std::cout << "mince, tu as rate ton attaque." << endl;
		return true;
	} else if (distribution(gen) > 8) {
		this->atk *= 1.5;
		std::cout << "mama mon copain t'es chaud aujd" << endl;
	}
	this->atk = copyAtk;
}

// Vérification du status du personnage
bool Heros::estMort()
{
	if (this->pv < 1) {
		return true;
	}
	return false;
}

void Heros::levelUp(int level)
{
	this->lv += level;
	cout << "voici ton nouveau niveau heros " << this->lv << endl;
	if (lv >= 3 && atk < 5) {
		this->atk += 2;
		cout << "Bien joue mon suisse, tu es passe a " << this->atk << " points d'attaque." << endl;

	}
	else if (lv >= 6 && atk < 7) {
		this->atk += 2;
		cout << "Oh bah ma gueule... tu te surpasses, tu passe a " << this->atk << " points d'attaque. *inserer emoji heureux* " << endl;

	}
	else if (lv >= 10) {
		this->atk += 20;
		this->nom = "Billy le Beau gosse";
	}
}