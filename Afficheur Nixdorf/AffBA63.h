#if !defined(AffBA63_H)
#define AffBA63_H

/**********************************************
 classe AffBA63
**********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define TAILLE_TRAME 50

class AffBA63
{
private:
    /* data */
    int fd_serie;
    unsigned char trame[TAILLE_TRAME];
    int send_data(unsigned char *buf, int psize);
    int myseropen(const char *dev);
public:
    AffBA63(const char *dev);
    ~AffBA63();
    bool error;
    void effaceEcran();
    void placeCurseur(int ligne, int colonne);
    void ecritChaine(const char *chaine);
    void ecritChaine(const char *chaine, int size);
	void reculeDuneCase();
	void ligneSuivante();
	void debutLigne();
	void effaceFinLigne();
	void defPays(int codePays);
	char *afficheIdentification(); 
};

#endif // AffBA63_H

