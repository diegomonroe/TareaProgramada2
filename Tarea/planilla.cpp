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

void Planilla::llenarPlanilla(string archivoPlanilla)
{

    std::istringstream streamEntradaPersonas{ archivoPlanilla };
   
    // Leer l�nea por l�nea 
    string linea{ "" };
    int id{ 0 };
    string nombre{""};
    string apellido{""};
    string correo{""};
    int tipoTrabajador{ 0 };
    int idJefe{ 0 };

    while (getline(streamEntradaPersonas, linea)) {

        try
        {
            // Procesamos la l�nea
            istringstream streamEntradaPersonas(linea);

            id = 0;
            nombre = "";
            apellido = "";
            correo = "";
            tipoTrabajador = 0;
            idJefe = 0;

            streamEntradaPersonas >> id >> nombre >> apellido >> correo>>tipoTrabajador>>idJefe;

            // Revisar si l�nea es v�lida
            if (nombre.length() == 0)
            {
                string error = "Error en l�nea \"" + linea + "\". Nombre no puede ser vac�o.";
                throw error;
            }

            this->agregarEmpleado(id, nombre, apellido, correo, tipoTrabajador, idJefe);
            
        }
        catch (string& excepcion)
        {
            cerr << excepcion << endl;
        }
    }

}

void Planilla::agregarSalarios(string archivoSalariosNomina)
{
    std::istringstream streamEntradaPersonas{ archivoSalariosNomina };
   

    // Leer l�nea por l�nea 
    string linea{ "" };
    int id{ 0 };
    float salario{ 0.0f };


    while (getline(streamEntradaPersonas, linea)) {

        try
        {
            // Procesamos la l�nea
            istringstream streamEntradaPersonas(linea);

            id = 0;
            salario = 0.0f;

            streamEntradaPersonas >> id >> salario;


            // Revisar si l�nea es v�lida
            if (id == 0)
            {
                string error = "Error en l�nea \"" + linea + "\". Nombre no puede ser vac�o.";
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

}


void Planilla::agregarHoras(string archivoPagoHoras)
{
    std::istringstream streamEntradaPersonas{ archivoPagoHoras };

    // Leer l�nea por l�nea 
    string linea{ "" };
    int id{ 0 };
    float montoHora{ 0.0f };
    int horaLaborada{ 0 };


    while (getline(streamEntradaPersonas, linea)) {

        try
        {
            // Procesamos la l�nea
            istringstream streamEntradaPersonas(linea);

            id = 0;
            montoHora = 0.0f;
            horaLaborada = 0;
            streamEntradaPersonas >> id >> montoHora>>horaLaborada;

            // Revisar si l�nea es v�lida
            if (id == 0)
            {
                string error = "Error en l�nea \"" + linea + "\". Nombre no puede ser vac�o.";
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
}

string Planilla::convertirArchivo(string nombreArchivo)
{
    stringstream archivo;
    ifstream ifs(nombreArchivo, ifstream::in);
    if (!ifs.is_open())
    {
        cerr << "Error leyendo archivo ejemplo.txt" << endl;
        //return -1;
    }
    string linea{ "" };
    while (getline(ifs, linea)) {
        archivo<<linea<<endl;
        
    }
    ifs.close();

    string archivoConvertido = archivo.str();
    return archivoConvertido;
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
