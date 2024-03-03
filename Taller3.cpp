#include "libs/List.h"
#include "libs/Match.h"
#include "libs/TextFileHandler.h"

#include <iostream>


using namespace std;

 

int main() {
    
    struct Match prueba;
    prueba.getNameForLocalTeam();
    prueba.getPointsForLocalTeam();
    prueba.getNameForVisitingTeam();
    prueba.getPointsForVisitingTeam();
    
    int eleccion = 0;
    cout << "Menú de inicio." << endl;
    do{
    cout << "1. Mostrar lista de partidos." << endl;
    cout << "2. Agregar partido." << endl;
    cout << "3. Eliminar partido." << endl;
    cout << "4. Realizar reportes." << endl;
    cout << "5. Salir." << endl;
    cout << "Seleccione su opción de preferencia: ";
    cin >> eleccion;
        switch(eleccion){
            case 1:
            cout << endl;          
                
                cout << "Equipo local:"<<prueba.localTeam<<"" << endl;
                cout << "Puntos del equipo local:"<<prueba.scoreLocalTeam<<"" << endl;
                cout << "Equipo visitante:"<<prueba.visitingTeam<<"" << endl;
                cout << "Puntos del equipo visitante:"<<prueba.scoreVisitingTeam<<"" << endl;
                cout << endl;
            
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            cout << "Saliendo..." << endl;
            break;

            default:
            cout << "Opci+on no disponible, vuelva a elegir." << endl;

        }
    }while(eleccion != 5);
    return 0;


}
