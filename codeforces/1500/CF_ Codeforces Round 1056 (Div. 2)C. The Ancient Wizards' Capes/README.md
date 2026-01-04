🧙‍♂️ The Ancient Wizards' Capes — Explained Simply
Problem Recap:

There are n wizards standing in a line, numbered from 1 to n.

Each wizard wears an invisibility cape either on:

Left side, or

Right side.

Harry walks from position 1 to n.

At each position i, Harry counts how many wizards he can see.

You are given an array a where:

a[i] = number of wizards Harry saw at position i.

Visibility Rules

A wizard j is visible from position i if:

Wizard j wears Left cape and i ≥ j

Wizard j wears Right cape and i ≤ j

A wizard always sees himself

Key Intuition (Most Important Part)

The entire problem becomes easy once you notice this:

When Harry moves one step forward (from position i to i+1),
only two wizards can possibly change visibility:

Wizard at position i

Wizard at position i+1

All other wizards stay on the same side of Harry, so their visibility does not change.

This single observation explains everything.

What Does This Mean for the Array a?

Since only two wizards can affect visibility when moving one step:

The number of visible wizards can:

Increase by 1

Decrease by 1

Stay the same

It can never change by more than 1.

First Rule (Validity Check)

If for any i:

|a[i+1] - a[i]| > 1


then no cape arrangement is possible.

Answer is 0 immediately.

Why Differences Matter More Than Absolute Values

Instead of focusing on the exact values of a[i], we look at:

diff = a[i+1] - a[i]


Each difference tells us how wizard i and i+1 must behave.

What Each Difference Means
a[i+1] - a[i]	What happened	Cape relationship
+1	One wizard became visible	Both wear Left
-1	One wizard became invisible	Both wear Right
0	One lost, one gained	They wear different capes

So the array doesn’t directly tell us capes —
it tells us relationships between neighboring wizards.

Step-by-Step Strategy
Step 1: Check If the Array Is Even Possible

Scan the array once:

If any adjacent difference is more than 1 → answer is 0

Step 2: Try the Only Two Possible Starts

Wizard 1 can only be:

Left

Right

Once wizard 1 is fixed, all other wizards are forced by the differences.

So there are at most 2 candidate arrangements.

Step 3: Build the Arrangement (No Guessing)

Move from wizard 1 to n:

Use a[i+1] - a[i] to decide wizard i+1’s cape:

0 → opposite of previous

+1 → Left

-1 → Right

This process is deterministic.

Step 4: Validate Efficiently (Without Recounting Everything)

Instead of recalculating visibility from scratch:

Start with visible count at position 1

Move step by step

Update visibility using only wizard i and i+1

This keeps the check linear time.

Small Example
Input
a = [4, 4, 3, 2]

Differences
0, -1, -1

Meaning

Wizard 1 ≠ Wizard 2

Wizard 2 = Wizard 3 (Right)

Wizard 3 = Wizard 4 (Right)

Try both starts:

Wizard 1 = Left → works

Wizard 1 = Right → fails

Answer
1

Final Decision Rule (Summary)

If any |a[i+1] - a[i]| > 1 → answer = 0

Otherwise:

Try wizard 1 = Left

Try wizard 1 = Right

For each:

Build the forced arrangement

Validate using incremental visibility updates

Count how many are valid

Time Complexity

Each test case is processed in O(n) time

No nested loops

Works efficiently for large inputs
