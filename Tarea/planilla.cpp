#include "planilla.h"
#include "empleadoAsalariado.h"
#include "empleadoHoras.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void Planilla::agregarDirector(int id, string nombreJefe, string apellidoJefe, string correoJefe, int tipoEmpleado)
{
	switch (tipoEmpleado)
	{
	case 1:
		this->director = new EmpleadoAsalariado(id, nombreJefe, apellidoJefe, correoJefe);
		break;
	case 2:
		this->director = new EmpleadoHoras(id, nombreJefe, apellidoJefe, correoJefe);
		break;
	default:
		break;
	}
	
	this->trabajadores.insert(pair<int, Empleado*>(id, director));
}

Planilla::Planilla()
{
    this->director = nullptr;
}

Planilla::~Planilla()
{
	delete this->director;
}

void Planilla::agregarEmpleado(int id, string nombre, string apellido, string correo, int tipoEmpleado, int idJefe)
{
	
    if (idJefe == 0)
    {
        this->agregarDirector(id, nombre, apellido, correo, tipoEmpleado);
    }
    else 
    {
        Empleado* nuevoEmpleado = nullptr;
        Empleado* jefeDirecto = this->trabajadores.at(idJefe);
	    switch (tipoEmpleado)
	    {
        case 1:
		    nuevoEmpleado = new EmpleadoAsalariado(id, nombre, apellido, correo, jefeDirecto);
		    break;
	    case 2:
		    nuevoEmpleado = new EmpleadoHoras(id, nombre, apellido, correo, jefeDirecto);
		    break;
	    default:
		    break;
	    }
	    jefeDirecto->agregarEmpleadoDirecto(nuevoEmpleado);
	    this->trabajadores.insert(pair<int, Empleado*>(id, nuevoEmpleado));
    }
}

void Planilla::llenarPlanilla()
{
    ifstream ifs("Personas.txt", ifstream::in);
    if (!ifs.is_open())
    {
        cerr << "Error leyendo archivo ejemplo.txt" << endl;
        //return -1;
    }
    
   
    // Leer línea por línea 
    string linea{ "" };

    int id{ 0 };
    string nombre{""};
    string apellido{""};
    string correo{""};
    int tipoTrabajador{ 0 };
    int idJefe{ 0 };


    while (getline(ifs, linea)) {

        try
        {
            // Procesamos la línea
            istringstream stream(linea);

            id = 0;
            nombre = "";
            apellido = "";
            correo = "";
            tipoTrabajador = 0;
            idJefe = 0;

            stream >> id >> nombre >> apellido >> correo>>tipoTrabajador>>idJefe;

            // Revisar si línea es válida
            if (nombre.length() == 0)
            {
                string error = "Error en línea \"" + linea + "\". Nombre no puede ser vacío.";
                throw error;
            }

            this->agregarEmpleado(id, nombre, apellido, correo, tipoTrabajador, idJefe);
            

            //cout << "Linea de " << nombre << " es correcta." << endl;
        }
        catch (string& excepcion)
        {
            cerr << excepcion << endl;
        }
    }


    ifs.close();
}

void Planilla::agregarSalarios()
{
    ifstream ifs("Nomina.txt", ifstream::in);
    if (!ifs.is_open())
    {
        cerr << "Error leyendo archivo ejemplo.txt" << endl;
        //return -1;
    }


    // Leer línea por línea 
    string linea{ "" };
    int id{ 0 };
    float salario{ 0.0f };


    while (getline(ifs, linea)) {

        try
        {
            // Procesamos la línea
            istringstream stream(linea);

            id = 0;
            salario = 0.0f;

            stream >> id >> salario;


            // Revisar si línea es válida
            if (id == 0)
            {
                string error = "Error en línea \"" + linea + "\". Nombre no puede ser vacío.";
                throw error;
            }
            float impuesto = salario * (float)0.07;
            float salarioNeto = salario - impuesto;

            this->totalRetencionImpuesto += impuesto;
            this->totalSalariosPorPagar += salarioNeto;

            Empleado* empleado = this->trabajadores.at(id);
            empleado->agregarSalario(salarioNeto);
            
        }
        catch (string& excepcion)
        {
            cerr << excepcion << endl;
        }
    }


    ifs.close();
}


void Planilla::agregarHoras()
{
    ifstream ifs("HorasTrabajadas.txt", ifstream::in);
    if (!ifs.is_open())
    {
        cerr << "Error leyendo archivo ejemplo.txt" << endl;
        //return -1;
    }


    // Leer línea por línea 
    string linea{ "" };
    int id{ 0 };
    float montoHora{ 0.0f };
    int horaLaborada{ 0 };


    while (getline(ifs, linea)) {

        try
        {
            // Procesamos la línea
            istringstream stream(linea);

            id = 0;
            montoHora = 0.0f;
            horaLaborada = 0;
            stream >> id >> montoHora>>horaLaborada;

            // Revisar si línea es válida
            if (id == 0)
            {
                string error = "Error en línea \"" + linea + "\". Nombre no puede ser vacío.";
                throw error;
            }
            float salario = montoHora * horaLaborada;
            this->totalSalariosPorPagar += salario;
            Empleado* empleado = this->trabajadores.at(id);
            empleado->agregarPagoHoras(montoHora, horaLaborada, salario);

        }
        catch (string& excepcion)
        {
            cerr << excepcion << endl;
        }
    }


    ifs.close();
}

ostream& operator<<(ostream& o, const Planilla& planilla)
{
    o.precision(2);
    o << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
    Empleado* jefe = planilla.director;
    o << *(jefe);
    o << fixed << "Subtotal:," << planilla.totalSalariosPorPagar << endl;
    o << fixed << "Impuestos a retener:," << planilla.totalRetencionImpuesto  << endl;
    o << fixed << "Total:," << planilla.totalSalariosPorPagar + planilla.totalRetencionImpuesto << endl;
    return o;
}
