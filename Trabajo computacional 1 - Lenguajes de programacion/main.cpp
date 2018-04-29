#include <iostream>
#include <string>
#include "Cifrado.h"

using namespace std;

void hola(char *asd,int l){
    for (int i=0; i<l;i++){
        cout<<asd[i];
    }
}

int main()
{
    char *men;
    string h;
    Cifrado Cif;
    Cif.Set_Clave("TAQUION");
    Cif.Set_Mensaje("LENGUAJES DE PROGRAMACION");
    h= Cif.Get_Mensaje();
    men = Cif.Cifrador();
    for(int i = 0;i<h.length();i++){
        cout << men[i];
    }
    cout<<endl;
    hola(men,h.length());
    cout<<endl;
    cout<<Cif.V_Clave("AAAAAA")<<endl;
    return 0;
}
