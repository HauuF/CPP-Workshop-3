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
        int contadorempatesnogoles = 0, contadorempates = 0, contadorwinlocal = 0, contadorwinvisitante = 0;
        float prempatesnogoles = 0, prempates = 0, prwinlocal = 0, prwinvisitante = 0;
        TextFileHandler empatesNomarcadorFileHandler("reporteCreado_empates_sin_marcador.txt");
        empatesNomarcadorFileHandler.writeSingleLine("Reporte de partidos empatados sin goles");
        empatesNomarcadorFileHandler.writeSingleLine("");
        empatesNomarcadorFileHandler.writeSingleLine("===================================");
        empatesNomarcadorFileHandler.writeSingleLine("");
        TextFileHandler empatesFileHandler("reportecreado_empates.txt");
        empatesFileHandler.writeSingleLine("Reporte de partidos empatados");
        empatesFileHandler.writeSingleLine("");
        empatesFileHandler.writeSingleLine("===================================");
        empatesFileHandler.writeSingleLine("");
        TextFileHandler winLocalFileHandler("reporteCreado_ganador_local.txt");
        winLocalFileHandler.writeSingleLine("Reporte de partidos ganados por el equipo local");
        winLocalFileHandler.writeSingleLine("");
        winLocalFileHandler.writeSingleLine("===================================");
        winLocalFileHandler.writeSingleLine("");
        TextFileHandler winVisitanteFileHandler("reporteCreado_ganador_visitante.txt");
        winVisitanteFileHandler.writeSingleLine("Reporte de partidos ganados por el equipo visitante");
        winVisitanteFileHandler.writeSingleLine("");
        winVisitanteFileHandler.writeSingleLine("===================================");
        winVisitanteFileHandler.writeSingleLine("");
    
        List<string> lines = TextFileHandler("resultados.txt").readLines();
        for(int i = 0; i < lines.size; i++){
            match.number = i;
            match.getNameForLocalTeam();
            match.getPointsForLocalTeam();
            match.getNameForVisitingTeam();
            match.getPointsForVisitingTeam();
        if(match.scoreLocalTeam == 0 && match.scoreVisitingTeam == 0){ 
        contadorempatesnogoles++;
           empatesnomarcador = match.localTeam + " " + to_string(match.scoreLocalTeam) + " " + match.visitingTeam + " " + to_string(match.scoreVisitingTeam); 
           empatesNomarcadorFileHandler.writeSingleLine(empatesnomarcador);
        }
        if(match.scoreLocalTeam == match.scoreVisitingTeam && match.scoreLocalTeam != 0){
        contadorempates++;
           empates = match.localTeam + " " + to_string(match.scoreLocalTeam) + " " + match.visitingTeam + " " + to_string(match.scoreVisitingTeam); 
           empatesFileHandler.writeSingleLine(empates);
        }
        if(match.scoreLocalTeam > match.scoreVisitingTeam){
        contadorwinlocal++;
           winlocal = match.localTeam + " " + to_string(match.scoreLocalTeam) + " " + match.visitingTeam + " " + to_string(match.scoreVisitingTeam); 
           winLocalFileHandler.writeSingleLine(winlocal);
        }
        if(match.scoreLocalTeam < match.scoreVisitingTeam){
        contadorwinvisitante++;
           winvisitante = match.localTeam + " " + to_string(match.scoreLocalTeam) + " " + match.visitingTeam + " " + to_string(match.scoreVisitingTeam); 
           winVisitanteFileHandler.writeSingleLine(winvisitante);
        }
                }
        int partidos = lines.size;
        float prprpr = partidos;
        prempatesnogoles = (contadorempatesnogoles / prprpr) * 100;
        prempates = (contadorempates / prprpr) * 100;
        prwinlocal = (contadorwinlocal / prprpr) * 100;
        prwinvisitante = (contadorwinvisitante / prprpr) * 100;
        empatesNomarcadorFileHandler.writeSingleLine("");
        empatesNomarcadorFileHandler.writeSingleLine("---------------------------------");
        empatesNomarcadorFileHandler.writeSingleLine("");
        empatesNomarcadorFileHandler.writeSingleLine("Cantidad de partidos empatados sin goles: " + to_string(contadorempatesnogoles));
        empatesNomarcadorFileHandler.writeSingleLine("Cantidad de partidos totales: " + to_string(partidos));
        empatesNomarcadorFileHandler.writeSingleLine("Porcentaje de partidos empatados sin goles: " + to_string(prempatesnogoles) + "%");
        empatesFileHandler.writeSingleLine("");
        empatesFileHandler.writeSingleLine("---------------------------------");
        empatesFileHandler.writeSingleLine("");
        empatesFileHandler.writeSingleLine("Cantidad de partidos empatados: " + to_string(contadorempates));
        empatesFileHandler.writeSingleLine("Cantidad de partidos totales: " + to_string(partidos));
        empatesFileHandler.writeSingleLine("Porcentaje de partidos empatados: " + to_string(prempates) + "%");
        winLocalFileHandler.writeSingleLine("");
        winLocalFileHandler.writeSingleLine("---------------------------------");
        winLocalFileHandler.writeSingleLine("");
        winLocalFileHandler.writeSingleLine("Cantidad de partidos ganados por el equipo local: " + to_string(contadorwinlocal));
        winLocalFileHandler.writeSingleLine("Cantidad de partidos totales: " + to_string(partidos));
        winLocalFileHandler.writeSingleLine("Porcentaje de partidos ganados por el equipo local: " + to_string(prwinlocal) + "%");
        winVisitanteFileHandler.writeSingleLine("");
        winVisitanteFileHandler.writeSingleLine("---------------------------------");
        winVisitanteFileHandler.writeSingleLine("");
        winVisitanteFileHandler.writeSingleLine("Cantidad de partidos ganados por el equipo visitante: " + to_string(contadorwinvisitante));
        winVisitanteFileHandler.writeSingleLine("Cantidad de partidos totales: " + to_string(partidos));
        winVisitanteFileHandler.writeSingleLine("Porcentaje de partidos ganados por el equipo visitante: " + to_string(prwinvisitante) + "%");

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