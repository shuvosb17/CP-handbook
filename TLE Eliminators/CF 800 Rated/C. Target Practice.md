# Visual Explanation of Distance Calculation

Let me show you **step-by-step** how the distance calculation works with detailed diagrams.

---

## **Understanding the 10×10 Grid**

```
Grid indices (0-9 for both rows and columns):

     Column indices →
     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
0  │ .  .  .  .  .  .  .  .  .  . │
1  │ .  .  .  .  .  .  .  .  .  . │
2  │ .  .  .  .  .  .  .  .  .  . │
3  │ .  .  .  .  .  .  .  .  .  . │
4  │ .  .  .  .  .  .  .  .  .  . │
5  │ .  .  .  .  .  .  .  .  .  . │
6  │ .  .  .  .  .  .  .  .  .  . │
7  │ .  .  .  .  .  .  .  .  .  . │
8  │ .  .  .  .  .  .  .  .  .  . │
9  │ .  .  .  .  .  .  .  .  .  . │
   └──────────────────────────────┘
Row indices ↓
```

---

## **Example 1: Corner Cell (0, 0)**

```
Position: row = 0, col = 0

     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
0  │ X ← YOU ARE HERE             │
1  │ .                            │
2  │ .                            │
3  │ .                            │
4  │ .                            │
5  │ .                            │
6  │ .                            │
7  │ .                            │
8  │ .                            │
9  │ .                            │
   └──────────────────────────────┘
```

### **Step 1: Calculate from_top**
```cpp
int from_top = row;  // = 0
```

```
from_top = How many rows ABOVE you?

     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
   │ ← TOP EDGE (no rows above)
0  │ X ← You are at row 0
   │
   
from_top = 0 rows above ✓
```

### **Step 2: Calculate from_bottom**
```cpp
int from_bottom = 9 - row;  // = 9 - 0 = 9
```

```
from_bottom = How many rows BELOW you?

     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
0  │ X ← You are at row 0
1  │ . ↓
2  │ . ↓
3  │ . ↓
4  │ . ↓ 9 rows below
5  │ . ↓
6  │ . ↓
7  │ . ↓
8  │ . ↓
9  │ . ← BOTTOM EDGE
   └──────────────────────────────┘
   
from_bottom = 9 rows below ✓
```

### **Step 3: Calculate from_left**
```cpp
int from_left = col;  // = 0
```

```
from_left = How many columns to your LEFT?

     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
0  │ X ← You are at column 0
   │ ↑
   │ LEFT EDGE (no columns left)
   
from_left = 0 columns to left ✓
```

### **Step 4: Calculate from_right**
```cpp
int from_right = 9 - col;  // = 9 - 0 = 9
```

```
from_right = How many columns to your RIGHT?

     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
0  │ X  .  .  .  .  .  .  .  .  . │
   │ → → → → → → → → → →
   │ 9 columns to the right    RIGHT EDGE
   
from_right = 9 columns to right ✓
```

### **Step 5: Find Minimum**
```cpp
int min_distance = min({from_top, from_bottom, from_left, from_right});
                 = min({0, 9, 0, 9})
                 = 0
```

```
Visual summary for (0, 0):

        0 columns left
            ↓
    ┌───────X───────────────┐
    │       ↑               │
    │   0 rows above        │
    │                       │
    │   9 rows below        │
    │       ↓               │
    └───────────────────────┘
            ↑
        9 columns right

Minimum = 0 (touching the edge!)
```

### **Step 6: Calculate Points**
```cpp
int points = min_distance + 1;
           = 0 + 1
           = 1 point (outermost ring) ✓
```

---

## **Example 2: Cell at (2, 7)**

