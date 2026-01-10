Problem Recap

You are given:

An array a of length n

A number k

Your task is to:

Split the array into exactly k non-overlapping contiguous subarrays

For each subarray, compute its MEX

Take the minimum MEX among all subarrays

Maximize that minimum value

What is MEX?

The MEX (Minimum Excluded Number) of an array is:

The smallest non-negative integer that does not appear in the array.

Examples:

MEX([0,1,2]) = 3

MEX([1,2]) = 0

MEX([0,2]) = 1

Key Intuition (Why this problem works this way)

Instead of directly trying all possible splits (which is impossible for large n), we change the question.

Instead of asking:

“What is the best split?”

We ask:

“Is it possible to make the minimum MEX at least x?”

If we can answer this yes or no efficiently, we can find the maximum possible x.

Important Observation 1: What does “minimum MEX ≥ x” mean?

If the minimum MEX is at least x, then:

👉 Every one of the k subarrays must contain all numbers

0, 1, 2, ..., x-1


Because:

MEX is the smallest missing number

If any subarray misses one of these, its MEX becomes smaller than x

So the requirement is very strict.

Important Observation 2: Order matters

Even if the array contains many 0s and 1s globally,
we still may fail, because:

Subarrays must be contiguous

You cannot rearrange elements

You must pick them in the given order

So we must check feasibility by scanning the array from left to right.

The Core Idea

We solve the problem in two layers:

Layer 1: Binary Search on the answer

The answer (maximum minimum MEX) lies between 0 and n

If value x is possible, then all values < x are also possible

If value x is not possible, then all values > x are also impossible

This “possible / impossible” behavior allows binary search.

Layer 2: How to check if a value x is possible

We simulate the process greedily.

Goal of the check:

Can we form at least k subarrays, each containing:

0, 1, 2, ..., x-1

How we do it:

Traverse the array from left to right

Keep track of which numbers < x we have seen

Once we have seen all required numbers, we:

Count one valid subarray

Reset tracking

Continue from the next position

At the end:

If we formed k or more subarrays → x is valid

Otherwise → x is not valid

We always cut as early as possible.
This greedy choice gives the maximum number of valid subarrays.

Simple Example
Array: [0, 2, 1, 0, 1, 2]
k = 2
Try x = 2


We need each subarray to contain {0,1}.

Scan:

0 → seen

2 → ignore

1 → now have {0,1} → first subarray formed

reset

0 → seen

1 → now have {0,1} → second subarray formed

We got 2 subarrays ⇒ x = 2 is possible.

Why Greedy Works Here

We always close a subarray as soon as it becomes valid

This gives us the maximum number of valid segments

If even this fails to reach k, no other splitting can succeed

Final Decision Rule

To find the answer:

Binary search on x from 0 to n

For each x, check:

Can we greedily split the array into at least k subarrays

Each subarray must contain all numbers 0 to x-1

The largest valid x is the final answer

Time Complexity

Checking one value of x: O(n)

Binary search range: O(log n)
