#include "Lecteur.h"

using namespace std;

Lecteur::Lecteur()
{
    cout << "Constructeur Lecteur" << endl;
}

Lecteur::~Lecteur()
{
    //dtor
}

string Lecteur::lireID() {
    cout << "Lecture de l'ID sur la carte" << endl;
    return "12345";
    //return "56789";
    //return "04560";
}
