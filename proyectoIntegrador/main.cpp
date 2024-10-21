#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Profesor {
    string nombre;
    string apellido; 
    string sexo;
    int edad;
    string titulo;
    int noCedulaProfesional;

public:
    Profesor(string nombre, string apellido, string sexo, int edad, string titulo, int noCedulaProfesional) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->sexo = sexo;
        this->edad = edad;
        this->titulo = titulo;
        this->noCedulaProfesional = noCedulaProfesional;
    }

    void mostrarProfesor() const {
        cout << "Nombre: " << nombre << " " << apellido << endl;
        cout << "Sexo: " << sexo << ", Edad: " << edad << ", Título: " << titulo << endl;
        cout << "No. de Cédula Profesional: " << noCedulaProfesional << endl;
        cout << "---------------------------" << endl;
    }

    string getNombreCompleto() const {
        return nombre + " " + apellido;
    }
};

class Materia {
    string nombre;
    int creditos;
    Profesor profesor;

public:
    Materia(string nombre, int creditos, const Profesor& profesor) : profesor(profesor) {
        this->nombre = nombre;
        this->creditos = creditos;
    }

    void mostrarMateria() const {
        cout << "Materia: " << nombre << ", Créditos: " << creditos << endl;
        cout << "Profesor: " << profesor.getNombreCompleto() << endl;
        cout << "---------------------------" << endl;
    }

    string getNombre() const {
        return nombre;
    }
};

class Alumno {
    string nombre;
    string apellido;
    int noControlEscolar;
    int edad;
    string sexo;
    string semestre;
    vector<Materia> materias;

public:
    Alumno(string nombre, string apellido, int noControlEscolar, int edad, string sexo, string semestre) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->noControlEscolar = noControlEscolar;
        this->edad = edad;
        this->sexo = sexo;
        this->semestre = semestre;
    }

    void agregarMateria(const Materia& materia) {
        materias.push_back(materia);
    }

    void mostrarAlumno() const {
        cout << "Nombre: " << nombre << " " << apellido << endl;
        cout << "No. de Control Escolar: " << noControlEscolar << endl;
        cout << "Edad: " << edad << ", Sexo: " << sexo << ", Semestre: " << semestre << endl;
        cout << "Materias: " << endl;
        for (const auto& materia : materias) {
            cout << "- " << materia.getNombre() << endl;
        }
        cout << "---------------------------" << endl;
    }
};

int main() {
    vector<Alumno> alumnos;
    vector<Profesor> profesores;
    vector<Materia> materiasDisponibles;

    while (true) {
        int opcion = 0;

        cout << "Seleccione una opción:" << endl;
        cout << "1. Agregar Alumno" << endl;
        cout << "2. Agregar Profesor" << endl;
        cout << "3. Agregar Materia" << endl;
        cout << "4. Visualizar Alumnos" << endl;
        cout << "5. Visualizar Profesores" << endl;
        cout << "6. Visualizar Materias" << endl;
        cout << "7. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        if(opcion == 1) {
            string nombre, apellido, sexo, semestre;
            int noControlEscolar, edad;
            size_t numMaterias;

            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Apellido: ";
            getline(cin, apellido);
            cout << "No. de Control Escolar: ";
            cin >> noControlEscolar;
            cout << "Edad: ";
            cin >> edad;
            cin.ignore(); // Limpiar el buffer de entrada
            cout << "Sexo: ";
            getline(cin, sexo);
            cout << "Semestre: ";
            getline(cin, semestre);

            Alumno alumno(nombre, apellido, noControlEscolar, edad, sexo, semestre);

            if(materiasDisponibles.empty()) {
                cout << "No hay materias disponibles. Por favor, agregue materias primero." << endl;
            } else {
                cout << "¿Cuántas materias desea agregar?: ";
                cin >> numMaterias;
                cin.ignore(); // Limpiar el buffer de entrada

                for(size_t i = 0; i < numMaterias; i++) {
                    cout << "Seleccione una materia para agregar al alumno:" << endl;
                    for(size_t j = 0; j < materiasDisponibles.size(); j++) {
                        cout << j+1 << ". " << materiasDisponibles[j].getNombre() << endl;
                    }
                    size_t seleccion;
                    cout << "Opción: ";
                    cin >> seleccion;
                    cin.ignore(); // Limpiar el buffer de entrada
                    if(seleccion > 0 && seleccion <= materiasDisponibles.size()) {
                        alumno.agregarMateria(materiasDisponibles[seleccion - 1]);
                    } else {
                        cout << "Selección inválida." << endl;
                    }
                }
            }

            alumnos.push_back(alumno);
            cout << "Alumno agregado exitosamente!" << endl;

        } else if(opcion == 2) {
            string nombre, apellido, sexo, titulo;
            int edad, noCedulaProfesional;

            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Apellido: ";
            getline(cin, apellido);
            cout << "Sexo: ";
            getline(cin, sexo);
            cout << "Edad: ";
            cin >> edad;
            cin.ignore(); // Limpiar el buffer de entrada
            cout << "Título o Profesión: ";
            getline(cin, titulo);
            cout << "No. de Cédula Profesional: ";
            cin >> noCedulaProfesional;
            cin.ignore(); // Limpiar el buffer de entrada

            Profesor profesor(nombre, apellido, sexo, edad, titulo, noCedulaProfesional);
            profesores.push_back(profesor);
            cout << "Profesor agregado exitosamente!" << endl;

        } else if(opcion == 3) {
            string nombreMateria;
            int creditos;
            size_t seleccionProfesor;

            if(profesores.empty()) {
                cout << "No hay profesores disponibles. Por favor, agregue un profesor primero." << endl;
                continue;
            }

            cout << "Nombre de la materia: ";
            getline(cin, nombreMateria);
            cout << "Número de créditos: ";
            cin >> creditos;
            cin.ignore(); // Limpiar el buffer de entrada

            cout << "Seleccione un profesor para esta materia:" << endl;
            for(size_t i = 0; i < profesores.size(); i++) {
                cout << i+1 << ". " << profesores[i].getNombreCompleto() << endl;
            }
            cout << "Opción: ";
            cin >> seleccionProfesor;
            cin.ignore(); // Limpiar el buffer de entrada

            if(seleccionProfesor > 0 && seleccionProfesor <= profesores.size()) {
                Materia materia(nombreMateria, creditos, profesores[seleccionProfesor - 1]);
                materiasDisponibles.push_back(materia);
                cout << "Materia agregada exitosamente!" << endl;
            } else {
                cout << "Selección inválida." << endl;
            }

        } else if(opcion == 4) {
            cout << "Lista de Alumnos:" << endl;
            for(const auto& alumno : alumnos) {
                alumno.mostrarAlumno();
            }

        } else if(opcion == 5) {
            cout << "Lista de Profesores:" << endl;
            for(const auto& profesor : profesores) {
                profesor.mostrarProfesor();
            }

        } else if(opcion == 6) {
            cout << "Lista de Materias:" << endl;
            for(const auto& materia : materiasDisponibles) {
                materia.mostrarMateria();
            }

        } else if(opcion == 7) {
            cout << "Saliendo del programa..." << endl;
            break;

        } else {
            cout << "Opción no válida" << endl;
        }
    }

    return 0;
}
