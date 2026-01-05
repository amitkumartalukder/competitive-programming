Problem Recap 

You are given two integers x and y:

Both have the same number of digits

All digits are from 1 to 9

You may perform this operation any number of times:

Choose a position i and swap the i-th digit of x and y

Your goal is to maximize the product x × y

If multiple answers exist, any one is acceptable

Key Intuition (Why This Problem Works This Way)

The most important idea is very simple:

Big numbers multiplied together give bigger results.

But we have a restriction:

We cannot move digits freely

We can only swap digits at the same position

So the real question becomes:

At each position, which number should receive the bigger digit?

Important Observation

Digits on the left side of a number are more important than digits on the right.

For example:

91 > 19


So:

Decisions made at earlier (leftmost) positions matter more

Once one number becomes bigger at a left position, we should avoid making the other number too small

Step-by-Step Strategy

We process the numbers from left to right.

We keep a boolean variable:

biggerFound = false


This tells us whether one number is already larger than the other at a previous position.

Step 1: Compare digits at the current position

At position i, we compare:

x[i] and y[i]


If they are equal → do nothing

If they are different → decision is needed

Step 2: First time digits differ

If this is the first position where digits differ:

Put the larger digit into x

Put the smaller digit into y

Set biggerFound = true

This ensures:

x becomes larger early

Early digits have the biggest impact on the final product

Step 3: After a difference already exists

Once biggerFound = true:

We reverse the strategy

Put the larger digit into y

Put the smaller digit into x

Why?

x is already larger

Giving all big digits to x would make y too small

A balanced pair produces a larger product

Simple Example
Example
x = 73
y = 31


Position 0

7 vs 3 → first difference

Put 7 in x, 3 in y

biggerFound = true

Position 1

3 vs 1 → difference again

Now give the larger digit to y

Swap digits

Final result:

x = 71
y = 33


Product:

71 × 33 = 2343 (maximum)

Why This Greedy Choice Works

Leftmost digits control the number’s size

We maximize the first difference

Then we balance later digits to avoid shrinking one number too much

This guarantees a large product without brute force

Final Decision Rule:

Process digits from left to right:

If digits are equal → do nothing

If digits differ and this is the first difference:

Larger digit → x

Smaller digit → y

If digits differ and a difference already exists:

Larger digit → y

Smaller digit → x

Time Complexity

Each test case: O(n) where n is number of digits

Efficient even for maximum constraints
