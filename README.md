*This project has been created as part of the 42 curriculum by sla-gran.*

# push_swap

## Description

`push_swap` is a sorting algorithm project that challenges you to sort a stack of integers using only two stacks and a limited set of operations, while minimizing the number of moves.

The program takes a list of integers as arguments, places them in **stack A**, and outputs a sequence of instructions that will sort the stack in ascending order. A second stack, **stack B**, is available as auxiliary storage.

This project emphasizes algorithmic efficiency, optimization techniques, and understanding of data structure manipulation under strict constraints.

---

## Instructions

### Compilation

Clone the repository and compile the project using `make`:
```bash
git clone https://github.com/zaimon95/push_swap.git
cd push_swap
make
```

This will generate the `push_swap` executable.

### Execution

Run the program with a list of integers as arguments:
```bash
./push_swap 3 2 1
```

Or pass them as a single string:
```bash
./push_swap "5 4 3 2 1"
```

The program outputs a list of operations (one per line) that will sort the numbers.

### Valid Input Rules

* Arguments must be valid integers
* No duplicate numbers are allowed
* Numbers must fit within the range of a 32-bit signed integer (`-2147483648` to `2147483647`)
* If the input is already sorted, the program outputs nothing
* Invalid input displays `Error` on stderr and exits with status 1

---

## Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements of stack A |
| `sb` | Swap the first 2 elements of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top element from B to A |
| `pb` | Push the top element from A to B |
| `ra` | Rotate stack A up (first element becomes last) |
| `rb` | Rotate stack B up |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B |
| `rrr` | `rra` and `rrb` at the same time |

---

## Algorithm Overview

This implementation uses a hybrid approach combining specialized strategies for different input sizes:

### Small Stacks (2-5 elements)
- **2 elements**: Single swap if needed
- **3 elements**: Hardcoded optimal solution (maximum 2 operations)
- **4-5 elements**: Push minimum values to stack B, sort remaining elements, then push back

### Large Stacks (6+ elements)
- **Radix Sort**: Binary digit-based sorting algorithm
  - Assigns simplified indices to each value (0 to n-1)
  - Sorts by examining each bit position from least to most significant
  - Pushes numbers with 0 in current bit position to stack B
  - Rotates numbers with 1 in current bit position
  - Pushes everything back from B to A
  - Repeats for each bit until fully sorted

### Key Optimizations
- Index normalization: Values are mapped to indices (0 to n-1) for efficient bit manipulation
- Minimal comparisons: Radix sort eliminates the need for value comparisons
- Predictable performance: O(n × k) where k is the number of bits needed

---

## Performance Targets

The implementation meets and often exceeds the 42 evaluation requirements:

| Numbers | Target Operations | Typical Performance |
| ------: | ----------------: | ------------------: |
|       3 |               ≤ 3 |                 ≤ 3 |
|       5 |              ≤ 12 |               ≤ 12 |
|     100 |             ≤ 1100 |           1000-1100 |
|     500 |            ≤ 8500 |        6500-8500 |

---

## Project Structure
```
push_swap/
├── src/
│   ├── main.c              # Entry point and main logic
│   ├── parsing.c           # Argument validation and parsing
│   ├── operations.c        # Stack operations (sa, sb, ss, pa, pb)
│   ├── rotate.c            # Rotation operations (ra, rb, rr)
│   ├── reverse_rotate.c    # Reverse rotation operations (rra, rrb, rrr)
│   ├── simple_sort.c       # Sorting for small stacks (2-5 elements)
│   ├── radix.c             # Radix sort for large stacks
│   ├── index.c             # Index assignment for values
│   ├── utils.c             # Utility functions (error, free, is_sorted)
│   └── push_swap.h         # Header file with prototypes
├── libft/                  # Custom C library (ft_printf, ft_split, etc.)
├── Makefile                # Compilation rules
└── README.md               # This file
```

---

## Testing

### Manual Testing
```bash
# Test with 3 numbers
./push_swap 2 1 3

# Test with 5 numbers
./push_swap 5 4 3 2 1

# Test with 100 random numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with 500 random numbers
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

### Error Handling Tests
```bash
# Duplicate numbers
./push_swap 1 2 3 2    # Error

# Non-numeric input
./push_swap 1 2 abc    # Error

# Number out of range
./push_swap 2147483648 # Error

# Empty string
./push_swap ""         # Error
```

## Implementation Details

### Memory Management
- All allocated memory is properly freed
- No memory leaks (tested with valgrind)
- Stack structures use linked lists for dynamic sizing

### Error Handling
- Comprehensive input validation
- Graceful error messages on stderr
- Proper exit codes (0 for success, 1 for error)

### Norminette Compliance
- All files respect the 42 norminette coding standard
- Maximum 25 lines per function
- Maximum 5 functions per file
- Maximum 80 characters per line

---

## Resources

### Technical References

* **42 push_swap subject** — Official project specification provided by 42 School
* **Radix Sort Algorithm** — [GeeksforGeeks](https://www.geeksforgeeks.org/radix-sort/)
* **Stack Data Structure** — Understanding LIFO operations and manipulations
* **Algorithm Complexity Analysis** — Big O notation and performance optimization

These resources were used to understand algorithmic complexity, stack manipulation techniques, and sorting strategies applicable under constrained operations.

### AI Usage Disclosure

AI tools were used strictly as **learning and documentation aids**, not as a source of ready-made solutions.

Specifically, AI assistance was used for:

* Clarifying algorithmic concepts (radix sort implementation, bit manipulation)
* Reviewing and improving code structure and organization
* Debugging complex edge cases in sorting logic
* Enhancing README documentation clarity and completeness
* Understanding norminette requirements and best practices

All core algorithm design, implementation decisions, optimization strategies, and debugging were performed independently by the project author, in full compliance with 42 academic integrity rules.

---

## Notes

`push_swap` is fundamentally about understanding constraints and making intelligent tradeoffs. The project teaches:

- **Algorithm selection**: Choosing the right approach based on input size
- **Optimization mindset**: Minimizing operations without sacrificing correctness
- **Data structure mastery**: Deep understanding of stack operations
- **Edge case handling**: Robust input validation and error management
- **Performance analysis**: Measuring and improving algorithmic efficiency

The beauty of this project lies not in sorting itself, but in discovering elegant solutions within strict limitations.

---

## License

This project is part of the 42 curriculum and follows the school's academic policies.

---

## Author

**sla-gran** - 42 Student

---
