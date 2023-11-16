#include <iostream>
#include <fstream>
#include "Sauvegarde.h"
using namespace std;

FILE* f;
string fileName;

void writeFolder(string name, int16_t pointVie, uint16_t attaque, float level)
{
    fstream folder;
    folder.open("save.txt", ios::out);
    if (folder.bad()) {
        cout << "erreur ouverture fichier." << endl;
    }else{
        folder << (f, "%s %d %d %f", name, pointVie, attaque, level) << endl;
        folder.close();
    }
}

void readFolder()
{
}
