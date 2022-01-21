#include "stdlib.h"
#include "stdio.h"
#include "complex.h"


#define printCoef(c) printf("%d\n",c)

// Representação por coeficientes de um polinômio
typedef struct Polinomio {
  int grau;
  int * coef;
}coef_poli;



// Funções refetentes à representação de coeficientes
//########################################################################################################################################

// Inicializa um polinômio sob a representação de coeficientes
coef_poli* inicializa_poli();

// Multiplica dois polinômios sob a representação de "coeficientes": O(n^2)
coef_poli mult_direta(coef_poli *, coef_poli *);

// Multiplica o polinômio sob a representação de "coeficientes" por x^k
coef_poli delc_poli(coef_poli ,int );

// Exibe os coeficientes de um polinômio sob a representação "coeficientes"
void print_poli(coef_poli *P);

// Recupere les k premiers coefficients d'un polynome sous la representation "coefficients"
coef_poli poli_esquerda(coef_poli, int);

// Obtém os últimos k coeficientes de um polinômio sob a representação "coeficientes"
coef_poli poli_direita(coef_poli,int );

// Criamos um polinômio de grau k
coef_poli cria_poli(int );

// Adiciona dois polinômios sob a representação de "coeficientes"
coef_poli add_poli(coef_poli , coef_poli );

// Retorna o oposto de um polinômio sob a representação de "coeficientes"
coef_poli invert_poli(coef_poli );

// Multiplica dois polinômios sob a representação de "coeficientes" usando Karatsuba: O(n^log(3))
coef_poli mult_karatsuba(coef_poli ,coef_poli);
