#!/usr/bin/env sh

process_cases() {
    for case in $( find ./test-data/*.in )
    do
        cat "$case" | python 10mins.py
    done
}

time process_cases
