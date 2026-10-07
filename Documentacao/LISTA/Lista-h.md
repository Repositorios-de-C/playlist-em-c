# 3-lista.h — Documentação

## 1. Visão geral

O arquivo `3-lista.h` é o **cabeçalho (header)** do TAD `Lista`.

Ele apresenta as operações que podem ser utilizadas por outros arquivos do programa, sem mostrar como a lista é implementada internamente.

Na atividade, a lista deve ser **unicamente encadeada** e armazenar músicas. O TAD `Lista` possui operações para criar a lista, inserir, remover, consultar e destruir seus elementos.

A atividade também determina que os TADs `Musica` e `Lista` sejam implementados utilizando **tipos opacos**, de modo que suas estruturas internas não sejam acessadas diretamente pelo programa principal.

---

## 2. Bibliotecas incluídas

### `#include <stdio.h>`

Inclui recursos de entrada e saída da linguagem C.

No código apresentado no `3-lista.h`, não há nenhuma função de entrada ou saída sendo declarada diretamente. Portanto, essa biblioteca não é essencial para as declarações mostradas neste arquivo.

### `#include <stdlib.h>`

Disponibiliza recursos da biblioteca padrão do C, como funções relacionadas ao gerenciamento de memória.

Assim como `stdio.h`, ela não é utilizada diretamente nas declarações apresentadas neste cabeçalho.

### `#include "1-musica.h"`

Inclui o cabeçalho do TAD `Musica`.

Isso é necessário porque as funções da lista recebem e retornam valores do tipo `Musica`.

---

## 3. `typedef struct elemento* Elemento`

```c
typedef struct elemento* Elemento;
```

Essa linha cria um novo nome para um ponteiro para `struct elemento`.

Em vez de escrever:

```c
struct elemento*
```

podemos escrever:

```c
Elemento
```

Cada elemento representa um **nó** da lista encadeada.

Conceitualmente:

```text
Elemento
   |
   v
+-------------------+
| música            |
| próximo elemento  | -----> ...
+-------------------+
```

A estrutura completa do elemento não aparece neste arquivo. Ela será definida no arquivo `.c`, mantendo a estrutura interna escondida.

---

## 4. `typedef struct lista* Lista`

```c
typedef struct lista* Lista;
```

Cria um apelido para um ponteiro para `struct lista`.

Assim:

```c
Lista
```

representa:

```c
struct lista*
```

A variável `Lista` será utilizada para representar a lista criada.

Conceitualmente:

```text
Lista
  |
  v
+----------------------+
| informações da lista |
| início               | -----> Elemento
+----------------------+          |
                                  v
                              Elemento
                                  |
                                  v
                                NULL
```

---

## 5. `criar_lista`

```c
Lista criar_lista(void);
```

Declara a função responsável por **criar uma nova lista**.

### Retorno

`Lista` indica que a função retorna uma lista.

Como `Lista` foi definido como:

```c
typedef struct lista* Lista;
```

o retorno é um ponteiro para a estrutura da lista.

### Parâmetro

`void` dentro dos parênteses indica que a função **não recebe parâmetros**.

---

## 6. `inserir_no_inicio`

```c
int inserir_no_inicio(Lista li, Musica valor_inserido);
```

Declara a função que insere uma música **no início da lista**.

### Parâmetros

- `li`: lista onde a música será inserida.
- `valor_inserido`: música que será adicionada.

### Retorno

A função retorna um `int`, utilizado pela implementação para indicar o resultado da operação.

### Exemplo

Antes:

```text
[A] -> [B] -> [C] -> NULL
```

Depois de inserir `X` no início:

```text
[X] -> [A] -> [B] -> [C] -> NULL
```

---

## 7. `inserir_no_final`

```c
int inserir_no_final(Lista li, Musica valor_inserido);
```

Insere uma música **no final da lista**.

Antes:

```text
[A] -> [B] -> [C] -> NULL
```

Depois:

```text
[A] -> [B] -> [C] -> [X] -> NULL
```

- `li`: lista que receberá a música.
- `valor_inserido`: música que será inserida.

A função retorna um `int` indicando o resultado da operação.

---

## 8. `inserir_por_posicao`

```c
int inserir_por_posicao(Lista li, int posicao, Musica valor_inserido);
```

Insere uma música em uma **posição específica** da lista.

### Parâmetros

- `li`: lista onde ocorrerá a inserção.
- `posicao`: posição em que a música deverá ser inserida.
- `valor_inserido`: música que será adicionada.

