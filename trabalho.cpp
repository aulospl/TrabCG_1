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

GLfloat XcirHead = 400;						//posicao em X do centro do quadrado.
GLfloat YcirHead = 370;						//posicao em Y do centro do quadrado.

GLfloat XcirButt = 400;						//posicao em X do centro do quadrado.
GLfloat YcirButt = 300;						//posicao em Y do centro do quadrado.


/*Incremento de cada eixo das figuras*/
GLfloat incXcir = 0;					//incremento em X do centro do triangulo.
GLfloat incYcir = 0;					//incremento em Y do centro do triangulo.

GLint Xposition = 400;
GLint Yposition = 370;

//int globalflag = 0;


/*Funcao responsavel por desenhar todas as fuguras na janela.*/
void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);		//Limpa o buffer responsavel por desenhar

	/*Quando se altera o tamanho da tela a imagem acompanha*/
	glMatrixMode(GL_PROJECTION);		//Projeta a imagem na tela
	glLoadIdentity();					//Carrega a MatrixMode
	gluOrtho2D(0,windowW,0,windowH);	//Limita a area da tela no primeiro quadrante

	/*Desenha Circulo*/
	glMatrixMode(GL_MODELVIEW);			//Projeta a imagem na tela
	glLoadIdentity();					//Carrega MatrixMode.


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


	//cout << "Mouse X" << Xposition << " Mouse Y" << Yposition << endl;
	//cout << "Obj X" << XcirButt << " Obj Y" << YcirButt << endl;

		//int dist = sqrt(pow((XcirHead - Xposition),2) + pow((YcirHead - Yposition),2));
	

		cout << XcirHead << " - " << Xposition << " - " << YcirHead << " - " << Yposition << endl;
		//cout << "distancia: " << dist << endl;

		//if( dist > 100) {
		if(abs(Xposition - XcirHead) > 3) {
			XcirHead += incXcir; //incrementa o centro do circulo em X.
			XcirButt += incXcir;
		}

		if(abs((- Yposition + windowH) - YcirHead) > 3) {
			YcirHead += incYcir; //incrementa o centro do circulo em Y.
			YcirButt += incYcir;
		}
		//}

	glutPostRedisplay();				//Redesenha as figuras na janela.
}

/*Recebe comandos do mouse */
void Mouse(GLint botao, GLint estado,  GLint x, GLint y) {

	int velPadrao = 100;									//Velocidade padronizada, sem ela fica muito rapido.

	//Verifica se houve click com o botao esquerdo do mouse.
	if(botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
	
		Xposition = x;
		Yposition = y;

		//int gap = abs(Xposition - XcirHead);

		/*if(globalflag < 10) {
			cout << "distancia " << gap << endl;
			cout << "Mouse X" << Xposition << " Mouse Y" << Yposition << endl;
			cout << "Obj X" << XcirButt << " Obj Y" << YcirButt << endl;
			globalflag++;
		}*/

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
	glutDisplayFunc(Draw);				//Funcao responsavel por redesenhar a tela.
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
