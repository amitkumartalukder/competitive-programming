1. Problem Recap:

You are given:

An array of n numbers.

q queries.
Each query gives a range [l, r] and asks for the sum of elements from index l to r.

Before answering the queries, you are allowed to reorder (shuffle) the array once.

Your goal:

Reorder the array in such a way that the total sum of all query answers is as large as possible.

You only need to output that maximum possible total sum.

2. Key Intuition (the most important idea)

Think about this carefully:

Some positions in the array are used many times in queries.

Some positions are used very few times.

If a position is included in many queries,
then the number placed at that position will be added again and again.

So the main idea is:

Put big numbers in positions that are used many times,
and small numbers in positions that are used few times.

This single idea explains why the solution works.

3. Step-by-Step Thinking
Step 1: How important is each index?

For every index i (from 1 to n), we want to know:

How many queries include index i?

Let’s call this number the frequency of index i.

If freq[i] = 5, index i is counted in 5 different queries.

If freq[i] = 0, index i does not matter at all.

Step 2: Counting frequencies efficiently

Directly increasing all indices inside every query would be too slow.

Instead, we use a smart trick:

For a query [l, r]:

Increase freq[l] by 1 (start counting)

Decrease freq[r + 1] by 1 (stop counting)

After processing all queries, we take a prefix sum of freq.

Now:

freq[i] tells us exactly how many queries include index i.

No heavy math — just careful counting.

Step 3: Why sorting helps

At this point we have:

The original numbers in the array.

A frequency value for each index.

To maximize the total sum:

The largest number should go to the largest frequency.

The second largest number goes to the second largest frequency, and so on.

So we:

Sort the array values.

Sort the frequency array.

Multiply them index by index and add everything.

This greedy pairing guarantees the maximum possible sum.

4. Small Example

Suppose:

Array values:      [5, 3, 2]
Index frequencies: [3, 2, 1]


Best pairing:

5 × 3
3 × 2
2 × 1


Why?

5 contributes the most, so it should be used the most.

2 contributes the least, so it should be used the least.

Any other pairing gives a smaller total.

5. Final Decision Rule (easy to remember)

Count how many times each index is used.
Sort indices by usage, sort numbers by value,
and pair big with big, small with small.

That’s it.

6. Time Complexity

Processing queries with difference array: O(n + q)

Sorting values and frequencies: O(n log n)

Overall complexity:

O((n + q) log n)


This easily fits within the limits.
