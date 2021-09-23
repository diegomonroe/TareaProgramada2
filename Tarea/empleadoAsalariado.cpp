#include "empleadoAsalariado.h"
#include <iostream>
using namespace std;
EmpleadoAsalariado::EmpleadoAsalariado(int idNuevo, string nombreNuevo, string correoNuevo)
{
	this->id = idNuevo;
	this->nombre = nombreNuevo;
	this->correo = correoNuevo;
}

void EmpleadoAsalariado::agregarEmpleadoDirecto(Empleado* nuevoEmpleado)
{
	this->empleadosDirectos.push_back(nuevoEmpleado);
}

EmpleadoAsalariado::~EmpleadoAsalariado()
{
	cout << "hola" << endl;
	for (Empleado* empleado : this->empleadosDirectos) {
		delete empleado;
	}
}
