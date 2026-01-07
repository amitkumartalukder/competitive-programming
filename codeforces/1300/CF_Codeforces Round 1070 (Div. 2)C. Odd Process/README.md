Problem Recap 

You are given some coins.
Each coin has a number written on it.

You also have a bag, which starts empty.

You must perform exactly k actions:

In each action, you pick one unused coin and put it into the bag.

 There is a catch:

Whenever the total sum of coins in the bag becomes even, the bag is immediately emptied.

This can happen at any moment, not only at the end.

 Your score is the sum of coins left in the bag after all k actions.

Your task:

For every k = 1 … n, find the maximum possible final score.

Key Intuition 
 The cat only cares about parity (odd or even)

The actual values of coins don’t matter at first.
What matters is whether the total sum is odd or even.

Important facts:

If the sum is even → bag is emptied → score becomes 0

If the sum is odd → bag survives → score is kept

So the entire game is about keeping the sum odd at the end.

Crucial Observation

The parity of the sum depends on how many odd coins are in the bag:

Number of odd coins	Total sum
Odd	Odd (safe)
Even	Even  (bag empties)

Final rule:
To survive, the bag must contain an odd number of odd coins.

Step 1: Split the Coins

We separate the coins into two groups:

odd → all coins with odd values

even → all coins with even values

Why?

Even coins do not change parity

Odd coins flip parity

Step 2: How Do We Build a Safe Bag?
Case 1: No odd coins at all

Any sum of even numbers is even

The bag will always be emptied

Answer for all k is 0

Case 2: At least one odd coin exists

This is the interesting part.

Safe strategy

Start with one odd coin
→ sum becomes odd → safe start

Add as many even coins as possible
→ odd + even = odd → still safe

When even coins are finished:

We are forced to use odd coins

Adding odd coins can break parity

Why Do We “Reset” Using Odd Coins?

If we add two odd coins together:

odd + odd = even → bag empties (reset)

This sounds bad, but it’s actually useful.

Why?

Extra odd coins don’t help increase value

They only help control parity

We use small odd coins to “burn” (sacrifice)

We protect the largest odd coin to maximize score later

This controlled reset allows us to:

Remove one previously added even coin’s effect

Restore a safe odd state afterward

Step-by-Step Idea (Simplified)

For each k = 1 … n:

Try to use:

1 odd coin

(k − 1) even coins, if possible

If even coins run out:

Use two odd coins to reset parity

This may reduce usable even coins by 1

At the end:

If the number of odd coins used is odd → bag survives

If it’s even → bag empties

Small Example

Coins:

odd  = [1, 3, 5]
even = [4, 2]

k = 1

Take 5 → sum = 5 (odd) → score = 5

k = 2

Take 5, 4 → sum = 9 (odd) → score = 9

k = 3

Take 5, 4, 2 → sum = 11 (odd) → score = 11

k = 4

Need an odd coin → parity breaks → bag empties → score = 0

Final Decision Rule (Clean Summary)

For each k:

If no odd coin exists → answer is 0

Otherwise:

Keep exactly one large odd coin

Add as many large even coins as possible

Use extra odd coins only to fix parity

If final number of odd coins is odd → output the sum

Else → output 0

Time Complexity

Sorting coins: O(n log n)

Processing all k: O(n)

Efficient enough for large inputs.
