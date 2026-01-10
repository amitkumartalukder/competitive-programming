1. Problem Recap 

You are given two arrays:

a — flowers available on the road (in order)

b — flowers you must collect in order

Rules:

You walk through a from left to right.

To collect flower b[i], you must find some a[j] ≥ b[i].

Each flower in a can be used only once.

Order matters for b.

You are allowed to insert exactly one new flower (with any beauty value) anywhere in a.

Your task is to find:

0 → if you can already collect all flowers in b

the minimum beauty of the flower you need to insert

-1 → if it is impossible even after inserting one flower

2. Key Intuition (Most Important Part)
Greedy Rule

While walking through a:

If the current flower in a is good enough for the next required flower in b, you should take it immediately.

Why this greedy choice is correct:

Taking a valid flower early never blocks future choices

Skipping a valid flower can only make things worse

You never benefit from waiting if you can already collect the current target

So the behavior of the problem is fully determined by this greedy matching.

3. First Check: Do We Need to Insert Anything?

Before thinking about insertion:

Run the greedy process on a and try to collect all of b

If you succeed → answer is 0

This is the simplest and best case.

4. Insertion Trick: Think in Reverse

Inserting one new flower into a has a powerful effect:

You can place it anywhere

You can use it exactly once

It can help you satisfy one missing requirement from b

That means:

Inserting one flower is equivalent to deleting one flower from b.

Why this works:

If you delete b[i], the inserted flower can replace it

Order of the remaining flowers stays the same

So instead of inserting, we try deleting one flower from b

Now the problem becomes:

Is there some flower in b that we can delete so that the remaining flowers can be collected using greedy?

5. Why Brute Force Is Too Slow

A slow idea would be:

For each position i in b:

Delete b[i]

Run greedy on a

Pick the minimum valid b[i]

This would be too slow because greedy itself is linear, and we would repeat it many times.

We need a faster way.

6. Prefix Greedy: What Can We Do Early?

We create an array pre:

pre[i] = the index in a where we finish collecting b[0..i] using greedy

If we cannot collect b[i], pre[i] becomes invalid

How we compute it:

Use two pointers

Walk through a once

Match b greedily from left to right

This tells us how early we can collect the first part of b.

7. Suffix Greedy: What Can We Do Late?

We also create an array suf:

suf[i] = the index in a from where we can start and still collect b[i..end]

Computed from right to left

How we compute it:

Walk through a from the end

Match b backwards using greedy

This tells us how late we can start collecting the remaining part of b.

8. When Is It Safe to Delete a Flower?

Suppose we want to delete b[i].

We need:

The part before it (b[0..i-1]) to be collected before

The part after it (b[i+1..end]) to be collected after

And these two parts must not overlap in a

That gives a simple condition:

pre[i-1] < suf[i+1]


Edge cases:

If i = 0, only the suffix matters

If i = last, only the prefix matters

If this condition is true, deleting b[i] works.

9. Choosing the Best Flower to Delete

Now we:

Try deleting each b[i]

Check if the condition holds

Among all valid deletions, pick the minimum value of b[i]

If none work → answer is -1.

10. Final Decision Rule

If greedy on full b works → print 0

Else:

Try deleting each b[i]

If pre[i-1] < suf[i+1], it is valid

Take the minimum such b[i]

If no valid deletion exists → print -1

11. Time Complexity

Prefix greedy: O(n)

Suffix greedy: O(n)

Final scan: O(m)

Total per test case: O(n + m)
Efficient enough for large inputs.
