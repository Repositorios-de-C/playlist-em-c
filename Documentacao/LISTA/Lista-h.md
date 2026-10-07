# 🎵 TAD Lista — `3-lista.h`

## 📌 Sobre o arquivo

O arquivo `3-lista.h` é o **arquivo de cabeçalho** do TAD `Lista`.

Ele contém as **declarações** das estruturas e funções que podem ser utilizadas para manipular uma lista de músicas.

A implementação dessas funções está no arquivo:

```text
4-lista.c
```

A lista utiliza o TAD `Musica`, definido anteriormente em:

```text
1-musica.h
```

---

# 📚 Bibliotecas utilizadas

```c
#include <stdio.h>
#include <stdlib.h>
#include "1-musica.h"
```

### `stdio.h`

Biblioteca padrão da linguagem C. Fornece recursos de entrada e saída.

### `stdlib.h`

Fornece funções relacionadas à memória dinâmica, como:

```c
malloc()
free()
```

Essas funções são importantes para a criação e destruição dos elementos da lista.

### `1-musica.h`

Inclui o TAD `Musica`, permitindo que a lista armazene músicas.

---

# 🧱 Definição dos tipos

```c
typedef struct elemento* Elemento;

typedef struct lista* Lista;
```

Aqui são criados dois tipos que serão utilizados pela lista.

## `Elemento`

```c
typedef struct elemento* Elemento;
```

`Elemento` representa um **ponteiro para um elemento da lista**.

Cada elemento será responsável por armazenar uma música e apontar para o próximo elemento.

Podemos imaginar:

```text
+---------+---------+
| Música  | próximo | ---->
+---------+---------+
```

---

## `Lista`

```c
typedef struct lista* Lista;
```

`Lista` representa um **ponteiro para a estrutura que controla a lista**.

Essa estrutura é responsável por guardar informações gerais da lista, como a quantidade de músicas e o primeiro elemento.

De forma simplificada:

```text
Lista
  |
  v
+----------------+
| informações    |
| da lista       |
+----------------+
       |
       v
    Elemento
       |
       v
    Elemento
       |
       v
     NULL
```

---

# 🛠️ Funções da lista

## 🟢 `criar_lista`

```c
Lista criar_lista(void);
```

Cria uma nova lista e retorna seu endereço.

### Retorno

```c
Lista
```

Retorna a lista criada.

### Exemplo

```c
Lista li = criar_lista();
```

---

# ➕ `inserir_no_inicio`

```c
int inserir_no_inicio(Lista li, Musica valor_inserido);
```

Insere uma música **no começo da lista**.

A nova música passa a ser o primeiro elemento.

### Exemplo

Antes:

```text
[Musica A] -> [Musica B] -> NULL
```

Depois de inserir `Musica C`:

```text
[Musica C] -> [Musica A] -> [Musica B] -> NULL
```

### Retorno

Retorna um `int` indicando se a operação foi realizada com sucesso.

---

# ➕ `inserir_no_final`

```c
int inserir_no_final(Lista li, Musica valor_inserido);
```

Insere uma música **no final da lista**.

### Exemplo

Antes:

```text
[Musica A] -> [Musica B] -> NULL
```

Depois de inserir `Musica C`:

```text
[Musica A] -> [Musica B] -> [Musica C] -> NULL
```

### Retorno

Retorna um `int` indicando o resultado da operação.

---

# 📍 `inserir_por_posicao`

```c
int inserir_por_posicao(Lista li, int posicao, Musica valor_inserido);
```

Insere uma música em uma **posição específica da lista**.

A posição é informada pelo parâmetro:

```c
int posicao
```

### Exemplo

Lista:

```text
[Musica A] -> [Musica B] -> [Musica C]
```

Inserindo `Musica X` na posição 2:

```text
[Musica A] -> [Musica X] -> [Musica B] -> [Musica C]
```

### Parâmetros

| Parâmetro | Função |
|---|---|
| `li` | Lista que será modificada |
| `posicao` | Local onde a música será inserida |
| `valor_inserido` | Música que será adicionada |

---

