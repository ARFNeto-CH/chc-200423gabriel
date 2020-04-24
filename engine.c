#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "malloc.h"

#include "engine.h"

char eventos_nome[9][24] =
{ 
    "Colisao",
    "Atualizacao tela",
    "Particulas",
    "Logica do Jogo",
    "Teclado",
    "Inteligencia Artificial",
    "Mouse", 
    "Simulacao Fisica",
    "Internet"
};

int controlador = 0;

void inserir_infos(fila_prio* fp, int qnt_tempo)
{
    free(fp);
    srand((unsigned)time(NULL));
    int num_aleatorio;
    fp->tam = 0;
    for (int v = 1; v <= qnt_tempo; v++)
    {
        printf("\nTempo #%d \n\n", v);
        int girar = rand() % 20;
        printf("Eventos gerados (%d):\n", girar);
        for (int i = 0; i < girar; i++)
        {
            num_aleatorio = rand() % 9;
            /*fp->info[i].prioridade = ranking_prioridade(num_aleatorio);
            fp->info[i].grupo = ranking_grupo(num_aleatorio);
           //strcpy(fp[i].grupo, ranking_grupo(num_aleatorio));
            strcpy(fp->info[i].evento, eventos_nome[num_aleatorio]);
            fp->info[i].momento = i;
           fp->tam++;*/
            ajusta_fila(fp, num_aleatorio, i);
            //fp->info[i].momento = i;
            printf("Nome: %s | Prioridade : %d |Grupo : %c |Ordem : %d \n", eventos_nome[num_aleatorio], ranking_prioridade(num_aleatorio), ranking_grupo(num_aleatorio), i);

            //arrumar_infos(fp, )
        }
        //qsort(fp, girar, sizeof(fila_prio*), compara_eventos);
        printf("\nEventos Atendidos: \n");
        for (int i = 0; i < fp->tam; i++)
        {
            printf("Nome: %s |Prioridade : %d |Grupo : %c |Ordem : %d\n", fp->info[i].evento, fp->info[i].prioridade, fp->info[i].grupo, fp->info[i].momento);
        }
        fp->tam = 0;
        free(fp);
    }
}

void Quick(fila_prio* fp, fila_prio* auxiliar, int inicio, int fim)
{

    int aux, i, j, meio;

    i = inicio;
    j = fim;

    meio = (int)((i + j) / 2);
    //auxiliar->info = fp->info[meio];

    do
    {
        while ((fp->info[i].grupo < fp->info[meio].grupo && fp->info[i].grupo == 97) || (((fp->info[i].grupo == fp->info[meio].grupo) || (fp->info[i].grupo > 97)) && (fp->info[i].prioridade < fp->info[meio].prioridade)))
        {
            printf("Prioridade : %d | Grupo : %c  |--------------| Prioridade : %d | Grupo : %c \n", fp->info[i].prioridade, fp->info[i].grupo, fp->info[meio].prioridade, fp->info[meio].grupo);
            i = i + 1; // maior
        }
        while (fp->info[meio].grupo == 97 && (fp->info[j].grupo > fp->info[meio].grupo) || (((fp->info[j].grupo == fp->info[meio].grupo) || (fp->info[j].grupo > 97)) && (fp->info[j].prioridade > fp->info[meio].prioridade)))
        {
            printf("Prioridade : %d | Grupo : %c  |--------------| Prioridade : %d | Grupo : %c \n", fp->info[i].prioridade, fp->info[i].grupo, fp->info[meio].prioridade, fp->info[meio].grupo);
            j = j - 1; // menor
        }

        if (i <= j)
        {
            auxiliar->info[0] = fp->info[i];
            fp->info[i] = fp->info[j];
            fp->info[j] = auxiliar->info[0];
            i = i + 1;
            j = j - 1;
        }
    } while (j > i);

    if (inicio < j)
        Quick(fp, auxiliar, inicio, j);
    if (i < fim)
        Quick(fp, auxiliar, i, fim);


}


void ajusta_fila(fila_prio* fp, int j, int x)
{
    int i = fp->tam - 1;

    while ((i >= 0 && ranking_prioridade(j) < fp->info[i].prioridade && fp->info[i].grupo != 'a' && ranking_grupo(j) != 'a') || (i >= 0 && fp->info[i].grupo != 'a' && ranking_grupo(j) == 'a') || (i >= 0 && ranking_prioridade(j) < fp->info[i].prioridade && fp->info[i].grupo != 'a' && ranking_grupo(j) == 'a') || (i >= 0 && ranking_prioridade(j) < fp->info[i].prioridade && fp->info[i].grupo == 'a' && ranking_grupo(j) == 'a') || (i >= 0 && ranking_prioridade(j) == fp->info[i].prioridade && fp->info[i].grupo != 'a' && ranking_grupo(j) != 'a' && fp->info[i].momento > x)) //|| (i >= 0 && fp->info[i].prioridade > ranking_prioridade(j) && fp->info[i].grupo != 'a' && ranking_grupo(j) == 'a' ))
    // while ( (fp->info[i].grupo < fp->info[meio].grupo && fp->info[i].grupo == 97) || ( ( (fp->info[i].grupo == fp->info[meio].grupo) || (fp->info[i].grupo > 97) ) && (fp->info[i].prioridade < fp->info[meio].prioridade) )  )
    {
        fp->info[i + 1] = fp->info[i];
        i--;
    }

    strcpy(fp->info[i + 1].evento, eventos_nome[j]);
    fp->info[i + 1].grupo = ranking_grupo(j);
    fp->info[i + 1].prioridade = ranking_prioridade(j);
    fp->info[i + 1].momento = x;
    fp->tam++;
}

void listar_FilaPrio(fila_prio* fp)
{
    printf("Tamanho %d \n", fp->tam);
    for (int i = 0; i <= sizeof(fp); i++)
    {
        printf("Nome: %s | Prioridade : %d | Grupo : %c \n", fp->info[i].evento, fp->info[i].prioridade, fp->info[i].grupo);
    }
}

int ranking_prioridade(int num)
{
    switch (num)
    {
    case 0:
    case 3:
    case 4:
        return 0;
        break;
    case 1:
    case 5:
    case 6:
        return 1;
        break;
    case 2:
    case 7:
    case 8:
        return 2;
        break;
    }
    return -1;
}

char ranking_grupo(int valor_at)
{
    //int indice = strcspn(eventos_nome, fp[valor_array].evento);
    //printf("%d e %d -> ",valor_array, valor_at);
    switch (valor_at)
    {
    case 0:
    case 1:
    case 2:
        //fp[valor_array].grupo = 'a';
        //printf("A");
        return 'a';
        break;
    case 3:
    case 5:
    case 7:
        //printf("B");
        // fp[valor_array].grupo = 'b';
        return 'b';
        break;
    case 4:
    case 6:
    case 8:
        // printf("C");
        // fp[valor_array].grupo = 'c';
        return 'c';
        break;
    }
    return -1;
}
