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

EmpleadoHoras::EmpleadoHoras(int idNuevo, string nombreNuevo, string apellidoNuevo, string correoNuevo,Empleado* jefe)
{
	this->id = idNuevo;
	this->nombre = nombreNuevo;
	this->apellido = apellidoNuevo;
	this->correo = correoNuevo;
	this->jefeDirecto = jefe;
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
	this->salario = this->horasLaboradas * this->montoPorHora;
}

ostream& EmpleadoHoras::serializar(std::ostream& o) const {
	o << this->id << ",";
	o << this->nombre << " "<< this->apellido << ",";

	if (this->jefeDirecto != nullptr) {
		o << this->jefeDirecto->getNombreCompleto() << ",";
	}
	else {
		o << " " << ",";
	}

	o.precision(2);
	o <<fixed<< this->salario << endl;

	for (Empleado *empleadoDirecto : this->empleadosDirectos)
	{
		o << *empleadoDirecto;
	}

	return o;
}

string EmpleadoHoras::getNombreCompleto() {
	return this->nombre + " " + this->apellido;
}