# ❌ `remover_a_primeira`

```c
int remover_a_primeira(Lista li);
```

Remove a **primeira música da lista**.

### Exemplo

Antes:

```text
[Musica A] -> [Musica B] -> [Musica C]
```

Depois:

```text
[Musica B] -> [Musica C]
```

A primeira música deixa de fazer parte da lista.

---

# ❌ `remover_a_ultima`

```c
int remover_a_ultima(Lista li);
```

Remove a **última música da lista**.

### Exemplo

Antes:

```text
[Musica A] -> [Musica B] -> [Musica C] -> NULL
```

Depois:

```text
[Musica A] -> [Musica B] -> NULL
```

---

# ❌ `remover_por_posicao`

```c
int remover_por_posicao(Lista li, int posicao);
```

Remove a música que está em uma **posição específica**.

### Exemplo

Antes:

```text
[Musica A] -> [Musica B] -> [Musica C]
```

Removendo a posição 2:

```text
[Musica A] -> [Musica C]
```

### Parâmetros

| Parâmetro | Função |
|---|---|
| `li` | Lista que será modificada |
| `posicao` | Posição da música que será removida |

---

# 🔎 `consultar_a_primeira`

```c
Musica consultar_a_primeira(Lista li);
```

Consulta a **primeira música da lista** sem removê-la.

### Exemplo

```text
[Musica A] -> [Musica B] -> [Musica C]
     ↑
  primeira
```

A função retorna a música que está no primeiro elemento.

---

# 🔎 `consultar_por_posicao`

```c
Musica consultar_por_posicao(Lista li, int posicao);
```

Consulta uma música localizada em uma **determinada posição**.

A música é retornada sem ser removida da lista.

### Exemplo

```text
[Musica A] -> [Musica B] -> [Musica C]
                  ↑
               posição
```

Se a posição informada for a de `Musica B`, a função retorna essa música.

---

# 🔢 `consultar_qtd_de_musicas_na_lista`

```c
int consultar_qtd_de_musicas_na_lista(Lista li);
```

Retorna a **quantidade de músicas armazenadas na lista**.

### Exemplo

```text
[Musica A] -> [Musica B] -> [Musica C]
```

Quantidade:

```text
3
```

### Retorno

```c
int
```

Retorna o número de músicas existentes na lista.

---

# 🗑️ `liberar_destruir_a_lista`

```c
void liberar_destruir_a_lista(Lista li);
```

Libera a memória utilizada pela lista.

A função deve percorrer os elementos, liberar cada um deles e, ao final, liberar a própria estrutura da lista.

### Exemplo

Antes:

```text
Lista
  |
  v
[A] -> [B] -> [C] -> NULL
```

Depois de destruir:

```text
Lista
  |
  v
memória liberada
```

Essa função é importante porque os elementos da lista são criados dinamicamente na memória.

---

# 📋 Resumo das funções

| Função | O que faz |
|---|---|
| `criar_lista()` | Cria uma lista |
| `inserir_no_inicio()` | Insere uma música no início |
| `inserir_no_final()` | Insere uma música no final |
| `inserir_por_posicao()` | Insere uma música em uma posição |
| `remover_a_primeira()` | Remove a primeira música |
| `remover_a_ultima()` | Remove a última música |
| `remover_por_posicao()` | Remove uma música pela posição |
| `consultar_a_primeira()` | Consulta a primeira música |
| `consultar_por_posicao()` | Consulta uma música pela posição |
| `consultar_qtd_de_musicas_na_lista()` | Consulta a quantidade de músicas |
| `liberar_destruir_a_lista()` | Libera e destrói a lista |

---

# 🧠 Visão geral

O arquivo `3-lista.h` funciona como a **interface do TAD Lista**.

Ele informa **quais operações existem**, mas não mostra como elas são implementadas.

A implementação fica no arquivo:

```text
4-lista.c
```

Assim, podemos separar o projeto em:

```text
1-musica.h
      ↓
   TAD Musica
      ↓
3-lista.h
      ↓
   TAD Lista
      ↓
4-lista.c
      ↓
Implementação das funções
```
