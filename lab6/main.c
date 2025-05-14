#include <stdio.h>
#include <stdlib.h>

#define ogranich 256

void process_file(const char *in_file, const char *out_file) {
    FILE *in = fopen(in_file, "r");
    FILE *out = fopen(out_file, "w");

    char line[ogranich];
    while (fgets(line, ogranich, in)) {
        char imya[100], familiya[100], otchestvo[100];
        int year;

        if (sscanf(line, "%99s %99s %99s %d", imya, familiya, otchestvo, &year) == 4) {
            if (year > 1980) {
                fprintf(out, "%s %s %s %d\n", imya, familiya, otchestvo, year);
            }
        }
    }

}

int main() {
    process_file("input.txt", "output.txt");
    return 0;
}
