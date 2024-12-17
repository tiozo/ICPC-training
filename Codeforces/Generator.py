import random

def generate_test_case():
    # Open the file in write mode
    with open('input.inp', 'w') as file:
        # Number of test cases
        t = random.randint(1, 100)
        file.write(str(t) + '\n')
        
        for _ in range(t):
            # Dimensions of the grid
            n = random.randint(1, 50)
            m = random.randint(1, 50)
            file.write(f"{n} {m}\n")
            
            # Generate the grid with a valid pattern
            grid = []
            for i in range(n):
                row = []
                for j in range(m):
                    if random.random() < 0.5:
                        if (i + j) % 2 == 0:
                            row.append('R')
                        else:
                            row.append('W')
                    else:
                        row.append('.')
                grid.append(''.join(row))
            
            # Write the grid to the file
            for row in grid:
                file.write(row + '\n')

# Example usage:
generate_test_case()
