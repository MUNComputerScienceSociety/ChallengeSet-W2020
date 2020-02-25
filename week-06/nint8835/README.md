# Running instructions

* Ensure you have [Go](https://golang.org/) 1.13 or greater installed
* Run the following command from within this directory to test:
  * `cat <PATH TO SAMPLE INPUT> | go run sudoku.go`
* Alternatively, to build a binary and run that:
  * ```sh
    go build sudoku.go
    cat <PATH TO SAMPLE INPUT> | ./sudoku
    ```
* Alternatively to install the command to be available anywhere:
  * Ensure your go bin directory (`$HOME/go/bin`) is in your path
  * ```
    go install sudoku.go
    cat <PATH TO SAMPLE INPUT> | sudoku
    ```

# Entries

Entry count | Reason                 | Status | Additional description
------------|------------------------|--------|-----------------------
1 entry     | Correct solution       | ✅     |
2 entries   | In CS2004              | ❓     | Jack: _Paul mentioned in class Riley still might be permitted to get this entry_
3 entries   | Solution in C          | ❌     |
4 entries   | Multithreaded solution | ❓     | Unsure about this one. The solution was implemented using [goroutines](https://tour.golang.org/concurrency/1), which according to the Go developers are "a lightweight thread managed by the Go runtime". However, many people online argue that as the thread is managed by the Go runtime it's not a real thread.
