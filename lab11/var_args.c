#include "var_args.h"

// 1. Сумма чисел
int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return total;
}

// 2. Максимальное значение
int max(int count, ...) {
    va_list args;
    va_start(args, count);

    int max_val = INT_MIN; // Начальное значение — минимальное возможное int
    for (int i = 0; i < count; i++) {
        int current = va_arg(args, int);
        if (current > max_val) {
            max_val = current;
        }
    }

    va_end(args);
    return max_val;
}

// 3. Минимальное значение
int min(int count, ...) {
    va_list args;
    va_start(args, count);

    int min_val = INT_MAX; // Начальное значение — максимальное возможное int
    for (int i = 0; i < count; i++) {
        int current = va_arg(args, int);
        if (current < min_val) {
            min_val = current;
        }
    }

    va_end(args);
    return min_val;
}

// 4. Среднее арифметическое
double average(int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return (double)total / count;
}
