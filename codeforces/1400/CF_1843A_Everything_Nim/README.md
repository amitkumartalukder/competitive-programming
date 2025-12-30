1. Game Rules (Short Recap)

There are n piles of stones.

In one move, a player chooses a number k.

k must be ≤ smallest non-empty pile.

Then k stones are removed from every non-empty pile.

A player who cannot make a move loses.

Alice plays first.

2. Key Observation: Why pile size 1 is special

If any pile has size 1:

The smallest pile = 1

So k can only be 1

No player can choose a bigger move

That means:

While there is a pile of size 1, the game is forced —
every move removes exactly 1 from all piles.

This is called the forced phase.

3. What happens during the forced phase?

Each move:

All piles reduce by 1

Turn switches (Alice → Bob → Alice → …)

So the only thing that matters here is:

How many forced moves happen?
(odd or even number of moves)

4. When does the forced phase end?

The forced phase ends when:

There is no pile of size 1 anymore

To detect this without simulation, we define:

b = the smallest positive integer NOT present in the array

(also called MEX excluding 0)

Example:

Piles: 1 2 3 5 8
b = 4


Meaning:

1 → forced

2 → forced

3 → forced

4 is missing → forced phase ends here

So:

Forced phase length = b − 1 moves

5. What happens after the forced phase?

After forced phase:

The smallest pile size is ≥ 2

Now the current player has full control

The current player can always force a win

So:

Whoever gets the turn after forced phase wins

6. Two Possible Cases

Let:

a = maximum pile size

b = smallest missing positive integer

Case 1: b > a

(Forced phase never ends)

All numbers from 1 to a exist

The game is forced until all piles become 0

Total moves = a

Winner:

a odd → Alice

a even → Bob

Case 2: b ≤ a

(Forced phase ends)

Forced moves = b − 1

After that, smallest pile ≥ 2

Player whose turn comes at that moment wins

Winner:

b odd → Alice

b even → Bob

7. Final Decision Rule (One Screen Logic)
Let a = maximum pile
Let b = smallest positive integer missing from array

if (b > a):
    winner depends on parity of a
else:
    winner depends on parity of b

8. Why This Works (In One Sentence)

Pile 1 forces the game to move step-by-step

Missing number b tells when that force breaks

Parity (odd/even) tells who gets the winning turn

9. Time Complexity

Sorting: O(n log n)

Finding b: O(n)

Works easily within constraints
