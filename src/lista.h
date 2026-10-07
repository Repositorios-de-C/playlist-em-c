#include <stdio.h>
#include <stdlib.h>
#include "1-musica.h"

typedef struct elemento* Elemento;
typedef struct lista* Lista;

Lista criar_lista(void);

int inserir_no_inicio(Lista li, Musica valor_inserido);
int inserir_no_final(Lista li, Musica valor_inserido);
int inserir_por_posicao(Lista li, int posicao, Musica valor_inserido);

int remover_a_primeira(Lista li);
int remover_a_ultima(Lista li);
int remover_por_posicao(Lista li, int posicao);

Musica consultar_a_primeira(Lista li);
Musica consultar_por_posicao(Lista li, int posicao);
int consultar_qtd_de_musicas_na_lista(Lista li);

void liberar_destruir_a_lista(Lista li);