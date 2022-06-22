/* Autor: Andrea Alejandra Vargas Pucheta
	 Fecha de creación: 30/12/2020
	 Fecha de modicación: 28/01/2021
	 Descripción: Programa para guardar datos de un evento
*/
#include <iostream>
using namespace std;
#include "Evento.cpp"

void menuPrincipal ();
void despedida ();

int main(){
		Evento eventos[10];
		Evento even1;
		int eventosRegistrados=0;
		int opcion;
		string nuevoEvento;
		string encargadoEvento;
		string lugarEvento;
		string inciaEvento;
		string duracionEvento;
		string codigo01;
		string ingresarCod;
		bool existir;
		char repuesta = 's';
	do{
		menuPrincipal ();
	    cout<<"> ";
			cin>>opcion;
			cin.ignore();
		switch(opcion){
			case 1:
				if (eventosRegistrados<=10){
	            cout<<endl<<"Registrar un nuevo evento"<<endl;
	                //Solo es ingresar y guardar la variable
	                cout<<"Nombre del evento"<<endl;
	                getline(cin,nuevoEvento); cout<<endl;

					cout<<"Nombre del responsable de la organizaci\242n"<<endl;
	                getline(cin,encargadoEvento); cout<<endl;

					cout<<"Lugar del evento"<<endl;
	                getline(cin,lugarEvento); cout<<endl;

					cout<<"Fecha de inicio (dd/mm/aa)"<<endl;
	                getline(cin,inciaEvento); cout<<endl;

					cout<<"D\241as de duraci\242n"<<endl;
	                getline(cin,duracionEvento); cout<<endl;


				    //Mostrar los datos anteriores
				    cout<<"Retificar Valores"<<endl;
				    cout<<"Nombre Del Evento: "<<nuevoEvento<<endl;
				    cout<<"Nombre del responsable de la organizaci\242n: "<<encargadoEvento<<endl;
				    cout<<"Lugar del evento: "<<lugarEvento<<endl;
					cout<< "Fecha de inicio: "<<inciaEvento<<endl;
					cout<<"D\241as de duraci\242n: "<<duracionEvento<<endl;

					//Validar los datos ingresados
					cout<<"�Estan correcto los Datos? "<<"(s/n)"<<endl;
					cin>>repuesta;
					cin.ignore();
					if(repuesta =='s'){
	                even1.setNombreEvento(nuevoEvento);
							    even1.setEncargado(encargadoEvento);
							    even1.setLugar(lugarEvento);
							    even1.setFechaInicio(inciaEvento);
							    even1.setDuracion(duracionEvento);
	                eventos[eventosRegistrados]= even1;
				    eventosRegistrados++;

					//Generar el código
				    for(int i=0; i<eventosRegistrados;i++){
				    	eventos[i].setCodigo(eventos[i].generarCodigo());
					}
					cout<<"Se ha generado un c\242digo de busquedad"<<endl;
					for(int i=0; i<eventosRegistrados;i++){
				    	cout<<"No perder este codigo"<<": "<<eventos[i].getCodigo()<<endl;
					}
				    cout<<"Se registro el evento correctamente."<<endl;
				}
				}else{
					cout<<"Ya no tienes m�s acceso a registrar otro evento";
				}
				            break;
			case 2:
			    //Ingresar C�digo a buscar
			    cout<<"Ingrese la c\242digo: ";
			    getline(cin,ingresarCod);
			    existir = false; //Por si es falso o verdadero

			    //Buscar el c�digo y ver si existe
			    for(int i=0;i<eventosRegistrados;i++){
			    	if(eventos[i].getCodigo()==ingresarCod){
			    	existir = true;
			    	cout<<"NOTA: Si no cambiaras un apartado solo dale enter"<<endl;
			    	//Empezar a modificar lo que se necesite
			    	cout<<"Nombre del evento"<<endl;
	                getline(cin,nuevoEvento); cout<<endl;

					cout<<"Nombre del responsable de la organizaci\242n"<<endl;
	                getline(cin,encargadoEvento); cout<<endl;

					cout<<"Lugar del evento"<<endl;
	                getline(cin,lugarEvento); cout<<endl;

					cout<<"Fecha de inicio (dd/mm/aa)"<<endl;
	                getline(cin,inciaEvento); cout<<endl;

					cout<<"D\241as de duraci\242n"<<endl;
	                getline(cin,duracionEvento); cout<<endl;

	                //Si hay un espacio mantener misma informaci�n
					if(nuevoEvento!=""){
	                	eventos[i].setNombreEvento(nuevoEvento);
					}
					if(encargadoEvento!=""){
	                	eventos[i].setEncargado(encargadoEvento);
					}
					if(lugarEvento!=""){
	                	eventos[i].setLugar(lugarEvento);
					}
					if(inciaEvento!=""){
	                	eventos[i].setFechaInicio(inciaEvento);
					}
					if(duracionEvento!=""){
	                	eventos[i].setDuracion(duracionEvento);
					}

					//Mostrar los nuevos y viejos valores
					cout<<"Retificar Valores"<<endl;
				    cout<<"Nombre Del Evento: "<<eventos[i].getNombreEvento()<<endl;
				    cout<<"Nombre del responsable de la organizaci\242n: "<<eventos[i].getEncargado()<<endl;
				    cout<<"Lugar del evento: "<<eventos[i].getLugar()<<endl;
					cout<< "Fecha de inicio: "<<eventos[i].getFechaInicio()<<endl;
					cout<<"D\241as de duraci\242n: "<<eventos[i].getDuracion()<<endl;

					//Hacer el c�digo
				    for(int j=0; j<eventosRegistrados;j++){
				    	eventos[j].setCodigo(eventos[j].generarCodigo());
					}
					cout<<"Se ha generado un c\242digo de busquedad"<<endl;
					//Mostrar el c�digo
					for(int k=0; k<eventosRegistrados;k++){
				    	cout<<"No perder este codigo"<<": "<<eventos[k].getCodigo()<<endl;
					}
					}
					}
				//No existe ese c�digo que ingreso
				if(existir==false){
					cout<<"El c\242digo no existe"<<endl;
				}
			       break;
			case 3:
				for(int i=0;i<eventosRegistrados;i++){
			        cout<<"Nombre Del Evento: "<<eventos[i].getNombreEvento()<<endl;
			        cout<<"Nombre del responsable de la organizaci\242n: "<<eventos[i].getEncargado()<<endl;
			        cout<<"Lugar del evento: "<<eventos[i].getLugar()<<endl;
			        cout<< "Fecha de inicio: "<<eventos[i].getFechaInicio()<<endl;
			        cout<<"D\241as de duraci\242n: "<<eventos[i].getDuracion()<<endl;
			        cout<<endl;
			}
				   break;
			case 4:
			        despedida ();
			        break;
			default:
				cout<<"Opci\242n incorrecta. ";
				cout<<"Intente de nuevo"<<endl;
		}
		system("pause");
		system("cls");
	}while(opcion!=4);

	return 0;
}

void menuPrincipal (){
		cout<<"\t \tPrograma que Registra Eventos"<<endl<<endl;
		cout<<"\tEscoga una opci\242n del men\243"<<endl<<endl;
	    cout<<"1. Registra un nuevo evento."<<endl;
	    cout<<"2. Modificar informaci\242n de los eventos."<<endl;
	    cout<<"3. Mostrar eventos registrados."<<endl;
	    cout<<"4. Salir."<<endl;
}

void despedida (){
	cout<<"Gracias por usar este programa. ";
	cout<<"Vuelva pronto"<<endl;
}
