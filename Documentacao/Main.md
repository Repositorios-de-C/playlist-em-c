# 🎵 Playlist de Músicas — `main.c`

## 📌 Sobre o arquivo

O arquivo `main.c` é responsável por **utilizar os TADs `Musica` e `Lista`** para criar e controlar uma playlist.

Enquanto os arquivos anteriores definem e implementam as estruturas:

```text
1-musica.h / 2-musica.c
        ↓
     TAD Musica

3-lista.h / 4-lista.c
        ↓
      TAD Lista
```

O `main.c` utiliza essas estruturas para realizar operações como:

- adicionar músicas;
- inserir músicas em posições específicas;
- remover músicas;
- reproduzir músicas;
- calcular o tempo restante;
- informar quantas músicas já foram reproduzidas;
- destruir a playlist ao final.

---

# 📚 Bibliotecas utilizadas

```c
#include <stdio.h>

#include "1-musica.h"
#include "3-lista.h"
```

### `stdio.h`

Permite utilizar funções de entrada e saída, principalmente:

```c
printf()
```

### `1-musica.h`

Permite utilizar o TAD `Musica` e suas funções, como:

```c
criar_musica()
destruir_musica()
imprimir_seus_dados()
consultar_duracao()
```

### `3-lista.h`

Permite utilizar o TAD `Lista`, incluindo funções como:

```c
inserir_no_final()
inserir_por_posicao()
remover_por_posicao()
consultar_por_posicao()
```

---

# ➕ Método `adicionar_musica`

```c
int adicionar_musica(
    Lista playlist,
    char *titulo,
    char *artista,
    int duracao
)
```

Essa função é responsável por **criar uma música e adicioná-la ao final da playlist**.

---

## 1. Criando a música

```c
Musica m = criar_musica(titulo, artista, duracao);
```

A função `criar_musica()` cria uma nova música utilizando:

```text
título
artista
duração
```

Por exemplo:

```text
"Girassol"
"Cidade Negra"
250
```

---

## 2. Verificando se a criação funcionou

```c
if(m == NULL) return 0;
```

Se `m` for `NULL`, significa que não foi possível criar a música.

Nesse caso, a função retorna:

```text
0 → falha
```

---

## 3. Adicionando ao final

```c
return inserir_no_final(playlist, m);
```

A música criada é enviada para a função do TAD Lista:

```text
adicionar_musica()
        ↓
criar_musica()
        ↓
Musica criada
        ↓
inserir_no_final()
        ↓
Playlist
```

O retorno de `inserir_no_final()` é repassado diretamente.

---

# 📍 Método `adicionar_musica_numa_posicao`

```c
int adicionar_musica_numa_posicao(
    Lista playlist,
    char *titulo,
    char *artista,
    int duracao,
    int posicao
)
```

Funciona de maneira semelhante à função anterior, mas permite escolher **em qual posição a música será inserida**.

---

## 1. Criando a música

```c
Musica m = criar_musica(titulo, artista, duracao);
```

A música é criada normalmente.

---

## 2. Verificando a criação

```c
if(m == NULL) return 0;
```

Se não foi possível criar, retorna `0`.

---

## 3. Inserindo na posição

```c
return inserir_por_posicao(playlist, posicao, m);
```

A música é enviada para a função:

```text
inserir_por_posicao()
```

do TAD Lista.

Por exemplo:

```text
Playlist:

[A] -> [B] -> [C] -> [D]
```

Inserindo `X` na posição `2`:

```text
[A] -> [B] -> [X] -> [C] -> [D]
```

---

# ▶️ Método `play`

```c
void play(Lista playlist, int *posicao_atual)
```

Essa função representa a **reprodução da próxima música da playlist**.

A variável `posicao_atual` indica qual posição será reproduzida.

---

## 1. Consultando a música atual

```c
Musica atual =
    consultar_por_posicao(playlist, *posicao_atual);
```

A função consulta a música que está na posição atual.

Exemplo:

```text
Playlist:

[A] -> [B] -> [C] -> [D]
 ↑
posição 0
```

Se:

```c
posicao_atual = 0;
```

a música `A` será consultada.

---

## 2. Verificando se a playlist chegou ao fim

```c
if(atual == NULL){
    printf("\nPlaylist chegou ao fim.");
    return;
}
```

