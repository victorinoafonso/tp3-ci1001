/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 09/09/2025 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/* coloque aqui as funções auxiliares que precisar neste arquivo */

/*Alocar vetor de racionais*/
struct racional **aloca_vetor_r(int n)
{
    return malloc(n * sizeof(struct racional *));
}

/*Preencher vetor de racionais*/
void preenche(struct racional **vetor, int n)
{
    int i;
    int num, den;

    for (i = 0; i < n; i++) {
        scanf("%d %d", &num, &den);
        vetor[i] = cria_r(num, den);
    }
}

/*Imprimir vetor de racionais*/
void imprime_vetor(struct racional **vetor, int n)
{
    printf("VETOR = ");

    for (int i = 0; i < n; i++) {
        imprime_r(vetor[i]);

        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

/*Eliminar racionais inválidos*/
void elimina_invalidos(struct racional **vetor, int *n)
{
    int i = 0;

    while (i < *n) {

        if (!valido_r(vetor[i])) {

            destroi_r(&vetor[i]);

            (*n)--;

            vetor[i] = vetor[*n];
        }
        else {
            i++;
        }
    }
}

/*Ordenar vetor de racionais*/
/*Insertion Sort*/
void ordena_vetor(struct racional **vetor, int n)
{
    for (int i = 1; i < n; i++) {
        struct racional *aux = vetor[i];
        int j = i - 1;

        while (j >= 0 && compara_r(vetor[j], aux) > 0) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
    }
}

/*Soma os racionais do vetor*/
struct racional *soma_vetor(struct racional **vetor, int n)
{
    struct racional *resultado = cria_r(0, 1);

    for (int i = 0; i < n; i++) {
        soma_r(resultado, vetor[i], resultado);
    }

    return resultado;
}

/*Destroi vetor de racionais*/
void destroi_vetor(struct racional **vetor, int n)
{
    for (int i = 0; i < n; i++) {
        destroi_r(&vetor[i]);
    }
}

/* programa principal */
int main ()
{
  int n;
  struct racional **vetor;

  scanf("%d", &n);

  vetor = aloca_vetor_r(n);

  preenche(vetor, n);
  imprime_vetor(vetor, n);

  elimina_invalidos(vetor, &n);
  imprime_vetor(vetor, n);

  ordena_vetor(vetor, n);
  imprime_vetor(vetor, n);

  struct racional *soma = soma_vetor(vetor, n);
  printf("SOMA = ");
  imprime_r(soma);
  printf("\n");

  destroi_vetor(vetor, n);
  imprime_vetor(vetor, n);

  free(vetor);
  destroi_r(&soma);
  

  return 0;
}

