#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct ventas{
	int producto;
	float descuento;
	float precio;
	int unidades;
	float totalventas;
};

void venta();
void reporte();

int main(){
	
	venta();
}
void venta(){
	int producto;
	float descuento;
	float precio;
	int unidades;
	float totalventas;
	string s;
	
	cout<<"ingrese el tipo de pizza que desea: "<<endl;
	cout<<"1. pizza grande    Q80    10% descuento"<<endl;
	cout<<"2. pizza familiar  Q115   15% descuento"<<endl;
	cout<<"3. pizza fiesta    Q100   20% descuento"<<endl;
	cin>>producto;
	cout<<"indique la cantidad a comprar: "<<endl;
	cin>>unidades;
	
	if(producto==1){
		descuento = 0.10;
		precio = 80;
		totalventas=(precio-(descuento*precio))*unidades;
	}
	else if(producto==2){
		descuento = 0.15;
		precio = 115;
		totalventas=(precio-(descuento*precio))*unidades;
	}
    else if(producto==3){
		descuento = 0.20;
		precio = 100;
		totalventas=(precio-(descuento*precio))*unidades;
	}
	cout<<"producto:"<<producto<<"\tdescuento:"<<descuento<<"\tprecio:"<<precio<<"\tunidades:"<<unidades<<"\ttotal de la venta:"<<totalventas<<endl;
    ofstream archivo;
	
	try{
		archivo.open("pizza.txt",ios::app);
		archivo<<producto<<"\t\t"<<descuento<<"\t\t"<<precio<<"\t\t"<<unidades<<"\t\t"<<totalventas<<endl;
		archivo.close();
	}	
	catch(exception X){
		cout<<"error"<<endl;
	}
	
	cout<<"\nventas actuales"<<endl;
	cout<<"Tipo\t"<<"Producto\t"<<"Descuento\t"<<"Unidades\t"<<"Precio\t"<<"Total venta\t"<<endl;
	ifstream leerarchivo;
	try{
		leerarchivo.open("pizza.txt",ios::in);
		while(getline(leerarchivo,s))
		cout<<s<<endl;
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"error"<<endl;
	}	
}

void reporte(){
	
	ifstream nuevo;
	float totalp,desc,produc,unid,totalventa=0;
	float sumat=0;
	float totalp1;
	float totalp2;
	float totalp3;
	
	try{
		nuevo.open("pizza.txt",ios::in);
		
		while(nuevo>>totalp>>desc>>produc>>unid>>totalventa){
			
			sumat= totalventa+sumat;
			if(totalp==1)
			totalp1+=totalventa;
			else if(totalp==2)
			totalp2+=totalventa;
			else if(totalp==3)
			totalp3+=totalventa;
		}
		nuevo.close();
		
		cout<<setprecision(5)<<"Total de Ventas:          "<<sumat<<endl;
		cout<<"Desgloce por producto:  "<<endl;
		cout<<setprecision(5)<<" Pizza Grande   "<<totalp1<<" - % sobre el total: "<<setprecision(3)<<totalp1*100/sumat<<endl;
		cout<<setprecision(5)<<" Pizza Familiar "<<totalp2<<" - % sobre el total: "<<setprecision(3)<<totalp2*100/sumat<<endl;
		cout<<setprecision(5)<<" Pizza Fiesta   "<<totalp3<<" - % sobre el total: "<<setprecision(3)<<totalp3*100/sumat<<endl;
	}
	catch(exception X){
		cout<<"error"<<endl;
		exit(1);
	}
}










