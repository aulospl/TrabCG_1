//Choyoung Lim				6436060
//Luiz Eduardo Dorici		4165850
//Aulos Plautius M Marino	7986409

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

using namespace std;

#define PI 3.141592653589793238

/*Tamanho janela*/
int windowW = 800;                        //Tamanho da tela na Horizontal.
int windowH = 600;                        //Tamanho da tela na Vertical.

/*Posicao do centro das figuras*/

//cefalotorax
GLfloat Xctx = 400;                        //posicao em X do centro da cabeça da aranha.
GLfloat Yctx = 370;                        //posicao em Y do centro do cabeça da aranha.
//abdomen
GLfloat Xabd = 400;                        //posicao em X do centro da bunda da aranha.
GLfloat Yabd = 300;                        //posicao em Y do centro da bunda da aranha.

GLfloat X11 = Xctx + -50;
GLfloat Y11 = Yctx + 50;
GLfloat X12 = Xctx + -75;
GLfloat Y12 = Yctx + 125;

GLfloat X21 = Xctx + -60;
GLfloat Y21 = Yctx + 23;
GLfloat X22 = Xctx + -119;
GLfloat Y22 = Yctx + 85;

GLfloat X31 = Xctx + -60;
GLfloat Y31 = Yctx + -18;
GLfloat X32 = Xctx + -129;
GLfloat Y32 = Yctx + -48;

GLfloat X41 = Xctx + -50;
GLfloat Y41 = Yctx + -40;
GLfloat X42 = Xctx + -95;
GLfloat Y42 = Yctx + -105;

GLfloat X11d = Xctx - -50;
GLfloat X12d = Xctx - -75;

GLfloat X21d = Xctx - -60;
GLfloat X22d = Xctx - -119;

GLfloat X31d = Xctx - -60;
GLfloat X32d = Xctx - -129;

GLfloat X41d = Xctx - -50;
GLfloat X42d = Xctx - -95;



/*Incremento de cada eixo das figuras*/
GLfloat incXcir = 0;                    //incremento em X do circulo.
GLfloat incYcir = 0;                    //incremento em Y do circulo.

GLint Xposition = 400;
GLint Yposition = 370;

void Draw() {
    glLineWidth(3.0f);

    //cefalotorax
    glBegin(GL_POLYGON);
    //Inicia o desenho de um poligono.
    glColor3f(0.02,0.02,0.02);                                                    //Cor do poligono.
    for (float i = 0; i < 2*PI ; i+=0.1){                                //Rotaciona os pontos do poligono para formar um circulo.
        glVertex2f(30.0*(float)cos(i)+Xctx , 30.0*(float)sin(i)+Yctx);    //Coordenadas do circulo de raio 20 pixels.
    }
    glEnd();                                                            //Finaliza o circulo.

    //abdomen
    glBegin(GL_POLYGON);                                                //Inicia o desenho de um poligono.
    glColor3f(0.02,0.02,0.02);                                                    //Cor do poligono.
    for (float i = 0; i < 2*PI ; i+=0.1){                                //Rotaciona os pontos do poligono para formar um circulo.
        glVertex2f(50.0*(float)cos(i)+Xabd , 50.0*(float)sin(i)+Yabd);    //Coordenadas do circulo de raio 20 pixels.
    }
    glEnd();

    //perna 1
    glBegin(GL_LINES);
    glColor3f(1,0,0.0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X11, Y11);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,0,0.0);
    glVertex2f(X11, Y11);
    glVertex2f(X12, Y12);
    glEnd();

    //perna 2
    glBegin(GL_LINES);
    glColor3f(0,1,0.0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X21, Y21);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,1,0.0);
    glVertex2f(X21, Y21);
    glVertex2f(X22, Y22);
    glEnd();

    //perna 3
    glBegin(GL_LINES);
    glColor3f(0,0,1.0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X31, Y31);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,1.0);
    glVertex2f(X31, Y31);
    glVertex2f(X32, Y32);
    glEnd();

    //perna 4
    glBegin(GL_LINES);
    glColor3f(1,1,0.0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X41, Y41);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,0.0);
    glVertex2f(X41, Y41);
    glVertex2f(X42, Y42);
    glEnd();

    //perna 1d
    glBegin(GL_LINES);
    glColor3f(1,0,0.0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X11d, Y11);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,0,0.0);
    glVertex2f(X11d, Y11);
    glVertex2f(X12d, Y12);
    glEnd();

    //perna 2d
    glBegin(GL_LINES);
    glColor3f(0,1,0.0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X21d, Y21);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,1,0.0);
    glVertex2f(X21d, Y21);
    glVertex2f(X22d, Y22);
    glEnd();

    //perna 3d
    glBegin(GL_LINES);
    glColor3f(0,0,1.0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X31d, Y31);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,1.0);
    glVertex2f(X31d, Y31);
    glVertex2f(X32d, Y32);
    glEnd();

    //perna 4d
    glBegin(GL_LINES);
    glColor3f(1,1,0.0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X41d, Y41);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,0.0);
    glVertex2f(X41d, Y41);
    glVertex2f(X42d, Y42);
    glEnd();
}

