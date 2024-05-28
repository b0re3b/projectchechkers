# Programming patterns in other projects

All program code files are in the repository(https://github.com/b0re3b/projectchechkers), there are three labs from algorithms and complexity.

Using design patterns helps developers create more structured, flexible, and easily maintainable programs. Patterns provide standard solutions to common problems, avoiding ad-hoc solutions and improving code readability. They also help reduce dependencies between program components and enhance code reuse. Utilizing patterns reduces the risk of errors and simplifies component testing, while also improving system scalability.

## Binominal heap(Singleton, Factory method, Composite)
This program is designed to demonstrate and visualize the functionality of a binomial heap using the SFML graphics library. It allows users to insert elements into the heap, retrieve the minimum element, delete the minimum element, print the heap structure to the console, and visualize it on the screen.

Users can interact with the heap through a graphical interface created using SFML. The program enables input of new elements, retrieval of the minimum value without removal, deletion of the minimum element, and printing of the heap structure in textual form for analysis.

The main components of the program include the `BinomialHeap` class, which implements all basic operations with the binomial heap, and the `BinomialHeapSingleton` class, which ensures the existence of a single instance of the binomial heap. The graphical part of the program utilizes SFML to display heap nodes and their connections in a window. Nodes are represented as circles with values inside them, and connections between nodes are depicted as lines.

Users can press keys to perform various operations: `I` for inputting a new value, `M` to retrieve the minimum value, `E` to delete the minimum value, and `P` to print the heap structure to the console. The visualization of the heap updates after each operation, allowing the user to see the current state of the data structure.The correctness of the program is ensured by unit tests that have a positive result
### Use patterns for what

#### Singleton

The Singleton pattern ensures the existence of only one instance of a particular class in the program and provides global access to that instance. In our program, the use of the Singleton pattern in the `BinomialHeapSingleton` class ensures the existence of a single instance of the binomial heap throughout the program.

Specifically, in the program, we utilize the Singleton pattern by creating a private static field named `instance` in the `BinomialHeapSingleton` class, which holds the sole instance of the binomial heap. The `getInstance()` method is used to retrieve this single instance. Upon the first call to `getInstance()`, a new instance of the binomial heap is created if it has not been created yet, and a reference to it is returned. Subsequent calls to `getInstance()` return the same instance that was previously created. This ensures that only one instance of the binomial heap is used throughout the program, simplifying data management and avoiding conflicts when working with the heap from different parts of the program.

#### Factory method
The Factory Method pattern allows us to define an interface for creating objects while allowing subclasses to change the type of objects that will be created. In our program, the use of the Factory Method pattern in the `NodeFactory` class for creating nodes (Node objects) provides a centralized way to create objects, simplifying their modification, testing, and maintenance.

Specifically, in our program, we use the Factory Method pattern by defining a static method `createNode()` in the `NodeFactory` class, which is responsible for creating nodes. This method abstracts the creation process and allows us to create nodes without exposing the instantiation logic directly in the client code. If there is a need to change the logic of node creation or add additional initialization in the future, it can be done in one place (inside the createNode() method), without the need to modify the entire program. This enhances the flexibility, maintainability, and scalability of the codebase.

#### Composite
The Composite pattern allows us to compose objects into tree-like structures to represent part-whole hierarchies. It enables clients to treat individual objects and compositions of objects uniformly.

In our program, the Composite pattern is implemented in the structure of nodes in the binomial heap, where each node can have child nodes. This allows us to handle both individual nodes and their sub-trees uniformly, simplifying algorithms that traverse and process the heap structure. Thanks to this pattern, the code for traversing and visualizing trees becomes simpler and more intuitive.

Specifically, in our program, each node in the binomial heap can have a list of child nodes (represented by the `children` vector in the `Node` class). This structure allows us to build a hierarchical representation of the heap, where each node can act as both an individual element and as a part of a larger structure. When traversing or processing the heap, we can treat each node and its children uniformly, without distinguishing between individual nodes and composite structures. This simplifies the code and makes it easier to understand and maintain.

## Perfect hashing(Strategy pattern)

In this program, perfect hashing is implemented by placing each key at a unique position in the table without collisions. Let's consider several key stages of perfect hashing implementation in this program:

Hash function selection: A crucial stage is the selection of a hash function that calculates a unique hash for each key. The program uses two different hash functions: UniversalHashFunction and SimpleHashFunction. Both functions are designed to generate unique hashes for keys.

Placement of keys in the table: After calculating the hash for each key, it is placed in the table at the computed position. In case of a collision, where two keys have the same hash, they can be placed at different positions, maintaining perfect hashing.

Searching for elements: Searching for elements involves calculating the hash for the desired key and checking its position in the table. Since each key is placed at a unique position, searching occurs quickly without the need to examine other elements.

Output of elements: To verify the correctness of key placement in the table, the program can output all elements of the table along with their positions.

This program demonstrates the principles of perfect hashing, allowing for fast and efficient searching of elements in the hash table without collisions. The program also use unit testing, to check a correctness of result.
The "Strategy" pattern is used to select an algorithm or strategy on the fly based on specific requirements. In this program, the Strategy pattern is used to implement different hashing methods within the context of a perfect hash table.
### Use patterns for what

#### Strategy
This program utilizes the Strategy pattern to implement various hashing algorithms within the context of a perfect hash table. The Strategy pattern allows dynamically selecting different hashing algorithms based on specific needs. It facilitates easy alteration of hashing methods without modifying the code that uses these algorithms. In the program, the `IHashFunction` interface defines the methods that must be implemented for any hashing algorithm. This abstraction enables the use of different hashing strategies without being tied to a specific implementation. Classes implementing this interface, such as `UniversalHashFunction` and `SimpleHashFunction`, represent concrete hashing algorithms. They offer different approaches to computing the hash for a given key.

Using the Strategy pattern in this program provides several advantages: flexibility, ease of testing, and scalability. It allows developers to switch between hashing strategies seamlessly, depending on the requirements. Moreover, it simplifies the addition of new hashing algorithms in the future without disrupting existing code. This approach promotes clean, modular, and maintainable code architecture.

## OBS Tree

This program implements the construction of an Optimal Binary Search Tree (OBST) using dynamic programming. An optimal binary search tree is a binary search tree in which the average number of comparisons required for searching an element is minimized. The program uses the strategy design pattern to separate the main class into two: a base template class (OBSTreeTemplate) and its subclass with a specific implementation of OBST construction steps (DPStrategy). The main function creates an object of the DPStrategy class, which calls methods for inputting data from the console, constructing the OBST, and printing the resulting tree to the console. The program allows users to easily construct an optimal binary search tree for given values and probabilities.

### Use patterns for what

#### Template

The Template Method pattern is used in the program to define a general algorithm for constructing an optimal binary search tree (OBST), while concrete steps of the algorithm are implemented in subclasses. The main purpose of this pattern is to separate the general structure of the algorithm from its specific implementation, allowing for the modification or extension of individual algorithm steps without changing its overall structure.

In the program, the base class `OBSTreeTemplate` contains the template method `constructTreeDP`, which defines the general algorithm for constructing an OBST. This method is called to create a tree with specific values and probabilities. The subclass `DPStrategy` implements this method using a specific dynamic programming approach for tree construction.

The Template Method allows subclasses, such as `DPStrategy`, to define specific algorithm steps without the need to change the overall structure in the base class. This provides flexibility and extensibility to the program, as new subclasses with different OBST construction methods can be easily added without altering the core algorithm.

## Summary

So, the first program utilizes the "Strategy" pattern, allowing the interchange of algorithms for data processing without modifying the classes that use them. This makes the code more flexible and convenient for changing algorithms based on program requirements.

The second program employs the "Observer" pattern, defining a dependency between objects so that changes in one object automatically trigger updates in others. This facilitates interaction between different parts of the program, reducing their mutual dependencies.

The third program utilizes the "Template Method" pattern, defining a skeleton of an algorithm in the base class, with specific steps of this algorithm implemented in subclasses. This separates the general structure of the algorithm from its specific implementation, providing flexibility to modify individual steps of the algorithm without altering its overall structure.

All these patterns help make the programs more flexible, extensible, and maintainable in the future.