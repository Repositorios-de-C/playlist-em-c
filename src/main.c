#include <stdio.h>
#include "1-musica.h"
#include "1-musica.h"

// adicionar_musica(){}; //adicionar no fim da playlist
// adicionar_musica_posicao(){}; //adicionar em uma posição específica da playlist
// remover_musica(){}; //remover uma musica de uma posição da playlist
// tempo_restante(){}; //calcular e informar o tempo total restante para o fim da playlist
// play(){}; //iniciar a execução da playlist
// musicas_reproduzidas(){}; //informar a quantidade de músicas já reproduzidas


int main(){
    Lista playlist = criar_lista();

    inserir_no_final(playlist, criar_musica("Girassol (Acústico)", "Cidade Negra", 250));
    inserir_no_final(playlist, criar_musica("A Sombra da Maldade (Acústico)", "Cidade Negra", 231));
    inserir_no_final(playlist, criar_musica("Johny B. Goode (Johny B. Goode)", "Cidade Negra", 255));
    inserir_no_final(playlist, criar_musica("Soldado da Paz (Acústico)", "Cidade Negra", 194));
    inserir_no_final(playlist, criar_musica("Firmamento (Wrong Girl to)", "Cidade Negra", 222));
    inserir_no_final(playlist, criar_musica("Extra (Acústico)", "Cidade Negra", 304));
    inserir_no_final(playlist, criar_musica("O Erê (Acústico)", "Cidade Negra", 236));
    inserir_no_final(playlist, criar_musica("Podes Crer (Acústico)", "Cidade Negra", 232));
    inserir_no_final(playlist, criar_musica("A Estrada (Acústico)", "Cidade Negra", 249));
    inserir_no_final(playlist, criar_musica("Berlim (Acústico)", "Cidade Negra", 207));
    
    printf("Quantidade de músicas na playlist: %d\n", consultar_qtd_de_musicas_na_lista(playlist));
    liberar_destruir_a_lista(playlist);
    
    return 0;
}