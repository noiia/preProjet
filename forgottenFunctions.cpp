// Ce fichier r�pertorie les fonctions utiles mais abandonn�es avec leurs desciptions si besoin
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <array>
#include <sstream>
#include "Creatures.h"


using namespace std;

void readCSVFile() {
	// cr�ation des diff�rents personnages
	std::ifstream fichier;
	fichier.open("Data.csv", ios::out);
	std::string CreaName, CreaPv, CreaAtk, CreaLv;
	// V�rifie si le fichier est ouvert correctement
	if (!fichier.is_open()) {
		cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
	}

	vector<Creatures> donnees;  // Stocke les donn�es CSV

	string ligne;
	int i = 0;
	while (getline(fichier, ligne)) {

		istringstream streamLigne(ligne);

		string colonne;
		getline(streamLigne, colonne, ',');
		string nom = colonne;
		getline(streamLigne, colonne, ',');
		int atk = stoi(colonne);
		getline(streamLigne, colonne, ',');
		int pv = stoi(colonne);
		getline(streamLigne, colonne, ',');
		int niveau = stoi(colonne);

		Creatures creature(nom, atk, pv, niveau, i++);
		creature.affiche(1);
		donnees.push_back(creature);
	}
}
	
