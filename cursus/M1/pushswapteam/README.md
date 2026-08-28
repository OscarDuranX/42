*This project has been created as part of the 42 curriculum by oduran-m and sayala-c.*

## Description 

The core of the project is to sort a stack with the minimum number of operations. The logic follows a multi-strategy flow depending on the input size and the flags used:

1. **Parsing:** The program analyzes the input arguments to verify they are valid integers, within limits, and contains no duplicates.
2. **Stack Creation:** Once validated, Stack A is initialized with the provided arguments.
3. **Disorder Index Calculation:** The program calculates a **Global Disorder Index** (a decimal value) for the entire stack. This metric represents the current state of "unsortedness," helping the program assess the complexity of the input.
4. **Node Indexing (Coordinate Compression):** Each node is assigned a unique **index** (from 0 to N-1) based on its value relative to the others. This normalization allows the algorithms to work independently of the raw values, handling negative numbers and gaps seamlessly.
5. **Dispatching:** Based on the **number of arguments** and the **Disorder Index**, the program automatically selects the most efficient algorithm, unless overridden by a flag.

### Algorithms

* **Simple algorithm:** for a disorder index smaller than 0.20% or up to 5 arguments in the stack
    * `Hardcoded Logic`: for 2 to 5 numbers.
    * `Selection Sort:` for small sets, identifying the minimum element and pushing it to Stack B. This is preferred over Bubble Sort as it drastically reduces the number of operations by performing only one "push" per element instead of constant adjacent swaps.
* **Medium algorithm:** for a disorder index equal or higher than 0.20% and smaller than 0.50%.
    * `Chunks Algorithm`: For medium sets, dividing the stack into value blocks to reduce rotation costs.
* **Complex algorithm:**  for a disorder index equal or higher than 0.50%.
    * `Radix Sort`: for large sets, sorting bit by bit based on the node indices.
* **Adaptive algorith:** it automatically selects an algorithm based on the number of arguments introduced and the disorder index mentioned before.

## Operations for the algorithms

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

### Custom Flags

We have implemented system of flags run and test different strategies:
* `--bench`: displays the disorder index (% with two decimal places), the name of the strategy used and its theoretical complexity class, the total number of operations used and the number of operations of each type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr) used during the sorting process.
* `--adaptive`: Automatically detects the stack size and chooses the best algorithm (Small, Selection, Chunks, or Radix).
* `--simple`: forces the use of the **Hardcoded Logic** and **Selection Sort** algorihm.
* `--medium`: forces the use of the **Chunks-based** algorithm.
* `--complex`: forces the use of the **Radix Sort** algorithm.

### Instructions

**1. Compiling the program**

To compile the program, run:

```shell
$ cd path/to/push_swap && make
```

To compile the checker, run:

```shell
$ cd path/to/push_swap && make bonus
```

**2. How to run the program**

Run the executable together with the set of numbers separated by a space:
```shell
./push_swap 5 7 10 4 6 8 9 2 1 3
```

To run the checker on push_swap, use the pipe:
```shell
ARG="5 7 10 4 6 8 9 2 1 3"; ./push_swap $ARG | ./checker $ARG
```

Use `clean` to delete all object files, `fclean` to remove executable and all object files, and `re` to recompile the program:
```shell
make clean / make fclean / make re
```

## Resourses
* 42 cursus guide
* YouTube tutorials

### AI Usage
For this project AI has been used as a guide to understand concepts and logic and find errors. No code generation was used.
