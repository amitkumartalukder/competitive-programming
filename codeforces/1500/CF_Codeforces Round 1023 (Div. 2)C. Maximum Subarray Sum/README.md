Problem Recap

You are given:

An array a of length n

A binary string s of the same length

A number k

Rules:

If s[i] = 1, then a[i] is fixed and cannot be changed.

If s[i] = 0, then a[i] is missing and you are allowed to fill it with any value (up to ±10^18).

The maximum subarray sum of the final array must be exactly k.

Your task:

Decide if it is possible.

If yes, output one valid filled array.

Key Intuition (Why the solution works)

The most important idea is this:

The maximum subarray sum comes from one “best” continuous segment.
If we can control that segment, we can control the answer.

So the strategy is:

Make sure no forced (fixed) segment already exceeds k.

Block all missing positions so they cannot accidentally create a larger sum.

Carefully choose exactly one missing position and assign it a value so that the maximum subarray sum becomes exactly k.

This avoids complicated case analysis and keeps everything under control.

Step 1: Handle the Easy Case (No Missing Positions)

If all positions are fixed (s contains only 1):

We cannot change anything.

We simply compute the maximum subarray sum using a standard scan.

If it equals k, answer is YES.

Otherwise, NO.

This is straightforward.

Step 2: Block All Missing Positions

Now assume there is at least one s[i] = 0.

We do this:

Replace every missing position with a very large negative number (for example -10^13).

Why?

Any subarray that includes this value becomes very small.

So missing positions cannot accidentally help form a large subarray.

This lets us safely analyze only the fixed parts.

We also remember one missing position, call it pos.
We will later “fix” only this one.

Step 3: Check If the Answer Is Impossible

After replacing missing positions with large negatives:

Compute the maximum subarray sum of this modified array.

Two impossible cases:

If this maximum is greater than k
→ impossible, because fixed values already exceed k.

If this maximum is not equal to k and there is no missing position
→ impossible, because we cannot adjust anything.

If neither happens, we can continue.

Step 4: Build the Exact Maximum Subarray Using One Missing Position

At this point:

All missing positions are large negatives.

So the only way to get a subarray with sum k is to include pos.

Now we calculate:

left_max: the best sum you can get by extending to the right of pos

right_max: the best sum you can get by extending to the left of pos

Both are found by simple scans.

We want:

right_max + a[pos] + left_max = k


So we set:

a[pos] = k - left_max - right_max


This guarantees:

There is one subarray with sum exactly k

No other subarray can exceed k (because all other missing spots are blocked)

Step 5: Output the Result

Print YES

Print the final array

That’s it.

Simple Example

Input:

n = 3, k = 5
s = 101
a = [2, 0, 2]


Steps:

Replace 0 with -INF → [2, -INF, 2]

Best fixed subarray = 2

Choose pos = 1

left_max = 2, right_max = 2

Set a[1] = 5 - 2 - 2 = 1

Final array:

[2, 1, 2]


Maximum subarray sum = 5.

Final Decision Rule (Summary)

If fixed values already force a subarray sum greater than k → NO

Otherwise:

Block all missing positions with a large negative value

Pick one missing position

Assign it a value so the best subarray becomes exactly k

→ YES

Time Complexity

Each test case is processed in O(n) time.

Memory usage is linear.
