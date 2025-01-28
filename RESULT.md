# RESULTS

## Command to run for 100

```bash
python3 push_swap_tester.py -l 100 -c 100
```

## RESULT 0

- 結果：基準値の700から程遠い

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
- 結果：基準値の700からさらに遠くなった

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
- 結果：基準値の700を下回った

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
- 結果：基準値の700を下回ったが、`rev_rotate_sort_b(a, b);`があった方が早いし、エラーなし

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

- 結果：基準値の5500から程遠い

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
- 結果：基準値の5500に近づいたが、500もの手数を削減する必要がある

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

## RESULT 2 for 500

- `sort_stack_of_three(a, b);`を`sort_stack_of_five(a, b);`に変更
- 結果：ほんの少しだけ改善

```bash
❯ python3 push_swap_tester.py -l 500 -c 5
Test 5 cases: arg_length=500 range=(-2147483648, 2147483647)
.....
---- Result ----
max   : 6046
median: 5883
min   : 5757
See result.log for details
```

## RESULT 3 for 500

- `merge_operations`をより最適化
  - A も B も forward 回転する
    - 実際の手数は max(ra, rb) になる (同時回転 rr を最小手数で使えるから)
  - A も B も reverse 回転する
    - 実際の手数は max(rra, rrb) になる (同時回転 rrr を最小手数で使えるから)
  - A は forward 回転し、B は reverse 回転する
    - 同時回転できないので、実際の手数は ra + rrb
  - A は reverse 回転し、B は forward 回転する
    - 実際の手数は rra + rb

```bash

```

## ISSUE

- rev_rotate_sort_b(a, b);を消すと、結果が悪化する
- 後500手減らす必要がある
- 仮説
  - sort_threeからsort_fiveにしたことによって、処理は早くなった
  - sort_fiftyを使うことでもっと処理は早くなる？

```bash

```
