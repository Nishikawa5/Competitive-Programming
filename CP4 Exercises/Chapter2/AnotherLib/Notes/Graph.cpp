/*
G(V, E)
We can represent graphs in different ways:

Adjacency Matrix:
    represent the graph as a matrix[V][V]
    use when V is small , |V| < 5000
    O(V^2)

Adjacency list:
    typedef pair<int, int> ii (index of neighbouring and weight of edge)
    typedef vector<ii> vii
    use vector<vii> AL
    O(V + E)

Edge list:
    vector<tuple<int, int, int>> EL
    store a list of all E edges
    For example:
        1-----2 would be {0, 1, 2}, edge 0 connects 1 and 2

Vertex labels are not [0, 1, .., V - 1]:
    we can use an unordered map to label strings to integers
    and proceed or use:
        unordered_map<string, vector<string>> AL; , for example

Implicit graphs:
    Some structures can be seen as graphs without being stored
    in graph data structure:
        2D grid map, knight movements, etc.

Exercises:
    2.4.1.1:
        it implies that the graph doesn't have a directions
    
    2.4.1.2:
        1. AM: number of rows or column of matrix; number of != values
           AL: size of vector (max indice + 1); go through all the vectors counting neighbors
        
        2. AM: columns; rows
           AL: go through the list and check if the we have the indice as neighbor;
               size of list corresponding to indice
        
        3. AM: transpose the matrix
           AL: ?
        
        4. AM: 0 to ones?
           AL: ?

        5. AM: BFS
           AL: BFS
        
        6. AM: matrix is upper triangular
           AL: vertice < neighbors
        
        7. 
*/