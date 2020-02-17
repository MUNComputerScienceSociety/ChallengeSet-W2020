/**
 * Solution to Unlock Pattern on kattis
 * https://open.kattis.com/problems/unlockpattern
 * https://github.com/MemorialU/ChallengeSet-W2020/tree/master/week-05/pauls
 *
 * One approach to the problem ...
 * The problem description puts the numbers in a 3x3 grid, and only uses numbers
 * from 1 to 9.  This can be reimagined as a telephone or calculator keyboard.
 * The provided input, then indicates the order that the keys will be accessed
 * in.  It can be thought of as a 9 digit pin, with no repeated digits.  The
 * output required is the distance travelled by a finger moving along the pin.
 * The vertical and horizontal distance between grid squares is 1.
 *
 * This solution, records the x and y coordinates of each number.  The distance
 * moved, is then the distance from 1 to 2 + distance from 2 to 3 etc.
 *
 * Knowing the x and y values, one approach would be to see if the move is
 * horizontal or vertical, then use simple addition/subtraction to get those
 * distances. An isocoles triangle would then have square root of 2 as the
 * distance, and the only other value needed would be square root of 5 if one
 * axis has a distance of 2.  The benefit of this strategy would be for low
 * powered computers, such as micro controlers.  Comparisons and
 * addition/subtraction are generally much faster than exponential floating
 * point operations (some micro controlers have no floating point ALU and would
 * need a large number of operations for square root).  But that was not the
 * approach taken.
 *
 * The approach taken here was to sum the lengths of the vectors (edges on a
 * graph) between all the points.  The length of a vector in a plane is nothing
 * more than good old pythagoras theorem with some absolute values thrown in.
 * The absolute values allow only being concerned with the magnitude of the
 * vector and not the direction.
 *
 * A benefit of this approach is a consistent known time for the calculation.
 * This could be a factor in real time operating systems (RTOS) and
 * microcontrollers
 *
 *
 */
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 15

typedef struct point {
  int x;
  int y;
} point;

int main() {
  /* This array is where we store the coordinates for each number in order.  It
   * does not fill from 0-8, but rather fills based on the input sequence */
  point pattern[9];

  char line[BUFFERSIZE];
  char *tok;

  for (int x = 0; x < 3; x++) {
    fgets(line, BUFFERSIZE, stdin);

    /* line will be modified by strtok, so if it was needed for other operations
     * a copy would have to be kept */
    tok = strtok(line, " ");

    int y = 0;
    /* Could count to 3 here just like the outer loop, but why not use the
     * classical string tokenizer format */
    while (tok != NULL) {
      /* Probably should error check this but hey, it's a programming challenge
       * problem */
      int tmp = atoi(tok) - 1;

      pattern[tmp].x = x;
      pattern[tmp].y = y;

      /* Move to next token, DON'T pass the line string, to move along a char*
       * array and pull out tokens, only the first call should have the string
       * address (char*), subsequent calls use NULL.  But the separator
       * characters must be included every time. */
      tok = strtok(NULL, " ");

      y++;
    }
  }

  /* So much time in C goes to dealing with strings (same as every language
   * really).  The computation of the length is quite simple.  Iterate over each
   * edge adding on the distance as we go. */
  double sum = 0;
  for (int i = 0; i < 8; i++) {
    sum = sum + sqrtl(pow(abs(pattern[i].x - pattern[i + 1].x), 2) +
                      pow(abs(pattern[i].y - pattern[i + 1].y), 2));
  }
  /* Learned something new for this.  float.h has a number of macros.  The macro
   * in the print statement allows for maximum precision output. It is used for
   * the '.*' to control the number of digits after the decimal.  Using 'g'
   * instead of 'f' in the printf format will trim trailing zeros from the
   * output */
  printf("%.*g\n", DBL_DECIMAL_DIG, sum);
}