```
Position: row = 2, col = 7

     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
0  │ .  .  .  .  .  .  .  .  .  . │
1  │ .  .  .  .  .  .  .  .  .  . │
2  │ .  .  .  .  .  .  .  X ← HERE│
3  │ .  .  .  .  .  .  .  .  .  . │
4  │ .  .  .  .  .  .  .  .  .  . │
5  │ .  .  .  .  .  .  .  .  .  . │
6  │ .  .  .  .  .  .  .  .  .  . │
7  │ .  .  .  .  .  .  .  .  .  . │
8  │ .  .  .  .  .  .  .  .  .  . │
9  │ .  .  .  .  .  .  .  .  .  . │
   └──────────────────────────────┘
```

### **Calculate All Distances:**

```cpp
from_top = row = 2
```
```
     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
0  │ .  .  .  .  .  .  .  ↓  .  . │ ← 1 row above
1  │ .  .  .  .  .  .  .  ↓  .  . │ ← 2 rows above
2  │ .  .  .  .  .  .  .  X  .  . │ ← YOU ARE HERE
   
from_top = 2 ✓
```

```cpp
from_bottom = 9 - row = 9 - 2 = 7
```
```
2  │ .  .  .  .  .  .  .  X  .  . │ ← YOU
3  │ .  .  .  .  .  .  .  ↓  .  . │ ← 1
4  │ .  .  .  .  .  .  .  ↓  .  . │ ← 2
5  │ .  .  .  .  .  .  .  ↓  .  . │ ← 3
6  │ .  .  .  .  .  .  .  ↓  .  . │ ← 4
7  │ .  .  .  .  .  .  .  ↓  .  . │ ← 5
8  │ .  .  .  .  .  .  .  ↓  .  . │ ← 6
9  │ .  .  .  .  .  .  .  ↓  .  . │ ← 7 rows below
   
from_bottom = 7 ✓
```

```cpp
from_left = col = 7
```
```
     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
2  │ ← ← ← ← ← ← ← X  .  . │
   │                 ↑
   │     7 columns to left
   
from_left = 7 ✓
```

```cpp
from_right = 9 - col = 9 - 7 = 2
```
```
     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
2  │ .  .  .  .  .  .  .  X  →  → │
   │                       ↑
   │              2 columns to right
   
from_right = 2 ✓
```

### **Find Minimum:**
```cpp
min_distance = min({2, 7, 7, 2})
             = 2
```

```
Visual summary for (2, 7):

        7 left
          ↓
    ┌─────────X──┐
    │     2   ↑  │
    │   above │  │
    │         │  │ 2 right
    │     7   │  │
    │   below ↓  │
    └────────────┘

Closest edge is 2 units away (top or right)
Minimum = 2 ✓
```

### **Calculate Points:**
```cpp
points = min_distance + 1
       = 2 + 1
       = 3 points (third ring) ✓
```

---

## **Example 3: Center Cell (4, 4) or (4, 5)**

```
Position: row = 4, col = 4

     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
0  │ .  .  .  .  .  .  .  .  .  . │
1  │ .  .  .  .  .  .  .  .  .  . │
2  │ .  .  .  .  .  .  .  .  .  . │
3  │ .  .  .  .  .  .  .  .  .  . │
4  │ .  .  .  .  X ← CENTER .  . . │
5  │ .  .  .  .  .  .  .  .  .  . │
6  │ .  .  .  .  .  .  .  .  .  . │
7  │ .  .  .  .  .  .  .  .  .  . │
8  │ .  .  .  .  .  .  .  .  .  . │
9  │ .  .  .  .  .  .  .  .  .  . │
   └──────────────────────────────┘
```

### **Calculate:**
```cpp
from_top    = 4
from_bottom = 9 - 4 = 5
from_left   = 4
from_right  = 9 - 4 = 5

min_distance = min({4, 5, 4, 5}) = 4
points = 4 + 1 = 5 (center ring!) ✓
```

```
Visual summary for (4, 4):

        4 left
          ↓
    ┌─────X─────┐
    │  4  ↑  5  │
    │     │     │
    │  5  ↓     │
    └───────────┘

Farthest from any edge!
Minimum = 4 → 5 points ✓
```

