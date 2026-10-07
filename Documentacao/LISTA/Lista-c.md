# 🎵 Documentação — `4-lista.c`

## 📌 Sobre o arquivo

O arquivo `4-lista.c` contém a **implementação das funções declaradas em `3-lista.h`**.

Enquanto o arquivo `3-lista.h` informa quais funções existem, este arquivo mostra **como cada uma delas funciona**.

A lista utilizada é uma **lista encadeada**, na qual cada elemento possui:

- uma música;
- um ponteiro para o próximo elemento.

A estrutura pode ser representada assim:

```text
+---------+---------+     +---------+---------+     +---------+---------+
| Música  | próximo | --> | Música  | próximo | --> | Música  | NULL    |
+---------+---------+     +---------+---------+     +---------+---------+
```

---

# 📚 Bibliotecas utilizadas

```c
#include <stdio.h>
#include <stdlib.h>
#include "3-lista.h"
```

### `stdio.h`

Biblioteca padrão de entrada e saída.

### `stdlib.h`

É utilizada principalmente para:

```c
malloc()
free()
```

Essas funções permitem criar e liberar memória dinamicamente.

### `3-lista.h`

Inclui as declarações do TAD `Lista`, além do TAD `Musica` utilizado pela lista.

---

# 🧱 Estrutura `elemento`

```c
struct elemento {
    Musica valor;
    struct elemento *proximo;
};
```

Essa estrutura representa **um elemento da lista**.

Ela possui duas informações principais:

```text
+-------------------+
|      elemento     |
+-------------------+
| valor             |
| próximo           |
+-------------------+
```

### `valor`

```c
Musica valor;
```

Armazena a música daquele elemento.

### `proximo`

```c
struct elemento *proximo;
```

É um ponteiro que guarda o endereço do **próximo elemento da lista**.

Quando não existe próximo elemento:

```c
proximo = NULL;
```

Isso indica o final da lista.

---

# 🧱 Estrutura `lista`

```c
struct lista {
    int quantidade;
    struct elemento *inicio;
};
```

Essa estrutura representa a **própria lista**.

Ela possui duas informações:

### `quantidade`

```c
int quantidade;
```

Armazena quantas músicas existem atualmente na lista.

### `inicio`

```c
struct elemento *inicio;
```

Guarda o endereço do **primeiro elemento da lista**.

Podemos imaginar:

```text
Lista
  |
  v
+------------------+
| quantidade = 3   |
| inicio ----------|------+
+------------------+      |
                          v
                       [A] -> [B] -> [C] -> NULL
```

---

# 🟢 Método `criar_lista`

```c
Lista criar_lista() {
    Lista li = malloc(sizeof(struct lista));

    if(li != NULL) {
        li->quantidade = 0;
        li->inicio = NULL;
    }

    return li;
}
```

Esse método cria uma nova lista na memória.

## 1. Reservando memória

```c
Lista li = malloc(sizeof(struct lista));
```

O `malloc` reserva espaço suficiente para armazenar uma `struct lista`.

O endereço dessa memória é armazenado em:

```c
li
```

---

## 2. Verificando se a memória foi criada

```c
if(li != NULL)
```

Se `li` for diferente de `NULL`, significa que a memória foi alocada com sucesso.

---

## 3. Inicializando a quantidade

```c
li->quantidade = 0;
```

A lista começa vazia.

```text
quantidade = 0
```

---

## 4. Inicializando o início

```c
li->inicio = NULL;
```

Como ainda não existem elementos, não existe primeiro elemento.

```text
inicio -> NULL
```

---

## 5. Retornando a lista

```c
return li;
```

O endereço da lista criada é devolvido para quem chamou a função.

### Resultado inicial

```text
Lista
+------------------+
| quantidade = 0   |
| inicio ----------|----> NULL
+------------------+
```

---

# ➕ Método `inserir_no_inicio`

```c
int inserir_no_inicio(Lista li, Musica valor_inserido)
```

Insere uma nova música **no começo da lista**.

---

## 1. Criando um novo elemento

```c
Elemento novo = malloc(sizeof(struct elemento));
```

É reservada memória para um novo elemento.

