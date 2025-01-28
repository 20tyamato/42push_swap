# RESULTS

## Command to run for 100

```bash
python3 push_swap_tester.py -l 100 -c 100
```

## RESULT 0

```bash
❯ python3 push_swap_tester.py -l 100 -c 100
Test 100 cases: arg_length=100 range=(-2147483648, 2147483647)
....................................................................................................
---- Result ----
max   : 1159
median: 916
min   : 590
See result.log for details
```

## RESULT 1 for 100

- `rev_rotate_sort_b(a, b);`を消す

```bash
❯ python3 push_swap_tester.py -l 100 -c 100
Test 100 cases: arg_length=100 range=(-2147483648, 2147483647)
....................................................................................................
---- Result ----
max   : 4017
median: 2435
min   : 621
See result.log for details
```

## RESULT 2 for 100 FINAL

- `forward_rotate_sort_a(a, b);`をループから外す

```bash
❯ python3 push_swap_tester.py -l 100 -c 100
Test 100 cases: arg_length=100 range=(-2147483648, 2147483647)
....................................................................................................
---- Result ----
max   : 655
median: 611
min   : 552
See result.log for details
```

## RESULT 3 for 100

- `rev_rotate_sort_b(a, b);`を消す
- `forward_rotate_sort_a(a, b);`をループから外す

```bash
❯ python3 push_swap_tester.py -l 100 -c 100
Test 100 cases: arg_length=100 range=(-2147483648, 2147483647)
...........................F.......................F...........................F....................
---- Result ----
max   : 681
median: 611
min   : 534
See result.log for details
```

## Command to run for 500

```bash
python3 push_swap_tester.py -l 500 -c 5
```

## RESULT 0 for 500

```bash
❯ python3 push_swap_tester.py -l 500 -c 5
Test 5 cases: arg_length=500 range=(-2147483648, 2147483647)
.....
---- Result ----
max   : 8570
median: 7725
min   : 6972
See result.log for details
```

## RESULT 1 for 500 FINAL

- `forward_rotate_sort_a(a, b);`をループから外す

```bash
❯ python3 push_swap_tester.py -l 500 -c 5
Test 5 cases: arg_length=500 range=(-2147483648, 2147483647)
.....
---- Result ----
max   : 6078
median: 5917
min   : 5734
See result.log for details
```

## RESULT

- 改善点

```bash

```
