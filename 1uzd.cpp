#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>

//struktura studentas

struct studentas{
    std::vector<float>pazymiai;
    std::string vardas;
    std::string pavarde;
    float egzaminoRezultatas;
    int pKiekis;
};

int main(){

    studentas studentas;
    float galutinisV;
    float galutinisM;
    float vidurkis;
    float suma = 0;
    int meniu;

    std::cout << "Pasirinkite generavimo buda: 1 - ranka, 2 - generuoti pazymius, 3 - generuoti pazymius, studentu vardus, pavardes - 3, baigti darba - 4." << std::endl;
    std::cin >> meniu;

    while(meniu < 1 || meniu > 4){
        std::cout << "Ivedete neteisinga skaiciu, veskite is naujo: " << std::endl;
        std::cin >> meniu;
    }


    while(meniu == 1 || meniu == 2 || meniu == 3){

        if(meniu == 1){

            std::cout << "Iveskite studento varda: " << std::endl;
            std::cin >> studentas.vardas;
            std::cout << "Iveskite studento pavarde: " << std::endl;
            std::cin >> studentas.pavarde;
        
            std::cout << "Iveskite pazymiu kieki" << std::endl;
            std::cin >> studentas.pKiekis;
        
            while(studentas.pKiekis <= 0){
                std::cout << "Pazymiu kiekis negali buti 0 arba neigiamas, iveskite teigiama skaiciu: " << std::endl;
                std::cin >> studentas.pKiekis;
            }

            std::cout << "Iveskite pazymius: " << std::endl;
    
            for(int i = 0; i < studentas.pKiekis; i++){
                int pazymys = 0;
                std::cout << "Pazymys " << i + 1 << ". ";
                std::cin >> pazymys;
                studentas.pazymiai.push_back(pazymys);
            }

            //vidurkis

            std::cout << "Iveskite egzamino pazymi: " << std::endl;
            std::cin >> studentas.egzaminoRezultatas;

            for(int i = 0; i < studentas.pKiekis; i++){
                suma += studentas.pazymiai[i];
            }
        
            if(suma == 0){
                vidurkis = 0;
            }
            else{
                vidurkis = suma/studentas.pKiekis;
            }

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
        
            //mediana
        
            float mediana = 0;
        
            if(studentas.pKiekis % 2 == 0){
                mediana = (studentas.pazymiai[studentas.pKiekis/2 - 1] + studentas.pazymiai[studentas.pKiekis/2])/2;
            }
            else{
                mediana = studentas.pazymiai[(studentas.pKiekis+1)/2 - 1];
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

        }
        else if(meniu == 2){
            std::cout << "Iveskite studento varda: " << std::endl;
            std::cin >> studentas.vardas;
            std::cout << "Iveskite studento pavarde: " << std::endl;
            std::cin >> studentas.pavarde;
        
            std::cout << "Iveskite pazymiu kieki" << std::endl;
            std::cin >> studentas.pKiekis;
        
            while(studentas.pKiekis <= 0){
                std::cout << "Pazymiu kiekis negali buti 0 arba neigiamas, iveskite teigiama skaiciu: " << std::endl;
                std::cin >> studentas.pKiekis;
            }

            srand(time(0));

            for(int i = 0; i < studentas.pKiekis; i++){
                float randomPazymys = rand()%11;
                studentas.pazymiai.push_back(randomPazymys);
            }
    
            studentas.egzaminoRezultatas = rand()%11;

            //mediana
        
            float mediana = 0;
        
            if(studentas.pKiekis % 2 == 0){
                mediana = (studentas.pazymiai[studentas.pKiekis/2 - 1] + studentas.pazymiai[studentas.pKiekis/2])/2;
            }
            else{
                            mediana = studentas.pazymiai[(studentas.pKiekis+1)/2 - 1];
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
        }
        else{
            
        }


    }



    // std::cout << "Iveskite studento varda: " << std::endl;
    // std::cin >> studentas.vardas;
    // std::cout << "Iveskite studento pavarde: " << std::endl;
    // std::cin >> studentas.pavarde;

    // std::cout << "Iveskite pazymiu kieki" << std::endl;
    // std::cin >> studentas.pKiekis;

    // while(studentas.pKiekis <= 0){
    //     std::cout << "Pazymiu kiekis negali buti 0 arba neigiamas, iveskite teigiama skaiciu: " << std::endl;
    //     std::cin >> studentas.pKiekis;
    // }

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
            studentas.pazymiai.push_back(randomPazymys);
        }

        studentas.egzaminoRezultatas = rand()%11;

    }
    // else{
    
    //     std::cout << "Iveskite pazymius: " << std::endl;
    
    //     for(int i = 0; i < studentas.pKiekis; i++){
    //         int pazymys = 0;
    //         std::cout << "Pazymys " << i + 1 << ". ";
    //         std::cin >> pazymys;
    //         studentas.pazymiai.push_back(pazymys);
    //     }
    
    //     std::cout << "Iveskite egzamino pazymi: " << std::endl;
    //     std::cin >> studentas.egzaminoRezultatas;

    // }


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
    
    //sorting

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

    //mediana

    float mediana = 0;

    if(studentas.pKiekis % 2 == 0){
        mediana = (studentas.pazymiai[studentas.pKiekis/2 - 1] + studentas.pazymiai[studentas.pKiekis/2])/2;
    }
    else{
        mediana = studentas.pazymiai[(studentas.pKiekis+1)/2 - 1];
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