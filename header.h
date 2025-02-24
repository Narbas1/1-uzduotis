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
#include <numeric>

struct studentas {
    std::vector<float> pazymiai;
    std::string vardas;
    std::string pavarde;
    float egzaminoRezultatas;
    float galutinisV;
    float galutinisM;
};

float skaiciuotiVid(std::vector<float>&pazymiai){

    if(pazymiai.empty()) return 0.0f;
    float sum = std::accumulate(pazymiai.begin(), pazymiai.end(), 0.0f);
    return sum / pazymiai.size();

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

void spausdinimasFaile(char galutinioBudas, std::vector<studentas> &grupe){

    std::ofstream outFile("duomenys.txt");

    outFile << "Pavarde" << std::setw(20) << "Vardas" << std::setw(40) << "Galutinis(vid.)/Galutinis(med.)" << std::endl;
    outFile << "-------------------------------------------------------------------" << std::endl;

    for(int i = 0; i < grupe.size(); i++){

        if(galutinioBudas == 'v'){

            outFile << grupe[i].pavarde << std::setw(17) << grupe[i].vardas << std::setw(15) << std::fixed << std::setprecision(2) << grupe[i].galutinisV << std::endl;

        } else {

            outFile << grupe[i].pavarde << std::setw(17) << grupe[i].vardas << std::setw(15) << std::fixed << std::setprecision(2) << grupe[i].galutinisM << std::endl;
 
        }
    }
    outFile.close();
}

void rusiuotiOutput(std::vector<studentas>& grupe, char rusiavimoBudas, char galutinioBudas){
    
    if(rusiavimoBudas == 'p'){
        std::sort(grupe.begin(), grupe.end(), [](const studentas& a, const studentas& b){
            if(a.pavarde == b.pavarde){
                return a.vardas < b.vardas;
            }
            return a.pavarde < b.pavarde;
        });
    }
    else{
        std::sort(grupe.begin(), grupe.end(), [galutinioBudas](const studentas& a, const studentas& b){
            if(galutinioBudas == 'v'){
                return a.galutinisV > b.galutinisV;
            }
            else{
                return a.galutinisM > b.galutinisM;
            }
        });
    }
}

void spausdinimasTerminale(std::vector<studentas>&grupe, char galutinioBudas){

    std::cout << "Pavarde" << std::setw(20) << "Vardas" << std::setw(40) << "Galutinis(vid.)/Galutinis(med.)" << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;

    for(int i = 0; i < grupe.size(); i++){
            
        if(galutinioBudas == 'v'){
            std::cout << grupe[i].pavarde << std::setw(17) << grupe[i].vardas << std::setw(15) << std::fixed << std::setprecision(2) << grupe[i].galutinisV << std::endl;

        }
        else{
            std::cout << grupe[i].pavarde << std::setw(17) << grupe[i].vardas << std::setw(15)  << std::fixed << std::setprecision(2) << grupe[i].galutinisM << std::endl;
        }
    }
}