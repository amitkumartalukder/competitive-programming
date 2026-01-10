Problem Recap

You are given an array of integers.

The beauty of a number = how many 1 bits it has in binary
(for example, 7 = 111 has beauty 3)

The beauty of the array = sum of beauties of all numbers

You are allowed to do at most k operations.

In one operation, you can choose any index and increase that number by 1

Your goal is to maximize the total beauty of the array.

Key Intuition (Most Important Part)

We only care about when adding +1 actually increases the number of 1 bits.

So the real question becomes:

When does adding 1 to a number increase its number of set bits?

Important Observation

In binary:

Adding 1 flips bits starting from the right

If the number ends with 0, that 0 becomes 1 (good)

If it ends with 1, that 1 becomes 0 (bad)

So:

Turning a 0 bit into 1 increases beauty

Turning 1 bits into 0 decreases beauty

To increase beauty safely, we must flip a 0 → 1 without destroying too many 1s.

The Core Idea
Best possible improvement

For any number:

Look at the lowest (least significant) bit that is 0

Turning that bit into 1 always increases beauty by exactly 1

This is the cheapest and safest improvement

Why cheapest?

That bit has value 2^i

You need exactly 2^i increments to reach that state

Smaller i → smaller cost

So:

To maximize beauty with limited operations, always flip the smallest possible 0 bit first.

Step-by-Step Strategy
Step 1: Count initial beauty

Before any operation:

Count how many 1 bits each number already has

Add them all together
This is your starting beauty.

Step 2: Count available improvements

We now think in terms of bit positions, not numbers.

For each bit position i (from 0 up to ~60):

Count how many numbers have bit i = 0

Each such 0 is a potential beauty increase

Let:

cnt[i] = how many numbers have a 0 at bit position i

Step 3: Greedy choice (the heart of the solution)

We now spend our k operations wisely.

For bit positions from lowest to highest:

Cost to flip bit i = 2^i

Benefit = +1 beauty

While:

We still have numbers with 0 at this bit (cnt[i] > 0)

We can afford the cost (k >= 2^i)

We:

Spend 2^i operations

Increase beauty by 1

Decrease cnt[i]

Reduce k

Then move to the next bit.

This works because:

Every improvement gives the same benefit (+1)

Lower bits are strictly cheaper

So taking cheap improvements first is always optimal

Simple Example

Suppose:

a = [2, 3]
k = 3

2 = 10
3 = 11


Initial beauty:

2 has 1 bit

3 has 2 bits
Total = 3

Zero bits:

Bit 0: 2 has 0 → cnt[0] = 1

Bit 1: none

Bit 2: both have 0 → cnt[2] = 2

Greedy:

Bit 0 costs 1, k = 3 → take it → beauty = 4, k = 2

Bit 1 costs 2, k = 2 → take it → beauty = 5, k = 0

Answer = 5

Final Decision Rule

Start with the initial beauty of the array

For each bit position:

Count how many numbers have 0 there

From lowest bit to highest:

Spend operations to flip 0 → 1 while possible

Stop when you run out of operations

This guarantees the maximum possible beauty.

Time Complexity

Checking bits: O(n × 60)

Greedy process: O(60)

Total: O(n × 60) per test case

This easily fits within the limits.
