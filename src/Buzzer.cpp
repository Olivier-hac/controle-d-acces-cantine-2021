#include "Buzzer.h"

using namespace std;

Buzzer::Buzzer()
{
    cout << "Constructeur Buzzer" << endl;
}

Buzzer::~Buzzer()
{
    //dtor
}

void Buzzer::bipper(int nbBips) {
    cout << "Bipper " << nbBips << " fois"<< endl;
}
