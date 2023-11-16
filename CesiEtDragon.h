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

    // D�tailles de la fonction suivante
    // preProjet::FormMenu -> nom de la m�thode au sein de la class
    // ^ -> symbole de gestion automatique de la m�moire, d�fini l'objet comme manag�
    // monFormulaire -> est la variable qui va prendre l'instance de FormMenu
    // gcnew -> est l'op�rateur utilis� pour cr�er et allouer un nouvel objet manag�e sur le tas 
    // preProjet::FormMenu() -> appel au constructeur par d�faut de la classe 
    preProjet::FormMenu^ monFormulaire = gcnew preProjet::FormMenu();
    Application::Run(monFormulaire);
    }
    catch (Exception^ ex) {
    // G�rer l'exception ici (affichage de message d'erreur, journalisation, etc.)
    MessageBox::Show("Une exception s'est produite : " + ex->Message, "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
//void jeu();