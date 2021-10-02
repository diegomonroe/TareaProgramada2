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
	string apellido{ "" };
	string correo{ "" };
	float salario{ 0.0f };
	vector <Empleado*>empleadosDirectos;
	Empleado* jefeDirecto{ nullptr };

	virtual std::ostream& serializar(std::ostream& out) const;

	Empleado(){}
	
	public:
	virtual ~Empleado(){}
	virtual void agregarEmpleadoDirecto(Empleado*) {}
	virtual void agregarSalario(float salarioNuevo){}
	virtual void agregarPagoHoras(float pagoHora, int horas, float salario) {}
	virtual string getNombreCompleto() = 0;
	friend std::ostream& operator << (std::ostream& o, const Empleado& empleado);


};

#endif