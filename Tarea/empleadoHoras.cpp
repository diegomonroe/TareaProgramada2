#include "empleadoHoras.h"
#include <iostream>
using namespace std;

EmpleadoHoras::EmpleadoHoras(int idNuevo, string nombreNuevo, string correoNuevo)
{
	this->id = idNuevo;
	this->nombre = nombreNuevo;
	this->correo = correoNuevo;
}

void EmpleadoHoras::agregarEmpleadoDirecto(Empleado* nuevoEmpleado)
{
	this->empleadosDirectos.push_back(nuevoEmpleado);
}

EmpleadoHoras::~EmpleadoHoras()
{
	cout << "hola" << endl;
	for (Empleado* empleado : this->empleadosDirectos) {
		delete empleado;
	}
}