```text
novo
  |
  v
+---------+---------+
|         |         |
| valor   | próximo |
+---------+---------+
```

---

## 2. Verificando a alocação

```c
if(novo != NULL)
```

Verifica se a memória foi alocada corretamente.

---

## 3. Colocando a música no elemento

```c
novo->valor = valor_inserido;
```

A música recebida pela função é armazenada no novo elemento.

---

## 4. Ligando o novo elemento à lista

```c
novo->proximo = li->inicio;
```

O novo elemento passa a apontar para o antigo primeiro elemento.

Antes:

```text
inicio
  |
  v
[A] -> [B] -> NULL
```

Depois dessa linha:

```text
novo
  |
  v
[C] -> [A] -> [B] -> NULL
```

---

## 5. Atualizando o início

```c
li->inicio = novo;
```

Agora o novo elemento passa oficialmente a ser o primeiro.

```text
inicio
  |
  v
[C] -> [A] -> [B] -> NULL
```

---

## 6. Atualizando a quantidade

```c
li->quantidade++;
```

A quantidade de músicas aumenta em 1.

---

## 7. Retornando sucesso

```c
return 1;
```

O valor `1` indica que a inserção foi realizada.

Se o `malloc` falhar:

```c
return 0;
```

indica falha.

---

# ➕ Método `inserir_no_final`

```c
int inserir_no_final(Lista li, Musica valor_inserido)
```

Insere uma música no **final da lista**.

---

## 1. Criando o novo elemento

```c
Elemento novo = malloc(sizeof(struct elemento));
```

É criada memória para o novo elemento.

---

## 2. Armazenando a música

```c
novo->valor = valor_inserido;
```

---

## 3. Indicando que ele será o último

```c
novo->proximo = NULL;
```

Como o elemento será colocado no final, ele não aponta para ninguém.

```text
[C] -> NULL
```

---

## 4. Verificando se a lista está vazia

```c
if(li->inicio == NULL)
```

Se o início for `NULL`, significa que não existe nenhum elemento.

Nesse caso:

```c
li->inicio = novo;
```

O novo elemento passa a ser o primeiro e também o último.

```text
inicio
  |
  v
[C] -> NULL
```

Depois:

```c
li->quantidade++;
return 1;
```

---

## 5. Percorrendo a lista

Se a lista não estiver vazia:

```c
Elemento auxiliar = li->inicio;
```

O ponteiro `auxiliar` começa no primeiro elemento.

```text
auxiliar
   |
   v
[A] -> [B] -> [C] -> NULL
```

---

## 6. Andando até o último

```c
while(auxiliar->proximo != NULL) {
    auxiliar = auxiliar->proximo;
}
```

Enquanto existir um próximo elemento, `auxiliar` avança.

Exemplo:

```text
1º:
auxiliar
   |
   v
[A] -> [B] -> [C] -> NULL

2º:
        auxiliar
           |
           v
[A] -> [B] -> [C] -> NULL

3º:
                auxiliar
                   |
                   v
[A] -> [B] -> [C] -> NULL
```

Quando `auxiliar->proximo == NULL`, chegamos ao último elemento.

---

## 7. Ligando o último ao novo

```c
auxiliar->proximo = novo;
```

Agora o antigo último aponta para o novo.

```text
[A] -> [B] -> [C] -> [D] -> NULL
```

Depois:

```c
li->quantidade++;
return 1;
```

---

# 📍 Método `inserir_por_posicao`

```c
int inserir_por_posicao(Lista li, int posicao, Musica valor_inserido)
```

Insere uma música em uma posição específica da lista.

---

## 1. Verificando a posição

```c
if(posicao < 0 || posicao > li->quantidade) {
    return 0;
}
```

A posição não pode ser menor que `0` nem maior que a quantidade atual.

Por exemplo, em uma lista com 3 elementos:

```text
[A] -> [B] -> [C]
```

São permitidas posições de inserção:

```text
0   1   2   3
```

A posição `3` é permitida porque representa a inserção depois do último elemento.

---

## 2. Criando o novo elemento

```c
Elemento novo = malloc(sizeof(struct elemento));
```

---

