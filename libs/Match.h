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

    string getNameForLocalTeam(){
        TextFileHandler fileHandler("resultados.txt");
        List<string> lines = fileHandler.readLines();

        for(int i = 0; i < lines.size; i++){
        string line = lines.get(i);
        List<string> tokens = split(line, ',');
        localTeam = tokens.get(0);
        }

        return localTeam;
    }

    string getNameForVisitingTeam(){
        TextFileHandler fileHandler("resultados.txt");
        List<string> lines = fileHandler.readLines();
        
        for(int i = 0; i < lines.size; i++){
        string line = lines.get(i);
        List<string> tokens = split(line, ',');
        visitingTeam = tokens.get(2);
        }

        return visitingTeam;
    }

    int getPointsForLocalTeam() {
        TextFileHandler fileHandler("resultados.txt");
        List<string> lines = fileHandler.readLines();

        for(int i = 0; i < lines.size; i++){
        string line = lines.get(i);
        List<string> tokens = split(line, ',');
        scoreLocalTeam = stoi(tokens.get(1));
        }

        return scoreLocalTeam;
    }

    int getPointsForVisitingTeam() {
        TextFileHandler fileHandler("resultados.txt");
        List<string> lines = fileHandler.readLines();

        for(int i = 0; i < lines.size; i++){
        string line = lines.get(i);
        List<string> tokens = split(line, ',');
        scoreVisitingTeam = stoi(tokens.get(3));
        }

        return scoreVisitingTeam;
    }
};

Match getMatchFromLine(string line, char delimiter) {
        Match match;
        
        
        return match;
}

string getLineFromMatch(Match match, char delimiter) {
    string line;

    return line;
}


     

#endif /* MATCH_H */