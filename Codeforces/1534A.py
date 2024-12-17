def solve(input_lines, output_file):
    n, m = map(int, input_lines[0].strip().split())

    red_signal = None
    white_signal = None

    for i in range(n):
        s = input_lines[i + 1].strip()
        for j in range(len(s)):
            if s[j] == '.':
                continue
            elif s[j] == 'R':
                if red_signal is None:
                    red_signal = (i + j) % 2
                elif red_signal != (i + j) % 2:
                    output_file.write('NO\n')
                    return
            elif s[j] == 'W':
                if white_signal is None:
                    white_signal = (i + j) % 2
                elif white_signal != (i + j) % 2:
                    output_file.write('NO\n')
                    return

    if red_signal == white_signal and red_signal is not None:
        output_file.write('NO\n')
        return

    if red_signal is None:
        red_signal = 0
    if white_signal is None:
        white_signal = 1 - red_signal

    output_file.write('YES\n')
    for i in range(n):
        ans = ['R' if (i + j) % 2 == red_signal else 'W' for j in range(m)]
        output_file.write(''.join(ans) + '\n')

def main():
    with open('input.inp', 'r') as input_file:
        input_lines = input_file.readlines()
    
    with open('output.out', 'w') as output_file:
        idx = 0
        t = int(input_lines[idx].strip())
        idx += 1

        for _ in range(t):
            n, m = map(int, input_lines[idx].strip().split())
            solve(input_lines[idx:idx + n + 1], output_file)
            idx += n + 1

if __name__ == "__main__":
    main()
