#!/usr/bin/env python3

def solve():
    m = int(input())
    n = input()
    if m == 1:
        thres = '0'
    else:
        thres = '1' + ('0' * (m-2)) + '1'
    if len(n) < len(thres):
        print("NO")
    elif len(n) > len(thres):
        print("YES")
    elif n >= thres:
        print("YES")
    else:
        print("NO")
        
t = int(input())
for i in range(t):
    solve()