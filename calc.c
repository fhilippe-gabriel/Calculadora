#include <stdio.h>
#include <stdlib.h>

float calcular(float num1, float num2, char op) {
    switch(op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if(num2 != 0) {
                return num1 / num2;
            } else {
                printf("Erro: divisao por zero!\n");
                exit(1); // Encerra o programa em caso de erro
            }
        default:
            printf("Operacao invalida!\n");
            exit(1); // Encerra o programa em caso de erro
    }
}

int main() {
    char expressao[100];
    float num1, num2;
    char op;
    float resultado;

    while(1) { // Loop infinito
        // Solicita ao usuário que insira a expressão
        printf("Digite a expressao (ou 's' para sair): ");
        scanf("%s", expressao);

        if(expressao[0] == 's' && expressao[1] == '\0') // Verifica se o usuário quer sair
            break;

        // Lê os valores e a operação da expressão
        sscanf(expressao, "%f%c%f", &num1, &op, &num2);

        // Calcula o resultado
        resultado = calcular(num1, num2, op);

        // Exibe o resultado
        printf("Resultado: %.2f\n", resultado);
    }

    return 0;
}
