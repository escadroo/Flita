#define _CRT_SECURE_NO_WARNINGS
#define MAX_BOARD 100
#define MATRIX_LEN 100
#include <stdio.h>
#include <stdlib.h>

void quicksort(int number[10000], int first, int last){
    int i, j, pivot, temp;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while((number[i] <= number[pivot]) && (i<last))
                i++;
            while(number[j] > number[pivot])
                j--;
            if(i<j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
    }
}

int main(){
    int r = 0; // ребра
    int s = 0; //кол-во строк
    int v = 0; //вершины
    char c;
    FILE* file = fopen("list_of_edges103.txt", "r");
    if (!file)
        exit(EXIT_FAILURE);
    c = fgetc(file);
    while (c != EOF){
        if (c == '\n'){
            r++;
        }
        c = fgetc(file);
    }
    fclose(file);

    s = r;
    int matrix[MATRIX_LEN][2]; 
    int count_arr[MAX_BOARD] = {0};
    int i, j;


    FILE* file1 = fopen("list_of_edges103.txt", "r"); 
    if (!file1)
        exit(EXIT_FAILURE);
    for (i = 0; i < s && !feof(file1); i++){
        for (j = 0; j < 2 && !feof(file1); j++){
            fscanf(file1, "%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
            if (v < matrix[i][j]){
                v = matrix[i][j];
            }
        }
        putchar('\n');
    }
    fclose(file1);


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
    

    for (int out_bord = 0; out_bord < MAX_BOARD; out_bord++) {
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < 2; j++) {
                if (matrix[i][j] == out_bord) {
                    count_arr[out_bord] += 1;
                }
            }
        }
    }

    //здесь нужно дописать 
    //quicksort
    for(int k=0; k<len;k++){ //прикидываю идею
        for(int l=0;l<len;l++){
            if (int sorted_mass[k] == count_arr[l]){
                printf(l);
            }
        }
    }

    return (EXIT_SUCCESS);
}
