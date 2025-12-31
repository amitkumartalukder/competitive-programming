# Rectangle Filling — Concept Explained (Beginner Friendly)

This repository documents the **full idea and intuition** behind the
*Rectangle Filling* problem from competitive programming.

The focus here is **not just the code**, but **why the solution works**.

---

##  Problem Recap (Rules Only)

You are given an `n × m` grid.
Each cell is either:

- `W` → White  
- `B` → Black  

### Allowed Operation

In one operation:

1. Pick **any two cells of the same color**
2. Treat them as **opposite corners of a rectangle**
3. Color **every cell inside that rectangle** with that same color

You can perform this operation **any number of times (or zero times)**.

---

##  What Is the Goal?

To decide whether it is possible to make **all cells of the grid the same color**
(either all White or all Black).

---

##  Key Intuition (Most Important Part)

At first glance, the problem looks complex because:
- The grid can be large
- There are many possible rectangles
- Colors can change multiple times

But the **key realization** is this:

> **Operations can only expand a color inside rectangles —  
> they can never break a fully uniform boundary.**

So instead of thinking about *all rectangles*,  
we only need to think about the **edges of the grid**.

---

##  Why Do Edges Matter?

Look at these two situations:

### Case A — Top and Bottom Rows

- If the **entire top row** is one color
- And the **entire bottom row** is another color
- And those two colors are **different**

Then no operation can ever change that.

Why?

- Any rectangle that touches the top row keeps it the same color
- Any rectangle that touches the bottom row keeps it the same color
- You can never make both rows match

So the grid is **permanently blocked**.

---

### Case B — Left and Right Columns

The exact same logic applies if:

- The **entire left column** is one color
- The **entire right column** is another color
- And they are different

Again, the grid is blocked forever.

---

##  What About All Other Cases?

If the grid is **not blocked by opposite sides**, then:

- There is always at least one rectangle that can expand a color
- That expansion unlocks larger rectangles
- Eventually, one color can dominate the whole grid

Even grids that look impossible (like checkerboard patterns)
can be solved if the edges are not fully blocking.

---


