#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
class Celda{
	private:
	    char celda;
	public:
	    Celda(){
			celda=' ';
			}
		Celda &operator!=(Celda c){}
		char getCelda();
		void setCelda(char c);
		bool esAbierta();
};
char Celda::getCelda(){
	return celda;
}
void Celda::setCelda(char c){
	celda=c;
	}
class Wally{
	private:
	    char forma;
	public:
	    Wally(){
			forma=184;
			}
	    char getForma();
	    bool  moverNorte(Celda c);
	    bool moverSur(Celda c);
	    bool moverOeste(Celda c);
	    bool moverEste(Celda c);
	    bool puedeAvanzar(Celda c);
};
char Wally::getForma(){
	return forma;
}
bool Wally::puedeAvanzar(Celda c){
	if(c.getCelda()!='0' ||c.getCelda()!=219)
	    return true;
	else
		return false;
}
bool Wally::moverNorte(Celda c){
	if(puedeAvanzar(c))
		return true;
		else
			return false;
}
bool Wally::moverSur(Celda c){
	if(puedeAvanzar(c))
		return true;

}
bool Wally::moverOeste(Celda c){
	if(puedeAvanzar(c))
		return true;
	else
	  	return false;
}
bool Wally::moverEste(Celda c){
	if(puedeAvanzar(c))
	    return true;
	else
		return false;
}
class Laberinto{
	private:
		int fil,col,x,y;
		Celda celdas[100][100];
		Wally w;
	public:
	    Laberinto(){
				col=50;
				fil=20;
			}
	    Laberinto(int c,int f){
			col=c;
			fil=f;
			}
	    void crearParedes();
	    void crearEscenario();
	    void Imprimir();
	    bool recorrerLaberinto(int i,int j);
	    void resultado();
	    void ubicarWally();
};
void Laberinto::crearParedes(){
	for(int i=0;i<fil;i++){
	    for(int j=0;j<col; j++)
	        if(i==0 || j==0 || i==fil-1 || j==col-1)
	            celdas[i][j].setCelda('0');
		}
	}
void Laberinto::crearEscenario(){
	int i,j,x;
	srand(time(NULL));
	for(i=0;i<fil;i++){
	    for(j=0;j<col;j++){
	        if(celdas[i][j].getCelda()!='0'){
	            x=rand()%3+1;
	            celdas[i][j].setCelda(x);
    			}
   		}
}
for(i=0; i<fil;i++){
    for(j=0;j<col;j++)
	    if(celdas[i][j].getCelda()!='0'){
	        if(celdas[i][j].getCelda()!=1 /*&&celdas[i][j].getCelda()!=3 /*&& celdas[i][j].getCelda()!=3 && celdas[i][j].getCelda()!=4*/)
	        	celdas[i][j].setCelda(' ');
	        else
				celdas[i][j].setCelda(219);
	    }
	}
	x=rand()%(fil-1)+1;
	celdas[x][col-1].setCelda('x');
}
void Laberinto::Imprimir(){
	int i,j;
	for(i=0;i<fil;i++){
	    for(j=0;j<col;j++){
	        if(celdas[i][j].getCelda()!='0')
	        	cout<<celdas[i][j].getCelda();
		    else
				cout<<(char)219;
		    }
		    cout<<endl;
	}
}
bool Laberinto::recorrerLaberinto(int i,int j){
	char aux;
    if(celdas[i][j].getCelda()=='x')
        return true;
    else{
        Imprimir();
        system("cls");
        if(w.moverNorte(celdas[i+1][j])){
         celdas[i+1][j].setCelda(w.getForma());
         recorrerLaberinto(i+1,j);}
         if(w.moverSur(celdas[i-1][j])){
            celdas[i-1][j].setCelda(w.getForma());
            recorrerLaberinto(i-1,j);
         }
         if(w.moverOeste(celdas[i][j-1])){
            celdas[i][j-1].setCelda(w.getForma());
            recorrerLaberinto(i,j-1);
         }
         if(w.moverSur(celdas[i][j+1])){
            celdas[i][j+1].setCelda(w.getForma());
            recorrerLaberinto(i,j+1);
         }
    }
	return false;
}
void Laberinto::ubicarWally(){
	int x,y;
	x=rand()%(fil-1)+1;
	y=rand()%(col-1)+1;
	celdas[x][y].setCelda(w.getForma());
	}
void Laberinto::resultado(){
	recorrerLaberinto(x,y);
	    cout<<"Wally ha encontrado la salida"<<endl;
}
int main(){
	Laberinto l;
	l.crearParedes();
	l.crearEscenario();
	l.Imprimir();
	l.ubicarWally();
	l.resultado();
	//l.recorrerLaberinto(x,y);
}
