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
                  << " - SRD" << std::fixed << std::setprecision(2) << price
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

int main
}
