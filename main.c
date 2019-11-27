#include<stdio.h>//Jogo BATALHA NAVAL 
#include<stdlib.h>//Developed by GRUPO 10 ;)

#define VER  "\033[0;31m" // Cor vermelha
#define CIA  "\033[1;36m" // Cor Ciano
#define RESET "\033[0m"   // Reseta cor
#define TEMPO 100000

void geratab(char tab[][10]){
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

void mostratabPC(char tab[][10]){
		int i, j;
		for(i= 0; i < 10; i++){
			for(j =0; j<10; j++){
				if(j == 0){
					if(i<=9){
						printf(" ");
					}
					printf("%d ", i);
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
void mostratabJ(char tab[][10]){
		int i,j;
		for(i= 0; i < 10; i++)
			for(j =0; j<10; j++){
				if(j == 0){
					if(i<=9){
						printf(" ");
					}
					printf("%d ", i);
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
void naviosPC(char tab[][10]){
		int n, i, j;
       	n= rand()%3;
		if(n == 0){//1� Op��o dos navis do PC
			tab[0][1]= 'S'; //submarino
			
			for(j=2; j<=3;j++){//cruzador
				tab[2][j]= 'C'; 
			}
		
			tab[5][6]='H'; //hidroavi�o
			tab[6][5]='H'; //hidoavi�o
			tab[6][7]='H'; //hidroavi�o
			
			for(j=6;j<=9;j++){//encoura�ado
				tab[9][j]='E'; 
			}
			for(j=1;j<=5;j++){// porta-avioes
				tab[7][j]='P'; 
			}
		}
		if(n == 1){//2� Op��o dos navis do PC
			tab[1][7]= 'S'; //submarino
			
			for(i=3; i<=4;i++){//cruzador
				tab[i][9]= 'C'; 
			}
		
			tab[8][2]='H'; //hidroavi�o
			tab[9][1]='H'; //hidoavi�o
			tab[9][3]='H'; //hidroavi�o
			
			for(i=4;i<=7;i++){//encoura�ado
				tab[i][0]='E'; 
			}
			for(j=4;j<=8;j++){// porta-avioes
				tab[2][j]='P'; 
			}
		}
		if(n == 2){//3� Op��o dos navis do PC
			tab[8][0]= 'S'; //submarino
			
			for(j=8; j<=9;j++){//cruzador
				tab[9][j]= 'C'; 
			}
		
			tab[0][1]='H'; //hidroavi�o
			tab[1][0]='H'; //hidoavi�o
			tab[1][2]='H'; //hidroavi�o
			
			for(i=4;i<=7;i++){//encoura�ado
				tab[i][9]='E'; 
			}
			for(j=2;j<=6;j++){// porta-avioes
				tab[2][j]='P'; 
			}
		}
}
void naviosJ(char tab[][10]){
		int i, j;
		
		tab[9][8]='S';//submarino
		
		for(j=0; j<=1;j++){	//cruzador
			tab[0][j]='C';
		}
		
		tab[0][8]='H';//hidroavi�o
		tab[1][7]='H';//hidroavi�o
		tab[1][9]='H';//hidroavi�o
		
		for(i=3;i<=7;i++){//encura�ado
			tab[i][2]='E';
		}
		
		for(j=1;j<=5;j++){//porta-avi�o
			tab[9][j]='P';
		}

}
void tiro(char tab[][10], int i, int j, int c[]){
		if(tab[i][j]=='S'){
				tab[i][j]= '*';
				c[0]++;
			}
		else if(tab[i][j]=='C'){
			tab[i][j]= '*';
			c[1]++;			
		}
		else if(tab[i][j]=='H'){
			tab[i][j]= '*';
			c[2]++;			
		}
		else if(tab[i][j]=='E'){
			tab[i][j]= '*';
			c[3]++;			
		}
		else if(tab[i][j]=='P'){
			tab[i][j]= '*';
			c[4]++;	
		}
		else if(tab[i][j]=='~'){
			tab[i][j]='x';
		}
		else{
			printf("\n tiro j� foi dado\n");
		}
}
int verificador(char tabs[][10], int i, int j){
	if (tabs[i][j] == '*'){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int qmjoga, count=0, pntC=0, pntJ=0, numtirosC=0,numtirosJ=0, verificatiro, i, j, fim=0;
	int cC[5], cJ[5]; //s�o os contadores de cada navio, pois cada parte atingida soma um  e atingindo determinada quantia significa q o navio foi detruido
	char tabC[10][10],tabJ[10][10], op; //op ve se o usuario vai jogar ou fechar
	geratab(tabC); //Gera  o Tab. do PC
	geratab(tabJ);//Gera  o Tab. do Jogador
	for(i=0; i<5;i++){
		cC[i]=0;
		cJ[i]=0;
	}
	do{	
		naviosPC(tabC); //gera a posi��o dos navios do PC
		naviosJ(tabJ); //gera a posi��o dos navios do Jogador 
		titulo(); //apresenta��o e regras do Jogo
		printf("\n O jogo apenas terminara quando voce ou seu inimigo destruirem todos os Navios, quem destruir todos os navios primeiro sera o VENCEDOR dessa Batalha");
		printf("\n \n Regras: Os jogadores terao direito ao um tiro de cada vez, mas queM acertar o navio inimigo podera continuar atirando ate errar\n");
		printf("  A pontuacao dos navios:\n Submarino: 5 pontos\n Cruzador: 10 pontos\n Hidro-Aviao: 15 pontos\n Encouracado:20 pontos\n Porta-Avioes: 25 pontos\n \n");
		
		qmjoga = rand() % 2; //faz um sorteio de quem inicia o jogo - 0 � PC | 1 � Jogador
		do{//jogo
			
			do{ //vai repetir enquanto estiver acertando o tiro
				printf("\n O JOGO MARCARA"VER "'■'"RESET" QUANDO O SEU TIRO ACERTAR UM NAVIO DO INIMIGO, OU O INIMIGO ACERTAR SEU NAVIO E SERA COLOCADO "CIA"'■'"RESET" QUANDO FOR TIRO NA AGUA \n");	
				printf("\n Tabuleiro do inimigo:                     Pontos: %d \n \n", pntC);
				printf("   0 1 2 3 4 5 6 7 8 9 \n");
				mostratabPC(tabC);	//mostra o tabuleiro do PC(nao mostra os navios)
	
				printf("\n  - - - - - - - - - -  \n \n");
		
				printf(" Seu Tabuleiro:                 Pontos: %d \n \n", pntJ);
				printf("   0 1 2 3 4 5 6 7 8 9  \n");
				mostratabJ(tabJ); //mostra o tabuleiro do Jogador com os navios
				
				if(qmjoga ==0){ // PC atira
					printf("\n Seu Inimigo esta jogando... \n");
					i = rand() % 10;
					j = rand() % 10;			
					tiro(tabJ, i, j, cJ);
					numtirosC  ++;
					verificatiro = verificador(tabJ, i, j);
					if(verificatiro == 1){
						printf("\nInimigo acertou!");
					}else{
						printf("\nTiro errado!");
					}
					
					if(cJ[0] == 1){
						printf("\nInimigo derrubou seu Submarino!\n");
						cJ[0]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pntC +=5;
					}
					if(cJ[1] == 2){
						printf("\nInimigo derrubou seu Cruzador!\n");
						cJ[1]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pntC +=10;
					}
					if(cJ[2] == 3){
						printf("\nInimigo derrubou seu Hidro-Aviao!\n");
						cJ[2]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pntC +=15;
					}
					if(cJ[3]== 4){
						printf("\nInimigo derrubou seu Encouracado!\n");
						cJ[3]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pntC +=20;
					}
					if(cJ[4] == 5){
						printf("\nInimigo derrubou seu Porta-avioes!\n");
						cJ[4]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pntC +=25;
					}
				}
				else{// Jogador atira
				    do{
					    printf("\n Sua vez, escolha uma linha e coluna\n");
					    printf(" linha: ");
					    scanf("%d", &i);
					    printf("\n coluna: ");
					    scanf("%d", &j);
					    if(i<0 || i>9 || j<0 || j>9){
					        printf("Coordenadas inválidas,digite novamente\n");
					    }
				    }
				    while(i<0 || i>9 || j<0 || j>9);
					tiro(tabC, i, j, cC);
					verificatiro = verificador(tabC, i, j);
					numtirosJ  ++;
					
					if(verificatiro == 1){
						printf("\nVoce acertou!\n");
					}else{
						printf("\nTiro errado!\n");
					}
					
					if(cC[0] == 1){
						printf("\nVoce derrubou o Submarino do inimigo!\n");
						cC[0]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pntJ +=5;
					}
					if(cC[1] == 2){
						printf("\nVoce derrubou o cruzador do inimigo!\n");
						cC[1]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pntJ +=10;
					}
					if(cC[2] == 3){
						printf("\nVoce derrubou o Hidro-aviao do inimigo!\n");
						cC[2]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pntJ +=15;
					}
					if(cC[3] == 4){
						printf("\nVoce derrubou o Encoura�ado do inimigo!\n");
						cC[3]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pntJ +=20;
					}
					if(cC[4] == 5){
						printf("\nVoce derrubou o Porta-avioes do inimigo!\n");
						cC[4]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pntJ +=25;
					}
				}
				printf("\n Porfavor, aperte alguma tecla para continuar");
				getchar();
				if((pntC==75 )|| (pntJ ==75)){
					verificatiro =0;
				}
			}while(verificatiro == 1);
			
			if(qmjoga == 0){ //se o PC jogou muda para o Jogador a vez
				qmjoga = 1;
			}
			else{//se o Jogador jogou muda para o PC a vez
				qmjoga = 0;
			}
			if((pntC == 75) || (pntJ==75)){
				fim=1;
			}
		}while(fim == 0); // o Jogo n�o acaba enquanto o PC ou Jogador atingirem os pontos, que seria derrubar todos os navios
		
		if(pntJ > pntC){
			printf("\n\n      V O C E   V E N C E U !!!");
			printf("\n  Sua pontuacao: %d", pntJ);
			printf("\n Seu Numero de tiros: %d\n\n", numtirosJ);
			printf("\n  Pontuacao do inimigo: %d", pntC);
			printf("\n Numero de tiros do inimigo: %d\n", numtirosC);
		}
		if(pntC > pntJ){
			printf("\n\n     O   I N I M I G O   V E N C E U !");
			printf("\n  Pontuacao do inimigo: %d", pntC);
			printf("\n Numero de tiros do inimigo: %d\n", numtirosC);
			printf("\n\n  Sua pontuacao: %d", pntJ);
			printf("\n Seu Numero de tiros: %d", numtirosJ);
		}
		
		printf("\n\n\n  Deseja Jogar novamente?(s / n) \n");
		scanf("%c", op);
	}while(op != 'n');


	return 0;
} 
// ;)
