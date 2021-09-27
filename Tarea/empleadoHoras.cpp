#include "empleadoHoras.h"
#include <iostream>
using namespace std;

EmpleadoHoras::EmpleadoHoras(int idNuevo, string nombreNuevo, string apellidoNuevo, string correoNuevo)
{
	this->id = idNuevo;
	this->nombre = nombreNuevo;
	this->apellido = apellidoNuevo;
	this->correo = correoNuevo;
}

void EmpleadoHoras::agregarEmpleadoDirecto(Empleado* nuevoEmpleado)
{
	this->empleadosDirectos.push_back(nuevoEmpleado);
}

EmpleadoHoras::~EmpleadoHoras()
{
	
	for (Empleado* empleado : this->empleadosDirectos) {
		delete empleado;
	}
}

void EmpleadoHoras::agregarPagoHoras(float montoHora, int horas)
{
	this->horasLaboradas = horas;
	this->montoPorHora = montoHora;
}

