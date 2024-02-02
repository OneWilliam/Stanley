#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>
#include <fstream>
#include <iomanip>
#define tab setw(10) 
#define tab_nombre setw(20)

using namespace std;

class Producto{
	private:
		string nombre;
		string tipo;
		int cantidad;
		float precio;
		float ganancia;
	public:
		Producto();
		Producto(string, string, int, float, float);
		string get(string);
		string getNombre();
		string getTipo();
		int getCantidad();
		float getPrecio();
		float getGanancia();
		void setNombre(string);
		void setTipo(string);
		void setCantidad(int);
		void setPrecio(float);
		void setGanancia(float);
		bool operator== (Producto&);
};

Producto::Producto(){
	nombre = "";
	tipo = "";
	cantidad = 0;
	precio = 0;
	ganancia = 0;
}

Producto::Producto(string nom, string tip, int cant, float pre, float gan){
	nombre = nom;
	tipo = tip;
	cantidad = cant;
	precio = pre;
	ganancia = gan;
}

string Producto::get(string e){
	if (e == "nombre")
		return nombre;
	if (e == "tipo")
		return tipo;
	if (e == "cantidad") 
		return to_string(cantidad);
	if (e == "precio")
		return to_string(precio);
	if (e == "ganancia")
		return to_string(ganancia);
	return "NOTHING";
}

string Producto::getNombre(){
	return nombre;
}

string Producto::getTipo(){
	return tipo;
}

int Producto::getCantidad(){
	return cantidad;
}

float Producto::getPrecio(){
	return precio;
}

float Producto::getGanancia(){
	return ganancia;
}

void Producto::setNombre(string e){
	nombre = e;
}

void Producto::setTipo(string e){
	tipo = e;
}

void Producto::setCantidad(int e){
	cantidad = e;
}

void Producto::setPrecio(float e){
	precio = e;
}

void Producto::setGanancia(float e){
	ganancia = e;
}

bool Producto :: operator== (Producto& e){
	if(this->ganancia == e.ganancia && this->nombre == e.nombre && this->precio == e.precio && this->tipo == e.tipo){
		return true;
	}
	return false;
}

class Inventario{
	protected:
		vector<Producto> Productos;
		string fecha = " ";
	public:
		Inventario();
		vector<Producto> getProductos();
		void setProductos(vector <Producto>);
		string getFecha();
		void AgregarNuevoProducto(Producto);
		void AgregarProducto(string, int);
		void QuitarProducto(string, int);
		void VerTodo();
		void Registrar();
};

Inventario::Inventario(){
}

vector<Producto> Inventario::getProductos(){
	return Productos;
}
void Inventario::setProductos(vector <Producto> nuevo){
	Productos = nuevo;
}

string Inventario::getFecha(){
	return fecha;
}

void Inventario::AgregarNuevoProducto(Producto e){
	Productos.push_back(e);
}

void Inventario::AgregarProducto(string e, int a){
	for(int i = 0; i != Productos.size(); i++){
		if (Productos[i].getNombre() == e){
			Productos[i].setCantidad(Productos[i].getCantidad() + a);
			return;
		}
	}
	cout<<"Ese producto no existe en el inventario, tienes que crearlo"<<endl<<endl;
}

void Inventario::QuitarProducto(string e, int a){
	for(int i = 0; i < Productos.size(); i++){
		if (Productos[i].getNombre() == e){
			if (Productos[i].getCantidad() >= a){
				Productos[i].setCantidad(Productos[i].getCantidad() - a);
				return;
			} else {
				cout<<"No tenemos esa cantidad, elige algo menor."<<endl<<endl;
				return;
			}
		}
	}
	cout<<"Ese producto no existe en el inventario, tienes que crearlo"<<endl<<endl;
}

void Inventario::VerTodo(){
	if (getFecha() != " "){
		cout<<"Inventario con fecha " << getFecha() << " <-- " << endl;
	}
	cout<<"En el inventario tenemos: "<<endl<<endl;
	if (!Productos.empty())
	
	{
		cout << "     " << left << tab_nombre <<  "NOMBRE" << tab  <<  "TIPO" << tab << "CANTIDAD" << tab << "PRECIO" << tab << "GANANCIA" << endl;
		for(int i = 0; i != Productos.size(); i++){
			cout << "[" << i  << "]  "<< left << tab_nombre << Productos[i].getNombre() << tab << Productos[i].getTipo() << tab << Productos[i].getCantidad() << tab << Productos[i].getPrecio() << tab << Productos[i].getGanancia() << endl;
		}
		
	} else {
	cout << "Aun no se han registrando productos..." << endl;
	}
}

void Inventario::Registrar(){
	cout<<"\n Ingrese la fecha en formato DD/MM/AA: ";
	cin>>fecha;
}