Se não existe música naquela posição, significa que não há mais músicas para reproduzir.

---

## 3. Mostrando a música

```c
printf("\nTocando agora: ");
imprimir_seus_dados(atual);
```

Primeiro é exibida a mensagem:

```text
Tocando agora:
```

Depois, `imprimir_seus_dados()` mostra as informações da música.

---

## 4. Avançando a posição

```c
(*posicao_atual)++;
```

Depois de reproduzir a música, a posição é incrementada.

Exemplo:

```text
Antes:

posicao_atual = 0

[A] -> [B] -> [C]


Depois de play():

posicao_atual = 1

[A] -> [B] -> [C]
       ↑
```

Assim, a próxima chamada de `play()` reproduzirá a música seguinte.

---

# ⏱️ Método `tempo_restante`

```c
int tempo_restante(Lista playlist, int posicao_atual)
```

Calcula o **tempo total das músicas que ainda faltam ser reproduzidas**.

---

## 1. Criando o acumulador

```c
int total = 0;
```

A variável `total` começa em zero e receberá a duração das músicas.

---

## 2. Descobrindo a quantidade de músicas

```c
int qtd = consultar_qtd_de_musicas_na_lista(playlist);
```

A função consulta quantas músicas existem na playlist.

---

## 3. Percorrendo as músicas restantes

```c
for(int i = posicao_atual; i < qtd; i++)
```

O `for` começa na posição atual e continua até a última música.

Por exemplo:

```text
[A] [B] [C] [D] [E]
          ↑
     posição atual = 2
```

Serão consideradas:

```text
[C] [D] [E]
```

---

## 4. Consultando cada música

```c
Musica m = consultar_por_posicao(playlist, i);
```

A música daquela posição é obtida.

---

## 5. Somando a duração

```c
total += consultar_duracao(m);
```

A duração da música é adicionada ao total.

Exemplo:

```text
Música C = 200 segundos
Música D = 250 segundos
Música E = 300 segundos

total = 200 + 250 + 300
total = 750 segundos
```

---

## 6. Retornando o resultado

```c
return total;
```

A função retorna o tempo restante em segundos.

---

# 🔢 Método `musicas_reproduzidas`

```c
int musicas_reproduzidas(int posicao_atual)
```

Informa quantas músicas já foram reproduzidas.

A função simplesmente retorna:

```c
return posicao_atual;
```

Isso funciona porque `posicao_atual` é incrementada depois de cada execução bem-sucedida de `play()`.

Por exemplo:

```text
posição atual = 0
→ nenhuma música reproduzida

posição atual = 1
→ 1 música reproduzida

posição atual = 2
→ 2 músicas reproduzidas

posição atual = 4
→ 4 músicas reproduzidas
```

---

# ❌ Método `remover_musica_por_posicao`

```c
int remover_musica_por_posicao(
    Lista playlist,
    int posicao
)
```

Remove uma música de uma posição específica da playlist.

Essa função possui uma lógica importante porque primeiro precisa **obter a música** antes de removê-la.

---

## 1. Consultando a música

```c
Musica m = consultar_por_posicao(playlist, posicao);
```

A música localizada na posição é armazenada em `m`.

---

## 2. Verificando se existe

```c
if(m == NULL){
    return 0;
}
```

Se `m` for `NULL`, a posição é inválida ou não existe música naquele local.

---

## 3. Removendo da lista

```c
int resultado =
    remover_por_posicao(playlist, posicao);
```

A função do TAD Lista remove o elemento da posição indicada.

O resultado é armazenado em:

```c
resultado
```

---

## 4. Destruindo a música

```c
if(resultado){
    destruir_musica(m);
}
```

Se a remoção foi realizada com sucesso, a música também é destruída.

Isso é importante porque remover o elemento da lista e destruir a música são operações relacionadas, mas diferentes:

```text
remover_por_posicao()
        ↓
remove o elemento da lista

destruir_musica()
        ↓
libera a memória da música
```

---

## 5. Retornando o resultado

```c
return resultado;
```

Retorna:

```text
1 → remoção realizada
0 → falha
```

---

# 🚀 Função `main`

```c
int main()
```

A função `main()` é o **ponto de início da execução do programa**.

Tudo começa aqui.

---

# 1️⃣ Criando a playlist

```c
Lista playlist = criar_lista();
```

