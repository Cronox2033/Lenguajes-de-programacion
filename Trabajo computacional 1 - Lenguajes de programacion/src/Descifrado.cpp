#include <iostream>
#include <string>
#include "Descifrado.h"
using namespace std;

Descifrado::Descifrado()
{
    MensajeD = " ";
    ClaveD = " ";
}

Descifrado::~Descifrado()
{
    //dtor
}

void Descifrado::Set_MensajeD(string men){
    MensajeD = men;
}

string Descifrado::Get_MensajeD(){return MensajeD;}

void Descifrado::Set_ClaveD(string cl){
    ClaveD = cl;
}

string Descifrado::Get_ClaveD(){return ClaveD;}

char *Descifrado::Descifrador(){
    Mensaje_Descifrado = new char [MensajeD.length()];
    int aux,aux2[ClaveD.length()],cont = 0,temp;
    for(int i=0; ClaveD[i]!= NULL; i++){
        for(int k = 0; k<26; k++){
            if(ClaveD[i]==AlfabetoD[k]){aux2[i]=k;}
        }
    }
    for(int i = 0; MensajeD[i]!= NULL; i++){
        if(MensajeD[i]!=' '){
            for(int j = 0; j<26; j++){
                if(MensajeD[i] == AlfabetoD[j]){aux = j;}
            }
            temp = aux-aux2[cont];
            if(temp<0){
                Mensaje_Descifrado[i] = AlfabetoD[26+temp];
            }
            else{Mensaje_Descifrado[i] = AlfabetoD[temp];}
            cont++;
            if(cont==ClaveD.length()){cont = 0;}
        }
        else{Mensaje_Descifrado[i] =' ';}
    }
    return Mensaje_Descifrado;
}
