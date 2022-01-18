#include "polinomio.h"

int main()
{
    coef_poli *A, *B, C;

    A = inicializa_poli();
    B = inicializa_poli();

    C = mult_direta(A, B);
    print_poli(&C);

    return 0;
}