### Exemplo

Antes:

```text
Posição:  0     1     2
          ↓     ↓     ↓
        [A] -> [B] -> [C]
```

Inserindo `X` na posição `1`:

```text
Posição:  0     1     2     3
          ↓     ↓     ↓     ↓
        [A] -> [X] -> [B] -> [C]
```

---

## 9. `remover_a_primeira`

```c
int remover_a_primeira(Lista li);
```

Remove a **primeira música** da lista.

Antes:

```text
[A] -> [B] -> [C] -> NULL
```

Depois:

```text
[B] -> [C] -> NULL
```

A função retorna um `int` indicando o resultado da remoção.

---

## 10. `remover_a_ultima`

```c
int remover_a_ultima(Lista li);
```

Remove a **última música** da lista.

Antes:

```text
[A] -> [B] -> [C] -> NULL
```

Depois:

```text
[A] -> [B] -> NULL
```

A função retorna um `int` indicando o resultado da operação.

---

## 11. `remover_por_posicao`

```c
int remover_por_posicao(Lista li, int posicao);
```

Remove uma música localizada em uma **posição específica**.

### Parâmetros

- `li`: lista que será alterada.
- `posicao`: posição da música que será removida.

### Exemplo

Antes:

```text
Posição:  0     1     2
          ↓     ↓     ↓
        [A] -> [B] -> [C]
```

Removendo a posição `1`:

```text
[A] -> [C] -> NULL
```

---

## 12. `consultar_a_primeira`

```c
Musica consultar_a_primeira(Lista li);
```

Consulta a **primeira música** da lista.

A função retorna uma `Musica`.

Conceitualmente:

```text
Lista
  |
  v
[A] -> [B] -> [C]
 ^
 |
 primeira música
```

---

## 13. `consultar_por_posicao`

```c
Musica consultar_por_posicao(Lista li, int posicao);
```

Consulta uma música que está em uma **determinada posição**.

### Parâmetros

- `li`: lista que será consultada.
- `posicao`: posição da música que queremos encontrar.

Exemplo:

```text
Posição:  0     1     2
          ↓     ↓     ↓
        [A] -> [B] -> [C]
```

Consultando a posição `1`:

```text
Resultado -> [B]
```

---

## 14. `consultar_qtd_de_musicas_na_lista`

```c
int consultar_qtd_de_musicas_na_lista(Lista li);
```

Consulta a **quantidade de músicas presentes na lista**.

Retorna um `int`.

Exemplo:

```text
[A] -> [B] -> [C] -> NULL

Quantidade = 3
```

Essa operação permite saber quantas músicas existem atualmente na playlist.

---

## 15. `liberar_destruir_a_lista`

```c
void liberar_destruir_a_lista(Lista li);
```

Responsável por **liberar/destruir a lista**.

### `void`

O `void` indica que a função **não retorna um valor**.

Ela realiza uma ação: liberar os recursos utilizados pela lista.

### Parâmetro

`li` é a lista que será destruída.

Conceitualmente:

```text
Antes:

Lista
  |
  v
[A] -> [B] -> [C] -> NULL


Depois:

memória da lista e seus elementos
          ↓
        liberada
```

---

## 16. Resumo das funções

| Função | Retorno | Função |
|---|---|---|
| `criar_lista` | `Lista` | Cria uma lista |
| `inserir_no_inicio` | `int` | Insere uma música no início |
| `inserir_no_final` | `int` | Insere uma música no final |
| `inserir_por_posicao` | `int` | Insere uma música em uma posição |
| `remover_a_primeira` | `int` | Remove a primeira música |
| `remover_a_ultima` | `int` | Remove a última música |
| `remover_por_posicao` | `int` | Remove uma música por posição |
| `consultar_a_primeira` | `Musica` | Consulta a primeira música |
| `consultar_por_posicao` | `Musica` | Consulta uma música por posição |
| `consultar_qtd_de_musicas_na_lista` | `int` | Consulta a quantidade de músicas |
| `liberar_destruir_a_lista` | `void` | Libera/destrói a lista |

---

## 17. Papel do `3-lista.h`

O `3-lista.h` funciona como a **interface do TAD Lista**.

Ele informa:

> "Estas são as operações que podem ser realizadas sobre uma lista."

Ele não precisa mostrar como essas operações funcionam internamente.

A implementação ficará no arquivo:

```text
lista.c
```

Enquanto o uso das funções poderá ser feito pelo:

```text
main.c
```
