# push_swap

## What is push_swap?

- push_swap is a project that sorts a stack of integers using two stacks and a limited set of instructions.
- The goal is to sort the stack in the fewest number of moves possible.

## GOAL

| Number of Integers | Maximum Moves |
|--------------------|---------------|
| 3                  | less than 2   |
| 5                  | less than 12  |
| 100                | less than 700 |
| 500                | less than 5500|

## How to use

- `git clone ; make; ./push_swap 1 2 3 4 5 | ./checker 1 2 3 4 5`

## How to test

- `git clone https://github.com/nafuka11/push_swap_tester.git`
- `cd push_swap_tester`
- `python3 push_swap_tester.py -l 100 -c 100`
- `python3 push_swap_tester.py -l 500 -c 5`

## What Algo I used

- Turk Sort
  - STEP 1: Create two stacks, A and B.
  - STEP 2: Parse the input and push the elements to A.
  - STEP 3: If the number of elements is under 5, use a different sorting algorithm.
  - STEP 4: push 2 elements from A to B.
  - STEP 5: Until A has 3 elements left, find the “element that can be inserted into B with the minimum steps” within A and push it to B.
    - Utilize `ra + rb = rr` and `rra + rrb = rrr` to minimize the number of steps.
  - STEP 6: Once 3 elements remain in A, sort these 3 elements.
  - STEP 7: Rotate B by using rb or rrb multiple of times to make it descending order.
  - STEP 8: Return all elements in B back to their appropriate positions in A.

## NOTE

- It takes a while to sort 500 integers.

## References

- [42Tokyo push_swap](https://concrete-lion-c56.notion.site/push_swap-30078256cdf24ee09a1d5ef8d69f18b9)
- [Turk Sort: Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Algo for 5 numbers or less: Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [push_swap_tester by nafuka11](https://github.com/nafuka11/push_swap_tester)
