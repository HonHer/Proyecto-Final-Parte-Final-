#include <iostream>
#include <stdio.h>  
#include <string.h> 
#include <cstdio>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;
const char *nombe_archivo = "proyecto.dat";
const char *archivo_prov= "prov.dat";

struct Proyecto{
	int codigo;
	char ing[50];
	char esp[50];
	char concepto[2000];
};
	
	
	void ingresar();
	void abrir();
 	void modificar();
 	void buscar();
 	void eliminar();
	void traduc();
	void gotoxy(int x,int y);
	void dibujarCuadro(int x1,int y1,int x2,int y2);
	
	void traductor (string& palabras, string busca, string rem){
		int pos = palabras.find(busca);
		while  (pos != -1){
		palabras.replace(pos, busca.size(), rem);
		pos = palabras.find(busca, pos + rem.size());
		}
	}
	
int main (){
 	int a=40,b=15, menu;
	string frase;
	
 	
 	do{
 		
		system("cls");
		
		system("COLOR F0");
		dibujarCuadro(0,0,78,24);
		dibujarCuadro(16,1,62,16);
	 	
		gotoxy(20,3);cout<<"                 MENU"<<endl<<endl;
		gotoxy(20,5);cout<<"1. INGRESAR REGISTRO"<<endl;
		gotoxy(20,6);cout<<"2. ABRIR BASE DE DATOS"<<endl;
		gotoxy(20,7);cout<<"3. MODIFICAR REGISTRO"<<endl;
		gotoxy(20,8);cout<<"4. ELIMINAR REGISTRO"<<endl;
		gotoxy(20,9);cout<<"5. BUSCAR REGISTRO"<<endl;
		gotoxy(20,10);cout<<"6. TRADUCTOR"<<endl;
		gotoxy(20,11);cout<<"0. SALIR"<<endl;
		
		gotoxy(22,13);cin>>menu;
		system("cls");
		
		if (menu==1){
		ingresar();		
		}
		else if(menu==2){
		abrir();	
		}	 
		else if(menu==3){
		modificar();		
		}
		else if(menu==4){
		eliminar();
		} 
		else if(menu==5){
		buscar();
    	}
    	else if(menu==6){
    		
    		system("cls");
    		system("mode con: cols=80 lines=25");
			system("COLOR F0");



dibujarCuadro(0,0,78,100);//Cuadro grande
dibujarCuadro(1,1,77,3);//Cuadro del titulo
dibujarCuadro(38,10,77,99);//Cuadro del titu
dibujarCuadro(1,10,77,99);//Cuadro del titulo
dibujarCuadro(4,11,35,13);
dibujarCuadro(42,11,74,13);
gotoxy(16,2); cout << "               T R A D U C T O R";
gotoxy(3,6); cout <<"INSTRUCCIONES: Agregue el codigo fuente del lado izquierdo, se le mostrara";
gotoxy(3,7); cout <<"la traduccion del lado derecho, para indicar que termino de ingresar el ";
gotoxy(3,8); cout <<"codigo a traducir escriba un punto (.)";
gotoxy(10,12); cout << "INGRESE CODIGO FUENTE";
gotoxy(53,12); cout << "TRADUCCION";

do{
		gotoxy(3,b);getline(cin,frase);
		
		
		traductor(frase, "if ","si ");
		traductor(frase, "void ","vacio ");
		traductor(frase, "and ","y ");
		traductor(frase, "int ","entero ");
		traductor(frase, "main ","principal ");
		traductor(frase, "string","cadena");
		traductor(frase, "cout","escribir");
		traductor(frase, "cin","leer ");
		traductor(frase, "float","flotadora");
		traductor(frase, "for","por");
		traductor(frase, "friend","amigo");
		traductor(frase, "goto","ir a");
		traductor(frase, "if","si");
		traductor(frase, "inline","en_linea");
		traductor(frase, "int","en_t");
		traductor(frase, "long","largo");
		traductor(frase, "mutable","mutable");
		traductor(frase, "namespace","espacio_de_nombres");
		traductor(frase, "new","nuevo");
		traductor(frase, "operator","operador");
		traductor(frase, "asm","asm");
		traductor(frase, "auto","auto");
		traductor(frase, "bool","booleana");
		traductor(frase, "break","romper");
		traductor(frase, "else","si no");
		traductor(frase, "case","caso");
		traductor(frase, "catch","capturar");
		traductor(frase, "char","cadena");
		traductor(frase, "class","clase");
		traductor(frase, "const","constante");
		traductor(frase, "const_cast","caso_constante ");
		traductor(frase, "private","privado");
		traductor(frase, "protected","protegido");
		traductor(frase, "public","publico");
		traductor(frase, "register","registro");
		traductor(frase, "Reinterpret_cast","Reinterpretar_Caso");
		traductor(frase, "return","regreso");
		traductor(frase, "short","pequeño");
		traductor(frase, "signed","firmado");
		traductor(frase, "sizeof","tamaño_de");
		traductor(frase, "static","estatico");
		traductor(frase, "static_cast","elenco_estatico");
		traductor(frase, "struct","estructura");
		traductor(frase, "switch","cambiar");
		traductor(frase, "template","planilla");
		traductor(frase, "this","esto");
		traductor(frase, "throw","lanzar");
		traductor(frase, "true","verdadero");
		traductor(frase, "try","tratar");
		traductor(frase, "typedef","tipo_def");
		traductor(frase, "typename","tipo_nombre");
		traductor(frase, "union","union");
		traductor(frase, "unsigned","no_firmado");
		traductor(frase, "using","utilizando");
		traductor(frase, "virtual","virtual");
		traductor(frase, "void","vacio");
		traductor(frase, "volatile","volatil");
		traductor(frase, "while","mientras");	
		traductor(frase, "main", "principal");
		traductor(frase, "exit", "salir");
		traductor(frase, "endl", "fin l");
				
		gotoxy (a,b); cout << frase<<" "<< endl;
		b+=1;
    	}while(frase != ".");
    		
    		
		}
    }while(menu!=0);
    system("pause>null");
	return 0;	
}

