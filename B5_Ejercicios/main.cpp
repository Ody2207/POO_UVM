#include <iostream>
#include <vector>
#include <string>

class calcularFiguras{
    int base, altura, radio;
    float area;
    public:
        void areaCirculo(){
            std::cout << "Ingrese el radio del círculo: ";
            std::cin >> radio;
            area = 3.1416 * radio * radio;
            std::cout << "El área del círculo es: " << area << std::endl;
        }
        void areaTriangulo(){
            std::cout << "Ingrese la base del triángulo: ";
            std::cin >> base;
            std::cout << "Ingrese la altura del triángulo: ";
            std::cin >> altura;
            area = (base * altura) / 2;
            std::cout << "El área del triángulo es: " << area << std::endl;
        }
        void areaCuadrado(){
            std::cout << "Ingrese la base del cuadrado: ";
            std::cin >> base;
            area = base * base;
            std::cout << "El área del cuadrado es: " << area << std::endl;
        }
        void areaTrapecio(){
            int base2;
            std::cout << "Ingrese la base mayor del trapecio: ";
            std::cin >> base;
            std::cout << "Ingrese la base menor del trapecio: ";
            std::cin >> base2;
            std::cout << "Ingrese la altura del trapecio: ";
            std::cin >> altura;
            area = ((base + base2) * altura) / 2;
            std::cout << "El área del trapecio es: " << area << std::endl;
        }
        
};
int main (){
   while (true){
int opcion;

    std ::cout << "Que figura quieres calcular" << std::endl;
    std ::cout << "1. Circulo" << std::endl;
    std ::cout << "2. Triangulo" << std::endl;
    std ::cout << "3. Cuadrado" << std::endl;
    std ::cout << "4. Trapecio" << std::endl;
    std ::cout << "5. Salirn" << std::endl;
    std ::cin >> opcion;
    if (opcion == 1){
        calcularFiguras circulo;
        circulo.areaCirculo();
    }
    else if (opcion == 2){
        calcularFiguras triangulo;
        triangulo.areaTriangulo();
    }
    else if (opcion == 3){
        calcularFiguras cuadrado;
        cuadrado.areaCuadrado();
    }
    else if (opcion == 4){
        calcularFiguras trapecio;
        trapecio.areaTrapecio();

   } else if (opcion == 5){
       std::cout << "Saliendo del programa..." << std::endl;
       break;

    
    }
   }
    return 0;
}
