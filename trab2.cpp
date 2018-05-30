//Choyoung Lim               6436060
//Luiz Eduardo Dorici        4165850
//Aulos Plautius M Marino    7986409

#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>

int width = 1200;
int height = 1200;


//cefalotorax
GLfloat Xctx = 0;                        //posicao em X do centro da cabeça da aranha.
GLfloat Yctx = 0;                        //posicao em Y do centro do cabeça da aranha.
//abdomen
GLfloat Xabd = 0;                        //posicao em X do centro da bunda da aranha.
GLfloat Yabd = -70;                        //posicao em Y do centro da bunda da aranha.

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
	i[0] = 5.0;
	i[1] = i[2] = 0.0;
	j = new float[3];
	j[0] = j[2] = 0.0;
	j[1] = 5.0;
	k = new float[3];
	k[0] = k[1] = 0.0;
	k[2] = 5.0;
	drawAxes(basePoint, i, j, k);
}

/**
 * @desc Função de callback para desenho na tela.
 */
void displayCallback()
{
	/** Limpa a janela APENAS uma vez */
	glClear(GL_COLOR_BUFFER_BIT);
	
	/* Espessura da linha-perna */
	glLineWidth(3.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	/** Desenha a janela esquerda inferior */
	glViewport(0, 0, width/2, height/2);
	glLoadIdentity();
	//gluLookAt(3.0, 2.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	gluLookAt(10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	drawWCAxes();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(3.5, 0.0, 0.0);
	glutSolidSphere(2.0, 30, 30);
	glTranslatef(-3.5, -0.0, -0.0);
	glutSolidSphere(1.75, 30, 30);
	glBegin(GL_LINES);
  		glVertex3f(0.0f, 0.0f, 0.0f);
  		glVertex3f(5.0f, 5.0f, 5.0f);
	glEnd();
	
	/** Desenha a janela direita inferior */
	glViewport(width/2, 0, width/2, height/2);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	drawWCAxes();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(3.5, 0.0, 0.0);
	glutSolidSphere(2.0, 30, 30);
	glBegin(GL_LINES);
		glVertex3f(5.0f, 5.0f, 5.0f);
  		glVertex3f(5.0f, 5.0f, 5.0f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(5.0f, 5.0f, 5.0f);
		glVertex3f(0.0f, 0.0f, -5.0f);
	glEnd();
	/* Desenha janela esquerda superior*/
	glViewport(0, height/2, width/2, height/2);
	glLoadIdentity();
	gluLookAt(2.0, 1.0, 10.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0);
	drawWCAxes();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(3.5, 0.0, 0.0);
	glutSolidSphere(2.0, 30, 30);
	glTranslatef(-3.5, -0.0, -0.0);
	glutSolidSphere(1.75, 30, 30);

	glBegin(GL_LINES);
  		glVertex3f(0.0f, 0.0f, 0.0f);
  		glVertex3f(5.0f, 5.0f, 5.0f);
	glEnd();
	/* Desenha janela direita superior */
	glViewport(width/2, height/2, width/2, height/2);
	glLoadIdentity();		
	//gluLookAt(1.0, 0.0, 10.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.5);
	gluLookAt(0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0);
	drawWCAxes();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(3.5, 0.0, 0.0);
	glutSolidSphere(2.0, 30, 30);
	glTranslatef(-3.5, -0.0, -0.0);
	glutSolidSphere(1.75, 30, 30);	
	glBegin(GL_LINES);
  		glVertex3f(0.0f, 0.0f, 0.0f);
  		glVertex3f(5.0f, 5.0f, 5.0f);
	glEnd();
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

	/** Passo 3: Executa o programa */
	glutMainLoop();
	return 0;
}
