#pragma once
#ifndef PLANILLA_H
#define PLANILLA_H

#include "empleado.h"
#include <map>
#include <string>

class Planilla
{
	Empleado* director=nullptr;
	map<int, Empleado *> trabajadores;
	float totalSalariosPorPagar = 0.0f;
	float totalRetencionImpuesto = 0.0f;
	void agregarDirector(int idJefe, string nombreJefe, string apellidoJefe, string correoJefe, int tipoEmpleado);

	public:
	Planilla();
	~Planilla();
	void agregarEmpleado(int id, string nombre, string apellido, string correo, int tipoEmpleado, int idJefe);
	void llenarPlanilla(string archivoPlanilla);
	void agregarSalarios(string archivoSalariosNomina);
	void agregarHoras(string archivoPagoHoras);

	friend std::ostream& operator << (std::ostream& o, const Planilla& planilla) ;
	string convertirArchivo(string nombreArchivo);
};

#endif