#include <stdio.h>

int main() {
    int N = 0;
    scanf("%d", &N);
    while(N-- > 0) {
        int a, b, c, possible=0;
        scanf("%d %d %d", &a, &b, &c);
        if(a+b==c) possible++;
        if(a*b==c) possible++;
        if(a-b==c || b-a==c) possible++;
        if((float)a/(float)b==(float)c || (float)b/(float)a==(float)c) { possible++; }
        printf("%sossible\n", possible>0?"P":"Imp");
    }
    return 0;
}

