#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "funcC.h"
#include <string>

struct studentas {
    float* pazymiai;
    std::string vardas;
    std::string pavarde;
    float egzaminoRezultatas;
    int pKiekis;
    char pasirinkimas;
    float galutinisV;
    float galutinisM;
};

int main(){
    
    srand(time(0));
    std::string vardai[] = {"Vardenis", "Vardenis_1", "Vardenis_2", "Vardenis_3", "Vardenis_4"};
    std::string pavardes[] = {"Pavardenis", "Pavardenis_1", "Pavardenis_2", "Pavardenis_3", "Pavardenis_4"};
    int vardaiSize = sizeof(vardai) / sizeof(vardai[0]);
 
    int studentuMaxKiekis;
    std::cout << "Iveskite maksimalu studentu kieki: " << std::endl;
    std::cin >> studentuMaxKiekis;

    while(studentuMaxKiekis <=0){
        std::cout << "Studentu kiekis turi buti teigiamas, veskite is naujo: " << std::endl;
        std::cin >> studentuMaxKiekis;
    }

    studentas* grupe = new studentas[studentuMaxKiekis];

    int studentuCount = 0;
    float vidurkis;
    float mediana;
    int meniu;

    std::cout << "\nPasirinkite generavimo buda:\n 1 - ranka\n 2 - generuoti pazymius\n 3 - generuoti pazymius studentu vardus, pavardes\n 4 - baigti darba" << std::endl;
    std::cin >> meniu;

    while(meniu < 1 || meniu > 4){
        std::cout << "Ivedete neteisinga skaiciu, veskite is naujo: " << std::endl;
        std::cin >> meniu;
    }
    
    while(meniu == 1 || meniu == 2 || meniu == 3 || meniu == 4){

        if(studentuCount == studentuMaxKiekis){
            std::cout << "Pasiektas maksimalus studentu skaicius." << std::endl;
            break;
        }

        studentas studentas;
        studentas.pazymiai = nullptr;

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

            studentas.pazymiai = new float[studentas.pKiekis];

            std::cout << "Iveskite pazymius: " << std::endl;
            for(int i = 0; i < studentas.pKiekis; i++){

                int pazymys = 0;
                std::cout << "Pazymys " << i + 1 << ". ";
                std::cin >> pazymys;

                studentas.pazymiai[i] = pazymys;
            }

            std::cout << "Iveskite egzamino pazymi: " << std::endl;
            std::cin >> studentas.egzaminoRezultatas;

            vidurkis = skaiciuotiVid(studentas.pKiekis, studentas.pazymiai);
            rikiavimas(studentas.pKiekis, studentas.pazymiai);
            mediana = skaiciuotiMed(studentas.pKiekis, studentas.pazymiai);

            studentas.galutinisV = vidurkis*0.4 + studentas.egzaminoRezultatas*0.6;
            studentas.galutinisM = mediana*0.4 + studentas.egzaminoRezultatas*0.6;

            std::cout << "Ar norite skaiciuoti galutini ivertinima naudojant pazymiu vidurki ar mediana(v/m)?" << std::endl;
            std::cin >> studentas.pasirinkimas;

            while(studentas.pasirinkimas != 'm' && studentas.pasirinkimas != 'v'){
                std::cout << "Ivedete bloga simboli, iveskite is naujo: " << std::endl;
                std::cin >> studentas.pasirinkimas;
            }

            grupe[studentuCount] = studentas;
            studentuCount++;
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
            
            studentas.pazymiai = new float[studentas.pKiekis];

            for(int i = 0; i < studentas.pKiekis; i++){

                float randomPazymys = rand()%11;
                studentas.pazymiai[i] = randomPazymys;

            }

            studentas.egzaminoRezultatas = rand()%11;

            vidurkis = skaiciuotiVid(studentas.pKiekis, studentas.pazymiai);
            rikiavimas(studentas.pKiekis, studentas.pazymiai);
            mediana = skaiciuotiMed(studentas.pKiekis, studentas.pazymiai);

            studentas.galutinisV = vidurkis*0.4 + studentas.egzaminoRezultatas*0.6;
            studentas.galutinisM = mediana*0.4 + studentas.egzaminoRezultatas*0.6;

            char pasirinkimas;

            std::cout << "Ar norite skaiciuoti galutini ivertinima naudojant pazymiu vidurki ar mediana(v/m)?" << std::endl;
            std::cin >> pasirinkimas;

            while(pasirinkimas != 'm' && pasirinkimas != 'v'){
                std::cout << "Ivedete bloga simboli, iveskite is naujo: " << std::endl;
                std::cin >> pasirinkimas;
            }
            
            studentas.pasirinkimas = pasirinkimas;
            grupe[studentuCount] = studentas;
            studentuCount++;

        }
        else if(meniu == 3){

            int x = rand()%vardaiSize;

            studentas.vardas = vardai[x];
            studentas.pavarde = pavardes[x];

            std::cout << "Iveskite pazymiu kieki" << std::endl;
            std::cin >> studentas.pKiekis;

            studentas.pazymiai = new float[studentas.pKiekis];

            for(int i = 0; i < studentas.pKiekis; i++){

                float randomPazymys = rand()%11;
                studentas.pazymiai[i] = randomPazymys;
            }

            studentas.egzaminoRezultatas = rand()%11;

            vidurkis = skaiciuotiVid(studentas.pKiekis, studentas.pazymiai);
            rikiavimas(studentas.pKiekis, studentas.pazymiai);
            mediana = skaiciuotiMed(studentas.pKiekis, studentas.pazymiai);

            studentas.galutinisV = vidurkis*0.4 + studentas.egzaminoRezultatas*0.6;
            studentas.galutinisM = mediana*0.4 + studentas.egzaminoRezultatas*0.6;

            char pasirinkimas;

            std::cout << "Ar norite skaiciuoti galutini ivertinima naudojant pazymiu vidurki ar mediana(v/m)?" << std::endl;
            std::cin >> pasirinkimas;

            while(pasirinkimas != 'm' && pasirinkimas != 'v'){

                std::cout << "Ivedete bloga simboli, iveskite is naujo: " << std::endl;
                std::cin >> pasirinkimas;

            }

            studentas.pasirinkimas = pasirinkimas;
            grupe[studentuCount] = studentas;
            studentuCount++;
        }
        else{
            break;
        }

        std::cout << "Pavarde" << std::setw(15) << "Vardas" << std::setw(15) << "Galutinis(vid.)/Galutinis(med.)" << std::endl;
        std::cout << "-------------------------------------" << std::endl;

        for (int i = 0; i < studentuCount; i++){

            if(grupe[i].pasirinkimas == 'v'){
                std::cout << grupe[i].pavarde << std::setw(15) << grupe[i].vardas << std::setw(15) << std::fixed << std::setprecision(2) << grupe[i].galutinisV << std::endl;
            }
            else{
                std::cout << grupe[i].pavarde << std::setw(15) << grupe[i].vardas << std::setw(15) << std::fixed << std::setprecision(2) << grupe[i].galutinisM << std::endl;
            }
        }

        std::cout << "Pasirinkite kita veiksma (1-4): " << std::endl;
        std::cin >> meniu;

        while(meniu < 1 || meniu > 4){
            std::cout << "Ivedete neteisinga skaiciu, veskite is naujo: " << std::endl;
            std::cin >> meniu;
        }
    }

    for (int i = 0; i < studentuCount; i++){
        delete [] grupe[i].pazymiai;
    }

    delete [] grupe;
    
    return 0;
}
