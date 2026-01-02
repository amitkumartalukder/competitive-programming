Problem Recap

You are given an array of n numbers.

You can repeat the following operation any number of times:

Choose two adjacent elements x and y

Replace one of them with gcd(x, y)

Your goal is to make all elements equal to 1 using the minimum number of operations.

If it is impossible, print -1.

Key Intuition (Most Important Idea)

The GCD operation only reduces numbers, never increases them.

So:

If 1 can ever appear, it will help reduce everything else to 1

If 1 can never appear, the task is impossible

So the whole problem becomes:

Can we create at least one 1?
If yes → spread it
If no → answer is -1

Step-by-Step Reasoning
Step 1: Check the GCD of the Entire Array

Take the GCD of all elements together.

If this GCD is greater than 1,
then every possible GCD operation will also stay > 1
→ You will never get a 1

 In that case:

Answer = -1

 Step 2: If the Array Already Contains 1

This is the easiest case.

Why?

gcd(1, x) = 1 for any number x

So a 1 can convert its neighbors into 1 using one operation each

If:

there are cnt1 ones in the array

total elements = n

Then:

Number of operations = n - cnt1


We just turn every non-1 into 1.

 Step 3: No 1 Exists — We Must Create One

This is the core idea of the problem.

We look for a contiguous subarray whose GCD is 1.

Why contiguous?

Operations are allowed only on adjacent elements

Why GCD = 1?

Only then can we finally produce a 1

How many operations to create the first 1?

If the shortest such subarray has length L:

It takes L - 1 operations to collapse it into a single 1

After we get one 1

We now spread it to the remaining n - 1 elements

Each takes one operation

So total operations:

(L - 1) + (n - 1)

🔹 Simple Example
Example:
Array: [2, 6, 9]


No 1 initially

GCD of [2, 6] = 2

GCD of [6, 9] = 3

GCD of [2, 6, 9] = 1 

Length = 3

Operations:

Create first 1: 3 - 1 = 2

Spread to others: 3 - 1 = 2

Total = 4

 Final Decision Rule

If GCD of entire array > 1
→ print -1

Else if array already contains 1
→ print n - count_of_1

Else:

Find the shortest subarray with GCD = 1

Let its length be L

Answer = (L - 1) + (n - 1)

 Time Complexity

Checking all subarrays takes O(n²)

Constraints allow this (n ≤ 2000)

Overall complexity:

O(n²)
