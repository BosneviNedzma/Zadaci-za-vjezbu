#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

enum Stanje{NEAKTIVAN, AKTIVAN};
int br;

struct Autobus{
    string ID;
    char* vozac;
    char* prevoznik;
    int brojMjesta;
    string mjesta[100];
    Stanje stanje;

    void unosAutobusa(){
        do{
            string provjera;
            br = 0;
            cout << "Unesite ID autobusa: ";
            cin >> ID;
            ifstream autobus;
            autobus.open("autobusi.txt");
            while(!autobus.eof()){
                autobus >> provjera;
                if(provjera == ID){
                    br++;
                }
            }
            if(br!=0){
                cout << "Autobus sa tim ID-om vec postoji.\n";
                cout << "Molimo Vas da unesete novi ID.\n";
            }
            autobus.close();
        }while(br!=0);
        ofstream upis("autobusi.txt", ios::app);
        upis << "ID: " << ID << endl;
        cin.ignore();
        cout << "Unesite ime i prezime vozaca: ";
        char *vozac = new char[50];
        cin.getline(vozac,50);
        upis << "Vozac: " << vozac << endl;
        delete[] vozac;
        vozac = nullptr;
        cout << "Unesite ime prevoznika: ";
        char *prevoznik = new char[50];
        cin.getline(prevoznik,50);
        upis << "Prevoznik: " << prevoznik << endl;
        delete[] prevoznik;
        prevoznik = nullptr;
        cout << "Unesite broj mjesta u autobusu: ";
        cin >> brojMjesta;
        upis << "Broj mjesta: " << brojMjesta << endl;
        string *mjesta = new string[brojMjesta+1];
        string ime = ID + ".txt";
        ofstream snimi;
        snimi.open(ime.c_str());
        for(int i=1;i<=brojMjesta;i++){
            snimi << "[" << i << "] Prazno" << endl;
        }
        snimi.close();
        int x;
        do{
            cout << "Unesite stanje: 0. NEAKTIVAN i 1. AKTIVAN";
            cout << "\nOdabir: ";
            cin >> x;
        }while(x<0 || x>1);
        this->stanje = (Stanje)x;
        if(x==0){
            upis << "Stanje: NEAKTIVAN\0" << endl;
        }else{
            upis << "Stanje: AKTIVAN\0" << endl;
        }
        upis.close();
    }

    void pregledAutobusa(){
        string provjera;
        cout << left << setw(8) << "ID" << setw(25) << "Vozac" << setw(25) << "Prevoznik" << setw(15) << "Broj mjesta"
             << setw(15) << "Stanje" << endl;
        ifstream autobus("autobusi.txt");
        while(true){
            autobus >> provjera;
            if(autobus.eof()){
                break;
            }
            if(provjera == "ID:"){
                autobus >> provjera;
                cout << setw(8) << provjera;
            }
            autobus >> provjera;
            string tekst;
            if(provjera == "Vozac:"){
                autobus >> provjera;
                tekst = "";
                do{
                    tekst += provjera + " ";
                    autobus >> provjera;
                }while(provjera != "Prevoznik:");
                cout << setw(25) << tekst;
            }
            tekst = "";
            autobus >> provjera;
            do{
                tekst += provjera + " ";
                autobus >> provjera;
            }while(provjera != "Broj");
            cout << setw(25) << tekst;
            autobus >> provjera;
            if(provjera == "mjesta:"){
                autobus >> provjera;
                cout << setw(15) << provjera;
            }
            autobus >> provjera;
            if(provjera == "Stanje:"){
                autobus >> provjera;
                cout << setw(8) << provjera << endl;
            }

        }
        autobus.close();
    }

    void rezervacija(){
        this->pregledAutobusa();
        string IDRezervacija, provjera;
        br = 0;
        int brMjesta;
        do{
            cout << "Odaberite ID autobusa: ";
            cin >> IDRezervacija;
            ifstream autobus;
            autobus.open("autobusi.txt");
            while(!autobus.eof()){
                autobus >> provjera;
                if(provjera == "ID:"){
                    autobus >> provjera;
                    if(provjera == IDRezervacija){
                        br++;
                        autobus >> provjera;
                        do{
                            autobus >> provjera;
                        }while(provjera != "mjesta:");
                        autobus >> brMjesta;
                    }
                }
            }
            if(br==0){
                cout << "Autobus sa tim ID-om ne postoji.\n";
                cout << "Molimo Vas da unesete pravi ID!\n";
            }
            autobus.close();
        }while(br==0);
        string ime = IDRezervacija + ".txt";
        ifstream ispis(ime.c_str());
        string *mjesta = new string[brMjesta+1];
        bool prazan = true;
        while(!ispis.eof()){
            ispis >> provjera; //broj u zagradi;
            ispis >> mjesta[br];
            //if(mjesta[br] != "Prazno") prazan = false;
            br++;
        }
        ispis.close();
        int mjesto;
        cin.ignore();
        char putnik[50];
        cout << "Unesite ime i prezime putnika: ";
        cin.getline(putnik,50);
        do{
            cout << "Unesite mjesto za rezervaciju: ";
            cin >> mjesto;
            if(mjesto <1 || mjesto>brMjesta){
                cout << "Pogresan unos za mjesto!\n";
            }else if(mjesta[mjesto] != "Prazno"){
                mjesto = 0;
                cout << "To mjesto je vec zauzeto!\n";
            }
        }while(mjesto<1 || mjesto>brMjesta);
        mjesta[mjesto] = putnik;
        ofstream unos(ime.c_str());
        for(int i=1;i<brMjesta;i++){
            unos << "[" << i << "] " << mjesta[i] << endl;
        }
        unos.close();

    }
};

void prikaziMeni(){
    system("cls");
    cout << "----------------------------------------\n";
    cout << "\t\tMeni:\n";
    cout << "----------------------------------------\n";
    cout << "\t1. Unos autobusa\n";
    cout << "\t2. Pregled autobusa\n";
    cout << "\t3. Rezervacija mjesta\n";
    cout << "\t4. Pregled rezervacija\n";
    cout << "\t5. Kraj programa\n";
    cout << "----------------------------------------\n";
}
int main(){
    ofstream kreiraj("autobusi.txt", ios::app);
    kreiraj.close();

    Autobus a;
    int izbor;
    do{
        do{
            system("cls");
            prikaziMeni();
            cout << "Izbor: ";
            cin >> izbor;
            switch(izbor){
                case 1:
                    a.unosAutobusa();
                    cout << endl;
                    system("pause");
                    break;
                case 2:
                    a.pregledAutobusa();
                    cout << endl;
                    system("pause");
                    break;
                case 3:
                    a.rezervacija();
                    cout << endl;
                    system("pause");
                    break;
                case 4:
                    //Za zadacu da se igrate malo
                    break;
                case 5:
                    cout << "Hvala i dovidjenja\n";
                    break;
                default:
                    cout << "Greska\n!";
            }
        }while(izbor != 5);
    }while(izbor<1 || izbor>5);
    return 0;
}
