#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>

//struktura studentas

struct studentas{
    float* pazymiai;
    int pKiekis;
    std::string vardas;
    std::string pavarde;
    float egzaminoRezultatas;
};

int main() {

    studentas studentas;

    


    std::cout << "Iveskite studento varda: " << std::endl;
    std::cin >> studentas.vardas;
    std::cout << "Iveskite studento pavarde: " << std::endl;
    std::cin >> studentas.pavarde;

    std::cout << "Iveskite pazymiu kieki: " << std::endl;
    std::cin >> studentas.pKiekis;

    while(studentas.pKiekis <= 0){
        std::cout << "Pazymiu kiekis negali buti 0 arba neigiamas, iveskite teigiama skaiciu: " << std::endl;
        std::cin >> studentas.pKiekis;
    }

    // dinaminis masyvas

    studentas.pazymiai = new float[studentas.pKiekis];

    char pazymiuGenBudas;
    std::cout << "Ar norite atsitiktinai generuoti studento pazymius? t/n(taip/ne)" << std::endl;
    std::cin >> pazymiuGenBudas;

    while(pazymiuGenBudas != 't' && pazymiuGenBudas != 'n'){
        std::cout << "Ivedete bloga simboli, veskite is naujo: " << std::endl;
        std::cin >> pazymiuGenBudas;
    }

    if(pazymiuGenBudas == 't'){
        srand(time(0));

        for(int i = 0; i < studentas.pKiekis; i++){
            float randomPazymys = rand()%11;
            studentas.pazymiai[i] = randomPazymys;
        }
        
        studentas.egzaminoRezultatas = rand()%11;

    }
    else{

        std::cout << "Iveskite pazymius: " << std::endl;

        for(int i = 0; i < studentas.pKiekis; i++){
            std::cout << "Pazymys " << i + 1 << ": ";
            std::cin >> studentas.pazymiai[i];
        }
    
        std::cout << "Iveskite egzamino pazymi: " << std::endl;
        std::cin >> studentas.egzaminoRezultatas;

    }

    
    float galutinisV;
    float galutinisM;
    float vidurkis;
    float suma = 0;

    //vidurkis

    for(int i = 0; i < studentas.pKiekis; i++){
        suma += studentas.pazymiai[i];
    }

    if(suma == 0){
        vidurkis = 0;
    }
    else{
        vidurkis = suma/studentas.pKiekis;
    }

    // sorting

    float temp;

    for(int i = 0; i < studentas.pKiekis - 1; i++){
        for(int j = 0; j < studentas.pKiekis - 1; j++){
            if(studentas.pazymiai[j] > studentas.pazymiai[j + 1]){
                temp = studentas.pazymiai[j];
                studentas.pazymiai[j] = studentas.pazymiai[j + 1];
                studentas.pazymiai[j + 1] = temp;
            }
        }
    }

    // mediana

    float mediana = 0;

    if(studentas.pKiekis % 2 == 0) {
        mediana = (studentas.pazymiai[studentas.pKiekis / 2 - 1] + studentas.pazymiai[studentas.pKiekis / 2]) / 2.0;
    } 
    else {
        mediana = studentas.pazymiai[(studentas.pKiekis + 1) / 2 - 1];
    }

    // galutinis pazymys

    galutinisV = vidurkis * 0.4 + studentas.egzaminoRezultatas * 0.6;
    galutinisM = mediana * 0.4 + studentas.egzaminoRezultatas * 0.6;

    //lentele

    char pasirinkimas;
    std::cout << "Ar norite skaiciuoti galutini ivertinima naudojant pazymiu vidurki ar mediana (v/m)? " << std::endl;
    std::cin >> pasirinkimas;

    while(pasirinkimas != 'm' && pasirinkimas != 'v') {
        std::cout << "Ivedete bloga simboli, bandykite dar karta (v/m): ";
        std::cin >> pasirinkimas;
    }

    if(pasirinkimas == 'v'){
        std::cout << "Pavarde      Vardas       Galutinis(vid.)" << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << studentas.pavarde << "      " << studentas.vardas << "            " << std::fixed << std::setprecision(2) << galutinisV << std::endl;
    }   
    else {
        std::cout << "Pavarde      Vardas       Galutinis(med.)" << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << studentas.pavarde << "      " << studentas.vardas << "            " << std::fixed << std::setprecision(2) << galutinisM << std::endl;
    }

    delete[] studentas.pazymiai;

    return 0;
}
