Symmetrical Polygons — Conceptual Explanation
 Problem Recap :

You are given some sticks, each with a length.

You want to:

Choose some of these sticks (not necessarily all),

Use each chosen stick as one side of a polygon,

Form a polygon that is:

Symmetrical (has a mirror line),

Strictly convex (no flat angles),

Non-degenerate (a real polygon, not a straight line).

Your goal is to make such a polygon with the maximum possible perimeter
(sum of the lengths of its sides).

If it is impossible, output 0.

Key Intuition (the most important idea)

A symmetrical polygon behaves like a mirror.

That means:

Most sides must come in pairs of equal length
(one on the left, one on the right).

At most two sides can lie on the symmetry line itself.

So the whole problem becomes:

How do we choose sticks so that they can be arranged symmetrically
and still form a real polygon?

To maximize the perimeter:

We always want to use as many valid sticks as possible,

But we must never break the geometry rules of polygons.

Very Important Geometry Rule (no heavy math)

A real polygon can exist only if:

No single side is as long as or longer than all the other sides combined.

If one side is too long, everything becomes flat → not a polygon.

We will use this idea again and again.

Step 1: Special Case — n = 3

With exactly 3 sticks, the polygon must be a triangle.

For a valid answer:

The triangle must exist
(two sides together must be longer than the third).

The triangle must be symmetrical
(at least two sides must be equal).

Examples:

5 5 7 → valid (isosceles triangle)

4 5 7 → invalid (scalene, not symmetrical)

So for n = 3, we check these two things directly.

Step 2: Group Equal Sticks (for n > 3)

Now assume n > 3.

We sort the stick lengths and group equal values.

For each length:

Every pair of equal sticks can form mirror sides.

If one stick is left over, it becomes an odd stick
(a possible candidate to place on the symmetry line).

We track:

pair_sum → total length of all paired sticks,

pair_count → how many pairs we have,

odd_list → sticks that appear an odd number of times.

Why pairs matter:

Using all valid pairs always increases the perimeter.

There is no reason to drop a usable mirror pair.

Step 3: Try All Possible Symmetry Configurations

Now we consider how many sticks touch the symmetry line.

Case 1: Symmetry Line Touches 0 Sticks

We use only mirror pairs.

Important detail:

A polygon needs at least 3 sides.

Using only pairs means each pair gives 2 sides.

So we need at least 2 pairs (4 sides).

If that condition is met:

The polygon is symmetrical,

Geometry is safe,

Perimeter = pair_sum.

Case 2: Symmetry Line Touches 1 Stick

We choose one odd stick to place on the symmetry line.

This is valid only if:

That stick is shorter than all paired sticks combined.

Why?

Otherwise, that single stick would dominate and flatten the shape.

If valid:

Perimeter = pair_sum + odd_stick.

We try all odd sticks and keep the maximum result.

Case 3: Symmetry Line Touches 2 Sticks

Now we place two odd sticks on the symmetry line
(one above, one below).

Key observation:

To keep the shape balanced, the difference between these two sticks
must be “handled” by the mirror pairs.

So the rule is:

(larger − smaller) < pair_sum

To maximize the chance of success:

We only check adjacent odd sticks in sorted order
(they have the smallest difference).

If valid:

Perimeter = pair_sum + both_sticks.

Step 4: Take the Best Answer

From:

Case 1 (only pairs),

Case 2 (pairs + 1 odd),

Case 3 (pairs + 2 odds),

we simply take the maximum valid perimeter.

If nothing works → answer is 0.

Final Decision Rule (clean summary)

Use all mirror pairs first.
Then:

Try no symmetry-line stick,

Try one symmetry-line stick,

Try two symmetry-line sticks.

Accept a case only if no single side overpowers the rest.
Among all valid cases, choose the maximum perimeter.

Time Complexity

Sorting the sticks: O(n log n)

All other checks: linear

Overall complexity: O(n log n) per test case.

Why This Works

This approach works because:

Symmetry forces equal-length pairing,

Maximum perimeter always uses all valid pairs,

Polygon geometry only fails when one side becomes too dominant.

By respecting these simple ideas, we get a correct and efficient solution.