class Empleado{
	private:
		string Nombre;
		string Nivel;
		float Sueldo;
	public:
		Empleado(string, string, float);
		string getNombre();
		string getNivel();
		float getSueldo();
		void setNombre(string);
		void setNivel(string);
		void setSueldo(float);
};

Empleado::Empleado(string e, string a, float s){
	Nombre = e;
	Nivel = a;
	Sueldo = s;
}

string Empleado::getNombre(){
	return Nombre;
}

string Empleado::getNivel(){
	return Nivel;
}

float Empleado::getSueldo(){
	return Sueldo;
} 

void Empleado::setNombre(string e){
	Nombre = e;
}

void Empleado::setNivel(string e){
	Nivel = e;
}

void Empleado::setSueldo(float e){
	Sueldo = e;
}

class Tienda{
	private:
		string nombre;
		vector<Inventario> Inventarios;
		vector<Empleado> Empleados;
	public:
		Tienda(string);
		void AsignarEmpleado(Empleado);
		vector<Inventario> getInventarios();
		void setInventarios(vector <Inventario>);
		Inventario getInventarioActual();
		void setInventarioActual(Inventario);
		string getNombre();
		void setNombre(string);
		void Info();
		void VerHistInventarios();
		
};

Tienda::Tienda(string nom){
	Inventario e;
	Inventarios.push_back(e);
	nombre = nom;
}

void Tienda::AsignarEmpleado(Empleado e){
	Empleados.push_back(e);
}

vector<Inventario> Tienda::getInventarios(){
	return Inventarios;
}
void Tienda::setInventarios(vector <Inventario> Nuevo){
	Inventarios = Nuevo;
}

Inventario Tienda::getInventarioActual(){
	return Inventarios.back();
}

void Tienda::setInventarioActual(Inventario e){
	Inventarios[Inventarios.size() - 1] = e;
}

string Tienda::getNombre(){
	return nombre;
}

void Tienda::setNombre(string e){
	nombre = e;
} 

void Tienda::Info(){
	//HAY QUE LLENAR ACA
}

void Tienda::VerHistInventarios(){
	for (int i = 0; i < Inventarios.size(); i++)
	{
		cout << i+1 << ". Inventario " << setw(20) << (getInventarios())[i].getFecha();
	}
}
template<class T>
void editarInventario(Tienda &a, T &e){
	vector<Inventario> nuevo;
	vector<Producto> nuevo2;
	nuevo = a.getInventarios();
	nuevo2 = a.getInventarios().back().getProductos();
	nuevo2.push_back(e);
	nuevo.back().setProductos(nuevo2);
	a.setInventarios(nuevo);
}

void Ordenador (int a, vector<Producto> &e){																										
	string k;
	Producto aux;
	if(a == 1) k = "nombre";
	else if(a == 2) k = "tipo";
	else if(a == 3) k = "cantidad";
	else if(a == 4) k = "precio";
	else if(a == 5) k = "ganancia";
	for (int i = 1; i < e.size(); i++){
		for (int j = 1; j < e.size() - i; j++){
			if (e[j-1].get(k) > e[j].get(k)){
				aux = e[j];
				e[j] = e[j-1];
				e[j-1] = aux; 
			}
		}
	}
}

void Busqueda (int a, vector<Producto> &e){																										
	string k;
	Producto aux;
	if(a == 1) k = "nombre";
	else if(a == 2) k = "tipo";
	else if(a == 3) k = "cantidad";
	else if(a == 4) k = "precio";
	else if(a == 5) k = "ganancia";
	for (int i = 1; i < e.size(); i++){
		for (int j = 1; j < e.size() - i; j++){
			if (e[j-1].get(k) > e[j].get(k)){
				aux = e[j];
				e[j] = e[j-1];
				e[j-1] = aux; 
			}
		}
	}
}

