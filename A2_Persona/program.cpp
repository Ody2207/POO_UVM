#include <iostream>
#include <string>

class Person {
public:
    // Atributos
    std::string nombre;
    int edad;
    std::string genero;

    // Constructor
    Person(std::string nombre, int edad, std::string genero) {
        this->nombre = nombre;
        this->edad = edad;
        this->genero = genero;
    }

    // Método para sudar
    int sudar() {
        std::cout << "Hola, mi nombre es Rodrigo" << std::endl;
        return 1;
    }
};

int main() {
    // Creación de un objeto de la clase Person
    Person juan("Rodrigo", 20, "M");
    // Llamada al método sudar
    juan.sudar();

    return 0;
}
