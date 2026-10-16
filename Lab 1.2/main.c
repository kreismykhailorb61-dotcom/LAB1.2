// Бібліотеки для роботи програми
#include <stdio.h>
#include <stdlib.h>
// Бібліотека для розрахунків
#include <math.h>

// Функція для Варіанту 6: f(x) = (x^2 / 1000) - 0.5 * x - 1000
double calculate_function(double x) {
    return (pow(x, 2) / 1000.0) - (0.5 * x) - 1000.0;
}
//Програма
int main() {
    //Оголошення змінних та ініціалізація деяких(N, prev_fx)
    unsigned int input_variant, N = 0;
    double x1, x2, delta, x, fx, prev_fx = 0;
    unsigned int i;

    // Валідація вибору варіанта вводу
        printf("Choose Variant:\n");
        printf("Enter variant (1 or 2): ");
        scanf("%u", &input_variant);

        if (input_variant != 1 && input_variant != 2) {
            printf("Invalid variant! Please try again.\n\n");
        }
//Шапка для введення змінних для подальшої роботи
    printf("1. Enter X1, X2 and number of points (N)\n");
    printf("2. Enter X1, X2 and step (delta)\n");
    printf("Enter initial value X1: ");
    scanf("%lf", &x1);
    printf("Enter final value X2: ");
    scanf("%lf", &x2);
//Робота для 1 варіанту
    if (input_variant == 1) {
        printf("Enter number of points N (>1): ");
        scanf("%u", &N);
        delta = (x2 - x1) / (N - 1);}
//Робота для 2 варіанту
    else {
        printf("Enter step delta: ");
        scanf("%lf", &delta);
        N = (unsigned int)((x2 - x1) / delta) + 1;
    }

    system("cls"); // Очищення екрану

    // Виведення шапки таблиці
    printf("X1 = %.2lf, X2 = %.2lf, Delta = %.2lf, Points N = %u\n", x1, x2, delta, N);
    printf("+--------+---------------------------+---------------------------+\n");
    printf("| %-6s | %-25s | %-25s |\n", "N", "Argument (X)", "Function F(X)");
    printf("+--------+---------------------------+---------------------------+\n");

    // Цикл розрахунку та виведення
    for (i = 0; i < N; i++) {
        x = x1 + i * delta;
        fx = calculate_function(x);

        printf("| %-6u | %-25.4lf | %-25.4lf |\n", i + 1, x, fx);

        // Пошук зміни знака функції
        if (i > 0 && (prev_fx * fx < 0)) {
            printf("+--------+---------------------------+---------------------------+\n");
            printf("  [!] Root interval detected between X = %.4lf and X = %.4lf\n", x - delta, x);
            printf("+--------+---------------------------+---------------------------+\n");
        }
    }
    printf("+--------+---------------------------+---------------------------+\n");

    return 0;
}
