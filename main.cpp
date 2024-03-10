#include <iostream>
#include<vector>
#include<iomanip>

using namespace std;

class Car {
public:
    std::string mBrand;
    std::string mLicensePlate;
    uint16_t mYearOfFabrication;
    double mAverageConsumption;
    uint32_t mNumberOfKilometers;

    Car(std::string brand, std::string placuta, uint16_t anfabricatie, double consum, uint32_t nrkm) {
        mBrand = brand;
        mLicensePlate = placuta;
        mYearOfFabrication = anfabricatie;
        mAverageConsumption = consum;
        mNumberOfKilometers = nrkm;
    }

    virtual double getFuelConsumption() const = 0;

    virtual double getFuelCost() const = 0;

    virtual std::string getType() const = 0;

    bool operator<(const Car &masina) const {
        /*   if (mYearOfFabrication != masina.mYearOfFabrication) {
               return mYearOfFabrication > masina.mYearOfFabrication;
           } else if (mNumberOfKilometers != masina.mNumberOfKilometers) {
               return mNumberOfKilometers < masina.mNumberOfKilometers;
           } else  {
               return mAverageConsumption > masina.mAverageConsumption;
           }*/return true;
    }

    string getBrand() const {
        return mBrand;
    }

    string getLicensePlate() const {
        return mLicensePlate;
    }

    uint16_t getYearOfFabrication() const {
        return mYearOfFabrication;
    }

    double getAverageConsumption() const {
        return mAverageConsumption;
    }

    uint32_t getNumberOfKilometers() const {
        return mNumberOfKilometers;
    }
};

class PetrolCar : public Car {
public:
    double getFuelConsumption() const override {
        //Benzină - (0.879 * consumul_mediu * numar_kilometri) / 100;
        double consum;
        consum = (0.879 * mAverageConsumption * mNumberOfKilometers) / 100;
        return consum;
    }

    double getFuelCost() const override {
        double cost;
        cost = 4.5 * getFuelConsumption();
        return cost;
    }

    std::string getType() const override {
        return "benzina";
    }

    PetrolCar(std::string mBrand, std::string mLicensePlate, uint16_t mYearOfFabrication, double mAverageConsumption,
              uint32_t mNumberOfKilometers) : Car(mBrand, mLicensePlate, mYearOfFabrication, mAverageConsumption,
                                                  mNumberOfKilometers) {

    }
};

class DieselCar : public Car {
public:
    DieselCar(std::string mbBrand, std::string mLicensePlate, uint16_t mYearOfFabrication, double mAverageConsumption,
              uint32_t mNumberOfKilometers) : Car(mbBrand, mLicensePlate, mYearOfFabrication, mAverageConsumption,
                                                  mNumberOfKilometers) {

    }

    double getFuelConsumption() const override {
        //Motorină - (0.789 * consumul_mediu * numar_kilometri) / 100;
        double consum;
        consum = (0.789 * mAverageConsumption * mNumberOfKilometers) / 100;
        return consum;
    }

    double getFuelCost() const override {
        double cost;
        cost = 4.8 * getFuelConsumption();
        return cost;
    }

    std::string getType() const override {
        return "diesel";
    }
};

class HybridCar : public Car {
public:
    HybridCar(std::string mbBrand, std::string mLicensePlate, uint16_t mYearOfFabrication, double mAverageConsumption,
              uint32_t mNumberOfKilometers) : Car(mbBrand, mLicensePlate, mYearOfFabrication, mAverageConsumption,
                                                  mNumberOfKilometers) {

    }

    double getFuelConsumption() const override {
        //(consumul_mediu * numar_kilometri - 0.124 * numar_kilometri) / 100;
        double consum;
        consum = (mAverageConsumption * mNumberOfKilometers - 0.124 * mNumberOfKilometers) / 100;
        return consum;
    }

    double getFuelCost() const override {
        double cost;
        cost = 4.5 * getFuelConsumption();
        return cost;
    }

    std::string getType() const override {
        return "hibrid";
    }

};