void menu(Tienda &a){
	int opc;
	do {
	system("cls");
	cout<<"Bienvenido al sistema de gestion de Tiendas, "<<a.getNombre();
	cout<<endl<<"1. Inventarios";
	cout<<endl<<"2. Empleados";
	cout<<endl<<"3. Informacion";
	cout<<endl<<"4. Salir ";
	cout<<endl<< ">>> ";
	cin >> opc;
	
	switch (opc){
		case 1:
			system("cls");
			cout<< "--------Inventario--------"<<endl;
			cout<< "1. Ver Inventario Actual"<<endl;
			cout<< "2. Ver Historial de Inventarios"<<endl;
			cout<< "3. Modificar Inventario Actual"<<endl;
			cout<< "4. Registrar Inventario"<<endl;
			cout<< "5. Salir"<<	endl;
			cout<<endl<< ">>> ";
			cin >> opc;
			switch (opc){
				case 1:
					(a.getInventarios())[(a.getInventarios()).size()-1].VerTodo();
					system("PAUSE");
					break;
				case 2:
					a.VerHistInventarios();	cout << endl;
					system("PAUSE");
					break;
				case 3:
					system("cls");
					cout<< "--------Productos--------"<<endl; 
					cout<< "1. Ver Productos" << endl;
					cout<< "2. Agregar Nuevo Producto" << endl;
					cout<< "3. Quitar Producto" << endl;	
					cout<< "4. Modificar Producto" << endl;
					cout<< "5. Ordenar Productos" << endl;
					cout<< "6. Buscar Productos" << endl;
					cout<< "7. Salir" << endl;
					cout<<endl<<">>> ";
					cin >> opc;
					switch (opc){
						case 1:
							(a.getInventarios())[(a.getInventarios()).size()-1].VerTodo();
							system("PAUSE");
							break;
						case 2:
							{
							string nombre;
							string tipo;
							int cantidad;
							float precio;
							float ganancia;
							cout << "Producto [" << (a.getInventarios())[(a.getInventarios()).size()-1].getProductos().size()+1 << "]" << endl;
							cout << "Nombre: "; getline(cin >> ws, nombre);
							cout << "Tipo: "; cin >> tipo;
							cout << "Cantidad: "; cin >> cantidad;
							cout << "Precio: "; cin >> precio;
							cout << "Ganancia: "; cin >> ganancia;
							Producto e(nombre, tipo, cantidad, precio, ganancia);
							editarInventario(a,e);
							}
							system("\nPAUSE");
							break;
						case 3:
						{
							Inventario Cambio = a.getInventarios().back();
							string nom; int cant;
						 	Cambio.VerTodo();
						 	cout << "Que producto desea quitar: ";
						 	getline(cin >> ws, nom);
						 	cout << "Que cantidades del producto desea quitar: ";
						 	cin >> cant;
							Cambio.QuitarProducto(nom, cant);
							a.setInventarioActual(Cambio);
						}
							system("\nPAUSE");
							break;
						case 4:
							
							system("\nPAUSE");
							break;
						case 5:{
							int criterio;
							WAZA:
							system("cls");
							cout << "Segun que criterio desea ordenar los productos?\n" << endl;
							cout << "1. Ordenar segun Nombre\n" << endl;
							cout << "2. Ordenar segun Tipo\n" << endl;
							cout << "3. Ordenar segun Cantidad\n" << endl;
							cout << "4. Ordenar segun Precio\n" << endl;
							cout << "5. Ordenar segun Ganancia\n\n" << endl;
							cout << ">>> "; cin >> criterio;
							if(criterio > 0 && criterio < 6){
							vector<Producto> e = a.getInventarioActual().getProductos();
							Ordenador(criterio, e);
							Inventario f = a.getInventarioActual();
							f.setProductos(e);
							a.setInventarioActual(f);
							}else {
								cout << "Eliga una opcion disponible\n\n";
								system("PAUSE");
								goto WAZA;
							}
							cout << "Ordenando..." << endl;
								for (int j = 0; j < 22; j++){
									system("cls");
									cout << "-----------------------------------------\n";
									for(int i = 0; i < j; i++){
										cout << "XD";
										}
									cout << "\n-----------------------------------------";
									Sleep(300);
									}
						}
							system("cls");
							cout << "Se ordeno correctamente!!" << endl;
							a.getInventarios().back().VerTodo();
							system("\nPAUSE");
							break;
						case 6:
							
							system("\nPAUSE");
							break;
						case 7:

							system("\nPAUSE");
							break;
						default:
							break;
						}
					break;
				case 4:

					break;
				case 5:
					
					break;
		
				default:
					cout << "Elegir una opcion disponible [1-5]" << endl;
					system("PAUSE");
					break;
				}
			break;
		case 2:
			break;
		case 3:
			
			break;
		case 4:
			break;
		default:
			cout << "Elegir una opcion disponible [1-6]" << endl;
			system("PAUSE");
			break;
		}
	} while (opc != 6);
	
}

int main(){
	string nombre;
	ofstream archiv1;
	ifstream archiv2;
	archiv2.open("datos.txt");
	if (!archiv2.is_open()){
		cout << "Error al leer archivo.dat\n";
		exit(EXIT_FAILURE);
	} else{
		int b;
		archiv2 >> b;
		if (b == 2){
			char aux;
			archiv2.get(aux);
			cout<<aux<<aux<<aux<<aux;
			getline(archiv2, nombre);
			archiv2.close();
		} else {
			archiv2.close();
			archiv1.open("datos.txt");
			cout<<"Bienvenido al sistema de gestion de Tienda.";
			cout<<endl<<endl<<"      Ingrese el nombre de su tienda";
			cout<<endl<<">>> ";
			getline(cin >> ws, nombre);
			archiv1 << 2 << " " << nombre << endl;
			archiv1.close();
		}
		Tienda tienda1(nombre);
		menu(tienda1);
	}
	return 0;
}