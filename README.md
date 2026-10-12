# Smart Delivery Planning – Fractional Knapsack

A menu-driven C program that implements the **Fractional Knapsack Problem** using the Greedy Algorithm to maximize the total value of packages carried within a fixed vehicle capacity.

## Problem Statement

Given a set of packages, each with a specific value and weight, determine the maximum possible value that can be carried in a vehicle with limited capacity. A package may be selected completely or fractionally.

## Objectives

- Understand and implement the Greedy Method.
- Calculate the value-to-weight ratio of each package.
- Sort packages in decreasing order of their ratios.
- Select complete packages whenever possible and a fraction when necessary.
- Calculate the maximum achievable value.
- Analyze the time complexity of the algorithm.

## Features

- Menu-driven interface.
- Accepts package values, weights, and vehicle capacity.
- Calculates value-to-weight ratios.
- Sorts packages using Selection Sort.
- Selects packages using the Fractional Knapsack Greedy Algorithm.
- Displays selected fractions, total weight used, and maximum value.

## Algorithm

1. Accept the number of packages, their values and weights, and the vehicle capacity.
2. Calculate the value-to-weight ratio for each package.
3. Sort the packages in decreasing order of their ratios using Selection Sort.
4. Select complete packages while they fit within the remaining capacity.
5. If a package does not fit completely, select the fraction that fits.
6. Update the total weight and total value.
7. Display the selected fractions and maximum achievable value.

## Sample Test Case

**Input**

| Package | Value | Weight |
|---|---:|---:|
| 1 | 40 | 5 |
| 2 | 30 | 10 |
| 3 | 50 | 5 |
| 4 | 20 | 4 |

Vehicle capacity: `15`

**Expected Output**

```text
Total Weight Used = 15.00
Maximum Value Obtained = 113.00
```

## Complexity Analysis

- **Time Complexity: O(n²)** — Selection Sort takes O(n²) time, while package selection takes O(n) time.
- **Auxiliary Space Complexity: O(1)** — The sorting and selection operations use a constant number of additional variables, excluding the arrays used to store the input and package details.

## Technologies Used

- Programming Language: C
- Algorithm: Greedy Method
- Sorting Technique: Selection Sort

## How to Run

1. Download `fractional_knapsack.c` from this repository.
2. Open it in a C compiler or IDE.
3. Compile and execute the program.
4. Follow the menu options to enter package details and calculate the maximum value.

## Result

The program successfully implements the Fractional Knapsack Greedy Algorithm and calculates the maximum achievable value for the given vehicle capacity.