---

## **Complete Ring Visualization**

```
Points map for entire grid:

     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
0  │ 1  1  1  1  1  1  1  1  1  1 │
1  │ 1  2  2  2  2  2  2  2  2  1 │
2  │ 1  2  3  3  3  3  3  3  2  1 │
3  │ 1  2  3  4  4  4  4  3  2  1 │
4  │ 1  2  3  4  5  5  4  3  2  1 │
5  │ 1  2  3  4  5  5  4  3  2  1 │
6  │ 1  2  3  4  4  4  4  3  2  1 │
7  │ 1  2  3  3  3  3  3  3  2  1 │
8  │ 1  2  2  2  2  2  2  2  2  1 │
9  │ 1  1  1  1  1  1  1  1  1  1 │
   └──────────────────────────────┘

Each number = min_distance + 1
```

---

## **Key Formula Summary**

```
For any cell at (row, col):

from_top    = row           (distance from top edge)
from_bottom = 9 - row       (distance from bottom edge)
from_left   = col           (distance from left edge)
from_right  = 9 - col       (distance from right edge)

min_distance = minimum of all 4 distances
points = min_distance + 1

Ring 1 (edges):    min_distance = 0 → 1 point
Ring 2:            min_distance = 1 → 2 points
Ring 3:            min_distance = 2 → 3 points
Ring 4:            min_distance = 3 → 4 points
Ring 5 (center):   min_distance = 4 → 5 points
```

This is how the distance calculation determines which ring (and point value) each cell belongs to! 🎯


# Understanding `min_distance` - The Key Concept

Let me explain **why** and **how** we use the minimum distance formula.

---

## **The Core Idea: "Closest to Any Edge"**

The **minimum distance** tells us: **"How far is this cell from the NEAREST edge?"**

---

## **Visual Explanation**

### **Example: Cell at (2, 7)**

```
     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
0  │ .  .  .  .  .  .  .  .  .  . │ ← TOP edge
1  │ .  .  .  .  .  .  .  .  .  . │
2  │ .  .  .  .  .  .  .  X  .  . │ ← YOU
3  │ .  .  .  .  .  .  .  .  .  . │
4  │ .  .  .  .  .  .  .  .  .  . │
   │                              │
   └──────────────────────────────┘
   ↑                              ↑
 LEFT                           RIGHT
 edge                           edge
```

### **Calculate All 4 Distances:**

```
1. Distance to TOP edge:
   ┌──────────────────────────────┐
0  │ .  .  .  .  .  .  .  ↓  .  . │ TOP
1  │ .  .  .  .  .  .  .  ↓  .  . │
2  │ .  .  .  .  .  .  .  X  .  . │ YOU
   
   from_top = 2 (need to cross 2 rows to reach top)


2. Distance to BOTTOM edge:
2  │ .  .  .  .  .  .  .  X  .  . │ YOU
3  │ .  .  .  .  .  .  .  ↓  .  . │
4  │ .  .  .  .  .  .  .  ↓  .  . │
5  │ .  .  .  .  .  .  .  ↓  .  . │
6  │ .  .  .  .  .  .  .  ↓  .  . │
7  │ .  .  .  .  .  .  .  ↓  .  . │
8  │ .  .  .  .  .  .  .  ↓  .  . │
9  │ .  .  .  .  .  .  .  ↓  .  . │ BOTTOM
   
   from_bottom = 7 (need to cross 7 rows to reach bottom)


3. Distance to LEFT edge:
   LEFT
   ↓
2  │ ← ← ← ← ← ← ← X  .  . │
   
   from_left = 7 (need to cross 7 columns to reach left)


4. Distance to RIGHT edge:
2  │ .  .  .  .  .  .  .  X  →  → │
                              ↑
                            RIGHT
   
   from_right = 2 (need to cross 2 columns to reach right)
```

### **Now Apply the Formula:**

