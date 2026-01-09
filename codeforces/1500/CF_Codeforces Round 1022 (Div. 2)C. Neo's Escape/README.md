Problem Recap:

Neo is stuck in front of a row of n buttons.
Each button has a weight.

Neo cannot move, but he can:

Create clones in front of any button.

Move a clone one step left or right.

Rules:

When a clone reaches a button that has not been pressed yet, the button is pressed immediately.

Each button can be pressed only once.

Neo must press all buttons.

The order of pressed weights must be non-increasing
(each next weight must be less than or equal to the previous one).

Goal

Find the minimum number of clones needed to press all buttons following the rule above.

Key Intuition (Most Important Part)

The entire problem depends on where clones must be created.

The crucial observation is:

A clone can safely move from a bigger weight to smaller weights,
but it is dangerous to move from smaller weights to bigger ones.

Why?

Because buttons are pressed automatically.

If a smaller weight is pressed before a bigger one, the order becomes invalid.

So the real question becomes:

Which buttons cannot be safely reached from any other button without breaking the order?

These buttons force us to create a clone directly there.

Step 1: Ignore Consecutive Equal Buttons

If several buttons with the same weight are next to each other, they do not change the answer.

Example:

5 5 5 3 3 7


Behaves the same as:

5 3 7


Why this is safe:

Pressing 5 → 5 → 5 never breaks the non-increasing rule.

A clone moving across equal values causes no problem.

So first, we compress the array by keeping only one copy of consecutive equal values.

Step 2: Think of the Buttons as Heights

After compression, imagine the array as heights on a line.

Example:

7 8 1 5 9 2


Now focus on positions that are higher than both neighbors.

These are called local peaks.

Example:

7  8  1  5  9  2
   ↑        ↑


Here:

8 is higher than 7 and 1

9 is higher than 5 and 2

Step 3: Why Each Peak Needs Its Own Clone

Consider a peak like this:

smaller < PEAK > smaller

Why can’t we reach a peak from somewhere else?

To reach it, a clone must pass through a smaller button first.

That smaller button would be pressed before the peak.

This would cause the sequence to increase (small → big), which is invalid.

So:

Every peak must have a clone created directly on it.

There is no other safe way to press it.

Step 4: Why Other Buttons Do NOT Need New Clones

If a button is not a peak, then:

At least one neighbor is greater than or equal to it.

That neighbor can be pressed first.

Then a clone can safely move downward to this button.

Since moving from larger to smaller values is always safe:

No extra clone is needed for non-peak buttons.

Also:

Once a button is pressed, clones can return to it freely.

Revisiting pressed buttons never causes problems.

Final Decision Rule

After removing consecutive equal values:

Count how many elements are strictly greater than both their left and right neighbors.

That count is the minimum number of clones needed.

Edge cases:

If the array has only one element → answer is 1.

The first or last element is a peak if it is greater than its only neighbor.

Time Complexity

Compressing consecutive equals: O(n)

Scanning to count peaks: O(n)
