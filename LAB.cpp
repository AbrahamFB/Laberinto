#include <cstdlib>
#include <iostream>
#include <time.h>
#include <windows.h>
#define FIL 20
#define COL 50
using namespace std;

class Laberinto{
	protected:
		char lab[FIL][COL];

struct recorrido{
       int x;
       int y;
       struct recorrido *w;
       };
       typedef struct recorrido *Lista;

       public:
			Lista reco=NULL;
			void Inicializar();
			void Imprimir();
			void GenerarCamino(int i, int j);
			int Adelante(int i, int j);
			void InsertReco(int x, int y);
			bool Verificar(int x, int y);
			void GenerarParedes();
			void FinGenerar();
};

void Laberinto::Inicializar(){
	 for(int i=0; i<FIL; i++){
             for(int j=0; j<COL; j++){
                     if(i==0 || j==0 || i==FIL-1 || j==COL-1)
					 	lab[i][j]='0';
                     else
					 	lab[i][j]=' ';
                     }
             }
     }

void Laberinto::Imprimir(){
     for(int i=0; i<FIL; i++){
             for(int j=0; j<COL; j++){
                     if(lab[i][j]=='0')
					 	cout<<(char)219;//Ascii
                     else
					 	cout<<lab[i][j];
                     }
                     cout<<endl;
             }
     }

void Laberinto::GenerarCamino(int i, int j){
     while(j!=COL-2){
             int a=rand()%+3;
             switch(a){
                      case 0:
                           if(i+1!=FIL-1 && lab[i+1][j]!='O'){
                                      i++;
                                      lab[i][j]='O';
                                      }
                           break;
                      case 1:
                           if(i-1!=0 && lab[i-1][j]!='O'){
                                     i--;
                                     lab[i][j]='O';
                                      }
                           break;
                      case 2:
                           if(j+1!=COL-1 && lab[i][j+1]!='O'){
                                      j++;
                                      lab[i][j]='O';
                                      if(j==COL-2) 
									  	lab[i][j]='F';
                                      }
                           break;                     
                      }                  
                 }
     }
     
void Laberinto::GenerarParedes(){
     int paredes=0;
     while(paredes<100){
                      int x=rand()%FIL;
                      int y=rand()%COL;
                      
                      if(lab[x][y]==' '){
                                      paredes++;
                                      int lim=1+rand()%10;
                                      int puestas=0;          
                                      switch(rand()%4){
                                                       case 0:
                                                            while(lab[x][y]==' '){//para oeste
                                                                               if(puestas==lim)
																			   	break;
                                                                               puestas++;
                                                                               lab[x][y]='0';
                                                                               x--;        
                                                                               }
                                                            break;
                                                       case 1:
                                                            while(lab[x][y]==' '){//para este
                                                                               if(puestas==lim)
																			   	break;
                                                                               puestas++;
                                                                               lab[x][y]='0';
                                                                               x++;      
                                                                               }
                                                            break;
                                                       case 2:
                                                            while(lab[x][y]==' '){//para sur
                                                                               if(puestas==lim)
																			   	break;
                                                                               puestas++;
                                                                               lab[x][y]='0';
                                                                               y--;        
                                                                               }
                                                            break;
                                                       case 3:
                                                            while(lab[x][y]==' '){//para el norte
                                                                               if(puestas==lim)
																			   	break;
                                                                               puestas++;
                                                                               lab[x][y]='0';
                                                                               y++;      
                                                                               }
                                                            break;
                                                            }
                                                       }
                                      }
     }
     
void Laberinto::FinGenerar(){
     for(int i=0; i<FIL; i++){
             for(int j=0; j<COL-1; j++){
                     if(lab[i][j]=='O')
					 	lab[i][j]=' ';
                     if(j==COL-2 && lab[i][j]!='F')
					 	lab[i][j]='0';
                     if(lab[i][j]=='F'){
                                       lab[i][j+1]='F';
                                       lab[i][j]=' ';
                                       }
                     }
             }
     }
int Laberinto::Adelante(int i, int j){
    int re=0;
    if(lab[i][j+1]=='F'){
                        lab[i][j]=(char)1;
                        return 1;
                        }
    lab[i][j]=(char)1;
    system("cls");
    Imprimir();
    if(lab[i][j+1]==' ' && re==0 && Verificar(i,j+1)) re=Adelante(i,j+1);//hacia norte
    if(lab[i][j-1]==' ' && re==0 && Verificar(i,j-1)) re=Adelante(i,j-1);//hacia sur
    if(lab[i-1][j]==' ' && re==0 && Verificar(i-1,j)) re=Adelante(i-1,j);//hacia oeste
    if(lab[i+1][j]==' ' && re==0 && Verificar(i+1,j)) re=Adelante(i+1,j);//hacia este
    if(re==1) return 1;
    else{
        InsertReco(i,j);
        lab[i][j]=' ';
        }
    return 0;    
     }
     
void Laberinto::InsertReco(int x, int y){
     Lista q=new (struct recorrido);
     q->x=x;
     q->y=y;
     q->w=reco;
     reco=q;
     }

bool Laberinto::Verificar(int x, int y){
     Lista q=reco;
     while(q!=NULL){
                   if(q->x==x && q->y==y)
				return false;
                   q=q->w;
                   }
                   return true;
     }

int main(){
	system("color F0");
    Laberinto l1;
    char lab[FIL][COL];

	srand(unsigned(time(NULL)));
    l1.Inicializar();
    int x=1+rand()%FIL-2;
    l1.GenerarCamino(x, 1);
    lab[x][1]='I';
    l1.GenerarParedes();
    l1.FinGenerar();
    l1.Imprimir();
    if(l1.Adelante(x,1)==0)
		cout<<"Wally no ah encontrado el camino correcto"<<endl;
    else
		cout<<"Wally ah encontrado el camino correcto"<<endl;
}
