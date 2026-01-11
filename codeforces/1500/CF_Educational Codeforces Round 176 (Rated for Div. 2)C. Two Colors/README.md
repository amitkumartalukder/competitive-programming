Problem Recap

There are n fence planks in a straight line.

Each plank must be painted exactly one color.

Exactly two different colors must be used.

Planks painted with the same color must be continuous (one block).

There are m available colors.

Color i can paint at most a[i] planks.

We must count how many different valid paintings are possible.

Two paintings are considered different if any plank has a different color.

Key Intuition (most important idea)

Because:

only two colors are allowed, and

each color must appear in one continuous block,

every valid fence must look like this:

[ same color ][ same color ]


That means:

the fence is split at one boundary position,

the left part has one color,

the right part has a different color.

So instead of thinking about the whole fence at once,
we only need to think about where the color changes.

Step 1: Think in Terms of a Boundary

Let’s say the fence changes color after plank k:

Left side: planks 1 to k → length = k

Right side: planks k+1 to n → length = n - k

Here:

k can be any value from 1 to n - 1

Each k represents a different fence structure

We will count valid paintings for each possible k, then add them up.

Step 2: Which Colors Can Go on Each Side?

Now fix a boundary k.

Left side (length = k)

A color can be used on the left if:

a[i] ≥ k


Let:

x = number of colors that can paint at least k planks

Right side (length = n - k)

A color can be used on the right if:

a[i] ≥ n - k


Let:

y = number of colors that can paint at least (n - k) planks

Step 3: Naive Counting (and Why It’s Wrong)

At first glance:

We can choose any of the x colors for the left

And any of the y colors for the right

So it looks like:

x × y


ways.

But this counts some invalid cases.

Step 4: Fixing the Overcount (Critical Observation)

The problem requires exactly two different colors.

However, x × y also includes cases where:

the same color is used on both sides.

When can a color appear on both sides?

Only if it can paint both parts:

a[i] ≥ k AND a[i] ≥ n - k


That means:

a[i] ≥ max(k, n - k)


How many such colors are there?

Because:

x counts colors valid for the left

y counts colors valid for the right

The number of colors valid for both sides is:

min(x, y)


These cases must be removed.

Step 5: Correct Count for One Boundary

For a fixed k, the number of valid paintings is:

x × y − min(x, y)


This:

counts all left/right color choices

removes the invalid same-color cases

Step 6: Add Results for All Boundaries

We repeat this process for:

k = 1 to n − 1


Each k represents a unique fence split, so there is no double counting.

The final answer is:

sum over all k of (x × y − min(x, y))

How We Compute x and y Efficiently

Sort the array a

For any required length L:

find the first index where a[i] ≥ L using binary search

the number of valid colors is:

m − index


This keeps the solution fast.

Simple Example

Let:

n = 5
a = [2, 4]


Try k = 2:

Left needs 2 → both colors work → x = 2

Right needs 3 → only color 4 works → y = 1

Naive: 2 × 1 = 2
Invalid same-color case: 1

Valid paintings: 2 − 1 = 1

Final Decision Rule

For each boundary k from 1 to n − 1:

Count how many colors can paint k planks → x

Count how many colors can paint n − k planks → y

Add:

x × y − min(x, y)


Sum all results

That sum is the answer.

Time Complexity

Sorting colors: O(m log m)

Looping over boundaries with binary search: O(n log m)

Overall:

O((n + m) log m)
