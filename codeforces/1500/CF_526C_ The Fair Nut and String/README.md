Problem Recap :

You are given a string s made of lowercase letters.

You want to choose some positions (indices) from the string such that:

You only choose positions where the character is 'a'.

The chosen positions must be strictly increasing (left to right).

If you choose more than one 'a', then between every two chosen 'a' positions, there must be at least one 'b' in the string.

A single 'a' by itself is always valid.

Your task is to count how many such valid sequences are possible.

The answer must be printed modulo 10⁹ + 7.

Key Intuition (The Most Important Insight)

The most important thing to realize is this:

The positions of 'a' are what we choose,
but the positions of 'b' decide which 'a' can be together.

A 'b' acts like a separator.

If two 'a' characters have no 'b' between them, they cannot both be chosen.

If there is a 'b' between them, they can be chosen together.

So instead of thinking about all combinations of 'a', we should think about how 'b' splits the string.

Step 1: Split the String Using 'b'

Look at the string and split it at every 'b'.

Example:

s = a b a b a a


Split by 'b':

[a] | [a] | [a a]


Each part is a block of consecutive 'a' characters.

Let’s say the block sizes are:

[1, 1, 2]

Step 2: What Can We Choose from One Block?

Inside one block, there is no 'b'.

So:

You cannot choose two 'a' from the same block.

You can choose:

0 'a' from the block

exactly 1 'a' from the block

If a block has c 'a' characters:

Choosing none → 1 way

Choosing one → c ways (you can pick any one of them)

So for that block, total choices:

(1 + c)

Step 3: Combine All Blocks

All blocks are independent of each other.

So we multiply the choices of all blocks.

Example:

block sizes = [1, 1, 2]


Choices:

(1+1) × (1+1) × (1+2)
= 2 × 2 × 3
= 12

Step 4: Remove the Empty Case

One of those combinations means:

You chose nothing from every block

That corresponds to an empty sequence, which is not allowed.

So we subtract 1.

Final Answer = product of (1 + block_size) − 1

Simple Example Walkthrough
Example
s = a b a b a a


Blocks:

[a] [a] [a a]


Block sizes:

[1, 1, 2]


Calculation:

(1+1)(1+1)(1+2) − 1
= 2 × 2 × 3 − 1
= 11


So there are 11 valid sequences.

Final Decision Rule (Summary)

Split the string by 'b'.

For each block of consecutive 'a' with size c, count (1 + c) choices.

Multiply all these values.

Subtract 1 to remove the empty selection.

Take the result modulo 10⁹ + 7.

Time Complexity

We scan the string once.

Each character is processed in constant time.

Time Complexity: O(n)
Space Complexity: O(1) (only counters)
