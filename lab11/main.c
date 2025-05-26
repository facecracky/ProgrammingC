#include "var_args.h"
#include <stdio.h>

int main() {
    printf("Сумма: %d\n", sum(5, 1, 2, 3, 4, 5));
    printf("Максимм: %d\n", max(4, 10, 30, 20, 5));
    printf("Минимум: %d\n", min(3, -5, 0, 8));
    printf("Сpеднеe: %.2f\n", average(5, 1, 2, 3, 4, 5));

    return 0;
}
