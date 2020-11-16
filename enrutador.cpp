#include "enrutador.h"

bool Enrutador::Agregar_Enlace(char nombre,int valor)
{
    bool ts=false;
    if(router.find(nombre)==router.end()){
        router.insert(pair<char,int>(nombre,valor));
        ts=true;
    }
    return ts;
}

bool Enrutador::Eliminar_Enlace(char nombre)
{
    bool ts=false;
    if(router.find(nombre)!=router.end()){
        router.erase(nombre);
        ts=true;
    }
    return ts;
}

bool Enrutador::Modificar_Enlace(char nombre, int value)
{
    bool ts=false;
    if(router.find(nombre)!=router.end()){
        router[nombre]=value;
        ts=true;
    }
    return ts;
}

void Enrutador::Imprimir()
{
    for(it=router.begin();it!=router.end();it++){
        cout<<"Enlace: "<<it->first<<" costo: "<<it->second<<endl;
    }
}

void Enrutador::Matriz_Ady()
{
    for(it=router.begin();it!=router.end();it++){
        cout<<it->second<<'\t';
    }
}
