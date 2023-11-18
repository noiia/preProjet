#pragma once
#include "FormMenu.h"
#include "BDD.h"
#include <exception>


using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int __clrcall WinMain(array<String^>^ args)
{
    try{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Détailles de la fonction suivante
    // preProjet::FormMenu -> nom de la méthode au sein de la class
    // ^ -> symbole de gestion automatique de la mémoire, défini l'objet comme managé
    // monFormulaire -> est la variable qui va prendre l'instance de FormMenu
    // gcnew -> est l'opérateur utilisé pour créer et allouer un nouvel objet managée sur le tas 
    // preProjet::FormMenu() -> appel au constructeur par défaut de la classe 
    //Je te conseille d'init ta bdd dans le main et la refiler ensuite a toutes tes futures fenetres
    BDD^ bdd = gcnew BDD();

    preProjet::FormMenu^ monFormulaire = gcnew preProjet::FormMenu(bdd);
    Application::Run(monFormulaire);
    }
    catch (Exception^ ex) {
    // Gérer l'exception ici (affichage de message d'erreur, journalisation, etc.)
    MessageBox::Show("Une exception s'est produite : " + ex->Message, "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
//void jeu();