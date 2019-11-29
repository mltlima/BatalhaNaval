/*
 *  Batalha Naval
 *  Trabalho Computacao 1 UFRJ
 *  Grupo 10
 */

#include<stdio.h>
#include<stdlib.h>

#define VER  "\033[0;31m"    // Cor vermelha
#define CIA  "\033[1;36m"    // Cor Ciano
#define RESET "\033[0m"      // Reseta cor
#define TEMPO 100000
#define CLEAN "\033[H\033[J" // Limpa terminal UNIX
#define BLINK "\e[5m"        // Texto pisca terminal UNIX
#define INVERTE "\e[7m"       // Inverte cores terminal UNIX


void geraTabuleiro(char tab[][10]){
	 int i,j;
	 for(i= 0; i < 10; i++)
		for(j =0; j<10; j++){
					tab[i][j]= '~';
				} 			
}

void titulo(void)
{
    printf(CIA"                            ██████╗  █████╗ ████████╗ █████╗ ██╗     ██╗  ██╗ █████╗     ███╗   ██╗ █████╗ ██╗   ██╗ █████╗ ██╗ \n");    
    usleep(TEMPO);
    printf("                            ██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██║     ██║  ██║██╔══██╗    ████╗  ██║██╔══██╗██║   ██║██╔══██╗██║     \n");
    usleep(TEMPO);
    printf("                            ██████╔╝███████║   ██║   ███████║██║     ███████║███████║    ██╔██╗ ██║███████║██║   ██║███████║██║     \n");
    usleep(TEMPO);
    printf("                            ██╔══██╗██╔══██║   ██║   ██╔══██║██║     ██╔══██║██╔══██║    ██║╚██╗██║██╔══██║╚██╗ ██╔╝██╔══██║██║     \n");
    usleep(TEMPO);
    printf("                            ██████╔╝██║  ██║   ██║   ██║  ██║███████╗██║  ██║██║  ██║    ██║ ╚████║██║  ██║ ╚████╔╝ ██║  ██║███████╗ \n");
    usleep(TEMPO);
    printf("                            ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝    ╚═╝  ╚═══╝╚═╝  ╚═╝  ╚═══╝  ╚═╝  ╚═╝╚══════╝\n"RESET);
    
}

void instrucoes(void)
{   
    printf(CLEAN);
    titulo();
    printf("\n  O jogo apenas terminara quando voce ou seu inimigo destruirem todos os Navios, quem destruir todos os navios primeiro sera o VENCEDOR dessa Batalha");
	printf("\n \n"CIA"  Regras: Os jogadores terao direito ao um tiro de cada vez, mas quem acertar o navio inimigo podera continuar atirando ate errar\n"RESET);
	printf("  O tamanho dos navios:\n  Submarino: 1 \n  Cruzador: 2 \n  Hidro-Aviao: 3 \n  Encouracado: 4\n  Porta-Avioes: 5 \n \n");
	printf("\n O JOGO MARCARA"VER " ■ "RESET" QUANDO UM TIRO ACERTAR UM NAVIO E SERA COLOCADO "CIA" ■ "RESET" QUANDO UM TIRO FOR NA AGUA \n");	
    printf( BLINK INVERTE"\n\n\n Pressione enter para voltar ao menu\n"RESET);
    char enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
    
}

void menu(void)
{
    printf("\n\n\n\n");
    printf(CIA" MENU \n"RESET);
    //Exibe as opções para o usuário
    printf(" 1. Jogar\n");
    printf(" 2. Demo\n");
    printf(" 3. Instruções\n");
    printf(" 4. Sair do jogo\n");
}

void tabuleiroComputador(char tab[][10]){
		int i, j;
		for(i= 0; i < 10; i++){
			for(j =0; j<10; j++){
				if(j == 0){
					if(i<=9){
						printf(" ");
					}
					printf("%c ", i + 65);
				}
				if(tab[i][j]=='*'){
					printf(VER"■ "RESET);
                }
                else if (tab[i][j]=='x'){
                    printf(CIA"■ "RESET);
                }
				else{
					printf("■ ");
				}
			}
			printf("\n");
		}
}

void tabuleiroJogador(char tab[][10]){
		int i,j;
		for(i= 0; i < 10; i++)
			for(j =0; j<10; j++){
				if(j == 0){
					if(i<=9){
						printf(" ");
					}
					printf("%c ", i + 65);
				}
				if(tab[i][j]=='*'){
					printf(VER"■ "RESET);
                }
                else if (tab[i][j]=='x'){
                    printf(CIA"■ "RESET);
                }
                else if (tab[i][j] == 'H' || tab[i][j] == 'C' || tab[i][j] == 'E' || tab[i][j] == 'S' || tab[i][j] == 'P')
                {
                    printf("%c ",tab[i][j]);
                }
                
				else{
					printf("■ ");
				}


				if(j == 9){
					printf("\n");
				}
		}
}


int main(void)
{   
    int opcaoMenu;
    char entradaUsuario[1];

    while (1)                    // Loop do MENU principal
    {
        printf(CLEAN);
        titulo();
        menu();


        printf("\n Escolha uma das opcoes: ");

        while (1)          // Loop ate uma opcao valida ser digitada
        {
            scanf("%s",entradaUsuario);
            while (getchar() != '\n');

            sscanf(entradaUsuario, "%d", &opcaoMenu);
            if (opcaoMenu == 1 || opcaoMenu == 2 || opcaoMenu == 3 || opcaoMenu == 4)
            {
                break;
            }
            printf("\n Digite uma opcao valida: ");
            
        }

        switch (opcaoMenu)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            instrucoes();
            break;
        case 4:
            exit(1);
        
        default:
            break;
        }
    }
}