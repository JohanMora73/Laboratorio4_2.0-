#ifndef RED_H
#define RED_H
#include "enrutador.h"

class Red
{
private:
    map<char,Enrutador> net;
    map<char,Enrutador> :: iterator it;
public:
     void agregar_nuevo_nodo(char nombre);
     void Eliminar_nodo(char nombre);
     void Editar_Nodo(char nombre);
     void Leer_Archivo(string archivo);
     void Imprimir_TEnrutamiento(char nombre);
     void Matriz_Adyasencia();
     int Contar_Nodos();
     void Dijkstra(int **matriz,char**Matriz2, int n,char *definitivos);
     void red_aleatoria(string nombre_a, char letra, int nodos);
     char generar_letra();
     int generar_numero();
     //void Red_Aleatoria(int nodos, char *Lista1,char *Lista2);
};

#endif // RED_H
