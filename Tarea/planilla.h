#pragma once
#ifndef PLANILLA_H
#define PLANILLA_H

#include "empleado.h"
#include "empleadoAsalariado.h"
#include "empleadoHoras.h"
#include <map>
#include <string>

class Planilla
{
	Empleado* director=nullptr;
	map<int, Empleado *> trabajadores;
	float totalSalariosPorPagar = 0.0f;
	float totalRetencionImpuesto = 0.0f;

	void agregarDirector(int idJefe, string nombreJefe, string apellidoJefe, string correoJefe, int tipoEmpleado);
	void agregarEmpleado(int id, string nombre, string apellido, string correo, int tipoEmpleado, int idJefe);
	void agregarImpuesto(float impuesto);
	void agregarSalarioPorPagar(float salario);
	
	public:
	Planilla();
	~Planilla();
	void llenarPlanilla(string archivoPlanilla);
	void agregarSalarios(string archivoSalariosNomina);
	void agregarHoras(string archivoPagoHoras);
	string convertirArchivo(string nombreArchivo);
	friend std::ostream& operator << (std::ostream& o, const Planilla& planilla) ;
};

#endif