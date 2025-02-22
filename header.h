#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>

struct studentas {
    std::vector<float> pazymiai;
    std::string vardas;
    std::string pavarde;
    float egzaminoRezultatas;
    int pKiekis;
    float galutinisV;
    float galutinisM;
};


float skaiciuotiVid(int pKiekis, std::vector<float>&pazymiai){
    float vidurkis;
    float suma = 0;
    for(int i = 0; i < pKiekis; i++){
        suma += pazymiai[i];
    }

    if(suma == 0){
        vidurkis = 0;
    }
    else{
        vidurkis = suma/pKiekis;
    }
    return vidurkis;
}

float skaiciuotiMed(int pKiekis, std::vector<float>&pazymiai){
    float mediana;

    if(pKiekis % 2 == 0){
        return mediana = (pazymiai[pKiekis/2 - 1] + pazymiai[pKiekis/2])/2;
    }
    else{
        return mediana = pazymiai[(pKiekis+1)/2 - 1];
    }
}

void spausdinimasFaile(char pasirinkimas, std::vector<studentas> &grupe){

    std::cout << grupe.size();

    std::ofstream outFile("duomenys.txt");

    outFile << "Pavarde" << std::setw(20) << "Vardas" << std::setw(40) << "Galutinis(vid.)/Galutinis(med.)" << std::endl;
    outFile << "-------------------------------------------------------------------" << std::endl;

    for(int i = 0; grupe.size(); i++){

        if(pasirinkimas == 'v'){

            outFile << grupe[i].pavarde << std::setw(17) << grupe[i].vardas << std::setw(15) << std::fixed << std::setprecision(2) << grupe[i].galutinisV << std::endl;

        } else {

            outFile << grupe[i].pavarde << std::setw(17) << grupe[i].vardas << std::setw(15) << std::fixed << std::setprecision(2) << grupe[i].galutinisM << std::endl;
 
        }
    }
    outFile.close();
}