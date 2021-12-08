#include "Afficheur.h"

using namespace std;

Afficheur::Afficheur()
{
    cout << "Constructeur Afficheur" << endl;
}

Afficheur::~Afficheur()
{
    //dtor
}

void Afficheur::afficher(string texte) {
    cout << "Afficher : " << texte << endl;
}
