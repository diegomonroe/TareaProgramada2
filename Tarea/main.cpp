#include "planilla.h"
#include "empleadoHoras.h"
#include "empleadoAsalariado.h"

#include <iostream>
using namespace std;

int main() {

	Planilla* planilla = new Planilla();
	
	planilla->llenarPlanilla();
	planilla->agregarSalarios();
	planilla->agregarHoras();
	delete planilla;
	

    

	return 0;
}