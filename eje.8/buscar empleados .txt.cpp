#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>

using  std::cin;
using  std::cout;
using  std::endl;

using namespace std;

int menu()
{
	system("cls");
	int x;
	cout<<"                 BIENVENIDO"<<endl<<endl;
	cout<<"#1---AGREGAR PERSONAS"<<endl;
	cout<<"#2-------VER PERSONAS"<<endl;
	cout<<"#3----BUSCAR PERSONAS"<<endl;
//	cout<<"#4-MODIFICAR PERSONAS"<<endl;
//	cout<<"#5--ELIMINAR PERSONAS"<<endl;
	cout<<"#0--------------SALIR"<<endl;
	cout<<"Elija una opcion"<<endl;
	cin>>x;
	return x;
}

void agregar(ofstream &es)
{
	system("cls");
	//fflush(stdin);
	string nom;
	string ape;
	string pue;
	int sue;
	int bas;
	int total;
	string cod;
	
	es.open("Personas3.txt", ios::out | ios::app);
	cout<<"Nombre: ";
	cin>>nom;
	cout<<"Apellido: ";
	cin>>ape;
	cout<<"Puesto: ";
	cin>>pue;
	cout<<"Sueldo: ";
	cin>>sue;
	cout<<"Base: ";
	cin>>bas;
	total=sue+bas;
	cout<<"Total: "<<total<<endl<<endl;
	cout<<"Codigo: ";
	cin>>cod;
	//if(verifica(cod))
	es<<nom<<", "<<ape<<", "<<pue<<", "<<sue<<", "<<bas<<", "<<total<<", "<<cod<<"\n";
	es.close();		
}

void verRegistro(ifstream &Lec)
{	system("cls");
	string Nom;
	string Ape;
	string Pue;
	string Sue;
	string Bas;
	string Total;
	string Cod;	
	Lec.open("archivo.txt", ios::in);
	cout<<"-------Personas Guardadas----------"<<endl<<endl;
	Lec>>Nom;
	while(!Lec.eof())
	{
		Lec>>Ape;
		Lec>>Pue;
		Lec>>Sue;
		Lec>>Bas;
		Lec>>Total;
		Lec>>Cod;
		cout<<"----------------------------------"<<endl<<endl;
		cout<<"Nombre--------------------:"<<Nom<<endl;
		cout<<"Apellido------------------:"<<Ape<<endl;
		cout<<"Puesto--------------------:"<<Pue<<endl;
		cout<<"Sueldo--------------------:"<<Sue<<endl;
		cout<<"Base----------------------:"<<Bas<<endl;
		cout<<"Total----------------------:"<<Total<<endl;
		cout<<"Codigo--------------------:"<<Cod<<endl;
		cout<<"----------------------------------"<<endl<<endl;
		Lec>>Nom;
	}
	Lec.close();
	system("pause");
}
void buscarpersona(ifstream &Lec)
{
	system("cls");
	Lec.open("archivo.txt", ios:: in);
	string nom,ape,pue,sue,bas,total,cod,codaux;
	bool encontrado = false;
	cout<<"Ingrese el Codigo"<<endl;
	cin>>codaux;
	Lec>>nom;
	while(!Lec.eof() && !encontrado){
		Lec>>ape;
		Lec>>pue;
		Lec>>sue;
		Lec>>bas;
		Lec>>total;
		Lec>>cod;
		if(cod == codaux){
		cout<<"----------------------------------"<<endl<<endl;
		cout<<"Nombre--------------------:"<<nom<<endl;
		cout<<"Apellido------------------:"<<ape<<endl;
		cout<<"Puesto--------------------:"<<pue<<endl;
		cout<<"Sueldo--------------------:"<<sue<<endl;
		cout<<"Base----------------------:"<<bas<<endl;
		cout<<"Total----------------------:"<<total<<endl;
		cout<<"Codigo--------------------:"<<cod<<endl;
		cout<<"----------------------------------"<<endl<<endl;
		encontrado = true;	
		}
	
	Lec>>nom;	
	}
	Lec.close();
	if(!encontrado)
	cout<<"Dato no encontrado"<<endl;
	system("pause");
	
}

int main ()
{
	ofstream Esc;
	ifstream Lec;
	int op;
	do{
		system("cls");
		op=menu();
		switch(op)
		{
			case 0:{
			
				
				
			}
			break;
			case 1:{
					agregar(Esc);	
			
			}
			break;
			case 2:{
					verRegistro(Lec);		
				
			}
			break;
			case 3:{
					buscarpersona(Lec);
			
			}
			break;
			case 4:{
				
			
			}
			break;
				case 5:{
				
			
			}
			break;	
		}
	}while(op!=0);	
}
