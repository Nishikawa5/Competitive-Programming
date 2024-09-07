# Sucessor Graphs
Graphs that each node has outdegree 1

### Floyd algo
a: ->
b: -> ->

We have two pointers, a moves 1 node and b moves 2 nodes (the speed of b is 2x faster).

Assume the fast and slow pointer will meet at the second cycle of b. Separe the lengths in X, Y, Z. So the distance b = X + Y + Z and distance a = X + Y => X + Y + Z = 2 * X + 2 * Y => Z = X, since the speed of b is 2 times the speed of a