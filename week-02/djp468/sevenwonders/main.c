#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 51
int min(int a, int b) {
  return a < b ? a : b;
}
int ipow(int v, int p) {
  int r = v;
  for (int i=0; i<p-1; i++) {
    r *= r;
  }
  return r;
}
int main() {
  char cards[MAX];
  int t = 0;
  int c = 0;
  int g = 0;
  fgets(cards, MAX, stdin);
  for (int i=0; i<strlen(cards); i++) {
    switch (cards[i]) {
      case 'T':
        t++;
        break;
      case 'C':
        c++;
        break;
      case 'G':
        g++;
        break;
    }
  }
  printf("%d\n", ipow(t, 2) + ipow(c, 2) + ipow(g, 2) + (min(min(t, c), g) * 7));
}
