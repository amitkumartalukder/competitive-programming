Problem Recap 

You have n flower pots in a row.

Each pot is either:

1 → has a flower

0 → empty

You must put a rabbit in every empty pot (0).

Each rabbit must look either left or right.

 Rabbit behavior

A rabbit wants to jump to the next pot in the direction it looks, but it will NOT jump if:

The next pot already has a rabbit, or

Another rabbit is also trying to jump into that same pot, or

The jump would go outside the row.

Your goal: choose directions so that no rabbit ever jumps.

Key Intuition (the most important idea)

The problem is not about simulating jumps.

It is about finding dangerous patterns where rabbits cannot be stopped, no matter how you choose directions.

Most arrangements are actually safe.
Only very specific patterns force a rabbit to jump.

So instead of thinking about every rabbit, we focus on patterns in the string.

First Observation: Some positions are harmless
1️ Zeros at the boundary are always safe

If the string starts or ends with 0:

That rabbit can look outside

So it will never jump

 Boundary zeros can be ignored.

 Second Observation: 11 splits the problem

If you see:

11


That means two flower pots together.

Rabbits on the left side cannot interact with rabbits on the right side.

So the problem splits into independent segments.

We can solve each segment separately.

Third Observation: When is a segment dangerous?

After splitting by 11, look at one segment.

There are two cases:

Case 1: The segment contains 00

Example:

100101


Two rabbits are already next to each other.

They block movement naturally.

This segment is always safe.

 Case 2: Pure alternating segment (no 00)

Example:

10101


This pattern alternates strictly between 1 and 0.

Now the rule is very simple:

Count how many 0 (rabbits) are in this segment.

If the number of 0 is odd →  NO

If the number of 0 is even → YES

Why?

Because rabbits can only block each other in pairs.
An odd rabbit is left unblocked and must jump.

 Small Examples
Segment	Zeros	Result	Reason
010	1	 NO	Odd rabbit, no block
0101	2	 YES	Rabbits pair up
00101	3	YES	00 makes it safe
101	1	 NO	Pure alternating + odd
 Step-by-Step Logic (High Level)

Ignore boundary zeros (they are safe).

Split the string at every 11.

For each segment:

If it has 00 → safe.

Else (pure alternating):

If number of 0 is odd → answer is NO.

If all segments are safe → YES.

Final Decision Rule

The answer is NO if and only if there exists a segment (after splitting by 11) that:

has no 00, and

contains an odd number of 0.

Otherwise, the answer is YES.

Time Complexity

Each test case is scanned once.

Time complexity: O(n) per test case.

Efficient for large inputs.
