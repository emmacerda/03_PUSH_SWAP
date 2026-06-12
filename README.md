# push_swap

A sorting algorithm project from 42 school. The program sorts a stack of integers using a limited set of operations on two stacks, selecting the most efficient strategy based on input size and disorder.

## Authors

- `romapere` — `emcerda`

---

## Usage

```bash
make
./push_swap [--simple | --medium | --complex | --adaptive] <integers>
```

**Examples:**
```bash
./push_swap 3 1 4 2 5
./push_swap --medium 9 1 8 3 7 2 6 5 4 10
./push_swap --bench 42 7 13 1 99
```

---

## Flags

| Flag | Description |
|------|-------------|
| `--simple` | Force O(n²) algorithm |
| `--medium` | Force O(n√n) chunk-based algorithm |
| `--complex` | Force O(n log n) algorithm |
| `--adaptive` | Force adaptive algorithm (default behavior) |
| `--bench` | Display benchmark info on stderr after sorting |

If no flag is given, the adaptive algorithm is used by default.

---

## Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of B to top of A |
| `pb` | Push top of A to top of B |
| `ra` | Rotate A upward (first becomes last) |
| `rb` | Rotate B upward (first becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A (last becomes first) |
| `rrb` | Reverse rotate B (last becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Algorithms

### Disorder metric

Before sorting, the program computes a disorder score between 0 and 1:
- `0` means the stack is already sorted
- `1` means the stack is in the worst possible order

It is computed by counting how many pairs `(i, j)` with `i < j` satisfy `a[i] > a[j]`, divided by the total number of pairs.

---

### Simple — O(n²)

A selection or insertion sort adaptation. At each step, finds the minimum (or maximum) element and brings it to the correct position using rotations and pushes.

Best for small inputs or nearly sorted stacks.

---

### Medium — O(n√n)

A chunk-based sorting strategy:

**Phase 1 — Push to B by chunk:**
- Elements are assigned an index (their rank in sorted order)
- Indexes are divided into `√n` chunks
- Elements are pushed to B chunk by chunk, from smallest to largest

**Phase 2 — Reconstruct A:**
- Repeatedly find the maximum element in B by index
- Bring it to the top using `rb` or `rrb` (whichever requires fewer moves)
- Push it to A

Result: A is sorted in ascending order.

---

### Complex — O(n log n)

A radix sort or merge sort adaptation using the two stacks as data structures.

---

### Adaptive

Selects the strategy automatically based on the measured disorder:

| Disorder | Strategy | Complexity |
|----------|----------|------------|
| < 0.2 | Simple (nearly sorted) | O(n) |
| 0.2 ≤ disorder < 0.5 | Medium chunk-based | O(n√n) |
| ≥ 0.5 | Complex | O(n log n) |

**Rationale:** A low disorder means most elements are already in place — a few targeted moves suffice. Medium disorder benefits from chunk partitioning to group elements efficiently. High disorder requires a full O(n log n) strategy to keep operation count manageable.

---

## Benchmark mode

When `--bench` is passed, the following is printed to stderr after sorting:

```
Disorder:     0.73 (73.00%)
Strategy:     Medium — O(n√n)
Total ops:    142
sa: 0   sb: 0   ss: 0
pa: 10  pb: 10  ra: 67  rb: 12  rr: 0
rra: 8  rrb: 35 rrr: 0
```

---

## Error handling

The program prints `Error` to stderr and exits in the following cases:
- Non-integer arguments
- Values outside the `INT_MIN` / `INT_MAX` range
- Duplicate values

---

## Project structure

```
push_swap/
├── main.c
├── ft_checkarg.c       — argument parsing and validation
├── ft_create_stacks.c  — stack initialization
├── ft_adaptive.c       — adaptive algorithm
├── ft_complex.c        — O(n log n) algorithm
├── ft_find_disorder.c  — disorder computation
├── ft_utils_lst.c      — linked list utilities
├── ft_str_utils.c      — string utilities
├── ft_atoi.c
├── ft_split.c
├── push.c              — pa, pb
├── rotate.c            — ra, rb, rr
├── reverse.c           — rra, rrb, rrr
├── swap.c              — sa, sb, ss
├── simple.c            — O(n²) algorithm
├── ft_bench.c          — benchmark output
├── ft_push_swap.h
└── Makefile
```
