#include <stdio.h>
#include <stdlib.h>
int comp(const void *p, const void *q) {
    int a = *(const int *)p;
    int b = *(const int *)q;
    return a < b ? 1 : -1;
}
void stack(int t[], int a, int b, int c) {
    for (int i=0; i<3; i++) {

        for (int j=0; j<3; j++) {

        }
    }
    return;
}
int main() {
    int h1, h2;
    int box[6];
    int t1[3];
    int t2[3];
    for (int i=0; i<6; i++) {
        if (scanf("%d", &box[i]) != 1) {return 1;}
    }
    if (scanf("%d %d", &h1, &h2) != 2) {return 1;}
    int a, b, c;
    for (a=0; a<6; a++) {
        for (b=a+1; b<6; b++) {
            for (c=b+1; c<6; c++) {
                if (box[a] + box[b] + box[c] == h1) {
                    t1[0] = box[a];
                    t1[1] = box[b];
                    t1[2] = box[c];
                    qsort(t1, 3, sizeof(int), comp);
                    goto endl;
                }
            }
        }
    }
    endl:;
    int f = 0;
    for (int x=0; x<6; x++) {
        if (f > 2) {break;}
        if (x != a && x != b && x != c) {
            t2[f] = box[x];
            f++;
        }
    }
    qsort(t2, 3, sizeof(int), comp);
    for (int i=0; i<3; i++) {
        printf("%d ", t1[i]);
    }
    for (int i=0; i<3; i++) {
        printf(i == 2 ? "%d\n" : "%d ", t2[i]);
    }
}