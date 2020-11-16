#include "red.h"


void Red::agregar_nuevo_nodo(char nombre)     //Agrega a la tabla un nodo ingresado por consola
{
    Enrutador router;
    char name;
    int costo;
    if(net.find(nombre)==net.end()){     //Se verifica que el nodo no exista
        router.Agregar_Enlace(nombre,0);  //Se agrega el enlace con sigo mismo
        for(it=net.begin();it!=net.end();it++){
            it->second.Agregar_Enlace(nombre,-1); //Se agrega el nombre del nuevo nodo con valor -1
            router.Agregar_Enlace(it->first,-1);   //Se agrega la clave de cada objeto perteneciente a net como un enlace de costo -1
        }

    do{
        cout<<"Ingrese el nombre del nodo, si desea terminaar de ingresar enlaces ingrese simbolo %"<<endl;
        cin>>name;
        if(name!='%'){
            cout<<"Ingrese el costo del enlace"<<endl;
            cin>>costo;
            if(router.Modificar_Enlace(name,costo)==false) cout<<"El nodo al que se desea conectar no existe"<<endl;
            else net[name].Modificar_Enlace(nombre,costo);
        }
    }while(name!='%');
    net.insert(pair<char ,Enrutador>(nombre,router));
    }
    else cout<<"El nodo que desea agregar ya existe";
}

void Red::Eliminar_nodo(char nombre)
{
    Enrutador router;
    if(net.find(nombre)!=net.end()){     //Se verifica que el nodo exista
        net.erase(nombre);
        for(it=net.begin();it!=net.end();it++){
            it->second.Eliminar_Enlace(nombre);
        }
    }
    else cout<<"El nodo que desea eliminar no existe";
}

void Red::Editar_Nodo(char nombre)
{
    Enrutador router;
    char name;
    int costo;
    short resp;
    if(net.find(nombre)!=net.end()){     //Se verifica que el nodo exista
        cout<<"Ingrese el enlace a editar seguido del costo"<<endl;
        cin>>name>>costo;
        net[nombre].Modificar_Enlace(name,costo);
        net[name].Modificar_Enlace(nombre,costo);
    }
    else cout<<"El nodo que desea editar no existe";
}

void Red::Leer_Archivo(string archivo)
{
    char nombre,nodo1,nodo2;
    int costo;
    string texto,c,l;
    Enrutador router;
    ifstream textoArch;
    textoArch.open(archivo,ios::in); //Abriendo en modo lectura
    if(textoArch.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    while(!textoArch.eof()){//Mientras no sea el final del archivo
        c="";
        getline(textoArch,texto);
        nodo1=texto[0];
        nodo2=texto[2];
        for(int i=4;i<texto.length();i++){
            l=texto[i];
            c.append(l);
        }
        costo=atoi(c.c_str());     //se convierte el costo a entero
        cout<<"Nodo 1: "<<nodo1<<" Nodo 2: "<<nodo2<<" Costo: "<<costo<<endl;
    }

}

void Red::Imprimir_TEnrutamiento(char nombre)
{
    net[nombre].Imprimir();
}

void Red::Matriz_Adyasencia()
{
    int n=0;
    cout<<'\t';
    for(it=net.begin();it!=net.end();it++){
        n+=1;
        cout<<it->first<<'\t';
    }
    cout<<endl;
    for(it=net.begin();it!=net.end();it++){
        cout<<it->first<<'\t';
        it->second.Matriz_Ady();
        cout<<endl;
    }
}