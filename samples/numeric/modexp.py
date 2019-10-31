import sys

def modexp(x, y, N):
    '''
    Input: Two n-bit integers x and N, an integer exponent y
    Output: x**y mod N
    '''
    if y == 0: return 1
    z = modexp(x, y // 2, N)
    if y % 2 == 0:  # y is even
        return (z * z) % N
    else:
        return (x * z * z) % N

if __name__ == '__main__':
    if len(sys.argv) != 4:
        print("usage:", sys.argv[0], "x y N\n", "\tto calculate x^y mod N\n")
        sys.exit(1)
    x = int(sys.argv[1])
    y = int(sys.argv[2])
    N = int(sys.argv[3])
    print(modexp(x, y, N))
