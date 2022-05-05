#include <stdio.h>
#include <stdlib.h>


int main(){
  int s, t;
  int i, j, k;
  printf("Enter the number of lines: ");
  scanf("%d", &s);
  printf("Enter the number of columns: ");
  scanf("%d", &t);
  int matrix[s][t];
  FILE *file = fopen("list_of_edges103.txt", "r");
    if (!file)
      exit(EXIT_FAILURE);
    for (i = 0; i < s && !feof(file); i++){
      for (j = 0; j < t && !feof(file); j++){
        fscanf(file, "%d", &matrix[i][j]);
        printf("%d ", matrix[i][j]);
      }
      putchar('\n');
    }
    fclose(file);

  FILE *out;
    out = fopen("output.dot", "w");
    fprintf(out, "graph{\n");
    for (i = 0; i < s; i++){
        fprintf(out, "%d -- %d", matrix[i][0], matrix[i][1]);
        fprintf(out, "\n");
    }

  fprintf(out, "}\n");
  fclose(out);
  system("dot output.dot -Tpng -o image.png");

  return (EXIT_SUCCESS);
}
