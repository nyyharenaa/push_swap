*This project has been created as part of the 42 curriculum by todina-r, ny-handr*.

---

# push_swap

### Description

**push_swap** is an algorithmic project whose objective is to sort a list of integers using two stacks (`a` and `b`) and a restricted set of stack operations.

The program must generate the **smallest possible sequence of operations** that sorts the input numbers in ascending order inside stack `a`.

This project focuses on:

* Algorithm design and optimization
* Algorithmic complexity analysis (in terms of generated operations)
* Adaptive strategy selection based on input disorder
* Clean memory management and strict C coding standards (norme 42)

---

### Features

* Sorting using **four distinct strategies**

  * Simple strategy — `O(n²)`
  * Medium strategy — `O(n√n)`
  * Complex strategy — `O(n log n)`
  * Adaptive strategy — runtime selection based on disorder metric

* Benchmark mode providing:

  * Disorder percentage
  * Strategy used and complexity class
  * Total number of operations
  * Operation breakdown

* Robust error handling:

  * Non-integer arguments
  * Duplicate values
  * Integer overflow
  * Invalid flags

---

### Allowed Operations

* `sa` / `sb` / `ss` — swap
* `pa` / `pb` — push
* `ra` / `rb` / `rr` — rotate
* `rra` / `rrb` / `rrr` — reverse rotate

---

### Disorder Metric

Disorder measures how far the initial stack is from being sorted.

$$
disorder = inversionCount / pairCount
$$

Thresholds used in the adaptive strategy:

* `< 0.2` → Low disorder → `O(n²)` method
* `0.2 – 0.5` → Medium disorder → `O(n√n)` method
* `≥ 0.5` → High disorder → `O(n log n)` method

> Justification:
> 
> The `Max-extraction` strategy works very well with low disorder input.
> The `Bucket sort` strategy is stable and vesatil, work well for medium disorder input.
> High number of input tend to produce medium-to-high disorder, which is suitable for the `Radix sort` strategy.
> 

---

### Algorithms Implemented

#### 0. Normalization

* Principle: `make the value of each node contiguous (0, 1, 2, ..., size - 1)`
* Advantages: `allow to use bit-order-dependent algorithm`

---

#### 1. Simple Strategy — `O(n²)`

* Algorithm used: `Max extraction`
* Principle: `push the nodes in a to b, starting with the maximum`
* Advantages: `small input / low and high disorder metric`
* Limitations: `large inputs / disorder count around 0.5`

The algorithm loop, at most, through `n` node (optimized to `n / 2` when using `reverse rotate`) to find the maximum valued node before pushing it to `b`.
Repeating this action to each node in `a` and pushing every node in `b` to `a` lead to a `n²` complexity.

---

#### 2. Medium Strategy — `O(n√n)`

* Algorithm used: `Bucket sorting`
* Chunk size formula: `√n`
* Strategy flow:

  1. push every node with value below `√n`, then below `2√n`, ...
  2. apply the inverse of the Simple strategy on `b`

The algorithm divide the initial stack to `√n` bucket with `√n` capacity and perform a `m²` algorithm with each one of the `√n` chunck (`m = √n` => `(√n)² = n`) leading to `n` `√n` times (`n√n`).

---

#### 3. Complex Strategy — `O(n log n)`

* Algorithm used: `Radix sort`
* Bit / partition logic: `push to b every node with 0 in the specified bit, starting with the LSD`
* Why suitable for large inputs: `loop at most 32 times ( sizeof(int) * 8 ) through a`

  1. The algorithm check the bit of each node's value from `LSD` to `MSD` and push every node who have a bit`0` in the checked position, taking exactly `n` operation.
  2. When every node in `a` are checked, return every node in `b` to a, taking at most `n` operation.
  3. The process above are repeated at most `32` times.

As the value taken by this algorithm are between `-2147483648` and `2147483647`, who are represented at most by 32 bit. In the case when every possible value are given, we have `n = 2 * 2147483647`, equal to `4294967294` then we have `log 4294967294 = 32`. In sum, in the worst case scenario (n = `4294967294`), we perform `n` `push` or `rotate`, plus `n` `push` to `a`, and we repeat that process in `log 4294967294` times. We execute then `2n log n` operation, noted `O(n log n)`.

---

#### 4. Special case strategy

* Principle: `if the number of node are less than 3, we use a pre-conceved set of operation`
* Limitations: `work only for a very few input case`

---

#### 4. Adaptive Strategy

The program computes disorder and dynamically selects the most appropriate internal method.

| Disorder Range | Strategy Used | Complexity   |
| -------------- | ------------- | ------------ |
| `< 0.2`        | `Extraction`  | `O(n²)`      |
| `0.2–0.5`      | `Bucket sort` | `O(n√n)`     |
| `≥ 0.5`        | `Radix sort`  | `O(n log n)` |

---

### Project Structure

```bash
push_swap/
│
├── push_swap.h		# main header
├── *.h				# misc. header
│
├── main.c
├── ps_al_*.c		# algorithm
├── ps_op_*.c		# push_swap operation
├── ps_bench.c		# benchmark
├── ps_oplist.c		# result storage utility
├── ps_option.c		# program option utility
├── ps_parser.c		# program argument utility
├── ps_stack.c		# stack data-structure utility
├── ps_utils.c		# program utility
│
├── libft/			# general purpose library
│
├── Makefile
└── README.md
```

---

### Instructions

#### Compilation

```
make
```

Clean objects:

```
make clean
```

Full clean:

```
make fclean
```

Rebuild:

```
make re
```

---

### Usage

Basic execution:

```
./push_swap 2 1 3 6 5 8
```

Force a specific strategy:

```
./push_swap --simple <numbers>
./push_swap --medium <numbers>
./push_swap --complex <numbers>
./push_swap --adaptive <numbers>
```

Benchmark mode:

```
./push_swap --bench <numbers>
```

---

### Performance Targets

| Input Size | Pass        | Good       | Excellent  |
| ---------- | ----------- | ---------- | ---------- |
| 100        | < 2000 ops  | < 1500 ops | < 700 ops  |
| 500        | < 12000 ops | < 8000 ops | < 5500 ops |

---

### Error Handling

The program prints:

```
Error
```

on **stderr** when:

* Argument is not an integer
* Duplicate values or flags are present
* Integer overflow occurs
* Invalid flag is used

---

### Bonus — Checker

The `checker` program:

* Reads operations from **stdin**
* Executes them on the given stack
* Prints:

  * `OK` if sorted
  * `KO` if not sorted
  * `Error` if invalid command line argument

---

### Resources

* Algorithm complexity documentation: [wikipedia - sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
* Simple algorithm documentation: [wikipedia - selection sort](https://en.wikipedia.org/wiki/Selection_sort)
* Bucket sort documentation: [wikipedia - bucket sort](https://en.wikipedia.org/wiki/Bucket_sort)

#### AI Usage

AI tools were used for:

* documentation structuring
* documentation review
* exceptional case error

AI was **not** used to generate or copy implementation code directly. All logic and coding decisions were made and implemented by the project authors.

---

### Authors

* `todina-r`: [DinaTolotra](https://github.com/DinaTolotra) — algorithm, optimization, documentation, cleaning
* `ny-handr`: [nyyharenaa](https://github.com/nyyharenaa) — argument parsing, error handling, algorithm, cleaning
