
Problem Recap 

You are given two numbers l and r.

Create two arrays:

b = [l, l+1, l+2, ..., r]

a initially has the same numbers, but you are allowed to reorder a

Your task is to reorder a so that the following value is as large as possible:

(a[0] | b[0]) + (a[1] | b[1]) + ... + (a[n-1] | b[n-1])


Here | means bitwise OR.

You must output:

The maximum possible sum

One valid reordered array a

key Intuition (The Most Important Part)

Let’s focus on one position i.

We want (a[i] | b[i]) to be as large as possible.

When does OR become maximum?

For two numbers x and y:

If they do not share any 1 bits (i.e. x & y = 0)

Then:

x | y = x + y   (this is the best possible case)


So the main goal becomes:

For every index i, choose a[i] such that
a[i] and b[i] have no common set bits

If we achieve this everywhere, the total OR sum becomes maximal.

How Do We Guarantee No Common Bits?

This is where the main trick comes in.

Idea: Use a “bitwise complement” under a mask

Take a number like:

mask = 1, 3, 7, 15, 31, ...


(these numbers look like 111...1 in binary)

For any index i, consider:

a[i] = mask - i


Because mask has all bits set, i and mask - i become bitwise opposites.

That means:

i & (mask - i) = 0


Perfect! This is exactly what we want.

But There Is a Catch…

Sometimes mask - i:

Goes outside the range [l, r]

Or was already used for another position

When that happens, we simply:

Shrink the mask
(move from 1111 → 111 → 11 → 1)

Shrinking the mask means:

We use fewer bits

But the “no shared bit” property still holds

Step-by-Step Algorithm
Step 1: Build the initial mask

Start with mask = 1

Keep expanding it until mask >= r

This gives the largest useful “all-ones” number

Step 2: Assign values from right to left

We process indices from r down to l.

For each i:

Try candidate = mask - i

If:

candidate < l or candidate > r, or

candidate was already used
→ shrink the mask

Once valid:

Set a[i] = candidate

Mark it as used

Add (a[i] | i) to the answer

Step 3: Output the result

The computed sum

The array a

Small Example

Input:

l = 0, r = 9


Initial mask = 15 (1111)

Assign from right to left:

i = 9 → a[9] = 6

i = 8 → a[8] = 7

i = 5 → 15 - 5 = 10 (invalid) → shrink mask to 7

i = 5 → a[5] = 2

Final a becomes a valid permutation where:

a[i] & i = 0  for all i


So every OR term is maximized.

Final Decision Rule (Clean Summary)

Start with the largest all-ones bit mask.
For each index i (from right to left), pair it with its complement mask - i.
If the complement is invalid or already used, reduce the mask.
This guarantees no shared bits and achieves the maximum OR sum.

Time Complexity

Time: O(n) (each element processed once)

Space: O(n) (array + used tracking)
