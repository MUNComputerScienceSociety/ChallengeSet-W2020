#include <math.h>
#include <stdio.h>

/* More than one solution for this, depending on the complexity of the
 * calculation.  For complex calculations and the criteria that k, the number
 * of stops is less than 30, it is possible to pre-calculate all answers.
 * Then store the answers, for lookup when needed.
 *
 * Doing that using busrecursion.c, the sequence looked familiar. A few
 * moments on the gargler pointed me to Pascal's triangle, which lead
 * to the specification presented in the URL.  This solves the problem in
 * O(1) time.  Also can be noted once the pattern is figured out, that the
 * solution is the maximum number of bits that can be represented by the input.
 */
/* http://oeis.org/A000225 */

int main() {
  int stops, testcases;
  scanf("%d", &testcases);
  for (int i = 0; i < testcases; i++) {
    scanf("%d", &stops);
    printf("%d\n", (int)pow(2, stops) - 1);
  }
}