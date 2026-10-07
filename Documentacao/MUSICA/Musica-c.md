# 🎵 Documentação — `2-musica.c`

O arquivo `2-musica.c` contém a **implementação do TAD Música** apresentado no `1-musica.h`.

Enquanto o `.h` define quais operações podem ser utilizadas, o `.c` mostra **como cada operação funciona internamente**.

Neste arquivo são definidos:

- a estrutura `struct musica`;
- a criação de uma música;
- a consulta de seus dados;
- a impressão dos dados;
- a destruição da música e liberação da memória.

---

# 📌 Inclusão das bibliotecas

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "1-musica.h"
```

São incluídas as bibliotecas necessárias para a implementação.

### `stdio.h`

Utilizada para funções de entrada e saída. Neste arquivo, é utilizada principalmente pelo:

```c
printf()
```

que aparece no método `imprimir_seus_dados()`.

### `stdlib.h`

Fornece funções relacionadas à memória dinâmica.

Neste código, são utilizadas:

```c
malloc()
free()
```

`malloc()` é utilizada para reservar memória para uma nova música e `free()` para liberar essa memória quando ela não for mais necessária.

### `string.h`

Utilizada para operações com strings.

Neste código, a função utilizada é:

```c
strncpy()
```

Ela permite copiar o título e o nome do artista para dentro da estrutura da música.

### `1-musica.h`

```c
#include "1-musica.h"
```

Inclui a interface do TAD Música.

Isso permite que o arquivo `2-musica.c` utilize o tipo:

```c
Musica
```

e mantenha as funções implementadas de acordo com as declarações feitas no arquivo `.h`.

---

# 🎵 Estrutura `struct musica`

```c
struct musica {
    char titulo[100];
    char artista[100];
    int duracao;
};
```

Aqui está definida a estrutura interna de uma música.

Ela possui três atributos:

| Atributo | Tipo | Função |
|---|---|---|
| `titulo` | `char[100]` | Armazena o título da música |
| `artista` | `char[100]` | Armazena o nome do artista |
| `duracao` | `int` | Armazena a duração da música |

Por exemplo, uma música poderia possuir:

```text
Título: Imagine
Artista: John Lennon
Duração: 183
```

Na memória, a estrutura pode ser representada como:

```text
┌──────────────────────────────┐
│       struct musica          │
├──────────────────────────────┤
│ titulo[100]                  │
│ "Imagine"                    │
├──────────────────────────────┤
│ artista[100]                 │
│ "John Lennon"                │
├──────────────────────────────┤
│ duracao                      │
│ 183                          │
└──────────────────────────────┘
```

Essa estrutura fica no arquivo `.c`, e não no `.h`.

Isso mantém a característica de **tipo opaco** do TAD: o programa que utiliza `Musica` não precisa conhecer diretamente seus atributos internos.

---

# 🆕 Método `criar_musica()`

```c
Musica criar_musica(char *titulo, char *artista, int duracao) {
    Musica m = malloc(sizeof(struct musica));

    if (m != NULL) {
        strncpy(m->titulo, titulo, sizeof(m->titulo) - 1);
        m->titulo[sizeof(m->titulo) - 1] = '\0';

        strncpy(m->artista, artista, sizeof(m->artista) - 1);
        m->artista[sizeof(m->artista) - 1] = '\0';

        m->duracao = duracao;
    }

    return m;
}
```

Esse método é responsável por **criar uma nova música na memória** e preencher seus dados.

## 1. Alocação da memória

```c
Musica m = malloc(sizeof(struct musica));
```

Primeiro, `malloc()` reserva na memória um espaço suficiente para armazenar uma `struct musica`.

O resultado de `malloc()` é armazenado em `m`.

Podemos imaginar:

```text
m
│
▼
┌─────────────────────┐
│ struct musica       │
│ titulo              │
│ artista             │
│ duracao             │
└─────────────────────┘
```

Se a memória não puder ser alocada, `malloc()` retorna `NULL`.

---

## 2. Verificação da alocação

```c
if (m != NULL) {
```

Antes de tentar utilizar a estrutura, o código verifica se a memória foi realmente alocada.

Isso evita tentar acessar uma posição de memória inválida.

Se:

```c
m == NULL
```

a criação não foi realizada.

---

## 3. Copiando o título

```c
strncpy(m->titulo, titulo, sizeof(m->titulo) - 1);
```

O título recebido pelo método é copiado para:

```c
m->titulo
```

O operador `->` é utilizado porque `m` é um ponteiro para a estrutura.

A expressão:

```c
sizeof(m->titulo) - 1
```

limita a quantidade de caracteres copiados, deixando espaço para o caractere final da string:

```text
'\0'
```

---

## 4. Garantindo o final da string

```c
m->titulo[sizeof(m->titulo) - 1] = '\0';
```

Essa linha garante que o título termine com `'\0'`.

Em C, strings precisam possuir esse caractere para indicar onde terminam.

Isso é importante porque, caso o texto recebido seja grande demais para o espaço disponível, o `strncpy()` pode não colocar `'\0'` automaticamente.

---

## 5. Copiando o artista

```c
strncpy(m->artista, artista, sizeof(m->artista) - 1);
```

Funciona da mesma maneira que o título.

O nome do artista recebido como parâmetro é copiado para:

```c
m->artista
```

---

## 6. Garantindo o final do nome do artista

```c
m->artista[sizeof(m->artista) - 1] = '\0';
```

Assim como no título, essa linha garante que a string do artista termine corretamente com `'\0'`.

---

## 7. Armazenando a duração

```c
m->duracao = duracao;
```

A duração recebida como parâmetro é armazenada diretamente no atributo `duracao`.

Por exemplo:

```c
duracao = 183;
```

resulta em:

```text
m->duracao
     ↓
    183
```

---

## 8. Retorno da música

```c
return m;
```

Depois de preencher todos os dados, o método retorna `m`.

Assim, quem chamou `criar_musica()` recebe a referência para a música criada.

Exemplo:

```c
Musica m = criar_musica("Imagine", "John Lennon", 183);
```

---

# 🔎 Método `consultar_titulo()`

```c
char* consultar_titulo(Musica *m) {
    return m->titulo;
}
```

Esse método retorna o **título da música**.

O parâmetro:

```c
Musica *m
```

representa a música que será consultada.

O retorno é:

```c
m->titulo
```

Como `titulo` é um vetor de caracteres, ele representa uma string e pode ser retornado como `char*`.

### Fluxo

```text
m
│
▼
┌──────────────────┐
│ titulo           │ ───► "Imagine"
│ artista          │
│ duracao          │
└──────────────────┘
          │
          ▼
     retorna título
```

---

# 🔎 Método `consultar_artista()`

```c
char* consultar_artista(Musica *m) {
    return m->artista;
}
```

Funciona de maneira semelhante ao método anterior.

Ele acessa:

```c
m->artista
```

e retorna o nome do artista armazenado na música.

Por exemplo:

```c
char *artista = consultar_artista(m);
```

poderia retornar:

```text
"John Lennon"
```

---

# 🔎 Método `consultar_duracao()`

```c
int consultar_duracao(Musica *m) {
    return m->duracao;
}
```

Esse método retorna a duração armazenada na música.

Como `duracao` foi definida como:

```c
int duracao;
```

o método também possui retorno do tipo:

```c
int
```

Por exemplo, se a duração armazenada for:

```text
183
```

o método retorna:

```text
183
```

---

# 🖨️ Método `imprimir_seus_dados()`

```c
void imprimir_seus_dados(Musica *m) {
    if (m == NULL) {
        return;
    }

    int minutos = m->duracao / 60;
    int segundos = m->duracao % 60;

    printf("%s - %s (%d:%02d)\n",
           m->titulo,
           m->artista,
           minutos,
           segundos);
}
```

Esse método é responsável por **exibir os dados da música formatados na tela**.

Ele também transforma a duração, que está armazenada em segundos, para o formato:

```text
minutos:segundos
```

---

## 1. Verificação da música

```c
if (m == NULL) {
    return;
}
```

Primeiro, o método verifica se existe uma música válida.

Se:

```c
m == NULL
```

não existe uma estrutura válida para consultar.

Nesse caso, o método simplesmente encerra sua execução com:

```c
return;
```

---

## 2. Calculando os minutos

```c
int minutos = m->duracao / 60;
```

A duração está armazenada em segundos.

Para descobrir quantos minutos existem, o código divide a duração por `60`.

Por exemplo:

```text
183 / 60 = 3
```

Como estamos trabalhando com `int`, a parte decimal é descartada.

Portanto:

```text
183 segundos = 3 minutos + alguns segundos
```

---

## 3. Calculando os segundos restantes

```c
int segundos = m->duracao % 60;
```

O operador `%` calcula o **resto da divisão**.

Para:

```text
183 % 60
```

o resultado é:

```text
3
```

Portanto:

```text
183 segundos
= 3 minutos e 3 segundos
```

---

## 4. Exibindo os dados

```c
printf("%s - %s (%d:%02d)\n",
       m->titulo,
       m->artista,
       minutos,
       segundos);
```

O `printf()` exibe:

1. o título;
2. o artista;
3. a duração formatada.

A saída será semelhante a:

```text
Imagine - John Lennon (3:03)
```

### O que significa `%02d`?

```c
%02d
```

indica que o número deve ocupar pelo menos **dois caracteres**, preenchendo com `0` quando necessário.

Por exemplo:

```text
3:03
```

em vez de:

```text
3:3
```

Isso deixa a duração no formato tradicional de uma música.

---

# 🗑️ Método `destruir_musica()`

```c
void destruir_musica(Musica *m) {
    if (m != NULL) {
        free(m);
    }
}
```

Esse método é responsável por **liberar a memória alocada para uma música**.

A memória foi reservada anteriormente por:

```c
malloc()
```

Portanto, quando a música não for mais necessária, essa memória deve ser liberada.

---

## 1. Verificação

```c
if (m != NULL) {
```

Antes de liberar a memória, o código verifica se existe uma música válida.

---

## 2. Liberação

```c
free(m);
```

O `free()` devolve ao sistema a memória que havia sido reservada pelo `malloc()`.

O fluxo é:

```text
criar_musica()
      │
      ▼
   malloc()
      │
      ▼
┌───────────────┐
│ Música        │
│ na memória    │
└───────────────┘
      │
      │ uso
      ▼
destruir_musica()
      │
      ▼
    free()
      │
      ▼
 memória liberada
```

---

# 📋 Resumo dos métodos

| Método | Função | Retorno |
|---|---|---|
| `criar_musica()` | Aloca memória e cria uma música | `Musica` |
| `consultar_titulo()` | Retorna o título | `char*` |
| `consultar_artista()` | Retorna o artista | `char*` |
| `consultar_duracao()` | Retorna a duração | `int` |
| `imprimir_seus_dados()` | Exibe os dados formatados | `void` |
| `destruir_musica()` | Libera a memória da música | `void` |

---

# 🔄 Funcionamento geral

Os métodos trabalham em conjunto seguindo este fluxo:

```text
             criar_musica()
                   │
                   ▼
          ┌─────────────────┐
          │ Música criada   │
          │                 │
          │ título          │
          │ artista         │
          │ duração         │
          └────────┬────────┘
                   │
          ┌────────┼────────┐
          ▼        ▼        ▼
       consultar consultar imprimir
        título     artista   dados
          │        │        │
          └────────┼────────┘
                   │
                   ▼
          destruir_musica()
                   │
                   ▼
             free(m)
                   │
                   ▼
          Memória liberada
```

Dessa forma, o `2-musica.c` implementa todas as operações declaradas no `1-musica.h`.

O `.h` define **quais operações existem**, enquanto o `.c` define **como essas operações são realizadas**.

---

# 💡 Relação entre `1-musica.h` e `2-musica.c`

```text
1-musica.h
   │
   │ declara
   ▼
┌──────────────────────┐
│ criar_musica()       │
│ consultar_titulo()   │
│ consultar_artista()  │
│ consultar_duracao()  │
│ imprimir_seus_dados()│
│ destruir_musica()    │
└──────────┬───────────┘
           │
           │ implementa
           ▼
2-musica.c
   │
   ├── struct musica
   ├── malloc()
   ├── strncpy()
   ├── printf()
   └── free()
```
