import itertools
import subprocess

def run_push_swap_and_checker(length):
    sequence = list(range(1, length + 1))
    permutations = list(itertools.permutations(sequence))
    formatted_permutations = [" ".join(map(str, perm)) for perm in permutations]
    max_steps = 0
    min_steps = float("inf")

    for perm in formatted_permutations:
        push_swap_result = subprocess.run(
            f"./push_swap {perm}",
            shell=True,
            capture_output=True,
            text=True
        )
        checker_result = subprocess.run(
            f"./checker {perm}",
            shell=True,
            input=push_swap_result.stdout,
            capture_output=True,
            text=True
        )
        steps = len(push_swap_result.stdout.strip().split("\n"))
        if steps > max_steps:
            max_steps = steps
        if steps < min_steps:
            min_steps = steps
        print(f"{perm}: {checker_result.stdout.strip()} with {steps} steps")

    print(f"Max steps: {max_steps}")
    print(f"Min steps: {min_steps}")

if __name__ == "__main__":
    # python test_random_numbers.py 5 | grep "KO"
    import argparse

    parser = argparse.ArgumentParser(description="Test push_swap and checker with permutations.")
    parser.add_argument("length", type=int, choices=[3, 5], help="The length of the sequence (3 or 5).")
    args = parser.parse_args()

    run_push_swap_and_checker(args.length)
