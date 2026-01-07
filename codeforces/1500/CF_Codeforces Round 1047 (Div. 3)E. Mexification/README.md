Problem Recap:

You are given:

An array a of size n

An integer k (number of operations)

One operation works like this:

For every position i at the same time:

Remove a[i] temporarily

Find the MEX of the remaining elements

Replace a[i] with that MEX

MEX = the smallest non-negative integer that does not appear in the array.

After doing this operation k times, you must output the sum of the final array.

Key Intuition (Why this problem becomes easy)

At first glance, k can be very large (up to 10⁹), so simulating every operation seems impossible.

The key insight is:

This operation destroys most of the array’s structure very quickly.
After at most 2 operations, the array either stops changing or starts repeating in a simple pattern.

So instead of worrying about large k, we only need to understand:

What happens in one operation

What happens after repeating it a few times

Understanding One Operation

Let:

m = MEX of the current array

freq[x] = how many times value x appears

Now look at one element a[i]:

Case 1: a[i] < m and appears exactly once

When you remove it, that number disappears

So it becomes the new MEX

It stays the same

Case 2: Any other situation

This includes:

a[i] > m

or a[i] < m but appears more than once

In these cases:

Removing a[i] does not change the fact that m is missing

It becomes m

Simple Rule for One Operation

Only numbers smaller than MEX and appearing exactly once survive.
Everything else turns into MEX.

First Big Observation: Permutation Case

If the array is exactly:

[0, 1, 2, ..., n-1]   (each value appears once)


Then:

MEX = n

Every number is < MEX and appears once

So nothing ever changes

If the array is a permutation, the answer is simply the original sum.

 What If the Array Is NOT a Permutation?

This is where the magic happens.

After applying the operation once:

Most values collapse into the MEX

The array becomes much simpler

After applying it again:

One of two things happens:

The array becomes a permutation → stops forever

The array starts bouncing between two fixed states

It is guaranteed that after at most 2 operations, the behavior is fixed.

This means:

There is no need to simulate more than 2 operations

Large k does not matter anymore

Small Example
Example:
a = [0, 0, 1, 1]


MEX = 2

After 1 operation:

[2, 2, 2, 2]


After 2 operations:

[0, 0, 0, 0]


From now on, it just alternates between these states.

Final Decision Rule (Very Important)

If the array is a permutation

It never changes

Answer = sum of original array

Otherwise

You only need to simulate:

min(k, k % 2 + 2)


operations (this is at most 2)

After that, the array is already stable or cycling

Compute the sum of the resulting array

Time Complexity

Each operation takes O(n)

We do at most 2 operations

Total per test case: O(n)
