#include "header.h"


struct studentas{
    std::vector<float>pazymiai;
    std::string vardas;
    std::string pavarde;
    float egzaminoRezultatas;
    int pKiekis;
    float galutinisV;
    float galutinisM;
};

int main(){

    srand(time(0));
    std::vector<std::string>vardai = {"Jonas", "Paulius", "Matas", "Tomas", "Vardenis"};
    std::vector<std::string>pavardes = {"Jonavicius", "Pauliavicius", "Matavicius", "Tomavicius", "Pavardenis"};

    std::vector<studentas> grupe;

    float vidurkis;
    float suma = 0;
    int meniu;
    float mediana;
    char pasirinkimas;

    std::cout << "\nPasirinkite generavimo buda:\n 1 - ranka\n 2 - generuoti pazymius\n 3 - generuoti pazymius studentu vardus, pavardes\n 4 - nuskaityti duomenis is failo\n 5 - baigti darba" << std::endl;
    std::cin >> meniu;

    while(meniu < 1 || meniu > 5){
        std::cout << "Ivedete neteisinga skaiciu, veskite is naujo: " << std::endl;
        std::cin >> meniu;
    }

    std::cout << "Ar norite skaiciuoti galutini ivertinima naudojant pazymiu vidurki ar mediana(v/m)?" << std::endl;
    std::cin >> pasirinkimas;

    while(pasirinkimas != 'm' && pasirinkimas != 'v'){
        std::cout << "Ivedete bloga simboli, iveskite is naujo: " << std::endl;
        std::cin >> pasirinkimas;
    }



    while(meniu == 1 || meniu == 2 || meniu == 3 || meniu == 4 || meniu == 5){

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
            std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());
            mediana = skaiciuotiMed(studentas.pKiekis, studentas.pazymiai);

            studentas.galutinisV = vidurkis*0.4 + studentas.egzaminoRezultatas*0.6;
            studentas.galutinisM = mediana*0.4 + studentas.egzaminoRezultatas*0.6;

            grupe.push_back(studentas);

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
            std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());
            mediana = skaiciuotiMed(studentas.pKiekis, studentas.pazymiai);

            studentas.galutinisV = vidurkis*0.4 + studentas.egzaminoRezultatas*0.6;
            studentas.galutinisM = mediana*0.4 + studentas.egzaminoRezultatas*0.6;

            grupe.push_back(studentas);

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
            std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());;
            mediana = skaiciuotiMed(studentas.pKiekis, studentas.pazymiai);

            studentas.galutinisV = vidurkis*0.4 + studentas.egzaminoRezultatas*0.6;
            studentas.galutinisM = mediana*0.4 + studentas.egzaminoRezultatas*0.6;

            grupe.push_back(studentas);
        
        }
        else if(meniu == 4){

            std::ifstream inFile("kursiokai.txt");
            if(!inFile.is_open()){
                std::cout << "Nepavyko atidaryti failo." << std::endl;
                std::cout << "Pasirinkite kita veiksma: " << std::endl;
                std::cin >> meniu;
                continue;
            }

            std::string topLine;
            std::getline(inFile, topLine);

            while(inFile){
                std::string line;

                if(!std::getline(inFile, line)){
                    break;
                }
                
                if(line.empty()){
                    continue;
                }

                std::istringstream token(line);
                
                token >> studentas.vardas >> studentas.pavarde;
                float nd = 5;

                studentas.pKiekis = nd;
                studentas.pazymiai.resize(nd);

                for(int i = 0; i < nd; i++){
                    token >> studentas.pazymiai[i];
                }

                token >> studentas.egzaminoRezultatas;

                vidurkis = skaiciuotiVid(nd, studentas.pazymiai);
                std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());
                mediana = skaiciuotiMed(nd, studentas.pazymiai);

                studentas.galutinisV = vidurkis * 0.4 + studentas.egzaminoRezultatas * 0.6;
                studentas.galutinisM = mediana * 0.4 + studentas.egzaminoRezultatas * 0.6;

                grupe.push_back(studentas);

            }

        }
        else{
            break;
        }

        std::cout << "Pavarde" << std::setw(20) << "Vardas" << std::setw(40) << "Galutinis(vid.)/Galutinis(med.)" << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;

        for(int i = 0; i < grupe.size(); i++){
                
            if(pasirinkimas == 'v'){
                std::cout << grupe[i].pavarde << std::setw(17) << grupe[i].vardas << std::setw(15) << std::fixed << std::setprecision(2) << grupe[i].galutinisV << std::endl;

            }
            else{
                std::cout << grupe[i].pavarde << std::setw(17) << grupe[i].vardas << std::setw(15)  << std::fixed << std::setprecision(2) << grupe[i].galutinisM << std::endl;
            }
        }

        std::cout << "Pasirinkite kita veiksma (1-4): " << std::endl;
        std::cin >> meniu;

        while(meniu < 1 || meniu > 4){
            std::cout << "Ivedete neteisinga skaiciu, veskite is naujo: " << std::endl;
            std::cin >> meniu;
        }

    }

    return 0;
}
