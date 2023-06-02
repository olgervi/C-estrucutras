#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct nodoNumero 
{
	int numero;
	nodoNumero *sig;
	nodoNumero *ant;
} ;
typedef struct nodoNumero *lista;

nodoNumero *crearNodo(int num)
{
	nodoNumero *aux = new (struct nodoNumero);
	aux->numero=num;
	aux->sig=NULL;
	aux->ant=NULL;
	return aux;
}

void agregarInicio(lista &cab,int numero)
{
	nodoNumero *nuevo;
	nuevo=crearNodo(numero);
	
	if (cab==NULL)
	cab=nuevo;
	else
	{
		nuevo->sig=cab;
		cab->ant=nuevo;
		cab=nuevo;
	}
}

void agregarFinal(lista &cab,int num)
{
	lista aux;
	nodoNumero *nuevo;
	nuevo=crearNodo(num);
	
	if (cab==NULL)
	cab=nuevo;
	else
	{
		aux=cab;
		while(aux->sig!=NULL)
		aux=aux->sig;
	
		aux->sig=nuevo;
		nuevo->ant=aux;	
	}
}

void listarNumeros(lista cab)
{
	lista aux;
	
	if(cab==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cab;
		while(aux!=NULL)
		{
			cout <<" [ "<<aux->numero<<" ] ";
			aux=aux->sig;
		}
	}	
}

void listarInvertido(lista cab)
{
	lista aux;
	
	if(cab==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cab;
		while(aux->sig!=NULL)
		aux=aux->sig;
		
		while(aux!=NULL)
		{
		    cout <<" [ "<<aux->numero<<" ] ";
			aux=aux->ant;	
		}
	}	 
}

int main()
{
	lista LD=NULL;
	
	agregarFinal(LD,34);
	agregarFinal(LD,35);
	agregarFinal(LD,36);
	agregarInicio(LD,33);
	agregarInicio(LD,32);
	agregarInicio(LD,31);
	listarNumeros(LD);
	cout <<endl;
	listarInvertido(LD);
	system("pause");
}
