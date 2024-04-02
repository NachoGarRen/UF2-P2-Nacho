#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string toLowercase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    map<string, int> listaCompra;
    char opcion;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Insertar producto" << endl;
        cout << "2. Visualizar lista de la compra" << endl;
        cout << "3. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1': {
            string producto;
            cout << "Ingrese el nombre del producto: ";
            cin >> producto;

            string productoLowerCase = toLowercase(producto);

            auto it = listaCompra.find(productoLowerCase);
            if (it != listaCompra.end()) {
                cout << "El producto ya esta en la lista. ¿Desea modificar la cantidad? (s/n): ";
                char respuesta;
                cin >> respuesta;
                if (respuesta == 's' || respuesta == 'S') {
                    int nuevaCantidad;
                    cout << "Ingrese la nueva cantidad: ";
                    cin >> nuevaCantidad;
                    it->second = nuevaCantidad;
                    cout << "Cantidad modificada exitosamente." << endl;
                }
            }
            else {
                int cantidad;
                cout << "Ingrese la cantidad: ";
                cin >> cantidad;
                listaCompra[productoLowerCase] = cantidad;
                cout << "Producto agregado a la lista." << endl;
            }
            break;
        }
        case '2': {
            cout << "\nLista de la compra:" << endl;
            if (listaCompra.empty()) {
                cout << "La lista de la compra esta vacia." << endl;
            }
            else {
                for (const auto& par : listaCompra) {
                    cout << par.first << ": " << par.second << endl;
                }
            }
            break;
        }
        case '3':
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != '3');
}
