//Choyoung Lim                6436060
//Luiz Eduardo Dorici        4165850
//Aulos Plautius M Marino    7986409

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define FPS 30

GLint width = 800;
GLint height = 600;

GLfloat globalTimeSeconds = 0;
GLint globalFrameCounter = 0;
GLint globalMouseScreenX = 0;
GLint globalMouseScreenY = 0;
GLint globalTimerTriggered = 0;
const int FRAME_TIME_MS = 1000 / FPS;
GLfloat angle = 0;
// eixo X = vermelho
// eixo Y = verde
// eixo Z = azul

//cefalotorax
GLfloat Xctx = 0;                        //posicao em X do centro da cabeça da aranha.
GLfloat Yctx = 0;                        //posicao em Y do centro do cabeça da aranha.
//abdomen
GLfloat Xabd = 0;                        //posicao em X do centro da bunda da aranha.
GLfloat Yabd = -70;                        //posicao em Y do centro da bunda da aranha.

//pernas
//XYZ dos pontos da aresta.
GLfloat X11 = Xctx + -2.5;
GLfloat Y11 = Yctx + 2.5;
GLfloat X12 = Xctx + -3.75;
GLfloat Y12 = Yctx + 6.25;

GLfloat X21 = Xctx + -3;
GLfloat Y21 = Yctx + 1.15;
GLfloat X22 = Xctx + -6;
GLfloat Y22 = Yctx + 4.25;

GLfloat X31 = Xctx + -3;
GLfloat Y31 = Yctx + -0.9;
GLfloat X32 = Xctx + -6.5;
GLfloat Y32 = Yctx + -2.4;

GLfloat X41 = Xctx + -2.5;
GLfloat Y41 = Yctx + -2;
GLfloat X42 = Xctx + -4.75;
GLfloat Y42 = Yctx + -5.25;
//X do outro lado
GLfloat X11d = Xctx - -2.5;
GLfloat X12d = Xctx - -3.75;

GLfloat X21d = Xctx - -3;
GLfloat X22d = Xctx - -6;

GLfloat X31d = Xctx - -3;
GLfloat X32d = Xctx - -6.5;

GLfloat X41d = Xctx - -2.5;
GLfloat X42d = Xctx - -4.75;
//Z dos pontos da perna
GLfloat Zart = 3;
GLfloat Zbase = -2;

/**
 * @desc Desenha eixos de um sistema de coordenadas.
 * @param {float*} basePoint Ponto de origem de um sistema de coordenadas.
 * @param {float*} i Primeiro versor.
 * @param {float*} j Segundo versor.
 * @param {float*} k Terceiro versor.
 */
void drawAxes(float *basePoint, float *i, float *j, float *k)
{
    float currentColor[4];
    /** Armazena cor atual */
    glGetFloatv(GL_CURRENT_COLOR, currentColor);
    /** Desenha versores */
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(basePoint[0], basePoint[1], basePoint[2]);
    glVertex3f(i[0], i[1], i[2]);
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(basePoint[0], basePoint[1], basePoint[2]);
    glVertex3f(j[0], j[1], j[2]);
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(basePoint[0], basePoint[1], basePoint[2]);
    glVertex3f(k[0], k[1], k[2]);
    glEnd();
    /** Retorna para cor anterior */
    glColor3f(currentColor[0], currentColor[1], currentColor[2]);
}

/**
 * @desc Desenha as coordenadas globais.
 */
void drawWCAxes()
{
    float *basePoint, *i, *j, *k;
    basePoint = new float[3];
    basePoint[0] = basePoint[1] = basePoint[2] = 0.0;
    i = new float[3];
    i[0] = 500.0;
    i[1] = i[2] = 0.0;
    j = new float[3];
    j[0] = j[2] = 0.0;
    j[1] = 500.0;
    k = new float[3];
    k[0] = k[1] = 0.0;
    k[2] = 500.0;
    drawAxes(basePoint, i, j, k);
}

