def is_valid_grid(n, m, grid):
    for i in range(n):
        for j in range(m):
            if grid[i][j] not in "RW":
                return False
            if grid[i][j] == 'R':
                if (i > 0 and grid[i-1][j] == 'R') or (i < n-1 and grid[i+1][j] == 'R') or (j > 0 and grid[i][j-1] == 'R') or (j < m-1 and grid[i][j+1] == 'R'):
                    return False
            elif grid[i][j] == 'W':
                if (i > 0 and grid[i-1][j] == 'W') or (i < n-1 and grid[i+1][j] == 'W') or (j > 0 and grid[i][j-1] == 'W') or (j < m-1 and grid[i][j+1] == 'W'):
                    return False
    return True

def checker(input_data, output_file):
    input_lines = input_data.strip().split('\n')
    with open(output_file, 'r') as file:
        output_lines = file.read().strip().split('\n')

    t = int(input_lines[0])
    idx = 1

    for case_num in range(t):
        n, m = map(int, input_lines[idx].split())
        idx += 1
        grid = [list(input_lines[idx + i]) for i in range(n)]
        idx += n

        expected_result = output_lines[0].strip().lower()
        output_grid = [list(output_lines[i+1].strip()) for i in range(n)]

        if expected_result == 'no':
            print(f"Test case {case_num + 1}: NO")
            if output_lines[0].strip().lower() != 'no':
                return f"Checker failed: Expected 'NO' but got 'YES' for test case {case_num + 1}"
            continue

        print(f"Test case {case_num + 1}: YES")
        if not is_valid_grid(n, m, output_grid):
            return f"Checker failed: Invalid grid for test case {case_num + 1}"

    return "Checker passed all test cases."

# Example usage:
input_data = """2
3 3
R..
.W.
...
2 2
RW
.WR"""
output_file = "output.out"

result = checker(input_data, output_file)
print(result)
