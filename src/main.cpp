#include <iostream>
#include "..\lib\ProgressBar.h"

using namespace std;

int main()
{
	setColor(BLACK,LCYAN);
    loading();
}

/*
	Error: Se puede presentar un error cuando no podamos abrir el archivo log.txt y escribir el ProgressBar en ese 
	caso se mostrara un mensaje de alerta. Esto se debe a alguna falla en la memoria o en el archivo log.txt.

    Issue: Se podria mejorar el porcentaje de carga para que llegue al 100% ya que dada la longitud de la cadena 
	llega a 96% caso contrario se reducria nuestra ProgressBar.

    Bug: Se puede presentar si definimos mal los ciclos for dado que podemos ejecutar al programa sin un limite 
	y correra infinitas veces.
*/
