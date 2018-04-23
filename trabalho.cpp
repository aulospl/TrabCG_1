#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;

#define PI 3.1415926535897932384

/*Tamanho janela*/
int windowW = 800;						//Tamanho da tela na Horizontal.
int windowH = 600;						//Tamanho da tela na Vertical.

/*Posicao do centro das figuras*/

GLfloat XcirHead = 400;						//posicao em X do centro da cabeça da aranha.
GLfloat YcirHead = 370;						//posicao em Y do centro do cabeça da aranha.

GLfloat XcirButt = 400;						//posicao em X do centro da bunda da aranha.
GLfloat YcirButt = 300;						//posicao em Y do centro da bunda da aranha.


GLfloat Xart1pata1 = 355;	
GLfloat Xart2pata1 = 285;
					
GLfloat Yart1pata1 = 390;
GLfloat Yart2pata1 = 395;
GLfloat Yart1pata2 = 390;
GLfloat Yart2pata2 = 395;
	
GLfloat Xart1pata2 = 445;	
GLfloat Xart2pata2 = 515;	
						
GLfloat Yart1pata34 = 360;

GLfloat Yart1pata56 = 400;	

GLfloat Yart1pata78 = 400;	
										


/*Incremento de cada eixo das figuras*/
GLfloat incXcir = 0;					//incremento em X do circulo.
GLfloat incYcir = 0;					//incremento em Y do circulo.

GLint Xposition = 400;
GLint Yposition = 370;

/*Funcao responsavel por desenhar todas as fuguras na janela.*/
void onDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);		//Limpa o buffer responsavel por desenhar

	/*Quando se altera o tamanho da tela a imagem acompanha*/
	glMatrixMode(GL_PROJECTION);		//Projeta a imagem na tela
	glLoadIdentity();					//Carrega a MatrixMode
	gluOrtho2D(0,windowW,0,windowH);	//Limita a area da tela no primeiro quadrante

	/*Desenha Circulo*/
	glMatrixMode(GL_MODELVIEW);			//Projeta a imagem na tela
	glLoadIdentity();					//Carrega MatrixMode.


	glPushMatrix();
	{
		glBegin(GL_POLYGON);        										//Inicia o desenho de um poligono.
		glColor3f(0.02,0.02,0.02);													//Cor do poligono.
		for (float i = 0; i < 2*PI ; i+=0.1){								//Rotaciona os pontos do poligono para formar um circulo.
	 		glVertex2f(30.0*(float)cos(i)+XcirHead , 30.0*(float)sin(i)+YcirHead);	//Coordenadas do circulo de raio 20 pixels.
		}
	 	glEnd();															//Finaliza o circulo.

		/*Desenha Circulo*/
		glMatrixMode(GL_MODELVIEW);			//Projeta a imagem na tela
		glLoadIdentity();					//Carrega MatrixMode.


		glBegin(GL_POLYGON);        										//Inicia o desenho de um poligono.
		glColor3f(0.02,0.02,0.02);													//Cor do poligono.
		for (float i = 0; i < 2*PI ; i+=0.1){								//Rotaciona os pontos do poligono para formar um circulo.
	 		glVertex2f(50.0*(float)cos(i)+XcirButt , 50.0*(float)sin(i)+YcirButt);	//Coordenadas do circulo de raio 20 pixels.
		}
	 	glEnd();	

		/*Desenha articulação 1 da pata 1*/
		glMatrixMode(GL_MODELVIEW);			//Projeta a imagem na tela.
		glLoadIdentity();					//Carrega MatrixMode.

		glBegin(GL_QUADS);				//Inicia o desenho do triangulo
			glColor3f(0,0,0);					//cor do triangulo
			glVertex2f(Xart1pata1-40,Yart1pata1+10);			//Coordenadas dos pontos do triangulo.
			glVertex2f(Xart1pata1-40,Yart1pata1+25);
			glVertex2f(Xart1pata1+20,Yart1pata1-5);
			glVertex2f(Xart1pata1+30,Yart1pata1-25);
		glEnd();							

		/*Desenha articulação 2 da pata 1*/
		glMatrixMode(GL_MODELVIEW);			//Projeta a imagem na tela.
		glLoadIdentity();					//Carrega MatrixMode.

		glBegin(GL_QUADS);				//Inicia o desenho do triangulo
			glColor3f(0,0,0);					//cor do triangulo
			glVertex2f(Xart2pata1-70,Yart2pata1-35);			//Coordenadas dos pontos do triangulo.
			glVertex2f(Xart2pata1-40,Yart2pata1-15);
			glVertex2f(Xart2pata1+30,Yart2pata1+20);
			glVertex2f(Xart2pata1+30,Yart2pata1+5);
		glEnd();									

		/*articulação 1 da pata 2*/
		glMatrixMode(GL_MODELVIEW);			//Projeta a imagem na tela.
		glLoadIdentity();					//Carrega MatrixMode.

		glBegin(GL_QUADS);				//Inicia o desenho do triangulo
			glColor3f(0,0,0);					//cor do triangulo
			glVertex2f(Xart1pata2+40,Yart1pata2+25);			//Coordenadas dos pontos do triangulo.
			glVertex2f(Xart1pata2+40,Yart1pata2+10);
			glVertex2f(Xart1pata2-30,Yart1pata2-25);
			glVertex2f(Xart1pata2-20,Yart1pata2-5);
		glEnd();							

		/*Desenha articulação 2 da pata 2*/
		glMatrixMode(GL_MODELVIEW);			//Projeta a imagem na tela.
		glLoadIdentity();					//Carrega MatrixMode.

		glBegin(GL_QUADS);				
			glColor3f(0,0,0);					
			glVertex2f(Xart2pata2+40,Yart2pata2-15);			
			glVertex2f(Xart2pata2+70,Yart2pata2-35);
			glVertex2f(Xart2pata2-30,Yart2pata2+5);
			glVertex2f(Xart2pata2-30,Yart2pata2+20);
		glEnd();	
	}							

	glutSwapBuffers();					//Troca o buffer
	glFlush();

}

