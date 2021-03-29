#### 2021 spring Algorithm 
# HW1: Randomized-select & Deterministic-select

## 제공해주신 Makefile 및 skeleton code를 사용함.

## 1. How to compile
Run `$ make` command to compile source code in this directory.


## 2. How to run
1. run with whole input files
    - Run `$ make run` command

1. If you want to run with just one input file,
    ```
    $ make
    $ ./program ./input/<filename>
    ```
    for example, if the file name is "100.in",
    ```
    $ make
    $ ./program ./input/100.in
    ```
2. If you want to add extra input files, modify "Makefile".
    1. open Makefile
    1. add `./$(TARGET) input/<filename>`
