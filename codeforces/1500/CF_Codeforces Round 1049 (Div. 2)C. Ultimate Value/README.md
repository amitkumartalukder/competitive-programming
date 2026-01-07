 Problem Recap (Rules in Simple Words)

You are given an array a of length n.

We define a value:

f(a) = cost + (a1 − a2 + a3 − a4 + ... )


cost starts at 0

The alternating sum is:

add elements at odd positions

subtract elements at even positions

 The Game

Alice and Bob play a game, Alice goes first

On each turn, a player can:

End the game, or

Swap two positions l and r

This adds (r − l) to cost

Goals

Alice wants to maximize f(a)

Bob wants to minimize f(a)

Both play optimally

Your task is to find the final value of f(a).

 Key Intuition (Most Important Part)

The most important observation is this:

Bob never wants to swap. He will always end the game.

Why?

If Bob swaps, Alice can undo or improve it on her next turn

Any swap Bob makes only helps Alice in the long run

So the game effectively becomes:

Alice can make at most ONE swap.
Bob will immediately end the game after that.

This simplifies the entire problem.

 What Can Alice Do?

Alice has three possible choices:

Do nothing

End the game immediately

Final value = initial alternating sum

Swap two positions with the same parity

odd ↔ odd or even ↔ even

Alternating sum stays the same

Only cost increases

Swap one odd position with one even position

This changes both:

the alternating sum

the cost

Alice will choose the option that gives the maximum final value.

Case 1: No Swap

Very simple.

Just compute:

a1 − a2 + a3 − a4 + ...


This is the baseline answer.

Case 2: Same Parity Swap (Odd–Odd or Even–Even)
Why does this help?

Swapping two odd positions:

both were added before

still added after

Same for even positions

So:

Alternating sum does not change

Only cost increases

Since:

f(a) = alternating_sum + cost


Increasing cost is always good for Alice.

Best Strategy Here

To maximize cost:

Pick the two farthest positions with the same parity

That gives the largest distance, hence the largest cost.

This can be computed in O(1).

Case 3: Odd–Even Swap (The Interesting One)

This is where most of the logic lives.

What happens when Alice swaps:

an odd index j

with an even index i

Two things happen:

Alternating sum changes

the odd value moves to an even position (now subtracted)

the even value moves to an odd position (now added)

Cost increases

by |i − j|

So Alice gains:

gain = (change in alternating sum) − distance

Key Insight

Alice wants:

a large value to move into an odd position

a small value to move into an even position

but not too far apart (distance hurts)

This is a balance between:

value difference

index distance

How Do We Compute This Efficiently?

Instead of checking all pairs (which would be too slow), we:

Scan the array once from left to right

Keep track of:

the best odd position seen so far

the best even position seen so far

At each index:

Try forming a swap with the opposite parity

Update the maximum possible gain

This works because:

we only need the best candidate so far

worse candidates will never beat a better one later

Final Decision Rule

After checking all cases:

Compute the initial alternating sum

Compute:

best value with no swap

best value with same-parity swap

best value with odd–even swap

Take the maximum of all three

That is the final value of f(a).

Time Complexity

Each test case is solved in O(n)

Only simple loops and constant extra memory

Works efficiently within the given limits
