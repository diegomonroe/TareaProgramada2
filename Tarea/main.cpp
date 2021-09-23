#include "planilla.h"
#include "empleadoHoras.h"
#include "empleadoAsalariado.h"

#include <iostream>

int main() {

	Planilla *planilla = new Planilla(1,"Diego","prueba@hotmail.com", 1);
	planilla->agregarEmpleado(2, "Angelica","curling26@gmail.com",2,1);
	delete planilla;
	
	return 0;
}