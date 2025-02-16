#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int factorial(int n);

int main() {
    char op, choice;
    float n1, n2, re;

    printf("Welcome to the Advanced Calculator!\n");
    printf("Available operations:\n");
    printf("+ : Addition\n- : Subtraction\n* : Multiplication\n/ : Division\n");
    printf("%% : Modulo (Remainder)\n^ : Power\ns : Square Root\n! : Factorial\np : Percentage\n");

    while (1) {
        printf("\nEnter an operator (+, -, *, /, %%, ^, s, !, p) or 'q' to quit: ");
        scanf(" %c", &op);

        if (op == 'q') {
            printf("Thank you for using the Advanced Calculator. Goodbye!\n");
            break;
        }

        if (op == 's' || op == '!') {
            printf("Enter a number: ");
            scanf("%f", &n1);

            if (op == 's') {
                if (n1 < 0) {
                    printf("Error: Square root of a negative number is not real.\n");
                } else {
                    re = sqrt(n1);
                    printf("result: Square root of %.2f = %.2f\n", n1, re);
                }
            } else if (op == '!') {
                if (n1 < 0 || n1 != (int)n1) {
                    printf("Error: Factorial is only defined for non-negative integers.\n");
                } else {
                    int numInt = (int)n1;
                    re = factorial(numInt);
                    printf("result: Factorial of %d = %lld\n", numInt, (long long int)re);
                }
            }
        } else {
            printf("Enter the first number: ");
            scanf("%f", &n1);
            printf("Enter the second number: ");
            scanf("%f", &n2);

            if (op == '+') {
                re = n1 + n2;
                printf("result: %.2f + %.2f = %.2f\n", n1, n2, re);
            } else if (op == '-') {
                re = n1 - n2;
                printf("result: %.2f - %.2f = %.2f\n", n1, n2, re);
            } else if (op == '*') {
                re = n1 * n2;
                printf("result: %.2f * %.2f = %.2f\n", n1, n2, re);
            } else if (op == '/') {
                if (n2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    re = n1 / n2;
                    printf("result: %.2f / %.2f = %.2f\n", n1, n2, re);
                }
            } else if (op == '%') {
                if (n2 == 0) {
                    printf("Error: Modulo by zero is not allowed.\n");
                } else {
                    int modre = (int)n1 % (int)n2;
                    printf("result: %d %% %d = %d\n", (int)n1, (int)n2, modre);
                }
            } else if (op == '^') {
                re = pow(n1, n2);
                printf("result: %.2f ^ %.2f = %.2f\n", n1, n2, re);
            } else if (op == 'p') {
                re = (n1 * n2) / 100;
                printf("result: %.2f%% of %.2f = %.2f\n", n1, n2, re);
            } else {
                printf("Error: Invalid operator. Try again.\n");
            }
        }
    }
    return 0;
}
long long int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return (long long int)n * factorial(n - 1);
}
