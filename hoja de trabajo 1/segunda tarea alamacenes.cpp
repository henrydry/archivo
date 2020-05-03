#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct ventas{
	int id;
	int mes;
	float vendido;
};

int main(){
	
	int i,n=0;
	float sumat=0,media,mayor;
	string almacen=" ";
	ostringstream ssal;
	ostringstream smes;
	ostringstream smt;
	cout<<"Cuantos datos se almacenaran? "<<endl;
	cin>>n;
	
	ventas venta[n];
	
	for(i=0;i<n;i++){
		cout<<"Ingrese codigo del almacen: "<<endl;
		cin>>venta[i].id;
		cout<<"Ingrese el mes de la venta: "<<endl;
		cin>>venta[i].mes;
		cout<<"Monto vendido: "<<endl;
		cin>>venta[i].vendido;
		
		sumat=sumat+venta[i].vendido;
		system("CLS");
	}
	
	media=sumat/n;
	mayor=media;
	
	for(i=0;i<n;i++){
		
		if(venta[i].vendido>media){
			if(venta[i].vendido>mayor){
			
			ssal << venta[i].id;
			smes << venta[i].mes;
			smt << venta[i].vendido;
			
			almacen=almacen+"Almacen:"+ssal.str()+"\tMes"+smes.str()+"\tMonto:"+smt.str()+" / ";
			
			smes.str("");
			smt.str("");
			ssal.str("");
			smes.clear();
			smt.clear();
			ssal.clear();
			
			mayor=venta[i].vendido;
			}
		}
	}
	
	cout<<"Promedio: "<<media<<endl;
	cout<<"Mayores ventas: "<<almacen.substr(0,almacen.length()-2)<<endl;
system("Pause");
}
