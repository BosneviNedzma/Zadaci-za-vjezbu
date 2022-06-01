
#include <iostream>
#include <vector>
#include <fstream>

#include <string>

using namespace std;


void Adi_Zu()
{
	ifstream file("ulaz.txt");

	if (file.is_open())
	{
		int velicina;

		file >> velicina;		// pretpostavljam da se u fajlu nalazi samo jedan broj i onda korisnik kroz konzolu unosi brojeve dalje
		if (velicina < 1)
		{
			cout << "\n\tInvalidna velicina (manja od 1)";
			return;
		}
		cout << "\n\tNapravljen niz velicine " << velicina;

		float ukupno = 0;
		float* niz = new float[velicina];

		for (int i = 0; i < velicina; i++)
		{
			cout << "\n\tUnesite " << i + 1 << ". broj: ";
			cin >> niz[i];
			ukupno += niz[i];
		}
		velicina++;
		float* noviNiz = new float[velicina];

		for (int i = 0; i < velicina - 1; i++)
		{
			noviNiz[i] = niz[i];
		}
		delete[] niz;

		noviNiz[velicina - 1] = ukupno / velicina;

		ofstream file("Izlaz.txt");

		for (int i = 0; i < velicina; i++)
		{
			file << noviNiz[i] << " ";
		}
		file.close();
	}
	else
		cout << "\n\n\t\"ulaz.txt\" fajl nije pronadjen!";
	    cout << "\n\n\n\n";
}
