import sys

def extended_Euclid(a, b):
    '''
    Input: Two positive integers a and b with a >= b >= 0
    Output: Integers x,y,d such that d = gcd(a, b) and a*x + b*y = d
    '''
    if b == 0: return (1, 0, a)
    x1, y1, d = extended_Euclid(b, a % b)
    return (y1, x1 - (a//b)*y1, d)

def gcd_ext(a, b):
    if a > b:
        return extended_Euclid(a, b)
    else:
        return extended_Euclid(b, a)

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("usage:", sys.argv[0], "a b\n", "\tto calculate gcd(a, b)\n")

    a = int(sys.argv[1])
    b = int(sys.argv[2])
    x, y, d = gcd_ext(a, b)
    print("gcd_ext(%d, %d) = %d, (%d)*(%d) + (%d)*(%d) = %d" % (a, b, d, a, x, b, y, d))

