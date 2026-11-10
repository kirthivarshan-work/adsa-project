**Intelligent Route Optimization Using Graph Algorithms in Advanced Data Structures**

## 1. Abstract

A C-based route optimization system that finds the shortest path between two locations in a weighted transportation network. The network is represented using a graph, where locations are vertices and routes are weighted edges. The system uses an adjacency list to store connections efficiently and an array-based binary min-heap as a priority queue. Dijkstra's algorithm is applied to determine the minimum-distance route between a selected source and destination. The program displays the shortest distance and the sequence of locations in the route. It also demonstrates the application of graph representation, heap operations, greedy algorithm design, and algorithm complexity analysis in a practical transportation problem.

## 2. Objectives

- Represent a transportation network using a weighted graph.
- Store graph connections using an adjacency list.
- Implement a binary min-heap priority queue.
- Apply Dijkstra's algorithm to find a shortest route.
- Reconstruct and display the route using a parent array.
- Demonstrate the use of advanced data structures and algorithm design.

## 3. Data structures and algorithms

| Component | Data structure / algorithm | Purpose |
|---|---|---|
| Network representation | Weighted, undirected graph | Represents locations and routes |
| Graph storage | Adjacency list | Stores each location's neighbouring locations |
| Priority queue | Binary min-heap | Selects the next location with the smallest tentative distance |
| Route calculation | Dijkstra's algorithm | Finds the shortest path for non-negative edge weights |
| Path reconstruction | Parent array | Reconstructs the selected route |

## 4. Requirements

- C compiler (GCC or Clang)
- Terminal or command prompt
- Operating system: Windows, Linux, or macOS

## 5. Project files

```text
project/
├── code.c
└── README.md
```

## 6. Compilation and execution

### Linux / macOS

```bash
gcc code.c -o smartroute
./smartroute
```

### Windows (MinGW GCC)

```bash
gcc code.c -o smartroute
smartroute.exe
```

## 7. Sample input

The sample network contains five locations:

| ID | Location |
|---:|---|
| 0 | Chennai |
| 1 | Arcot |
| 2 | Villupuram |
| 3 | Salem |
| 4 | Coimbatore |

Enter the following input when prompted:

```text
5
6
0 1 140
0 2 165
1 3 180
2 3 160
3 4 165
2 4 250
0
4
```

The route distances are illustrative values for demonstrating the algorithm.

## 8. Sample output

```text
============================================
       SMARTROUTE - ROUTE OPTIMIZER
============================================
Enter number of locations (1-100): 5
Enter number of routes: 6

Enter each route as: source destination distance
Location IDs must be between 0 and 4.
Route 1: Route 2: Route 3: Route 4: Route 5: Route 6:

Enter starting location (0-4): 0
Enter destination location (0-4): 4

Shortest distance: 415
Shortest path: 0 -> 2 -> 4
```

The route `0 -> 2 -> 4` represents Chennai → Villupuram → Coimbatore.

Its total distance is:

```text
165 + 250 = 415
```

## 9. Algorithm: Dijkstra's

1. Initialize the distance of every vertex to infinity.
2. Set the source vertex distance to zero.
3. Insert the source into the min-heap.
4. Extract the vertex with the smallest tentative distance.
5. Examine each adjacent vertex.
6. If travelling through the current vertex gives a shorter distance, update the distance and parent, then insert the updated entry into the heap.
7. Ignore outdated heap entries.
8. Continue until the heap is empty or the destination is extracted with its current minimum distance.
9. Use the parent array to display the shortest path.

**Note:** Dijkstra's algorithm requires non-negative edge weights. This program validates that condition while accepting routes.

## 10. Complexity analysis

Let:
- `V` = number of vertices (locations)
- `E` = number of edges (routes)

| Operation | Time complexity |
|---|---:|
| Graph initialization | O(V) |
| Add an edge | O(1) |
| Min-heap insertion | O(log H) |
| Min-heap extraction | O(log H) |
| Dijkstra's algorithm | O((V + E) log(V + E)) |
| Path reconstruction | O(V) |

`H` is the number of entries currently in the heap. This implementation uses duplicate heap entries instead of a decrease-key operation. Its Dijkstra complexity can therefore be expressed as O((V + E) log(V + E)); for a simple connected graph, this is commonly written as O((V + E) log V).

**Space complexity:** O(V + E) for the adjacency-list graph, distance and parent arrays, and heap entries.

## 11. Limitations

- The current implementation treats routes as undirected.
- All route weights must be non-negative.
- Locations are entered as numeric IDs rather than names.
- The program finds one shortest route for a selected source and destination.
- It does not currently account for live traffic, road closures, or changing travel times.

## 12. Possible future enhancements

- Accept location names instead of numeric IDs.
- Add directed routes and different travel modes.
- Implement BFS and DFS for network traversal.
- Add Bellman–Ford for graphs with negative edge weights.
- Add Floyd–Warshall for all-pairs shortest paths.
- Add Prim's or Kruskal's algorithm for minimum spanning trees.
- Create a graphical interface to visualize the network and selected route.
- Compare algorithm execution time across different graph sizes.

## 13. Conclusion

SmartRoute demonstrates how graph representation, binary min-heaps, and Dijkstra's greedy algorithm can be combined to solve a practical route optimization problem. The project provides hands-on implementation of concepts from Advanced Data Structures and Algorithms and can be extended with additional graph algorithms and performance comparisons.
