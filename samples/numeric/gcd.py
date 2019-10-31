import sys
import math

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("usage:", sys.argv[0], "a b\n", "\tto calculate gcd(a, b)\n")
        sys.exit(1)
    a = int(sys.argv[1])
    b = int(sys.argv[2])
    print(math.gcd(a, b))
