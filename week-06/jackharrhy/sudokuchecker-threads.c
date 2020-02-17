#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 9

int grid[LEN * LEN];

void parse_inp(void);
void print_grid(void);
int is_valid(void);

void *valid_square(void *ptr);
void *valid_col(void *ptr);
void *valid_row(void *ptr);

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
  int cur_thread = 0;
  pthread_t threads[LEN * 3];

  for (int i = 0; i < LEN / 3; i++) {
    for (int j = 0; j < LEN / 3; j++) {
      pthread_create(&threads[cur_thread], NULL, valid_square, (void *)((i * (LEN * 3)) + j * 3));
      cur_thread += 1;
    }
  }

  for (int i = 0; i < LEN; i++) {
    pthread_create(&threads[cur_thread], NULL, valid_col, (void *)i);
    cur_thread += 1;
    pthread_create(&threads[cur_thread], NULL, valid_row, (void *)(i * LEN));
    cur_thread += 1;
  }

  for (int i = 0; i < LEN * 3; i++)
    pthread_join(threads[i], NULL);

  return 1;
}

void *valid_square(void *ptr) {
  int start = *(int *)ptr;
  int seen[LEN] = {0};

  for (int i = 0; i < LEN; i++) {
    if (seen[grid[start] - 1] == 1)
      pthread_exit((void* )-1);

    if ((start + 1) % 3 == 0) {
      start += 7;
    } else {
      start += 1;
    }
  }

  pthread_exit((void* )1);
}

void *valid_col(void *ptr) {
  int start = *(int *)ptr;
  int seen[LEN] = {0};

  for (int i = 0; i < LEN; i++) {
    if (seen[grid[start] - 1] == 1)
      pthread_exit((void* )-1);

    seen[grid[start] - 1] = 1;
    start += LEN;
  }

  pthread_exit((void* )1);
}

void *valid_row(void *ptr) {
  int start = *(int *)ptr;
  int seen[LEN] = {0};

  for (int i = 0; i < LEN; i++) {
    if (seen[grid[start] - 1] == 1)
      pthread_exit((void* )-1);

    seen[grid[start] - 1] = 1;
    start += 1;
  }

  pthread_exit((void* )1);
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
