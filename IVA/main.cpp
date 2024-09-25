#include <iostream>
#include <cmath> 

class CalculadoraIVA {
    private:
    double total;
    double iva;

    public:
    CalculadoraIVA(double total, double iva) {
        this->total = total;
        this->iva = iva;
    }

    double calcularIVA() {
        return total / (1 + (iva/100));
    }
};

int main() {
    double total, iva;

    std::cout << "Ingrese el total: ";
    std::cin >> total;
    std::cout << "Ingrese el IVA: ";
    std::cin >> iva;

    CalculadoraIVA calc(total, iva);

    std::cout << "Total sin IVA: " << calc.calcularIVA() << std::endl;

    return 0;
}