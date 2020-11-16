#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

class Enrutador
{
private:
    map<char,int> router;
    map<char,int>:: iterator it;
public:
    bool Agregar_Enlace(char nombre,int valor);
    bool Eliminar_Enlace(char nombre);
    bool Modificar_Enlace(char nombre,int value);
    void Imprimir();
    void Matriz_Ady();
};

#endif // ENRUTADOR_H
