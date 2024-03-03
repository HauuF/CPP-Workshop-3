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
        TextFileHandler fileHandler("resultados.txt");
        List<string> lines = fileHandler.readLines();
        string LocalName, LocalScore, VisitingName, VisitingScore;
        LocalName = match.localTeam;
        LocalScore = match.scoreLocalTeam;
        VisitingName = match.visitingTeam;
        VisitingScore = match.scoreVisitingTeam;
    
        return match;
}

string getLineFromMatch(Match match, char delimiter) {
    string line;
        string fileHandlerText("resultados.txt");
        fstream file;
        file.open(fileHandlerText, ios::out | ios::app);
        if(file.fail()){
        return line;
        }
        line = match.localTeam + delimiter + to_string(match.scoreLocalTeam) + delimiter + match.visitingTeam + delimiter + to_string(match.scoreVisitingTeam);
    TextFileHandler fileHandler("resultados.txt");
    fileHandler.writeSingleLine(line);
    file.close(); 

    return line;
}  

#endif /* MATCH_H */