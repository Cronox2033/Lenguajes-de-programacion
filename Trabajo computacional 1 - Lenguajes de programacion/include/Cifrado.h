#include <iostream>
#include <string>
#ifndef CIFRADO_H
#define CIFRADO_H
using namespace std;

class Cifrado
{
    public:
        Cifrado();
        virtual ~Cifrado();
        bool Verificador(string palabra);
        char *Cifrador();
        void Set_Mensaje(string men);
        string Get_Mensaje();
        void Set_Clave(string cl);
        string Get_Clave();
        bool V_Clave(string palabra);

    protected:

    private:
        char *Mensaje_cifrado = NULL;
        string Mensaje;
        string Clave;
        char Alfabeto[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
};

#endif // CIFRADO_H
