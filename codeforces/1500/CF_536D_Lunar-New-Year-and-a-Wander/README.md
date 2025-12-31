Lunar New Year and a Wander — Concept Explained
Problem Recap

You are given a connected graph with n nodes.

You start at node 1.

You can move using the graph edges.

Every time you visit a node for the first time, you write it down.

You stop when all nodes are visited once.

At the end, you get a sequence of nodes (a permutation of 1..n).

Goal:
Among all possible valid sequences, find the lexicographically smallest one.

What Does “Lexicographically Smallest” Mean?

Think of comparing two sequences like words in a dictionary.

Example:

[1, 4, 3, 2, 5]  <  [1, 5, 2, 3, 4]


Why?

First difference is at position 2

4 < 5, so the first sequence is smaller

So, earlier positions matter more than later ones.

Key Intuition (Most Important Part)

When writing the sequence:

At every step, we should write the smallest-numbered node that we can possibly reach at that moment.

Very Important Observation

This is not a normal DFS or BFS problem.

DFS goes deep on one path and may miss smaller choices elsewhere.

BFS does not care about node values.

But lexicographical order only cares about values.

So the correct question at every step is:

“Among all unvisited nodes that are reachable right now, which one has the smallest value?”

That node must be written next, otherwise the sequence will not be lexicographically smallest.

How Do We Know Which Nodes Are “Reachable Right Now”?

A node is reachable if:

It is connected to any already visited node

Once we visit a node, all its neighbors become reachable candidates.

So we maintain:

A visited set → nodes already written

A candidate set → reachable but not yet visited nodes

Step-by-Step Idea (Logical Flow)
Step 1: Build the Graph

Use an adjacency list

The graph is undirected

Step 2: Start from Node 1

Mark 1 as visited

Add 1 to the answer

All neighbors of 1 become candidates

Step 3: Always Pick the Smallest Candidate

Repeat until all nodes are visited:

From the candidate set, pick the smallest-numbered node

Mark it visited

Add it to the answer

Add all of its unvisited neighbors to the candidate set

This guarantees:

Every next number is as small as possible

Lexicographical order is never violated

Why This Works (Simple Reasoning)

Lexicographical order prioritizes earlier positions

Choosing a bigger number when a smaller reachable number exists is always bad

By always selecting the smallest reachable node:

We make the best possible choice at each position

Future choices cannot fix a bad early decision

So this greedy choice is safe and optimal.

Small Example

Graph connections:

1 - 4
1 - 5
4 - 3
3 - 2


Process:

Start at 1 → answer = [1]
Reachable = {4, 5}

Pick smallest → 4
answer = [1, 4]
Reachable = {3, 5}

Pick smallest → 3
answer = [1, 4, 3]
Reachable = {2, 5}

Pick smallest → 2
answer = [1, 4, 3, 2]

Pick last → 5
answer = [1, 4, 3, 2, 5]

Final Decision Rule (Very Clean Summary)

While there are still unvisited nodes:
Always write the smallest-numbered node that is reachable from already visited nodes.

That single rule defines the whole solution.

Time Complexity

Each node and edge is processed once

Selecting the smallest candidate takes log n time

Overall Time Complexity:

O((n + m) log n)


This is efficient for large graphs.
