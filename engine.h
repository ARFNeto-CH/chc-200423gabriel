#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include    <time.h>

typedef struct fpa_info
{
    char evento[21]; // nome do evento
    char grupo; // 'a', 'b' ou 'c'
    int prioridade; // 0: alta, 1: média, 2: baixa
    int momento;
    unsigned long timestamp; // tempo em nanosegundos
} fpa_info;

typedef struct
{
    int tam;
    struct fpa_info info[MAX];
} fila_prio;

void    ajusta_fila(fila_prio*, int, int);
void    inserir_infos(fila_prio*, int);
char    ranking_grupo(int);
int     ranking_prioridade(int);
