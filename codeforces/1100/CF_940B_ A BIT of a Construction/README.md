 Problem Recap 

For each test case, we are given:

An integer n → how many numbers we must output

An integer k → the sum of those numbers

We must construct an array:

a1, a2, ..., an


Such that:

All numbers are non-negative

Their sum is exactly k

If we take the bitwise OR of all numbers,
the number of 1s in its binary form is as large as possible

If multiple answers are possible, any one is allowed.

 Key Intuition (The most important idea)

The problem is not about making the OR result large in value.
It is about making the OR result have as many 1 bits as possible.

Why is this important?

In bitwise OR, a bit becomes 1 if at least one number has 1 in that position.

So the final OR collects all the 1 bits that appear anywhere in the array.

Our goal is to use the sum k in a smart way so that the OR result lights up many different bit positions.

 First Special Case: n = 1

If we are allowed to print only one number, then:

The sum must be k

So the only possible output is:

[k]


There is no freedom here.

This case is handled separately.

 Understanding Bits Using k

Now assume n > 1.

Let’s think about the binary form of k.

Suppose the highest set bit of k is at position x.
That means:

2^x ≤ k < 2^(x+1)


This tells us something very important:

Even in the best case, the OR result cannot have more than x+1 bits set

Otherwise, the total sum would need to be at least 2^(x+1), which is more than k

So:

x+1 is the absolute maximum

In most cases, achieving x bits is guaranteed and safe

 A Very Useful Number: 2^x - 1

The number:

2^x - 1


Looks like this in binary:

111...111   (x times)


So it already contains exactly x ones.

This is powerful, because:

With a single number, we can guarantee x set bits in the OR

And 2^x - 1 is always ≤ k (by how we chose x)

 How We Build the Array

For n > 1, we do the following:

Put the number 2^x - 1 in the array

Put the remaining value:

k - (2^x - 1)


as the second number

Fill the rest of the array with 0

So the array looks like:

[ 2^x - 1 , k - (2^x - 1) , 0 , 0 , ... , 0 ]

Why does this work?

The sum is exactly k

The OR will include all the x bits from 2^x - 1

If k happens to be exactly 2^(x+1) - 1,
then the second number adds one more bit, giving x+1 bits automatically

So this construction is:

Always valid

Always optimal

 Small Example
Example: n = 6, k = 51

Highest power of two ≤ 51 is 32 = 2^5, so x = 5

2^x - 1 = 31 → binary 11111

Remaining = 51 - 31 = 20

Array:

[31, 20, 0, 0, 0, 0]


OR result:

31 | 20 = 11111


Number of 1s = 5, which is the maximum possible here.

 Final Decision Rule (Summary)

For each test case:

If n == 1
→ Output k

Otherwise:

Find the highest bit position x such that 2^x ≤ k

Output:

2^x - 1 , k - (2^x - 1) , 0 , 0 , ... , 0


This guarantees the maximum possible number of 1 bits in the OR.

 Time Complexity

Finding x takes O(log k)

Outputting the array takes O(n)
