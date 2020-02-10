#include <stdio.h>
#include <string.h>
#define MAX 102

int main() {
  int count;
  if (scanf("%d\n", &count) != 1) {return 1;};
  for (int i=0; i<count; i++) {
    char estimate[MAX];
    if (!fgets(estimate, MAX, stdin)) {return 1;}
    printf("%ld\n", strlen(estimate)-1);
  }
}
