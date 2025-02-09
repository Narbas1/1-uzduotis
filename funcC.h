float skaiciuotiVid(int pKiekis, float* pazymiai) {
    float suma = 0;
    for(int i = 0; i < pKiekis; i++){
        suma += pazymiai[i];
    }
    return (pKiekis > 0) ? suma / pKiekis : 0;
}

void rikiavimas(int pKiekis, float* pazymiai) {
    for(int i = 0; i < pKiekis - 1; i++){
        for(int j = 0; j < pKiekis - 1; j++){
            if(pazymiai[j] > pazymiai[j+1]){
                float temp = pazymiai[j];
                pazymiai[j] = pazymiai[j+1];
                pazymiai[j+1] = temp;
            }
        }
    }
}

float skaiciuotiMed(int pKiekis, float* pazymiai) {
    if(pKiekis % 2 == 0)
        return (pazymiai[pKiekis/2 - 1] + pazymiai[pKiekis/2]) / 2;
    else
        return pazymiai[(pKiekis + 1) / 2 - 1];
}