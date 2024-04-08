#include <iostream>

using namespace std;

template<typename T>
class Exchange {
private:
    T uah_to_usd;
    T uah_to_eur;
    T usd_to_uah;
    T usd_to_eur;
    T eur_to_uah;
    T eur_to_usd;

public:
    Exchange(T uah_to_usd, T uah_to_eur, T usd_to_uah, T usd_to_eur, T eur_to_uah, T eur_to_usd)
        : uah_to_usd(uah_to_usd), uah_to_eur(uah_to_eur), usd_to_uah(usd_to_uah), usd_to_eur(usd_to_eur), eur_to_uah(eur_to_uah), eur_to_usd(eur_to_usd) {}

    void printRates() const {
        cout << "UAH to USD: " << uah_to_usd << endl;
        cout << "UAH to EUR: " << uah_to_eur << endl;
        cout << "USD to UAH: " << usd_to_uah << endl;
        cout << "USD to EUR: " << usd_to_eur << endl;
        cout << "EUR to UAH: " << eur_to_uah << endl;
        cout << "EUR to USD: " << eur_to_usd << endl;
    }

    void updateRates(T new_uah_to_usd, T new_uah_to_eur, T new_usd_to_uah, T new_usd_to_eur, T new_eur_to_uah, T new_eur_to_usd) {
        uah_to_usd = new_uah_to_usd;
        uah_to_eur = new_uah_to_eur;
        usd_to_uah = new_usd_to_uah;
        usd_to_eur = new_usd_to_eur;
        eur_to_uah = new_eur_to_uah;
        eur_to_usd = new_eur_to_usd;
    }

    T exchange(T amount, const string& from, const string& to) const {
        if (from == "UAH" && to == "USD")
            return amount * uah_to_usd;
        else if (from == "UAH" && to == "EUR")
            return amount * uah_to_eur;
        else if (from == "USD" && to == "UAH")
            return amount * usd_to_uah;
        else if (from == "USD" && to == "EUR")
            return amount * usd_to_eur;
        else if (from == "EUR" && to == "UAH")
            return amount * eur_to_uah;
        else if (from == "EUR" && to == "USD")
            return amount * eur_to_usd;
        else
            throw invalid_argument("Invalid currency exchange");
    }
};

int main() {
    Exchange<double> exchanger(27.50, 32.10, 0.036, 0.88, 30.20, 1.15);

    exchanger.printRates();

    cout << "Exchange 100 UAH to USD: " << exchanger.exchange(100, "UAH", "USD") << endl;

    exchanger.updateRates(27.60, 32.20, 0.037, 0.89, 30.30, 1.16);

    cout << "Updated Rates:" << endl;
    exchanger.printRates();

    return 0;
}
