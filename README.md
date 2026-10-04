# 🎵 Playlist de Músicas em C

Projeto desenvolvido em **C** para simular o funcionamento de uma playlist de músicas utilizando uma **lista unicamente encadeada** e **Tipos Abstratos de Dados (TADs)**.

A atividade trabalha conceitos de **estruturas de dados, modularização, tipos opacos, alocação dinâmica e manipulação de listas encadeadas**, além de simular operações comuns de uma playlist.

## 📌 Sobre o projeto

A aplicação organiza músicas em uma playlist. Cada música possui:

- **Título**
- **Artista**
- **Duração**

A playlist é armazenada por meio de uma **lista unicamente encadeada**, permitindo inserir, remover e consultar músicas em diferentes posições.

O projeto também utiliza **TADs com tipos opacos**, mantendo as estruturas internas dos dados protegidas do programa principal.

> A proposta da atividade é implementar os TADs `Musica` e `Lista` e utilizá-los no `main.c` para simular o funcionamento de uma playlist.

## 🎯 Objetivos

- Praticar a implementação de **TADs em C**;
- Utilizar **tipos opacos** para esconder as estruturas internas;
- Implementar uma **lista unicamente encadeada**;
- Trabalhar com **alocação e liberação de memória**;
- Inserir e remover elementos da lista;
- Consultar músicas e informações da playlist;
- Simular a reprodução de músicas;
- Controlar a posição da próxima música a ser reproduzida.

## 📂 Organização do projeto

```text
playlist-em-c/
│
├── .vscode/
│
├── src/
│   ├── 1-musica.h
│   ├── 2-musica.c
│   ├── lista.c
│   ├── lista.h
│   └── main.c
│
├── documentacao.md
├── LICENSE
└── README.md
```

### 📄 Descrição dos arquivos

| Arquivo | Função |
|---|---|
| `1-musica.h` | Interface do TAD Música |
| `2-musica.c` | Implementação do TAD Música |
| `lista.h` | Interface do TAD Lista |
| `lista.c` | Implementação da lista unicamente encadeada |
| `main.c` | Programa principal e simulação da playlist |
| `documentacao.md` | Documentação complementar do projeto |
| `README.md` | Apresentação e organização do projeto |
| `LICENSE` | Licença do projeto |

## 🎵 TAD Música

O TAD Música representa cada música armazenada na playlist.

Cada música possui:

```text
Título
Artista
Duração
```

O TAD é responsável pelas operações relacionadas à criação, consulta, impressão e destruição das músicas.

A utilização de um tipo opaco permite que o `main.c` utilize as operações disponibilizadas pelo TAD sem precisar conhecer diretamente como a estrutura da música foi implementada.

## 📋 TAD Lista

A playlist é representada por uma **lista unicamente encadeada** capaz de armazenar músicas.

Entre as operações previstas para a lista estão:

- Criar a lista;
- Inserir uma música no início;
- Inserir uma música no final;
- Inserir uma música em uma posição específica;
- Remover a primeira música;
- Remover a última música;
- Remover uma música por posição;
- Consultar a primeira música;
- Consultar uma música por posição;
- Consultar a quantidade de músicas;
- Liberar a memória utilizada pela lista.

### 🔗 Estrutura da lista

Cada elemento da lista aponta para o próximo elemento:

```text
┌───────────┐      ┌───────────┐      ┌───────────┐
│  Música 1 │ ───► │  Música 2 │ ───► │  Música 3 │ ───► NULL
└───────────┘      └───────────┘      └───────────┘
```

Dessa forma, as músicas são armazenadas de maneira encadeada.

## ▶️ Funcionamento da playlist

O `main.c` é responsável por utilizar os TADs para simular o funcionamento da playlist.

Entre as funções da aplicação estão:

### `adiciona_musica`

Adiciona uma música ao **final da playlist**.

### `adiciona_musica_posicao`

Adiciona uma música em uma **posição específica** da playlist.

### `remove_musica`

Remove uma música de uma **posição específica**.

### `tempo_restante`

Calcula e informa o **tempo total restante** para o fim da playlist.

### `play`

Simula a reprodução da próxima música.

A função consulta a música correspondente à posição atual, exibe seus dados e avança para a próxima posição da playlist.

A posição da próxima música é controlada por uma variável no `main.c`.

### `musicas_reproduzidas`

Informa a quantidade de músicas que já foram reproduzidas durante a simulação.

## 🧪 Testes no `main.c`

Para testar o funcionamento da aplicação, o programa principal deve criar **10 músicas diretamente no código** e utilizar as funções implementadas para simular diferentes operações da playlist.

Ao final da execução, devem ser apresentadas:

- Quantidade de músicas presentes na playlist;
- Posição da próxima música a ser reproduzida.

## 🧠 Conceitos praticados

- **Linguagem C**
- **TAD (Tipo Abstrato de Dados)**
- **Tipos opacos**
- **Lista unicamente encadeada**
- **Ponteiros**
- **Structs**
- **Alocação dinâmica de memória**
- `malloc`
- `free`
- Inserção e remoção em listas
- Modularização com arquivos `.h` e `.c`

## 🔄 Organização dos TADs

A comunicação entre os arquivos segue a ideia:

```text
             ┌─────────────┐
             │   main.c    │
             └──────┬──────┘
                    │
          utiliza as interfaces
                    │
          ┌─────────┴─────────┐
          ▼                   ▼
   ┌─────────────┐     ┌─────────────┐
   │  1-musica.h │     │   lista.h   │
   └──────┬──────┘     └──────┬──────┘
          │                   │
          ▼                   ▼
   ┌─────────────┐     ┌─────────────┐
   │ 2-musica.c  │     │   lista.c   │
   └─────────────┘     └─────────────┘
```

Essa separação mantém o código organizado e permite que o programa principal trabalhe com as operações dos TADs sem depender diretamente de suas estruturas internas.

## 🛠️ Compilação

Considerando que os arquivos `.c` estão dentro de `src/`:

```bash
gcc src/main.c src/2-musica.c src/lista.c -o playlist
```

Depois, execute:

### Windows

```bash
playlist.exe
```

### Linux / macOS

```bash
./playlist
```

## 📚 Atividade

Este projeto foi desenvolvido como uma atividade prática de programação em C envolvendo **TAD Música**, **TAD Lista** e uma aplicação de playlist baseada em lista unicamente encadeada.

A proposta também envolve a criação de um programa principal capaz de testar as operações implementadas e simular a reprodução das músicas.

---

⭐ **Projeto acadêmico desenvolvido para prática de estruturas de dados e programação em C.**
