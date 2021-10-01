#pragma once
#ifndef PLANILLA_H
#define PLANILLA_H

#include "empleado.h"
#include <map>
#include <string>

class Planilla
{
	Empleado* jefe;
	map<int, Empleado *> trabajadores;
	float totalSalariosPorPagar = 0.0f;
	float totalRetencionImpuesto = 0.0f;


	public:

	void agregarDirector(int idJefe, string nombreJefe, string apellidoJefe, string correoJefe, int tipoEmpleado);
	Planilla();
	~Planilla();
	void agregarEmpleado(int id, string nombre, string apellido, string correo, int tipoEmpleado, int idJefe);
	void llenarPlanilla();
	void agregarSalarios();
	void agregarHoras();

	friend std::ostream& operator << (std::ostream& o, const Planilla& planilla) ;
};

#endif