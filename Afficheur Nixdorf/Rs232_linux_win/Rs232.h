#ifndef RS232_H
#define RS232_H

#include <iostream>

//----------------------------------------------------------------------------
#define AVEC_FINAL	0
#define SANS_FINAL	1

//----------------------------------------------------------------------------
#define	AVEC_TIME_OUT	true
#define	SANS_TIME_OUT	false

//----------------------------------------------------------------------------
#define OK		0
#define ERREUR 	-1
#define TIMEOUT	-2
#define RIEN_RECU 1


#if defined(__linux__) || defined(__FreeBSD__)   /*------------- Linux & FreeBSD ------------------*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <time.h>

#else /*----------------- Windows --------------------*/

#include <windows.h>
#include <stdio.h>
#include <time.h>

#endif  /*------------ on a choisit linux ou windows ----------------*/

using namespace std;

class Rs232
{
    public:
        string erreur;
        string port;

        Rs232(string port);
        virtual ~Rs232();
        int ouvrir(int vitesse=9600, int nbBits=8, char parite='n', int nbStops=1, bool flowCtrl=false);
        void fermer();

        // Envoyer une chaine de caractère
        int envoyerChaine(string chaine);
        int envoyerCaractere(char car);

        // Recevoir Nb caractères
        int recevoir(int nb, string *chaine);

        // Recevoir une chaîne se terminant par un caractère donné
        // (\r, \n ou autre)
        // avec ou sans time out
        int recevoir(char carFin, string *chaine, bool avecCarFin=false);
        int recevoir(char fin, string *chaine, bool avecCarFin, int nbSecTimeOut);

        // Recevoir un caracère avec time out
        int recevoirCaractere(char* caractere, int nbSecTimeOut);

        // Recevoir un fichier
        int recevoirFichier(string nomFichier, int attenteDebut);
    protected:

    private:

#if defined(__linux__) || defined(__FreeBSD__)   /*------------- Linux & FreeBSD ------------------*/
    #include "Rs232.h.linux"
#else /*----------------- Windows --------------------*/
    #include "Rs232.h.windows"
#endif  /*------------ on a choisit linux ou windows ----------------*/

};

#endif // RS232_H
