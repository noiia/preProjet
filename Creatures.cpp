#include <iostream>
#include <random>
#include <algorithm>
#include <Windows.h>
#include <string>
#include "Creatures.h"
#include "Heros.h"

using namespace std;


// Déclaration de la liste de créatures
vector<Creatures> Creatures::creaturesList;

Creatures::Creatures(string name, int16_t pointVie,uint16_t attaque, uint16_t niveau, uint8_t id) : nom(name), pv(pointVie), atk(attaque), lv(niveau), id(id) {
	nbCreatures++;
	// La ligne ci-dessous sert à ajouter la nouvelle créature à la liste de créatures en vie
	// *this fait référence à l'élément en cours (la créature ne cours)
	// push_back est une fonction des vecteurs en C++, elle ajoute un élément à la fin du vecteur. Elle augmente automatiquement la taille d'un vecteur et y ajoute la valeur renseignée (la créature ici)
	creaturesList.push_back(*this); 
}
// Ne pas oublier déclarer la variable (et de l'initialiser)
uint16_t Creatures::nbCreatures = 0; // Définition de la variable statique

void Creatures::affiche(int i) {
	switch (i) {
	case 0: // présentation de la créature au joueur
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



// sélectionne une valeur au hasard parmis toutes les créatures en vie
int Creatures::valeurHasardEnnemi() {
	// Utiliser un moteur de génération de nombres aléatoires
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> distribution(0, Creatures::getNbCreatures()-1); // écart créé entre 0 et le nombre de creatures en jeu

	// Générer un nombre aléatoire entre 0 et 3
	return distribution(gen);
}

// récupère la créature à partir de son id
Creatures Creatures::getCreatureById(int id) {
	// On déclare ici une variable creature pour chaque élément du vecteur creaturesList
	// les arguments "const auto&" servent à définir automatiquement le type de chaque vecteur et de le traiter comme une référence constante sans copie 
	for ( auto& creature : Creatures::creaturesList) {
		// si le vecteur creature est défini en tant que constante, il ne faut pas oublier de définir la méthode recupID() en tant que constante
		if (creature.recupID() == id) {
			return creature;
		}
	}
	// Si aucune créature correspondante n'est trouvée, vous pouvez retourner une créature par défaut ou générer une exception, selon vos besoins.
	// Ici, nous retournons une créature avec des valeurs par défaut.
	return Creatures("default", 0, 0, 0, -1);
}

bool Creatures::operator==(const Creatures& other) const {
	// Logique de comparaison, basée sur ce qui constitue l'égalité pour deux créatures
	return this->id == other.id ; // Ou utilisez une autre logique selon vos besoins
}

// retire une creature de la liste à partir de son id
void Creatures::eraseCreaturesInList(int id)
{
	// find sert à trouver la valeur dans le vecteur creatureList
	// auto sert à déclarer automatiquement la variable it
	// on déclare le début du vecteur, la fin du vecteur, la valeur à supprimer ici le lambda 
	// le troisième argument est ce qu'on appelle un lambda, il va servir pour la comparaison
	// [id] capture la valeur d'id pour être comparé
	// (const Creatures& creature) déclare un paramètre de la lambda, représentant chaque élément du vecteur pendant la recherche
	// { return creature.recupID() == id;} sert lui de logique de comparaison, ici une correspondance exacte entre l'id en argument de la fonction et l'id de la creature en cours
	//auto it = find(creaturesList.begin(), creaturesList.end(), [id]( Creatures& creature) {return creature.recupID() == id;});
	auto it = find(creaturesList.begin(), creaturesList.end(), Creatures("", 0, 0, 0, id));
	creaturesList.erase(it); // erase l'itération it récupérée, la créature correspondant à l'ID
	
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

