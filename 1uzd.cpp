#include <iostream>
#include <vector>

//struktura studentas

struct studentas{
    std::vector<float>pazymiai;
    std::string vardas;
    std::string pavarde;
    float egzaminoRezultatas;
};

int main(){

    std::vector<studentas> grupe;

    studentas studentas;
    std::cout << "Iveskite studento varda: " << std::endl;
    std::cin >> studentas.vardas;
    std::cout << "Iveskite studento pavarde: " << std::endl;
    std::cin >> studentas.pavarde;

    std::cout << "Iveskite pazymiu kieki" << std::endl;
    int pKiekis;
    std::cin >> pKiekis;

    std::cout << "Iveskite pazymius: " << std::endl;

    for(int i = 0; i < pKiekis; i++){
        int pazymys = 0;
        std::cout << "Pazymys " << i + 1 << ". ";
        std::cin >> pazymys;
        studentas.pazymiai.push_back(pazymys);
    }

    std::cout << "Iveskite egzamino pazymi: " << std::endl;
    std::cin >> studentas.egzaminoRezultatas;

    float galutinisV;
    float galutinisM;
    float vidurkis;
    float suma = 0;

    //vidurkis

    for(int i = 0; i < pKiekis; i++){
        suma += studentas.pazymiai[i];
    }

    vidurkis = suma/pKiekis;
    
    //sorting

    float temp;
    for(int i = 0; i < pKiekis - 1; i++){
        for(int j = 0; j < pKiekis - 1; j++){
            if(studentas.pazymiai[j] > studentas.pazymiai[j + 1]){
                temp = studentas.pazymiai[j];
                studentas.pazymiai[j] = studentas.pazymiai[j + 1];
                studentas.pazymiai[j + 1] = temp;
            }
        }
    }

    //mediana

    float mediana = 0;

    if(pKiekis % 2 == 0){
        mediana = (studentas.pazymiai[pKiekis/2 - 1] + studentas.pazymiai[pKiekis/2])/2;
    }
    else{
        mediana = studentas.pazymiai[(pKiekis+1)/2 - 1];
    }

    //galutinis

    galutinisV = vidurkis*0.4 + studentas.egzaminoRezultatas*0.6;
    galutinisM = mediana*0.4 + studentas.egzaminoRezultatas*0.6;

    //lentele
    char pasirinkimas;
    std::cout << "Ar norite skaiciuoti galutini ivertinima naudojant pazymiu vidurki ar mediana(v/m)?" << std::endl;
    std::cin >> pasirinkimas;

    while(pasirinkimas != 'm' && pasirinkimas != 'v'){
        std::cout << "Ivedete bloga simboli, iveskite is naujo: " << std::endl;
        std::cin >> pasirinkimas;
    }

    if(pasirinkimas == 'v'){
        std::cout << "Pavarde" << "   " << "Vardas" << "   " << "Galutinis(vid.)" << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        std::cout << studentas.pavarde << "   " << studentas.vardas << "   " << galutinisV << std::endl;
    }
    else{
        std::cout << "Pavarde" << "   " << "Vardas" << "   " << "Galutinis(med.)" << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        std::cout << studentas.pavarde << "   " << studentas.vardas << "   " << galutinisM << std::endl;
    }
    return 0;
}