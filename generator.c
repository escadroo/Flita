#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOTTOM_BORDER 10
#define UPPER_BORDER 30

int main(int argc, char **argv) {
    FILE *output_fs;
    size_t number_of_vertex;
    size_t number_of_edges;
    unsigned short bottom_border;
    unsigned short upper_border;

    output_fs = fopen(argv[1], "w+");
    if (output_fs == NULL) {
        fputs("Can't open file for read.\n", stderr);
        return 1;
    }

    number_of_vertex = atoi(argv[2]);
    srand(time(NULL));

    for (size_t i = 1; i < number_of_vertex + 1; ++i) {
        fprintf(output_fs, "%ld ", i);

        bottom_border = (number_of_vertex < UPPER_BORDER) ? 1 : BOTTOM_BORDER;
        upper_border = (number_of_vertex < UPPER_BORDER) ? number_of_vertex : UPPER_BORDER;

        number_of_edges = bottom_border + rand() % (upper_border - bottom_border + 1);

        for (size_t j = 1; j < number_of_edges + 1; ++j)
            fprintf(output_fs, "%ld%s", j, j == number_of_edges ? "\n" : " ");
    }

    fclose(output_fs);

    return 0;
}
