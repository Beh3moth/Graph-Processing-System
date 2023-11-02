# Graph Processing System

This program is designed to process graphs, specifically focusing on tasks such as calculating distances using Dijkstra's algorithm and ranking the graphs based on certain criteria. The program takes input from the standard input and processes the data accordingly.

## Prerequisites

- C compiler

## Getting Started

To get started with this program, follow these steps:

1. Clone the repository to your local machine.
2. Compile the program using the provided Makefile or any C compiler.
3. Run the executable with the necessary input.

## Usage

The program reads input from the standard input and executes the following commands:

1. **TopK:** Prints the top K ranked graphs based on the specified criteria.
2. **AggiungiGrafo:** Adds a new graph and calculates the distance using Dijkstra's algorithm.

## File Structure

- `main.c`: Contains the main logic of the program, including the input processing and command execution.
- `library.h`: Header file containing function prototypes and necessary definitions.
- `library.c`: Source file containing function implementations for various operations, including text management, matrix management, priority queue management, Dijkstra algorithm, and ranking functions.

## How to Run

Compile the program using the following command:

```bash
gcc main.c library.c -o program
```

Run the program and provide the necessary input through the standard input.

```bash
./program
```

## Contributors

- [Federico Camilletti]
