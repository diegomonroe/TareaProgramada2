#include "pch.h"
#include "..\Tarea\planilla.h"
#include "..\Tarea\planilla.cpp"
#include "..\Tarea\empleado.h"
#include "..\Tarea\empleado.cpp"
#include "..\Tarea\empleadoHoras.h"
#include "..\Tarea\empleadoHoras.cpp"
#include "..\Tarea\empleadoAsalariado.h"
#include "..\Tarea\empleadoAsalariado.cpp"
#include <string>
#include <sstream>
using namespace std;

namespace Test_Agregar_Empleados{

    TEST(PlanillaTest, Test_AgregarSalarioDirector) {
        Planilla* planilla = new Planilla();

        //Ingreso de archivo
        ostringstream ingresoDatos;
        ingresoDatos << "1 Diego Monroe 1234@prueba.com 1 0" << endl;
        string entradaEjemplo = ingresoDatos.str();
        planilla->llenarPlanilla(entradaEjemplo);

        //Resultado de la impresion de planilla
        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        //Resultado esperado
        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,0.00" << endl;
        streamSalidaEsperada << "Subtotal:,0.00" << endl;
        streamSalidaEsperada << "Impuestos a retener:,0.00" << endl;
        streamSalidaEsperada << "Total:,0.00" << endl;

        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }

    //Falta modificar
    TEST(PlanillaTest, Test_ConstructorDosTrabajadores) {
        Planilla* planilla = new Planilla();
        planilla->agregarEmpleado(1, "Diego", "Monroe", "1234@prueba.com", 1, 0);
        planilla->agregarEmpleado(2, "Angelica", "Curling", "9876@prueba.com", 2, 1);

        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,0.00" << endl;
        streamSalidaEsperada << "2,Angelica Curling,Diego Monroe,0.00" << endl;
        streamSalidaEsperada << "Subtotal:,0.00" << endl;
        streamSalidaEsperada << "Impuestos a retener:,0.00" << endl;
        streamSalidaEsperada << "Total:,0.00" << endl;
        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }

    //Falta modificar
    TEST(PlanillaTest, Test_ConstructorTresTrabajadores) {
        Planilla* planilla = new Planilla();
        planilla->agregarEmpleado(1, "Diego", "Monroe", "diego@prueba.com", 1, 0);
        planilla->agregarEmpleado(2, "Angelica", "Curling", "angelica@prueba.com", 2, 1);
        planilla->agregarEmpleado(3, "Karol", "Corrales", "karol@prueba.com", 1, 2);

        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,0.00" << endl;
        streamSalidaEsperada << "2,Angelica Curling,Diego Monroe,0.00" << endl;
        streamSalidaEsperada << "3,Karol Corrales,Angelica Curling,0.00" << endl;
        streamSalidaEsperada << "Subtotal:,0.00" << endl;
        streamSalidaEsperada << "Impuestos a retener:,0.00" << endl;
        streamSalidaEsperada << "Total:,0.00" << endl;
        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }

}

//Falta modificar
/*
namespace Test_Agregar_Salarios {

    TEST(PlanillaTest, Test_AgregarSalarioDirector) {
        Planilla* planilla = new Planilla();
        
        //Ingreso de archivo
        ostringstream ingresoDatos;
        ingresoDatos << "1 Diego Monroe 1234@prueba.com 1 0" << endl;
        string entradaEjemplo = ingresoDatos.str();
        planilla->llenarPlanilla(entradaEjemplo);

        //Resultado de la impresion de planilla
        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        //Resultado esperado
        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,0.00" << endl;
        streamSalidaEsperada << "Subtotal:,0.00" << endl;
        streamSalidaEsperada << "Impuestos a retener:,0.00" << endl;
        streamSalidaEsperada << "Total:,0.00" << endl;

        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }

    TEST(PlanillaTest, Test_ConstructorDosTrabajadores) {
        Planilla* planilla = new Planilla();
        planilla->agregarEmpleado(1, "Diego", "Monroe", "1234@prueba.com", 1, 0);
        planilla->agregarEmpleado(2, "Angelica", "Curling", "9876@prueba.com", 2, 1);

        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,0.00" << endl;
        streamSalidaEsperada << "2,Angelica Curling,Diego Monroe,0.00" << endl;
        streamSalidaEsperada << "Subtotal:,0.00" << endl;
        streamSalidaEsperada << "Impuestos a retener:,0.00" << endl;
        streamSalidaEsperada << "Total:,0.00" << endl;
        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }

    TEST(PlanillaTest, Test_ConstructorTresTrabajadores) {
        Planilla* planilla = new Planilla();
        planilla->agregarEmpleado(1, "Diego", "Monroe", "diego@prueba.com", 1, 0);
        planilla->agregarEmpleado(2, "Angelica", "Curling", "angelica@prueba.com", 2, 1);
        planilla->agregarEmpleado(3, "Karol", "Corrales", "karol@prueba.com", 1, 2);

        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,0.00" << endl;
        streamSalidaEsperada << "2,Angelica Curling,Diego Monroe,0.00" << endl;
        streamSalidaEsperada << "3,Karol Corrales,Angelica Curling,0.00" << endl;
        streamSalidaEsperada << "Subtotal:,0.00" << endl;
        streamSalidaEsperada << "Impuestos a retener:,0.00" << endl;
        streamSalidaEsperada << "Total:,0.00" << endl;
        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }

}

*/