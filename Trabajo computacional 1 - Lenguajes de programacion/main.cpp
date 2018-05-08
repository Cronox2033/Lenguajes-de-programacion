#include <iostream>
#include <string>
#include "Cifrado.h"
#include "Descifrado.h"
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
    Descifrado Des;
    Cif.Set_Clave("TAQUION");
    Cif.Set_Mensaje("LENGUAJES DE PROGRAMACION");
    Des.Set_ClaveD("TAQUION");
    Des.Set_MensajeD("EEDACOWXS TY XFBZRQGIQVHN");
    h= Des.Get_MensajeD();
    men = Des.Descifrador();
    for(int i = 0; i<h.length(); i++){
        cout<<men[i];
    }
    cout<<endl;
    hola(men,h.length());
    return 0;
}
