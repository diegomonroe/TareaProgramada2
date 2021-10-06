#pragma once

#ifndef EMPLEADOHORAS_H
#define EMPLEADOHORAS_H

#include "empleado.h"

class EmpleadoHoras:public Empleado{
	float montoPorHora{ 0 };
	int horasLaboradas{ 0 };

	protected:
	virtual std::ostream& serializar(std::ostream& out) const;
	virtual string getNombreCompleto();
	virtual ~EmpleadoHoras();
	virtual void agregarEmpleadoDirecto(Empleado*);
	virtual void agregarPagoHoras(float montoHora, int horas, float salario);

	public:
	EmpleadoHoras(int id, string nombre, string apellido, string correo);
	EmpleadoHoras(int id, string nombre,string apellido, string correo, Empleado* jefe);
};

#endif