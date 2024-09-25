#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Mascota {
    private:
        // Atributos de la clase Mascota
        string nombre;
        string especie;
        int edad;

    public:
        // Constructor por defecto
        Mascota() {}

        // Métodos set para asignar valores a los atributos privados
        void setNombre(string nombre) {
            this->nombre = nombre; // Asignamos el argumento al atributo privado
        }

        void setEspecie(string especie) {
            this->especie = especie;
        }

        void setEdad(int edad) {
            this->edad = edad;
        }

        // Método para presentar la información de la mascota
        void presentar() {
            cout << "Nombre: " << nombre << endl;
            cout << "Especie: " << especie << endl;
            cout << "Edad: " << edad << " años" << endl;
        }
};

int main() {
    vector<Mascota> mascotas;
    string nombre, especie;
    int edad;

    // Crear un objeto de la clase Mascota
    Mascota mascota;

    // Ingresar los datos de la mascota
    cout << "Ingrese el nombre de la mascota: ";
    cin >> nombre;
    mascota.setNombre(nombre);

    cout << "Ingrese la especie de la mascota: ";
    cin >> especie;
    mascota.setEspecie(especie);

    cout << "Ingrese la edad de la mascota: ";
    cin >> edad;
    mascota.setEdad(edad);

    // Guardar la mascota en el vector
    mascotas.push_back(mascota);

    // Llamar al método presentar() para mostrar la información de la mascota
    mascota.presentar();

    return 0;
}