## 3. Armazenando a música

```c
novo->valor = valor_inserido;
```

---

## 4. Caso a posição seja 0

```c
if(posicao == 0)
```

Se a posição for `0`, a inserção acontece no início.

```c
novo->proximo = li->inicio;
li->inicio = novo;
```

Antes:

```text
inicio
  |
  v
[A] -> [B] -> NULL
```

Depois:

```text
inicio
  |
  v
[X] -> [A] -> [B] -> NULL
```

---

## 5. Caso seja outra posição

```c
else {
    Elemento auxiliar = li->inicio;
```

O `auxiliar` começa no primeiro elemento.

Depois:

```c
for(int i = 0; i < posicao - 1; i++) {
    auxiliar = auxiliar->proximo;
}
```

O objetivo é fazer o `auxiliar` parar **no elemento anterior à posição onde o novo será inserido**.

Exemplo:

```text
[A] -> [B] -> [C]
        ↑
     auxiliar
```

Se queremos inserir entre `B` e `C`, precisamos chegar primeiro em `B`.

---

## 6. Ligando o novo elemento

```c
novo->proximo = auxiliar->proximo;
```

O novo elemento passa a apontar para o elemento que estava depois do auxiliar.

Depois:

```c
auxiliar->proximo = novo;
```

O elemento anterior passa a apontar para o novo.

Resultado:

```text
[A] -> [B] -> [X] -> [C]
```

---

## 7. Atualizando a quantidade

```c
li->quantidade++;
```

---

# ❌ Método `remover_a_primeira`

```c
int remover_a_primeira(Lista li)
```

Remove o primeiro elemento da lista.

---

## 1. Verificando se está vazia

```c
if(li->inicio == NULL) {
    return 0;
}
```

Se não existe primeiro elemento, não há nada para remover.

---

## 2. Guardando o primeiro elemento

```c
Elemento auxiliar = li->inicio;
```

Agora `auxiliar` aponta para o elemento que será removido.

```text
auxiliar
   |
   v
[A] -> [B] -> [C]
```

---

## 3. Avançando o início

```c
li->inicio = auxiliar->proximo;
```

O início passa a apontar para o segundo elemento.

```text
inicio
  |
  v
[B] -> [C]
```

---

## 4. Liberando o antigo primeiro

```c
free(auxiliar);
```

A memória do elemento removido é liberada.

---

## 5. Atualizando a quantidade

```c
li->quantidade--;
```

---

# ❌ Método `remover_a_ultima`

```c
int remover_a_ultima(Lista li)
```

Remove o último elemento da lista.

---

## 1. Verificando se a lista está vazia

```c
if(li->inicio == NULL) {
    return 0;
}
```

---

## 2. Criando um auxiliar

```c
Elemento auxiliar = li->inicio;
```

Ele começa no primeiro elemento.

---

## 3. Caso exista apenas um elemento

```c
if(auxiliar->proximo == NULL)
```

Significa que a lista possui somente um elemento.

```text
inicio
  |
  v
[A] -> NULL
```

Então:

```c
li->inicio = NULL;
free(auxiliar);
li->quantidade--;
return 1;
```

A lista volta a ficar vazia.

---

## 4. Encontrando o último elemento

Quando existem vários elementos:

```c
Elemento penultimo = NULL;
```

São utilizados dois ponteiros:

```text
penultimo   auxiliar
    |           |
    v           v
   [B] -> [C] -> NULL
```

O `while` percorre a lista:

```c
while(auxiliar->proximo != NULL) {
    penultimo = auxiliar;
    auxiliar = auxiliar->proximo;
}
```

Ao terminar:

```text
penultimo       auxiliar
    |               |
    v               v
   [B] -> [C] -> NULL
```

`auxiliar` está no último elemento e `penultimo` está no anterior.

---

## 5. Retirando o último da lista

```c
penultimo->proximo = NULL;
```

O penúltimo passa a ser o último.

```text
[A] -> [B] -> NULL
```

Depois:

```c
free(auxiliar);
```

A memória do antigo último é liberada.

Por fim:

```c
li->quantidade--;
return 1;
```

---

# ❌ Método `remover_por_posicao`

