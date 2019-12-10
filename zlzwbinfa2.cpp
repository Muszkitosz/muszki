#include "std_lib_facilities.h"

struct elem			//elem típus létrehozása
{
	int adat;
	elem* bal; 		//rekurzív megadás
	elem* jobb;
};

void fa_beszur(elem* gyoker, elem*& aktualis, char bit);
int agakszama(elem* aktualis);
int szumaghossz(elem* aktualis, int hossz);
double szumatlagelteres(elem* aktualis, double agatlag, int hossz);
int magassag(elem* aktualis);

int main()
{	
	
	elem* gyoker = new elem;			 // előre lefoglaljuk a memóriát(elvileg)
	gyoker->bal = NULL;				 // nagy input esetén szükséges.
	gyoker->jobb = NULL;
	elem* aktualis = gyoker;
	vector<int>v;
	char bit;
	while (cin >> bit && (bit == '0' || bit == '1')) // csak 0,1 karaktereket fogad el, 								 // egyébként véget ér a program.
	{
		v.push_back(bit - 48); // átalakítjuk számmá, mivel karakterként olvassuk be. 
	}

	for (int i = 0; i < v.size(); i++)
	{
		fa_beszur(gyoker, aktualis, v[i]);  // létrehozzuk a fát
	}

	double agszam = agakszama(gyoker);
	cout << "Agak szama: " << agszam << '\n';

	double agszum = szumaghossz(gyoker, 0);
	double agatlag = agszum / agszam;
	cout << "Agak hosszanak atlaga: " << agatlag << '\n';

	double szum = szumatlagelteres(gyoker, agatlag, 0);
	double tapszoras = sqrt(szum / agszam);
	double korrszoras = sqrt(szum / (agszam - 1));
	cout << "Agak hosszanak tapasztalati szorasa: " << tapszoras << '\n';
	cout << "Agak hosszanak korrigalt tapasztalati szorasa: " << korrszoras << '\n';

	int famagassag = magassag(gyoker);
	cout << "Fa magassaga gyokerelemmel: " << famagassag << '\n';
	cout << "Fa magassaga gyokerelem nelkul: " << famagassag - 1 << '\n';
}

void fa_beszur(elem* gyoker, elem*& aktualis, char bit)
{
	if (bit == 0)
	{
		if (aktualis->bal == NULL)
		{
			elem* kovetkezo = new elem;
			aktualis->bal = kovetkezo;
			kovetkezo->adat = 0;
			kovetkezo->bal = NULL;
			kovetkezo->jobb = NULL;
			aktualis = gyoker;
		}
		else
		{
			aktualis = aktualis->bal;
		}
	}
	if (bit == 1)
	{
		if (aktualis->jobb == NULL)
		{
			elem* kovetkezo = new elem;
			aktualis->jobb = kovetkezo;
			kovetkezo->adat = 1;
			kovetkezo->bal = NULL;
			kovetkezo->jobb = NULL;
			aktualis = gyoker;
		}
		else
		{
			aktualis = aktualis->jobb;
		}
	}
}

int agakszama(elem* aktualis)
{
	int darab = 0; //kinullázzuk, mint mindig :) 
	if (aktualis->bal == NULL && aktualis->jobb == NULL)
		return 1;
	if (aktualis->bal != NULL)
		darab = darab + agakszama(aktualis->bal);
	if (aktualis->jobb != NULL)
		darab = darab + agakszama(aktualis->jobb);
	return darab;
} //addig hívja önmagát a függvény, amég a bal és jobb is NULL értéket vesz fel.(ebben az esetben +1) 

int szumaghossz(elem* aktualis, int hossz)
{
	int osszeg=0;
	if (aktualis->bal == NULL && aktualis->jobb == NULL)
		return hossz;
	if (aktualis->bal != NULL)
		osszeg = osszeg + szumaghossz(aktualis->bal, hossz + 1);
	if (aktualis->jobb != NULL)
		osszeg = osszeg + szumaghossz(aktualis->jobb, hossz + 1);
	return osszeg;
}

double szumatlagelteres(elem* aktualis, double agatlag, int hossz)  //szórás számításhoz szükséges
{
	double osszeg = 0;
	if (aktualis->bal == NULL && aktualis->jobb == NULL)
		return (hossz-agatlag)*(hossz-agatlag);
	if (aktualis->bal != NULL)
		osszeg = osszeg + szumatlagelteres(aktualis->bal, agatlag, hossz + 1);
	if (aktualis->jobb != NULL)
		osszeg = osszeg + szumatlagelteres(aktualis->jobb, agatlag, hossz + 1);
	return osszeg;
}

int magassag(elem* aktualis)
{
	int b=0, j=0;
	if (aktualis->bal == NULL && aktualis->jobb == NULL)
		return 1;
	if (aktualis->bal != NULL)
		b = magassag(aktualis->bal); //meghívjuk a bal oldalra a magasságot
	if (aktualis->jobb != NULL)
		j = magassag(aktualis->jobb); //meghívjuk a jobb oldalra a magasságot
	return max(b + 1, j + 1); //visszaküldjük a kettő közül a nagyobbat. A +1 azért szükséges, 					  //mert az aktuális elágazást is bele kell számolni.
				  //Ez a számolás a gyökérelemet is beleszámolja (gyökérelem 								nélküli magasság : -1)
}
