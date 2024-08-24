#include <iostream>
using namespace std;

double sumar(double a, double b) {
    return a + b;
}

double restar(double a, double b) {
    return a - b;
}

double multiplicar(double a, double b) {
    return a * b;
}

double dividir(double a, double b) {
    if (b != 0)
        return a / b;
    else {
        cout << "Error: Divisi�n por cero!" << endl;
        return 0;
    }
}

typedef double (*Operador)(double, double);

int main() {
    Operador operaciones[4] = { sumar, restar, multiplicar, dividir };
    double num1, num2;
    int opcion;
    cout << "Ingrese el primer n�mero: ";
    cin >> num1;
    cout << "Ingrese el segundo n�mero: ";
    cin >> num2;
    cout << "Seleccione la operaci�n: " << endl;
    cout << "0: Sumar" << endl;
    cout << "1: Restar" << endl;
    cout << "2: Multiplicar" << endl;
    cout << "3: Dividir" << endl;
    cin >> opcion;
    if (opcion >= 0 && opcion < 4) {
        double resultado = operaciones[opcion](num1, num2);
        cout << "El resultado es: " << resultado << endl;
    }
    else {
        cout << "Opci�n no v�lida." << endl;
    }
    return 0;
}
