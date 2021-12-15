#include <iostream>

#include "Distributeur.h"
#include "Lecteur.h"
#include "Buzzer.h"
#include "Voyants.h"
#include "Leds.h"
#include "FichierAcceCsv.h"
#include "FichierAccesLog.h"
#include "Afficheur.h"

using namespace std;

int main()
{
    cout << "Application !" << endl << endl;

    cout << "----- instanciation des objets -----s" << endl;
    Distributeur distributeur;
    Lecteur lecteur;
    Afficheur afficheur;
    Buzzer buzzer;
    FichierAcceCsv fichierCSV((string)"acces.csv");
    FichierAccesLog fichierLOG((string)"acces.log");
    Voyants voyants;
    Leds leds;

    cout << endl;
    //on lit l'ID sur le lecteur
    string ID=lecteur.lireID();
    cout << "Id lu : " << ID << endl;

    //lecture des infos de l'utilisateur
    string nomEtat=fichierCSV.lireInfos(ID);
    cout << "nom+etat:" << nomEtat << endl;

    int pos=nomEtat.find(';');
    string nom=nomEtat.substr(0,pos);
    char etat=nomEtat[pos+1];

    //cout << "; trouvé à la position " << pos << endl;
    //string nom="inconnu";
    //char etat='R';

    afficheur.afficher(nom);

    if (nom!="inconnu") { //l'ID est connu
            if (etat=='A') { //autorisé
                distributeur.distribuer();
                buzzer.bipper(1);
                voyants.allumer(VERT); //vert
            } else { //si pas autorisé

                buzzer.bipper(2);
                voyants.allumer(ROUGE); //rouge
             }
    } else { //ID est inconnu
        buzzer.bipper(3);
        voyants.allumer(ROUGE); //rouge
    }

    fichierLOG.ecrireJournal("98765","tata",'A');


    return 0;
}
