#Frincy Lyn C. Urdas


import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.


def stop(si, List):
    global connection
    for x in List:  
        if x in connection[si]:  
            return [si, x]   
    for x in List:  
        if len(connection[x]) > 0:  
            return [x, connection[x][0]] 
    return [0, 0]  


def removelink(Link1, Link2):
    global connection
    connection[link1].remove(link2)
    connection[link2].remove(link1)

# n: the total number of nodes in the level, including the gateways
# l: the number of links
# e: the number of exit gateways
n, l, e = [int(i) for i in input().split()]
array = []
connection = {}

for i in range(l):
    # n1: N1 and N2 defines a link between these nodes
    n1, n2 = [int(j) for j in input().split()]
    connection.setdefault(n1, []).append(n2)
    connection.setdefault(n2, []).append(n1)

for i in range(e):
    ei = int(input()) # the index of a gateway node 
    array.append(ei)    

# game loop
while True:
    si = int(input())  # The index of the node on which the Bobnet agent is positioned this turn
    link1, link2 = stop(si, array) 
    removelink(link1, link2)

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)

    # Example: 0 1 are the indices of the nodes you wish to sever the link between
    print("{0} {1}".format(link1, link2))
