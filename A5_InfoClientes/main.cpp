#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
// libreria de colores
#include <iostream>
#include "colors.h"

using namespace std;

// clase cliente
class Cliente {
    // atributos de la clase cliente
    string nombre; 
    int id; 
    string direccion;
    string telefono;
    double saldo;

    // metodos publicos de la clase cliente
    public: 
        Cliente(string nombre, int id, string direccion, string telefono, double saldo) {
            // this sirve para referirse a los atributos de la clase
            this->nombre = nombre;
            this->id = id;
            this->direccion = direccion;
            this->telefono = telefono;
            this->saldo = saldo;
        }

        // funcion para mostrar los datos del cliente
        void showCliente() {
            cout << "\n";
            cout << "Nombre: " << nombre << endl;
            cout << "ID: " << id << endl;
            cout << "Direccion: " << direccion << endl;
            cout << "Telefono: " << telefono << endl;
            cout << "Saldo: " << saldo << endl;
            cout << "\n";
        }
};

int main() {
    // vector de clientes
    vector<Cliente> clientes;

    // ciclo para ingresar los datos de los clientes
    for(int i = 0; i < 3; i++) {

        // variables para los datos del cliente
        string nombre;
        int id;
        string direccion;
        string telefono;
        double saldo;
 
        // ingreso de datos del cliente
        cout << "\n" << RED << "Ingrese el cliente #" << i + 1 << RESET << "\n";
        cout << "Ingrese el nombre del cliente: ";
        cin >> nombre;
        cout << "Ingrese el id del cliente: ";
        cin >> id;
        cout << "Ingrese la direccion del cliente: ";
        cin >> direccion;
        cout << "Ingrese el telefono del cliente: ";
        cin >> telefono;
        cout << "Ingrese el saldo del cliente: ";
        cin >> saldo;
        cout << "\n";

        // se crea un nuevo cliente con los datos ingresados
        Cliente nuevoCliente(nombre, id, direccion, telefono, saldo);
        clientes.push_back(nuevoCliente);
    }

    // variable para la respuesta del usuario
    char respuesta;
    // se pregunta si se desea ver los clientes
    cout << "Desea ver los clientes? (s/n): ";  
    cin >> respuesta;

    // si la respuesta es s o S se muestran los clientes
    // || es un operador logico OR para validar si la respuesta es s o S
    if (respuesta == 's' || respuesta == 'S') {
        for (Cliente& cliente: clientes) {
            cliente.showCliente();
        }
    }
    return 0;
};

