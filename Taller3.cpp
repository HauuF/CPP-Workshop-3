#include "libs/List.h"
#include "libs/Match.h"
#include "libs/TextFileHandler.h"
#include <iostream>

using namespace std;

int main() {
    
    struct Match prueba;
    TextFileHandler fileHandler("resultados.txt");
    List<string> lines = fileHandler.readLines();
    
    int eleccion = 0;
    cout << "Menú de inicio." << endl;
    do{
    cout << "1. Mostrar lista de partidos." << endl;
    cout << "2. Agregar partido." << endl;
    cout << "3. Eliminar partido." << endl;
    cout << "4. Realizar reportes." << endl;
    cout << "0 Salir." << endl;
    cout << "Seleccione su opción de preferencia: ";
    cin >> eleccion;
        switch(eleccion){
            case 1:
            cout << endl;          
                for(prueba.number = 0; prueba.number < lines.size; prueba.number++) {
                prueba.getNameForLocalTeam();
                prueba.getPointsForLocalTeam();
                prueba.getNameForVisitingTeam();
                prueba.getPointsForVisitingTeam();
                cout << "Partido #"<<prueba.number + 1 <<"" << endl;
                cout << "Equipo local:"<<prueba.localTeam<<"" << endl;
                cout << "Puntos del equipo local:"<<prueba.scoreLocalTeam<<"" << endl;
                cout << "Equipo visitante:"<<prueba.visitingTeam<<"" << endl;
                cout << "Puntos del equipo visitante:"<<prueba.scoreVisitingTeam<<"" << endl;
                cout << endl;
                }

            break;

            case 2:
            {
            cout << endl;
            Match match;
            char delimiter = ',';
            string LocalName, VisitingName, LocalScore, VisitingScore;
        getline(cin, LocalName);
        cout << "Introduzca el nombre del equipo local: ";
        getline(cin, LocalName);
        cout << "Introduzca el marcador del equipo local: ";
        getline(cin, LocalScore);
        cout << "Introduzca el nombre del equipo visitante: ";
        getline(cin, VisitingName);
        cout << "Introduzca el marcador del equipo visitante: ";
        getline(cin, VisitingScore);
        match.localTeam = LocalName;
        match.scoreLocalTeam = stoi(LocalScore);
        match.visitingTeam = VisitingName;
        match.scoreVisitingTeam = stoi(VisitingScore);

        string line = getLineFromMatch(match, delimiter);
        cout << endl;
        }
            break;

           case 3:
           {
           cout << endl;
           int eleccion;
            TextFileHandler fileHandler("resultados.txt");
            List<string> lines = fileHandler.readLines();

           cout << "Elija el partido que desea eliminar (para ver partidos regrese al menú (presionando 0) y presione 1.)" << endl;
           cout << "Elija del 1 al "<<lines.size<<":";
           cin >> eleccion;

           if (eleccion >= 1 && eleccion <= lines.size) {
        lines.remove(eleccion - 1);
        fileHandler.writeLines(lines);
        cout << "Partido eliminado" << endl;
        cout << endl;
        break;

        } else if (eleccion == 0) {
            cout << "Regresando al menú principal..." << endl;
            cout << endl;
            break;

        } else {
            cout << "Selección inválida." << endl;
            cout << endl;
        }
        }
            break;

            case 4:
            {
        cout << endl;
        Match match;
        getMatchFromLine("", ';');     
        cout << "Reportes creados." << endl;
        cout << endl;
            }
            break;

            case 0:
            cout << "Saliendo..." << endl;
            break;

            default:
            cout << "Opción no disponible, vuelva a elegir." << endl;

        }
    }while(eleccion != 0);
    return 0;
}