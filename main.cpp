#include "header.h"

int main(){

    srand(time(0));
    std::vector<std::string>vardai = {"Jonas", "Paulius", "Matas", "Tomas", "Vardenis"};
    std::vector<std::string>pavardes = {"Jonavicius", "Pauliavicius", "Matavicius", "Tomavicius", "Pavardenis"};

    std::vector<studentas> grupe;

    std::cout << "\nPasirinkite generavimo buda:\n " << 
                "1 - ranka\n " << 
                "2 - generuoti pazymius\n " << 
                "3 - generuoti pazymius studentu vardus, pavardes\n " << 
                "4 - nuskaityti duomenis is failo\n " << 
                "5 - baigti darba" << std::endl;

    std::cin >> meniu;

    while(meniu < 1 || meniu > 5){
        std::cout << "Ivedete neteisinga skaiciu, veskite is naujo: " << std::endl;
        std::cin >> meniu;
    }

    std::cout << "Ar norite skaiciuoti galutini ivertinima naudojant pazymiu vidurki ar mediana(v/m)?" << std::endl;
    std::cin >> galutinioBudas;

    while(galutinioBudas != 'm' && galutinioBudas != 'v'){
        std::cout << "Ivedete bloga simboli, iveskite is naujo: " << std::endl;
        std::cin >> galutinioBudas;
    }

    std::cout << "Ar norite duomenis matyti terminale ar faile? (t/f)" << std::endl;
    std::cin >> spausBudas;

    std::cout << "Ar noresite studentus rusiuoti pagal pavarde ar pagal galutini pazymi? (p/g)" << std::endl;
    std::cin >> rusiavimoBudas;

    std::cout << "Iveskite pazymiu kieki" << std::endl;
    std::cin >> pKiekis;

    while(pKiekis <= 0){
        std::cout << "Pazymiu kiekis negali buti 0 arba neigiamas, iveskite teigiama skaiciu: " << std::endl;
        std::cin >> pKiekis;
    }


    while(meniu >= 1 && meniu <= 5){

        studentas studentas;
        studentas.pazymiai.clear();

        if(meniu == 1){
            std::cout << "Iveskite studento varda: " << std::endl;
            std::cin >> studentas.vardas;
            std::cout << "Iveskite studento pavarde: " << std::endl;
            std::cin >> studentas.pavarde;

            std::cout << "Iveskite pazymius: " << std::endl;
    
            for(int i = 0; i < pKiekis; i++){
                int pazymys = 0;
                std::cout << "Pazymys " << i + 1 << ". ";
                std::cin >> pazymys;
                studentas.pazymiai.push_back(pazymys);
            }
        
            std::cout << "Iveskite egzamino pazymi: " << std::endl;
            std::cin >> studentas.egzaminoRezultatas;

            vidurkis = skaiciuotiVid(studentas.pazymiai);
            std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());
            mediana = skaiciuotiMed(pKiekis, studentas.pazymiai);

            studentas.galutinisV = vidurkis*0.4 + studentas.egzaminoRezultatas*0.6;
            studentas.galutinisM = mediana*0.4 + studentas.egzaminoRezultatas*0.6;

            grupe.push_back(studentas);


        }
        else if(meniu == 2){
            std::cout << "Iveskite studento varda: " << std::endl;
            std::cin >> studentas.vardas;
            std::cout << "Iveskite studento pavarde: " << std::endl;
            std::cin >> studentas.pavarde;

            while(studentas.pazymiai.size() <= 0){
                std::cout << "Pazymiu kiekis negali buti 0 arba neigiamas, iveskite teigiama skaiciu: " << std::endl;
                std::cin >> pKiekis;
            }

            for(int i = 0; i < pKiekis; i++){
                float randomPazymys = rand()%11;
                studentas.pazymiai.push_back(randomPazymys);
            }
    
            studentas.egzaminoRezultatas = rand()%11;

            vidurkis = skaiciuotiVid(studentas.pazymiai);
            std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());
            mediana = skaiciuotiMed(pKiekis, studentas.pazymiai);

            studentas.galutinisV = vidurkis*0.4 + studentas.egzaminoRezultatas*0.6;
            studentas.galutinisM = mediana*0.4 + studentas.egzaminoRezultatas*0.6;

            grupe.push_back(studentas);

        }
        else if(meniu == 3){
            int x = rand()%vardai.size();

            studentas.pavarde = pavardes[x];
            studentas.vardas = vardai[x];

            for(int i = 0; i < pKiekis; i++){
                float randomPazymys = rand()%11;
                studentas.pazymiai.push_back(randomPazymys);
            }
    
            studentas.egzaminoRezultatas = rand()%11;

            vidurkis = skaiciuotiVid(studentas.pazymiai);
            std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());
            mediana = skaiciuotiMed(pKiekis, studentas.pazymiai);

            studentas.galutinisV = vidurkis*0.4 + studentas.egzaminoRezultatas*0.6;
            studentas.galutinisM = mediana*0.4 + studentas.egzaminoRezultatas*0.6;

            grupe.push_back(studentas);
        
        }
        else if(meniu == 4){

            auto pradzia = std::chrono::steady_clock::now();

            std::ifstream inFile("studentai10000.txt");
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

                studentas.pazymiai.resize(pKiekis);

                for(int i = 0; i < pKiekis; i++){
                    token >> studentas.pazymiai[i];
                }

                token >> studentas.egzaminoRezultatas;

                vidurkis = skaiciuotiVid(studentas.pazymiai);
                std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());
                mediana = skaiciuotiMed(pKiekis, studentas.pazymiai);

                studentas.galutinisV = vidurkis * 0.4 + studentas.egzaminoRezultatas * 0.6;
                studentas.galutinisM = mediana * 0.4 + studentas.egzaminoRezultatas * 0.6;

                grupe.push_back(studentas);

            }

            auto pabaiga = std::chrono::steady_clock::now();
            std::chrono::duration<double> trukme = pabaiga - pradzia;
            std::cout << "Uztruko " << trukme.count() << " sekundziu." << std::endl;

        }
        else{
            std::cout << "Isejote is programos." << std::endl;
            break;
        }
        
        while(spausBudas != 't' && spausBudas != 'f'){
            std::cout << "Pasirinkote bloga simboli, veskite is naujo: " << std::endl;
            std::cin >> spausBudas;
        }

        if(spausBudas == 't'){

            rusiuotiOutput(grupe, rusiavimoBudas, galutinioBudas);
            spausdinimasTerminale(grupe, galutinioBudas);

        }
        else{

            rusiuotiOutput(grupe, rusiavimoBudas, galutinioBudas);
            spausdinimasFaile(galutinioBudas, grupe);

        }

        std::cout << "Pasirinkite kita veiksma (1-5): " << std::endl;
        std::cin >> meniu;

        while(meniu < 1 || meniu > 4){
            std::cout << "Ivedete neteisinga skaiciu, veskite is naujo: " << std::endl;
            std::cin >> meniu;
        }

    }

    return 0;
}
