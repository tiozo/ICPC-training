t = int(input())

def xor_binary_strings(bin_str1, bin_str2):
    int1 = int("".join(bin_str1), 2)
    int2 = int("".join(bin_str2), 2)
    
    xor_result = int1 ^ int2
    return xor_result 
    


for _ in range(t):
    s = list(input())
    n = len(s)
    
    best_l1, best_r1, best_l2, best_r2 = 1, 1, 1, n
    
    if "0" in s:
        highest = 0
        index_0 = s[s.index("0"):]
        first_o = len(index_0)
        for i in range(0,n-first_o):
            temp = s[i:i+first_o]
            nums = xor_binary_strings(index_0,temp)
            if  nums > highest:
                best_l1, best_r1 = i+1, i+first_o
                highest = nums
    else:
        best_l1, best_r1 = n,n
            
    print(best_l1, best_r1, best_l2, best_r2)