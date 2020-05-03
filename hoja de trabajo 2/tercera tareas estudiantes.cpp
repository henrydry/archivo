#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct estudiante{
	string nombre;
	int id;
	float nota;
};

void menu();
void ingresar(string na);
void leer(string na);

int main(){
	menu();
}

void menu(){
	int respuesta;
	string nombrearch;
	cout<<"Ingrese el nombre del archivo: "<<endl;
	getline(cin,nombrearch);
	
	do{
		system("CLS");
		cout<<"Menu Principal"<<endl;
		cout<<"1. ingresar estudiante"<<endl;
		cout<<"2. ver datos"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Seleccione su respuesta: "<<endl;
		
		cin>>respuesta;
		
		if (respuesta==1){		
			system("CLS");
			ingresar(nombrearch);			
		}
		else if (respuesta==2){		
			system("CLS");
			leer(nombrearch);
		}					
		else if (respuesta==3)
			break;
		else 
			break;
		
	} while(respuesta!=3);
		
	}
	
void ingresar(string na){
	
	int idest;
	string nombreest;
	float notaest;
	
	cout<<"Ingrese codigo de estudiante: "<<endl;
	cin>>idest;
	fflush(stdin);
	cout<<"Ingrese nombre del estudiante: "<<endl;
	getline(cin,nombreest);
	cout<<"Ingrese nota del estudiante: "<<endl;
	cin>>notaest;
	
	ofstream archivo;
	fflush(stdin);
	archivo.open(na.c_str(),ios::app);
	if(archivo.fail()){
		cout<<"error";
		exit(1);
	}
	
	archivo<<nombreest<<"\t"<<idest<<"\t"<<notaest<<endl;
	archivo.close();		
}

void leer(string na){
	
	ifstream archivo;
	fflush(stdin);
	archivo.open("Datos.txt",ios::in);
	
	if(archivo.fail()){
		cout<<"error";
		exit(1);
	}
	
	int linea;
	string n;
	
	while(getline(archivo, n))
	linea++;
	archivo.close();
	
	estudiante array[linea];
	archivo.open(na.c_str(),ios::in); 
	if(archivo.fail()){
		cout<<"error";
		exit(1);
	}
	for(int i = 0; i<linea; i++){
		
		if (!archivo){
			cout<<"error al abrir el archivo"<<endl;
			system("PAUSE");
			break;
		}
		archivo>>array[i].nombre>>array[i].id>>array[i].nota;	
	}
	archivo.close();
	for(int i=0;i<linea;i++){
		cout<<array[i].id<<array[i].nombre<<array[i].nota;	
	}
	system("Pause");
}




















