#pragma once

#ifndef EMPLEADOASALARIADO_H
#define EMPLEADOASALARIADO_H

#include "empleado.h"

class EmpleadoAsalariado:public Empleado{

	protected:
	virtual std::ostream& serializar(std::ostream& out) const;
	//virtual string getNombreCompleto();

	public:
	EmpleadoAsalariado(int id, string nombre, string apellido, string correo);
	EmpleadoAsalariado(int id,string nombre, string apellido,string correo, Empleado* jefe);
	virtual void agregarEmpleadoDirecto(Empleado *);
	virtual ~EmpleadoAsalariado();
	void agregarSalario(float salarioNuevo);
};


#endif


