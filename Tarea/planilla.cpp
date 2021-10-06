#include "planilla.h"
#include "empleadoAsalariado.h"
#include "empleadoHoras.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Planilla::Planilla()
{
    this->director = nullptr;
}

Planilla::~Planilla()
{
	delete this->director;
}

void Planilla::agregarDirector(int id, string nombreDirector, string apellidoDirector, string correoDirector, int tipoEmpleado)
{
	switch (tipoEmpleado)
	{
	case 1:
		this->director = new EmpleadoAsalariado(id, nombreDirector, apellidoDirector, correoDirector);
		break;
	case 2:
		this->director = new EmpleadoHoras(id, nombreDirector, apellidoDirector, correoDirector);
		break;
	default:
		break;
	}
	
	this->trabajadores.insert(pair<int, Empleado*>(id, director));
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

void Planilla::agregarSalarioPorPagar(float salario)
{
    this->totalSalariosPorPagar += salario;
}

void Planilla::agregarImpuesto(float impuesto)
{
    this->totalRetencionImpuesto += impuesto;
}

void Planilla::llenarPlanilla(string archivoPlanilla)
{
    try
    {
        if (archivoPlanilla == "") {
            string error = "El archivo con datos para crear la planilla es incorrecto.";
            throw error;
        }
        std::istringstream streamEntradaPersonas{ archivoPlanilla };

        // Leer línea por línea 
        string linea{ "" };
        int id{ 0 };
        string nombre{ "" };
        string apellido{ "" };
        string correo{ "" };
        int tipoTrabajador{ 0 };
        int idJefe{ 0 };

        while (getline(streamEntradaPersonas, linea)) {

            try
            {
                // Procesamos la línea
                istringstream streamEntradaPersonas(linea);

                id = 0;
                nombre = "";
                apellido = "";
                correo = "";
                tipoTrabajador = 0;
                idJefe = 0;

                streamEntradaPersonas >> id >> nombre >> apellido >> correo >> tipoTrabajador >> idJefe;

                // Revisar si línea es válida
                if (nombre.length() == 0)
                {
                    string error = "Error en línea \"" + linea + "\". Nombre no puede ser vacío.";
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
    catch (string& exception)
    {
        cerr << exception << endl;
    }

}

void Planilla::agregarSalarios(string archivoSalariosNomina)
{ 
    if (archivoSalariosNomina == "") {
        cerr << "El archivo con datos de salarios es incorrecto." << endl;
        return;
    }
    if (this->director==nullptr) {
        cerr << "No se pueden agregar salarios porque no existe la planilla." << endl;
        return;
    }
    try
    {
        std::istringstream streamEntradaPersonas{ archivoSalariosNomina };

        // Leer línea por línea 
        string linea{ "" };
        int id{ 0 };
        float salario{ 0.0f };


        while (getline(streamEntradaPersonas, linea)) {

            try
            {
                // Procesamos la línea
                istringstream streamEntradaPersonas(linea);

                id = 0;
                salario = 0.0f;

                streamEntradaPersonas >> id >> salario;

                // Revisar si línea es válida
                if (id == 0)
                {
                    string error = "Error en línea \"" + linea + "\". ID no puede ser cero.";
                    throw error;
                }
                
                Empleado* empleado = this->trabajadores.at(id);
                float impuesto = salario * (float)0.07;
                float salarioNeto = salario - impuesto;
                agregarImpuesto(impuesto);
                agregarSalarioPorPagar(salarioNeto);
                
                empleado->agregarSalario(salarioNeto);
            }
            catch (string& excepcion)
            {
                cerr << excepcion << endl;
            }
        }
    }
    catch (const std::exception&)
    {
        cerr << "Empleado no existe en la planilla." << endl;
    }
}

void Planilla::agregarHoras(string archivoPagoHoras)
{
    if (archivoPagoHoras == "") {
        cerr << "El archivo con datos de horas y pago por horas es incorrecto." << endl;
        return;
    }
    if (this->director == nullptr) {
        cerr << "No se pueden agregar horas y pago por horas porque la planilla no se ha creado." << endl;
        return;
    }

    try
    {
        std::istringstream streamEntradaPersonas{ archivoPagoHoras };

        // Leer línea por línea 
        string linea{ "" };
        int id{ 0 };
        float montoHora{ 0.0f };
        int horaLaborada{ 0 };


        while (getline(streamEntradaPersonas, linea)) {

            try
            {
                // Procesamos la línea
                istringstream streamEntradaPersonas(linea);

                id = 0;
                montoHora = 0.0f;
                horaLaborada = 0;
                streamEntradaPersonas >> id >> montoHora >> horaLaborada;

                // Revisar si línea es válida
                if (id == 0)
                {
                    string error = "Error en línea \"" + linea + "\". ID no puede ser vacío.";
                    throw error;
                }
                Empleado* empleado = this->trabajadores.at(id);
                float salario = montoHora * horaLaborada;
                this->totalSalariosPorPagar += salario;
                
                empleado->agregarPagoHoras(montoHora, horaLaborada, salario);

            }
            catch (string& excepcion)
            {
                cerr << excepcion << endl;
            }
        }
    }
    catch (const std::exception&)
    {
        cerr << "Empleado no existe en la planilla." << endl;
    }
    
}

string Planilla::convertirArchivo(string nombreArchivo)
{
    stringstream archivo{""};
    ifstream ifs(nombreArchivo, ifstream::in);
    if (!ifs.is_open())
    {
        cerr << "Error leyendo archivo: "<<nombreArchivo << endl;
        return "";
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
    try
    {
        Empleado* director = planilla.director;
        if (director == nullptr) {
            string error = "La planilla no se ha creado.";
            throw error;
        }
        o.precision(2);
        o << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        o << *(director);
        o << fixed << "Subtotal:," << planilla.totalSalariosPorPagar << endl;
        o << fixed << "Impuestos a retener:," << planilla.totalRetencionImpuesto << endl;
        o << fixed << "Total:," << planilla.totalSalariosPorPagar + planilla.totalRetencionImpuesto << endl;
        
    }
    catch (string& error)
    {
        o << "Error en datos para la creacion de la planilla." << endl;
        o << "Corriga los datos y vuelva a intentar." << endl;
        cerr << error << endl;
    }
    return o;
}
