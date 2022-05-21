#include <stdio.h>
#include <stdlib.h>

int main(){
    int r = 0;
    int s = 0;
    int v = 0;
    char c;
    FILE *file = fopen("list_of_edges103.txt", "r");
    if (!file)
        exit(EXIT_FAILURE);
    c = fgetc(file);
    while (c != EOF)
    {
        if (c == '\n')
        {
            r++;
        }
        c = fgetc(file);
    }
    fclose(file);

    s = r;
    int matrix[100][2];
    int i, j;
    FILE *file1 = fopen("list_of_edges103.txt", "r");
    if (!file1)
        exit(EXIT_FAILURE);
    for (i = 0; i < s && !feof(file1); i++)
    {
        for (j = 0; j < 2 && !feof(file1); j++)
        {
            fscanf(file1, "%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
            if (v < matrix[i][j])
            {
                v = matrix[i][j];
            }
        }
        putchar('\n');
    }
    
    FILE *out;
    out = fopen("output.dot", "w");
    fprintf(out, "graph{\n");
    for (i = 0; i < s; i++)
    {
        fprintf(out, "%d -- %d", matrix[i][0], matrix[i][1]);
        fprintf(out, "\n");
    }

    fprintf(out, "}\n");
    fclose(out);
    system("dot output.dot -Tpng -o image.png");
    fclose(file1);
    for (i = 0; i < s; i++)
    {
        if (matrix[i][0] == matrix[i][1])
        {
            r--;
        }
        if (i > 0 && matrix[i][0] == matrix[i - 1][0] && matrix[i][1] == matrix[i - 1][1])
        {
            r--;
        }
    }

    v++;
    printf("Number of v = %d Number of r = %d\n", v, r);
    if (v <= ((r - 1) * (r - 2) / 2))
    {
        printf("This is a connected graph\n");
    }
    else
    {
        printf("This is a disconnected graph\n");
    }

    return (EXIT_SUCCESS);
}
