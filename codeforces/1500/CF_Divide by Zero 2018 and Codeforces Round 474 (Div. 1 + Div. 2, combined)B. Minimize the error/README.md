Problem Recap

You are given two arrays A and B, each of size n.

The error between them is defined as:

(A1 - B1)² + (A2 - B2)² + ... + (An - Bn)²


You must perform:

exactly k1 operations on array A

exactly k2 operations on array B

In one operation, you can:

choose any one element

increase it by 1 or decrease it by 1

Your goal is to perform all operations and make the final error as small as possible.

Key Intuition (Most Important Part)

The actual values inside arrays A and B are not what matter most.

What really matters is the difference between them.

For each position i, look at:

difference = |A[i] - B[i]|


The total error is just the sum of squares of these differences.

So the problem becomes:

We have some differences.
Each operation can increase or decrease one difference by 1.
We have a limited number of operations.
How do we minimize the sum of squared differences?

Why Greedy Works Here

Squaring makes large differences much more expensive than small ones.

Example:

10² = 100
9²  = 81   → reduced by 19

2² = 4
1² = 1    → reduced by only 3


So:

Reducing a large difference saves much more error

Reducing a small difference saves very little

That leads to a simple rule:

Always reduce the largest difference first

This is why a greedy approach is optimal.

Important Observation About Operations

An operation on A or B does the same thing:

It changes the difference by ±1

So instead of tracking k1 and k2 separately, we can safely combine them:

total_operations = k1 + k2


Now the problem becomes simpler:

You have total_operations

Each operation can reduce any one difference by 1

Step-by-Step Strategy
Step 1: Build the difference array

For every index:

diff[i] = |A[i] - B[i]|

Step 2: Always pick the largest difference

To always access the current largest difference efficiently, use a max heap (priority queue).

Step 3: Apply operations greedily

While you still have operations left:

Take the largest difference

Reduce it by 1

Put it back

This guarantees maximum reduction in total error.

Step 4: Handle leftover operations

If all differences become 0 but operations are still left:

One operation makes a difference 1

Another operation brings it back to 0

So:

If remaining operations are even → error stays 0

If remaining operations are odd → error becomes 1

Simple Example
A = [3, 4]
B = [14, 4]
k1 = 5, k2 = 7


Initial differences:

[11, 0]


We reduce 11 repeatedly using operations until:

[0, 0]


One operation is still left:

[0, 1]


Final error:

0² + 1² = 1

Final Decision Rule

Compute diff[i] = |A[i] - B[i]|

Put all differences into a max heap

Let k = k1 + k2

While k > 0 and the largest difference > 0:

Reduce the largest difference by 1

If all differences are 0:

If k is even → answer is 0

If k is odd → answer is 1

Otherwise:

Answer is the sum of squares of all differences

Time Complexity

Building differences: O(n)

Each operation uses heap operations: O(log n)
