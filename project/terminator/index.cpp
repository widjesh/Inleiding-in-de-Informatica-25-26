#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iomanip>

class Cleanbot {
public:
    std::string name;
    double price;
    std::vector<std::string> features;
    int stock;

    Cleanbot() : name(""), price(0.0), features(), stock(0) {}
    Cleanbot(const std::string& n, double p, const std::vector<std::string>& f, int s)
        : name(n), price(p), features(f), stock(s) {}

    void printSummary(int index) const {
        std::cout << std::setw(2) << index << ". " << name
                  << " - SRD " << std::fixed << std::setprecision(2) << price
                  << " (" << stock << " op voorraad)\n";
    }

    void printDetails() const {
        std::cout << "Naam: " << name << "\n";
        std::cout << "Prijs: SRD" << std::fixed << std::setprecision(2) << price << "\n";
        std::cout << "Functies:\n";
        for (const auto& f : features) {
            std::cout << "  - " << f << "\n";
        }
        std::cout << "Voorraad: " << stock << "\n";
    }
};

int main() {
    
    std::cout << "           _                  _           _       _  " << std::endl;
    std::cout << "          | |                | |         | |     | | " << std::endl;
    std::cout << "       ___| | ___  __ _ _ __ | |__   ___ | |_ ___| | " << std::endl;
    std::cout << "      / __| |/ _ \\/ _` | '_ \\| '_ \\ / _ \\| __/ __| | " << std::endl;
    std::cout << "     | (__| |  __/ (_| | | | | |_) | (_) | |_\\__ \\_| " << std::endl;
    std::cout << "      \\___|_|\\___|\\__,_|_| |_|_.__/ \\___/ \\__|___(_) " << std::endl;
    std::cout << "                                                     " << std::endl;
    std::cout << "                                                     " << std::endl;

    std::cout << "\nWelkom bij cleanbots! Hier vindt u de beste cleanbots in de HELE WERELD!!!.\n";
    std::cout << "Bent u geinteresseerd in een van onze cleanbots?\nVoer dan 'ilovecleanbots' in en druk op enter om meer details te zien over onze cleanbots en hun functies!.\n";

    std::string userInput;
    std::getline(std::cin, userInput);
    while(userInput != "ilovecleanbots") {  
        std::cout << "\numm... dat is niet correct! Probeer het nog eens: " << std::endl;
        std::getline(std::cin, userInput);
    }
    std::cout << "\nGood job vro! Hier zijn onze cleanbots:\n\n";
    std::array<Cleanbot, 5> cleanbots = {
        Cleanbot("CleanMaster 3000", 189999.99, {"Automatisch stofzuigen", "Dweilfunctie", "App-besturing"}, 10),
        Cleanbot("eco-bot", 75999.99, {"Energiezuinig", "Stofzuigen en dweilen", "Lange batterijduur"}, 15),
        Cleanbot("groom-bot", 56999.99, {"Speciaal voor huisdierenhaar", "HEPA-filter", "Zelfreinigend"}, 20),
        Cleanbot("broke-bot", 9999.99, {"Stofzuigen", "Eenvoudige bediening"}, 17),
        Cleanbot("rich-bot", 949999.99, {"AI-navigatie", "Spraakbesturing", "Automatische vuilnisbaklediging"}, 10)
    };

    for (int i = 0; i < cleanbots.size(); ++i) {
        cleanbots[i].printSummary(i + 1);
    }
    
    std::cout << "\nVoer het nummer van de cleanbot die u wilt kopen: ";
    int choice = 0;
    std::cin >> choice;

    if(choice < 1 || choice > (int)cleanbots.size()) {
        std::cout << "Ongeldige keuze.\n";
        
    }
    Cleanbot& selected = cleanbots[choice-1];

    if(selected.stock <= 0) {
        std::cout << "Sorry, deze cleanbot is niet op voorraad.\n";
       
    }

    selected.printDetails();

    std::cout << "Wilt u doorgaan met betalen voor deze cleanbot? (ja/nee): ";
    std::string payConfirm;
    std::cin >> payConfirm;

    if(payConfirm == "ja") {
        selected.stock--;
        std::cout << "Bedankt voor uw aankoop van " << selected.name << "! Uw betaling van SRD "
                  << std::fixed << std::setprecision(2) << selected.price << " is gelukt.\n";
        std::cout << "Resterende voorraad: " << selected.stock << std::endl;
    } else {
        std::cout << "Aankoop geannuleerd.\n";
    }

}
