# 🧠 What is a `set` (in simple words)?

In C++:

```cpp
set<int> s;
```

A `set` is a container that:

1. **Stores only unique values**
2. **Automatically removes duplicates**
3. Keeps elements **sorted**
4. Gives you the number of distinct elements using:

   ```cpp
   s.size()
   ```

👉 **If you insert the same value multiple times, it appears only once.**

---

## 🧪 Example (Basic)

```cpp
set<int> s;
s.insert(5);
s.insert(5);
s.insert(3);
s.insert(5);
s.insert(3);
```

Contents of `s`:

```
{3, 5}
```

`s.size()` → `2`

---

# 🎯 Why `set` is PERFECT for this Problem

The problem asks:

> **Are there at least 3 distinct values in array `c`?**

That word **distinct** is the key.

Instead of:

* Sorting
* Manually counting differences
* Handling edge cases

We simply:

```
Put everything in a set → ask how many unique values exist
```

---

# 🧩 How `set` Is Used in THIS Problem

We use `set` in **two different places**:

---

## 1️⃣ Counting distinct elements in `a` and `b`

```cpp
set<long long> sa(a.begin(), a.end());
set<long long> sb(b.begin(), b.end());
```

### What this does:

* Removes duplicates
* Keeps **only distinct values**
* Helps us compute:

  ```cpp
  da = sa.size();
  db = sb.size();
  ```

---

### 🔍 Example

```cpp
a = [100, 1, 100, 1]
```

After set:

```
sa = {1, 100}
da = 2
```

---

## 2️⃣ Why distinct count matters

We reasoned that:

> Maximum possible distinct sums ≤ `da × db`

So we **don’t even build array `c`**.

We only need to know:

* How many distinct values `a` has
* How many distinct values `b` has

`set` gives this **instantly and safely**.

---

# 🧠 Why NOT Manual Counting?

Your earlier logic was something like:

```cpp
sort(c.begin(), c.end());
count transitions
```

This is dangerous because:

* You count **changes**, not actual distinct values
* Off-by-one bugs happen easily
* More code = more mistakes

### `set` avoids ALL of this.

---

# 🧪 Concrete Problem Examples

---

## ❌ Example 1 (Impossible Case)

```
a = [100, 1, 100, 1]
b = [2, 2, 2, 2]
```

### Using set:

```
sa = {1, 100} → da = 2
sb = {2} → db = 1
```

Maximum sums:

```
2 × 1 = 2 < 3
```

❌ Answer = NO

---

## ✅ Example 2 (Possible Case)

```
a = [1, 2, 1, 2]
b = [1, 2, 1, 2]
```

```
sa = {1, 2} → da = 2
sb = {1, 2} → db = 2
```

```
2 × 2 = 4 ≥ 3
```

✅ Answer = YES

---

## ❌ Example 3 (n = 3 Special Case)

```
a = [1, 1, 1]
b = [2, 2, 2]
```

```
sa = {1} → da = 1
sb = {2} → db = 1
```

```
1 × 1 = 1 < 3
```

❌ Answer = NO

---

# 🧠 Mental Model (Remember This)

Think of `set` as a **filter**:

```
Array with duplicates
        ↓
      set
        ↓
 Only unique values survive
```

---

# 🏁 Final Takeaway

### In THIS problem, `set` helps because:

* The question is about **distinct values**
* We only care about **how many different values exist**
* We do **not** care about order or frequency
* `set.size()` gives the answer instantly

---

## 💡 CP Rule You Should Remember

> Whenever a problem says
> **“distinct / unique / different values”**
> think **`set` first**.

