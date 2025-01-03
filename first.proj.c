#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int n);

int main() {
    char op, choice;
    float num1, num2, result;

    printf("Welcome to the Advanced Calculator!\n");
    printf("Available operations:\n");
    printf("+ : Addition\n- : Subtraction\n* : Multiplication\n/ : Division\n");
    printf("%% : Modulo (Remainder)\n^ : Power\ns : Square Root\n! : Factorial\np : Percentage\n");

    do {
        printf("\nEnter an operator (+, -, *, /, %%, ^, s, !, p): ");
        scanf(" %c", &op);

        if (op == 's' || op == '!') {
            printf("Enter a number: ");
            scanf("%f", &num1);

            if (op == 's') {
                // Square Root operation
                if (num1 < 0) {
                    printf("Error: Square root of a negative number is not real.\n");
                } else {
                    result = sqrt(num1);
                    printf("Result: Square root of %.2f = %.2f\n", num1, result);
                }
            } else if (op == '!') {

                if (num1 < 0 || num1 != (int)num1) {
                    printf("Error!!Factorial is only defined for non-negative integers.Enter +ive Integers except 0.\n");
                } else {
                    int numInt = (int)num1;  // Cast to int
                    result = factorial(numInt);
                    printf("Result: Factorial of %d = %.0f\n", numInt, result);
                }
            }
        } else {
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);

            if (op == '+') {
                result = num1 + num2;
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
            } else if (op == '-') {
                result = num1 - num2;
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
            } else if (op == '*') {
                result = num1 * num2;
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
            } else if (op == '/') {
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                }
            } else if (op == '%') {
                // Modulo operation (integer based)
                if ((int)num2 == 0) {
                    printf("Error: Modulo by zero is not allowed.\n");
                } else {
                    int modResult = (int)num1 % (int)num2;
                    printf("Result: %d %% %d = %d\n", (int)num1, (int)num2, modResult);
                }
            } else if (op == '^') {
                // Power operation
                result = pow(num1, num2);
                printf("Result: %.2f ^ %.2f = %.2f\n", num1, num2, result);
            } else if (op == 'p') {
                // Percentage calculation
                result = (num1 * num2) / 100;
                printf("Result: %.2f%% of %.2f = %.2f\n", num2, num1, result);
            } else {
                printf("Error: Invalid operator. Try again.\n");
            }
        }
        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &choice);
        } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Advanced Calculator. Goodbye!\n");
    return 0;
}
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
