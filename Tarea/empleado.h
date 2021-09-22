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
		Empleado* nodoPadre{ 0 };
		vector <Empleado*>empleadosDirectos;

	Empleado(){}

	void agregarEmpleadoDirecto(){}

	public:

	//Empleado(int id, string nombre, string correo, Empleado *empleados);
	~Empleado(){}
	//void agregarEmpleadoDirecto(Empleado *empleadoDirecto);

};

#endif