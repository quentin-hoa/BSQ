# BSQ - Biggest Square Finder

High-performance dynamic programming solution to find the largest obstacle-free square in a grid, optimized for processing massive datasets.

## Core Algorithm: Tabulation-Based Dynamic Programming

### Problem Definition

Given a 2D grid with:
- `.` = empty cell
- `o` = obstacle

Find the **largest square** composed entirely of empty cells, and mark it with `x`.

### Algorithm: Bottom-Up DP Tabulation

The solution uses a **parallel matrix** to track square sizes:

#### Step 1: Build the DP Matrix

Create a 2D matrix `dp[i][j]` representing the **maximum square size ending at position (i, j)**:

```c
// For each cell (i, j):
if (map[i][j] == 'o') {
    dp[i][j] = 0;  // Obstacle blocks square
} else if (i == 0 || j == 0) {
    dp[i][j] = 1;  // First row/column: max square is 1
} else {
    // Take minimum of three neighbors, add 1
    dp[i][j] = min(dp[i-1][j],        // top
                   dp[i][j-1],        // left
                   dp[i-1][j-1]) + 1; // diagonal
}
```

#### Key Insight: Why Minimum of Three?

A square of size `N` ending at (i, j) requires:
- A square of size `N-1` **above** at (i-1, j)
- A square of size `N-1` **left** at (i, j-1)
- A square of size `N-1` **diagonal** at (i-1, j-1)

Taking the minimum ensures all three prerequisites exist. Adding 1 extends the square.

#### Example Walkthrough

```
Original map:
. . . . .
. . o . .
. . . . .
. . . . .

DP matrix (during computation):
1 1 1 1 1
1 1 0 1 1
1 1 1 1 2
1 1 1 2 2
```

At position (3, 3), we find `dp[3][3] = 2`, indicating a 2×2 square can fit.

### Step 2: Track Maximum Square

While building the DP matrix, maintain:
- `max_size`: largest value seen
- `max_i`, `max_j`: coordinates of the bottom-right corner

### Step 3: Mark the Square on Original Map

Once we know the largest square:
- Start at position `(max_i, max_j)`
- Mark all cells backwards: from `(max_i, max_j)` to `(max_i - max_size + 1, max_j - max_size + 1)`
- Replace `.` with `x`

```c
for (int i = 0; i < max_size; i++) {
    for (int j = 0; j < max_size; j++) {
        // Mark cell at (max_i - i, max_j - j)
        map[max_i - i][max_j - j] = 'x';
    }
}
```

### Tie-Breaking Rules

Per specification:
1. If multiple squares of **same maximum size** exist: choose the **highest** one (lowest row index)
2. If still tied: choose the **leftmost** one (lowest column index)

This is naturally achieved by iterating top-to-bottom, left-to-right.

## Performance Optimization

### Single-Pass Algorithm
- **Time:** O(rows × cols) — each cell computed once
- **Space:** O(rows × cols) — DP matrix required, but typically smaller than input

### High-Performance I/O
- Direct `read()` system call instead of buffered I/O
- Preallocated memory for large grids (no dynamic allocation per row)
- Efficient 1D-to-2D conversion (row-major format)

### Input Modes

**File Mode:**
```bash
./bsq map.txt
```
- Reads first line for row count
- Loads remaining lines as the grid
- Validates format before processing

**Generator Mode:**
```bash
./bsq 10 "..o.."
```
- First argument: grid size (NxN)
- Second argument: pattern repeated row-by-row
- Useful for stress testing without file I/O

## Implementation Details

### Data Structures

**Compact representation:**
```c
char **map;        // Original grid (rows × cols)
int **dp;          // DP matrix (same dimensions)

// Single allocation: avoids fragmentation
int *dp_data = malloc(rows * cols * sizeof(int));
```

### Key Functions

1. **`find_biggest_square()`**: Fills DP matrix using recurrence relation
2. **`mark_biggest_square()`**: Locates maximum value and marks corresponding cells
3. **`oned_to_twod()`**: Converts flat input buffer to 2D grid
4. **`free_all()`**: Deallocates all allocated memory

## Complexity Analysis

| Aspect | Complexity |
|--------|-----------|
| Time | O(rows × cols) |
| Space (DP) | O(rows × cols) |
| Space (Input) | O(rows × cols) |
| I/O | O(N) where N = total characters |

For a 10,000 × 10,000 grid: ~100M cells, all processed in seconds.

## How to Use

### Compilation
```bash
make
```

### Execution: File Mode
```bash
./bsq input_map.txt
```

File format (example):
```
5
.....
....o
.....
.....
.....
```

Output:
```
xxxxx
xxxo
xxxxxxx
xxxxxxx
xxxxx
```

### Execution: Generator Mode
```bash
./bsq 6 "..o.."
```

Generates a 6×6 grid with pattern `..o..` repeated:
```
..o...o...
..o...o...
..o...o...
..o...o...
..o...o...
..o...o...
```

Then finds and marks the largest square within it.
