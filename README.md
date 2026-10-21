_This activity has been created as part of the 42 curriculum by mohal-al, lnafa._

# push_swap

## Description

`push_swap` is a C project that sorts a list of unique integers using two stacks (`a` and `b`) and a limited set of stack operations. The goal is to print a sequence of operations that leaves stack `a` sorted in ascending order, with the smallest value at the top, while keeping the number of operations as low as reasonably possible.

## How the Program Works

The program follows these main steps:

1. **Read command-line arguments:** The program checks the arguments for strategy flags and the optional benchmark flag. Flags may appear before, between, or after integer arguments.
2. **Parse the integers:** Integer arguments can be supplied separately or as a quoted, space-separated list. Each token is checked to ensure it is a valid integer within the C `int` range.
3. **Validate the input:** The program rejects invalid tokens, out-of-range values, duplicate integers, unknown flags, and repeated strategy or benchmark flags. On invalid input, it prints `Error` followed by a newline to standard error.
4. **Build stack A:** Valid integers are stored in stack `a` in argument order. Stack `b` starts empty. The first integer supplied is the top of stack `a`.
5. **Choose a sorting strategy:** An explicitly supplied strategy is used. If no strategy selector is provided, the default is `--adaptive`.
6. **Measure disorder:** The adaptive strategy measures how far the initial stack is from ascending order before performing any operations.
7. **Generate stack operations:** The selected algorithm manipulates the stacks using the allowed operations.
8. **Print the operations:** Each operation is printed to standard output on its own line. If `--bench` is enabled, benchmark information is printed to standard error.
9. **Finish sorting:** The generated operations should leave stack `a` sorted in ascending order, with the smallest number at the top, and stack `b` empty.

## Stack Operations

| Operation | Meaning                                                |
| --------- | ------------------------------------------------------ |
| `sa`      | Swap the top two values of stack `a`.                  |
| `sb`      | Swap the top two values of stack `b`.                  |
| `ss`      | Perform `sa` and `sb` together.                        |
| `pa`      | Push the top value of `b` onto `a`.                    |
| `pb`      | Push the top value of `a` onto `b`.                    |
| `ra`      | Rotate `a` upward: its top value moves to the bottom.  |
| `rb`      | Rotate `b` upward: its top value moves to the bottom.  |
| `rr`      | Perform `ra` and `rb` together.                        |
| `rra`     | Reverse-rotate `a`: its bottom value moves to the top. |
| `rrb`     | Reverse-rotate `b`: its bottom value moves to the top. |
| `rrr`     | Perform `rra` and `rrb` together.                      |

## Sorting Strategies and Algorithm Choices

The program includes four strategy modes: simple, medium, complex, and adaptive. The complexity classes described below refer to the number of Push_swap operations generated, as required by the project subject.

### 1. Simple Strategy — Selection Sort Adaptation

**Target complexity: O(n²)**

The simple strategy repeatedly identifies the smallest remaining value and moves it into its correct position using stack operations.

Selection sort is straightforward and provides a useful baseline. However, the number of operations can grow quadratically as the input becomes larger, making it more suitable for small inputs or inputs with low disorder.

### 2. Medium Strategy — Chunk Sort

**Target complexity: O(n√n)**

The medium strategy divides the values into ranges called chunks. Values belonging to a chunk are moved from stack `a` to stack `b` in a planned order. The algorithm then brings values back to stack `a` in sorted order.

Chunking reduces the need to locate and move every value independently across the entire stack. It provides a middle ground between the simple and complex strategies.

### 3. Complex Strategy — Radix Sort

**Target complexity: O(n log n)**

The complex strategy uses an adaptation of radix sort. Values are represented by ranks or non-negative indices so their bit patterns can be processed.

For each bit position, the algorithm distributes values between the stacks according to whether that bit is set, then collects them back. Repeating this process for the required bit positions sorts the values.

Rank-based binary radix sorting is suitable for larger inputs and can achieve O(n log n) Push_swap operations when implemented using this approach.

### 4. Adaptive Strategy — Disorder-Based Selection

The adaptive strategy measures the disorder of the initial stack before performing any operations. It then selects a sorting strategy according to the disorder value.

Disorder is calculated as:

`disorder = inverted_pairs / total_pairs`

An inverted pair occurs when a larger value appears before a smaller value. Disorder ranges from `0` (already sorted) to `1` (reverse-sorted).

The adaptive strategy uses the following thresholds:

- **Low disorder:** `disorder < 0.2` — select the simple strategy.
- **Medium disorder:** `0.2 <= disorder < 0.5` — select the medium strategy.
- **High disorder:** `disorder >= 0.5` — select the complex strategy.

These thresholds allow the program to choose a strategy according to how ordered the input already is. The disorder must be measured before any stack operations are performed. The implementation should also handle inputs with fewer than two values without dividing by zero.

## Instructions

Compile the project from the root of the repository using the Makefile:

```sh
make
```

This should compile the project and create the `push_swap` executable.

