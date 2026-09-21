/*
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 20/09/2024 para a disciplina CI1001 - Programação 1.
 * Atualizado em 09/09/2025 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
 */

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/* aqui vem a struct racional propriamente dita, nao modifique! */
struct racional
{
    long num; /* numerador   */
    long den; /* denominador */
};

/* Retorna o numerador do racional r */
long numerador_r(struct racional *r)
{
    return r->num;
}

/* Retorna o denominador do racional r */
long denominador_r(struct racional *r)
{
    return r->den;
}

struct racional *cria_r(long numerador, long denominador)
{
    struct racional *r;

    /*Alocar memória para o struct racional */
    r = malloc(sizeof(struct racional));

    if (r == NULL)
        return NULL;

    r->num = numerador;
    r->den = denominador;

    return r;
}

/* Libera a memória alocada para o racional apontado por r */
void destroi_r (struct racional **r)
{
    if (r != NULL)
    {
        free(*r); /*Libera a memória alocada para o struct racional */
        *r = NULL; /*Atribui NULL ao ponteiro */
    }
}

/* Maximo Divisor Comum entre a e b      */
/* calcula o mdc pelo metodo de Euclides */
long mdc(long a, long b)
{
    a = labs(a);
    b = labs(b);

    while (b != 0)
    {
        long resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

/* Minimo Multiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc(long a, long b)
{
    /* mmc de zero com qualquer numero é sempre zero */
    if (a == 0 || b == 0)
        return 0;

    return (labs(a) * labs(b)) / mdc(a, b);
}



/* Retorna 1 se o racional r for válido ou 0 se for inválido. Um racional
 * é inválido se o denominador for zero ou se ele não tiver sido alocado. */
int valido_r (struct racional *r){

    if (r == NULL || r->den == 0)
        return 0;

    return 1;
}

/* Simplifica o número racional indicado no parâmetro.
 * Por exemplo, se o número for 10/8 muda para 5/4.
 * Retorna 1 em sucesso e 0 se r for inválido ou o ponteiro for nulo.
 * Se ambos numerador e denominador forem negativos, o resultado é positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador. */
int simplifica_r(struct racional *r)
{
    /* ponteiro nulo ou racional inválido */
    if (r == NULL || !valido_r(r))
        return 0;

    long divisor = mdc(r->num, r->den);

    r->num = r->num / divisor;
    r->den = r->den / divisor;

    if (r->den < 0)
    {
        r->num = r->num * (-1);
        r->den = r->den * (-1);
    }

    return 1;
}

/*Imprime o número racional r*/
void imprime_r (struct racional *r)
{
    if (r == NULL)
    {
        printf("NULL");
        return;
    }

    if (!valido_r(r))
    {
        printf("NaN");
        return;
    }

    simplifica_r(r);

    if (numerador_r(r) == 0)
    {
        printf("0");
        return;
    }

    if (numerador_r(r) == denominador_r(r))
    {
        printf("1");
        return;
    }

    if (denominador_r(r) == 1)
    {
        printf("%ld", numerador_r(r));
        return;
    }

    printf("%ld/%ld", numerador_r(r), denominador_r(r));

}

/*Compara dois números racionais r1 e r2*/
int compara_r (struct racional *r1, struct racional *r2)
{
    if (!valido_r(r1) || !valido_r(r2))
        return -2;

    long denominador_comum= mmc(denominador_r(r1), denominador_r(r2));

    long racional1 = numerador_r(r1) * (denominador_comum / denominador_r(r1));
    long racional2 = numerador_r(r2) * (denominador_comum / denominador_r(r2));

    if (racional1 < racional2)
        return -1;

    else if (racional1 > racional2 )
        return 1;
   
    return 0;

}


/* Coloca em *r3 a soma simplificada dos racionais *r1 e *r2.
 * Retorna 1 em sucesso e 0 se r1 ou r2 for inválido ou um ponteiro for nulo. */
int soma_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
    if (r3 == NULL || !valido_r(r1) || !valido_r(r2))
        return 0;

    if (r1->den == r2->den)
    {
        r3->num = r1->num + r2->num;
        r3->den = r1->den;
    }
    else
    {
        long denominador_comum = mmc(r1->den, r2->den);

        r3->num = (r1->num * (denominador_comum / r1->den)) + (r2->num * (denominador_comum / r2->den));
        r3->den = denominador_comum;
    }

    simplifica_r(r3);
    return 1;
}

/* Coloca em *r3 a diferença simplificada dos racionais *r1 e *r2.
 * Retorna 1 em sucesso e 0 se r1 ou r2 for inválido ou um ponteiro for nulo. */
int subtrai_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
    if (r3 == NULL || !valido_r(r1) || !valido_r(r2))
        return 0;

    if (r1->den == r2->den)
    {
        r3->num = r1->num - r2->num;
        r3->den = r1->den;
    }
    else
    {
        long denominador_comum = mmc(r1->den, r2->den);

        r3->num = (r1->num * (denominador_comum / r1->den)) - (r2->num * (denominador_comum / r2->den));
        r3->den = denominador_comum;
    }

    simplifica_r(r3);
    return 1;
}

/* Coloca em *r3 o produto simplificado dos racionais *r1 e *r2.
 * Retorna 1 em sucesso e 0 se r1 ou r2 for inválido ou um ponteiro for nulo. */
int multiplica_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
    if (r3 == NULL || !valido_r(r1) || !valido_r(r2))
        return 0;

    r3->num = r1->num * r2->num;
    r3->den = r1->den * r2->den;

    simplifica_r(r3);
    return 1;
}

/* Coloca em *r3 a divisão simplificada do racional *r1 por *r2.
 * Retorna 1 em sucesso e 0 se r1 ou r2 for inválido ou um ponteiro for nulo. */
int divide_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
    if (r3 == NULL || !valido_r(r1) || !valido_r(r2) || r2->num == 0)
        return 0;

    r3->num = r1->num * r2->den;
    r3->den = r1->den * r2->num;

    simplifica_r(r3);
    return 1;
}
