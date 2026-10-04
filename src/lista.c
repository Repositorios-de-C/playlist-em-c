#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int valor;
    struct elemento *proximo;
};
typedef struct elemento* Elemento;

struct lista{
    int quantidade;
    struct elemento *inicio;
};
typedef struct lista* Lista;


Lista criar_lista(){
    Lista li = malloc(sizeof(struct lista));
    if(li != NULL){
        li->quantidade = 0;
        li->inicio = NULL;
    }
    return li;
}


int inserir_no_inicio(Lista li, int valor_inserido){
    Elemento novo = malloc(sizeof(struct elemento));
    if(novo != NULL){
        novo->valor = valor_inserido;
        novo->proximo = li->inicio;
        li->inicio = novo; 
        li->quantidade++;
        return 1; // sucesso
    }
    return 0; // falha
}


int inserir_no_final(Lista li, int valor_inserido){
    Elemento novo = malloc(sizeof(struct elemento));
    if(novo != NULL){
        novo->valor = valor_inserido;
        novo->proximo = NULL;

        if(li->inicio == NULL){
            li->inicio = novo;
            li->quantidade++;
            return 1; // sucesso
        }

        Elemento auxiliar = li->inicio;

        while(auxiliar->proximo != NULL){
            auxiliar = auxiliar->proximo; //"andar"
        }
        auxiliar->proximo = novo;
        li->quantidade++;
        return 1; // sucesso
    }
    return 0; // falha
}


int inserir_por_posicao(Lista li, int posicao, int valor_inserido){
    if(posicao < 0 || posicao > li->quantidade){
        return 0; // posição inválida
    }

    Elemento novo = malloc(sizeof(struct elemento));
    if(novo != NULL){
        novo->valor = valor_inserido;

        if(posicao == 0){
            novo->proximo = li->inicio;
            li->inicio = novo;
        } else {
            Elemento auxiliar = li->inicio;
            for(int i=0; i<posicao-1; i++){
                auxiliar = auxiliar->proximo;
            }
            novo->proximo = auxiliar->proximo;
            auxiliar->proximo = novo; 
        }
        li->quantidade++;
        return 1;
    }
    return 0;
}


int remover_a_primeira(Lista li){
    if(li->inicio == NULL){
        return 0;
    }
    Elemento auxiliar = li->inicio;
    li->inicio = auxiliar->proximo;
    free(auxiliar);
    li->quantidade--;
    return 1;
}


int remover_a_ultima(Lista li){
    if(li->inicio == NULL){
        return 0;
    }
    Elemento auxiliar = li->inicio;
    if(auxiliar->proximo == NULL){
        li->inicio = NULL;
        free(auxiliar);
        li->quantidade--;
        return 1;
    }
    Elemento penultimo = NULL;
    while(auxiliar->proximo != NULL){
        penultimo = auxiliar;
        auxiliar = auxiliar->proximo;
    }
    penultimo->proximo = NULL;
    free(auxiliar);
    li->quantidade--;
    return 1;
}


int remover_por_posicao(Lista li, int posicao){
    if(posicao < 0 || posicao >= li->quantidade){
        return 0;
    }
    Elemento auxiliar = li->inicio;
    if(posicao == 0){
        li->inicio = auxiliar->proximo;
        free(auxiliar);
        li->quantidade--;
        return 1;
    }
    for(int i=0; i<posicao-1; i++){
        auxiliar = auxiliar->proximo;
    }
    Elemento a_remover = auxiliar->proximo;
    auxiliar->proximo = a_remover->proximo;
    free(a_remover);
    li->quantidade--;
    return 1;
}


int consultar_a_primeira(Lista li){
    if(li->inicio == NULL){
        return -1; // lista vazia
    }
    return li->inicio->valor;
}


int consultar_por_posicao(Lista li, int posicao){
    if(posicao < 0 || posicao >= li->quantidade){
        return -1; // posição inválida
    }
    Elemento auxiliar = li->inicio;
    for(int i=0; i<posicao; i++){
        auxiliar = auxiliar->proximo;
    }
    return auxiliar->valor;
}


int consultar_qtd_de_musicas_na_lista(Lista li){
    return li->quantidade;
}


void liberar_destruir_a_lista(Lista li){
    if(li == NULL){
        return;
    }
    Elemento auxiliar = li->inicio;
    while(auxiliar != NULL){
        Elemento atual = auxiliar;
        auxiliar = auxiliar->proximo;
        free(atual);
    }
    free(li);
}