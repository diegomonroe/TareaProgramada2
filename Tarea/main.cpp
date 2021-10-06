#include "planilla.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main() {

	Planilla* planilla = new Planilla();

	string archivoPersonas = planilla->convertirArchivo("Personas.txt");
	planilla->llenarPlanilla(archivoPersonas);
	
	string archivoSalariosNomina = planilla->convertirArchivo("Nomina.txt");
	planilla->agregarSalarios(archivoSalariosNomina);

	string archivoPagoHoras = planilla->convertirArchivo("HorasTrabajadas.txt");
	planilla->agregarHoras(archivoPagoHoras);

	std::ofstream archivoSalida("Reporte.csv", std::ofstream::out);
	archivoSalida << *planilla;
	archivoSalida.close();

	delete planilla;
	return 0;
}