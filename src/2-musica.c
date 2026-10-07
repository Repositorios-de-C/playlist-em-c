#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "1-musica.h"

struct musica{
    char titulo[100];
    char artista[100];
    int duracao;
};

Musica criar_musica(char *titulo, char *artista, int duracao){
    Musica m = malloc(sizeof(struct musica));
    if(m != NULL){
        strncpy(m->titulo, titulo, sizeof(m->titulo) - 1);
        m->titulo[sizeof(m->titulo) - 1] = '\0'; // garantir terminar com '\0'

        strncpy(m->artista, artista, sizeof(m->artista) - 1);
        m->artista[sizeof(m->artista) - 1] = '\0';

        m->duracao = duracao; //atribuir duração para a struct
    }
    return m;
}


char* consultar_titulo(Musica m){
    return m->titulo;
}
char* consultar_artista(Musica m){
    return m->artista;
}
int consultar_duracao(Musica m){
    return m->duracao;
}


void imprimir_seus_dados(Musica m){
    if(m == NULL){
        return;
    }
    int minutos = m->duracao / 60;
    int segundos = m->duracao % 60;
    printf("%s - %s (%d:%02d)\n", m->titulo, m->artista, minutos, segundos);
}


void destruir_musica(Musica m){
    if(m != NULL){
        free(m);
    }
}