/*Funcao responsavel por desenhar todas as fuguras na janela.*/
void onDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);        //Limpa o buffer responsavel por desenhar

    /*Quando se altera o tamanho da tela a imagem acompanha*/
    glMatrixMode(GL_PROJECTION);        //Projeta a imagem na tela
    glLoadIdentity();                    //Carrega a MatrixMode
    gluOrtho2D(0,windowW,0,windowH);    //Limita a area da tela no primeiro quadrante

    /*Desenha Circulo*/
    glMatrixMode(GL_MODELVIEW);            //Projeta a imagem na tela
    glLoadIdentity();                    //Carrega MatrixMode.


    glPushMatrix();
    {
        Draw();
    }
    glPopMatrix();

    glutSwapBuffers();                    //Troca o buffer
    glFlush();

}

/*Funcao responsavel pela movimentacao das figuras*/
void Movimenta() {

    //Verifica se o circulo saiu da janela.
    /*if(Xcir >windowW+20 || Xcir < -20 || Ycir >windowH+20 || Ycir < -20){
     Xcir = 40;                        //Reseta a posicao de inicio.
     Ycir = 40;
     }*/

    cout << Xctx << " - " << Xposition << " - " << Yctx << " - " << Yposition << endl;

    if(abs(Xposition - Xctx) > 2) {
        Xctx += incXcir; //incrementa o centro do circulo em X.
        Xabd += incXcir;
        X11 += incXcir;
        X12 += incXcir;
        X21 += incXcir;
        X22 += incXcir;
        X31 += incXcir;
        X32 += incXcir;
        X41 += incXcir;
        X42 += incXcir;
        X11d += incXcir;
        X12d += incXcir;
        X21d += incXcir;
        X22d += incXcir;
        X31d += incXcir;
        X32d += incXcir;
        X41d += incXcir;
        X42d += incXcir;
    }

    if(abs((- Yposition + windowH) - (Yctx - 19)) > 2) {
        Yctx += incYcir; //incrementa o centro do circulo em Y.
        Yabd += incYcir;
        Y11 += incYcir;
        Y12 += incYcir;
        Y21 += incYcir;
        Y22 += incYcir;
        Y31 += incYcir;
        Y32 += incYcir;
        Y41 += incYcir;
        Y42 += incYcir;
    }

    glutPostRedisplay();                //Redesenha as figuras na janela.
}

/*Recebe comandos do mouse */
void Mouse(GLint botao, GLint estado,  GLint x, GLint y) {

    int velPadrao = 100;                                    //Velocidade padronizada, sem ela fica muito rapido.

    //Verifica se houve click com o botao esquerdo do mouse.
    if(botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {

        Xposition = x;
        Yposition = y;

        incXcir = (x - Xctx)/velPadrao;                        //Incrementa X do circulo conforme click do mouse.
        incYcir = ((-y + windowH)-Yctx)/velPadrao;            //Incrementa Y do circulo conforme click do mouse.
    }
}

/*Responsavel por realizar a configuracao inicial da janela.*/
void Inicializa(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );                //Buffer e esquema de cores.
    glutInitWindowSize(windowW,windowH);                        //Tamanho da tela em pixels.
    glutInitWindowPosition((1366-windowW)/2, (768-windowH)/2);    //Posicao inicial da janela em pixels ((tam monitor - tam janela)/2 = centro)
    glutCreateWindow("OpenGL");                                    //Criacao de uma janela.
    glClearColor(0.91,0.91,0.91,1);                                        //Cor de background.
}

/*Coleta dados de entrada e realiza a saida atraves do monitor.*/
void InputeOutput() {

    glutMouseFunc(Mouse);                //Funcao responsavel pelos controles do mouse.
    glutDisplayFunc(onDisplay);                //Funcao responsavel por redesenhar a tela.
    Movimenta();
}

/*Gerencia a criacao de janela, chamada de funcoes de controle e o loop principal*/
int main(int argc, char **argv) {

    Inicializa(argc, argv);
    InputeOutput();
    glutIdleFunc(InputeOutput);
    glutMainLoop();                        //Loop Infinito

    return 0;
}
