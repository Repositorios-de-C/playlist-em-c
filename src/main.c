#include <stdio.h>
#include "1-musica.h"
#include "3-lista.h"


//adicionar uma musica criada no final da playlist
int adicionar_musica(Lista playlist, char *titulo, char *artista, int duracao){
    Musica m = criar_musica(titulo, artista, duracao);
    if(m == NULL) return 0; //falhou ao criar
    return inserir_no_final(playlist, m);
}


//adicionar em uma posição específica da playlist
int adicionar_musica_numa_posicao(Lista playlist, char *titulo, char *artista, int duracao, int posicao){
    Musica m = criar_musica(titulo, artista, duracao);
    if(m == NULL) return 0;
    return inserir_por_posicao(playlist, posicao, m);
}


//iniciar a execução da playlist
void play(Lista playlist, int *posicao_atual){
    Musica atual = consultar_por_posicao(playlist, *posicao_atual);
    if(atual == NULL){
        printf("\nPlaylist chegou ao fim.");
        return;
    }
    printf("\nTocando agora: ");
    imprimir_seus_dados(atual);
    (*posicao_atual)++;
}


//calcular e informar o tempo total restante para o fim da playlist
int tempo_restante(Lista playlist, int posicao_atual){
    int total = 0;
    int qtd = consultar_qtd_de_musicas_na_lista(playlist);
    for(int i=posicao_atual; i<qtd ; i++){
        Musica m = consultar_por_posicao(playlist, i);
        total += consultar_duracao(m);
    }
    return total;
}


//informar a quantidade de músicas já reproduzidas
int musicas_reproduzidas(int posicao_atual){
    return posicao_atual;
}


//remover uma musica de uma posição da playlist
int remover_musica_por_posicao(Lista playlist, int posicao){
    Musica m = consultar_por_posicao(playlist, posicao);
    if(m == NULL){
        return 0; //posicao invalida ou ta vazia
    }

    int resultado = remover_por_posicao(playlist, posicao);
    
    if(resultado){
        destruir_musica(m);
    }
    
    return resultado;
}




int main(){
    Lista playlist = criar_lista();
    int posicao_atual=0;

    //criando e adicionando as 10 musicas no final
    adicionar_musica(playlist, "Girassol", "Cidade Negra", 250);
    adicionar_musica(playlist, "A Sombra da Maldade", "Cidade Negra", 231);
    adicionar_musica(playlist, "Johny B. Goode", "Cidade Negra", 255);
    adicionar_musica(playlist, "Soldado da Paz", "Cidade Negra", 194);
    adicionar_musica(playlist, "Firmamento", "Cidade Negra", 222);
    adicionar_musica(playlist, "Extra", "Cidade Negra", 304);
    adicionar_musica(playlist, "O Erê", "Cidade Negra", 236);
    adicionar_musica(playlist, "Podes Crer", "Cidade Negra", 232);
    adicionar_musica(playlist, "A Estrada", "Cidade Negra", 249);
    adicionar_musica(playlist, "Berlim", "Cidade Negra", 207);

    //adicionando uma musica por posicao
    adicionar_musica_numa_posicao(playlist, "Ja foi", "Cidade Negra", 221, 2); //posicao 2

    //removendo uma musica de uma posicao
    remover_musica_por_posicao(playlist, 6);
    printf("Quantidade de musicas da playlist apos remocao: %d", consultar_qtd_de_musicas_na_lista(playlist));

    //tempo restante
    int restante = tempo_restante(playlist, posicao_atual);
    printf("\nTempo restante: %d\n", restante);

    //play, tocar a proxima musica da playlist- tocando 4 msucias em ordem
    play(playlist, &posicao_atual);
    play(playlist, &posicao_atual);
    play(playlist, &posicao_atual);
    play(playlist, &posicao_atual);

    //musicas reproduzirdas
    printf("Musicas ja reproduzidas: %d\n", musicas_reproduzidas(posicao_atual));

    //fim
    liberar_destruir_a_lista(playlist);
    
    return 0;
}