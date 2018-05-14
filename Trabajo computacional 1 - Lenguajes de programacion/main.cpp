#include <iostream>
#include <string>
#include "Cifrado.h"
#include "Descifrado.h"
#include<windows.h>
#include<conio.h>
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
using namespace std;

void gotoxy(int x,int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon,dwPos);
}

int menuprincipal(){
    int opcion=1,tecla;
    string opciones[11] = {"Ingresar mensaje a cifrar","Ingresar clave cifrado","Ver mensaje a cifrar","Ver clave a cifrar","Ver mensaje cifrado","Ingrese mensaje a decifrar","Ingrese clave descifrado","Ver mensaje a decifrar","ver clave descifrado","ver mensaje decifrado","Salir"};
    bool repite= true;
    do{
        system("CLS");
        gotoxy(15,2);cout<<"CIFRAR";
        gotoxy(5,3+opcion);cout<<"==>";
        gotoxy(10,4);cout<<"1)"<<opciones[0];
        gotoxy(10,5);cout<<"2)"<<opciones[1];
        gotoxy(10,6);cout<<"3)"<<opciones[2];
        gotoxy(10,7);cout<<"4)"<<opciones[3];
        gotoxy(10,8);cout<<"5)"<<opciones[4];
        gotoxy(15,9);cout<<"DESCIFRAR";
        gotoxy(10,10);cout<<"6)"<<opciones[5];
        gotoxy(10,11);cout<<"7)"<<opciones[6];
        gotoxy(10,12);cout<<"8)"<<opciones[7];
        gotoxy(10,13);cout<<"9)"<<opciones[8];
        gotoxy(10,14);cout<<"10)"<<opciones[9];
        gotoxy(10,15);cout<<"11)"<<opciones[10];
        do{
            tecla = getch();
        }while(tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
        switch(tecla){
        case ARRIBA:
            opcion --;
            if(opcion<1){
                opcion = 12;
            }
            if(opcion ==6){
                opcion = 5;
            }
            break;
        case ABAJO:
            opcion++;
            if(opcion>12){
                opcion = 1;
            }
            if(opcion ==6){
                opcion = 7;
            }
            break;
        case ENTER:
            repite = false;
            break;
        }
    }while(repite);
    return opcion;
}


int main()
{
    int opcion = 0;
    bool b_msj = false,b_clv = false, b_msjd = false,b_clvd = false;
    Cifrado Cif;
    Descifrado Des;
    string msj=" ",clv=" ";
    char *men;
    do{
        opcion = menuprincipal();
        switch(opcion){
            case 1:
                system("CLS");
                cout<<"Introduzca el mensaje a cifrar: ";
                getline(cin,msj);
                if(Cif.Verificador(msj)){
                    Cif.Set_Mensaje(msj);
                    b_msj = true;
                }
                else {
                    cout<<"El mensaje no es valido."<<endl;
                    system("PAUSE");}
                break;
            case 2:
                system("CLS");
                if(b_msj){
                    cout<<"Introduzca la clave para cifrar: ";
                    getline(cin,clv);
                    if(Cif.V_Clave(clv)){
                        Cif.Set_Clave(clv);
                        b_clv = true;
                    }
                    else {
                        cout<<"La clave no es valida."<<endl;
                        system("PAUSE");}}
                else{
                    cout<<"Primero ingresar un mensaje a cifrar."<<endl;
                    system("PAUSE");
                }
                break;
            case 3:
                system("CLS");
                cout<<"Mensaje a cifrar: "<<Cif.Get_Mensaje()<<endl;
                system("PAUSE");
                break;
            case 4:
                system("CLS");
                cout<<"Clave para cifrar: "<<Cif.Get_Clave()<<endl;
                system("PAUSE");
                break;
            case 5:
                system("CLS");
                if(b_msj && b_clv){
                    msj = Cif.Get_Mensaje();
                    men = Cif.Cifrador();
                    cout<<"Mensaje cifrado: "<<endl;
                    for(int i = 0; i<msj.length();i++){
                        cout<<men[i];
                    }
                    cout<<endl;
                    system("PAUSE");}
                else{
                    cout<<"Primero ingrese un mensaje y una clave."<<endl;
                    system("PAUSE");
                }
                break;
            case 7:
                system("CLS");
                cout<<"Introduzca el mensaje a descifrar: ";
                getline(cin,msj);
                if(Des.Verificador(msj)){
                    Des.Set_MensajeD(msj);
                    Des.Set_Mensaje(msj);
                    b_msjd = true;
                }
                else {
                    cout<<"El mensaje no es valido."<<endl;
                    system("PAUSE");}
                break;
            case 8:
                system("CLS");
                if(b_msjd){
                    cout<<"Introduzca la clave para descifrar: ";
                    getline(cin,clv);
                    if(Des.V_Clave(clv)){
                        Des.Set_ClaveD(clv);
                        b_clvd = true;
                    }
                    else {
                        cout<<"La clave no es valida."<<endl;
                        system("PAUSE");}}
                else{
                    cout<<"Primero ingrese un mensaje a descifrar."<<endl;
                    system("PAUSE");
                }
                break;
            case 9:
                system("CLS");
                cout<<"Mensaje a descifrar: "<<Des.Get_MensajeD()<<endl;
                system("PAUSE");
                break;
            case 10:
                system("CLS");
                cout<<"Clave para descifrar: "<<Des.Get_ClaveD()<<endl;
                system("PAUSE");
                break;
            case 11:
                system("CLS");
                if(b_msjd && b_clvd){
                    msj = Des.Get_MensajeD();
                    men = Des.Descifrador();
                    cout<<"Mensaje Descifrado: "<<endl;
                    for(int i = 0; i<msj.length();i++){
                        cout<<men[i];
                    }
                    cout<<endl;
                    system("PAUSE");}
                else{
                    cout<<"Primero ingrese un mensaje y una clave."<<endl;
                    system("PAUSE");
                }
                break;
            case 12:
                break;
        }
    }while(opcion != 12);
    return 0;
}