É criada uma lista vazia.

```text
playlist

quantidade = 0
inicio -> NULL
```

---

# 2️⃣ Criando a posição atual

```c
int posicao_atual = 0;
```

A reprodução começa na posição `0`, ou seja, na primeira música.

```text
[A] -> [B] -> [C]

 ↑
posição 0
```

---

# 3️⃣ Adicionando as músicas

O programa adiciona inicialmente 10 músicas:

```c
adicionar_musica(
    playlist,
    "Girassol",
    "Cidade Negra",
    250
);
```

O processo acontece assim:

```text
adicionar_musica()
        ↓
criar_musica()
        ↓
Musica
        ↓
inserir_no_final()
        ↓
Playlist
```

O mesmo processo é repetido para as outras músicas.

As músicas adicionadas inicialmente são:

| Posição | Música | Artista | Duração |
|---:|---|---|---:|
| 0 | Girassol | Cidade Negra | 250 |
| 1 | A Sombra da Maldade | Cidade Negra | 231 |
| 2 | Johny B. Goode | Cidade Negra | 255 |
| 3 | Soldado da Paz | Cidade Negra | 194 |
| 4 | Firmamento | Cidade Negra | 222 |
| 5 | Extra | Cidade Negra | 304 |
| 6 | O Erê | Cidade Negra | 236 |
| 7 | Podes Crer | Cidade Negra | 232 |
| 8 | A Estrada | Cidade Negra | 249 |
| 9 | Berlim | Cidade Negra | 207 |

A lista fica:

```text
Girassol
   ↓
A Sombra da Maldade
   ↓
Johny B. Goode
   ↓
Soldado da Paz
   ↓
Firmamento
   ↓
Extra
   ↓
O Erê
   ↓
Podes Crer
   ↓
A Estrada
   ↓
Berlim
   ↓
NULL
```

---

# 4️⃣ Inserindo uma música na posição 2

```c
adicionar_musica_numa_posicao(
    playlist,
    "Ja foi",
    "Cidade Negra",
    221,
    2
);
```

A música `"Ja foi"` é inserida na posição `2`.

Antes:

```text
0 → Girassol
1 → A Sombra da Maldade
2 → Johny B. Goode
```

Depois:

```text
0 → Girassol
1 → A Sombra da Maldade
2 → Ja foi
3 → Johny B. Goode
```

A partir desse momento, todas as músicas que estavam depois da posição 2 avançam uma posição.

---

# 5️⃣ Removendo uma música

```c
remover_musica_por_posicao(playlist, 6);
```

A música que está na posição `6` é removida.

A função:

```text
remover_musica_por_posicao()
        ↓
consultar_por_posicao()
        ↓
remover_por_posicao()
        ↓
destruir_musica()
```

Primeiro a música é localizada, depois o elemento é removido da lista e, por fim, a música é destruída.

---

# 6️⃣ Mostrando a quantidade de músicas

```c
printf(
    "Quantidade de musicas da playlist apos remocao: %d",
    consultar_qtd_de_musicas_na_lista(playlist)
);
```

A função:

```c
consultar_qtd_de_musicas_na_lista()
```

retorna a quantidade atual de músicas.

O valor é mostrado pelo `printf`.

---

# 7️⃣ Calculando o tempo restante

```c
int restante =
    tempo_restante(playlist, posicao_atual);
```

Como:

```c
posicao_atual = 0;
```

nenhuma música foi reproduzida ainda.

Portanto, a função soma a duração de **todas as músicas restantes da playlist**.

Depois:

```c
printf("\nTempo restante: %d\n", restante);
```

mostra o resultado.

O valor está em **segundos**.

---

# 8️⃣ Reproduzindo as músicas

O programa chama:

```c
play(playlist, &posicao_atual);
play(playlist, &posicao_atual);
play(playlist, &posicao_atual);
play(playlist, &posicao_atual);
```

A função recebe:

```c
&posicao_atual
```

porque ela precisa **alterar a variável original**.

### Primeira chamada

```text
posicao_atual = 0
        ↓
reproduz música 0
        ↓
posicao_atual = 1
```

### Segunda chamada

```text
posicao_atual = 1
        ↓
reproduz música 1
        ↓
posicao_atual = 2
```

### Terceira chamada

```text
posicao_atual = 2
        ↓
reproduz música 2
        ↓
posicao_atual = 3
```

