#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long double ieee754(float input){
    int expoente;
    long double mantissa;

    expoente = floor(log2(input));
    printf("%d\n", expoente);
    mantissa = input/pow(2, expoente);
    printf("%.20Lf\n", mantissa);
    expoente += 1023; // bias 64bits

    if (fmod(input, 2) != 0)
        mantissa /= 2;

    return mantissa;
}

void main(){
    long double xk, fxk, Dfxk, xk1, erro, precisao;
    long double input;
    int i = 0;

    precisao = 0.000000000000000001;
    scanf(" %Lf", &input);
    xk1 = ieee754(input);
    //xk1 = input/4 + 1;
    do {
        printf("***********************iteracao = %d\n", i++);
        xk = xk1;
        printf("Xk = %.20Lf\n", xk);
        fxk = (xk * xk) - input;
        printf("f(Xk) = %.20Lf\n", fxk);
        Dfxk = 2 * xk;
        printf("f'(Xk) = %.20Lf\n", Dfxk);
        xk1 = xk - fxk/Dfxk;
        printf("Xk+1 = %.20Lf\n", xk1);
        erro = fabs(xk1 - xk);
        printf("erro = %.25Lf\n", erro);
        
        printf("absolutamente ratissimo mudando qualquer coisa atras de uma peita\n");
    } while(erro > precisao);

    printf("\n");
    printf("\nprecisao = %.25Lf\n", precisao);
    printf("xk = %.30Lf\n", xk);
}