```c
int remover_por_posicao(Lista li, int posicao)
```

Remove um elemento localizado em uma posição específica.

---

## 1. Verificando a posição

```c
if(posicao < 0 || posicao >= li->quantidade) {
    return 0;
}
```

A posição precisa existir.

Diferente da inserção, aqui a posição não pode ser igual à quantidade.

Por exemplo:

```text
[A] -> [B] -> [C]
```

As posições existentes são:

```text
0    1    2
```

---

## 2. Começando pelo início

```c
Elemento auxiliar = li->inicio;
```

---

## 3. Caso seja a primeira posição

```c
if(posicao == 0)
```

O primeiro elemento será removido.

```c
li->inicio = auxiliar->proximo;
free(auxiliar);
li->quantidade--;
return 1;
```

Resultado:

```text
Antes:

[A] -> [B] -> [C]

Depois:

[B] -> [C]
```

---

## 4. Encontrando o elemento anterior

Para posições maiores que zero:

```c
for(int i = 0; i < posicao - 1; i++) {
    auxiliar = auxiliar->proximo;
}
```

O objetivo é deixar `auxiliar` no elemento **anterior ao que será removido**.

Exemplo:

```text
[A] -> [B] -> [C] -> [D]
        ↑       ↑
     auxiliar  remover
```

---

## 5. Guardando o elemento que será removido

```c
Elemento a_remover = auxiliar->proximo;
```

Agora temos:

```text
auxiliar
   |
   v
  [B] -----> [C] -----> [D]
               ↑
          a_remover
```

---

## 6. Pulando o elemento

```c
auxiliar->proximo = a_remover->proximo;
```

O elemento anterior passa a apontar diretamente para o próximo.

```text
[B] ----------------> [D]
```

O `[C]` deixou de fazer parte da sequência.

---

## 7. Liberando a memória

```c
free(a_remover);
```

Depois:

```c
li->quantidade--;
return 1;
```

---

# 🔎 Método `consultar_a_primeira`

```c
Musica consultar_a_primeira(Lista li)
```

Retorna a música que está no primeiro elemento.

---

## 1. Verificando se está vazia

```c
if(li->inicio == NULL) {
    return NULL;
}
```

Se não existe primeiro elemento, não existe música para retornar.

---

## 2. Retornando a música

```c
return li->inicio->valor;
```

O acesso acontece em duas etapas:

```text
li->inicio
    ↓
primeiro elemento
    ↓
->valor
    ↓
música
```

A função apenas consulta o valor. Ela **não remove** o elemento.

---

# 🔎 Método `consultar_por_posicao`

```c
Musica consultar_por_posicao(Lista li, int posicao)
```

Consulta uma música em uma posição específica.

---

## 1. Verificando a posição

```c
if(posicao < 0 || posicao >= li->quantidade) {
    return NULL;
}
```

Se a posição não existir, a função retorna `NULL`.

---

## 2. Começando no primeiro elemento

```c
Elemento auxiliar = li->inicio;
```

---

## 3. Percorrendo até a posição

```c
for(int i = 0; i < posicao; i++) {
    auxiliar = auxiliar->proximo;
}
```

O `auxiliar` vai avançando pela lista.

Exemplo para consultar a posição 2:

```text
[A] -> [B] -> [C] -> [D]
 ↑       ↑       ↑
 0       1       2
                 ↑
             auxiliar
```

---

## 4. Retornando a música

```c
return auxiliar->valor;
```

A música armazenada naquele elemento é retornada.

---

# 🔢 Método `consultar_qtd_de_musicas_na_lista`

```c
int consultar_qtd_de_musicas_na_lista(Lista li)
```

Retorna a quantidade de músicas existentes.

A função simplesmente acessa:

```c
return li->quantidade;
```

Por exemplo:

```text
[A] -> [B] -> [C]

quantidade = 3
```

Resultado:

```text
3
```

---

# 🗑️ Método `liberar_destruir_a_lista`

```c
void liberar_destruir_a_lista(Lista li)
```

Essa função libera **toda a memória utilizada pela lista**.

É uma das funções mais importantes porque os elementos foram criados utilizando `malloc`.

