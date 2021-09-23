#include "empleadoAsalariado.h"

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
