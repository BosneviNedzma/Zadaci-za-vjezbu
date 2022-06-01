#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
using namespace std;

int main() {
	ofstream unos("test.txt", ios::app);
	ifstream file("test.txt");

	if(file) {
		string recenica;
		while (getline(file, recenica)) {
			cout<<endl;
			if (sqrt(recenica.size()) != floor(sqrt(recenica.size()))) {		// provjera kvadrata
				cout << "GRESKA";
				continue;
			}

			int velicina = sqrt(recenica.size());
			int brojac = 0;
			vector <vector <char>> matrica;		// vektor vektora charova, tj matrica slova
			for (int i = 0; i < velicina; i++) {
				vector <char> temp;				// slova spasavamo u vektor charova temp
				for (int j = 0; j < velicina; j++) {
					temp.push_back(recenica[brojac]);
					brojac++;
				}
				matrica.push_back(temp);				// taj temp stavljamo u matricu
			}
			for (int i = 0; i < velicina; i++) {
				for (int j = 0; j < velicina; j++) {
					cout << matrica[j][i];		// ispisujemo slova zamijenjena po dijagonali
				}
			}
		}

		file.close();
	}
	else
		cout << "Nije moguce otvoriti datoteku.\n";
}
