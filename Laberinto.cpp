#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define FIL 20
#define COL 50
using namespace std;
int destinox, puntox, puntoy;
char lab[FIL][COL];
void Inicializar();
void Imprimir();
void GenerarCamino(int i, int j);
void GenerarParedes();
void FinGenerar();
void Jugar(int tecla);
using namespace std;

int main(int argc, char** argv) {
	srand(unsigned(time(NULL)));
    Inicializar();
    int x=1+rand()%FIL-2;
    GenerarCamino(x, 1);
    lab[x][1]='W';
    GenerarParedes();
    FinGenerar();
    Imprimir();
    int tecla;
    puntox=x;
    puntoy=1;
    while(true){
    	tecla=getch();
    	if(tecla==27) break;
    	else{
    		
    		Jugar(tecla);
    		if(lab[puntox][puntoy+1]=='F'){
    			cout<<"Felicidades! Terminó el laberinto"<<endl;
    			break;
    		}
    		
    	}
    	
    }
    
	system("pause");
	return 0;
}

void Inicializar(){
     for(int i=0; i<FIL; i++)
     {
             for(int j=0; j<COL; j++)
             {
                     if(i==0 || j==0 || i==FIL-1 || j==COL-1) lab[i][j]='P';
                     else lab[i][j]=' ';
                     }
             }
     }

void Imprimir(){
     for(int i=0; i<FIL; i++)
     {
             for(int j=0; j<COL; j++)
             {
                     if(lab[i][j]=='0' || lab[i][j]=='P')cout<<(char)177;
                     else cout<<lab[i][j];
                     }
                     cout<<endl;
             }
     }

void GenerarCamino(int i, int j){
     while(j!=COL-2)
     {
             int a=rand()%3;
             switch(a)
             {
                      case 0:
                           if(i+1!=FIL-1 && lab[i+1][j]!='O')
                           {
                                      i++;
                                      lab[i][j]='O';
                                      }
                           break;
                      case 1:
                           if(i-1!=0 && lab[i-1][j]!='O')
                           {
                                     i--;
                                     lab[i][j]='O';
                                      }
                           break;
                      case 2:
                           if(j+1!=COL-1 && lab[i][j+1]!='O')
                           {
                                      j++;
                                      lab[i][j]='O';
                                      if(j==COL-2) lab[i][j]='F';
                                      }
                           break;
                      
                      
                }                  
    }//fin while
     destinox=i;
}

void GenerarParedes(){
     int paredes=0;
     while(paredes<100)
     {
                      int x=rand()%FIL;
                      int y=rand()%COL;
                      
                      if(lab[x][y]==' ')
                      {
                                      paredes++;
                                      int lim=1+rand()%10;
                                      int puestas=0;          
                                      switch(rand()%4)
                                      {
                                                       case 0:
                                                            
                                                            while(lab[x][y]==' ')//para arriba
                                                            {
                                                                               if(puestas==lim)break;
                                                                               puestas++;
                                                                               lab[x][y]='P';
                                                                               x--;        
                                                                               }
                                                            break;
                                                       case 1:
                                                            while(lab[x][y]==' ')//para abajo
                                                            {
                                                                               if(puestas==lim)break;
                                                                               puestas++;
                                                                               lab[x][y]='P';
                                                                               x++;      
                                                                               }
                                                            break;
                                                       case 2:
                                                            while(lab[x][y]==' ')//para atras
                                                            {
                                                                               if(puestas==lim)break;
                                                                               puestas++;
                                                                               lab[x][y]='P';
                                                                               y--;        
                                                                               }
                                                            break;
                                                       case 3:
                                                            while(lab[x][y]==' ')//para adelante
                                                            {
                                                                               if(puestas==lim)break;
                                                                               puestas++;
                                                                               lab[x][y]='P';
                                                                               y++;      
                                                                               }
                                                            break;
                                                            }
                                                       }
                                      }
     }
     
void FinGenerar(){
     for(int i=0; i<FIL; i++)
     {
             for(int j=0; j<COL-1; j++)
             {
                     if(lab[i][j]=='O') lab[i][j]=' ';
                     if(j==COL-2 && lab[i][j]!='F') lab[i][j]='P';
                     if(lab[i][j]=='F')
                     {
                                       lab[i][j+1]='F';
                                       lab[i][j]=' ';
                                       }
                     }
             }
     }

void Jugar(int tecla){
	switch(tecla){
		case 72://arriba
			if(lab[puntox-1][puntoy]==' '){
				system("cls");
				lab[puntox-1][puntoy]='.';
				puntox--;
				Imprimir();
			}
			else if(lab[puntox-1][puntoy]=='.' || lab[puntox-1][puntoy]=='I'){
				system("cls");
				lab[puntox][puntoy]=' ';
				puntox--;
				Imprimir();
			}
			break;
			
		case 80://abajo
			if(lab[puntox+1][puntoy]=='.' || lab[puntox+1][puntoy]=='I'){
				system("cls");
				lab[puntox][puntoy]=' ';
				puntox++;
				Imprimir();
			}
			else if(lab[puntox+1][puntoy]==' '){
				system("cls");
				lab[puntox+1][puntoy]='.';
				puntox++;
				Imprimir();
			}
			break;
			
		case 75://izquierda
			if(lab[puntox][puntoy-1]==' '){
				system("cls");
				lab[puntox][puntoy-1]='.';
				puntoy--;
				Imprimir();
			}
			else if(lab[puntox][puntoy-1]=='.' || lab[puntox][puntoy-1]=='I'){
				system("cls");
				lab[puntox][puntoy]=' ';
				puntoy--;
				Imprimir();
			}			
			break;
		
		case 77://derecha
		if(lab[puntox][puntoy+1]=='.' || lab[puntox][puntoy+1]=='I'){
				system("cls");
				lab[puntox][puntoy]=' ';
				puntoy++;
				Imprimir();
			}
			else if(lab[puntox][puntoy+1]==' '){
				system("cls");
				lab[puntox][puntoy+1]='.';
				puntoy++;
				Imprimir();
			}
			break;
	}
}
