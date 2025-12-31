Division and Union (Segments Problem)
Problem Recap 

You are given n line segments.
Each segment has a start point l and an end point r.

Your task is to divide all these segments into two different groups such that:

Both groups are non-empty

No segment from Group 1 overlaps (intersects) with any segment from Group 2

Every segment must belong to exactly one group

If this is possible, print which group each segment belongs to.
If it is not possible, print -1.

Key Intuition (Most Important Part)

The main idea is very simple:

If we can draw one clean vertical cut on the number line such that
all segments on the left finish before all segments on the right start,
then we can safely split them into two groups.

Why does this work?

Segments inside the same group are allowed to overlap

The problem only forbids overlap between different groups

So we only need to make sure:

Every segment in Group 1 ends before every segment in Group 2 starts

If such a separation point exists → answer is possible
If not → answer is -1

Step-by-Step Logic
Step 1: Sort the segments

Sort all segments by their starting point (l).

This helps us look at segments from left to right on the number line.

Step 2: Track how far the left side reaches

We create an array called maxRight.

maxRight[i] means:

Among segments 0 to i, what is the maximum right endpoint?

This tells us:

How far the left group stretches to the right

Example:

Segments after sorting:

[1,3], [2,5], [6,8]


Then:

maxRight = [3, 5, 8]

Step 3: Try to find a clean split

Now we check:

Is there an index i such that:
maxRight[i] < start of segment (i+1)?


Meaning:

All segments on the left end before

The next segment on the right starts

If yes → we found a clean separation point

Step 4: Assign groups

All segments before or at the split → Group 1

All segments after the split → Group 2

If no such split exists → print -1

Simple Example
Example where solution exists
Segments:
[1,2], [3,4], [5,6]


After sorting:

maxRight = [2,4,6]


At index 0:

2 < 3  ✅


So:

Group 1 → [1,2]

Group 2 → [3,4], [5,6]

No cross-group overlap ✔️

Example where solution does NOT exist
Segments:
[1,4], [2,5], [3,6]


No matter where you cut:

Left group always overlaps with right group

So:

Answer = -1

Final Decision Rule (Clean Summary)

If there exists a position where all segments on the left end before all segments on the right start, the answer is possible. Otherwise, it is impossible.

That’s it. No tricks.

Time Complexity

Sorting segments: O(n log n)

One pass to find the split: O(n)

Overall complexity per test case:

O(n log n)
