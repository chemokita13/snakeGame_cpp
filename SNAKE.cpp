#include <iostream>
#include <windows.h>
#include <math.h>
#include <vector>
#include <wchar.h>
#include <locale.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <winuser.h>
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
using namespace std;
// variables principales
const int W = 20, H = 20;
int headPos[2], foodPos[2];
int tailPosX[100], tailPosY[100];
int tailL = 0;
int score, oldScore = 0;
enum direcE {st=0, l, r, u, d};
direcE snakeDirec;
bool fin;
//ejecuta la salida
void salir (){
	system("cls");
		cout<<"Gracias por jugar.";
		exit(1);
}
//inicializa el tablero de juego, etc.
void init(){
	//system("cls");
	headPos[0] = W/2;
	headPos[1] = H/2;
	score=0;
	tailL = 0;
	do{
		foodPos[0] = rand()%23;
		foodPos[1] = rand()%23;
	} while((foodPos[1]<0)||(foodPos[1]>21)||(foodPos[0]<2)||(foodPos[0]>21)||(foodPos[1]==headPos[0])||(foodPos[0]==headPos[1]));
	snakeDirec = st;
	score = 0;
fin = false;
}
// ejecuta la pantalla de inicio
void inicio(){
	int a = 1,b;
	system("cls");
	cout<<endl<<endl;
	for(int i=0; i<41;i++){if((i==0)||(i==1)){cout<<" ";}else{ if((i==2)||(i==40)){cout<<"#";}else{cout<<"=";}}}
	cout<<endl;
	for(int i=0; i<41;i++){if((i==0)||(i==1)){cout<<" ";}
			if(i==3)
				cout<<"|";
			if(i>=4 && i<=14)
				cout<<" ";
			if(i==14)
				cout<<"B";
			if(i==15)
				cout<<"I";
			if(i==16)
				cout<<"E";
			if(i==17)
				cout<<"N";
			if(i==18)
				cout<<"V";
			if(i==19)
				cout<<"E";
			if(i==20)
				cout<<"N";
			if(i==21)
				cout<<"I";
			if(i==22)
				cout<<"D";
			if(i==23)
				cout<<"O";
			if(i>=24 && i<=39)
				cout<<" ";
			if(i==40)
				cout<<"|";
		}		
	cout<<endl;
	for(int i=0; i<41;i++){if((i==0)||(i==1)){cout<<" ";}else{ if((i==2)||(i==40)){cout<<"|";}else{cout<<"-";}}}
	cout<<endl<<"  |      ·Los controles son:            |";
	cout<<endl<<"  |        -W o flecha: Arriba          |";
	cout<<endl<<"  |        -A o flecha: Izquierda       |";
	cout<<endl<<"  |        -S o flecha: Abajo           |";
	cout<<endl<<"  |        -D o flecha: Derecha         |";
	cout<<endl<<"  |        -Q: Salir                    |";
	cout<<endl<<"  |        -P: Pausa                    |";
	cout<<endl;
	for(int i=0; i<41;i++){if((i==0)||(i==1)){cout<<" ";}else{ if((i==2)||(i==40)){cout<<"|";}else{cout<<"-";}}}
	cout<<endl<<"  | ·PULSA CUALQUIER TECLA PARA EMPEZAR |"<<endl;
	for(int i=0; i<41;i++){if((i==0)||(i==1)){cout<<" ";}else{ if((i==2)||(i==40)){cout<<"#";}else{cout<<"=";}}}
	cout<<endl<<"   (Para salir, pulse 1)"<<endl;
	switch(getch()){
			case '1':
				exit(1);
				break;
			default:
				init();
				break;
		}
	cout<<endl<<endl;
	system("cls");
}
// vuelve a empezar el juego
void reset (){
	 oldScore = score; // guarda la puntuacion anterior
	 init();}