```
Distances:
- from_top    = 2
- from_bottom = 7
- from_left   = 7
- from_right  = 2

Question: Which edge is CLOSEST?
Answer: TOP or RIGHT (both are 2 units away)

min_distance = min(2, 7, 7, 2) = 2
```

---

## **Why Minimum? The Ring Concept**

Think of rings like **layers of an onion** - each layer surrounds the previous one.

```
Ring visualization:

1 1 1 1 1 1 1 1 1 1  ← Ring 1 (outermost)
1 2 2 2 2 2 2 2 2 1  ← Ring 2
1 2 3 3 3 3 3 3 2 1  ← Ring 3
1 2 3 4 4 4 4 3 2 1  ← Ring 4
1 2 3 4 5 5 4 3 2 1  ← Ring 5 (center)
1 2 3 4 5 5 4 3 2 1
1 2 3 4 4 4 4 3 2 1
1 2 3 3 3 3 3 3 2 1
1 2 2 2 2 2 2 2 2 1
1 1 1 1 1 1 1 1 1 1
```

**Key observation:**
- To determine which ring you're in, you only need to know the **closest edge**
- If you're close to ANY edge, you're in an outer ring
- If you're far from ALL edges, you're in an inner ring

---

## **Step-by-Step Logic**

### **Case 1: Cell at Corner (0, 0)**

```
Position: (0, 0)

     X ← You're touching TWO edges!
     │
   TOP & LEFT edges

from_top    = 0  ← touching!
from_bottom = 9
from_left   = 0  ← touching!
from_right  = 9

min = min(0, 9, 0, 9) = 0

Interpretation: You're 0 units from an edge
→ You're in the outermost ring
→ Ring number = 0 + 1 = 1 point ✓
```

### **Case 2: Cell at (1, 1)**

```
Position: (1, 1)

1 1 1 1 1 1 1 1 1 1
1 X 2 2 2 2 2 2 2 1  ← You're here
1 2 3 3 3 3 3 3 2 1

from_top    = 1
from_bottom = 8
from_left   = 1
from_right  = 8

min = min(1, 8, 1, 8) = 1

Interpretation: You're 1 unit from the nearest edge
→ You're in the second ring
→ Ring number = 1 + 1 = 2 points ✓
```

### **Case 3: Cell at Center (4, 4)**

```
Position: (4, 4)

1 1 1 1 1 1 1 1 1 1
1 2 2 2 2 2 2 2 2 1
1 2 3 3 3 3 3 3 2 1
1 2 3 4 4 4 4 3 2 1
1 2 3 4 X 5 4 3 2 1  ← You're here (center)
1 2 3 4 5 5 4 3 2 1

from_top    = 4
from_bottom = 5
from_left   = 4
from_right  = 5

min = min(4, 5, 4, 5) = 4

Interpretation: You're 4 units from the nearest edge
→ You're in the innermost ring
→ Ring number = 4 + 1 = 5 points ✓
```

---

## **Why Not Maximum or Average?**

### **If we used MAXIMUM:**

```
Cell at (2, 7):
max(2, 7, 7, 2) = 7
Points = 7 + 1 = 8 ❌ (incorrect, no ring has 8 points)
```

### **If we used AVERAGE:**

```
Cell at (2, 7):
average(2, 7, 7, 2) = 4.5
Points = 5 ❌ (incorrect, this cell is not in center)
```

### **Using MINIMUM:**

```
Cell at (2, 7):
min(2, 7, 7, 2) = 2
Points = 3 ✓ (correct!)
```

---

## **Real-World Analogy**

Think of it like **security zones** in a building:

