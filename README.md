# Logic Calculator

## Building and Running
To build this program first navigate to the project directory. For example:

```console
cd ~/Documents/GitHub/LogicCalculator
```

Then make a new directory called build:

```console
mkdir build
```

Then navigate into the new build directory and run the following commands:

```console
cd build
cmake ..
make
```

After, to execute, do this command in the terminal.

```console
./LogicCalculator
```

The terminal will then prompt for a logical statement to create a truth table from. 
Please use paranthesis for each logical component to explicity separate the left and right sides. 

For example, instead of

```console
(a ^ c) -> (a -> b) ^ (c ^ d) -> (a -> d) -> (a -> c)
```
Use extra paranthesis to explicity show each statement.
```console
(((a ^ c) -> (a -> b)) ^ ((c ^ d) -> (a -> d))) -> (a -> c)
```

For the union operator, use a 'v' symbol. 

For the intersection operator, use a '^' symbol.

For the if-then operator, use '->'.

## About

This program takes an input of a string from the command line and creates a truth table for the statement.

One of the key parts of this course was the logical portion of it. 
Computers are complicated systems that require a lot of calculation and logical rules.
Without them, they are just piles of silicon and glass. 
In our project, we break down these logical rules and show the behind the scenes that connect these complex symbols with
ones and zeroes. 

What is important about this project is its step-by-step method of parsing and understanding the 