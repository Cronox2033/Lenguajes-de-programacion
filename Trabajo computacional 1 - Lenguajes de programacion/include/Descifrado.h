#include <iostream>
#include <string>
#ifndef DESCIFRADO_H
#define DESCIFRADO_H

#include <Cifrado.h>
using namespace std;

class Descifrado : public Cifrado
{
    public:
        Descifrado();
        virtual ~Descifrado();
        void Set_MensajeD(string men);
        string Get_MensajeD();
        void Set_ClaveD(string cl);
        string Get_ClaveD();
        char *Descifrador();

    protected:

    private:
        char *Mensaje_Descifrado = NULL;
        string MensajeD;
        string ClaveD;
        char AlfabetoD[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
};

#endif // DESCIFRADO_H
