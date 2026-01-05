You are given:

An array of n numbers

Three integers:

k → how many different numbers a subarray must have

l → minimum allowed length

r → maximum allowed length

Your task:

Count how many continuous subarrays satisfy both:

The subarray contains exactly k distinct numbers

The length of the subarray is between l and r (inclusive)

A subarray means a continuous part of the array (no skipping elements).

Why This Problem Is Tricky

At first glance, you might think:

“Let’s try all subarrays and check them.”

But:

There are too many subarrays (about n²)

For large n, this is far too slow

So we need a smart counting method, not brute force.

Key Intuition (Most Important Part)

Instead of thinking like this:

“Which subarrays are valid?”

We think like this:

“If I fix the starting point of a subarray, how far can I extend it to the right?”

This idea changes everything.

Step 1: Fix the Left Boundary

Suppose we fix the left index i.

Now the subarray looks like:

[a[i], a[i+1], ..., a[j]]


Our job is to find all valid j such that:

The subarray has exactly k distinct numbers

The length (j - i + 1) is between l and r

Step 2: Why We Use Two Sliding Windows

To handle exactly k distinct numbers, we use two windows:

Window X (exactly k distinct)

We extend it until the subarray first reaches k distinct numbers

This gives us the earliest possible right end

Window Y (at most k distinct)

We extend it as far as possible without exceeding k distinct numbers

This gives us the latest possible right end

All valid subarrays starting at i must end between these two points.

This is the core idea.

Step 3: Add the Length Constraint

Even if a subarray has exactly k distinct numbers, it is invalid if:

It is too short (< l)

Or too long (> r)

So for a fixed i:

Valid j must be in

[i + l - 1 , i + r - 1]

Step 4: Count Using Range Intersection

Now we have two ranges for the right endpoint j:

From the distinct-number condition

[x , y - 1]


From the length condition

[i + l - 1 , i + r - 1]


Only the intersection of these two ranges is valid.

So the number of valid subarrays starting at i is:

max(0, min(y - 1, i + r - 1) - max(x, i + l - 1) + 1)


This counts how many j values work — without looping!

Step 5: Slide the Left Boundary

After counting subarrays starting at i:

Move i one step to the right

Remove a[i] from both windows

Update distinct counts if needed

Repeat this until i reaches the end of the array.

Each element enters and leaves the windows only once.

Simple Example

Array:

[1, 2, 1, 2, 3]


Let:

k = 2, l = 2, r = 3


For i = 1:

Exactly k distinct numbers appear starting at index 2

They stop being valid after index 4

Length constraint allows indices [2, 3]

So valid subarrays:

[1,2], [1,2,1]


The same logic repeats for every i.

Final Decision Rule (Summary)

For each starting index i:

Find the earliest right index where distinct numbers become k

Find the latest right index where distinct numbers are still ≤ k

Intersect this range with the allowed length range [l, r]

Add the number of valid endpoints to the answer

Move i forward and update the windows

Time Complexity

Each pointer moves only forward

Each element is processed a constant number of times

Total time: O(n)
Extra space: O(n) (for frequency tracking)
