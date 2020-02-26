#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 9

int grid[LEN * LEN];

void parse_inp(void);
void print_grid(void);
int is_valid(void);
int valid_square(int start);
int valid_col(int start);
int valid_row(int start);

int main(void) {
  parse_inp();
  // print_grid();

  if (is_valid() == 1) {
    printf("valid\n");
  } else {
    printf("invalid\n");
  }

  return 0;
}

int is_valid() {
  for (int i = 0; i < LEN / 3; i++) {
    for (int j = 0; j < LEN / 3; j++) {
      if (valid_square((i * (LEN * 3)) + j * 3) == -1) {
        return -1;
      };
    }
  }

  for (int i = 0; i < LEN; i++) {
    if (valid_col(i) == -1 || valid_row(i * LEN) == -1)
      return -1;
  }

  return 1;
}

int valid_square(int start) {
  int seen[LEN] = {0};

  for (int i = 0; i < LEN; i++) {
    if (seen[grid[start] - 1] == 1)
      return -1;

    if ((start + 1) % 3 == 0) {
      start += 7;
    } else {
      start += 1;
    }
  }

  return 1;
}

int valid_col(int start) {
  int seen[LEN] = {0};

  for (int i = 0; i < LEN; i++) {
    if (seen[grid[start] - 1] == 1)
      return -1;

    seen[grid[start] - 1] = 1;
    start += LEN;
  }

  return 1;
}

int valid_row(int start) {
  int seen[LEN] = {0};

  for (int i = 0; i < LEN; i++) {
    if (seen[grid[start] - 1] == 1)
      return -1;

    seen[grid[start] - 1] = 1;
    start += 1;
  }

  return 1;
}

void print_grid(void) {
  int grid_pos = 0;
  for (int i = 0; i <= LEN; i++) {
    if (i % 3 == 0) {
      for (int x = 0; x < ((LEN * 2) + (LEN / 3) * 2) + 1; x++)
        printf("-");
      printf("\n");
    }

    if (i == LEN)
      continue;

    for (int j = 0; j < LEN; j++) {
      if (j % 3 == 0)
        printf("| ");

      printf("%d ", grid[grid_pos++]);
    }
    printf("|\n");
  }
}

void parse_inp(void) {
  int grid_pos = 0;

  for (int i = 0; i < LEN; i++) {
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin);

    int i = 0;
    char *p = strtok(line, " ");
    char *array[LEN];

    while (p != NULL) {
      array[i++] = p;
      p = strtok(NULL, " ");
    }

    for (i = 0; i < LEN; ++i)
      grid[grid_pos++] = atoi(array[i]);

    free(line);
  }
}
