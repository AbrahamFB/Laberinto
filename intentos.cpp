#include <iostream>
using namespace std;

class Celda{
	protected:
		bool estado; //1-abierta, 0-cerrada
	
};
class Abierta: public Celda{
	friend ostream & operator<<(ostream &, const Abierta &);
	public:
		int contenido;//0-Wally ya pasó por ahí(rastro)/1-vacía/2-Ahí está Wally
	public:
		static const bool estado=1;
};
ostream &operator<<(ostream &output, const Abierta &a) {
	if(a.contenido==1)
		output << ' ';//Representación de una celda abierta
	if(a.contenido==0)
		output << '.';
	if(a.contenido==2)
		output << "W";
	return output;
}

class Cerrada: public Celda{
	friend ostream & operator<<(ostream &, const Cerrada &);
	public:
		static const bool estado=0;
};
ostream &operator<<(ostream &output, const Cerrada &c) {
	output << '#';//Representación de una celda cerrada
	return output;
}
class Laberinto{
	Celda celdas[50][50];//Un laberinto está compuesto de celdas
	public:
		void crearLaberinto();
};
class Wally{
	friend ostream & operator<<(ostream &, const Wally &);
	public:
		void pasarCelda(Celda celda);
		void dejarRastro(Abierta celda);
};
ostream &operator<<(ostream &output, const Wally &w) {
	output << 'W';//Representación de una celda cerrada
	return output;
}
int main(){
	Cerrada c, c1, c2;
	Abierta a, a1, a2;
	Wally w;
	cout<< c << a <<w<< c1 << a1<<endl;
	cout << c2<<a2<<a2<<c2<<endl;
	cout << c.estado<<endl;
	cout << c1.estado<<endl;
	cout << c2.estado<<endl;
	cout << a.estado<<endl;
	cout << a1.estado<<endl;
	cout << a2.estado<<endl;
	
}
