#include <iostream>
#include <locale>
#include <windows.h>
#include <random>
#include <fstream>
#include <vector>
#include <string>
#include <array>
#include <sstream>

#include "Creatures.h"
#include "Heros.h"
#include "Sauvegarde.h"

array <string, 20> nomAtkCrea = { "coup de burne", "attaque au pigeon", "queue de fer", "etoile des tartes" };

void jeu() {
	std::cout << "Bienvenue dans CESI et Dragon le jeu que vous attendiez depuis le siecle precedent." << endl << endl;
	// création des différents personnages
	ifstream fichier;
	fichier.open("Data.csv", ios::out);
	string CreaName, CreaPv, CreaAtk, CreaLv;
	// Vérifie si le fichier est ouvert correctement
	if (!fichier.is_open()) {
		cerr << "Erreur lors de l'ouverture du fichier." << endl;
	}

	vector<Creatures> donnees;  // Stocke les données CSV

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

	// Actions de jeu
	bool limited;

	std::cout << "Creons ton personnage, comment veux-tu l'appeler ?" << endl;
	string name;
	std::cin >> name;
	std::cout << "Combien de points de vie veux-tu (entre 1 et 10, attention avoir plus de vie impact l'attaque) ?" << endl;
	int pv, atk;
	std::cin >> pv;
	if (pv > 10) {
		pv = 10;
		std::cout << "valeur depassant la limites superieur, nouvelle valeur de pv : " << pv << endl;
	}
	else if (pv >= 7) {
		atk = 1;
	}
	else if (pv >= 5) {
		atk = 2;
	}
	else if (pv >= 2) {
		atk = 3;
	}
	else if (pv >= 1) {
		atk = 4;
	}
	else if (pv < 1) {
		pv = 1;
		std::cout << "valeur depassant la limites inferieur, nouvelle valeur de pv : " << pv << endl;
	}
	std::cout << "Proportionnellement a la vie que tu as renseignee, voici tes points d'attaque " << atk << endl;

	float lv = 0;
	Heros Hero(name, pv, atk, lv);
	Hero.affiche(0);
	bool running_1 = true;
	bool running_2 = true;
	while (running_1) {
		writeFolder(name, pv, atk, lv);
		int action;
		Hero.affiche(2);
		Creatures ennemiPresent = Creatures::getCreatureById(Creatures::valeurHasardEnnemi());
		running_2 = true;
		while (running_2) {
			std::cout << " WOOOW ";
			ennemiPresent.affiche(0);
			std::cout << "t\'as surpris, que faire ? (1:attaquer, 2:fuir, 3:quitter le jeu) " << endl;
			scanf_s("%d", &action);
			fseek(stdin, 0, SEEK_END); // vidage du buffer
			switch (action) {
			case 1:
				action = 0;
				std::cout << "je vais te meler tous tes morts ";
				ennemiPresent.affiche(2);
				std::cout << endl;
				Hero.attaque(ennemiPresent);
				std::cout << Hero.estMort() << "  " << ennemiPresent.estMort() << endl;

				if (ennemiPresent.estMort() == 1) {
					std::cout << "tu étais un bon le sang" << endl;
					ennemiPresent.giveXP(Hero);
					running_2 = false;
					break;
				}
				else if (Hero.estMort() == 1) {
					std::cout << "Game over billy ";
					ennemiPresent.affiche(2);
					std::cout << " t'as monte en l'air";
					running_1 = false;
					running_2 = false;
					break;
				}
				else {
					ennemiPresent.affiche(2);
					std::cout << " passe a l'attaque." << endl;
					ennemiPresent.attaque(Hero);

				}
				break;
			case 2:
				action = 0;
				std::cout << "tu prends la poudre d'escampète" << endl;
				running_2 = false;
				break;
			case 3:
				std::cout << "aurevoir ";
				Hero.affiche(3);
				running_2 = false;
				break;
			default:
				SetConsoleTextAttribute(hConsole, 6);
				std::cout << "choix invalide, veuillez selectionner la bonne valeur" << endl;
				SetConsoleTextAttribute(hConsole, 15);
				break;
			}
		}
	}
}