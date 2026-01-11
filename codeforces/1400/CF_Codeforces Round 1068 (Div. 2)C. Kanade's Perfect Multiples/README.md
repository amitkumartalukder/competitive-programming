Problem Recap 

You are given:

An integer n — the size of an array

An integer k — the maximum allowed value

An array A of n numbers, where every number is between 1 and k

Your task is to build a set B (also containing numbers between 1 and k) such that two rules are satisfied:

Rule 1: Divisor Coverage

For every number in the array A, at least one number in B must divide it.

Rule 2: Multiple Completeness

For every number b you put into B, all positive multiples of b that are ≤ k must appear in array A.

Among all valid sets B, you must find one with minimum size.
If no such set exists, output -1.

Key Intuition (Why the solution works)

The most important observation is:

The smallest number in the array has no smaller divisor inside the array.

That means:

If the smallest number is x

There is nothing smaller than x in A

So the only way to satisfy Rule 1 for x is to put x itself into B

This forces our hand — we must include the smallest uncovered number.

Once we include a number x in B:

All its multiples (x, 2x, 3x, ...) become automatically covered

There is no reason to process those numbers again

This leads naturally to a greedy strategy:

Always take the smallest number that is not yet covered

Try to include it in B

If its multiples are missing, the answer is impossible

Step-by-Step Idea
Step 1: Count what exists

Store how many times each value appears in A.
This helps us quickly check whether a number is present or missing.

Step 2: Work only with unique values

Duplicates do not matter for the logic.
Extract all unique values from A and sort them in increasing order.

Step 3: Track which numbers are already covered

Maintain a finished marker:

finished[x] = true means x is already covered by some chosen number in B

Covered numbers can be skipped safely

Step 4: Greedy selection

Process the unique values from smallest to largest:

If the number is already marked as finished, skip it

Otherwise:

You must add it to B

Now check all its multiples (x, 2x, 3x, ... ≤ k)

If any multiple is missing from A, output -1

Otherwise, mark all these multiples as finished

This ensures:

Rule 1 is satisfied (everything is covered)

Rule 2 is satisfied (we only add numbers whose multiples all exist)

The size of B stays minimal

Simple Example
A = [2, 3, 4, 6], k = 6


Smallest number is 2 → must include it

Multiples: 2, 4, 6 → all exist

Covered now: 2, 4, 6

Next uncovered number is 3 → include it

Multiples: 3, 6 → exist

Everything is covered

Result:

B = {2, 3}

Why This Is Minimal

You only add a number to B when it is unavoidable

Every added number covers as many values as possible

No extra or redundant elements are added

That is exactly what “minimum size” means here.

Final Decision Rule

Repeat the following until all numbers are covered:

Take the smallest uncovered number x

If any multiple of x (≤ k) is missing in A, answer is -1

Otherwise:

Add x to B

Mark all its multiples as covered

If the process finishes successfully, output B.

Time Complexity

Sorting unique values: O(n log n)

Each number’s multiples are processed at most once
