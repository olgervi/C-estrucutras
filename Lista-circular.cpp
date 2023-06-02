#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct nodoNumero
{
	int numero;
	nodoNumero *sig;
};
typedef struct nodoNumero *lista;

nodoNumero *crearNodo(int num)
{
	nodoNumero *aux = new (struct nodoNumero);
	aux->numero=num;
	aux->sig=NULL;
	return aux; 
}

void AgregarFinal(lista &cab, int num)
{
	nodoNumero *nuevo;
	lista aux;
	nuevo=crearNodo(num);
		if(cab==NULL)
		{
			cab=nuevo;
			nuevo->sig=cab;
		}
		else
		{
			aux=cab;
			while(aux->sig!=cab)
			aux=aux->sig;

			aux->sig=nuevo;
			nuevo->sig=cab;
		}
}

void ListarNumeros(lista cab)
{
	
	lista aux;
	if(cab==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cab;
		do
		{
			cout <<"[ "<<aux->numero<<" ]";
			aux=aux->sig;
		}
		while(aux!=cab);	
	}
}

int main()
{
	lista LC = NULL;
	AgregarFinal(LC,25);
	AgregarFinal(LC,35);
	AgregarFinal(LC,45);
	AgregarFinal(LC,85);
	ListarNumeros(LC);
	system("Pause");
}




