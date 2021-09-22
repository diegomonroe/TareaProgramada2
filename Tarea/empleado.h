#pragma once

#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>
using namespace std;


class Empleado{

	protected:
		int	id{ 0 };
		string nombre{ "" };
		string correo{ "" };
		vector <Empleado*>empleadosDirectos;

	Empleado(){}

	

	public:
	void agregarEmpleadoDirecto(Empleado*) {}
	//Empleado(int id, string nombre, string correo, Empleado *empleados);
	~Empleado(){}
	virtual void agregarEmpleadoDirecto(Empleado *empleadoDirecto);

};

#endif