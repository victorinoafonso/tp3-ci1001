# TP3 — Programação 1

[svg](https://github.com/victorinoafonso/tp3-ci1001#tp3--programação-1)

**CI1001 — Programação 1**
**Departamento de Informática — UFPR**

Repositório destinado ao desenvolvimento e entrega do **Trabalho Prático 3 (TP3)** da disciplina de Programação 1.

---

## 📚 Sobre o trabalho

[svg](https://github.com/victorinoafonso/tp3-ci1001#-sobre-o-trabalho)

O TP3 consiste na implementação de um programa para manipulação de um **vetor dinâmico de ponteiros para números racionais**, utilizando a linguagem **C**.

Durante o desenvolvimento são trabalhados conceitos fundamentais de programação, como:

* Ponteiros;
* Ponteiros para ponteiros;
* Alocação dinâmica de memória;
* Liberação de memória;
* Manipulação de `struct`;
* Funções;
* Manipulação de números racionais;
* Eliminação de elementos inválidos;
* Ordenação de dados;
* Insertion Sort;
* Operações com números racionais;
* Organização de programas em múltiplos arquivos;
* Gerenciamento de memória com `malloc` e `free`;
* Verificação de vazamentos de memória com **Valgrind**.

---

## 📁 Estrutura do projeto

[svg](https://github.com/victorinoafonso/tp3-ci1001#-estrutura-do-projeto)

```text
tp3/
├── racional.c
├── racional.h
├── tp3.c
├── testes/
│   ├── entrada_1.txt
│   ├── entrada_2.txt
│   ├── entrada_3.txt
│   ├── entrada_4.txt
│   ├── entrada_5.txt
│   ├── entrada_6.txt
│   ├── saida_1.txt
│   ├── saida_2.txt
│   ├── saida_3.txt
│   ├── saida_4.txt
│   ├── saida_5.txt
│   └── saida_6.txt
├── testa.sh
└── README.md
```

### Arquivos

| **Arquivo**  | **Descrição**                                                               |
| ------------ | --------------------------------------------------------------------------- |
| `tp3.c`      | Programa principal e implementação das operações sobre o vetor de racionais |
| `racional.c` | Implementação das funções relacionadas aos números racionais                |
| `racional.h` | Declaração da estrutura e das funções de números racionais                  |
| `testa.sh`   | Script utilizado para executar os testes automaticamente                    |
| `testes/`    | Arquivos de entrada e saída utilizados nos testes                           |
| `README.md`  | Documentação do projeto                                                     |

---

## ⚙️ Compilação

[svg](https://github.com/victorinoafonso/tp3-ci1001#%EF%B8%8F-compilação)

O programa pode ser compilado utilizando o compilador **GCC**:

```bash
gcc -Wall -Wextra -g -std=c99 tp3.c racional.c -o tp3
```

Para executar:

```bash
./tp3
```

---

## 🧪 Testes

[svg](https://github.com/victorinoafonso/tp3-ci1001#-testes)

O projeto possui um script para executar os testes fornecidos junto ao trabalho.

Para executar os testes normalmente:

```bash
./testa.sh 1
```

Para executar os testes utilizando o **Valgrind**, verificando possíveis erros e vazamentos de memória:

```bash
./testa.sh 2
```

O Valgrind permite verificar se toda a memória alocada dinamicamente foi corretamente liberada durante a execução do programa.

---

## 🧠 Principais operações

[svg](https://github.com/victorinoafonso/tp3-ci1001#-principais-operações)

O programa realiza as seguintes operações:

1. Leitura da quantidade de números racionais;
2. Alocação dinâmica de um vetor de ponteiros;
3. Criação dos números racionais;
4. Preenchimento do vetor;
5. Impressão dos elementos;
6. Eliminação dos números racionais inválidos;
7. Ordenação dos racionais em ordem crescente;
8. Cálculo da soma dos elementos;
9. Liberação dos números racionais;
10. Liberação do vetor de ponteiros;
11. Verificação do gerenciamento de memória.

---

## 🛠️ Tecnologias utilizadas

[svg](https://github.com/victorinoafonso/tp3-ci1001#%EF%B8%8F-tecnologias-utilizadas)

* **C**
* **GCC**
* **Linux**
* **Valgrind**
* **Git / GitHub**

---

## 🎯 Objetivos

[svg](https://github.com/victorinoafonso/tp3-ci1001#-objetivos)

O desenvolvimento deste trabalho tem como objetivo aprofundar os conhecimentos de programação em C, especialmente em:

* Alocação dinâmica de memória;
* Uso de ponteiros;
* Uso de ponteiros para ponteiros;
* Manipulação dinâmica de estruturas;
* Ordenação de dados;
* Modularização;
* Gerenciamento e liberação de memória;
* Identificação de erros e vazamentos de memória.

---

## 👨‍💻 Autor

[svg](https://github.com/victorinoafonso/tp3-ci1001#-autor)

**Victorino Afonso**

Estudante de **Ciência da Computação — UFPR**.

---

## 📌 Disciplina

[svg](https://github.com/victorinoafonso/tp3-ci1001#-disciplina)

**CI1001 — Programação 1**
**Departamento de Informática — Universidade Federal do Paraná (UFPR)**

