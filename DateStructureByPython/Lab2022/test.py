from Graph import Graph
from Vertex import Vertex

graph = Graph()
"""
        A(T)-B(U)
        |     |
        C(U)-D(T)
"""
A = Vertex(True)
B = Vertex(False)
C = Vertex(False)
D = Vertex(True)

A.add_edge(B)
A.add_edge(C)

graph.add_vertex(A)
graph.add_vertex(B)
graph.add_vertex(C)
graph.add_vertex(D)
print(graph.send_message(A, D))
'''
6 6
1 6 path
1 2
2 3
1 4
4 5
5 6
2 6
0 1 1 1 1 0 is_trusted=0
'''