void drawSpider(){
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.0, 3.5, 0.0);
    glutSolidSphere(2.0, 30, 30);
    glTranslatef(-0.0, -3.5, -0.0);
    glutSolidSphere(1.75, 30, 30);

    //patas esquerdas
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(X11, Y11, Zart);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(X11, Y11, Zart);
    glVertex3f(X12, Y12, Zbase);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(X21, Y21, Zart);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(X21, Y21, Zart);
    glVertex3f(X22, Y22, Zbase);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(X31, Y31, Zart);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(X31, Y31, Zart);
    glVertex3f(X32, Y32, Zbase);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(X41, Y41, Zart);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(X41, Y41, Zart);
    glVertex3f(X42, Y42, Zbase);
    glEnd();

    //patas direitas
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(X11d, Y11, Zart);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(X11d, Y11, Zart);
    glVertex3f(X12d, Y12, Zbase);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(X21d, Y21, Zart);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(X21d, Y21, Zart);
    glVertex3f(X22d, Y22, Zbase);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(X31d, Y31, Zart);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(X31d, Y31, Zart);
    glVertex3f(X32d, Y32, Zbase);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(X41d, Y41, Zart);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(X41d, Y41, Zart);
    glVertex3f(X42d, Y42, Zbase);
    glEnd();
}


/**
 * @desc Função de callback para desenho na tela.
 */
void displayCallback()
{

    if(globalTimerTriggered != 1) {
        return;
    }
    angle += 0.5f;
    globalTimerTriggered = 0;

    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, width, height);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0, -height, 0);
    glVertex3f(0, height, 0);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-width, 0, 0);
    glVertex3f(width, 0, 0);
    glEnd();

    /* Espessura da linha-perna */
    glLineWidth(3.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    /** Desenha a janela esquerda inferior */
    glViewport(0, 0, width/2, height/2);
    glLoadIdentity();
    gluLookAt(15.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    drawWCAxes();
    glPushMatrix();
    {
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        drawSpider();
    }
    glPopMatrix();
    /** Desenha a janela direita inferior */
    glViewport(width/2, 0, width/2, height/2);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    drawWCAxes();
    glPushMatrix();
    {
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        drawSpider();
    }
    glPopMatrix();
    /* Desenha janela esquerda superior*/
    glViewport(0, height/2, width/2, height/2);
    glLoadIdentity();
    gluLookAt(2.0, 10.0, 15.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    drawWCAxes();
    glPushMatrix();
    {
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        drawSpider();
    }
    glPopMatrix();

    /* Desenha janela direita superior */
    glViewport(width/2, height/2, width/2, height/2);
    glLoadIdentity();
    //gluLookAt(1.0, 0.0, 10.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.5);
    gluLookAt(0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0);
    drawWCAxes();
    glPushMatrix();
    {
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        drawSpider();
    }
    glPopMatrix();
    /** Dispara os comandos APENAS uma vez */
    glFlush();

}

/**
 * @desc Função de callback para reshape.
 * @param {int} w Nova largura da janela.
 * @param {int} h Nova altura da janela.
 */
void reshapeCallback(int w, int h)
{

    /** Atualiza os valores da janela */
    width = w;
    height = h;
    /** Define o volume de vista */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) width/(GLfloat) height, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}


// Função para contar o tempo */
void onTimerTick(int frameCounter) {
    globalTimerTriggered = 1;
    globalFrameCounter = frameCounter;
    globalTimeSeconds = frameCounter * FRAME_TIME_MS / 1000.0f;

    glutTimerFunc(FRAME_TIME_MS, onTimerTick, frameCounter + 1);
    glutPostRedisplay();
}




int main(int argc, char **argv)
{
    /** Passo 1: Inicializa funções GLUT */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width, height);
    glutCreateWindow("Trabalho Parte 2");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /** Passo 2: Registra callbacks da OpenGl */
    glutDisplayFunc(displayCallback);
    glutReshapeFunc(reshapeCallback);

    /** Passo 3: função ocioso */
    glutIdleFunc(displayCallback);
    glutTimerFunc(0, onTimerTick, 0);

    /** Passo 4: Executa o programa */
    glutMainLoop();
    return 0;
}
