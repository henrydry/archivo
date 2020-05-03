#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

void ingresar();
void leer();
void menu();

int main(){
	
menu();	
}

void menu(){
	
	int i;
	
	cout<<"------------------------------"<<endl;
	cout<<"******* Menu principal ********"<<endl;
	cout<<"1. Ingresar datos de trabajador"<<endl;
	cout<<"2. Ver datos del trabajador "<<endl;
	cout<<"3. Salir"<<endl;
	cout<<"------------------------------"<<endl;
	cout<<"ingrese la opcion"<<endl;
	cin>>i;
	system("pause");
	if(i==1)
	 ingresar();
	 else if(i==2)
	 leer();
	 else if(i==3)
	 	cout<<"ERROR"<<endl;
		else 
			cout<<"error"<<endl;
		
	while(i!=3);	
}

void ingresar(){
	string nombre,apellido;
	int horas,pagom,horase;
	ofstream trabajadores;
	double pagoh,pagohe,igss,pagot;
	
	if(trabajadores.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	system("CLS");
	fflush(stdin);
	cout<<"ingrese el nombre del trabajador: "<<endl;
	getline(cin,nombre,'\n');
	cout<<"ingrese el apellido del trabajador: "<<endl;
	getline(cin,apellido,'\n');
	cout<<"ingrese las horas trabajadas extra"<<endl;
	cin>>horas;
	cout<<"ingrese el pago del mes"<<endl;
	cin>>pagom;
	
		
	pagoh= pagom/30/8;
	if(horas<40){
	
	pagot= pagoh*horas;
	igss= pagom*0.0483;
	
	cout<<"el pago total de horas es de; "<<pagot<<endl;
	cout<<"el pago de igss es de; "<<igss<<endl;
		
	trabajadores.open("salario.txt",ios::app);
	trabajadores<<"nombre"<<setw(10)<<"apellido"<<setw(10)<<"salario"<<setw(10)<<"horas"<<setw(20)<<"pago horas"<<setw(20)<<"pago de igss"<<endl;
	trabajadores<<nombre<<setw(10)<<apellido<<setw(10)<<pagom<<setw(10)<<horas<<setw(20)<<pagot<<setw(20)<<igss<<endl;
	trabajadores.close();
}
	else {
	
	horase=horas-40;
	pagot=(horase*1.5*pagoh)+(pagoh*40);
	igss= pagom*0.0483;
	
	cout<<"el pago total de horas es de; "<<pagot<<endl;
	cout<<"el pago de igss es de; "<<igss<<endl;
		
	trabajadores.open("salario.txt",ios::app);
	trabajadores<<"nombre"<<setw(10)<<"apellido"<<setw(10)<<"salario"<<setw(10)<<"horas"<<setw(20)<<"pago horas"<<setw(20)<<"pago de igss"<<endl;
	trabajadores<<nombre<<setw(10)<<apellido<<setw(10)<<pagom<<setw(10)<<horas<<setw(20)<<pagot<<setw(20)<<igss<<endl;
	trabajadores.close();
}
	system("Pause");
	system("CLS");
	
	while(!trabajadores.eof()){
		menu();
	}

}

void leer(){
	ifstream trabajadores;
	string texto;
	
    trabajadores.open("salario.txt",ios::in);
    if(trabajadores.fail()){
    	cout<<"no se pudo abrir"<<endl;
    	exit(1);
    	
	}
	
	while(!trabajadores.eof()){
		getline(trabajadores,texto);
		cout<<texto<<endl;
	 
	
	}
	 system("Pause");
	 system("CLS");
		menu();
	
    
	trabajadores.close();
	
}
