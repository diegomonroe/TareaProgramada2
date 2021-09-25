#include "empleadoAsalariado.h"
#include <iostream>
using namespace std;
EmpleadoAsalariado::EmpleadoAsalariado(int idNuevo, string nombreNuevo, string apellidoNuevo, string correoNuevo)
{
	this->id = idNuevo;
	this->nombre = nombreNuevo;
	this->apellido = apellidoNuevo;
	this->correo = correoNuevo;
}

void EmpleadoAsalariado::agregarEmpleadoDirecto(Empleado* nuevoEmpleado)
{
	this->empleadosDirectos.push_back(nuevoEmpleado);
}

EmpleadoAsalariado::~EmpleadoAsalariado()
{
	for (Empleado* empleado : this->empleadosDirectos) {
		delete empleado;
	}
}

void EmpleadoAsalariado::agregarSalario(float salarioNuevo)
{
	this->salario = salarioNuevo;
}

