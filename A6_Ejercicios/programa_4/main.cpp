#include <iostream>
#include <vector>
#include <string>

// Necesario para std::invalid_argument
// LIBRERIA PARA COLORES
#include <stdexcept> 
#include "colors.h" 

using namespace std;

class Mascota {
    private:
        // Atributos de la clase Mascota
        string nombre;
        string especie;
        int edad;

    public:
        // Constructor por defecto
        Mascota() : edad(0) {}

        // Métodos set para asignar valores a los atributos privados
        void setNombre(string nombre) {
            this->nombre = nombre; // Asignamos el argumento al atributo privado
        }

        void setEspecie(string especie) {
            this->especie = especie;
        }

        void setEdad(const std::string& input) {
            // Validar si la entrada es un número
            for (char const &c : input) {
                if (!std::isdigit(c)) {
                    throw std::invalid_argument("Error: La edad ingresada no es un número válido.");
                }
            }
            // Convertir la entrada a un número entero y asignar a la variable edad
            edad = std::stoi(input);
        }

        // Método para presentar la información de la mascota
        void presentar() {
            cout << GRAY << "Nombre: " << nombre << endl;
            cout << "Especie: " << especie << endl;
            cout << "Edad: " << edad << " años" << endl;
            cout << "\n" << RESET;
        }
};

int main() {
    vector<Mascota> mascotas;
    string nombre, especie, edadStr;
    int cantidad;

    cout << GRAY << "¿Cuántas mascotas quiere agregar?: " << RESET;
    cin >> cantidad;

    for(int i = 0; i < cantidad; i++) {
        Mascota mascota;

        // Ingresar los datos de la mascota
        cout << "Ingrese el nombre de la mascota: ";
        cin >> nombre;
        mascota.setNombre(nombre);

        cout << "Ingrese la especie de la mascota: ";
        cin >> especie;
        mascota.setEspecie(especie);

        bool edadValida = false;
        while (!edadValida) {
            cout << "Ingrese la edad de la mascota: ";
            cin >> edadStr;
            try {
                mascota.setEdad(edadStr);
                edadValida = true; // La edad es válida, salimos del bucle
            } catch (const std::invalid_argument& e) {
                cout << "\n";
                cout << RED <<  e.what() << " Por favor, intente de nuevo." << RESET << endl;
                cout << "\n";
            }
        }
        cout << "\n";

        // Guardar la mascota en el vector
        mascotas.push_back(mascota);
    }

    // Llamar al método presentar() para mostrar la información de las mascotas
    for (int i = 0; i < cantidad; i++) {
        mascotas[i].presentar();
    }

    return 0;
}
