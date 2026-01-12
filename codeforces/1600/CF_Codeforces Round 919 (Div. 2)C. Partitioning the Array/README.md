C. Partitioning the Array — Concept Explanation
Problem Recap 

You are given an array of length n.

For every divisor k of n:

Split the array into consecutive blocks of length k

So you get n / k blocks

You earn 1 point for this k if:

There exists some number m ≥ 2

After replacing every element a[i] with a[i] % m

All blocks become exactly identical

Your task is to count how many values of k give you a point.

Key Intuition (The Heart of the Problem)

When all blocks are identical after modulo, it does not mean the original values are the same.

It means something more specific:

For every position inside a block, the values at that position in all blocks must behave the same after modulo.

So instead of comparing whole blocks, we compare positions inside blocks.

This turns the problem into a column-by-column check, not a block-by-block check.

What “All Blocks Identical” Really Means

Suppose:

n = 12, k = 3


The array is split like this:

Block 1: a[0]  a[1]  a[2]
Block 2: a[3]  a[4]  a[5]
Block 3: a[6]  a[7]  a[8]
Block 4: a[9]  a[10] a[11]


For blocks to be identical after modulo m, we must have:

a[0] % m == a[3] % m == a[6] % m == a[9] % m

a[1] % m == a[4] % m == a[7] % m == a[10] % m

a[2] % m == a[5] % m == a[8] % m == a[11] % m

So each position inside the block gives its own condition.

Why Differences Matter

Two numbers give the same remainder when divided by m if and only if:

their difference is divisible by m


So for a fixed position j inside the block, we look at:

a[j], a[j + k], a[j + 2k], ...


If all these values must give the same remainder, then:

m must divide all their differences


This means:

All differences at this position share some common divisors

Any such divisor ≥ 2 can be used as m

Step-by-Step Idea

For a chosen block size k:

Step 1: Process each position inside the block

There are k positions: 0 to k - 1.

For each position j:

Look at values:
a[j], a[j + k], a[j + 2k], ...

Compute differences with the first value

Find the greatest common divisor (GCD) of those differences

This GCD tells us what values of m are possible for this position.

Step 2: Combine all positions

Every position gives a restriction on m

To satisfy all positions, we combine their GCDs

If the final combined value:

Is 1 → no valid m ≥ 2

Is 0 → all values already equal, any m ≥ 2 works

Is ≥ 2 → that value itself can be used as m

Simple Example
Array: [1, 3, 1, 3]
n = 4, k = 2


Blocks:

[1, 3]
[1, 3]


Check positions:

Position 0: 1, 1 → differences = 0

Position 1: 3, 3 → differences = 0

Everything already matches → valid.

So k = 2 earns a point.

Special Cases (Handled Naturally)

k = n

Only one block

Always valid (nothing to compare)

k = 1

Each block has one element

All elements must give the same remainder

The same logic still works

No special code is needed for these cases.

Final Decision Rule

For a divisor k of n:

Compute the GCD of all differences between elements that appear at the same position in different blocks.

If the final GCD is not equal to 1, then this k earns 1 point.

Time Complexity

For one k, every element of the array is processed once → O(n)

Number of divisors of n is small

Total complexity over one test case:
O(n × number_of_divisors(n))

This easily fits within the limits.
