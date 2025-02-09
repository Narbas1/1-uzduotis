float skaiciuotiVid(float pKiekis, float suma, std::vector<float>&pazymiai){
    float vidurkis;
    suma = 0;
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

void rikiavimas(float pKiekis, std::vector<float>&pazymiai){

    float temp;

    for(int i = 0; i < pKiekis - 1; i++){
        for(int j = 0; j < pKiekis - 1; j++){
            if(pazymiai[j] > pazymiai[j + 1]){
                temp = pazymiai[j];
                pazymiai[j] = pazymiai[j + 1];
                pazymiai[j + 1] = temp;
            }
        }
    }
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