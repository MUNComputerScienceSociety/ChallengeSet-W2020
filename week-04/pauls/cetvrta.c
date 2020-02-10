#include <stdio.h>
#define NUMPOINTS 3

void longAlgorithmWay(int *x, int *y);

int main(void) {
  int x[NUMPOINTS], y[NUMPOINTS];
  int missingx, missingy;
  for (int i = 0; i < NUMPOINTS; i++) {
    scanf("%d", &x[i]);
    scanf("%d", &y[i]);
    // printf("%d %d\n", x[i], y[i]);
  }

  /* Only 3 points, easy to figure the missing vertex from compairsons */
  if (x[0] != x[1] & x[0] != x[2])
    missingx = x[0];
  else if (x[1] != x[0])
    missingx = x[1];
  else
    missingx = x[2];

  if (y[0] != y[1] & y[0] != y[2])
    missingy = y[0];
  else if (y[1] != y[0])
    missingy = y[1];
  else
    missingy = y[2];

  printf("%d %d\n", missingx, missingy);
  printf("Or the long algorithmic way\n");
  longAlgorithmWay(x, y);
}

void longAlgorithmWay(int *x, int *y) {
  /* Bad proctice to output in random functions */
  int xfreq[] = {-1, -1, -1};
  int yfreq[] = {-1, -1, -1};
  int xc = 0, yc = 0;

  for (int i = 0; i < NUMPOINTS; i++) {
    xc = 1;
    yc = 1;
    for (int j = i + 1; j < NUMPOINTS; j++) {
      if (x[i] == x[j]) {
        xc++;
        xfreq[j] = 0;
      }
      if (y[i] == y[j]) {
        yc++;
        yfreq[j] = 0;
      }
    }
    if (xfreq[i] != 0)
      xfreq[i] = xc;
    if (yfreq[i] != 0)
      yfreq[i] = yc;
  }
  for (int i = 0; i < NUMPOINTS; i++) {
    if (xfreq[i] == 1)
      printf("%d ", x[i]);
  }
  for (int i = 0; i < NUMPOINTS; i++) {
    if (yfreq[i] == 1)
      printf("%d", y[i]);
  }
  printf("\n");
}