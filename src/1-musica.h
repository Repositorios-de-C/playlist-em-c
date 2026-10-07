#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct musica* Musica;

Musica criar_musica(char *titulo, char *artista, int duracao);

//consultando os dados da musica
char* consultar_titulo(Musica m);
char* consultar_artista(Musica m);
int consultar_duracao(Musica m);

//imprimir os dados da musica
void imprimir_seus_dados(Musica m);

//liberar a memoria alocada para a musica
void destruir_musica(Musica m);