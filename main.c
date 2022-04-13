#include <stdio.h>
#include <stdlib.h>

int main(){
  int matrix[13][2];
  int i, j, k;
  FILE *file = fopen("list_of_edges103.txt", "r");
  if (!file)
    exit(EXIT_FAILURE);
  for (i = 0; i < 13 && !feof(file); i++){
    for (j = 0; j < 2 && !feof(file); j++){
      fscanf(file, "%d", &matrix[i][j]);
      printf("%d ", matrix[i][j]);
    }
    putchar('\n');
  }
  fclose(file);

  FILE *out;
  out = fopen("output.dot", "w");
  fprintf(out, "graph{\n");
for (i = 0; i < 12; i++){
    fprintf(out, "%d -- %d", matrix[i][j], matrix[i][j + 1]);
    fprintf(out, "\n");
}

fprintf(out, "}\n");
fclose(out);
system("dot output.dot -Tpng -o image.png");

return (EXIT_SUCCESS);
}