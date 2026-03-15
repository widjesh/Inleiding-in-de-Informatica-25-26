#include <iostream>
#include <string>

using namespace std;

class Rekening {
private:
    string naam;
    string rekeningNummer;
    double saldo;
    bool geblokkeerd;

public:
    void setGegevens(string n, string r) {
        naam = n;
        rekeningNummer = r;
        saldo = 0;
        geblokkeerd = false;
    }

    void toonGegevens() {
        cout << "Naam: " << naam << " | Rekening: " << rekeningNummer
             << " | Saldo: SRD " << saldo
             << " | Status: " << (geblokkeerd ? "Geblokkeerd" : "Actief") << endl;
    }

    void stort(double bedrag) {
        if (!geblokkeerd && bedrag > 0) {
            saldo += bedrag;
            cout << "✅ Storting geslaagd! Nieuw saldo: SRD " << saldo << endl;
        } else {
            cout << "⚠️ Storting mislukt.\n";
        }
    }

    void neemOp(double bedrag) {
        if (!geblokkeerd && bedrag > 0 && bedrag <= saldo) {
            saldo -= bedrag;
            cout << "✅ Opname geslaagd! Nieuw saldo: SRD " << saldo << endl;
        } else {
            cout << "⚠️ Opname mislukt.\n";
        }
    }

    void blokkeer() { geblokkeerd = true; cout << "🔒 Rekening geblokkeerd.\n"; }
    void deblokkeer() { geblokkeerd = false; cout << "🔓 Rekening gedeblokkeerd.\n"; }
};

int main() {
    Rekening bank[3];

    // Vooraf ingestelde rekeningen
    bank[0].setGegevens("Dalmar", "SRD001");
    bank[1].setGegevens("Dillon", "SRD002");
    bank[2].setGegevens("Shaniel", "SRD003");

    int keuze;
    int rekeningNummer;
    double bedrag;

    do {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Toon alle rekeningen\n";
        cout << "2. Stort geld\n";
        cout << "3. Neem geld op\n";
        cout << "4. Blokkeer rekening\n";
        cout << "5. Deblokkeer rekening\n";
        cout << "0. Stop\n";
        cout << "Maak uw keuze: ";
        cin >> keuze;

        switch (keuze) {
            case 1:
                for (int i = 0; i < 3; i++) {
                    cout << i + 1 << ". ";
                    bank[i].toonGegevens();
                }
                break;
            case 2:
                cout << "Kies rekening (1-3): ";
                cin >> rekeningNummer;
                cout << "Bedrag om te storten: ";
                cin >> bedrag;
                bank[rekeningNummer - 1].stort(bedrag);
                break;
            case 3:
                cout << "Kies rekening (1-3): ";
                cin >> rekeningNummer;
                cout << "Bedrag om op te nemen: ";
                cin >> bedrag;
                bank[rekeningNummer - 1].neemOp(bedrag);
                break;
            case 4:
                cout << "Kies rekening (1-3) om te blokkeren: ";
                cin >> rekeningNummer;
                bank[rekeningNummer - 1].blokkeer();
                break;
            case 5:
                cout << "Kies rekening (1-3) om te deblokkeren: ";
                cin >> rekeningNummer;
                bank[rekeningNummer - 1].deblokkeer();
                break;
            case 0:
                cout << "Tot ziens!\n";
                break;
            default:
                cout << "Ongeldige keuze!\n";
        }

    } while (keuze != 0);

    return 0;
}