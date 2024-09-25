#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class Mascota {
    // Atributos de la clase Mascota
    string nombre;
    string especie;
    int edad;

    // Métodos públicos de la clase Mascota
    public:
        // Constructor de la clase Mascota
        Mascota(string nombre, string especie, int edad) {
            this->nombre = nombre;
            this->especie = especie;
            this->edad = edad;
        }

        // Método para presentar la información de la mascota
        void presentar() {
            cout << "Nombre: " << nombre << endl;
            cout << "Especie: " << especie << endl;
            cout << "Edad: " << edad << endl;
        }
};



int main() {
    vector<Mascota> mascotas;

    string nombre; 
    string especie;
    int edad;

    // Crear un objeto de la clase Mascota
    Mascota mascota("Firulais", "Perro", 5);

    // Ingresar los datos de la mascota
    cout << "Ingrese el nombre de la mascota: ";
    cin >> nombre;
    cout << "Ingrese la especie de la mascota: ";
    cin >> especie;
    cout << "Ingrese la edad de la mascota: ";
    cin >> edad;

    Mascota nuevaMascota(nombre, especie, edad);
    mascotas.push_back(nuevaMascota);

    // Llamar al método presentar() para mostrar la información
    mascota.presentar();
    
    return 0;
}

// Crear un objeto de la clase Mascota

// Pedir al usuario que ingrese los datos de la mascota

// Llamar al método presentar() para mostrar la información
