#pragma once

#ifndef EMPLEADOASALARIADO_H
#define EMPLEADOASALARIADO_H

#include "empleado.h"

class EmpleadoAsalariado:public Empleado{
	float salario = 0.0f;

	public:
	EmpleadoAsalariado(int id,string nombre,string correo,Empleado *jefe);

};


#endif


