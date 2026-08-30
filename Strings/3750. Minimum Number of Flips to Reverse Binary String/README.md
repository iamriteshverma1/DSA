# 🔄 Minimum Flips to Make Binary Representation Palindromic

## 📌 Problem

Given an integer `n`, convert it into its **binary representation** and determine the minimum number of bit flips required to make the binary representation equal to its reverse.

In other words, compare:

```text
Binary representation of n
            ↓
        Reverse it
            ↓
Compare both strings position by position
```

Every position where the bits are different requires **one flip**.

---

## 💡 Approach

I solved this problem using **recursion** to convert the decimal number into binary.

The solution has three main steps:

1. Convert `n` into its binary representation using recursion.
2. Create a reversed copy of the binary string.
3. Compare the original and reversed strings and count the different positions.

---

## 1️⃣ Convert Decimal to Binary Using Recursion

The recursive function is:

```cpp
string s = "";

void binary(int x) {
    if (x == 1)
        s = "1";
    else if (x % 2 == 0) {
        binary(x / 2);
        s += "0";
    }
    else {
        binary((x - 1) / 2);
        s += "1";
    }
}
```

### How it works

For every number:

* If `x` is even, its last binary digit is `0`.
* If `x` is odd, its last binary digit is `1`.
* We recursively process `x / 2`.
* While returning from recursion, we append the corresponding binary digit.

### Example: `n = 10`

The recursive calls are:

```text
binary(10)
    ↓
binary(5)
    ↓
binary(2)
    ↓
binary(1)
```

At `x = 1`:

```text
s = "1"
```

While recursion returns:

```text
1 → "10"
10 → "101"
2 → "1010"
```

Therefore:

```text
10 in binary = 1010
```

---

## 2️⃣ Reverse the Binary String

After obtaining the binary representation:

```cpp
string r = s;
reverse(r.begin(), r.end());
```

For example:

```text
s = "1010"
r = "0101"
```

The original string `s` remains unchanged because `r` is a copy.

---

## 3️⃣ Compare Both Strings

Now compare the original binary string with its reversed version:

```cpp
int count = 0;

for (int i = 0; i < r.length(); i++) {
    if (r[i] != s[i])
        count++;
}
```

Whenever:

```text
s[i] != r[i]
```

the two bits are different, so one flip is required.

### Example

```text
Original:  1010
Reverse:   0101
           ↓↓↓↓
Different: ✓✓✓✓
```

Therefore:

```text
Minimum flips = 4
```

---

## 🧠 Complete Solution

```cpp
class Solution {
public:

    string s = "";

    void binary(int x) {
        if (x == 1)
            s = "1";
        else if (x % 2 == 0) {
            binary(x / 2);
            s += "0";
        }
        else {
            binary((x - 1) / 2);
            s += "1";
        }
    }

    int minimumFlips(int n) {

        if (n == 0)
            return 0;

        // Reset string before each call
        s = "";

        // Convert decimal to binary
        binary(n);

        // Create reversed binary string
        string r = s;
        reverse(r.begin(), r.end());

        int count = 0;

        // Compare original and reversed strings
        for (int i = 0; i < r.length(); i++) {
            if (r[i] != s[i])
                count++;
        }

        return count;
    }
};
```

---

# ⏱️ Time Complexity

Let:

```text
L = number of bits in the binary representation of n
```

For an integer `n`:

```text
L = O(log n)
```

### Binary conversion

The recursive function divides `x` by `2` at every step:

```text
n → n/2 → n/4 → n/8 → ...
```

Therefore:

```text
O(log n)
```

### Reversing the string

The binary string contains `L` characters:

```cpp
reverse(r.begin(), r.end());
```

takes:

```text
O(L) = O(log n)
```

### Comparing strings

The loop checks every binary digit:

```text
O(L) = O(log n)
```

### Overall

Therefore:

```text
Time Complexity = O(log n)
```

---

# 💾 Space Complexity

The binary representation contains `L = O(log n)` bits.

We store:

* `s` → `O(log n)`
* `r` → `O(log n)`
* Recursive call stack → `O(log n)`

Therefore:

```text
Space Complexity = O(log n)
```

---

# 📊 Complexity Summary

| Operation             |   Complexity |
| --------------------- | -----------: |
| Decimal → Binary      |   `O(log n)` |
| Reverse Binary String |   `O(log n)` |
| Compare Strings       |   `O(log n)` |
| **Total Time**        | **O(log n)** |
| **Total Space**       | **O(log n)** |

---

## 🚀 Key Concepts Used

* Recursion
* Binary representation
* String manipulation
* `reverse()`
* Character comparison
* Recursive call stack
* Time & space complexity analysis

---

## 📝 Important Note

The input `0` is handled separately:

```cpp
if (n == 0)
    return 0;
```

Therefore, the recursive `binary()` function only receives positive integers, making `x == 1` sufficient as its base case.

Also, `s` should **not be declared as `static`** unless it is defined separately outside the class. A normal member variable:

```cpp
string s = "";
```

is sufficient for this solution.