class ElectricCar : public Car {
public:
    ElectricCar(std::string mbBrand, std::string mLicensePlate, uint16_t mYearOfFabrication, double mAverageConsumption,
                uint32_t mNumberOfKilometers) : Car(mbBrand, mLicensePlate, mYearOfFabrication, mAverageConsumption,
                                                    mNumberOfKilometers) {

    }

    double getFuelConsumption() const override {
        //(consumul_mediu * numar_kilometri - 0.124 * numar_kilometri) / 100;
        double consum;
        consum = 0;
        return consum;
    }

    double getFuelCost() const override {
        double cost;
        cost = 0;
        return cost;
    }

    std::string getType() const override {
        return "electrica";
    }
};

int main() {
    int n;
    char comanda;
    string brand, tip_combustibil, placuta;
    uint16_t an;
    double consum;
    uint32_t km;
    vector<Car *> masini;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> brand;
        cin >> tip_combustibil;
        cin >> placuta;
        cin >> an;
        cin >> consum;
        cin >> km;
        if (tip_combustibil == "diesel") {
            masini.push_back(new DieselCar(brand, placuta, an, consum, km));
        }
        if (tip_combustibil == "benzina") {
            masini.push_back(new PetrolCar(brand, placuta, an, consum, km));
        }
        if (tip_combustibil == "hibrid") {
            masini.push_back(new HybridCar(brand, placuta, an, consum, km));
        }
        if (tip_combustibil == "electrica") {
            masini.push_back(new ElectricCar(brand, placuta, an, consum, km));
        }
    }
    cin >> comanda;
    if (comanda == 'a') {
        for (int i = 0; i < masini.size() - 1; i++) {
            for (int j = i + 1; j < masini.size(); j++) {
                if (masini[i]->getYearOfFabrication() < masini[j]->getYearOfFabrication()) {
                    swap(masini[i], masini[j]);
                }
            }
        }
        for (int i = 0; i < masini.size() - 1; i++) {
            for (int j = i + 1; j < masini.size(); j++) {
                if (masini[i]->getNumberOfKilometers() > masini[j]->getNumberOfKilometers() &&
                    masini[i]->getYearOfFabrication() == masini[j]->getYearOfFabrication()) {
                    swap(masini[i], masini[j]);
                }
            }
        }
        for (int i = 0; i < masini.size() - 1; i++) {
            for (int j = i + 1; j < masini.size(); j++) {
                if (masini[i]->getFuelConsumption() < masini[j]->getFuelConsumption() &&
                    masini[i]->getYearOfFabrication() == masini[j]->getYearOfFabrication() &&
                    masini[i]->getNumberOfKilometers() == masini[j]->getNumberOfKilometers())
                    swap(masini[i], masini[j]);
            }
        }
        for (int i = 0; i < masini.size(); i++) {
            cout << fixed << setprecision(3) << "Masina " << masini[i]->getBrand() << " cu numarul de inmatriculare "
                 << masini[i]->getLicensePlate() << " a parcurs " << masini[i]->getNumberOfKilometers()
                 << "km si a consumat " << masini[i]->getFuelConsumption() << " litri." << endl;
        }
    }
    if (comanda == 'b') {
        double suma = 0;
        for (int i = 0; i < masini.size(); i++) {
            suma = suma + masini[i]->getFuelCost();
        }
        cout << fixed << setprecision(2) << suma;
    }
    // cout<<fixed<<setprecision(2)<<masini[0]->getFuelCost();
    if (comanda == 'd') {
        int benzina = 0, hibrid = 0, electric = 0, diesel = 0;
        for (int i = 0; i < masini.size(); i++) {
            if (masini[i]->getType() == "benzina") {
                benzina++;
            }
            if (masini[i]->getType() == "diesel") {
                diesel++;
            }
            if (masini[i]->getType() == "electrica") {
                electric++;
            }
            if (masini[i]->getType() == "hibrid") {
                hibrid++;
            }

        }
        cout << "benzina -> " << benzina << endl;
        cout << "diesel -> " << diesel << endl;
        cout << "electrica -> " << electric << endl;
        cout << "hibrid -> " << hibrid << endl;
    }
    if (comanda == 'c') {
        while (cin >> brand) {
            cin >> tip_combustibil >> placuta >> an >> consum >> km;
            if (tip_combustibil == "diesel")
                masini.push_back(new DieselCar(brand, placuta, an, consum, km));

            if (tip_combustibil == "benzina")
                masini.push_back(new PetrolCar(brand, placuta, an, consum, km));

            if (tip_combustibil == "hibrid")
                masini.push_back(new HybridCar(brand, placuta, an, consum, km));

            if (tip_combustibil == "electrica")
                masini.push_back(new ElectricCar(brand, placuta, an, consum, km));

        }
        // for(int i=0;i<masini.size();i++){
        //   cout<<masini[masini.size()]->getBrand();
        double distanta_totala = 0, consum_mediu = 0;
        for (int i = 0; i < masini.size(); i++) {
            distanta_totala = distanta_totala + masini[i]->getNumberOfKilometers();
            consum_mediu = consum_mediu + masini[i]->getAverageConsumption();
        }
        cout << distanta_totala << " km" << endl;
        cout << fixed << setprecision(2) << consum_mediu / (double) masini.size() << " L/100km";
    }

    if (comanda == 'e') {

        for (int i = 0; i < masini.size(); i++) {
            int ok = 0;
            if (isupper(masini[i]->mLicensePlate[0])) {
                if (isupper(masini[i]->mLicensePlate[1])) {

                    if (isdigit(masini[i]->mLicensePlate[2]) && isdigit(masini[i]->mLicensePlate[3])) {
                        if (isdigit(masini[i]->mLicensePlate[4])) {
                            if (isupper(masini[i]->mLicensePlate[5]) && isupper(masini[i]->mLicensePlate[6]) &&
                                isupper(masini[i]->mLicensePlate[7])) {
                                ok = 1;
                            }
                        } else {
                            if (isupper(masini[i]->mLicensePlate[4]) && isupper(masini[i]->mLicensePlate[5]) &&
                                isupper(masini[i]->mLicensePlate[6])) {
                                ok = 1;
                            }
                        }
                    } else {
                        if (isdigit(masini[i]->mLicensePlate[3])) {
                            if (isupper(masini[i]->mLicensePlate[4]) && isupper(masini[i]->mLicensePlate[5]) &&
                                isupper(masini[i]->mLicensePlate[6])) {
                                ok = 1;
                            }
                        } else {
                            if (isupper(masini[i]->mLicensePlate[3]) && isupper(masini[i]->mLicensePlate[4]) &&
                                isupper(masini[i]->mLicensePlate[5])&&!isupper(masini[i]->mLicensePlate[6])) {
                                ok = 1;
                            }
                        }

                    }
                } else {
                    if (isdigit(masini[i]->mLicensePlate[1]) && isdigit(masini[i]->mLicensePlate[2])) {
                        if (isdigit(masini[i]->mLicensePlate[3])) {
                            if (isupper(masini[i]->mLicensePlate[4]) && isupper(masini[i]->mLicensePlate[5]) &&isupper(masini[i]->mLicensePlate[6])) {
                                ok = 1;
                            }
                        } else {
                            if (isupper(masini[i]->mLicensePlate[3]) && isupper(masini[i]->mLicensePlate[4]) &&
                                isupper(masini[i]->mLicensePlate[5])&&!isupper(masini[i]->mLicensePlate[6])) {
                                ok = 1;
                            }
                        }
                    } else {
                        if (isdigit(masini[i]->mLicensePlate[2])) {
                            if (isupper(masini[i]->mLicensePlate[3]) && isupper(masini[i]->mLicensePlate[4]) &&
                                isupper(masini[i]->mLicensePlate[5])&&!isupper(masini[i]->mLicensePlate[6])) {
                                ok = 1;
                            }
                        } else {
                            if (isupper(masini[i]->mLicensePlate[2]) && isupper(masini[i]->mLicensePlate[3]) &&
                                isupper(masini[i]->mLicensePlate[4])) {
                                ok = 1;
                            }
                        }

                    }
                }
            }
            //B53APOP
            if(ok==0){
                cout << masini[i]->getLicensePlate() << ": numar de inmatriculare invalid"<<endl;
            }
        }
    }
    return 0;

}