#include "polinomio.h"



coef_poli* inicializa_poli(int n)
{
	int i;
    int numero;
	coef_poli *Poli = (coef_poli*)malloc(sizeof(coef_poli));  //Aloca memoria para o struct

	Poli->grau = n;

	Poli->coef = (int*)malloc((Poli->grau +1)*sizeof(int));     // Aloca grau+1 para a caixa de complexo

	for (i=0; i <= Poli->grau; i++)       // Laço para receber os coeficientes
	{
        Poli->coef[i] = 3;
	}
	return Poli;       // Retorna o polinomio de entrada
}



coef_poli mult_direta(coef_poli *Poli1, coef_poli *Poli2)
{

	coef_poli Poli3;
    Poli3 = cria_poli(Poli1->grau + Poli2->grau);      // Aloca memória para o polinômio produzido

	for (int i = 0; i <= Poli1->grau;i++)
	{
		for (int j = 0; j <= Poli2->grau; j++)
		{
			Poli3.coef[i+j] += Poli1->coef[i] * Poli2->coef[j];       // Multiplica os coeficientes levando em consideração seu grau
		}
	}

	return Poli3;      // Retorna o produto da multiplicação
}



void print_poli(coef_poli *Poli)
{
	printf("\nO polinômio é:\n");

	for (int i = 0; i <= Poli->grau; i++)     // Para cada 0 <= i <= grau
	{
		printCoef(Poli->coef[i]);       // Mostra os coeficientes de grau i
	}
}



coef_poli poli_direita(coef_poli p,int k)
{
  coef_poli r;
  int i;

  if (k<0)
  {
    r = cria_poli(0);
    return r;
  }

  r = cria_poli(p.grau-k-1);       // Criamos um novo polinômio de grau k-1

  for (i = 0; i < p.grau-k && i<=p.grau; i++)
  {
    r.coef[i] = p.coef[i+k+1];        // Copia os últimos k-1 coeficientes para este novo polinômio
  }

  return r;     

}



coef_poli poli_esquerda(coef_poli p, int k)
{
 coef_poli r;
 

 if (k<=0)
 {
   r = cria_poli(0);
   return r;
 }

 r = cria_poli(k);      // Criamos um novo polinômio de grau k

 for (int i=0; i<=k && i<=p.grau; i++)
 {
   r.coef[i] = p.coef[i];     // Copie os primeiros k coeficientes para este novo polinômio
 }

 return r;     
}



coef_poli invert_poli(coef_poli p)
{
  
  coef_poli r;
  r = cria_poli(p.grau);   // Criamos um novo polinômio de mesmo grau

  for (int i = 0; i <= r.grau; i++)
  {
    r.coef[i] = -1 * p.coef[i];       // Para cada coeficiente tomamos o oposto

  }
  return r;     // Retorna polinômio
}



coef_poli delc_poli(coef_poli p,int k)
{

 coef_poli r;

 r = cria_poli(p.grau +k);     // Criamos um novo polinômio cujo grau é aumentado em k comparado ao polinômio original


 for (int i=0; i <= p.grau ;i++)
    r.coef[k+i]=p.coef[i];        // Deslocamos os coeficientes em um grau k


 return r;      
}



coef_poli add_poli(coef_poli p,coef_poli q)
{
 int i;
 coef_poli r;

 if (p.grau>=q.grau)  i=p.grau;
 else i=q.grau;

 r = cria_poli(i);      // Criamos um novo polinômio cujo grau é equivalente ao do polinômio de grau mais alto

 for (i=0; i <= r.grau;i++)        // Para cada i menor que este grau somamos os coeficientes
 {
     if (i <= p.grau && i <= q.grau)
         r.coef[i] = p.coef[i] + q.coef[i];
     else if (i <= p.grau)
         r.coef[i] = p.coef[i];
     else
         r.coef[i] = q.coef[i];
 }

 return r;
}



coef_poli cria_poli(int grau)
{
    coef_poli Poli;
    Poli.coef = (int *)calloc(sizeof(int), (size_t) (grau + 1));     // Nós alocamos grau + 1 complexos na memória

    Poli.grau = grau;        // O grau deste novo polinômio é grau

    return Poli;       

}



coef_poli mult_karatsuba(coef_poli A, coef_poli B)
{
  int n;
  n= (A.grau>B.grau) ? A.grau:B.grau;
  if (n < 2)    // Se o grau polinomial de grau mais alto for menor ou igual a dois, chamamos a multiplicação padrão
    return mult_direta(&A, &B);

 n = (n/2);     // Dividimos o grau por dois

 coef_poli A0,A1,B0,B1,C,D,E,F,G,Prod;

 A0 = poli_esquerda(A,n);        // Obtemos a primeira metade do polinômio 1
 A1 = poli_direita(A,n);     // Obtemos a última metade do polinômio 1

 B0 = poli_esquerda(B,n);        // Obtemos a primeira metade do polinômio 2
 B1 = poli_direita(B,n);     // Obtemos a última metade do polinômio 1



 D = mult_karatsuba(A0, B0);
 E = mult_karatsuba(A1, B1);
 C = mult_karatsuba(add_poli(A0,A1),add_poli(B0,B1));


 F = add_poli(invert_poli(D), invert_poli(E));
 G = add_poli(F,C);


 G = delc_poli(G, n+1);      // Corrigimos o deslocamento causado pela separação em dois dos polinômios
 E = delc_poli(E, 2*n+2);

 Prod = add_poli(D,G);
 Prod = add_poli(Prod,E);

 return Prod;      // Retorna produto da multiplicação
 }
