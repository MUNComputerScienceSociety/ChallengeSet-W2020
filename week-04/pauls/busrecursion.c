#include <stdio.h>

/* To calculate the number of passengers reverse the operation of passengers
 * leaving the bus.  So add 1/2 passenger and double the number
 *
 * To make it interesting, perform the action recursively, adding
 * passengers at each stop except the last.
 */

int busstop(float passengers, int stopsremaining) {
  if (stopsremaining > 0) {
    return busstop((passengers + 0.5) * 2, stopsremaining - 1);
  } else {
    return passengers;
  }
}

int main() {
  float passengers = 0;
  int stops, testcases;
  scanf("%d", &testcases);
  for (int i = 0; i < testcases; i++) {
    scanf("%d", &stops);
    printf("%d\n", busstop(passengers, stops));
  }
}