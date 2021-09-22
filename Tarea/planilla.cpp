#include "planilla.h"
#include "empleadoAsalariado.h"
#include "empleadoHoras.h"

Planilla::Planilla(int idJefe, string nombreJefe, string correoJefe, int tipoEmpleado)
{
	switch (tipoEmpleado)
	{
	case 1:
		Empleado *jefeNuevo = new EmpleadoAsalariado(idJefe,nombreJefe,correoJefe,0)
		this->jefe = jefeNuevo;
		break;
	case 2:
		this->jefe = new EmpleadoAsalariado(idJefe, nombreJefe, correoJefe);
		break;
	default:
		break;
	}
}

Planilla::~Planilla()
{

}

void Planilla::agregarEmpleado(int id, string nombre, string correo, int tipoEmpleado, Empleado* idJefe)
{

}

