import sys
import math
with open(sys.argv[1], 'r') as fp:
    for line in fp:
        num = int(line.strip())
        for i in range(2, int(math.sqrt(num)) + 1):
            if num % i == 0:
                print("{} = {} * {}".format(num, num//i, i))
                break