The Makefile must provide the following targets: (*stack_a)

```sh
make        # Compile the program
make all    # Compile the program
make clean  # Remove object files
make fclean # Remove object files and the executable
make re     # Clean and rebuild
```

The project is expected to compile using `cc` with the req (*stack_a)uired warning flags:

```sh
-Wall -Wextra -Werror
```

## Usage

General syntax: (*stack_a)

```sh
./push_swap [strategy flag] [--bench] integer [integer ...]
```

You can provide integers separately:

```sh
./push_swap 4 67 3 87 23
```
 (*stack_a)
Or provide several integers in one quoted argument:

```sh
./push_swap "4 67 3 87 23"
```

The first integer supplied becomes the top of stack `a`.

### Strategy Flags
 (*stack_a)
| Flag         | Behavior                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------- |
| `--simple`   | Force the simple selection-sort adaptation.                                                                 |
| `--medium`   | Force the medium chunk-sort strategy.                                                                       |
| `--complex`  | Force the complex radix-sort strategy.                                                                      |
| `--adaptive` | Select a strategy based on the initial disorder. This is the default when no strategy selector is supplied. |

Only **one strategy selector** may be provided in a command. Supplying more than one strategy flag is treated as invalid input.

### Benchmark Flag

The `--bench` flag enables benchmark reporting. It may appear before, between, or after the integer arguments and can be combined with one strategy selector.

The `--bench` flag may be provided at most once.

Benchmark information is written to **standard error**, keeping the Push_swap operation stream on **standard output**.

The benchmark report must include:

- Initial disorder as a percentage with two decimal places.
- The strategy used and its theoretical complexity class.
- The total number of operations.
- A count for each operation type: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

### Usage Examples

Use the default adaptive strategy:

```sh
./push_swap 4 67 3 87 23
``` (*stack_a)

Force the simple strategy:

```sh
./push_swap --simple 5 4 3 2 1
```

Place the strategy flag between integer arguments:

```sh
./push_swap 5 4 --medium 3 2 1
```

Force the complex strategy:

```sh
./push_swap 4 67 3 87 23 --complex
```

Enable benchmark reporting:
 (*stack_a)
```sh
./push_swap --bench 4 67 3 87 23
```

Combine the benchmark flag with a strategy flag:

```sh
./push_swap 4 67 --bench 3 87 23 --adaptive
```

Use a quoted list of integers:

```sh
./push_swap "4 67 3 87 23"
```

## Input Validation and Output Behavior

- With no command-line arguments, the program should produce no output.
- Inputs must be valid decimal integers within the C `int` range.
- Duplicate values are invalid.
- Unknown flags are invalid.
- More than one strategy selector is invalid.
- More than one `--bench` flag is invalid.
- Flags can appear before, between, or after the integer arguments.
- On invalid input, the program prints `Error` followed by a newline to standard error.
- Sorting operations are printed one per line to standard output, with no extra text mixed into the operation stream.
- Benchmark details appear only when `--bench` is supplied and are written to standard error.

## Testing and Performance

Use the provided checker, if available, to verify that the operation sequence sorts the input correctly:

```sh
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

To count the generated operations:

```sh
./push_swap 4 67 3 87 23 | wc -l
```

To save benchmark output separately from the operations:

```sh
./push_swap --bench 4 67 3 87 23 2> bench.txt
cat bench.txt
```

The project subject provides the following performance targets for random inputs:

| Input size  |      Minimum passing target | Good performance | Excellent performance |
| ----------- | --------------------------: | ---------------: | --------------------: |
| 100 numbers |  Fewer than 2000 operations |  Fewer than 1500 |        Fewer than 700 |
| 500 numbers | Fewer than 12000 operations |  Fewer than 8000 |       Fewer than 5500 |

These are evaluation targets, not a guarantee that every strategy or input will meet each level. Test each strategy with already-sorted, reverse-sorted, random, and invalid inputs.

## Contributors and Collaboration

This project was completed by **mohal-al** and **lnafa**.

### lnafa

- Implemented argument parsing.
- Stored the input numbers in the stack.
- Implemented strategy selection based on the input flag.
- Took primary responsibility for the Radix Sort strategy.

### mohal-al

- Implemented the operations.
- Implemented disorder calculation.
- Took primary responsibility for the Selection Sort and Chunk Sort strategies.

### Joint Contributions

- Collaborated on implementing and refining the Selection Sort, Chunk Sort, and Radix Sort strategies.
- Worked together on implementing the benchmark functionality.

## Resources

- The official Push_swap project subject provided for this activity.
- The C language documentation for integer ranges, memory allocation, and input/output.
- The project’s Libft implementation and its associated documentation and tests, where applicable.
- The provided Push_swap checker and project evaluation instructions, where available.
- Algorithm references for selection sort, chunk-based sorting, radix sort, and algorithmic complexity.

## AI Usage

AI tools were used as a supporting resource during development to clarify algorithmic concepts, review implementation approaches, and assist with debugging when needed.
