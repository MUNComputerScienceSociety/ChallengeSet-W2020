/* Solution to iBoard problem on Kattis
 * https://open.kattis.com/problems/iboard
 * https://github.com/MemorialU/ChallengeSet-W2020/tree/master/week-04/pauls
 */
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"
#define BUFFERSIZE 100

int main(int argc, char *argv[]) {

  /* Test log.c from
   * https://github.com/rxi/log.c
   * Functions starting with log_ are appropriate.
   * Comment:  Not as neat as the log level being a parameter to the function
   * call.
   */
  if (strcmp(argv[1], "-vvv") == 0)
    log_set_level(LOG_TRACE);
  else if (strcmp(argv[1], "-vv") == 0)
    log_set_level(LOG_DEBUG);
  else if (strcmp(argv[1], "-v") == 0)
    log_set_level(LOG_WARN);
  else
    log_set_level(LOG_INFO);

  char line[100];

  while (fgets(line, BUFFERSIZE, stdin)) {
    /* get rid of pesky new line indicators that fgets leaves in */
    line[strcspn(line, "\n\r")] = '\0';

    log_debug("Got line ---%s---", line);
    log_debug("Got %lu characters\n", strlen(line));
    log_trace("%s", line);

    /* Start the keys as "released", defined as true */
    bool keys[2] = {true, true};
    /* iterate through the string by character */
    for (char *i = line; *i != '\0'; i++) {

      /* Dereference the character and make a copy that can be maniupulated.
       * Not strictly necessary as we can destroy the character as they are
       * not required for further output, BUT writing *i everywhere isn't
       * as clean to read as a tmp */
      char tmp = *i;

      log_trace("%c", tmp);

      /* Now iterate through the bits of the character */
      for (int j = 0; j < 8; j++) {
        /* Logical AND, keeping only the least significant bit */
        bool mykey = tmp & 1;
        log_trace("%i", mykey);
        /* Flip the state of the appropriate key as per the problem description
         */
        if (mykey) {
          log_trace("Key 0 transition");
          keys[0] = !keys[0];
        } else {
          log_trace("Key 1 transition");
          keys[1] = !keys[1];
        }
        /* Shift the bits to the right, dropping the least significant.  The
         * most significant can be 1 or 0, depending on what it was originally.
         * This isn't an issue for this problem, because those bits are never
         * used. */
        tmp = tmp >> 1;
      }
    }

    /* Final output, if both keys are released (true) then we are FREE!!! */
    if (keys[0] & keys[1])
      printf("free\n");
    else
      printf("trapped\n");
  }
  return 0;
}