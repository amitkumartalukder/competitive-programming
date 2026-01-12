Solution Explanation — Making Two Arrays Ordered
Problem Recap

You are given two arrays a and b, each of length n.

Together, they contain all numbers from 1 to 2n exactly once

You can perform three types of operations:

Swap adjacent elements in a

Swap adjacent elements in b

Swap a[i] with b[i]

Your goal is to make the arrays satisfy all of the following:

a is strictly increasing

b is strictly increasing

For every index i, a[i] < b[i]

You do not need the minimum number of operations.
You only need any valid sequence with at most 1709 operations.

Key Intuition (Why This Problem Is Easier Than It Looks)

The most important observation is this:

There are exactly 2n numbers.

In the final valid state:

Array a must contain the smaller n numbers

Array b must contain the larger n numbers

If this is true, then:

Both arrays can be sorted in increasing order

And automatically, a[i] < b[i] for every index

So the real task is not complicated logic or game theory.

The real task is just to move smaller numbers to a, larger numbers to b, and then sort both arrays.

Step-by-Step Strategy
Step 1: Fix a[i] < b[i] at Every Index

For each position i:

If a[i] > b[i], swap them using operation type 3

This guarantees:

The smaller number is always in a

The larger number is always in b

Example:

a = [5, 2]
b = [1, 6]

At index 1: 5 > 1 → swap
a = [1, 2]
b = [5, 6]


After this step, every index is locally correct.

Step 2: Sort Array a

Now sort array a using only adjacent swaps (operation type 1).

This is equivalent to bubble sort

Since n ≤ 40, this is fast enough

Adjacent swaps are allowed, so every swap is legal

After this step:

a is strictly increasing

Step 3: Sort Array b

Similarly, sort array b using adjacent swaps (operation type 2).

After this step:

b is strictly increasing

Why This Always Works

Step 1 ensures:
a[i] < b[i] for all i

Steps 2 and 3 only rearrange elements inside each array

No element ever moves from a to b or vice versa after Step 1

So the condition a[i] < b[i] cannot break again.

This is the key reason the solution is correct.

Simple Example

Input:

a = [3, 1]
b = [4, 2]


Step 1:

Index 2: 1 < 2 → OK
Index 1: 3 < 4 → OK


Step 2 (sort a):

a = [1, 3]


Step 3 (sort b):

b = [2, 4]


Final result:

a = [1, 3]
b = [2, 4]


All conditions satisfied.

Final Decision Rule

For every index i, if a[i] > b[i], swap them

Sort array a using adjacent swaps

Sort array b using adjacent swaps

That’s it.

Time Complexity

Fixing a[i] < b[i]: O(n)

Sorting a: O(n²)

Sorting b: O(n²)
