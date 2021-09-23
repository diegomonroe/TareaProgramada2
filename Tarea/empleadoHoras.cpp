#include "empleadoHoras.h"

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
