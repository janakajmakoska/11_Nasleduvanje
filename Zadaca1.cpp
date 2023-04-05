#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

class Datum {
    private:
        int den;
        int mesec;
        int godina;
    public:
        Datum(int d, int m, int g) {
            den = d;
            mesec = m;
            godina = g;
        }
        void prikaziDatum() {
            cout << den << "." << mesec << "." << godina << endl;
        }
};

class Artikl {
    protected:
        string ime_na_artikl;
        string golemina;
        double cena;
        Datum donesen_vo_prodavnica;
    public:
        Artikl(string ime, string g, double c, Datum d) {
            ime_na_artikl = ime;
            golemina = g;
            cena = c;
            donesen_vo_prodavnica = d;
        }
        virtual void prikaziPodatoci() {
            cout << "Ime na artikl: " << ime_na_artikl << endl;
            cout << "Golemina: " << golemina << endl;
            cout << "Cena: " << cena << endl;
            cout << "Donesen vo prodavnica: ";
            donesen_vo_prodavnica.prikaziDatum();
        }
        virtual double presmetajNabavka() {
            return cena;
        }
};
class Pantoloni : public Artikl {
    private:
        Datum datum_na_sledna_nabavka;
    public:
        Pantoloni(string ime, string g, double c, Datum d, Datum dn) : Artikl(ime, g, c, d) {
            datum_na_sledna_nabavka = dn;
        }
        void prikaziPodatoci() {
            Artikl::prikaziPodatoci();
            cout << "Datum na sledna nabavka: ";
            datum_na_sledna_nabavka.prikaziDatum();
        }
        double presmetajNabavka() {
            return cena;
        }
};
class Kosuli : public Artikl {
    public:
        Kosuli(string ime, string g, double c, Datum d) : Artikl(ime, g, c, d) {}
        void prikaziPodatoci() {
            Artikl::prikaziPodatoci();
        }
        double presmetajNabavka() {
            return cena;
        }
};


void prikaziArtikli(vector<Artikl*>& artikli, string grupa) {
    cout << "Artikli od grupata " << grupa << ":\n";
    for (Artikl* artikl : artikli) {
        if (artikl->getGrupa() == grupa) {
            artikl->prikaziPodatoci();
        }
    }
}
int main() {
    vector<Artikl*> artikli;
    int izbor = 0;
    while (izbor != 5) {
        cout << endl;
        cout << "----- MENI -----" << endl;
        cout << "1. Dodavanje na artikl vo listata" << endl;
        cout << "2. Prikazuvanje na artikli od dadena grupa" << endl;
        cout << "3. Prikazuvanje na celata lista (so vkupna cena)" << endl;
        cout << "4. Prikazuvanje na artiklite koi treba da se nabavat vo rok od 1 nedela i pari koi treba da se potrosat za da se nabavat potrebnite artikli" << endl;
        cout << "5. Izlez od menito" << endl;
        cout << "Izbor: ";
        cin >> izbor;
        cout << endl;

        switch (izbor) {
            case 1: {
                int tipArtiklIzbor = 0;
                cout << "Tip na artikl: " << endl;
                cout << "1. Pantoloni" << endl;
                cout << "2. Kosuli" << endl;
                cout << "Izbor: ";
                cin >> tipArtiklIzbor;

                if (tipArtiklIzbor == 1) {
                    string ime;
                    int golemina;
                    float cena;
                    Datum donesenVoProdavnica;
                    cout << "Vnesi ime na pantalonite: ";
                    cin >> ime;
                    cout << "Vnesi golemina na pantalonite: ";
                    cin >> golemina;
                    cout << "Vnesi cena na pantalonite: ";
                    cin >> cena;
                    cout << "Vnesi datum koga pantalonite bea doneseni vo prodavnicata (vo format DD/MM/GGGG): ";
                    donesenVoProdavnica.push();
                    artikli.push_back(new Pantoloni(ime, golemina, cena, donesenVoProdavnica));
                    cout << "Pantalonite se dodadeni vo listata." << endl;
                } else if (tipArtiklIzbor == 2) {
                    string ime;
                    int golemina;
                    float cena;
                    Datum donesenVoProdavnica;
                    cout << "Vnesi ime na koshulata: ";
                    cin >> ime;
                    cout << "Vnesi golemina na koshulata: ";
                    cin >> golemina;
                    cout << "Vnesi cena na koshulata: ";
                    cin >> cena;
                    cout << "Vnesi datum koga koshulata bese doneseni vo prodavnicata (vo format DD/MM/GGGG): ";
                    donesenVoProdavnica.push();
                    artikli.push_back(new Kosuli(ime, golemina, cena, donesenVoProdavnica));
                    cout << "Koshulata se dodadeni vo listata." << endl;
                }
            }
            case 2:
            {
                void prikaziArtikli(vector<Artikl*>& artikli, string grupa) {
                cout << "Artikli od grupata " << grupa << ":\n";
                for (Artikl* artikl : artikli) {
                if (artikl->getGrupa() == grupa) {
                artikl->prikaziPodatoci();

            }
                }
                    }
            }
            case 3:
            {
                for (Artikl* artikl : artikli) {
                    artikl->prikaziPodatoci();
                }
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
        }
    }
    return 0;
}


