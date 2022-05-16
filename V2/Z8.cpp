#include <iostream>
#include <fstream>
using namespace std;

struct Student{
	char ime[20], prezime[20];
	int indeks, broj_ocjena;
	int ocjene[30];
};


int main(){
	
	int broj_studenata;
	Student neki_student;
	ifstream studenti("STUDENTI.DAT", ios::in | ios::binary);
	while(studenti.read((char*)&neki_student, sizeof(Student))){
		double prosjek=0;
		for(int i=0; i<neki_student.broj_ocjena; i++){
			prosjek += neki_student.ocjene[i];
		}
		prosjek /= neki_student.broj_ocjena;
		cout<<"Ime: "<<neki_student.ime<<" Prezime: "
		<<neki_student.prezime<<" "<<"Indeks: "
		<<neki_student.indeks<<" Prosjek: "<<prosjek<<endl;
	}
	
	
	
	
	
	
	
	
	return 0;
}
