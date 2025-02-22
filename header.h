#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

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