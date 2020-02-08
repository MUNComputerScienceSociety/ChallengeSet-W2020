#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  /* use fgets to prevent buffer overflows.  With all compiler warnings enabled
   * use of scanf and gets should generate a warning.
   * This necessitates extra steps to read from input.
   * 1. Create a buffer
   * 2. Read, setting a maximum of the buffersize
   * 3. Convert the read characters to an integer (can be done many ways)
   */
  char inputline[10];
  fgets(inputline, 10, stdin);
  int brokenswords = strtol(inputline, NULL, 10);

  /* Setup and read the each swords slats status string
   * no need to convert from the read characters to a number, just use the
   * character values.
   * The problem description makes it clear that a 0 is an unbroken slat. Beware
   * thinking that 1 is a good slat, when in fact it indicates that the slat was
   * broken. No need to count the broken slats, only the good ones.
   */
  int tb = 0, lr = 0;
  for (int i = 0; i < brokenswords; i++) {
    fgets(inputline, 10, stdin);
    if (inputline[0] == '0')
      tb++;
    if (inputline[1] == '0')
      tb++;
    if (inputline[2] == '0')
      lr++;
    if (inputline[3] == '0')
      lr++;
  }

  /* Data gathered so far
   *    - total good top/bottom slats as tb
   *    - total good left/right slats as lr
   *
   * The number of swords that can be made is calculated by finding the minimum
   * of (tb, lr), then dividing by 2 Following that calculation the remaining
   * slats can be calculated.  Note that the remaining slats of the minimum
   * (tb or lr) can only be 0 or 1
   *
   * This code could be modified by moving the remaining calculations outside of
   * the if statement, but they are included in each choice for the if statement
   * simply to show that the calculation is the same.
   */
  int numnewswords = 0, tbremaining = 0, lrremaining = 0;
  if (tb < lr) {
    numnewswords = tb / 2;
    tbremaining = tb % (numnewswords * 2);
    lrremaining = lr % (numnewswords * 2);
  } else {
    numnewswords = lr / 2;
    tbremaining = tb % (numnewswords * 2);
    lrremaining = lr % (numnewswords * 2);
  }
  printf("%d %d %d\n", numnewswords, tbremaining, lrremaining);
  return 0;
}