#include "BatalhaNaval.h"

void posicionamentoNaviosDemo(char tab[][10]){
			tab[0][1]= 'S'; //Submarino

		    tab[2][4]= 'C'; //Cruzador
		    tab[2][5]= 'C'; //Cruzador

			tab[5][3]='D'; //Destroyer
			tab[5][4]='D'; //Destroyer
			tab[5][5]='D'; //Destroyer

			tab[2][6]='E'; //Encouracado 
			tab[3][6]='E'; //Encouracado 
			tab[4][6]='E'; //Encouracado 
			tab[5][6]='E'; //Encouracado 

			tab[4][8]='P'; //Porta-avioes
			tab[5][8]='P'; //Porta-avioes
			tab[6][8]='P'; //Porta-avioes
			tab[7][8]='P'; //Porta-avioes
			tab[8][8]='P'; //Porta-avioes
			}

void jogoDemo(void)
{   
    int count = 0, pontoComputador = 0, pontoJogador = 0, tirosComputador = 0, tirosJogador = 0, fim = 0;
    int num = 0, index = 0, flag = 0, check = 0, modoAi = 0;
    int quemJoga, verificatiro, i, j, coluna, acertoPosicaoI, acertoPosicaoJ, direcao,linhaJogador,colunaJogador;
    int contadorComputador[5], contadorJogador[5]; // verifica qual navio foi afundado
    char tabComputador[10][10], tabJogador[10][10], inputUsuario[64];
    char temp, numUsuario[1];
    size_t length = 0;

    for (int z = 0; z < 5; z++)
	{
		contadorComputador[z] = 0;
		contadorJogador[z] = 0;
	}
	

    geraTabuleiro(tabComputador);  // Gera tabuleiro do computador
    geraTabuleiro(tabJogador);     //Gera tabuleiro do jogador

    
    
        

        posicionamentoNaviosDemo(tabComputador);
        posicionamentoNavios(tabJogador);

        quemJoga = rand() % 2; // 0 Computador inicia o jogo, 1 Jogador inicia

        do  // jogo
        {   
            do    // Repetir enquanto acertar o tiro
            {
                tabuleiroComputador(tabComputador);
                tabuleiroJogador(tabJogador);

                if (quemJoga == 0) // Rodada do computador
                {
                    printf(CIA"\n Computador esta jogando...\n"RESET);
					
					int check = 0;
	

					for (int i = 0; i < 4; i++)
					{
						if (delCoordenada[i].direcao == 1)   // Verifica se os vetores foram todos zerados
						{
							check ++;
						}
						
					}
				
					if (check == 4)
					{	
						for (int i = 0; i < 4; i++)
							{
								delCoordenada[i] = vazia[0];
							}	
						
						modoAi = 0;
					}


					

                    if (modoAi == 0) // Modo aleatorio
                    {	
						
                        do
						{
                         	i = rand() % 10;
                        	j = rand() % 10;
                           	verificatiro = verificadorCampoValido(tabJogador, i, j);
                        } while (verificatiro == 1);

                        tiro(tabJogador, i, j, contadorJogador);
                        tirosComputador ++;
						
                        
                    }
					
                    if (modoAi == 1) // Troca para o modo alvo  
                    {	
						//do
                        {
                           modoAlvo(tabComputador,&i,&j,&direcao,acertoPosicaoI,acertoPosicaoJ);  // TODO mais tarde
                           verificatiro = verificadorCampoValido(tabJogador, i, j);
                        } //while (verificatiro == 1);

                        tiro(tabJogador, i, j, contadorJogador);
                        
						tirosComputador ++;

					}
					

                    verificatiro = verificador(tabJogador, i, j);

                    if(verificatiro == 1){
						printf(VER"\nComputador acertou!"RESET);
						if(modoAi == 0){
							direcao = rand()%4;
							acertoPosicaoI = i;
							acertoPosicaoJ = j;
							modoAi = 1;
							}
						
						
					}
					
					else if (verificatiro != 1 && modoAi == 1)
					{
                            switch (direcao)
							{
							case 0: // Norte
								for (int i = 0; i < 4; i++)
								{
									if (delCoordenada[i].direcao == 1)
										continue;
									else{
										direcao = i;
										break;	
									}
								}
								
								i = acertoPosicaoI;
								delCoordenada[0].direcao = 1;
								break;


							case 1: // Sul
								for (int i = 0; i < 4; i++)
								{
									if (delCoordenada[i].direcao == 1)
										continue;
									else{
										direcao = i;
										break;	
									}	
								}

								i = acertoPosicaoI;
								delCoordenada[1].direcao = 1;
								break;


							case 2:	//Leste
								for (int i = 0; i < 4; i++)
								{
									if (delCoordenada[i].direcao == 1)
										continue;
									else{
										direcao = i;
										break;	
									}	
								}

								j = acertoPosicaoJ;
								delCoordenada[2].direcao = 1;
								break;


							case 3:	// Oeste
								for (int i = 0; i < 4; i++)
								{
									if (delCoordenada[i].direcao == 1)
										continue;
									else{
										direcao = i;
										break;	
									}	
								}

								j = acertoPosicaoJ;
								delCoordenada[3].direcao = 1;
								break;
							}
						printf("\nTiro errado!");					
					}

					else{
						printf("\nTiro errado!");
						
					}

					
					
					

                    if(contadorJogador[0] == 1){
						printf(VER"\nInimigo derrubou seu Submarino!\n"RESET);
						contadorJogador[0]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pontoComputador += 5;
						modoAi = 0;
						for (int i = 0; i < 4; i++)
						{
							delCoordenada[i] = vazia[0]; // zera array para proxima jogada
						}
					}

					if(contadorJogador[1] == 2){
						printf(VER"\nComputador derrubou seu Cruzador!\n"RESET);
						contadorJogador[1]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pontoComputador += 10;
						modoAi = 0;
						for (int i = 0; i < 4; i++)
						{
							delCoordenada[i] = vazia[0]; // zera array para proxima jogada
						}
					}
					

                    if(contadorJogador[2] == 3){
						printf(VER"\nInimigo derrubou seu Destroyer!\n"RESET);
						contadorJogador[2]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pontoComputador += 15;
						modoAi = 0;
						for (int i = 0; i < 4; i++)
						{
							delCoordenada[i] = vazia[0]; // zera array
						}
					}

                    if(contadorJogador[3] == 4){
						printf(VER"\nInimigo derrubou seu Encouracado!\n"RESET);
						contadorJogador[3]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pontoComputador += 20;
						modoAi = 0;
						for (int i = 0; i < 4; i++)
						{
							delCoordenada[i] = vazia[0];
						}
					}

                    if(contadorJogador[4] == 5){
						printf(VER"\nInimigo derrubou seu Porta-avioes!\n"RESET);
						contadorJogador[4]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pontoComputador += 25;
						modoAi = 0;
						for (int i = 0; i < 4; i++)
						{
							delCoordenada[i] = vazia[0];
						}
					}   
                }
                else{ // Jogador atira

                    printf(CIA"\n Sua vez, escolha uma linha e coluna\n"RESET);
					    
                        while (check == 0)  // valida linha
                        {
                            length = 0;
                            flag = 0;
                            check = 0;

                            printf("\n linha: ");
                            fgets(inputUsuario,63,stdin);
                            length = strlen(inputUsuario);

                            if( length < 1 || length > 2) {
			                    printf("Tamanho invalido\n");
			                    continue;
                            }
                            length --;


		                    if( (inputUsuario[0] == 'a') || (inputUsuario[0] == 'A') || (inputUsuario[0] == 'b') || (inputUsuario[0] == 'B') 
                            || (inputUsuario[0] == 'c') || (inputUsuario[0] == 'C') || (inputUsuario[0] == 'd') || (inputUsuario[0] == 'D')
                            || (inputUsuario[0] == 'e') || (inputUsuario[0] == 'E') || (inputUsuario[0] == 'f') || (inputUsuario[0] == 'F')
                            || (inputUsuario[0] == 'g') || (inputUsuario[0] == 'G') || (inputUsuario[0] == 'h') || (inputUsuario[0] == 'H')
                            || (inputUsuario[0] == 'i') || (inputUsuario[0] == 'I') || (inputUsuario[0] == 'j') || (inputUsuario[0] == 'J')) {
		                    	check ++;
		                    	continue;
		                    }

		                    printf("Caracter invalido\n");
                        }
                        temp = inputUsuario[0];
                        check = 0;

                        if (temp == 'a' || temp == 'A')
                            linhaJogador = 0;
                        else if (temp == 'b' || temp == 'B')
                            linhaJogador = 1;
                        else if (temp == 'c' || temp == 'C')
                            linhaJogador = 2;
                        else if (temp == 'd' || temp == 'D')
                            linhaJogador = 3;
                        else if (temp == 'e' || temp == 'E')
                            linhaJogador = 4;
                        else if (temp == 'f' || temp == 'F')
                            linhaJogador = 5;
                        else if (temp == 'g' || temp == 'G')
                            linhaJogador = 6;
                        else if (temp == 'h' || temp == 'H')
                            linhaJogador = 7;
                        else if (temp == 'i' || temp == 'I')
                            linhaJogador = 8;
                        else if (temp == 'j' || temp == 'J')
                            linhaJogador = 9;
                        else
                            linhaJogador = 100;

                        while (1)     // valida coluna
						{	
							length = 0;
							
							printf("\n coluna: ");
                            fgets(inputUsuario,63,stdin);
							length = strlen(inputUsuario);


							if( length < 1 || length > 2) {
			                    printf("Tamanho invalido\n");
			                    continue;
                            }
                            length --;

							for(index = 0; index < length; ++index) 
                            {
		                	    if(isalpha(inputUsuario[index])) {
		                		flag = 1;
		                		break;
		                	}
		                    }
							if( flag) {
		                    	printf("digite um numero\n");
								flag = 0;
		                    	continue;			
		                    }

							sscanf(inputUsuario,"%d",&colunaJogador);
							
							if (colunaJogador == 0 || colunaJogador == 1 || colunaJogador == 2 || colunaJogador == 3 || colunaJogador == 4 || colunaJogador == 5 || colunaJogador == 6 || colunaJogador == 7 || colunaJogador == 8 || colunaJogador == 9)
							{
								break;
							}
							printf("Digite um numero valido");
						}

                    tiro(tabComputador, linhaJogador, colunaJogador, contadorComputador);
                    verificatiro = verificador(tabComputador, linhaJogador, colunaJogador);
                    tirosJogador ++;

                    if(verificatiro == 1){
						printf(VERDE"\nVoce acertou!\n"RESET);
					}else{
						printf(VERDE"\nTiro errado!\n"RESET);
					}
					
					if(contadorComputador[0] == 1){
						printf(VERDE"\nVoce derrubou o Submarino do inimigo!\n"RESET);
						contadorComputador[0]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pontoJogador += 5;
					}
					if(contadorComputador[1] == 2){
						printf(VERDE"\nVoce derrubou o Cruzador do inimigo!\n"RESET);
						contadorComputador[1]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pontoJogador += 10;
					}
					if(contadorComputador[2] == 3){
						printf(VERDE"\nVoce derrubou o Destroyer do inimigo!\n"RESET);
						contadorComputador[2]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pontoJogador += 15;
					}
					if(contadorComputador[3] == 4){
						printf(VERDE"\nVoce derrubou o Encouracado do inimigo!\n"RESET);
						contadorComputador[3]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pontoJogador += 20;
					}
					if(contadorComputador[4] == 5){
						printf(VERDE"\nVoce derrubou o Porta-avioes do inimigo!\n"RESET);
						contadorComputador[4]++; // para nao repetir mais essa mensagem quando entrar no la�o novamente
						pontoJogador += 25;
					}
                    }

                printf(CIA"\n Pressione Enter para continuar"RESET);
				getchar();
                printf(CLEAN);   // limpa terminal
				if((pontoComputador == 75 )|| (pontoJogador == 75)){
					verificatiro = 0;
				}    
            } while (verificatiro == 1);
            
            if(quemJoga == 0){ // muda a vez para o jogador
				quemJoga = 1;
			}
			else{  // muda a vez para o computador
				quemJoga = 0;
			}
			
			if((pontoComputador == 75) || (pontoJogador == 75)){
				fim = 1;
			}
            
        } while (fim == 0); // O jogo so acaba quando todos os navios forem afundados
        if(pontoJogador == 75){
			printf(VERDE BLINK" ██╗   ██╗ ██████╗  ██████╗███████╗    ██╗   ██╗███████╗███╗   ██╗ ██████╗███████╗██╗   ██╗   \n");
			usleep(TEMPO);
			printf(" ██║   ██║██╔═══██╗██╔════╝██╔════╝    ██║   ██║██╔════╝████╗  ██║██╔════╝██╔════╝██║   ██║  \n ");
			usleep(TEMPO);
			printf("██║   ██║██║   ██║██║     █████╗      ██║   ██║█████╗  ██╔██╗ ██║██║     █████╗  ██║   ██║  \n ");
			usleep(TEMPO);
			printf("╚██╗ ██╔╝██║   ██║██║     ██╔══╝      ╚██╗ ██╔╝██╔══╝  ██║╚██╗██║██║     ██╔══╝  ██║   ██║  \n ");
			usleep(TEMPO);
			printf(" ╚████╔╝ ╚██████╔╝╚██████╗███████╗     ╚████╔╝ ███████╗██║ ╚████║╚██████╗███████╗╚██████╔╝  \n ");
			usleep(TEMPO);
			printf("  ╚═══╝   ╚═════╝  ╚═════╝╚══════╝      ╚═══╝  ╚══════╝╚═╝  ╚═══╝ ╚═════╝╚══════╝ ╚═════╝   \n "RESET);
		
			printf("\n Seu Numero de tiros: %d\n\n", tirosJogador);
			//printf("\n  Pontuacao do inimigo: %d", pntC);
			printf("\n Numero de tiros do computador: %d\n", tirosComputador);
		}
		if(pontoComputador == 75){
			printf(VER BLINK"  ██████╗      ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗   ██╗████████╗ █████╗ ██████╗  ██████╗ ██████╗     ██╗   ██╗███████╗███╗   ██╗ ██████╗███████╗██╗   ██╗  \n ");
			usleep(TEMPO);
			printf("██╔═══██╗    ██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║   ██║╚══██╔══╝██╔══██╗██╔══██╗██╔═══██╗██╔══██╗    ██║   ██║██╔════╝████╗  ██║██╔════╝██╔════╝██║   ██║   \n");
			usleep(TEMPO);
			printf(" ██║   ██║    ██║     ██║   ██║██╔████╔██║██████╔╝██║   ██║   ██║   ███████║██║  ██║██║   ██║██████╔╝    ██║   ██║█████╗  ██╔██╗ ██║██║     █████╗  ██║   ██║   \n");
			usleep(TEMPO);
			printf(" ██║   ██║    ██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║   ██║   ██║   ██╔══██║██║  ██║██║   ██║██╔══██╗    ╚██╗ ██╔╝██╔══╝  ██║╚██╗██║██║     ██╔══╝  ██║   ██║   \n");
			usleep(TEMPO);
			printf(" ╚██████╔╝    ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ╚██████╔╝   ██║   ██║  ██║██████╔╝╚██████╔╝██║  ██║     ╚████╔╝ ███████╗██║ ╚████║╚██████╗███████╗╚██████╔╝  \n ");
			usleep(TEMPO);
			printf("  ╚═════╝      ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝      ╚═════╝    ╚═╝   ╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚═╝  ╚═╝      ╚═══╝  ╚══════╝╚═╝  ╚═══╝ ╚═════╝╚══════╝ ╚═════╝    \n"RESET);
                      
			
			printf("\n Numero de tiros do computador: %d\n", tirosComputador);
			
			printf("\n Seu Numero de tiros: %d", tirosJogador);
		}
    
    printf( BLINK INVERTE"\n\n\n Pressione enter para voltar ao menu\n"RESET);
    char enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
    
}
