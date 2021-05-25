# Data structures
  
Common data structures

!> Work in process!

?> Coming soon...

## Content

- [Data structures](#data-structures)
  - [Content](#content)
  - [Data structures hierarchy](#data-structures-hierarchy)
    - [Non primitive data structures](#non-primitive-data-structures)
    - [Heap](#heap)
    - [Stacks](#stacks)
      - [Stack](#stack)
      - [Queue](#queue)
      - [Hash tables](#hash-tables)
      - [Graphs](#graphs)
      - [Trees](#trees)
      - [Binary Search](#binary-search)
      - [BFS](#bfs)
      - [DFS](#dfs)
      - [Dijkstra](#dijkstra)

## Data structures hierarchy

```mermaid
graph TD;

    types[Types of data structures] --> primitive[Primitive data structures]
    types[Types of data structures] --> nonPrimitive[Non Primitive data structures]

    primitive[Primitive data structures] --> int[Integer]
    primitive[Primitive data structures] --> char[Character]
    primitive[Primitive data structures] --> bool[Boolean]
    primitive[Primitive data structures] --> float[Float]

    nonPrimitive[Non Primitive data structures] --> linear[Linear data structures]
    nonPrimitive[Non Primitive data structures] --> nonLinear[Non-Linear data structures]

```

### Non primitive data structures

```mermaid
graph TD;

lin[Linear data structures] --> array[Array]
lin[Linear data structures] --> stack[Stack]
lin[Linear data structures] --> queue[Queue]
lin[Linear data structures] --> linkedList[Linked list]

nonLin[Non-Linear data structures] --> tree[Tree]
nonLin[Non-Linear data structures] --> grap[Graph]
nonLin[Non-Linear data structures] --> hashTable[Hash table]

```

### Heap

Data structure that manage free block of memory (OS do it). Dynamicaly memory.
<!-- Структура от данни, която управлява свободните блокове памет (ос го прави)
Наричана още динамична памет (памет на OS) -->

### Stacks

Linear structure.
<!-- Обработката на информацията става само от едната страна наречена връх -->
LIFO - last in, first out

#### Stack

- ```Stack<T>```
- LIFO (last in fist out)
- push, pop
- static stack (array based), fixed capacity
- linked stack (dynamic)
  - Two fields: value, next
  - Like linked list

#### Queue

- ```Queue<T>```
- FIFO (first in first out)
- staticaly (array based, fixed size)
- dynamicaly (using pointers). Linked queue

#### Hash tables

[Data Structure and Algorithms - Hash Table](https://www.tutorialspoint.com/data_structures_algorithms/hash_data_structure.htm)

[Hash table](https://en.wikipedia.org/wiki/Hash_table)

Hash Tables and Hash Functions <br>
[![](http://img.youtube.com/vi/KyUTuwz_b7Q/0.jpg)](https://www.youtube.com/watch?v=KyUTuwz_b7Q "Hash Tables and Hash Functions")

Hash Tables <br>
[![](http://img.youtube.com/vi/h2d9b_nEzoA/0.jpg)](https://www.youtube.com/watch?v=h2d9b_nEzoA "Hash Tables")

**Collision** refers to a situation where a function maps two distinct inputs to the same output. <br>
A collision is the situation when **different keys have the same hash value** ``h(k1) = h(k2) for k1 ≠ k2``

Solving Collision:
 - Linear Probing
   - If key match the same index, store the value to next free slot
   - Notes
     - Hash table will get large, 
	   - clustering - when more and more collisions,
     - abstract data type (ADT)
 - Separate Chaining
   - Hash table become array of linked lists

Summary

- Used to index large amounts of data
- Address of each key calculated using the key itself
- Collisions resolved with open or closed addressing
- Hashing is widely used in database indexing, compilers, caching, password authentication, and more
- Insertion, deletion and retrieval occur in constant time

#### Graphs

[Graph & Graph Models](https://www.tutorialspoint.com/discrete_mathematics/graph_and_graph_models.htm)

[Data Structure - Graph Data Structure](https://www.tutorialspoint.com/data_structures_algorithms/graph_data_structure.htm)

**Weighted** and **unweighted** graphs

Weight (cost) is associated with each edge

Data structures: Introduction to graphs <br>
[![](http://img.youtube.com/vi/gXgEDyodOJU/0.jpg)](https://www.youtube.com/watch?v=gXgEDyodOJU "Data structures: Introduction to graphs")

Graphs and Their Applications, Graphs have many real-world applications

- Modeling a computer network like Internet
  - Routes are simple paths in the network
- Modeling a city map
  - Streets are edges, crossings are vertices
- Social networks
  - People are nodes and their connections are edges
- State machines
  - States are nodes, transitions are edges

Representing Graphs

- Adjacency list
  - Each node holds a list of its neighbors
- Adjacency matrix
	- Each cell keeps whether and how two nodes are connected
- Set of edges

|     |     |     |
|:---:|:---:|:---:|
| ![img](assets/graphs-01.png) | ![img](assets/graphs-02.png) | ![img](assets/graphs-03.png) |

Simple C# Representation

```csharp
public class Graph
{
  List<int>[] childNodes;
  public Graph(List<int>[] nodes)
  {
    this.childNodes = nodes;
  }
}

Graph g = new Graph(new List<int>[] {
  new List<int> {3, 6}, // successors of vertice 0
  new List<int> {2, 3, 4, 5, 6},// successors of vertice 1
  new List<int> {1, 4, 5}, // successors of vertice 2
  new List<int> {0, 1, 5}, // successors of vertice 3
  new List<int> {1, 2, 6}, // successors of vertice 4
  new List<int> {1, 2, 3}, // successors of vertice 5
  new List<int> {0, 1, 4}  // successors of vertice 6
});
```

#### Trees

#### Binary Search

#### BFS

#### DFS

#### Dijkstra

resources

[data-structures-reference](https://www.interviewcake.com/data-structures-reference)
