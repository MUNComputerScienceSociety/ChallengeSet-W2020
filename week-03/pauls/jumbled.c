#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  unsigned int numbytes;
  short unsigned int dataval;
  scanf("%d", &numbytes);
  for (unsigned int i = 0; i < numbytes; i++){
    unsigned int convertedvalue = 0;
    scanf("%hd", &dataval);
    for (short unsigned int j = 0; j < 8; j++){
      convertedvalue = (((dataval ^ convertedvalue) & (unsigned int)pow(2, j)) << 1) | convertedvalue;
    }
      printf("%d ", convertedvalue / 2);
  }
  printf("\n");
}