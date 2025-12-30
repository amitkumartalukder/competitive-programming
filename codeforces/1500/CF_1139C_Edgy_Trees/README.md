Problem Recap 

You are given a tree with n nodes.

Every edge is either red or black.

You also get a number k.

You need to look at all possible sequences of nodes of length k:

[a1, a2, a3, ..., ak]


For each sequence:

Start at a1

Go to a2, then a3, ..., finally ak

Every move is done using the only possible path in the tree

A sequence is called GOOD if:

👉 During the whole walk, you pass at least one black edge

Your task:

Count how many sequences are GOOD
(Answer can be large, so output modulo 1e9+7)

Key Intuition (The Most Important Idea)

Instead of directly counting good sequences, we do something smarter:

💡 Count total sequences first

Then subtract the bad ones

Why?

Total sequences are easy to count

Bad sequences have a very clear structure

So:

GOOD = TOTAL − BAD

What Is a BAD Sequence?

A sequence is BAD if:

While following the sequence,

You never walk through a black edge

That means:
👉 The entire walk uses only red edges

Important Observation (Core Insight)

Let’s imagine this:

✂️ Remove all black edges from the tree

What remains?

The tree breaks into several separate groups

Inside each group, all connections are red only

These groups are called:

Red-only connected components

Very important rule:

If all nodes in a sequence come from the same red-only component,
then the sequence is BAD

Why?

Moving between any nodes inside that component uses only red edges

No black edge is ever touched

Step-by-Step Solution Logic
Step 1: Count Total Sequences

For each position in the sequence:

You can choose any of the n nodes

Sequence length is k

So:

TOTAL = n^k

Step 2: Find Red-Only Components

Ignore all black edges

Use DFS/BFS with only red edges

Each DFS gives one red-only component

Let its size be sz

Step 3: Count BAD Sequences

If a red component has sz nodes:

Each position in the sequence has sz choices

Total bad sequences from this component:

sz^k


Add this for all red components:

BAD = sz1^k + sz2^k + sz3^k + ...

Step 4: Final Answer
GOOD = TOTAL − BAD


Make sure to apply modulo properly.
