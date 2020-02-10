#include <stdio.h>
int main() {
    char n[100];
    int i=0;
    char c;
    while (scanf("%c", &c) == 1 && c != '\n') {
        if (c >= 'A' && c <= 'Z') {
            n[i] = c;
            i++;
        }
    }
    for (int j=0; j<i; j++) {
        printf("%c", n[j]);
    }
    printf("\n");
    return 0;
}