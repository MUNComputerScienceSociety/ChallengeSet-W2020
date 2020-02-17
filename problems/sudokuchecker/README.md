# Sudoku Solution Validator

All submitted solutions will earn entries in a draw for 2 GitHub t-shirt vouchers.
Entries earned are based on the following criteria.

* 1 entry – correct solution
* 2 entries – In CS2004
* 3 entries – solution in C (no C++ except for // comment lines)
* 4 entries – multithreaded solution (that actually runs multiple threads
  concurrently)

E.g. A threaded solution written in C++ by a student not in CS2004
would receive 5 entries.  Or a non-threaded solution from a CS2004 student
would receive 6 entries.

Drawing will take place at the end of CS2004 class on February 26.

## Problem

A Sudoku puzzle uses a 9 × 9 grid in which each column and row, as well as each
of the nine 3 × 3 subgrids, must contain all of the digits 1 ⋯ 9. The table
presents an example of a valid Sudoku puzzle. This problem consists of designing
an application that determines whether the solution to a Sudoku puzzle is valid.

||||||||||
|---|---|---|---|---|---|---|---|---|
| 6 | 2 | 4 | 5 | 3 | 9 | 1 | 8 | 7 |
| 5 | 1 | 9 | 7 | 2 | 8 | 6 | 3 | 4 |
| 8 | 3 | 7 | 6 | 1 | 4 | 2 | 9 | 5 |
| 1 | 4 | 3 | 8 | 6 | 5 | 7 | 2 | 9 |
| 9 | 5 | 8 | 2 | 4 | 7 | 3 | 6 | 1 |
| 7 | 6 | 2 | 3 | 9 | 1 | 4 | 5 | 8 |
| 3 | 7 | 1 | 9 | 5 | 6 | 8 | 4 | 2 |
| 4 | 9 | 6 | 1 | 8 | 2 | 5 | 7 | 3 |
| 2 | 8 | 5 | 4 | 7 | 3 | 9 | 1 | 6 |

### Input

The completed puzzle, 9 numbers per line, 9 lines with one space between
numbers.

#### Sample Input

```
6 2 4 5 3 9 1 8 7
5 1 9 7 2 8 6 3 4
8 3 7 6 1 4 2 9 5
1 4 3 8 6 5 7 2 9
9 5 8 2 4 7 3 6 1
7 6 2 3 9 1 4 5 8
3 7 1 9 5 6 8 4 2
4 9 6 1 8 2 5 7 3
2 8 5 4 7 3 9 1 6
```

### Output

Output is one word, either valid or invalid indicating wheter the solution is
valid

#### Sample output

```
valid
```

## Multithreading

There are several different ways of multithreading this application. One
suggested strategy is to create threads that check the following criteria:

A thread to check that each column contains the digits 1 through 9 A thread to
check that each row contains the digits 1 through 9 Nine threads to check that
each of the 3 × 3 subgrids contains the digits 1 through 9 This would result in
a total of eleven separate threads for validating a Sudoku puzzle. However, you
are welcome to create even more threads for this problem. For example, rather
than creating one thread that checks all nine columns, you could create nine
separate threads and have each of them check one column.

### I. Passing Parameters to Each Thread

The parent thread will create the worker threads, passing each worker the
location that it must check in the Sudoku grid. This step will require passing
several parameters to each thread. The easiest approach is to create a data
structure using a struct. For example, a structure to pass the row and column
where a thread must begin validating would appear as follows:

```C
/* structure for passing data to threads */
typedef struct {
  int row;
  int column;
} parameters;
```

Both Pthreads and Windows programs will create worker threads using a strategy
similar to that shown below:

```C
parameters *data = (parameters *) malloc(sizeof(parameters));
data->row = 1;
data->column = 1;
/* Now create the thread passing it data as a parameter */
```

The data pointer will be passed to either the pthread create() (Pthreads)
function or the CreateThread() (Windows) function, which in turn will pass it as
a parameter to the function that is to run as a separate thread.

### II. Returning Results to the Parent Thread

Each worker thread is assigned the task of determining the validity of a
particular region of the Sudoku puzzle. Once a worker has performed this check,
it must pass its results back to the parent. One good way to handle this is to
create an array of integer values that is visible to each thread. The ith index
in this array corresponds to the ith worker thread. If a worker sets its
corresponding value to 1, it is indicating that its region of the Sudoku puzzle
is valid. A value of 0 indicates otherwise. When all worker threads have
completed, the parent thread checks each entry in the result array to determine
if the Sudoku puzzle is valid.
