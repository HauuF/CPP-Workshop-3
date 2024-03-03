#ifndef MATCH_H
#define MATCH_H

#include <string>
#include <sstream>
#include "List.h"
#include "TextFileHandler.h"

using namespace std;

struct Match {
    string localTeam;
    int scoreLocalTeam;
    string visitingTeam;
    int scoreVisitingTeam;
    //
    int number;

    string getNameForLocalTeam(){
        TextFileHandler fileHandler("resultados.txt");
        List<string> lines = fileHandler.readLines();
        string line = lines.get(number);
        List<string> tokens = split(line, ',');
        localTeam = tokens.get(0);

        return localTeam;
    }

    string getNameForVisitingTeam(){
        TextFileHandler fileHandler("resultados.txt");
        List<string> lines = fileHandler.readLines();
        string line = lines.get(number);
        List<string> tokens = split(line, ',');
        visitingTeam = tokens.get(2);

        return visitingTeam;
    }

    int getPointsForLocalTeam() {
        TextFileHandler fileHandler("resultados.txt");
        List<string> lines = fileHandler.readLines();
        string line = lines.get(number);
        List<string> tokens = split(line, ',');
        scoreLocalTeam = stoi(tokens.get(1));

        return scoreLocalTeam;
    }

    int getPointsForVisitingTeam() {
        TextFileHandler fileHandler("resultados.txt");
        List<string> lines = fileHandler.readLines();
        string line = lines.get(number);
        List<string> tokens = split(line, ',');
        scoreVisitingTeam = stoi(tokens.get(3));

        return scoreVisitingTeam;
    }
};

Match getMatchFromLine(string line, char delimiter) {
        Match match;
        string empatesnomarcador, empates, winlocal, winvisitante;
        TextFileHandler fileHandler("resultados.txt");
        List<string> lines = fileHandler.readLines();
        for(int i = 0; i < lines.size; i++){
            match.number = i;
            match.getNameForLocalTeam();
            match.getPointsForLocalTeam();
            match.getNameForVisitingTeam();
            match.getPointsForVisitingTeam();
        if(match.scoreLocalTeam == 0 || match.scoreVisitingTeam == 0){
           empatesnomarcador = match.localTeam + delimiter + to_string(match.scoreLocalTeam) + delimiter + match.visitingTeam + delimiter + to_string(match.scoreVisitingTeam); 
           TextFileHandler fileHandler("reportecreado_empates_sin_marcador.txt");
           fileHandler.writeSingleLine(empatesnomarcador);
        }
        if(match.scoreLocalTeam == match.scoreVisitingTeam){
           empates = match.localTeam + delimiter + to_string(match.scoreLocalTeam) + delimiter + match.visitingTeam + delimiter + to_string(match.scoreVisitingTeam); 
           TextFileHandler fileHandler("reportecreado_empates.txt");
           fileHandler.writeSingleLine(empates);
        }
        if(match.scoreLocalTeam > match.scoreVisitingTeam){
           winlocal = match.localTeam + delimiter + to_string(match.scoreLocalTeam) + delimiter + match.visitingTeam + delimiter + to_string(match.scoreVisitingTeam); 
           TextFileHandler fileHandler("reportecreado_ganador_local.txt");
           fileHandler.writeSingleLine(winlocal);
        }
        if(match.scoreLocalTeam < match.scoreVisitingTeam){
           winvisitante = match.localTeam + delimiter + to_string(match.scoreLocalTeam) + delimiter + match.visitingTeam + delimiter + to_string(match.scoreVisitingTeam); 
           TextFileHandler fileHandler("reportecreado_ganador_visitante.txt");
           fileHandler.writeSingleLine(winvisitante);
        }
        }
        return match;
}

string getLineFromMatch(Match match, char delimiter) {
    string line;
    string fileHandlerText("resultados.txt");
    line = match.localTeam + delimiter + to_string(match.scoreLocalTeam) + delimiter + match.visitingTeam + delimiter + to_string(match.scoreVisitingTeam);
    TextFileHandler fileHandler("resultados.txt");
    fileHandler.writeSingleLine(line);

    return line;
}  

#endif /* MATCH_H */