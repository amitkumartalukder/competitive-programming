1. Problem Recap:

You are given an array b of size n.

Your task is to check whether there exists another array a (also of size n) such that:

For every position i
the value b[i] equals
the number of times a[i] appears in the entire array a

Formally:

b[i] = number of occurrences of a[i] in array a


If such an array a exists, construct and print it.
If it is impossible, print -1.

2. Key Intuition (Why the problem behaves this way)

The most important idea is this:

If a value appears x times in array a,
then every position containing that value must have b[i] = x.

So:

One number in a always has one fixed frequency

You cannot have the same number appearing with different required frequencies

This forces us to group positions by their b[i] values.

3. Crucial Observation (The heart of the solution)

Let’s focus on one number x.

Suppose b[i] = x

That means the value placed at position i must appear exactly x times in a

Now ask:

How many positions in b have value x?

Call this count cnt.

To satisfy the rule:

Every group of x positions can share one number

So cnt must be divisible by x

Important Rule
If count of x in b is NOT a multiple of x,
then the answer is impossible.


This is the only validity check needed.

4. Simple Example to Understand This
Example 1 (Impossible)
b = [2, 2, 2]


2 appears 3 times

But 3 is NOT divisible by 2

You cannot split 3 positions into groups of size 2.

Answer: -1

Example 2 (Possible)
b = [2, 2, 2, 2]


2 appears 4 times

4 is divisible by 2

You can create two groups:

a = [1, 1, 2, 2]


Each number appears exactly 2 times — valid.

5. Step-by-Step Construction Idea

Once the validity rule passes, building the array is straightforward.

Step 1: Group positions by b[i]

For every value x, collect all indices i where b[i] = x.

Step 2: Assign values group by group

Keep a variable z = 1 (this is just a label for new numbers)

For a value x:

Take its positions

Split them into chunks of size x

For each chunk:

Assign the same value z to all positions in that chunk

Increase z by 1

Each assigned number appears exactly x times — which is what we want.

6. Walkthrough Example
b = [1, 2, 2, 3, 3, 3]


Groups:

1 → 1 position
2 → 2 positions
3 → 3 positions


Construction:

value 1 → [1]
value 2 → [2, 2]
value 3 → [3, 3, 3]


Result:

a = [1, 2, 2, 3, 3, 3]


Check:

1 appears once → OK

2 appears twice → OK

3 appears three times → OK

7. Why This Always Works

Every value assigned to a appears exactly as many times as required

No position gets a conflicting frequency

The construction follows directly from the definition of the problem

There is no guessing involved — it is a direct, safe construction.

8. Final Decision Rule

For each value x in array b:

If count(x) % x != 0
→ print -1

Otherwise:

Split its positions into groups of size x

Assign a new number to each group

If all values pass the check, the constructed array is guaranteed to be valid.

9. Time Complexity

Grouping positions: O(n)

Construction: O(n)

Overall Complexity: O(n)

Efficient enough for large inputs.
