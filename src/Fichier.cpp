#include "Fichier.h"

using namespace std;

Fichier::Fichier(string leNom)
{
    nom=leNom;
    //ctor
}

void Fichier::ouvrir(char mode) {
    if (mode=='a') fichier.open(nom.c_str(), fstream::app);
    else if (mode=='r') fichier.open(nom.c_str(), fstream::in);
    else if (mode=='w') fichier.open(nom.c_str(), fstream::out);
}

void Fichier::ecrire1Ligne(string chaine) {
    fichier << chaine << endl;
}

void Fichier::fermer() {
    fichier.close();
}
