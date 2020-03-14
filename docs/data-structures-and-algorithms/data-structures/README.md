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

#### Graphs

#### Trees

#### Binary Search

#### BFS

#### DFS

#### Dijkstra

resources

[data-structures-reference](https://www.interviewcake.com/data-structures-reference)
