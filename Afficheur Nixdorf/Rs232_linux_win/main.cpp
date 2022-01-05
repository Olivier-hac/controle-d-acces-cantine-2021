#include <iostream>

#include "Rs232.h"

using namespace std;


Rs232 *portSerie;
string result;

int main() {
    string port="COM15";
    portSerie=new Rs232(port);

    cout << "Hello world!" << endl;

    int res=portSerie->ouvrir(57600);
    if (res==ERREUR) {
        cout << "Erreur a l'ouverture du port " << port << endl;
        cout << "code erreur : " << portSerie->erreur << endl;
        return -1;
    }

    sleep(2000);
    cout << "port " << port << " ouvert" << endl;
    for (int i=0; i<8; i++) {
        portSerie->envoyerCaractere('P');
        portSerie->recevoir('\n', &result);
        cout << "result:" << result << endl;
        sleep(1000);
        portSerie->envoyerCaractere('1');
        sleep(300);
        portSerie->envoyerCaractere('0');
        sleep(300);
        portSerie->envoyerCaractere('F');
        sleep(10);
    }
    portSerie->fermer();
    return 0;
}
