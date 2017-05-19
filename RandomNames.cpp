#include "RandomNames.hpp"
#include <fstream>
#include <ctime>
#include <cstdlib>

RandomNames::RandomNames(const char* fNamesFile, const char* lNamesFile) : id(100001){
    srand(time(0));
    ifstream streamFNames, streamLNames;
    streamFNames.open(fNamesFile);
    streamLNames.open(lNamesFile);
    if(streamFNames.is_open()){
        while(!streamFNames.eof()){
            char* current = new char[32];
            streamFNames.getline(current, 32);
            fnames.push_back(current);
        }
    }
    if(streamLNames.is_open()){
        while(!streamLNames.eof()){
            char* current = new char[32];
            streamLNames.getline(current, 32);
            lnames.push_back(current);
        }
    }
}

RandomNames::~RandomNames(){
    for(int i = 0; i < fnames.size(); i++){
        delete fnames[i];
    }
    for(int i = 0; i < lnames.size(); i++){
        delete lnames[i];
    }
}

char* RandomNames::getFname(){
    return fnames[rand()%fnames.size()];
}

char* RandomNames::getLname(){
    return lnames[rand()%lnames.size()];
}

int RandomNames::getId(){
    return id++;
}

float RandomNames::getGpa(){
    float gpa = (rand() % 1000);
    gpa /= 100;
    while(gpa > 4){
        gpa--;
    }
    return gpa;
}