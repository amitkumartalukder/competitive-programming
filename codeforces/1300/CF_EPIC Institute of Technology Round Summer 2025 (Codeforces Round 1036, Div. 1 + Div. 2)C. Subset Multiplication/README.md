Subset Multiplication — Concept Explanation
1. Problem Recap :

You are given an array b of positive integers.

Originally, there was another array a with these properties:

a was beautiful, meaning
every element divides the next one

a[i] divides a[i+1]


Bob copied a into b

Then Bob chose one positive integer x

He multiplied some elements (any subset) of b by x

You are only given the final array b.

Your task is to output any possible value of x that could make this happen.

It is guaranteed that at least one valid x exists.

2. Key Intuition (Why this works)

The most important idea is this:

Bob uses the same number x everywhere.
He does not choose a different multiplier for each position.

So the problem is not about individual elements —
it is about finding one global number x that keeps the whole array consistent.

3. What never changes (important observation)

Look at any position i.

Either b[i] = a[i]

Or b[i] = a[i] × x

In both cases:

a[i] always divides b[i]


So the original values are hidden inside b, possibly multiplied by x.

4. Why we look at adjacent pairs

The original array a had this rule:

a[i] divides a[i+1]


So we focus on adjacent pairs in b:

(b[i], b[i+1])


Each adjacent pair gives us a restriction on what x can be.

5. Extracting a restriction from one pair

Consider a single pair (b[i], b[i+1]).

There is some shared part between them that existed before Bob multiplied anything.

That shared part is exactly:

gcd(b[i], b[i+1])


Now look at what remains in b[i] after removing the shared part:

need = b[i] / gcd(b[i], b[i+1])


This value represents:

“The extra factor that must be explained by x.”

So for this one pair to make sense:

x must be a multiple of need

6. Why this happens for every pair

We repeat the same logic for every adjacent pair:

need[1], need[2], need[3], ...


Each one says:

x must be divisible by need[i]


So x must satisfy all these conditions at the same time.

7. How to satisfy all conditions together

Now the problem becomes very simple:

Find a number x that is divisible by
need[1], need[2], need[3], ...

The smallest number that does this is the:

LCM (Least Common Multiple)


So we take:

x = LCM of all need values


This guarantees that:

Every adjacent pair is valid

One single global x explains the entire array

8. Small Example

Suppose:

b = [4, 8, 4, 8]


Adjacent pairs:

(4, 8): gcd = 4 → need = 1

(8, 4): gcd = 4 → need = 2

(4, 8): gcd = 4 → need = 1

So we need:

x divisible by 1 and 2


The smallest such number is:

x = 2

9. Final Decision Rule

For each adjacent pair (b[i], b[i+1]):

Compute

need = b[i] / gcd(b[i], b[i+1])


Keep taking the LCM of all need values

Output the final LCM as x

That x is guaranteed to work.

10. Time Complexity

Each gcd and lcm operation takes O(log max(b[i]))

We process the array once

Total time complexity:

O(n log max(b))
