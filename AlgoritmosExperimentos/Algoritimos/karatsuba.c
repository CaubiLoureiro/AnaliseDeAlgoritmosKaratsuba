#include "polinomio.h"
#include <sys/resource.h>





void Tempo_CPU_Sistema(double *seg_CPU_total, double *seg_sistema_total)
{
    long seg_CPU, seg_sistema, mseg_CPU, mseg_sistema;
    struct rusage ptempo;

    getrusage(0,&ptempo);

    seg_CPU = ptempo.ru_utime.tv_sec;
    mseg_CPU = ptempo.ru_utime.tv_usec;
    seg_sistema = ptempo.ru_stime.tv_sec;
    mseg_sistema = ptempo.ru_stime.tv_usec;

    *seg_CPU_total     = (seg_CPU + 0.000001 * mseg_CPU);
    *seg_sistema_total = (seg_sistema + 0.000001 * mseg_sistema);
}





int main(int argc, char const *argv[]) {
    coef_poli *A, *B, C;
    int n=1, k=1;
    double s_CPU_inicial, s_total_inicial, s_CPU_final, s_total_final, tempo_total;

    

    while(k<=15){

        A = inicializa_poli(n);
        B = inicializa_poli(n);

        
        


        Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

        C = mult_karatsuba(*A, *B);

        Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);

        tempo_total = s_CPU_final - s_CPU_inicial;

        FILE* arquivo = fopen("karatsuba", "a+");
        fprintf(arquivo, "%d/%f\n", k, tempo_total);
        fclose(arquivo);
        if(k==2){
            print_poli(&C);
        }

        n=n*2;
        k++;

    }

















		
    return 0;
}
