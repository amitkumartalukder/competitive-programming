Problem Recap:

You are given n line segments on a number line.

Each segment has:

a left endpoint l

a right endpoint r

So a segment looks like:
[l , r]

Your task

Find two different indices i and j such that:

Segment i is completely inside segment j

That means:

li ≥ lj   AND   ri ≤ rj


Touching borders is allowed

Exact same segments are also allowed

If no such pair exists, print -1 -1

 Key Intuition (Why this works)

Instead of comparing every pair (which would be too slow), we use this idea:

If we look at segments in a smart order,
then a nested segment becomes easy to spot.

Core observation

If:

a big segment comes first

and a smaller segment comes later

and the smaller one ends earlier

 then the smaller segment is inside the bigger one.

So the real challenge is:

How do we arrange segments so that “possible containers” appear first?

 Step-by-Step Idea
Step 1: Store segments properly

For every segment, store:

(left, right, original_index)


The index is needed because the output must use original numbering.

Step 2: Sort the segments (very important)

Sort segments like this:

Left endpoint increasing

If left is same → Right endpoint decreasing

Why?

Smaller l means the segment starts earlier → can contain others

For same l, larger r comes first → bigger segment first

This guarantees:

If a segment can contain another one, it will appear before it.

Step 3: Scan from left to right (greedy)

Now we go through the sorted list once.

We keep track of:

maxR → the largest right endpoint seen so far

maxIdx → index of that segment

For every current segment:

If current.r ≤ maxR

then this segment is inside the earlier one

we found our answer

Otherwise:

update maxR and maxIdx

Simple Example

Segments:

[1, 10]
[2, 9]
[3, 8]


After sorting (already sorted here):

Start with [1,10] → maxR = 10

Next [2,9] → 9 ≤ 10 

So:

[2,9] is inside [1,10]


Answer found immediately.

 Why brute force is not used

Checking all pairs would take:

O(n²)


With n up to 3×10⁵, that is impossible.

Sorting + one scan gives:

O(n log n)


Which is fast enough.

 Final Decision Rule

After sorting:

While scanning from left to right,
if a segment ends before or at the same point as a previous one,
then it is nested inside that previous segment.

Print their indices.

If no such case is found, print:

-1 -1

 Time & Space Complexity

Time: O(n log n) (sorting dominates)

Space: O(n) (to store segments)
