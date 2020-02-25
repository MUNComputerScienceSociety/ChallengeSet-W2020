to compile program on a linux machine: gcc -pthread -o sudoku sudoku.c

to run with 3 test samples from the repository: ./sudoku ../test-samples/sudokuchecker/sample1.in

./sudoku ../test-samples/sudokuchecker/sample1.in
./sudoku ../test-samples/sudokuchecker/sample2.in
./sudoku ../test-samples/sudokuchecker/sample3.in

---

Entry count | Reason                 | Status
------------|------------------------|--------
1 entry     | Correct solution       | ✅
2 entries   | In CS2004              | ❌
3 entries   | Solution in C          | ✅
4 entries   | Multithreaded solution | ✅

Total: 1 + 3 + 4 = _8 entries_
