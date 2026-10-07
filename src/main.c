#include <stdio.h>
#include "1-musica.h"
#include "lista.h"

//adicionar uma musica criada no final da playlist
int adicionar_musica(Lista playlist, char *titulo, char *artista, int duracao){
    Musica m = criar_musica(titulo, artista, duracao);
    if(m != NULL) return 0; //falhou ao criar
    return inserir_no_final;
}

//adicionar em uma posição específica da playlist
int adicionar_musica_numa_posicao(Lista playlist, char *titulo, char *artista, int duracao){
    Musica m = criar_musica(titulo, artista, duracao);
    if(m != NULL) return 0;
    return inserir_por_posicao;
}

//remover uma musica de uma posição da playlist     FAZR DPOIS
int remover_musica(){}

//calcular e informar o tempo total restante para o fim da playlist
int tempo_restante(Lista playlist, int posicao_atual){
    int total = 0;
    int qtd = consultar_qtd_de_musicas_na_lista;
    for(int i=posicao_atual; i<qtd ; i++){
        Musica m = consultar_por_posicao(playlist, i);
        total += consultar_duracao(m);
    }
    return total;
}

//iniciar a execução da playlist
void play(){}

//informar a quantidade de músicas já reproduzidas
int musicas_reproduzidas(int posicao_atual){
    return posicao_atual;
}


int main(){
    Lista playlist = criar_lista();

    
    printf("\n================================================\n");
    printf("Quantidade de musicas na playlist: %d\n", consultar_qtd_de_musicas_na_lista(playlist));
    printf("Posicao da proxima musica a ser reproduzida: " );

    liberar_destruir_a_lista(playlist);
    
    return 0;
}
    //testes
    // inserir_no_final(playlist, criar_musica("Girassol (Acústico)", "Cidade Negra", 250));
    // inserir_no_final(playlist, criar_musica("A Sombra da Maldade (Acústico)", "Cidade Negra", 231));
    // inserir_no_final(playlist, criar_musica("Johny B. Goode (Johny B. Goode)", "Cidade Negra", 255));
    // inserir_no_final(playlist, criar_musica("Soldado da Paz (Acústico)", "Cidade Negra", 194));
    // inserir_no_final(playlist, criar_musica("Firmamento (Wrong Girl to)", "Cidade Negra", 222));
    // inserir_no_final(playlist, criar_musica("Extra (Acústico)", "Cidade Negra", 304));
    // inserir_no_final(playlist, criar_musica("O Erê (Acústico)", "Cidade Negra", 236));
    // inserir_no_final(playlist, criar_musica("Podes Crer (Acústico)", "Cidade Negra", 232));
    // inserir_no_final(playlist, criar_musica("A Estrada (Acústico)", "Cidade Negra", 249));
    // inserir_no_final(playlist, criar_musica("Berlim (Acústico)", "Cidade Negra", 207));