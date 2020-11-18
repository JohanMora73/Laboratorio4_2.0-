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

int Enrutador::DijKstra(int **matriz,char **Matriz2,int menor, int i,char *definitivos)
{
    char Nd=definitivos[i],D;
    int k=0,suma,men2=101;
    bool resp=false, resp2=false;
    //cout<<"Yes"<<endl;
    for(it=router.begin();it!=router.end();it++){
        if(i==0){
            if(it->second==-1){
                matriz[k][i]=-1;
                Matriz2[k][i]='-';
            }
            else{
                //if(menor==0) menor=it->second;
                if(menor>it->second && it->second!=0) menor=it->second;D=it->first;
                Matriz2[k][i]=Nd;
                matriz[k][i]=(it->second);
            }
        }
        else{
            for(int j=0;j<i;j++){
                if(it->first==definitivos[j]){
                    resp=true;
                    break;
                }
                else resp=false;

            }
            for(int j=0;j<=i;j++){
                if(it->first==definitivos[j]){
                    resp2=true;
                    break;
                }
                else resp2=false;
            }
            if(resp==true || matriz[k][i-1]==0 || matriz[k][i-1]==-2){
                matriz[k][i]=-2;
                Matriz2[k][i]='-';
            }
            else if(it->second==-1){
                if(matriz[k][i-1]!=-1){
                    matriz[k][i]=matriz[k][i-1];
                    Matriz2[k][i]=Matriz2[k][i-1];
                    if(matriz[k][i]<men2 && resp2==false){
                        men2=matriz[k][i];
                        D=it->first;
                        //cout<<men2<<D<<":("<<i<<endl;
                    }
                }
                else{
                    matriz[k][i]=-1;
                    Matriz2[k][i]='-';
                }
            }

            else{
                suma=0;
                suma=it->second+menor;
                if(suma<matriz[k][i-1] || matriz[k][i-1]==-1){
                    matriz[k][i]=suma;
                    Matriz2[k][i]=Nd;
                    if(suma<men2 && resp2==false){
                        men2=suma;
                        D=it->first;
                    }
                }
                else{
                    matriz[k][i]=matriz[k][i-1];
                    Matriz2[k][i]=Matriz2[k][i-1];
                    if(matriz[k][i]<men2 && resp2==false){
                        men2=matriz[k][i];
                        D=it->first;
                    }
                }


            }
        }
        k+=1;
    }
    //cout<<"menor: "<<menor<<endl;
    definitivos[i+1]=D;
    if(i!=0){
        menor=men2;
    }
    return menor;
}


