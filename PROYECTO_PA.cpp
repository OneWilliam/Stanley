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
		void verProducto(int);
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

void Producto :: verProducto(int i){
	cout << "     " << left << tab_nombre <<  "NOMBRE" << tab  <<  "TIPO" << tab << "CANTIDAD" << tab << "PRECIO" << tab << "GANANCIA" << endl;
	cout << "[" << i + 1  << "]  "<< left << tab_nombre << nombre << tab << tipo << tab << cantidad << tab << precio << tab << ganancia << endl;
}

class Inventario{
	private:
		vector<Producto> Productos;
		string fecha;
	public:
		Inventario();
		vector<Producto> getProductos();
		void setProductos(vector <Producto>);
		string getFecha();
		void setFecha(string);
		void AgregarNuevoProducto(Producto);
		void AgregarProducto(string, int);
		void QuitarProducto(string, int);
		void VerTodo();
		void Registrar();
};

Inventario::Inventario(){
	fecha = "Actual";
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

void Inventario::setFecha(string e){
	fecha = e;
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
	if (fecha != "Actual"){
		cout<<"Inventario con fecha " << fecha << " <-- " << endl;
	} else {
		cout<<"Inventario Actual...\n\n";
	}
	if (!Productos.empty()) {
		cout<<"En el inventario tenemos: "<<endl<<endl;
		cout << "     " << left << tab_nombre <<  "NOMBRE" << tab_nombre  <<  "TIPO" << tab << "CANTIDAD" << tab << "PRECIO" << tab << "GANANCIA" << endl;
		for(int i = 0; i != Productos.size(); i++){
			cout << "[" << i + 1 << "]  "<< left << tab_nombre << Productos[i].getNombre() << tab_nombre << Productos[i].getTipo() << tab << Productos[i].getCantidad() << tab << Productos[i].getPrecio() << tab << Productos[i].getGanancia() << endl;
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
		void DespedirEmpleado(int);
		void VerEmpleados();
		vector<Inventario> getInventarios();
		void setInventarios(vector <Inventario>);
		vector<Empleado> getEmpleados();
		void setEmpleados(vector<Empleado>);
		Inventario getInventarioActual();
		void setInventarioActual(Inventario);
		string getNombre();
		void setNombre(string);
		void Info();
		void VerHistInventarios();
		void guardarInventarioActual();
		
};

Tienda::Tienda(string nom){
	Inventario e;
	Inventarios.push_back(e);
	nombre = nom;
}

void Tienda::AsignarEmpleado(Empleado e){
	Empleados.push_back(e);
}
void Tienda::DespedirEmpleado(int a){
	Empleados.erase(Empleados.begin() + a);
}
void Tienda::VerEmpleados(){
	cout << "---------------------------------------------------------" << endl;
	cout << "    " << left << tab_nombre << "NOMBRE" << tab_nombre << "NIVEL" << tab << "SUELDO" << endl;
	cout << "---------------------------------------------------------" << endl;
	for (int i = 0; i < Empleados.size(); i++){
		cout << i << "  " << left << tab_nombre <<  Empleados[i].getNombre() << tab_nombre << Empleados[i].getNivel() << tab << Empleados[i].getSueldo() << endl;
	}	
}
vector<Inventario> Tienda::getInventarios(){	
	return Inventarios;
}
void Tienda::setInventarios(vector <Inventario> Nuevo){
	Inventarios = Nuevo;
}

vector<Empleado> Tienda::getEmpleados(){
	return Empleados;
}

void Tienda::setEmpleados(vector<Empleado> e){
	Empleados = e;
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
	cout<<"---Sistema creado por--- \n";
	cout<<"- Eduardo Paca\n";
	cout<<"- William Yak\n";
	cout<<"- Duilio Zapana\n\n";
}

void Tienda::VerHistInventarios(){
	int contador = 0;
	for (int i = Inventarios.size()-1; i > -1; i--)
	{
		contador++;
		cout << contador << ". Inventario " << left <<setw(20) << Inventarios[i].getFecha();
		cout << endl;
	}
}
void Tienda::guardarInventarioActual(){
	Inventario Inventario_actual = Inventarios.back();
	Inventarios.back().Registrar();
	ofstream archivo;
	archivo.open("Inventario.txt");
	for (int i = 0; i < Inventarios.size(); i++)
	{
		archivo << "Inventario "<< i << " " << Inventarios[i].getFecha() << " " <<Inventarios[i].getProductos().size() << endl; 
		for (int j = 0; j < Inventarios[i].getProductos().size(); j++){
			archivo << (Inventarios[i]).getProductos()[j].getTipo() << " ";
			archivo << (Inventarios[i]).getProductos()[j].getCantidad() << " ";
			archivo << (Inventarios[i]).getProductos()[j].getPrecio() << " ";
			archivo << (Inventarios[i]).getProductos()[j].getGanancia() << " ";
			archivo << (Inventarios[i]).getProductos()[j].getNombre() << " ";
			archivo << endl;
		}
	}
	cout<<endl<<endl;
	Inventarios.push_back(Inventario_actual);
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

int Busqueda (int a, string c, vector<Producto> &e){																										
	string k;
	int encontrados = 0;
	if(a == 1) k = "nombre";
	else if(a == 2) k = "tipo";
	for (int i = 0; i < e.size(); i++){
		if (e[i].get(k) == c){
			encontrados++;
			e[i].verProducto(i);
		}
	}
	if(encontrados > 0)
		return 1;
	return -1;
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
					a.getInventarios().back().VerTodo();
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
					cout<< "4. Ordenar Productos" << endl;
					cout<< "5. Buscar Productos" << endl;
					cout<< "6. Salir" << endl;
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
						case 4:{
							int criterio;
							DE0:
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
							} else {
								cout << "Eliga una opcion disponible\n\n";
								system("PAUSE");
								goto DE0;
							}

							cout << "Ordenando..." << endl;
								for (int j = 0; j < 22; j++){
									system("cls");
									cout << "-----------------------------------------\n";
									for(int i = 0; i < j; i++){
										cout << "XX";
										}
									cout << "\n-----------------------------------------";
									Sleep(300);
								}
							}
							system("cls");
							cout << "Se ordeno correctamente!!" << endl;
							a.getInventarios().back().VerTodo();
							opc = 0;
							system("\nPAUSE");
							break;
						case 5:{
							int criterio, l; 
							string c;
							DE1:
							system("cls");
							cout << "Segun que criterio desea buscar entre los productos?\n" << endl;
							cout << "1. Buscar segun Nombre\n" << endl;
							cout << "2. Buscar segun Tipo\n" << endl;
							cout << ">>> "; cin >> criterio;
							if(criterio > 0 && criterio < 3){
								vector<Producto> e = a.getInventarioActual().getProductos();
								cout << "Escriba el elemento a buscar segun el criterio elegido: "; getline(cin >> ws, c);
								int indice = Busqueda(criterio, c, e);
								if (indice == -1){
									cout<<"No se encontro ninguna similitud\n\n";	
								}
								system("PAUSE");
							} else {
								cout << "Eliga una opcion disponible\n\n";
								system("PAUSE");
								goto DE1;
							}
						}
							system("\nPAUSE");
							break;
						default:
							break;
						}
					break;
				case 4:
					a.guardarInventarioActual();
					opc = 0;
					break;
				case 5:
					break;
				default:
					cout << "Elegir una opcion disponible [1-5]" << endl;
					system("PAUSE");
					break;
				}
			break;
		case 2:{
			int tap;
			system("cls");
			cout << "-------Empleados-------" << endl;
			cout << "1. Ver Empleados" << endl;
			cout << "2. Contratar Empleados" << endl;
			cout << "3. Despedir Empleados" << endl;
			cout << "4. Salir" << endl;
			cout << ">>> "; cin >> tap;
			switch (tap)
			{
			case 1:
				a.VerEmpleados();
				system("PAUSE");
				break;
			case 2:{
				string nombre, nivel;
				float saldo;
				cout << "Nombre del empleado a contratar: "; cin >>  nombre;
				cout << "Nivel del contrato del empleado a contratar: "; cin >>  nivel;
				cout << "Sueldo que tendra el empleado a contratar: "; cin >>  saldo;
				Empleado e(nombre, nivel, saldo);
				a.AsignarEmpleado(e);
				}
				break;
			case 3:{
				system("cls");
				int e;
				a.VerEmpleados();
				cout << "Indice del empleado a despedir: "; cin >>  e;
				a.DespedirEmpleado(e);
				}
				break;
			case 4:
				break;	
			default:
				cout << "Eliga una opcion disponible [1-4]" << endl;
				system("PAUSE");
				break;
			}

		} 
			break;
		case 3:
			system("cls");
			a.Info();
			cout<<endl;
			system("PAUSE");
			break;
		case 4:
			break;
		default:
			cout << "Elegir una opcion disponible [1-4]" << endl;
			system("PAUSE");
			break;
		}
	} while (opc != 4);
	ofstream archiv2;
	vector<Inventario> Inventarios = a.getInventarios();
	archiv2.open("inventario.txt");
	for (int i = 0; i < Inventarios.size(); i++)
	{
		archiv2 << "Inventario "<< i << " " << Inventarios[i].getFecha() << " " <<Inventarios[i].getProductos().size() << endl; 
		for (int j = 0; j < Inventarios[i].getProductos().size(); j++){
			archiv2 << (Inventarios[i]).getProductos()[j].getTipo() << " ";
			archiv2 << (Inventarios[i]).getProductos()[j].getCantidad() << " ";
			archiv2 << (Inventarios[i]).getProductos()[j].getPrecio() << " ";
			archiv2 << (Inventarios[i]).getProductos()[j].getGanancia() << " ";
			archiv2 << (Inventarios[i]).getProductos()[j].getNombre() << " ";
			archiv2 << endl;
		}
	}
	archiv2<<"x";
	archiv2.close();
	vector<Empleado> Empleados = a.getEmpleados();
	archiv2.open("inventario.txt");
			for (int i = 0; i < Empleados.size(); i++){
			archiv2 << (Empleados[i]).getNivel() << " ";
			archiv2 << (Empleados[i]).getSueldo() << " ";
			archiv2 << (Empleados[i]).getNombre() << " ";
			archiv2 << endl;
		}
	archiv2<<"x";
	archiv2.close();
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
		vector<Inventario> Lector;
		Inventario ultimo;
		archiv2.open("inventario.txt");
		string temp;
		bool leer = true;
		while(leer){
			archiv2>>temp;
			if (!(temp == "x" || archiv2.eof())){
				Inventario e;
				int indice;
				string fecha;
				int cantidad;
				archiv2>>indice>>fecha>>cantidad;
				e.setFecha(fecha);
				vector<Producto> Lector_P;
				for (int i = 0; i < cantidad ; i ++){
					Producto a;
					string tipo;
					string nombre;
					int cantidad;
					float precio;
					float ganancia;
					char c;
					archiv2>>tipo>>cantidad>>precio>>ganancia;
					archiv2.get(c);
					getline(archiv2, nombre);
					a.setNombre(nombre);
					a.setTipo(tipo);
					a.setPrecio(precio);
					a.setCantidad(cantidad);
					a.setGanancia(ganancia);
					Lector_P.push_back(a);
				}
				e.setProductos(Lector_P);
				Lector.push_back(e);
			} else {
				leer = false;
			}
		}
		if (Lector.empty()){
			Inventario a;
			Lector.push_back(a);
		}
		tienda1.setInventarios(Lector);
		archiv2.close();
		archiv2.open("empleados.txt");
		vector <Empleado> Empleados;
		bool lee = true;
		while (lee){
			if (!(temp == "x" || archiv2.eof())){
				string nombre, nivel;
				float sueldo;
				char c;
				archiv2 >> nivel >> sueldo;
				archiv2.get(c);
				getline(archiv2, nombre);
				Empleado e(nombre, nivel, sueldo);
				
			} else{
				lee = false;
			}
		}
		
		
		menu(tienda1);
	}
	return 0;
}