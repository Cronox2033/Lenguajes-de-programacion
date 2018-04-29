#include <iostream>
#include <string>
#include "Cifrado.h"
using namespace std;

Cifrado::Cifrado()
{
    Mensaje = " ";
    Clave = " ";
}

Cifrado::~Cifrado()
{
    //dtor
}

 bool Cifrado::Verificador(string palabra){
    int y = 0,cont = 0;
    for(int i = 0; palabra[i] != NULL; i++){
        y = palabra[i];
        if(y < 65 || y >90){cont++;}
        if(y == 32){cont--;}
    }
    if(cont == 0){return true;}
    else{return false;}
 }


char *Cifrado::Cifrador(){
    Mensaje_cifrado = new char [Mensaje.length()];
    int aux,aux2[Clave.length()],cont = 0;
    for(int i=0; Clave[i]!= NULL; i++){
        for(int k = 0; k<26; k++){
            if(Clave[i]==Alfabeto[k]){aux2[i]=k;}
        }
    }
    for(int i = 0; Mensaje[i]!= NULL; i++){
        if(Mensaje[i]!=' '){
            for(int j = 0; j<26; j++){
                if(Mensaje[i] == Alfabeto[j]){aux = j;}
            }

            Mensaje_cifrado[i]=Alfabeto[(aux+aux2[cont])%26];
            cont++;
            if(cont==Clave.length()){cont = 0;}
        }
        else{Mensaje_cifrado[i] =' ';}
    }
    return Mensaje_cifrado;
}

void Cifrado::Set_Mensaje(string men){
    Mensaje = men;
}

string Cifrado::Get_Mensaje(){return Mensaje;}

void Cifrado::Set_Clave(string cl){
    Clave = cl;
}

string Cifrado::Get_Clave(){return Clave;}

bool Cifrado::V_Clave(string palabra){
    int y = 0;
    if(palabra.length()>8 || palabra.length()<5 || palabra.length()>Mensaje.length()){return false;}
    for(int i = 0; palabra[i] != NULL; i++){
        y = palabra[i];
        if(y < 65 || y >90){return false;}
    }
    for(int i = 0; i<palabra.length()-1; i++){
        for(int k = i+1; k<palabra.length(); k++){
            if(palabra[i]==palabra[k]){return false;}
        }
    }
    return true;
}
