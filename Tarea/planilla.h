#pragma once
#ifndef PLANILLA_H
#define PLANILLA_H

#include "empleado.h"
#include <map>
#include <string>

class Planilla
{
	Empleado* jefe=0;
	map<int, Empleado *> trabajadores;


	public:
	Planilla(int idJefe, string nombreJefe, string correoJefe, int tipoEmpleado);
	~Planilla();

	void agregarEmpleado(int id, string nombre, string correo, int tipoEmpleado, int idJefe);
	//void llenarPlanilla(ifstream );
};

#endif