#pragma once

#ifndef EMPLEADOHORAS_H
#define EMPLEADOHORAS_H

#include "empleado.h"

class EmpleadoHoras:public Empleado{
	float montoPorHora{ 0 };
	int horasLaboradas{ 0 };

	public:
	EmpleadoHoras(int id, string nombre, string correo, Empleado* jefe);
};

#endif