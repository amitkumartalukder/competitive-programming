D1. Removal of a Sequence (Easy Version)
Problem Recap (Rules in Simple Words)

We start with a sequence of natural numbers:

1, 2, 3, 4, 5, 6, 7, ...


(conceptually up to 10^12)

We perform the same operation x times.

In one operation:

Look at the current sequence

Remove the numbers at positions:

y, 2y, 3y, 4y, ...


(based on positions, not values)

After all x operations:

If the remaining sequence has at least k numbers, print the k-th number

Otherwise, print -1

Key Intuition (Most Important Part)

The biggest mistake beginners make is trying to simulate the sequence directly.

That is impossible because:

The sequence is extremely large

We cannot store or modify it explicitly

So we must change the way we think.

 Core Insight

Instead of asking:

“What is the k-th number after all operations?”

We ask:

“If we start with numbers 1 to p,
how many numbers remain after x operations?”

If we can answer this question, we can find the answer.

Why This Works

Every operation removes positions, not values

For a sequence of length n:

Exactly ⌊n / y⌋ positions are removed in one operation

So after one operation:

new_length = n − ⌊n / y⌋


This rule depends only on the length, not on the actual numbers.

That is the key simplification.

Step-by-Step Plan
Step 1: Define a “Check” Function

For a chosen number p:

Assume the initial sequence is:

1, 2, 3, ..., p


Repeat x times:

p = p − (p / y)


At the end:

p now represents how many numbers survived

This tells us:

How many numbers remain after all operations

Step 2: What Are We Looking For?

We want the smallest number p such that:

remaining_numbers ≥ k


Why the smallest?

Because:

The k-th remaining number is exactly the smallest p

for which k numbers still survive

Step 3: Why Binary Search Works

If p is small → few numbers survive

If p is large → more numbers survive

This behavior is monotonic (always increasing).

So we can safely use binary search on p.

Small Example

Let:

x = 2, y = 3, k = 5


Try different values of p:

p = 9

After operations → only 4 remain 

p = 10

After operations → 5 remain 

So the answer is 10.

Final Decision Rule

Binary search on p

For each p, simulate only the length change:

repeat x times:
    p = p − (p / y)


If final p ≥ k, it is valid

Choose the smallest valid p

If p > 10^12, print -1

Time Complexity

Each check: O(x)

Binary search steps: O(log 10^12)

Total per test case:

O(x · log 10^12)


This is fast enough for the Easy Version, because x ≤ 10^5.
