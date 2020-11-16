#include "red.h"
int main()
{
    Red red;
    short resp, opc;
    string archivo;
    char nombre;
    cout<<"(1) Crear una red interactuando con la consola"<<endl<<"(2) Cargar una red desde un archivo"<<endl<<"(3) Crear una red de manera aleatoria"<<endl;
    cin>>resp;
    switch (resp) {
        case 1:
            while(true){
                cout<<"(1) Agregar un enrutador "<<endl<<"(2) Eliminar un enrutador "<<endl<<"(3) Editar enlaces de un enrutador"<<endl<<"(4) Imprimir tabla de enrutamiento de un nodo"<<endl<<"(5) Imprimir matriz de adyasencia"<<endl<<"(6) Costo desde un enrutador origen a uno destino"<<endl;
                cin>>opc;
                switch (opc) {
                    case 1:
                        cout<<"Ingrese el nombre del enrutador: "<<endl;
                        cin>>nombre;
                        red.agregar_nuevo_nodo(nombre);
                    break;

                    case 2:
                        cout<<"Ingresar el nombre del enrutador a eliminar"<<endl;
                        cin>>nombre;
                        red.Eliminar_nodo(nombre);
                    break;

                    case 3:
                        cout<<"Ingrese el nombre del enrutador a editar"<<endl;
                        cin>>nombre;
                        red.Editar_Nodo(nombre);
                    break;
                    case 4:
                        cout<<"Ingrese el nombre del enrutador a imprimir: "<<endl;
                        cin>>nombre;
                        red.Imprimir_TEnrutamiento(nombre);
                    break;

                    case 5:
                        red.Matriz_Adyasencia();
                    break;

                    default:

                    break;

                }
            }
        break;

        case 2:
            cout<<"Digite el nombre del archivo con la extencion: "<<endl;
            cin>>archivo;
            red.Leer_Archivo(archivo);
        break;

        default:
        break;
    }
    return 0;
}
