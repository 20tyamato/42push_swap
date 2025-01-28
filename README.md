# `push_swap`

## What is `push_swap`?

- `push_swap` is a project that sorts a stack of integers using two stacks and a limited set of instructions.
- The objective is to sort the stack with the minimum number of moves possible.

## GOAL

| Number of Integers | Maximum Moves |
|--------------------|---------------|
| 3                  | Fewer than 2   |
| 5                  | Fewer than 12  |
| 100                | Fewer than 700 |
| 500                | Fewer than 5500|

## How to use

- `git clone ; make; ./push_swap 1 2 3 4 5 | ./checker 1 2 3 4 5`

## How to test

- `git clone https://github.com/nafuka11/push_swap_tester.git`
- `cd push_swap_tester`
- `python3 push_swap_tester.py -l 100 -c 100`
- `python3 push_swap_tester.py -l 500 -c 5`

## What Algo I used

- Turk Sort
  - STEP 1 (Initialize Stacks): Create two stacks, A and B.
  - STEP 2 (Parse Input): Push all input elements into stack A.
  - STEP 3 (Special Case for Small Inputs): If the number of elements is 5 or fewer, use a simplified sorting algorithm.
  - STEP 4 (Move Initial Elements): Push two elements from A to B.
  - STEP 5 (Sort Remaining Elements in A): While stack A has more than 3 elements, find the “element that requires the fewest steps to insert into B” and push it to B.
    - Use step optimization: `ra + rb = rr` and `rra + rrb = rrr`.
  - STEP 6 (Sort Remaining 3 Elements in A): Once 3 elements remain in A, sort them directly.
  - STEP 7 (Arrange Stack B): Rotate B using `rb` or `rrb` to make it descending.
  - STEP 8 (Reintegrate Elements from B to A): Push all elements from B back to A in their correct positions.

## NOTE

- Sorting 500 integers may take some time.

## References

- [42Tokyo push_swap](https://concrete-lion-c56.notion.site/push_swap-30078256cdf24ee09a1d5ef8d69f18b9)
- [Turk Sort: Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Algo for 5 numbers or less: Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [push_swap_tester by nafuka11](https://github.com/nafuka11/push_swap_tester)
