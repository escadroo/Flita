#include <stdio.h>
#include <ctype.h>
#include <string.h>

int deg2(short deg) {
    int result = 2;
    if (deg == 0) {
        return 1;
    }
    for (short i = 1; i < deg; i++) {
        result = result * 2;
    }
    return result;
}

int perevod(char arg1[]) {
    char len = strlen((arg1));
    int summ = 0;
    char counter = 0;
    char flag;
    for (char y = len - 1; y >= 0; y--) {
        if (arg1[y] != '1' && arg1[y] != '0' && arg1[y] != ' ') {
            return -1;
        }
        summ = summ + ((deg2(counter) * (arg1[y] - 48)));
        counter++;
    }
    return summ;
}

int main(void) {
    char s;
    int decimal[128];
    char processing[128];
    char counter1 = 0;
    char counter2 = 0;
    char counter3 = 0;
    char counted = 0;
    while ((s = getchar()) != '\n') {
        if (s != ' ') {
            processing[counter1] = s;
            counter1++;
        }
        if (s == ' ') {
            decimal[counter2] = perevod(processing);
            counter2++;
            memset(processing, 0, strlen(processing));
            counter1 = 0;
        }
    }
    decimal[counter2] = perevod(processing);
    counter2++;
    memset(processing, 0, strlen(processing));
    counter1 = 0;
    for (int j = 0; j < counter2; j++) {
        printf("%d ", decimal[j]);
    }
}
