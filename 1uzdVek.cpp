#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "func.h"

struct studentas{
    std::vector<float>pazymiai;
    std::string vardas;
    std::string pavarde;
    float egzaminoRezultatas;
    int pKiekis;
};

int main(){

    srand(time(0));
    std::vector<std::string>vardai = {"Jonas", "Paulius", "Matas", "Tomas", "Vardenis"};
    std::vector<std::string>pavardes = {"Jonavicius", "Pauliavicius", "Matavicius", "Tomavicius", "Pavardenis"};

    std::vector<studentas> grupe;

    float galutinisV;
    float galutinisM;
    float vidurkis;
    float suma = 0;
    int meniu;
    float mediana;
    
    std::cout << "\nPasirinkite generavimo buda:\n 1 - ranka\n 2 - generuoti pazymius\n 3 - generuoti pazymius studentu vardus, pavardes\n 4 - baigti darba" << std::endl;
    std::cin >> meniu;

    while(meniu < 1 || meniu > 4){
        std::cout << "Ivedete neteisinga skaiciu, veskite is naujo: " << std::endl;
        std::cin >> meniu;
    }

    while(meniu == 1 || meniu == 2 || meniu == 3 || meniu == 4){

        studentas studentas;
        studentas.pazymiai.clear();

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
        
            std::cout << "Iveskite egzamino pazymi: " << std::endl;
            std::cin >> studentas.egzaminoRezultatas;

            vidurkis = skaiciuotiVid(studentas.pKiekis, studentas.pazymiai);
            rikiavimas(studentas.pKiekis, studentas.pazymiai);
            mediana = skaiciuotiMed(studentas.pKiekis, studentas.pazymiai);

            galutinisV = vidurkis*0.4 + studentas.egzaminoRezultatas*0.6;
            galutinisM = mediana*0.4 + studentas.egzaminoRezultatas*0.6;

            char pasirinkimas;
            std::cout << "Ar norite skaiciuoti galutini ivertinima naudojant pazymiu vidurki ar mediana(v/m)?" << std::endl;
            std::cin >> pasirinkimas;

            while(pasirinkimas != 'm' && pasirinkimas != 'v'){
                std::cout << "Ivedete bloga simboli, iveskite is naujo: " << std::endl;
                std::cin >> pasirinkimas;
            }
            
            spausdinimas(pasirinkimas, studentas.pavarde, studentas.vardas, galutinisV, galutinisM);

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

            for(int i = 0; i < studentas.pKiekis; i++){
                float randomPazymys = rand()%11;
                studentas.pazymiai.push_back(randomPazymys);
            }
    
            studentas.egzaminoRezultatas = rand()%11;

            vidurkis = skaiciuotiVid(studentas.pKiekis, studentas.pazymiai);
            rikiavimas(studentas.pKiekis, studentas.pazymiai);
            mediana = skaiciuotiMed(studentas.pKiekis, studentas.pazymiai);

            galutinisV = vidurkis*0.4 + studentas.egzaminoRezultatas*0.6;
            galutinisM = mediana*0.4 + studentas.egzaminoRezultatas*0.6;

            char pasirinkimas;
            std::cout << "Ar norite skaiciuoti galutini ivertinima naudojant pazymiu vidurki ar mediana(v/m)?" << std::endl;
            std::cin >> pasirinkimas;

            while(pasirinkimas != 'm' && pasirinkimas != 'v'){
                std::cout << "Ivedete bloga simboli, iveskite is naujo: " << std::endl;
                std::cin >> pasirinkimas;
            }
            
            spausdinimas(pasirinkimas, studentas.pavarde, studentas.vardas, galutinisV, galutinisM);

        }
        else if(meniu == 3){
            int x = rand()%vardai.size();

            studentas.pavarde = pavardes[x];
            studentas.vardas = vardai[x];

            std::cout << "Iveskite pazymiu kieki" << std::endl;
            std::cin >> studentas.pKiekis;

            for(int i = 0; i < studentas.pKiekis; i++){
                float randomPazymys = rand()%11;
                studentas.pazymiai.push_back(randomPazymys);
            }
    
            studentas.egzaminoRezultatas = rand()%11;

            vidurkis = skaiciuotiVid(studentas.pKiekis, studentas.pazymiai);
            rikiavimas(studentas.pKiekis, studentas.pazymiai);
            mediana = skaiciuotiMed(studentas.pKiekis, studentas.pazymiai);

            galutinisV = vidurkis*0.4 + studentas.egzaminoRezultatas*0.6;
            galutinisM = mediana*0.4 + studentas.egzaminoRezultatas*0.6;

            char pasirinkimas;
            std::cout << "Ar norite skaiciuoti galutini ivertinima naudojant pazymiu vidurki ar mediana(v/m)?" << std::endl;
            std::cin >> pasirinkimas;

            while(pasirinkimas != 'm' && pasirinkimas != 'v'){
                std::cout << "Ivedete bloga simboli, iveskite is naujo: " << std::endl;
                std::cin >> pasirinkimas;
            }
            
            spausdinimas(pasirinkimas, studentas.pavarde, studentas.vardas, galutinisV, galutinisM);

        }
        else{
            


        }

        grupe.push_back(studentas);

        std::cout << "Pasirinkite kita veiksma (1-4): " << std::endl;
        std::cin >> meniu;


    }


    return 0;
}
