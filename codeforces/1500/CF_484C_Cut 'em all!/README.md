Problem Recap 

You are given a tree with n nodes.

A tree means:

All nodes are connected

There are exactly n − 1 edges

There are no cycles

You are allowed to remove (cut) some edges.

Your goal:

Remove as many edges as possible so that every remaining connected component has an even number of nodes.

Output:

Print the maximum number of edges you can remove

Print -1 if it is impossible

 Key Intuition (Most Important Idea)
 First and most important observation:

If the total number of nodes n is odd,
then it is impossible to split the tree into only even-sized components.

Why?

Even + Even + Even + ... = Even

You can never add even numbers to get an odd number

So:

If n is odd → answer = -1


This check comes before everything else.

 What Happens When You Cut an Edge?

Cutting one edge in a tree always splits it into two parts.

So for any edge, the question is:

“If I cut this edge, will both parts have an even number of nodes?”

If yes, this edge is a valid cut.
If no, this edge cannot be cut.

 How Do We Know the Size of Each Part?

This is where DFS (Depth First Search) comes in.

Idea:

Choose any node as the root (we use node 1)

Run DFS

For every node, calculate:

How many nodes are in its subtree (including itself)

This value is called subtree size.

🔹 Why Subtree Size Solves the Problem

Consider an edge like this:

parent ---- child


If we cut this edge:

One component = child’s subtree

Other component = rest of the tree

So we only need to check one thing:

Is the child’s subtree size even?

Because:

Total nodes n is already even

Even − Even = Even

So:

Child subtree even → both parts even → valid cut

Child subtree odd → invalid cut

 Step-by-Step Algorithm (Easy Flow)
Step 1: Check total nodes

If n is odd → print -1 and stop

Step 2: Build the graph

Use an adjacency list (because the tree is undirected)

Step 3: Run DFS to compute subtree sizes

For each node:

Start with subtree = 1 (count itself)

Visit all children (except parent)

Add child subtree sizes to subtree

Step 4: Count valid cuts

While returning from DFS:

For every edge parent → child:

If child_subtree_size is even

This edge can be cut

Increase answer count

 Simple Example

Tree:

        1
       / \
      2   3
           \
            4


Subtree sizes:

Node 4 → 1

Node 3 → 2

Node 2 → 1

Node 1 → 4

Valid cut:

Edge 1–3 (subtree size = 2, even)

Invalid cuts:

Any edge leading to subtree size 1

Answer = 1

Final Decision Rule (Core Logic)
1. If total nodes n is odd → answer = -1
2. Else:
   - Run DFS
   - For each edge:
       If child subtree size is even → count this cut
3. Print the count

Time Complexity

DFS visits each node once → O(n)

Edge checks are done during DFS → O(n)
