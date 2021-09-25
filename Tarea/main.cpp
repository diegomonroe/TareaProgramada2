#include "planilla.h"
#include "empleadoHoras.h"
#include "empleadoAsalariado.h"

#include <iostream>
using namespace std;

int main() {

	Planilla* planilla = new Planilla();
	
	planilla->llenarPlanilla();
	
	
	delete planilla;
	

    

	return 0;
}