```
Building with security rings:

┌─────────────────────────┐
│ Public area (Ring 1)    │
│ ┌─────────────────────┐ │
│ │ Staff area (Ring 2) │ │
│ │ ┌─────────────────┐ │ │
│ │ │ Restricted (3)  │ │ │
│ │ │ ┌───────────┐   │ │ │
│ │ │ │ High (4)  │   │ │ │
│ │ │ │ ┌───┐     │   │ │ │
│ │ │ │ │ X │     │   │ │ │  ← You are here
│ │ │ │ └───┘     │   │ │ │
│ │ │ └───────────┘   │ │ │
│ │ └─────────────────┘ │ │
│ └─────────────────────┘ │
└─────────────────────────┘
```

**Question:** What security level are you at?

**Answer:** The **highest** level you can reach by walking to the **nearest exit**

- If you can reach public area in 1 step → Security level 1
- If nearest exit is 4 steps away → Security level 4

**The minimum distance tells you which security zone (ring) you're in!**

---

## **Complete Solution with Comments**

````cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        vector<string> grid(10);
        for(int i = 0; i < 10; i++) {
            cin >> grid[i];
        }
        
        int total_score = 0;
        
        for(int row = 0; row < 10; row++) {
            for(int col = 0; col < 10; col++) {
                if(grid[row][col] == 'X') {
                    
                    // How far from each edge?
                    int from_top = row;
                    int from_bottom = 9 - row;
                    int from_left = col;
                    int from_right = 9 - col;
                    
                    // Which edge is CLOSEST?
                    // This determines which ring we're in
                    int min_distance = min({from_top, from_bottom, 
                                           from_left, from_right});
                    
                    // Closest to edge (0) = outer ring (1 point)
                    // Farthest from edge (4) = center ring (5 points)
                    int points = min_distance + 1;
                    
                    total_score += points;
                }
            }
        }
        
        cout << total_score << endl;
    }
    
    return 0;
}
````

---

## **Summary**

| Concept | Meaning |
|---------|---------|
| **min_distance** | Distance to the **nearest** edge |
| **Why minimum?** | Determines which ring (layer) you're in |
| **Formula** | `points = min_distance + 1` |
| **Ring 1** | `min_distance = 0` → touching edge |
| **Ring 5** | `min_distance = 4` → center (farthest from all edges) |

The **minimum** makes sense because **being close to ANY edge** puts you in an outer ring! 🎯



# I Didn't Take Those Numbers as Input! 📝

That diagram is **NOT input** - it's a **visualization** showing what the **point values** are for each cell position!

Let me clarify the confusion:

---

## **What the Program Actually Takes as Input**

The program reads a **10×10 grid of characters** (either `X` or `.`), not numbers!

### **Actual Input Format:**

```
1                    ← number of test cases
X.........          ← Row 0: X at position (0,0)
..........          ← Row 1: all dots
.......X..          ← Row 2: X at position (2,7)
.....X....          ← Row 3: X at position (3,5)
......X...          ← Row 4: X at position (4,6)
..........          ← Row 5: all dots
.........X          ← Row 6: X at position (6,9)
..X.......          ← Row 7: X at position (7,2)
..........          ← Row 8: all dots
.........X          ← Row 9: X at position (9,9)
```

**Input is:**
- `'X'` = arrow hit
- `'.'` = empty space

---

## **What That Number Diagram Represents**

The number diagram shows the **calculated point values** for each position - it's like a **lookup table** or **reference map**.

```
Point value map (NOT input, just for reference):

     0  1  2  3  4  5  6  7  8  9
   ┌──────────────────────────────┐
0  │ 1  1  1  1  1  1  1  1  1  1 │ ← If X is here, worth 1 point
1  │ 1  2  2  2  2  2  2  2  2  1 │ ← If X is here, worth 2 points
2  │ 1  2  3  3  3  3  3  3  2  1 │
3  │ 1  2  3  4  4  4  4  3  2  1 │
4  │ 1  2  3  4  5  5  4  3  2  1 │ ← Center worth 5 points
5  │ 1  2  3  4  5  5  4  3  2  1 │
6  │ 1  2  3  4  4  4  4  3  2  1 │
7  │ 1  2  3  3  3  3  3  3  2  1 │
8  │ 1  2  2  2  2  2  2  2  2  1 │
9  │ 1  1  1  1  1  1  1  1  1  1 │
   └──────────────────────────────┘

This is CALCULATED by the code, not read as input!
```

