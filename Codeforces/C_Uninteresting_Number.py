def is_possible_to_make_divisible_by_9(n_str):
    digits = [int(c) for c in n_str]
    initial_sum = sum(digits)

    if initial_sum % 9 == 0:
        return "YES"

    possible_squares = [digit ** 2 for digit in [0, 1, 2, 3]]

    dp = [False] * 9
    dp[initial_sum % 9] = True

    for digit in digits:
        if digit in [0, 1, 2, 3]:
            squared_value = digit ** 2
            current_remainder = initial_sum % 9

            new_dp = dp[:]
            for remainder in range(9):
                if dp[remainder]:
                    new_remainder = (remainder - digit + squared_value) % 9
                    new_dp[new_remainder] = True
            
            dp = new_dp

    if dp[0]:
        return "YES"
    else:
        return "NO"

t = int(input())
results = []
for _ in range(t):
    n_str = input().strip()
    results.append(is_possible_to_make_divisible_by_9(n_str))

for result in results:
    print(result)
