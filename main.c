#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int **Array, int index1, int index2) {
      int *tmp = Array[index1];
      Array[index1] = Array[index2];
      Array[index2] = tmp;
}

int partition(int **Array, int left, int right) {
      int pivot = Array[right][1];
      int i = left - 1;

      for (int j = left; j < right; ++j)
      if (Array[j][1] <= pivot)
                      swap(Array, ++i, j);

      swap(Array, i + 1, right);

      return i + 1;
}

void quick_sort(int **Array, int left, int right) {
      if (left < right) {
      int mid = partition(Array, left, right);
      quick_sort(Array, left, mid - 1);
      quick_sort(Array, mid + 1, right);
      }
}

void free_table(int **table, int length) {
      for (size_t i = 0; i < length; ++i)
              free(table[i]);
      free(table);
}

int **read_table_from_file(FILE *fs, int *size) {
      int **table;
      int **copy_table;
      int current_length;
      int maximum_length;
      int count;
      int x, c;

      current_length = 0;
      maximum_length = 1;
      table = (int **) malloc(maximum_length * sizeof(int *));
      if (table == NULL) {
              fputs("Allocation error.\n", stderr);
              return NULL;
      }

      count = 0;
      while (fscanf(fs, "%d", &x) != EOF) {
              c = fgetc(fs);

              if (c == '\n') {
                      ++current_length;

                      if (current_length >= maximum_length) {
                              maximum_length *= 2;

                              copy_table = table;
                              table = (int **) realloc(table, maximum_length * sizeof(int *));

                              if (table == NULL) {
                                      fputs("Allocation error.\n", stderr);
                                      free_table(copy_table, current_length);
                                      return NULL;
                              }
                      }

                      table[current_length - 1] = (int *) malloc(2 * sizeof(int));
                      if (table[current_length - 1] == NULL) {
                              fputs("Allocation error.\n", stderr);
                              free_table(table, current_length);
                              return NULL;
                      }

                      table[current_length - 1][0] = current_length;
                      table[current_length - 1][1] = count;
                      count = 0;
              } else {
                      ++count;
              }
      }

      *size = current_length;

      return table;
}

int main(int argc, char **argv) {
      FILE *graph_fs;
      FILE *output_fs;
      int **table;
      int size;
      clock_t start_time;
      clock_t end_time;

      graph_fs = fopen(argv[1], "r+");
      if (graph_fs == NULL) {
              fputs("Can't open file.\n", stderr);
              return 1;
      }

      table = read_table_from_file(graph_fs, &size);
      if (table == NULL) {
              fputs("Error in function read_table_from_file.\n", stderr);
              return 1;
      }

      fclose(graph_fs);

      start_time = clock();
      quick_sort(table, 0, size - 1);
      end_time = clock();

      output_fs = fopen(argv[2], "a+");
      if (output_fs == NULL) {
              fputs("Can't open file.\n", stderr);
              return 2;
      }

      fprintf(output_fs, "%lf\n", (double) (end_time - start_time) / CLOCKS_PER_SEC);

      fclose(output_fs);
      free_table(table, size);

      return 0;
}