---

## **How the Code Works - Step by Step**

### **Step 1: Read the Grid (Characters, not Numbers)**

```cpp
vector<string> grid(10);
for(int i = 0; i < 10; i++) {
    cin >> grid[i];  // Read one line like "X........."
}
```

**Example input:**
```
X.........   ← grid[0] = "X........."
..........   ← grid[1] = ".........."
.......X..   ← grid[2] = ".......X.."
```

### **Step 2: Process Each Cell**

```cpp
for(int row = 0; row < 10; row++) {
    for(int col = 0; col < 10; col++) {
        if(grid[row][col] == 'X') {
            // Calculate points for this X
```

### **Step 3: Calculate Points (This Creates the Number Map)**

```cpp
int from_top = row;
int from_bottom = 9 - row;
int from_left = col;
int from_right = 9 - col;

int min_distance = min({from_top, from_bottom, from_left, from_right});
int points = min_distance + 1;
```

**This formula generates those numbers you saw!**

---

## **Complete Example**

### **Input:**

```
1
X.........
..........
.......X..
.....X....
......X...
..........
.........X
..X.......
..........
.........X
```

### **What Happens:**

The code finds each `X` and calculates its points:

```
Position (0,0): X found
├─ from_top = 0
├─ from_bottom = 9
├─ from_left = 0
├─ from_right = 9
├─ min_distance = min(0,9,0,9) = 0
└─ points = 0 + 1 = 1 ✓

Position (2,7): X found
├─ from_top = 2
├─ from_bottom = 7
├─ from_left = 7
├─ from_right = 2
├─ min_distance = min(2,7,7,2) = 2
└─ points = 2 + 1 = 3 ✓

Position (3,5): X found
├─ from_top = 3
├─ from_bottom = 6
├─ from_left = 5
├─ from_right = 4
├─ min_distance = min(3,6,5,4) = 3
└─ points = 3 + 1 = 4 ✓

... and so on
```

### **Output:**

```
17  ← Sum of all points
```

---

## **Visual Comparison**

### **What You Read (Input):**

```
X.........  ← Characters: X or .
..........
.......X..
.....X....
......X...
..........
.........X
..X.......
..........
.........X
```

### **What the Code Calculates (Not Input):**

```
1 1 1 1 1 1 1 1 1 1  ← Point values (calculated)
1 2 2 2 2 2 2 2 2 1
1 2 3 3 3 3 3 3 2 1
1 2 3 4 4 4 4 3 2 1
1 2 3 4 5 5 4 3 2 1
1 2 3 4 5 5 4 3 2 1
1 2 3 4 4 4 4 3 2 1
1 2 3 3 3 3 3 3 2 1
1 2 2 2 2 2 2 2 2 1
1 2 2 2 2 2 2 2 2 1
```

### **What the Code Outputs:**

```
17  ← Final score (sum of points where X exists)
```

---

## **How to Test Your Code**

### **Create a test file `input.txt`:**

```
1
X.........
..........
.......X..
.....X....
......X...
..........
.........X
..X.......
..........
.........X
```

### **Run:**

```bash
g++ C_Target_Practice.cpp -o target
./target < input.txt
```

### **Expected Output:**

```
17
```

---

## **Summary**

| What | Description |
|------|-------------|
| **Input** | 10×10 grid of `X` and `.` characters |
| **Processing** | Code calculates point value for each `X` |
| **Formula** | `points = min(row, 9-row, col, 9-col) + 1` |
| **Number diagram** | Visual reference showing calculated points |
| **Output** | Total sum of points |

**The numbers in that diagram are NOT input - they're what the code CALCULATES!** 🎯

Your code is **correct** and working as expected! ✅
