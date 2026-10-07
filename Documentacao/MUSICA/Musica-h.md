# 🎵 Documentação — TAD Música

O arquivo `1-musica.h` corresponde à **interface do TAD Música**. Ele apresenta quais operações podem ser realizadas sobre uma música, sem mostrar como a estrutura interna da música foi implementada.

Essa separação permite que o `main.c` utilize uma música por meio das funções disponibilizadas, sem precisar conhecer seus atributos internos.

---

# `1-musica.h`

## 📌 Inclusão das bibliotecas

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

O arquivo inclui três bibliotecas da linguagem C:

- `stdio.h` — disponibiliza recursos relacionados à entrada e saída de dados, como `printf`.
- `stdlib.h` — possui funções relacionadas à alocação e liberação de memória, como `malloc` e `free`.
- `string.h` — disponibiliza funções para manipulação de strings.

---

## 🎵 Definição do tipo `Musica`

```c
typedef struct musica* Musica;
```

Essa linha cria o tipo `Musica`.

O `struct musica` representa a estrutura que será utilizada para armazenar os dados de uma música.

O detalhe importante é que o `Musica` representa um **ponteiro para essa estrutura**.

```text
Musica
   │
   ▼
┌──────────────────┐
│ struct musica    │
│                  │
│ título           │
│ artista          │
│ duração          │
└──────────────────┘
```

A estrutura `struct musica` não é apresentada no arquivo `.h`. Isso faz parte da ideia de **tipo opaco**: o programa principal sabe que existe um tipo `Musica`, mas não acessa diretamente seus atributos.

A implementação da estrutura fica no arquivo `2-musica.c`.

---

# 🎵 Criação da música

```c
Musica criar_musica(char *titulo, char *artista, int duracao);
```

Essa função é responsável por **criar uma nova música**.

Ela recebe três informações:

| Parâmetro | Tipo | Função |
|---|---|---|
| `titulo` | `char*` | Título da música |
| `artista` | `char*` | Nome do artista |
| `duracao` | `int` | Duração da música |

A função retorna um:

```c
Musica
```

Ou seja, retorna uma referência para a música criada.

Exemplo de utilização:

```c
Musica m = criar_musica("Imagine", "John Lennon", 183);
```

---

# 🔎 Consulta dos dados da música

O arquivo disponibiliza três funções para consultar os dados armazenados.

## Consultar título

```c
char* consultar_titulo(Musica *m);
```

Retorna o **título** da música.

O retorno é `char*`, pois o título é armazenado como uma string.

---

## Consultar artista

```c
char* consultar_artista(Musica *m);
```

Retorna o **nome do artista** associado à música.

Assim como o título, o nome do artista é uma string, por isso a função retorna `char*`.

---

## Consultar duração

```c
int consultar_duracao(Musica *m);
```

Retorna a **duração da música**.

Nesse caso, o retorno é `int`, pois a duração foi definida como um número inteiro.

---

# 🖨️ Impressão dos dados

```c
void imprimir_seus_dados(Musica *m);
```

Essa função é responsável por **imprimir os dados da música**.

Ela recebe uma música como parâmetro e não retorna nenhum valor, por isso utiliza:

```c
void
```

A ideia é centralizar a exibição das informações da música em uma única função.

Por exemplo, ela pode exibir:

```text
Título: Imagine
Artista: John Lennon
Duração: 183 segundos
```

---

# 🗑️ Destruição da música

```c
void destruir_musica(Musica *m);
```

Essa função é responsável por **liberar a memória utilizada pela música**.

Como a música é criada dinamicamente, é necessário liberar essa memória quando ela não for mais utilizada.

A função retorna `void`, pois sua finalidade é realizar a liberação da memória e não retornar um valor.

---

# 📋 Resumo das funções

| Função | Finalidade | Retorno |
|---|---|---|
| `criar_musica()` | Cria uma nova música | `Musica` |
| `consultar_titulo()` | Consulta o título | `char*` |
| `consultar_artista()` | Consulta o artista | `char*` |
| `consultar_duracao()` | Consulta a duração | `int` |
| `imprimir_seus_dados()` | Exibe os dados da música | `void` |
| `destruir_musica()` | Libera a memória da música | `void` |

---

# 🔐 Por que a estrutura não aparece no `.h`?

Uma das características importantes desse código é que o arquivo `1-musica.h` **não mostra os atributos da `struct musica`**.

Em vez de algo como:

```c
struct musica {
    char *titulo;
    char *artista;
    int duracao;
};
```

o arquivo apresenta somente:

```c
typedef struct musica* Musica;
```

Isso permite trabalhar com a música por meio das funções do TAD.

Assim, o `main.c` pode fazer:

```c
Musica m = criar_musica(...);

consultar_titulo(m);
consultar_artista(m);
consultar_duracao(m);

destruir_musica(m);
```

sem precisar acessar diretamente:

```c
m->titulo
m->artista
m->duracao
```

Essa é justamente a ideia de **encapsulamento do TAD**: o arquivo `.h` apresenta **o que pode ser feito**, enquanto o `.c` contém **como isso é feito**.

---

# 🔄 Organização

A relação entre os arquivos pode ser entendida assim:

```text
                1-musica.h
              ┌─────────────┐
              │  Interface  │
              │             │
              │ criar       │
              │ consultar   │
              │ imprimir    │
              │ destruir    │
              └──────┬──────┘
                     │
                     ▼
                2-musica.c
              ┌─────────────┐
              │Implementação│
              │             │
              │ struct      │
              │ funções     │
              │ memória     │
              └─────────────┘
```

Portanto, o `1-musica.h` funciona como o **contrato do TAD Música**: ele define quais operações estão disponíveis para o restante do programa.
