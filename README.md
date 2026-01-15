
*This project has been created as part of the 42 curriculum by sla-gran.*

# push_swap

## Description

`push_swap` is a sorting algorithm project.
The objective is to sort a list of integers in ascending order using **two stacks** and a **restricted set of operations**, while generating the **smallest possible number of moves**.

The program takes a list of integers as arguments, places them in **stack A**, and outputs a sequence of instructions that will sort the stack. A second stack, **stack B**, is available as auxiliary storage.

This project focuses on algorithmic efficiency, optimization, and a deep understanding of data manipulation under strict constraints.

---

## Instructions

### Compilation

Clone the repository and compile the project using `make`:

```bash
git clone https://github.com/zaimon95/push_swap
cd push_swap
make
```

This will generate the `push_swap` executable.

### Execution

Run the program with a list of integers as arguments:

```bash
./push_swap 3 2 1
```

The program outputs a list of operations (one per line) that will sort the numbers.

### Valid Input Rules

* Arguments must be valid integers
* No duplicate numbers are allowed
* Numbers must fit within the range of a 32-bit signed integer
* If the input is already sorted, the program outputs nothing

---

## Algorithm Overview

This implementation uses:

* Indexing (value normalization)
* Chunk-based pushing from stack A to stack B
* Cost calculation to determine the cheapest move
* Optimized reinsertion from stack B back to stack A

Specialized strategies are used for small inputs:

* 2–3 numbers: minimal swaps and rotations
* 4–5 numbers: push smallest values to B, sort A, reinsert

---

## Performance Targets

| Numbers | Maximum Operations |
| ------: | -----------------: |
|       3 |                ≤ 3 |
|       5 |               ≤ 12 |
|     100 |              ≤ 700 |
|     500 |             ≤ 5500 |

---

## Resources

### Technical References

* **42 push_swap subject** — Official project specification provided by 42 School
* **Sorting algorithms overview**: [https://en.wikipedia.org/wiki/Sorting_algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
* **Stack data structure**: [https://en.wikipedia.org/wiki/Stack_(abstract_data_type)](https://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29)
* **Big-O notation**: [https://en.wikipedia.org/wiki/Big_O_notation](https://en.wikipedia.org/wiki/Big_O_notation)
* **Radix sort** (commonly adapted for push_swap): [https://en.wikipedia.org/wiki/Radix_sort](https://en.wikipedia.org/wiki/Radix_sort)

These resources were used to understand algorithmic complexity, stack manipulation, and sorting strategies applicable under constrained operations.

### AI Usage Disclosure

AI tools were used strictly as **learning and documentation aids**, not as a source of ready-made solutions.

Specifically, AI assistance was used for:

* Clarifying algorithmic concepts (chunking strategies, move optimization)
* Reviewing and improving README documentation clarity
* Helping reason about edge cases and constraints

All algorithm design, code implementation, debugging, and testing were performed independently by the project author(s), in compliance with 42 rules.

---

## Notes

`push_swap` is less about sorting itself and more about understanding how constraints reshape problem-solving. The project rewards thoughtful tradeoffs between simplicity, performance, and elegance.
