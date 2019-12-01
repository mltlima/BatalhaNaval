#include "BatalhaNaval.h"

int main(void)
{   
    srand((unsigned int)time(NULL)); // Gera random seed
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
            jogoPrincipal();
            break;
        case 2:
            jogoDemo();
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
