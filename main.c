#define _CRT_SECURE_NO_WARNINGS

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include    "malloc.h"
#include	"engine.h"


int	main(int argc, char** argv)
{
    fila_prio* fp[100];
    //fila_prio* auxiliar[100];
    int op;
    int valor_roda;
    //char nome_string[30];

    do {
        printf("\n\n\tLISTA ORDENADA\n");
        printf("\t<1> Inserir\n");
        printf("\t<4> Imprimir\n");
        printf("\t<0> Sair do programa\n");
        printf("\tOpcao: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
            printf("\tFatias de tempo :");
            scanf("%d", &valor_roda);
            inserir_infos(fp, valor_roda);
            break;
        case 4: printf("\n\tConteudo da lista: ");
            listar_FilaPrio(fp);
            break;
        case 0: break;
        default: printf("\n\tOpcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}	// end main()
    // end testa_rotina()
// https://www.clubedohardware.com.br/forums/topic/
// 1442745-filas-de-prioridade-em-c-trab-impossivel
// /page/2/?tab=comments#comment-7761511