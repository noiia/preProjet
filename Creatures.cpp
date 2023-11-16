#include <iostream>
#include <random>
#include <algorithm>
#include <Windows.h>
#include <string>
#include "Creatures.h"
#include "Heros.h"

using namespace std;


// D�claration de la liste de cr�atures
vector<Creatures> Creatures::creaturesList;

Creatures::Creatures(string name, int16_t pointVie,uint16_t attaque, uint16_t niveau, uint8_t id) : nom(name), pv(pointVie), atk(attaque), lv(niveau), id(id) {
	nbCreatures++;
	// La ligne ci-dessous sert � ajouter la nouvelle cr�ature � la liste de cr�atures en vie
	// *this fait r�f�rence � l'�l�ment en cours (la cr�ature ne cours)
	// push_back est une fonction des vecteurs en C++, elle ajoute un �l�ment � la fin du vecteur. Elle augmente automatiquement la taille d'un vecteur et y ajoute la valeur renseign�e (la cr�ature ici)
	creaturesList.push_back(*this); 
}
// Ne pas oublier d�clarer la variable (et de l'initialiser)
uint16_t Creatures::nbCreatures = 0; // D�finition de la variable statique

void Creatures::affiche(int i) {
	switch (i) {
	case 0: // pr�sentation de la cr�ature au joueur
		cout << "Voici le monstre " << this->nom << endl;
		cout << "Points de vie de la creature : " << this->pv << endl;
		cout << "Niveau du monstre : " << this->lv << endl;
		break;
	case 1: // stats en direct
		cout << this->nom<< endl << "(" << this->pv << ", " << this->atk << ", " << this->lv << ")" << endl;
		break;
	case 2: // nom du monstre
		cout << this->nom;
		break;
	}

}

void Creatures::attaque(Heros& h) {
	int degats = this->atk;
	h.subitDegat(degats);
	SetConsoleTextAttribute(hConsole, 11);
	cout << this->nom << " attaque le heros et lui inflige " << degats << " degats." << endl;
	SetConsoleTextAttribute(hConsole, 15);

}

void Creatures::subitDegat(int degat) {
	pv -= degat;
	if (pv < 0) {
		pv = 0;
	}
}


// retourne le nombre de creatures encore en vie 
int Creatures::getNbCreatures()
{
	return nbCreatures;
}
// retourne l'id de la creature
int Creatures::recupID()  {
	return this->id;
}



// s�lectionne une valeur au hasard parmis toutes les cr�atures en vie
int Creatures::valeurHasardEnnemi() {
	// Utiliser un moteur de g�n�ration de nombres al�atoires
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> distribution(0, Creatures::getNbCreatures()-1); // �cart cr�� entre 0 et le nombre de creatures en jeu

	// G�n�rer un nombre al�atoire entre 0 et 3
	return distribution(gen);
}

// r�cup�re la cr�ature � partir de son id
Creatures Creatures::getCreatureById(int id) {
	// On d�clare ici une variable creature pour chaque �l�ment du vecteur creaturesList
	// les arguments "const auto&" servent � d�finir automatiquement le type de chaque vecteur et de le traiter comme une r�f�rence constante sans copie 
	for ( auto& creature : Creatures::creaturesList) {
		// si le vecteur creature est d�fini en tant que constante, il ne faut pas oublier de d�finir la m�thode recupID() en tant que constante
		if (creature.recupID() == id) {
			return creature;
		}
	}
	// Si aucune cr�ature correspondante n'est trouv�e, vous pouvez retourner une cr�ature par d�faut ou g�n�rer une exception, selon vos besoins.
	// Ici, nous retournons une cr�ature avec des valeurs par d�faut.
	return Creatures("default", 0, 0, 0, -1);
}

bool Creatures::operator==(const Creatures& other) const {
	// Logique de comparaison, bas�e sur ce qui constitue l'�galit� pour deux cr�atures
	return this->id == other.id ; // Ou utilisez une autre logique selon vos besoins
}

// retire une creature de la liste � partir de son id
void Creatures::eraseCreaturesInList(int id)
{
	// find sert � trouver la valeur dans le vecteur creatureList
	// auto sert � d�clarer automatiquement la variable it
	// on d�clare le d�but du vecteur, la fin du vecteur, la valeur � supprimer ici le lambda 
	// le troisi�me argument est ce qu'on appelle un lambda, il va servir pour la comparaison
	// [id] capture la valeur d'id pour �tre compar�
	// (const Creatures& creature) d�clare un param�tre de la lambda, repr�sentant chaque �l�ment du vecteur pendant la recherche
	// { return creature.recupID() == id;} sert lui de logique de comparaison, ici une correspondance exacte entre l'id en argument de la fonction et l'id de la creature en cours
	//auto it = find(creaturesList.begin(), creaturesList.end(), [id]( Creatures& creature) {return creature.recupID() == id;});
	auto it = find(creaturesList.begin(), creaturesList.end(), Creatures("", 0, 0, 0, id));
	creaturesList.erase(it); // erase l'it�ration it r�cup�r�e, la cr�ature correspondant � l'ID
	
	cout << "creature " << id << " supprimee de la liste" <<endl;
}


bool Creatures::estMort()
{
	if (this->pv < 1) {
		nbCreatures--;
		eraseCreaturesInList(Creatures::recupID());
		return true;
	}
	return false;
}

void Creatures::giveXP(Heros& h) {
	int xp = this->lv; 
	h.levelUp(xp);
}

