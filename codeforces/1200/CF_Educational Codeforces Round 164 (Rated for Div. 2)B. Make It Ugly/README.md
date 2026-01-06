Problem Recap 

You are given an array that is already beautiful.

An array is called beautiful if you can make all elements the same by repeating this operation any number of times:

Choose an index i such that 2 ≤ i ≤ n-1

If the left and right neighbors are equal
(a[i-1] == a[i+1])

Then you can replace the middle element
a[i] = a[i-1]

You are allowed to delete elements (but not swap them).

 Your task:
Delete the minimum number of elements so that the array is NO LONGER beautiful.

If it is impossible, print -1.

 Key Intuition (Most Important Part)

The operation can only change middle elements.
The first and last elements never change.

So the behavior of the array is controlled by its edges, especially the first element.

 If the value of the first element can spread inward and turn everything into itself,
then the array is beautiful.

 If we somehow break this spreading, the array stops being beautiful.

So the whole problem becomes:

How do we stop the first element from taking over the array?

 When Is It Impossible?

If all elements are already the same, for example:

[2, 2, 2, 2]


Then:

No matter what you delete

All remaining elements are still equal

The array will always be beautiful

in this case, the answer is -1.

Main Idea (Step-by-Step)

Assume not all elements are the same.

Step 1: Focus on the first element

Let:

x = a[0]


This value x is dangerous because:

It sits on the edge

It cannot be changed

It can spread inward using the operation

Step 2: Look at continuous blocks of x

Example:

3 3 3 5 3 3 3


Here, the first element is 3.

The array has two continuous blocks of 3:

[3 3 3]   and   [3 3 3]


Their sizes are:

Block 1 → size 3

Block 2 → size 3

Step 3: Find the weakest place

To stop 3 from spreading across the array,
we need to break at least one of its blocks.

The best choice is:

Delete the smallest block of the first element

Why?

Deleting fewer elements is better

Breaking one block is enough to stop the spread

After that, the operation can no longer make all elements equal

Simple Examples
Example 1
[1, 2, 1, 2, 1]


First element = 1

Blocks of 1 → sizes: 1, 1, 1

Smallest block = 1

Answer = 1

(Delete one 1, and the array can no longer become all same.)

Example 2
[3, 3, 3, 5, 3, 3, 3]


First element = 3

Blocks of 3 → sizes: 3, 3

Smallest block = 3

Answer = 3

(Delete one full block of size 3.)

Final Decision Rule
If all elements are the same:
Answer = -1

 Otherwise:

Take the first element

Find all its continuous blocks

The answer is the smallest block size

Time Complexity

Each test case is processed in O(n)

Works safely within the given limits
