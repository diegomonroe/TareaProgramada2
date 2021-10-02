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

EmpleadoAsalariado::EmpleadoAsalariado(int idNuevo, string nombreNuevo, string apellidoNuevo, string correoNuevo, Empleado* jefe)
{
	this->id = idNuevo;
	this->nombre = nombreNuevo;
	this->apellido = apellidoNuevo;
	this->correo = correoNuevo;
	this->jefeDirecto = jefe;
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

ostream& EmpleadoAsalariado::serializar(std::ostream& o) const {
	o << this->id << ",";
	o << this->nombre << " " << this->apellido << ","; 

	if (this->jefeDirecto != nullptr) {
		o << this->jefeDirecto->getNombreCompleto() << ",";
	}
	else {
		o << " " << ",";
	}

	o.precision(2);
	o << fixed << this->salario << endl;

	for (Empleado* empleadoDirecto : this->empleadosDirectos)
	{
		o << *empleadoDirecto;
	}


	return o;
}


string EmpleadoAsalariado::getNombreCompleto() {
	return this->nombre + " " + this->apellido;
}
