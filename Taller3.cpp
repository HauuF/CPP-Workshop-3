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
    cout << "5. Salir." << endl;
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
            Match match;
            char delimiter = ';';
            string LocalName, VisitingName, LocalScore, VisitingScore;
        getline(cin, LocalName);
        cout << "Introduzca el nombre del equipo local:" << endl;
        getline(cin, LocalName);
        cout << "Introduzca el marcador del equipo local:" << endl;
        getline(cin, LocalScore);
        cout << "Introduzca el nombre del equipo visitante:" << endl;
        getline(cin, VisitingName);
        cout << "Introduzca el marcador del equipo visitante:" << endl;
        getline(cin, VisitingScore);
        match.localTeam = LocalName;
        match.scoreLocalTeam = stoi(LocalScore);
        match.visitingTeam = VisitingName;
        match.scoreVisitingTeam = stoi(VisitingScore);

        string line = getLineFromMatch(match, delimiter);
            break;

           /*case 3:
            break;

            case 4:
            break;

            case 5:
            cout << "Saliendo..." << endl;
            break;

            default:
            cout << "Opci+on no disponible, vuelva a elegir." << endl;
*/ 
        }
    }while(eleccion != 5);
    return 0;


}
