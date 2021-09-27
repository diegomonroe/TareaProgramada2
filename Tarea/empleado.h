#pragma once

#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>
using namespace std;


class Empleado{

	protected:
	
	string nombre{ "" };
	string apellido{""};
	string correo{ "" };
	vector <Empleado*>empleadosDirectos;

	Empleado(){}

	public:
		int	id{ 0 };
	virtual ~Empleado(){}
	virtual void agregarEmpleadoDirecto(Empleado*) {}
	virtual void agregarSalario(float salarioNuevo){}
	virtual void agregarPagoHoras(float pagoHora, int horas) {}
};

#endif