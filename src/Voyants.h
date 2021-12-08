#ifndef VOYANTS_H
#define VOYANTS_H

#include <iostream>

#define ETEINT 0
#define ROUGE 1
#define VERT 2

using namespace std;

class Voyants
{
    public:
        Voyants();
        ~Voyants();
        void allumer(int couleur);

    protected:

    private:
};

#endif // VOYANTS_H
