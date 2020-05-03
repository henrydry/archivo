#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	char modelo,color;
	int edad;
	float precio;
	string s;
	int lineas;
	char lmodelo;
	int ledad;
	float lprecio;
	char lcolor;
	
	cout<<"*******Poliza de vehiculo******"<<endl;
	cout<<"Modelo          Color         Precio"<<endl;
	cout<<"A               Blanco        240.50"<<endl;
	cout<<"                Metalizado    300.00"<<endl;
	cout<<"                Otros         270.50"<<endl;
	cout<<"B               Blanco        300.00"<<endl;
	cout<<"                Metalizado    360.50"<<endl;
	cout<<"                Otros         330.00"<<endl<<endl;
	
	cout<<"******incremento de precio*****"<<endl;
	cout<<"Edad                %Incremento"<<endl;
	cout<<"18 a 31                  25%   "<<endl;
	cout<<"31 a 65                   0%   "<<endl;
	cout<<"mayor a 65               30%   "<<endl;
	
	cout<<"ingrese datos del vehiculo: "<<endl;
	cout<<"ingrese modelo de vehiculo: "<<endl;
	cin>>modelo;
	cout<<"ingrese el color del vehiculo: "<<endl;
	cin>>color;
	cout<<"ingrese edad del conductor: "<<endl;
	cin>>edad;
	
	modelo=toupper(modelo);
	color=toupper(color);
	
	if(modelo=='A'){
		if(color=='B')
		precio=240.50;
		else if(color=='M')
		precio=330;
		else if(color=='O')
		precio=270.50;
	}
	else
	cout<<"modelo incorecto";
	
	if(edad>=18 && edad <31)
	precio=precio+(precio*0.25);
	else if(edad>65 && edad<= 80)
	precio=precio+(precio*0.30);
	
	cout.precision(5);
	cout<<"modelo: "<<modelo<<endl;
	cout<<"color: "<<color<<endl;
	cout<<"edad: "<<edad<<endl;
	cout<<"\n\nPrecio de la poliza a pagar es: "<<precio;
	
	ofstream archivo;
	system("PAUSE");
	
	try {
		archivo.open("poliza.txt",ios::out);
		archivo<<modelo<<"\t"<<color<<"\t"<<edad<<"\t"<<precio<<endl;
		archivo.close();
		}
		
	catch(exception X){
		cout<<"error";
		system("PAUSE");
	}
	system("CLS");
	ifstream narchivo;
	narchivo.open("poliza.txt",ios::in);
	narchivo>>lmodelo>>lcolor>>ledad>>lprecio;
	narchivo.close();
	
	cout<<lmodelo<<lcolor<<ledad<<lprecio;
	
}