//INGRESAR REGISTRO 
void ingresar(){
	
	char otro;
	FILE* archivo = fopen(nombe_archivo, "ab");
		
		 Proyecto proyecto;
		 string ingl,espa, concep;
		do{
			fflush(stdin);
			cout <<"___________________________________________________\n"<<endl;
			cout<<"  INGRESE CODIGO: ";
			cin>>proyecto.codigo;
        	cin.ignore();
			
			cout<<"  INGRESE PALABRA:       ";
			getline(cin,ingl);
    		strcpy(proyecto.ing, ingl.c_str()); 
			
			cout<<"  INGRESE TRADUCCION:    ";
			getline(cin,espa);
			strcpy(proyecto.esp, espa.c_str()); 
		
			cout<<"  INGRESE FUNCIONALIDAD: ";
			getline(cin,concep);
			strcpy(proyecto.concepto, concep.c_str());
		
		fwrite( &proyecto, sizeof(Proyecto), 1, archivo );
		
			cout<<" \n\n DESEA AGREGAR OTRO REGISTRO S/N : ";
			cin>>otro;
			system("cls");
		} while((otro=='S') || (otro=='s') );
		
	
	fclose(archivo);
	system("cls");
}

//ABRIR MENU
void abrir(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Proyecto proyecto;
	int cont = 0;
	fread ( &proyecto, sizeof(Proyecto), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout<<"                     BASE DE DATOS                                  "<<endl;
		do{
		cout <<"____________________________________________________________________"<<endl;
		cout <<"       ID:           "<<cont<<endl<<"CODIGO:       "<<proyecto.codigo<<endl<<cont<<"PALABRA:      "<<proyecto.ing<<endl<<"TRADUCCION:   "<<proyecto.esp<<endl<<"DEFINICION:   "<<proyecto.concepto<<endl;
        
        
		fread ( &proyecto, sizeof(Proyecto), 1, archivo );
		cont++;
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
		system("pause");
		system("cls");
	}

void modificar(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int busca;
		string  ingle, espa, concep;	
    	Proyecto proyecto;
    		cout <<"___________________________________________________"<<endl;
			cout <<"   INGRESE EL ID DE REGISTRO A MODIFICAR: ";
    		cin >> busca;
    		cout <<"___________________________________________________\n"<<endl;
    		fseek ( archivo, busca * sizeof(Proyecto), SEEK_SET ); 
	
			cout<<"INGRESE CODIGO: ";
			cin>>proyecto.codigo;
        	cin.ignore();
			
			cout<<"INGRESE PALABRA:       ";
			getline(cin,ingle);
    		strcpy(proyecto.ing, ingle.c_str()); 
			
			cout<<"INGRESE TRADUCCION:    ";
			getline(cin,espa);
			strcpy(proyecto.esp, espa.c_str()); 
		
			cout<<"INGRESE FUNCIONALIDAD: ";
			getline(cin,concep);
			strcpy(proyecto.concepto, concep.c_str());
		
		fwrite( &proyecto, sizeof(Proyecto), 1, archivo );
		
	fclose(archivo);
		cout<<"\n\n";
		abrir();
		system("pause");
}

//BUSCAR REGISTRO	

void buscar(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	
	int busca;
	
	int cont=0;
	Proyecto proyecto;
	fread ( &proyecto, sizeof(Proyecto), 1, archivo );
	cout<<"___________________________________________________"<<endl;
	cout<<"                   BASE DE DATOS                                  "<<endl;
		
		cout <<"___________________________________________________"<<endl;
		cout <<"       ID:                PALABRA:   "<<endl;
		cout <<"___________________________________________________"<<endl<<endl;
		do{
		cout <<"        "<<cont<<"                 "<<proyecto.ing<<endl;
        
        
		fread ( &proyecto, sizeof(Proyecto), 1, archivo );
		cont++;
		} while (feof( archivo ) == 0);
	
	cout <<"___________________________________________________"<<endl;
	cout <<"\n\n___________________________________________"<<endl;
	cout<<"INGRESE ID DE REGISTRO A BUSCAR: ";
	cin>>busca;
	cout <<"___________________________________________"<<endl;
	cout<<"____________ ID: "<<busca<<" _______________"<<endl;
	fseek ( archivo, busca * sizeof(Proyecto), SEEK_SET );
	
	
	
    fread ( &proyecto, sizeof( Proyecto ), 1, archivo );

    	cout<<"   CODIGO:     "<<proyecto.codigo<<endl;
	   	cout<<"   PALABRA:    "<<proyecto.ing<<endl;
	   	cout<<"   TRADUCCION: "<<proyecto.esp<<endl;
	   	cout<<"   DEFINICION: "<<proyecto.concepto<<endl<<endl;
	cout <<"___________________________________________"<<endl;
	fclose(archivo);
	system("pause");
	
}

//ELIMINAR REGISTRO
void eliminar(){

	FILE* archivo = fopen(nombe_archivo, "rb");
	FILE* archivop = fopen(archivo_prov, "ab");
	
	int indice=0,pos=0,cod=0;
	
	dibujarCuadro(0,0,78,24);
	dibujarCuadro(16,1,62,16);
	gotoxy(20,4);cout<<"INGRESE CODIGO DE REGISTRO A ELIMINAR: ";
	cin>>cod;
	
	Proyecto proyecto;
	
	fread ( &proyecto, sizeof(Proyecto), 1, archivo );
	
		do{
			
			if (proyecto.codigo == cod){
			gotoxy(25,8);cout<<"ELIMINADO";
			gotoxy(22,10);system("pause");
			}
			else {
			fwrite( &proyecto, sizeof(Proyecto), 1, archivop );
		}
		fread ( &proyecto, sizeof(Proyecto), 1, archivo );
		
		} while (feof( archivo ) == 0);
		
	    		
		fclose(archivo);
		fclose(archivop);
	    
		remove("proyecto.dat");
		rename("prov.dat","proyecto.dat");
		cout<<"\n\n";
		abrir();
		system("pause");
}

void dibujarCuadro(int x1,int y1,int x2,int y2){
    int i;
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "Ä";
		gotoxy(i,y2); cout << "Ä";
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout << "³";
		gotoxy(x2,i); cout << "³";
    }
    
    gotoxy(x1,y1); cout << "Ú";
    gotoxy(x1,y2); cout << "À";
    gotoxy(x2,y1); cout << "¿";
    gotoxy(x2,y2); cout << "Ù";
}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}
