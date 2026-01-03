 Problem Recap 

Polycarp wants to watch n TV shows in one day.

Each show has:

a start time l

an end time r

Rules:

Polycarp has only 2 TVs

On one TV, he can watch only one show at a time

If one show ends at the same time another show starts,
they cannot be watched on the same TV

Goal:

Can Polycarp watch all shows using only 2 TVs?

Print:

"YES" if possible

"NO" otherwise

 Key Intuition (Most Important Part)

The whole problem depends on overlapping shows.

Think like this:

Each TV can handle only one running show

So 2 TVs can handle at most 2 shows at the same time

If 3 shows overlap at any moment, then 2 TVs are not enough

 Very important detail:
 
If one show ends at time t and another starts at time t,
this still counts as overlapping

So start == end is NOT allowed on the same TV

So the core idea is:

At no moment should more than 2 shows overlap.

Step-by-Step Idea
Step 1: Sort all shows

Sort all shows by their starting time.

Why?

It lets us process shows in the order they begin

This makes overlap checking simple and clean

Step 2: Simulate using two TVs

We pretend we have:

TV 1, which remembers when its current show ends → end1

TV 2, which remembers when its current show ends → end2

Initially:

end1 = -1
end2 = -1

Step 3: Try to place each show

For every show (l, r) in sorted order:

If l > end1
→ Put the show on TV 1

Else if l > end2
→ Put the show on TV 2

Else
→ The show cannot go on either TV
→ That means 3 shows overlap
→ Answer is "NO"

Why strict > ?

Because l == end is not allowed by the problem rules

 Simple Example

Shows:

(1,2), (1,2), (2,3)


After sorting:

(1,2), (1,2), (2,3)


Simulation:

First (1,2) → TV1

Second (1,2) → TV2

(2,3):

2 > 2 ❌ (TV1)

2 > 2 ❌ (TV2)

No TV is free → NO

 Final Decision Rule

If at any moment more than two shows overlap
(including when one starts exactly as another ends),
then the answer is NO.
Otherwise, the answer is YES.

This single rule explains the entire problem.

Time Complexity

Sorting the shows: O(n log n)

Checking overlaps in one pass: O(n)

Total:

O(n log n)


Works easily within the limits.
