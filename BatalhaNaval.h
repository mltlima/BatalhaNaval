#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define VERDE "\e[92m"       // Cor verde
#define VER  "\033[0;31m"    // Cor vermelha
#define CIA  "\033[1;36m"    // Cor Ciano
#define RESET "\033[0m"      // Reseta cor
#define TEMPO 100000
#define CLEAN "\033[H\033[J" // Limpa terminal UNIX
#define BLINK "\e[5m"        // Texto pisca terminal UNIX
#define INVERTE "\e[7m"       // Inverte cores terminal UNIX


struct VETOR
{
	int direcao;
};

struct VETOR delCoordenada[4];  // Armazena as 4 coordenas  if valor == 1  nao ha  mais possibilidades de acerto na linha/coluna
struct VETOR vazia[4];	// Limpa a struct anterior	

// Funcoes prototipos

void geraTabuleiro(char tab[][10]);
void titulo(void);
void instrucoes(void);
void menu(void);
void tabuleiroComputador(char tab[][10]);
void tabuleiroJogador(char tab[][10]);
void posicionamentoNavios(char tab[][10]);
void tiro(char tab[][10], int i, int j, int c[]);
int verificador(char tabs[][10], int i, int j);
int modoAlvo(char tab[][10], int *i, int *j,int *direcao,int acertoI,int acertoJ);
void jogoPrincipal(void);
