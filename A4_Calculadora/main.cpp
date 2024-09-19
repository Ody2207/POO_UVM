#include <iostream>
#include <cmath>  // Para usar sqrt() y pow()

// Definiciones de la clase Calculadora
class Calculadora {
private:
    double numero1;  // Atributo para el primer número
    double numero2;  // Atributo para el segundo número

public:
    // Constructor para inicializar los valores
    Calculadora(double numero1, double numero2) {
        this->numero1 = numero1;
        this->numero2 = numero2;
    }
   

    // Método para sumar
    double sumar() {
        return numero1 + numero2;
    }

    // Método para restar
    double restar() {
        return numero1 - numero2;
    }

    // Método para multiplicar
    double multiplicar() {
        return numero1 * numero2;
    }

    // Método para dividir
    double dividir() {
        if (numero2 != 0) {
            return numero1 / numero2;
        } else {
            std::cout << "Error: No se puede dividir entre cero." << std::endl;
            return 0;
        }
    }

    double raizCuadrada() {
        return sqrt(numero1);
    }

    double potencia() {
        return pow(numero1, numero2);
    }
};

int main() {
    double numero1, numero2;
    char operacion;  // Sirve para que pueda reconocer los símbolos de los métodos

    // Pedimos al usuario que ingrese dos números
    std::cout << "Ingrese el primer número: ";
    std::cin >> numero1;
    std::cout << "Ingrese el segundo número: ";
    std::cin >> numero2;

    // Pedimos al usuario que elija una operación
    std::cout << "Seleccione una operación (+, -, *, /, r, ^): ";
    std::cin >> operacion;

    // Creamos un objeto de la clase Calculadora
    Calculadora calc(numero1, numero2);

    // Realizamos la operación seleccionada
    switch (operacion) {
    case '+':
        std::cout << "Resultado: " << calc.sumar() << std::endl;
        break;
    case '-':
        std::cout << "Resultado: " << calc.restar() << std::endl;
        break;
    case '*':
        std::cout << "Resultado: " << calc.multiplicar() << std::endl;
        break;
    case '/':
        std::cout << "Resultado: " << calc.dividir() << std::endl;
        break;
    case 'r':
        std::cout << "Resultado: " << calc.raizCuadrada() << std::endl;
        break;
    case '^':
        std::cout << "Resultado: " << calc.potencia() << std::endl;
        break;
    default:
        std::cout << "Operación no válida." << std::endl;
        break;
    }

    return 0;
}
