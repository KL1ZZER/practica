#include <iostream>
#include <string>
#include "structuri.cpp"
#include <fstream>
#include <vector>

using namespace std;

vector<Locuitor> locuitori;
vector<Adresa> adrese;

fstream person("Person.txt");
fstream address("Address.txt");

// Citirea adreselor si persoanelor:
void citire_persoane() {
    Locuitor aux;
    while (person.peek() != EOF) {
        person >> aux.nume
            >> aux.prenume
            >> aux.ziua_nastere
            >> aux.luna_nastere
            >> aux.an_nastere
            >> aux.gen
            >> aux.stare_civila
            >> aux.studii
            >> aux.id_adresa;
        locuitori.push_back(aux);
    }
}

void citire_address() {
    Adresa aux;
    while (address.peek() != EOF) {
        address >> aux.id_adresa >> aux.nume_strada >> aux.nr_casa >> aux.nr_apartament;
        adrese.push_back(aux);
    }
}

// Afisarea adreselor si persoanelor:
void afisare_persoane() {
    for (int i = 0; i < locuitori.size(); i++) {
        cout << locuitori[i].nume << " "
            << locuitori[i].prenume << endl
            << locuitori[i].ziua_nastere << " "
            << locuitori[i].luna_nastere << " "
            << locuitori[i].an_nastere << endl
            << locuitori[i].gen << " "
            << locuitori[i].stare_civila << " "
            << locuitori[i].studii << " "
            << locuitori[i].id_adresa << endl;
    }
}

void afisare_address() {
    for (int i = 0; i < adrese.size(); i++) {
        cout << adrese[i].id_adresa << " "
            << adrese[i].nume_strada << " "
            << adrese[i].nr_casa << " "
            << adrese[i].nr_apartament << endl;
    }
}

// Inregistrarea adreselor si persoanelor:
void inregistrare_persoane() {
    Locuitor aux;
    cout << "Nume: ";
    cin >> aux.nume;
    cout << "Prenume: ";
    cin >> aux.prenume;
    cout << "Ziua nastere: ";
    cin >> aux.ziua_nastere;
    cout << "Luna nastere: ";
    cin >> aux.luna_nastere;
    cout << "Anul nasterii: ";
    cin >> aux.an_nastere;
    cout << "Genul: ";
    cin >> aux.gen;
    cout << "Starea civila: ";
    cin >> aux.stare_civila;
    cout << "Studiile: ";
    cin >> aux.studii;
    cout << "ID adresa: ";
    cin >> aux.id_adresa;

    locuitori.push_back(aux);
    person << aux.nume << " "
        << aux.prenume << endl
        << aux.ziua_nastere << " "
        << aux.luna_nastere << " "
        << aux.an_nastere << endl
        << aux.gen << " "
        << aux.stare_civila << " "
        << aux.studii << " "
        << aux.id_adresa << endl;
}

void inregistrare_address() {
    Adresa aux;
    cout << "ID adresa: ";
    cin >> aux.id_adresa;
    cout << "Nume strada: ";
    cin >> aux.nume_strada;
    cout << "Numarul casei: ";
    cin >> aux.nr_casa;
    cout << "Numarul apartamentului: ";
    cin >> aux.nr_apartament;

    adrese.push_back(aux);
    address << aux.id_adresa << " "
        << aux.nume_strada << " "
        << aux.nr_casa << " "
        << aux.nr_apartament << endl;
}

// Excluderea informației despre un locuitor si o adresa
void delete_locuitori(vector<Locuitor>& locuitori) {
    int idx;
    cout << "Acum vom sterge un locuitor" << endl;
    cout << "Indicati indexul locuitorului: ";
    cin >> idx;
    if (idx >= 0 && idx < locuitori.size()) {
        locuitori.erase(locuitori.begin() + idx);
        cout << "Ati sters locuitorul cu succes!" << endl << endl;
    }
    else {
        cout << "Index invalid!" << endl << endl;
    }
}

void delete_address(vector<Adresa>& adrese) {
    int id;
    cout << "Acum vom sterge o adresa" << endl;
    cout << "Indicati ID-ul adresei: ";
    cin >> id;
    auto it = remove_if(adrese.begin(), adrese.end(), [id](Adresa& addr) { return addr.id_adresa == id; });
    if (it != adrese.end()) {
        adrese.erase(it, adrese.end());
        cout << "Ati sters adresa cu succes!" << endl << endl;
    }
    else {
        cout << "Adresa nu a fost gasita!" << endl << endl;
    }
}

int main() {
    // Verificare deschidere fisiere
    if (!person.is_open() || !address.is_open()) {
        cerr << "Eroare la deschiderea fisierelor!" << endl;
        return 1;
    }

    citire_persoane();
    citire_address();

    // Exemple de apeluri ale functiilor de afisare
    afisare_persoane();
    afisare_address();

    // Inregistrare persoane si adrese
    inregistrare_persoane();
    inregistrare_address();

    // Exemple de apeluri ale functiilor de stergere
    delete_locuitori(locuitori);
    delete_address(adrese);

    // Inchiderea fisierelor
    person.close();
    address.close();

    return 0;
}
