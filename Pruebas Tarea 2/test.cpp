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

namespace Test_Planilla {
    TEST(LecturaPlanillaTest, Test_Lectura_Escritura_Archivo) {

        //Ingreso de archivo
        ostringstream ingresoDatos{};
        ingresoDatos << "1 Diego Monroe 1234@prueba.com 1 0" << endl;
        ingresoDatos << "2 Angelica Curling 9876@prueba.com 2 1" << endl;
        ingresoDatos << "3 Karol Corrales 5641@prueba.com 1 2" << endl;
        string entradaEjemplo = ingresoDatos.str();

        //LLenado planilla con los datos personales de los trabajadores
        Planilla* planilla = new Planilla();
        planilla->llenarPlanilla(entradaEjemplo);

        //Resultado impresion de pantalla
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
    TEST(CreacionPlanillaTest, Test_ConstructorSoloDirector) {
        Planilla* planilla = new Planilla();

        //Ingreso de archivo
        ostringstream ingresoDatos{};
        ingresoDatos << "1 Diego Monroe 1234@prueba.com 1 0" << endl;
        string entradaEjemplo = ingresoDatos.str();

        //LLenado planilla con los datos personales de los trabajadores
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
    TEST(CreacionPlanillaTest, Test_ConstructorDosTrabajadores) {
        Planilla* planilla = new Planilla();

        //Ingreso de archivo
        ostringstream ingresoDatos{};
        ingresoDatos << "1 Diego Monroe 1234@prueba.com 1 0" << endl;
        ingresoDatos << "2 Angelica Curling 9876@prueba.com 2 1" << endl;
        string entradaEjemplo = ingresoDatos.str();

        //LLenado planilla con los datos personales de los trabajadores
        planilla->llenarPlanilla(entradaEjemplo);

        //Resultado de la impresion de planilla

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
    TEST(CreacionPlanillaTest, Test_ConstructorTresTrabajadores) {
        Planilla* planilla = new Planilla();
        //Ingreso de archivo
        ostringstream ingresoDatos{};
        ingresoDatos << "1 Diego Monroe 1234@prueba.com 1 0" << endl;
        ingresoDatos << "2 Angelica Curling 9876@prueba.com 2 1" << endl;
        ingresoDatos << "3 Karol Corrales 5641@prueba.com 1 2" << endl;
        string entradaEjemplo = ingresoDatos.str();

        //LLenado planilla con los datos personales de los trabajadores
        planilla->llenarPlanilla(entradaEjemplo);

        //Resultado impresion de pantalla
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
    TEST(LlenadoSalariosPlanillaTest, Test_AgregarSalarioDirector) {
        Planilla* planilla = new Planilla();

        //Ingreso de archivo personas
        ostringstream ingresoDatosPersonas{};
        ingresoDatosPersonas << "1 Diego Monroe 1234@prueba.com 1 0" << endl;
        string entradaEjemplo = ingresoDatosPersonas.str();
        planilla->llenarPlanilla(entradaEjemplo);

        //Ingreso de archivo planilla
        ostringstream  ingresoDatosNomina;
        ingresoDatosNomina << "1 5000.56" << endl;
        string entradaEjemploSalarios = ingresoDatosNomina.str();

        //Llenando planilla con datos de salarios
        planilla->agregarSalarios(entradaEjemploSalarios);

        //Resultado de la impresion de planilla
        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        //Resultado esperado
        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,4650.52" << endl;
        streamSalidaEsperada << "Subtotal:,4650.52" << endl;
        streamSalidaEsperada << "Impuestos a retener:,350.04" << endl;
        streamSalidaEsperada << "Total:,5000.56" << endl;

        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }
    TEST(LlenadoSalariosPlanillaTest, Test_AgregarSalarioDosTrabajadores) {
        Planilla* planilla = new Planilla();

        //Ingreso de archivo personas
        ostringstream ingresoDatos{};
        ingresoDatos << "1 Diego Monroe 1234@prueba.com 1 0" << endl;
        ingresoDatos << "2 Angelica Curling 9876@prueba.com 1 1" << endl;
        string entradaEjemploPersonas = ingresoDatos.str();

        //LLenado planilla con los datos personales de los trabajadores
        planilla->llenarPlanilla(entradaEjemploPersonas);

        //Ingreso de archivo planilla
        ostringstream  ingresoDatosNomina;
        ingresoDatosNomina << "1 5000.56" << endl;
        ingresoDatosNomina << "2 10568.00" << endl;
        string entradaEjemploSalarios = ingresoDatosNomina.str();

        //Llenando planilla con los salarios
        planilla->agregarSalarios(entradaEjemploSalarios);

        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,4650.52" << endl;
        streamSalidaEsperada << "2,Angelica Curling,Diego Monroe,9828.24" << endl;
        streamSalidaEsperada << "Subtotal:,14478.76" << endl;
        streamSalidaEsperada << "Impuestos a retener:,1089.80" << endl;
        streamSalidaEsperada << "Total:,15568.56" << endl;
        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }
    TEST(LlenadoSalariosPlanillaTest, Test_AgregarSalarioTresTrabajadores) {
        Planilla* planilla = new Planilla();

        //Ingreso de archivo personas
        ostringstream ingresoDatos{};
        ingresoDatos << "1 Diego Monroe 1234@prueba.com 1 0" << endl;
        ingresoDatos << "2 Angelica Curling 9876@prueba.com 1 1" << endl;
        ingresoDatos << "3 Karol Corrales 2549@prueba.com 1 2" << endl;
        string entradaEjemploPersonas = ingresoDatos.str();

        //LLenado planilla con los datos personales de los trabajadores
        planilla->llenarPlanilla(entradaEjemploPersonas);

        //Ingreso de archivo planilla
        ostringstream  ingresoDatosNomina;
        ingresoDatosNomina << "1 5000.56" << endl;
        ingresoDatosNomina << "2 10568.00" << endl;
        ingresoDatosNomina << "3 3245.69" << endl;
        string entradaEjemploSalarios = ingresoDatosNomina.str();

        //Llenando planilla con los salarios
        planilla->agregarSalarios(entradaEjemploSalarios);

        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,4650.52" << endl;
        streamSalidaEsperada << "2,Angelica Curling,Diego Monroe,9828.24" << endl;
        streamSalidaEsperada << "3,Karol Corrales,Angelica Curling,3018.49" << endl;
        streamSalidaEsperada << "Subtotal:,17497.25" << endl;
        streamSalidaEsperada << "Impuestos a retener:,1317.00" << endl;
        streamSalidaEsperada << "Total:,18814.25" << endl;
        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }
    TEST(LlenadoPagoHorasPlanillaTest, Test_AgregarHorasDirector) {
        Planilla* planilla = new Planilla();

        //Ingreso de archivo personas
        ostringstream ingresoDatosPersonas{};
        ingresoDatosPersonas << "1 Diego Monroe 1234@prueba.com 2 0" << endl;
        string entradaEjemplo = ingresoDatosPersonas.str();
        planilla->llenarPlanilla(entradaEjemplo);

        //Ingreso de archivo planilla
        ostringstream  ingresoDatosHoras;
        ingresoDatosHoras << "1 42.26 55" << endl;
        string entradaEjemploSalarios = ingresoDatosHoras.str();

        //Llenando planilla con datos de salarios
        planilla->agregarHoras(entradaEjemploSalarios);

        //Resultado de la impresion de planilla
        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        //Resultado esperado
        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,2324.30" << endl;
        streamSalidaEsperada << "Subtotal:,2324.30" << endl;
        streamSalidaEsperada << "Impuestos a retener:,0.00" << endl;
        streamSalidaEsperada << "Total:,2324.30" << endl;

        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }
    TEST(LlenadoPagoHorasPlanillaTest, Test_AgregarHorasDosTrabajadores) {
        Planilla* planilla = new Planilla();

        //Ingreso de archivo personas
        ostringstream ingresoDatos{};
        ingresoDatos << "1 Diego Monroe 1234@prueba.com 2 0" << endl;
        ingresoDatos << "2 Angelica Curling 9876@prueba.com 2 1" << endl;
        string entradaEjemploPersonas = ingresoDatos.str();

        //LLenado planilla con los datos personales de los trabajadores
        planilla->llenarPlanilla(entradaEjemploPersonas);

        //Ingreso de archivo planilla
        ostringstream  ingresoDatosHoras;
        ingresoDatosHoras << "1 42.26 55" << endl;
        ingresoDatosHoras << "2 34.84 43" << endl;
        string entradaEjemploSalarios = ingresoDatosHoras.str();

        //Llenando planilla con los salarios
        planilla->agregarHoras(entradaEjemploSalarios);

        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,2324.30" << endl;
        streamSalidaEsperada << "2,Angelica Curling,Diego Monroe,1498.12" << endl;
        streamSalidaEsperada << "Subtotal:,3822.42" << endl;
        streamSalidaEsperada << "Impuestos a retener:,0.00" << endl;
        streamSalidaEsperada << "Total:,3822.42" << endl;
        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }
    TEST(LlenadoPagoHorasPlanillaTest, Test_AgregarHorasTresTrabajadores) {
        Planilla* planilla = new Planilla();

        //Ingreso de archivo personas
        ostringstream ingresoDatos{};
        ingresoDatos << "1 Diego Monroe 1234@prueba.com 2 0" << endl;
        ingresoDatos << "2 Angelica Curling 9876@prueba.com 2 1" << endl;
        ingresoDatos << "3 Karol Corrales 2549@prueba.com 2 2" << endl;
        string entradaEjemploPersonas = ingresoDatos.str();

        //LLenado planilla con los datos personales de los trabajadores
        planilla->llenarPlanilla(entradaEjemploPersonas);

        //Ingreso de archivo planilla
        ostringstream  ingresoDatosHoras;
        ingresoDatosHoras << "1 42.26 55" << endl;
        ingresoDatosHoras << "2 34.84 43" << endl;
        ingresoDatosHoras << "3 57.71 55" << endl;
        string entradaEjemploSalarios = ingresoDatosHoras.str();

        //Llenando planilla con los salarios
        planilla->agregarHoras(entradaEjemploSalarios);

        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,2324.30" << endl;
        streamSalidaEsperada << "2,Angelica Curling,Diego Monroe,1498.12" << endl;
        streamSalidaEsperada << "3,Karol Corrales,Angelica Curling,3174.05" << endl;
        streamSalidaEsperada << "Subtotal:,6996.47" << endl;
        streamSalidaEsperada << "Impuestos a retener:,0.00" << endl;
        streamSalidaEsperada << "Total:,6996.47" << endl;
        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }
    TEST(CreacionPlanillaTest, Test_Agregar_Empleados_UnNivel) {

        Planilla* planilla = new Planilla();
        //Ingreso de archivo
        ostringstream ingresoDatos{};
        ingresoDatos << "1 Diego Monroe 1234@prueba.com 1 0" << endl;
        ingresoDatos << "2 Angelica Curling 9876@prueba.com 2 1" << endl;
        ingresoDatos << "3 Karol Corrales 5641@prueba.com 1 1" << endl;
        ingresoDatos << "4 Dev Phrasab 4531@prueba.com 1 1" << endl;
        string entradaEjemplo = ingresoDatos.str();

        //LLenado planilla con los datos personales de los trabajadores
        planilla->llenarPlanilla(entradaEjemplo);

        //Resultado impresion de pantalla
        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,0.00" << endl;
        streamSalidaEsperada << "2,Angelica Curling,Diego Monroe,0.00" << endl;
        streamSalidaEsperada << "3,Karol Corrales,Diego Monroe,0.00" << endl;
        streamSalidaEsperada << "4,Dev Phrasab,Diego Monroe,0.00" << endl;
        streamSalidaEsperada << "Subtotal:,0.00" << endl;
        streamSalidaEsperada << "Impuestos a retener:,0.00" << endl;
        streamSalidaEsperada << "Total:,0.00" << endl;
        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }
    TEST(CreacionPlanillaTest, Test_Agregar_Empleados_DosNivel) {
        Planilla* planilla = new Planilla();
        //Ingreso de archivo
        ostringstream ingresoDatos{};
        ingresoDatos << "1 Diego Monroe 1234@prueba.com 1 0" << endl;
        ingresoDatos << "2 Angelica Curling 9876@prueba.com 2 1" << endl;
        ingresoDatos << "3 Karol Corrales 5641@prueba.com 1 1" << endl;
        ingresoDatos << "4 Dev Phrasab 4531@prueba.com 1 2" << endl;
        ingresoDatos << "450 Marcelo Padilla marcelo@prueba.com 2 3" << endl;
        string entradaEjemplo = ingresoDatos.str();

        //LLenado planilla con los datos personales de los trabajadores
        planilla->llenarPlanilla(entradaEjemplo);

        //Resultado impresion de pantalla
        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,0.00" << endl;
        streamSalidaEsperada << "2,Angelica Curling,Diego Monroe,0.00" << endl;
        streamSalidaEsperada << "4,Dev Phrasab,Angelica Curling,0.00" << endl;
        streamSalidaEsperada << "3,Karol Corrales,Diego Monroe,0.00" << endl;
        streamSalidaEsperada << "450,Marcelo Padilla,Karol Corrales,0.00" << endl;
        streamSalidaEsperada << "Subtotal:,0.00" << endl;
        streamSalidaEsperada << "Impuestos a retener:,0.00" << endl;
        streamSalidaEsperada << "Total:,0.00" << endl;
        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }
    TEST(CreacionPlanillaTest, Test_Agregar_Empleados_TresNivel) {
        Planilla* planilla = new Planilla();
        //Ingreso de archivo
        ostringstream ingresoDatos{};
        ingresoDatos << "1 Diego Monroe 1234@prueba.com 1 0" << endl;
        ingresoDatos << "2 Angelica Curling 9876@prueba.com 2 1" << endl;
        ingresoDatos << "3 Karol Corrales 5641@prueba.com 1 1" << endl;
        ingresoDatos << "4 Dev Phrasab 4531@prueba.com 1 2" << endl;
        ingresoDatos << "450 Marcelo Padilla marcelo@prueba.com 2 4" << endl;
        ingresoDatos << "650 Alberto Portilla alberto@prueba.com 2 4" << endl;
        string entradaEjemplo = ingresoDatos.str();

        //LLenado planilla con los datos personales de los trabajadores
        planilla->llenarPlanilla(entradaEjemplo);

        //Resultado impresion de pantalla
        ostringstream streamSalida{};
        streamSalida << *planilla;
        string actual = streamSalida.str();

        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "ID_Empleado, Nombre completo, Nombre completo del supervisor, Monto a pagar(monto neto)" << endl;
        streamSalidaEsperada << "1,Diego Monroe, ,0.00" << endl;
        streamSalidaEsperada << "2,Angelica Curling,Diego Monroe,0.00" << endl;
        streamSalidaEsperada << "4,Dev Phrasab,Angelica Curling,0.00" << endl;
        streamSalidaEsperada << "450,Marcelo Padilla,Dev Phrasab,0.00" << endl;
        streamSalidaEsperada << "650,Alberto Portilla,Dev Phrasab,0.00" << endl;
        streamSalidaEsperada << "3,Karol Corrales,Diego Monroe,0.00" << endl;
        streamSalidaEsperada << "Subtotal:,0.00" << endl;
        streamSalidaEsperada << "Impuestos a retener:,0.00" << endl;
        streamSalidaEsperada << "Total:,0.00" << endl;
        string esperada = streamSalidaEsperada.str();

        delete planilla;

        EXPECT_EQ(esperada, actual);
    }
}

namespace Test_EmpleadoAsalarido {  
    TEST(Test_TrabajadorAsalariado, Test_GetNombre) {

        Empleado* empleado = new EmpleadoAsalariado(1, "Diego", "Monroe", "prueba@.com");
        string actual = empleado->getNombreCompleto();
        delete empleado;
        EXPECT_EQ("Diego Monroe", actual);
    }
    TEST(Test_TrabajadorAsalariado, Agregar_EmpleadoDirecto) {
        Empleado* empleado1 = new EmpleadoAsalariado(1, "Diego", "Monroe", "prueba@.com");
        Empleado* empleado2 = new EmpleadoAsalariado(2, "Angelica", "Curling", "2prueba@.com", empleado1);

        empleado1->agregarEmpleadoDirecto(empleado2);

        ostringstream streamsalida;
        streamsalida << *empleado1;
        string actual = streamsalida.str();

        ostringstream streamesperado;
        streamesperado << "1,Diego Monroe, ,0.00" << endl;
        streamesperado << "2,Angelica Curling,Diego Monroe,0.00" << endl;
        string esperado = streamesperado.str();

        delete empleado1;
        EXPECT_EQ(esperado, actual);
    }
    TEST(Test_TrabajadorAsalariado, Test_AgregarSalario) {

        Empleado* empleado = new EmpleadoAsalariado(1, "Diego", "Monroe", "prueba@.com");
        empleado->agregarSalario(1000);

        ostringstream streamsalida;
        streamsalida << *empleado;
        string actual = streamsalida.str();

        ostringstream streamesperado;
        streamesperado << "1,Diego Monroe, ,1000.00" << endl;
        string esperado = streamesperado.str();

        delete empleado;
        EXPECT_EQ(esperado, actual);
        }
}

namespace Test_EmpleadoHoras {
    TEST(Test_TrabajadorHoras, Test_GetNombre) {

        Empleado* empleado = new EmpleadoHoras(1, "Diego", "Monroe", "prueba@.com");
        string actual = empleado->getNombreCompleto();
        delete empleado;
        EXPECT_EQ("Diego Monroe", actual);
    }
    TEST(Test_TrabajadorHoras, Agregar_EmpleadoDirecto) {
        Empleado* empleado1 = new EmpleadoHoras(1, "Diego", "Monroe", "prueba@.com");
        Empleado* empleado2 = new EmpleadoHoras(2, "Angelica", "Curling", "2prueba@.com", empleado1);

        empleado1->agregarEmpleadoDirecto(empleado2);

        ostringstream streamsalida;
        streamsalida << *empleado1;
        string actual = streamsalida.str();

        ostringstream streamesperado;
        streamesperado << "1,Diego Monroe, ,0.00" << endl;
        streamesperado << "2,Angelica Curling,Diego Monroe,0.00" << endl;
        string esperado = streamesperado.str();

        delete empleado1;
        EXPECT_EQ(esperado, actual);
    }
    TEST(Test_TrabajadorHoras, Test_AgregarHoras) {

        Empleado* empleado = new EmpleadoHoras(1, "Diego", "Monroe", "prueba@.com");
        empleado->agregarPagoHoras(20,10);

        ostringstream streamsalida;
        streamsalida << *empleado;
        string actual = streamsalida.str();

        ostringstream streamesperado;
        streamesperado << "1,Diego Monroe, ," <<20*10<<".00"<< endl;
        string esperado = streamesperado.str();

        delete empleado;
        EXPECT_EQ(esperado, actual);
    }
}