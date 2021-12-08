#include "Voyants.h"

using namespace std;

Voyants::Voyants()
{
    cout << "Constructeur Voyants" << endl;
}

Voyants::~Voyants()
{
    //dtor
}

void Voyants::allumer(int couleur) {
    cout << "Allumer les voyants . Couleur : " << couleur << endl;
}
