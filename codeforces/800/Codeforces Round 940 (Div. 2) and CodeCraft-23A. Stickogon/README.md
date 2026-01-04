Problem Recap (In Simple Words)

You are given some sticks.
Each stick has a length.

Your task is to build as many regular polygons as possible, such that:

All sides of a polygon have equal length

Each side uses exactly one stick

No stick can be reused

Sticks cannot be broken

A polygon must have at least 3 sides

You need to do this for multiple test cases.

Key Intuition (Most Important Part)

The smallest regular polygon is a triangle, which needs 3 equal sticks.

So:

If you have less than 3 sticks of the same length, you cannot make any polygon from them.

If you have 3 or more sticks of the same length, you can make at least one polygon.

Now the crucial insight:

To make the maximum number of polygons,
we should always build the smallest possible polygon (triangle).

Why?

Using more sides (like a square or pentagon) consumes more sticks

That reduces the total number of polygons we can build

Triangles give the best return per stick

Step-by-Step Thinking
Step 1: Group sticks by length

Sticks of different lengths cannot be in the same polygon.

So first:

Count how many times each stick length appears

This is done using a frequency count.

Step 2: Decide how many polygons each group can form

For one stick length:

Suppose it appears f times

Each polygon needs 3 sticks

So the number of polygons possible is:

f / 3


(We take integer division, because partial polygons don’t count.)

Step 3: Add everything together

Do this for every stick length

Add up all possible polygons

That sum is the final answer for the test case

Simple Examples
Example 1
Sticks: 1 1


Frequency:

1 → 2 times

Not enough for a polygon → Answer = 0

Example 2
Sticks: 3 3 3 3


Frequency:

3 → 4 times

4 / 3 = 1 → One triangle
Answer = 1

Example 3
Sticks: 2 2 2 2 2   and   4 4 4 4


Frequency:

2 → 5 → 5/3 = 1

4 → 4 → 4/3 = 1

Total polygons = 1 + 1 = 2

Final Decision Rule

For each test case:

Count how many times each stick length appears

For each length, compute:

number_of_polygons += frequency / 3


Output the total

That’s it.

Time Complexity

Counting frequencies: O(n)

Processing each stick length: O(n)

Overall per test case: O(n)

This easily fits within the problem limits.
