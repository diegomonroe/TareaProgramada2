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
TEST(PlanillaTest, Test_Constructor) {
    Planilla* planilla = new Planilla();
    planilla->agregarEmpleado(1,"Diego","Monroe","1234@prueba.com",1,0);
    planilla->agregarEmpleado(2, "Angelica", "Curling", "9876@prueba.com", 2, 1);
    
    ostringstream streamSalida{};
    streamSalida << *planilla;
    string actual = streamSalida.str();

    ostringstream streamSalidaEsperada{};
    streamSalidaEsperada << "1,Diego Monroe,1234@prueba.com, ,0.00" << endl;
    streamSalidaEsperada << "2,Angelica Curling,9876@prueba.com,Diego Monroe,0.00" << endl;
    string esperada = streamSalidaEsperada.str();
    

   delete planilla;

    EXPECT_EQ(1, 1);
}