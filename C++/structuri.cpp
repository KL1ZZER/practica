#include <iostream>

using namespace std;

struct Adresa
{
	int id_adresa;
	string nume_strada;
	int nr_casa;
	int nr_apartament;

};


struct Locuitor
{

	string nume;
	string prenume;
	int ziua_nastere;
	int luna_nastere;
	int an_nastere;
	bool gen; //0-Feminin 1-Masculin
	bool starea_civila; //0-necasatorit 1-necasatorit
	int studii; //0-gimnazial 1-liceal 2-superior
	int id_adresa;

};

