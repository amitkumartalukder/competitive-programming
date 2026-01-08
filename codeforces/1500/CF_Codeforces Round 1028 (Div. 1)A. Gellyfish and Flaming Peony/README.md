A. Gellyfish and Flaming Peony — Explanation
Problem Recap:

You are given an array of positive integers.

You can repeat the following operation any number of times:

Pick two different positions i and j

Replace a[i] with gcd(a[i], a[j])

Your goal is to make all elements of the array equal, using the minimum number of operations.

It is guaranteed that this is always possible.

Key Intuition (Why the problem behaves this way)
1. What value will all numbers become in the end?

When you replace a number by a gcd, the value can only stay the same or decrease, and it always becomes a divisor of the original number.

So:

You can never create a completely new value

All numbers slowly move “downward” toward a common divisor

The only value that all numbers are guaranteed to share is:

g = gcd(a1, a2, ..., an)


So in the final state, all elements must become g.
No other final value is possible.

2. Why is having one g so powerful?

Suppose at some point one element already equals g.

Then for any other element x:

gcd(x, g) = g


That means:

In one operation, you can convert any element into g

So once you get one g, the rest are easy

This splits the problem into two parts:

Make at least one element equal to g

Convert the remaining elements to g

Step-by-Step Solution Idea
Step 1: Compute the final target value

Compute:

g = gcd of the entire array


This is the value that all elements must reach.

Step 2: Check if g already exists

If g already appears k times in the array

Then the answer is simply:

n − k


Why?

Each non-g element can be converted to g in one operation

No faster solution is possible

Step 3: If g does NOT exist, we must create it

This is the only non-trivial case.

Important idea: Normalize the array

Divide every element by g:

b[i] = a[i] / g


Now the goal becomes:

Make one element equal to 1

Because:

1 × g = g


So if we can make a 1, we automatically get g in the original array.

Step 4: How do we make a 1?

We are allowed to take gcds of numbers.

Observation:

If the gcd of some numbers is 1

Then combining those numbers step by step will eventually produce 1

Example:

b = [6, 10, 15]
gcd(6, 10, 15) = 1


To combine k numbers into one gcd value:

You need exactly k − 1 operations

So the real question is:

What is the minimum number of elements whose gcd is 1?

Step 5: Finding the minimum number of elements (core idea)

Instead of checking all subsets (which is impossible), we do this:

Keep track of:

dp[x] = minimum number of elements needed to get gcd = x


How it works conceptually:

Each number alone can form its own gcd

When a new number arrives, we:

Combine it with all previously known gcd values

Compute new gcd values

Keep the minimum element count for each gcd

Eventually:

We will reach dp[1]

This tells us the smallest number of elements needed to create gcd = 1

Step 6: Total operation count

Let:

k = minimum number of elements whose gcd is 1


Then:

To create 1 → k − 1 operations

To convert the remaining elements to g → n − 1 operations

Total:

(k − 1) + (n − 1)

Simple Example
a = [12, 20, 30]


g = gcd(12,20,30) = 2

g is not in the array

Normalize:

b = [6, 10, 15]


Smallest group with gcd = 1 is {6,10,15} → size = 3

Operations:

Make 1 → 3 − 1 = 2

Convert rest → 3 − 1 = 2

Total = 4

Final Decision Rule

Compute g = gcd(all elements)

If g appears k times:

answer = n − k


Otherwise:

Normalize by dividing all elements by g

Find the minimum number k such that gcd of those k values is 1

Answer:

(k − 1) + (n − 1)

Time Complexity (Brief)

Computing gcds and tracking states is efficient because values are small

Overall complexity per test case:

O(n × max(a))


This fits comfortably within the given limits
