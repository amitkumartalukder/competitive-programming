Problem Recap

You originally had a sequence of 2n + 1 distinct positive numbers:

a1, a2, a3, ..., a(2n+1)


This sequence followed one special rule:

a1 = a2 - a3 + a4 - a5 + ... + a(2n) - a(2n+1)


Someone then:

deleted exactly one number from this sequence

shuffled the remaining numbers

You are now given the shuffled list of 2n numbers, called b.

Your task:

Reconstruct any valid original sequence a

The sequence must follow the rule above

All numbers must be distinct

If you remove one number from your output and shuffle, you should get b

At least one valid answer is guaranteed to exist.

Key Intuition (Why this problem is solvable)

The main idea is this:

The equation adds some numbers and subtracts others.
If we carefully choose which numbers are added and which are subtracted, we can control the result.

Two important observations make the problem easy:

Big numbers are powerful
If a big number is added and a small number is subtracted, the result grows.

We are allowed to create one new number
The missing number does not have to be in b.
So we can safely construct it to be larger than all given numbers, avoiding duplicates.

This means:

We arrange the given numbers smartly

Then compute the missing number so that the equation always holds

Step-by-Step Strategy
Step 1: Sort the numbers

Sort the given array b in increasing order.

This makes it easy to:

Take the smallest numbers when we want to subtract

Take the largest numbers when we want to add

Step 2: Choose the first number a1

Set:

a1 = the largest number in b


Why?

a1 appears alone on the left side of the equation

Using a large value gives us flexibility later

Remove this number from b.

Step 3: Split remaining numbers into two groups

Now we have 2n - 1 numbers left.

Take the next n largest numbers → call this list big

The remaining smallest n - 1 numbers → call this list small

These groups will be used like this:

Numbers in big will mostly be added

Numbers in small will be subtracted

Step 4: Compute the missing number

We now rebuild the equation from the right side.

The missing number is chosen so that the equation becomes true:

missing = a1
          + (big[0] - small[0])
          + (big[1] - small[1])
          + ...
          + last_big


Why this works:

Each (big - small) part is positive

We are adding many positive values

So missing becomes larger than all existing numbers

This guarantees:

No duplicates

All values stay positive

The equation is satisfied exactly

Step 5: Build the final sequence

Now output the sequence in this order:

a1,
small[0], big[0],
small[1], big[1],
...
missing,
last_big


This placement matches the alternating + - + - pattern required by the rule.

Simple Example

Suppose:

b = [2, 4, 6, 8]   (n = 2)


After sorting:

[2, 4, 6, 8]


a1 = 8

big = [6, 4]

small = [2]

Compute missing:

missing = 8 + (6 - 2) + 4 = 16


Final sequence:

8, 2, 6, 16, 4


Check:

8 = 2 - 6 + 16 - 4


Correct.

Final Decision Rule

To always solve the problem correctly:

Sort the given numbers

Pick the largest as a1

Use large numbers on the “add” side

Use small numbers on the “subtract” side

Construct the missing number so it becomes the largest

This guarantees:

The equation holds

All numbers are distinct

The original array can be recovered

Time Complexity

Sorting takes O(n log n)

All other steps are linear

Overall complexity per test case: O(n log n)
