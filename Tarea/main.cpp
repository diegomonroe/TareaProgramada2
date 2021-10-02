#include "planilla.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {

	Planilla* planilla = new Planilla();
	
	planilla->llenarPlanilla();
	//planilla->agregarSalarios();
	//planilla->agregarHoras();
	//cout << *planilla;

	std::ofstream archivoSalida("Reporte.csv", std::ofstream::out);
	archivoSalida << *planilla;
	archivoSalida.close();

	delete planilla;
	

    

	return 0;
}