### Quarta chamada

```text
posicao_atual = 3
        ↓
reproduz música 3
        ↓
posicao_atual = 4
```

Assim, quatro músicas foram reproduzidas.

---

# 9️⃣ Mostrando músicas reproduzidas

```c
printf(
    "Musicas ja reproduzidas: %d\n",
    musicas_reproduzidas(posicao_atual)
);
```

Como `posicao_atual` agora vale `4`, o programa informa:

```text
Músicas já reproduzidas: 4
```

---

# 🔟 Liberando a playlist

No final:

```c
liberar_destruir_a_lista(playlist);
```

Essa função percorre toda a lista e libera a memória utilizada pelos elementos e pelas músicas.

O processo é:

```text
Playlist
   ↓
Elemento 1 → destruir música → free
   ↓
Elemento 2 → destruir música → free
   ↓
Elemento 3 → destruir música → free
   ↓
...
   ↓
free(lista)
```

Isso evita deixar memória alocada sem necessidade.

---

# 🏁 Final do programa

```c
return 0;
```

Indica que o programa terminou normalmente.

---

# 🔄 Fluxo completo do programa

A execução do `main()` pode ser resumida assim:

```text
criar_lista()
      ↓
criar playlist
      ↓
adicionar 10 músicas
      ↓
inserir "Ja foi" na posição 2
      ↓
remover música da posição 6
      ↓
consultar quantidade
      ↓
calcular tempo restante
      ↓
play()
      ↓
play()
      ↓
play()
      ↓
play()
      ↓
consultar músicas reproduzidas
      ↓
liberar_destruir_a_lista()
      ↓
return 0
```

---

# 🔗 Relação entre os arquivos

O `main.c` funciona como uma camada que utiliza os dois TADs desenvolvidos anteriormente.

```text
              main.c
                 |
       +---------+---------+
       |                   |
       ↓                   ↓
   TAD Musica          TAD Lista
       |                   |
       ↓                   ↓
1-musica.h/.c         3-lista.h
                     4-lista.c
```

Por exemplo, para adicionar uma música:

```text
main.c
  |
  | adicionar_musica()
  ↓
criar_musica()
  |
  ↓
Musica criada
  |
  ↓
inserir_no_final()
  |
  ↓
Lista
```

---

# 🧠 Conceitos principais utilizados

## TAD

O `main.c` utiliza as funções dos TADs sem precisar conhecer todos os detalhes internos de suas estruturas.

## Lista encadeada

A playlist é armazenada como uma sequência de elementos ligados por ponteiros:

```text
[A] -> [B] -> [C] -> NULL
```

## Ponteiros

São utilizados para acessar e modificar estruturas e também para alterar `posicao_atual`.

```c
play(playlist, &posicao_atual);
```

O `&` envia o endereço da variável.

Dentro da função:

```c
(*posicao_atual)++;
```

O `*` permite acessar e modificar o valor original.

## Memória dinâmica

As músicas e elementos da lista são criados dinamicamente e precisam ser destruídos ao final:

```text
malloc() → cria/reserva memória

free() → libera memória
```

---

# 📋 Resumo das funções do `main.c`

| Função | Responsabilidade |
|---|---|
| `adicionar_musica()` | Cria e adiciona uma música ao final |
| `adicionar_musica_numa_posicao()` | Cria e adiciona uma música em uma posição |
| `play()` | Reproduz a música da posição atual |
| `tempo_restante()` | Soma a duração das músicas restantes |
| `musicas_reproduzidas()` | Retorna quantas músicas foram reproduzidas |
| `remover_musica_por_posicao()` | Remove e destrói uma música |
| `main()` | Executa e testa as operações da playlist |

---

# 🎯 Ideia principal

O `main.c` funciona como o **controlador da playlist**.

Ele não precisa implementar como uma lista funciona internamente. Em vez disso, utiliza as funções fornecidas pelos TADs:

```text
TAD Musica
    ↓
criar / consultar / destruir

TAD Lista
    ↓
inserir / remover / consultar

        ↓

     main.c
        ↓
   Playlist funcionando
```

Dessa forma, o programa consegue criar músicas, organizá-las em uma lista encadeada, reproduzi-las em ordem, calcular informações sobre a playlist e liberar corretamente a memória utilizada ao final.
