# Graphs workshop

## What is a graph?

Imagine a map where cities are represented as points (vertices) and roads connecting these cities are represented as lines (edges). A graph is a similar concept, but more generalized. A graph consists of points (vertices) and the connections between these points (edges).
- Vertex: An element in the graph. For example, a city, a person, or a webpage.
- Edge: A connection between two vertices. For example, a road between two cities, a friendship between two people, or a link between two web pages.

**Types of graphs:**
- Directed graph: Edges have a direction (e.g., a one-way street).
- Undirected graph: Edges have no direction (e.g., a friendship).
- Weighted graph: Numbers are assigned to edges (e.g., the length of a road).

**What are graphs used for?**
- Modeling networks: The internet, social networks, electrical circuits.
- Solving problems: Finding the shortest path, the traveling salesman problem, scheduling tasks.
- Data analysis: Analyzing social networks, biological networks.

## Assignments
### Detecting friendship groups
Figure out how many different cliques there are in the network. Do a depth-first search from each person who hasn't been checked yet. Each search will find a new clique.

### Shortest chain
Given two individuals, find the shortest chain of acquaintances connecting them. Use the Breadth-First Search (BFS) algorithm to solve this problem.