#!/usr/bin/env python3

import sys

for line in sys.stdin:
    
    a = list(map(int, line.split()))
    # print(a)
    currMax = a[0]
    currMin = a[0]
    maxProd = a[0]
    for i in range(1,len(a)-1):
        tmp = max([a[i], a[i] * currMax, a[i] * currMin])
        currMin = min([a[i], a[i] * currMax, a[i] * currMin])
        currMax = tmp
        maxProd = max([maxProd,currMax])
    print(maxProd)




