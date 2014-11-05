/*		Valtteri Louhelainen

Muuta harjoituksen 24 toiminnallisuutta niin, etta
varaat henkilötiedoille tilan dynaamisesti (max 10 hlo).
Muuta valikko alla olevan esimerkin mukaiseksi ja toteuta valikossa
näkyvät toiminnot.

VALIKKO
0 Lopeta
1 Lisaa henkilo
2 Nayta henkilo
3 Nayta kaikki henkilot
4 Poista henkilon tiedot*/

#include <iostream>
#include <fstream>
using namespace std;

struct DATA
{
	char nimi[15];
	float matka;
	int hattu;
	DATA *seuraava;
};
DATA rekisteri[10];
bool jatka = true;
int valinta;
int valinta2;
int valinta3;
int lkm = 0;
DATA *alku = NULL;
DATA *kohta, *uusi;



int Valikko(void)
{
	int temp;
	cout << "VALIKKO\n"
		<< "0 Lopeta\n"
		<< "1 Lis\x84\x84 henkil\x94\n"
		<< "2 N\x84yt\x84 yksi henkil\x94\n"
		<< "3 N\x84yt\x84 kaikki henkil\x94t\n"
		<< "4 Poista henkil\x94n tiedot\n";
	cin >> temp;
	return temp;
}

void LisaaHenkilo()
{
	if (lkm >= 10)
		cout << "\nRekisteri t\x84ynn\x84, max 10\n\n";
	else
	{
		uusi = new DATA;
		if (uusi)
		{
			cout << "\nEtunimi: ";
			cin >> uusi->nimi;
			cout << "Koulumatka: ";
			cin >> uusi->matka;
			cout << "Hatun koko: ";
			cin >> uusi->hattu;
			lkm++;
			cout << "\n";

			uusi->seuraava = NULL;
			if (!alku)
				alku = uusi;
			else
			{
				kohta = alku;
				while (kohta->seuraava)
					kohta = kohta->seuraava;
				kohta->seuraava = uusi;
			}
		}
		else
			cout << "Tilanvaraus ep\x94onnistui.";
	}
}

int TulostaYksiHenkilo()
{
	cout << "Anna henkil\x94n numero: ";
	cin >> valinta2;
	if (lkm < valinta2)
	{
		cout << "Numero liian suuri.";
		return 0;
	}
	printf_s("\n/===============|=====|==========\\\n|    Etunimi    |Matka|Hatun koko|\n|---------------|-----|----------|\n");
	kohta = alku;
	for (int n = valinta2 - 1; n > 0; n--)
		kohta = kohta->seuraava;
	printf_s("|%-15s|%5.1f|%10i|\n", kohta->nimi, kohta->matka, kohta->hattu);
	printf_s("\\===============|=====|==========/\n\n");
}

void TulostaKaikkiHenkilot()
{
	printf_s("\n/===============|=====|==========\\\n|    Etunimi    |Matka|Hatun koko|\n|---------------|-----|----------|\n");
	kohta = alku;
	while (kohta)
	{
		printf_s("|%-15s|%5.1f|%10i|\n", kohta->nimi, kohta->matka, kohta->hattu);
		kohta = kohta->seuraava;
	}
	printf_s("\\===============|=====|==========/\n\n");
}

int PoistaTiedot()
{
	cout << "Anna henkil\x94n numero: ";
	cin >> valinta2;
	if (lkm < valinta2)
	{
		cout << "Numero liian suuri.";
		return 0;
	}
	kohta = alku;
	for (int n = valinta2 - 1; n > 0; n--)
		kohta = kohta->seuraava;
	DATA *pois = kohta;
	printf_s("\n/===============|=====|==========\\\n|    Etunimi    |Matka|Hatun koko|\n|---------------|-----|----------|\n");
	printf_s("|%-15s|%5.1f|%10i|\n", pois->nimi, pois->matka, pois->hattu);
	printf_s("\\===============|=====|==========/\n\n");
	cout << "Haluatko poistaa kyseisen henkil\x84n tiedot? 1=Kyll\x84 0=Ei\n";
	cin >> valinta3;
	if (valinta3)
	{
		if (pois == alku)
			alku = pois->seuraava;
		else
		{
			kohta = alku;
			for (int n = valinta2 - 2; n > 0; n--)
				kohta = kohta->seuraava;
			DATA *edellinen = kohta;
			edellinen->seuraava = pois->seuraava;
		}
		delete pois;
		lkm--;
		cout << "Henkil\x94n tiedot poistettu.\n\n";
	}
}

//----------MAIN----------//
void main()
{
	while (jatka)
	{
		valinta = Valikko();
		if (valinta == 0)
			jatka = false;
		if (valinta == 1)
			LisaaHenkilo();
		if (valinta == 2)
			TulostaYksiHenkilo();
		if (valinta == 3)
			TulostaKaikkiHenkilot();
		if (valinta == 4)
			PoistaTiedot();
	}
}