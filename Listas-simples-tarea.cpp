#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct nodoPersona
{
	string nombre;
	string ap1;
	string ap2;
	string correo;
	string pass;
	int cedula;
	nodoPersona *sig;
};
typedef struct nodoPersona *lista;

nodoPersona *crearNodo(string nom,string ap1,string ap2,string correo,
 					   string pass,int cedula)
{
	nodoPersona *aux = new (struct nodoPersona);
	aux->nombre=nom;
	aux->ap1=ap1;
	aux->ap2=ap2;
	aux->correo=correo;
	aux->pass=pass;
	aux->cedula=cedula;
	aux->sig=NULL;
	return aux;
}

void ingresarFinal(lista &cab,string nom, string ap1,string ap2,
						 string correo,string pass, int cedula)
{
	nodoPersona *nuevo;
	lista aux;
	nuevo=crearNodo(nom,ap1,ap2,correo,pass,cedula);
	
	if(cab==NULL)// Lista esta vacia
	cab=nuevo;
	else
	{
		aux=cab;
		while(aux->sig!=NULL)
		aux=aux->sig;
		
		aux->sig=nuevo;
	}
	
}

void agregarInicio(lista &cab, string nom, string ap1, string ap2,
                   string correo, string pass, int cedula)
{
    nodoPersona *nuevo ;
	nuevo=crearNodo(nom, ap1, ap2, correo, pass, cedula);
    
    nuevo->sig = cab; 
    cab = nuevo;
    
}


void modificar(lista &cab, int cedula)
{
    lista aux = cab;
    bool Buscar = false;

    while (aux != NULL)
    {
        if (aux->cedula == cedula)
        {
            // Modificar los parámetros del nodo
            cout << "Ingrese el nuevo nombre: ";
            cin >> aux->nombre;
            cout << "Ingrese el nuevo apellido1: ";
            cin >> aux->ap1;
            cout << "Ingrese el nuevo apellido2: ";
            cin >> aux->ap2;
            cout << "Ingrese el nuevo correo: ";
            cin >> aux->correo;
            cout << "Ingrese el nuevo password: ";
            cin >> aux->pass;
            Buscar = true;
            break;
        }
        aux = aux->sig;
    }

   
}


void Listar(lista cab)
{
	lista aux;
	
	aux=cab;
	while(aux!=NULL)
	{
		cout <<"Nombre: "<<aux->nombre <<endl;
		cout <<"Apellido1: "<<aux->ap1 <<endl;
		cout <<"Apellido2: "<<aux->ap2 <<endl;
		cout <<"Correo: "<<aux->correo <<endl;
		cout <<"Password: "<<aux->pass <<endl;
		cout <<"Cedula: "<<aux->cedula <<endl;
		cout <<"-----------------------------"<<endl;
		aux=aux->sig;
	}
}

void eliminar(lista &cab,int ced)
{
	lista aux,ant;
	
	if(cab==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cab;
		ant=aux;
		
		if(cab->cedula==ced)
		{
			cab=aux->sig;
	      	aux->sig=NULL;
			delete(aux);
			aux=cab;
		}
		else
		{
			while(aux!=NULL)
			{
				if(aux->cedula==ced && aux->sig!=NULL)
				{
					ant->sig=aux->sig;
					aux->sig=NULL;
     				delete(aux);
					aux=cab;
				}
				else
				{
           			if(aux->cedula==ced && aux->sig==NULL)
      				{
						ant->sig=NULL;
						delete(aux);
						aux=cab;
					}
				}
				ant=aux;
				aux=aux->sig;
			}
		}
	}
}





int main()
{
	lista Lista=NULL;
	
	ingresarFinal(Lista,"Luis","Alvarado","Herrera","lah@g.com","123*",1);
	ingresarFinal(Lista,"Ana","Rojas","Perez","arp@g.com","125*",2);
	ingresarFinal(Lista,"Mario","Prado","Rojas","mpr@g.com","126*",3);
	agregarInicio(Lista,"Carlos","Martinez	","Rig","mrig@gmail.com","1238",4);
	Listar(Lista);
	system("Pause");
	
	eliminar(Lista,2);
	system("cls");
	Listar(Lista);
	system("Pause");
	
 	int cedula;
    cout << "Ingrese la cedula del nodo a modificar: ";
    cin >> cedula;
    modificar(Lista, cedula);
	system("cls");
	Listar(Lista);
	system("Pause");
	
	
	
	
}

