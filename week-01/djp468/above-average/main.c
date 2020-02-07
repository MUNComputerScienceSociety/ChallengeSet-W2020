#include <stdio.h>
int main () {
    int c;
    if (scanf("%d", &c) != 1) {return 1;};
    for (int i=0; i<c; i++) {
    int s;
        if (scanf("%d", &s) != 1) {return 1;};
        int g[s];
        int t=0;
        for (int j=0; j<s; j++) {
            if (scanf("%d", &g[j]) != 1) {return 1;};
            t+=g[j];
        }
        float a=(float)t/s;
        int w=0;
        for (int j=0; j<s; j++) {
            if (g[j]>a) {
                w++;
            }
        }
        float r=(float)w/s;
        printf("%.3f%%\n", r*100);
    }
    return(0);
}