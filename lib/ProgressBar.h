#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

const string email="mArIO.AIsAllA@Epn.EdU.Ec";

enum Colors { // Listado de colores (La letra "L" al inicio, indica que es un color mas claro que su antecesor).
    BLACK      = 0,
    BLUE       = 1,
    GREEN      = 2,
    CYAN       = 3,
    RED        = 4,
    MAGENTA    = 5,
    BROWN      = 6,
    LGREY      = 7,
    DGREY      = 8,
    LBLUE      = 9,
    LGREEN     = 10,
    LCYAN      = 11,
    LRED       = 12,
    LMAGENTA   = 13,
    YELLOW     = 14,
    WHITE      = 15
};

// procedimiento para cambiar el color del fondo y/o pantalla
void setColor(int Background, int Text){ 
    int colorTexto= Text + (Background * 16);         // los colores van del 0 al 255 por eso se multiplica por 16
    HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);   // referenciamos a la consola.
    SetConsoleTextAttribute(terminal, colorTexto); 
}

void ShowProgressBar_a(string email,int load)
{
    int imp=(100/email.length())*load;
    fstream f;
    f.open("resource\\log.txt", ios_base::app);
    if(!f.is_open())
    {
        cout<<"Error al imprimir la ProgressBar en el archivo"<<endl;
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<=100;i++) 
    {
        if(i==imp)
        {

            int num_characters= (i*email.length())/100;
            f<<"\r[";
            cout<<"\r[";
            for(int i=0; i<=email.length(); i++)
            {

                if(i<=num_characters)
                {
                    
                    if(i%2==0)
                    {
                        cout<<"-";
                        f<<"-";
                    }
                    else
                    {
                        cout<<"\b= ";
                        f<<"\b= ";
                    }
                }
                else 
                    cout<<" ";
                    f<<" ";
            }
            cout<<"\b\b"<<"] "<<i<<"% "<<"\t"<<"Loading: "<<load<<" de 24  ";
            f<<"\b\b"<<"] "<<i<<"% "<<"\t"<<"Loading: "<<load<<" de 24  ";
            if(imp!=0)
            {
                cout<<email.substr(0,load)<<endl;
                f<<email.substr(0,load);
                f<<"\n";
            }
            else
            {
                cout<<endl;
                f<<"\n";
            }
            fflush(stdout);
        }
    }
}

void loading()
{
    for(int i=0;i<=email.length();i++)
    {
        ShowProgressBar_a(email,i);
    }
}
