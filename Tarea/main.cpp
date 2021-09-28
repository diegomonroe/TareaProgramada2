#include "planilla.h"
#include "empleadoHoras.h"
#include "empleadoAsalariado.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {

	Planilla* planilla = new Planilla();
	
	planilla->llenarPlanilla();
	planilla->agregarSalarios();
	planilla->agregarHoras();
	//cout << *planilla;

	std::ofstream file("Reporte.csv", std::ofstream::out);
	file << *planilla;
	file.close();

	delete planilla;
	

    

	return 0;
}