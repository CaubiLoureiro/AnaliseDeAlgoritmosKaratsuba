#include "polinomio.h"

int main(int argc, char const *argv[]) {
    coef_poli *A, *B, C;

    A = inicializa_poli();
    B = inicializa_poli();

    C = mult_karatsuba(*A, *B);
    print_poli(&C);
		
    return 0;
}
