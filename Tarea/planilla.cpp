#include "planilla.h"
#include "empleadoAsalariado.h"
#include "empleadoHoras.h"



Planilla::Planilla(int idJefe, string nombreJefe, string correoJefe, int tipoEmpleado)
{
	switch (tipoEmpleado)
	{
	case 1:
		this->jefe = new EmpleadoAsalariado(idJefe, nombreJefe, correoJefe);
		break;
	case 2:
		this->jefe = new EmpleadoHoras(idJefe, nombreJefe, correoJefe);
		break;
	default:
		break;
	}
	
	this->trabajadores.insert(pair<int, Empleado*>(idJefe, jefe));
}

Planilla::~Planilla()
{

}

void Planilla::agregarEmpleado(int id, string nombre, string correo, int tipoEmpleado, int idJefe)
{
	Empleado* nuevoEmpleado = 0;
	switch (tipoEmpleado)
	{
	case 1:
		nuevoEmpleado = new EmpleadoAsalariado(id, nombre, correo);
		break;
	case 2:
		nuevoEmpleado = new EmpleadoHoras(id, nombre, correo);
		break;
	default:
		break;
	}

	Empleado* jefeDirecto = this->trabajadores.at(idJefe);
	jefeDirecto->agregarEmpleadoDirecto(nuevoEmpleado);
	this->trabajadores.insert(pair<int, Empleado*>(id, nuevoEmpleado));

}