// crea el tablero de juego, manzana y serpiente
void render(){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
	cout<<endl<<endl;
	for(int i = 0; i<23;i++){	if(i==0){cout<<" ";}else{
	if(i==1){cout<<"#";}
		else{if(i==22){cout<<"#";
		}else{cout<<"=";
		}
		}}};
	cout<<"\n";
	for(int i=0;i<22;i++){
		for(int j=0;j<23;j++){if(j==0){cout<<" ";}else{
		if(j==1){cout<<"|";}
		else{if(j==22){cout<<"|"<<endl;
		}else{if(i==headPos[0] && j==headPos[1]){cout<<"O";}else{if(j==foodPos[0] && i==foodPos[1]){cout<<"*";}else{
				
				bool printTail = false;
				for(int k=0; k<tailL; k++){
					if(tailPosX[k]==j && tailPosY[k]==i){
					cout<<".";
					printTail=true;}
				}
				if(printTail==false){cout<<" ";}
		}
		}
		}
		}
		}
		}
		}
		for(int i=0;i<23;i++){if(i==0){cout<<" ";}else {
		if(i==1){cout<<"#";}
		else{if(i==22){cout<<"#          ***Proyecto creado por Jose Maria Pahino.***"<<endl<<endl; 
		}else{cout<<"=";
		}
		}
	}
	}
	cout<<"Puntuacion: "<<score<<"."<<endl;
	if(oldScore!=0){
		cout<<"Puntuacion anterior: "<<oldScore<<"."<<endl;
	}
}
// pantalla en caso de que se pierda
void lose(){
	int a=(log10(score) + 1); // a = numero de cifras de la puntuacion. (Puntuacion = 1 -> a = 1; Puntuacion = 10 -> a=2)
	system("cls");
	cout<<endl<<endl<<endl;
	for(int i=0; i<41 ;i++){
		if((i==0)||(i==1)){
			cout<<" ";
		}else{
			if(i==2){
				cout<<"O";
			}else{
				if(i==40){
					cout<<"O";
				}else{
					cout<<"X";
				}
			}
		}
	}
	cout<<"\n  X             PERDISTE                X"<<endl;
	cout<<"  X   Tu puntuacion fue: "<<score;
	if((a==2)||(a>2 && a<3)){
		cout<<"             X";
	}else{
		if(a<2){
			cout<<"              X";
		}
	}
	cout<<endl;
	for(int i=0; i<41 ;i++){
		if((i==0)||(i==1)){
			cout<<" ";
		}else{
			if(i==2){
				cout<<"O";
			}else{
				if(i==40){
					cout<<"O";
				}else{
					cout<<"X";
				}
			}
		}
	}
	cout<<endl<<endl;
	for(int i=0; i<41 ;i++){
		if((i==0)||(i==1)){
			cout<<" ";
		}else{
			if(i==2){
				cout<<"#";
			}else{
				if(i==40){
					cout<<"#";
				}else{
					cout<<"=";
				}
			}
		}
	}
	cout<<endl<<"  | Presiona las teclas:                |\n  |     1: Salir                        |\n  |     2: Reiniciar                    |"<<endl;
	for(int i=0; i<41 ;i++){
		if((i==0)||(i==1)){
			cout<<" ";
		}else{
			if(i==2){
				cout<<"#";
			}else{
				if(i==40){
					cout<<"#";
				}else{
					cout<<"=";
				}
			}
		}
	}
	cout<<endl<<endl<<endl;
	int z = getch(); // z = tecla que se pulse
	switch(z){ // analizamos las teclas que se han pulsado
		case '1':
			salir();
			break;
		case '2':
			reset();
			break;
		default:
			cout<<"Tecla NO válida.";
			break;
	}
	system("cls");
}
// las maneras externas de modificar el progama (Pulsar la tecla "W" y mover la serpiente; etc.)
void input (){
	if(_kbhit()){ char opk = _getch(); // recojo la tecla pulsada
	// Equivalenca flechas -> teclas (Tecla FlechaDerecha = Tecla A y demas)
	if (opk == ARRIBA){ opk = 'w';} 
	if (opk == ABAJO){ opk = 's';}
	if (opk == IZQUIERDA){ opk = 'a';}
	if (opk == DERECHA){ opk = 'd';}
		switch(opk){ //muevo la serpiente excepto si va en la direccion opuesta (donde esta la cola)
			case 'a':
			case 'A':
				if(snakeDirec!=r)
					snakeDirec = l;
				break;
			case 's':
			case 'S':
				if(snakeDirec!=u)
					snakeDirec = d; 
				break;
			case 'D':
			case 'd':
				if(snakeDirec!=l)
					snakeDirec = r;
				break;
			case 'W':
			case 'w':
				if(snakeDirec!=d)
					snakeDirec = u;
				break;
			case 'Q':
			case 'q':
				fin = true;
				break;
			case 'P':
			case 'p':
				snakeDirec = st;
				break
		} 
	}
}
// toda la logica del juego ( comer una manzana; chocarse; etc )
void gamelogic(){
	//creo la cola de la serpiente
	int	 prevTailPosX = tailPosX[0], prevTailPosY = tailPosY[0];
	int prevTailPosX2, prevTailPosY2;
	tailPosX[0] = headPos[1];
	tailPosY[0] = headPos[0];
	for(int i=1; i< tailL;i++){
		prevTailPosX2 = tailPosX[i];
		prevTailPosY2 = tailPosY[i];
		tailPosX[i] = prevTailPosX;
		tailPosY[i] = prevTailPosY;
		prevTailPosX = prevTailPosX2;
		prevTailPosY = prevTailPosY2;
	}
	// aumento o disminuyo pa posicion de la cabeza de la serpiente.
	switch(snakeDirec){
		case st: 
			break;
		case l:
			headPos[1]--;
			break;
		case r:
			headPos[1]++;
			break;
		case d:
			headPos[0]++;
			Sleep(5);
			break;
		case u:
			headPos[0]--;
			Sleep(5);
			break;
	}
	// si la cabeza choca con los bordes
	if((headPos[1]>=23)||(headPos[1]<=0)||(headPos[0]<=-2)||(headPos[0]>=23)){
		fin = true; lose(); //cout<<"Limit"; //-> Prueba para ver el tipo de muerte.
	}
	// si se come una manzana
	if(headPos[1]==foodPos[0] && headPos[0]==foodPos[1]){
		score++;
		do{
		foodPos[0] = rand()%23;
		foodPos[1] = rand()%23;
	 	} while((foodPos[1]<0)||(foodPos[1]>21)||(foodPos[0]<2)||(foodPos[0]>21)||(foodPos[1]==headPos[0])||(foodPos[0]==headPos[1]));
		tailL++;
	}
	//si la cabeza se choca con la cola
	for(int i = 0; i<tailL;i++){
	if(tailPosX[i] == headPos[1] && tailPosY[i] == headPos[0] && snakeDirec != st){
		fin=true; lose(); //cout<<"Tail."; //-> Prueba para ver el tipo de muerte.
	}}			
}

	
	

int main(){
	setlocale(LC_ALL, ""); // para los signos y/o acentos
	srand(time(0));
	inicio();
while(fin==false){
	render();
	input();
	gamelogic();
	Sleep(50); 
}
	

return 0;}