/*Funcao responsavel pela movimentacao das figuras*/
void Movimenta() {

	//Verifica se o circulo saiu da janela.
	/*if(Xcir >windowW+20 || Xcir < -20 || Ycir >windowH+20 || Ycir < -20){
		Xcir = 40;						//Reseta a posicao de inicio.
		Ycir = 40;
	}*/

	cout << XcirHead << " - " << Xposition << " - " << YcirHead << " - " << Yposition << endl;

	if(abs(Xposition - XcirHead) > 2) {
		XcirHead += incXcir; //incrementa o centro do circulo em X.
		XcirButt += incXcir;
		Xart1pata1 += incXcir;
		Xart1pata2 += incXcir;
		Xart2pata1 += incXcir;
		Xart2pata2 += incXcir;
	}

	if(abs((- Yposition + windowH) - (YcirHead - 19)) > 2) {
		YcirHead += incYcir; //incrementa o centro do circulo em Y.
		YcirButt += incYcir;
		Yart1pata1 += incYcir;
		Yart2pata1 += incYcir;
		Yart1pata2 += incYcir;
		Yart2pata2 += incYcir;
	}

	glutPostRedisplay();				//Redesenha as figuras na janela.
}

/*Recebe comandos do mouse */
void Mouse(GLint botao, GLint estado,  GLint x, GLint y) {

	int velPadrao = 100;									//Velocidade padronizada, sem ela fica muito rapido.

	//Verifica se houve click com o botao esquerdo do mouse.
	if(botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
	
		Xposition = x;
		Yposition = y;

		incXcir = (x - XcirHead)/velPadrao;						//Incrementa X do circulo conforme click do mouse.
		incYcir = ((-y + windowH)-YcirHead)/velPadrao;			//Incrementa Y do circulo conforme click do mouse.
	}
}

/*Responsavel por realizar a configuracao inicial da janela.*/
void Inicializa(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );				//Buffer e esquema de cores.
	glutInitWindowSize(windowW,windowH);						//Tamanho da tela em pixels.
	glutInitWindowPosition((1366-windowW)/2, (768-windowH)/2);	//Posicao inicial da janela em pixels ((tam monitor - tam janela)/2 = centro)
	glutCreateWindow("OpenGL");									//Criacao de uma janela.
	glClearColor(0.91,0.91,0.91,1);										//Cor de background.
}

/*Coleta dados de entrada e realiza a saida atraves do monitor.*/
void InputeOutput() {

	glutMouseFunc(Mouse);				//Funcao responsavel pelos controles do mouse.
	glutDisplayFunc(onDisplay);				//Funcao responsavel por redesenhar a tela.
	Movimenta();
}

/*Gerencia a criacao de janela, chamada de funcoes de controle e o loop principal*/
int main(int argc, char **argv) {

	Inicializa(argc, argv);
	InputeOutput();
	glutIdleFunc(InputeOutput);
	glutMainLoop();						//Loop Infinito

	return 0;
}