---

## 1. Verificando se a lista existe

```c
if(li == NULL) {
    return;
}
```

Se a lista não existe, não há nada para liberar.

---

## 2. Começando pelo primeiro elemento

```c
Elemento auxiliar = li->inicio;
```

O `auxiliar` começa apontando para o primeiro elemento.

---

## 3. Percorrendo todos os elementos

```c
while(auxiliar != NULL)
```

Enquanto existir um elemento, ele será processado.

---

## 4. Guardando o elemento atual

```c
Elemento atual = auxiliar;
```

Agora `atual` representa o elemento que será destruído.

---

## 5. Avançando antes de liberar

```c
auxiliar = auxiliar->proximo;
```

Essa linha é muito importante.

Primeiro guardamos o próximo elemento:

```text
atual
 |
 v
[A] -> [B] -> [C]
       ↑
   auxiliar
```

Assim podemos liberar `[A]` sem perder o endereço de `[B]`.

---

## 6. Destruindo a música

```c
destruir_musica(atual->valor);
```

A música armazenada naquele elemento também é destruída.

Isso acontece porque a lista possui músicas que também podem utilizar memória dinâmica.

---

## 7. Liberando o elemento

```c
free(atual);
```

A memória daquele elemento da lista é liberada.

O processo continua até chegar em:

```text
auxiliar == NULL
```

---

## 8. Liberando a própria lista

Depois que todos os elementos foram liberados:

```c
free(li);
```

A estrutura que representa a lista também é liberada.

---

# 🧠 Funcionamento da destruição

O processo completo pode ser visualizado assim:

```text
[A] -> [B] -> [C] -> NULL
 ↓
destruir música A
 ↓
free(A)

[B] -> [C] -> NULL
 ↓
destruir música B
 ↓
free(B)

[C] -> NULL
 ↓
destruir música C
 ↓
free(C)

NULL
 ↓
free(lista)
```

---

# 🔗 Resumo da lógica da lista

A lista funciona utilizando **ponteiros encadeados**.

Cada elemento conhece o endereço do próximo:

```text
+---------+---------+
| Música  | próximo |----+
+---------+---------+    |
                         ↓
                    +---------+---------+
                    | Música  | próximo |----+
                    +---------+---------+    |
                                             ↓
                                        +---------+
                                        |  NULL   |
                                        +---------+
```

A estrutura `Lista` guarda o endereço do primeiro elemento:

```text
Lista
 |
 +-- quantidade
 |
 +-- inicio
       |
       v
      [A] -> [B] -> [C] -> NULL
```

---

# 📌 Operações principais

| Método | Função |
|---|---|
| `criar_lista()` | Cria e inicializa uma lista |
| `inserir_no_inicio()` | Adiciona no começo |
| `inserir_no_final()` | Adiciona no final |
| `inserir_por_posicao()` | Adiciona em uma posição |
| `remover_a_primeira()` | Remove o primeiro elemento |
| `remover_a_ultima()` | Remove o último elemento |
| `remover_por_posicao()` | Remove por posição |
| `consultar_a_primeira()` | Consulta a primeira música |
| `consultar_por_posicao()` | Consulta por posição |
| `consultar_qtd_de_musicas_na_lista()` | Retorna a quantidade |
| `liberar_destruir_a_lista()` | Libera toda a memória |

---

# 🎯 Ideia principal

O ponto mais importante deste arquivo é entender que a lista **não armazena todos os elementos juntos na memória**.

Cada elemento é criado separadamente com `malloc` e conectado ao próximo por meio de um ponteiro:

```text
[A] -> [B] -> [C] -> NULL
```

Por isso, para inserir, remover ou consultar determinados elementos, o programa frequentemente precisa **percorrer a lista utilizando ponteiros auxiliares**.

Os principais recursos utilizados são:

```text
malloc()  → reserva memória
free()    → libera memória
->        → acessa campos através de ponteiros
NULL      → indica ausência de elemento
proximo   → permite avançar pela lista
```

Dessa forma, `4-lista.c` é responsável por transformar as declarações de `3-lista.h` em operações reais sobre uma **lista encadeada de músicas**.
