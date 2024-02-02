#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>
#include <fstream>
#include <iomanip>
#define tab setw(10) 
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
Producto::Producto(string nom, string tip, int cant, float pre, float gan){
	nombre = nom;
	tipo = tip;
	cantidad = cant;
	precio = pre;
	ganancia = gan;
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
	cout << "Size: "  << Productos.size();
	Productos.push_back(e);
	cout << "Size: "  << Productos.size();
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
		for(int i = 0; i != Productos.size(); i++){
			cout<<"Producto ["<<i+1<<"]"<<endl<<endl;
			cout<<"Nombre: "<<Productos[i].getNombre()<<endl;
			cout<<"Tipo: "<<Productos[i].getTipo()<<endl;
			cout<<"Cantidad: "<<Productos[i].getCantidad()<<endl;
			cout<<"Precio: "<<Productos[i].getPrecio()<<endl;
			cout<<"Ganancia: "<<Productos[i].getGanancia()<<endl<<endl;
		}
	} else{
	cout << "Aun no se han registrando productos..." << endl;
	}
	
}

void Inventario::Registrar(){
	cout<<"\n Ingrese la fecha en formato DD/MM/AA: ";
	cin>>fecha;
}

class Flujo{
	private:
		float Dinero;
	public:
		Flujo();
		Flujo(float);
		void TodoFlujo();
		void Inversion(string, int);
		void Inversion();
		void Ventas();
		void GastoEmpleados();
		void GastoEmpleados(string);
		float getDinero();
		void setDinero(float);
		void sumarDinero(float);
};

Flujo::Flujo(){
	Dinero = 0;
}

Flujo::Flujo(float e){
	Dinero = e;
}

void Flujo::TodoFlujo(){
	
}

void Flujo::Inversion(){
	
}

void Flujo::Inversion(string e, int a){
	
}

void Flujo::Ventas(){
	
}

void Flujo::GastoEmpleados(){
	
}

void Flujo::GastoEmpleados(string e){
	
}

float Flujo::getDinero(){
	return Dinero;
}

void Flujo::setDinero(float e){
	Dinero = e;
}

void Flujo::sumarDinero(float e){
	Dinero += e;
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

class Usuario{
	private:
		string nombre;
		string contrasena;
		string correo;
		vector<Producto> adquiridos;
	public:
		Usuario(string, string, string);
		string getNombre();
		string getContrasena();
		string getCorreo();
		vector<Producto> getProductos();
		void setNombre(string);
		void setContrasena(string);
		void setCorreo(string);
		void agregarProductos(Producto);
		void quitarProductos(Producto);
};

Usuario::Usuario(string e,string d ,string a){
	nombre = e;
	contrasena = d;
	correo = a;
}

string Usuario::getNombre(){
	return nombre;
}

string Usuario::getContrasena(){
	return contrasena;
}

string Usuario::getCorreo(){
	return correo;
}

vector<Producto> Usuario::getProductos(){
	return adquiridos;
}

void Usuario::setNombre(string e){
	nombre = e;
}

void Usuario::setContrasena(string e){
	contrasena = e;
}

void Usuario::setCorreo(string e){
	correo = e;
}

void Usuario::agregarProductos(Producto e){
	for (int i = 0; i < adquiridos.size(); i++){
		if (adquiridos[i] == e){
			adquiridos[i].setCantidad(adquiridos[i].getCantidad() + e.getCantidad());
			return;
		}
	}
	adquiridos.push_back(e);
}

void Usuario::quitarProductos(Producto e){
	for (int i = 0; i < adquiridos.size(); i++){
		if (adquiridos[i] == e){
			if(adquiridos[i].getCantidad() < e.getCantidad()){
				cout<<"Solo compraste "<<adquiridos[i].getCantidad()<<" unidades de este producto, vuelve a intentar."<<endl<<endl;
			} else {
				if(adquiridos[i].getCantidad() == e.getCantidad()){
					adquiridos.erase(adquiridos.begin()+i); 
				} else {
					adquiridos[i].setCantidad(adquiridos[i].getCantidad() - e.getCantidad());
				}
			}
		}
	}
}

class Tienda{
	private:
		string nombre;
		vector<Inventario> Inventarios;
		vector<Empleado> Empleados;
		vector<Flujo> Flujos;
		vector<Usuario> Usuarios;
	public:
		Tienda(string);
		vector<Usuario> darUsuarios();
		void agregarUsuario(Usuario);
		void Ventas();
		void AsignarEmpleado(Empleado);
		vector<Inventario> getInventarios();
		void setInventarios(vector <Inventario>);
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

string Tienda::getNombre(){
	return nombre;
}

void Tienda::setNombre(string e){
	nombre = e;
} 

void Tienda::Info(){
	//HAY QUE LLENAR ACA
}

vector<Usuario> Tienda::darUsuarios(){
	return Usuarios;
}

void Tienda::agregarUsuario(Usuario e){
	Usuarios.push_back(e);
}

void Tienda::Ventas(){
	//Hay que imprimir toda la info de ventas aqui, los productos con sus cantidades :V
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

void menu(Tienda &a){
	int opc;
	do {
	system("cls");
	cout<<"Bienvenido al sistema de gestion de Tiendas, "<<a.getNombre();
	cout<<endl<<"1. Inventarios";
	cout<<endl<<"2. Usuarios";
	cout<<endl<<"3. Flujo";
	cout<<endl<<"4. Empleados";
	cout<<endl<<"5. Informacion";
	cout<<endl<<"6. Salir ";
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
						case 3:/*{
						// 	string nom; int cant;
						// 	a.getInventarios().back().VerTodo();
						// 	cout << "Que producto desea quitar: ";
						// 	getline(cin >> ws, nom);
						// 	cout << "Que cantidades del producto desea quitar: ";
						// 	cin >> cant;
						// 	a.getInventarios().back().QuitarProducto(nom, cant);
						// 	}*/
							system("\nPAUSE");
							break;
						case 4:

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
		case 5:
			break;
		case 6:
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