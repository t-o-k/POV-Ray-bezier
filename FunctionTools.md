# Include File: FunctionTools.inc

This document contains the technical reference for the utility functions and macros defined in `FunctionTools.inc`. 

---

## Section 1: Core Combinatorial Functions

This section documents the scalar factorial and sequential multiplication functions implemented inside `FunctionTools.inc`. These functions run inside the POV-Ray function virtual machine layer to calculate the exact coefficients for the Bernstein basis functions and their analytical polynomial derivatives.

WARNING: These functions are strictly designed for non-negative integers. They do not implement continuous Gamma function extensions and will return mathematically invalid values if supplied with fractional floating-point arguments.

By utilizing conditional evaluation, the execution paths are isolated to prevent division-by-zero, arithmetic underflow, and invalid floating-point operations (such as not a number NaN or indeterminate IND forms).

---

### Technical Overview

*   FactFn(n): Range constraints: n >= 0, returns >= 1. Sequential product upwards from 1 to n.
*   FactFallingFn(n, k): Range constraints: n >= 0, k >= 0. Sequential product downwards for k factors.
*   FactRisingFn(n, k): Range constraints: n >= 0, k >= 0. Sequential product upwards for k factors.
*   CombFn(n, k): Range constraints: n >= 0, 0 <= k <= n. Calculates standard combinations (n choose k).
*   BinomialFn(n, k): Alias mapping directly to CombFn(n, k).

---

### 1. FactFn(n)
Computes the standard factorial (n!) for a non-negative integer argument.

*   Definition: n! = 1 * 2 * 3 * ... * n
*   Boundary condition: If n = 0, the empty product evaluates to 1.
*   Examples:
    *   FactFn(3) -> 1 * 2 * 3 = 6
    *   FactFn(0) -> 1

---

### 2. FactFallingFn(n, k)
Computes the falling factorial (the lower Pochhammer symbol, representing the permutation count P(n, k)). It multiplies a sequence of k decreasing factors starting from n. This function computes the shifting coefficients when curves or surfaces are transformed into a monomial basis via analytical differentiation.

*   Definition: n * (n - 1) * (n - 2) * ... * (n - k + 1)
*   Boundary condition: If k = 0, the empty product evaluates to 1.
*   Examples:
    *   FactFallingFn(4, 2) -> 4 * 3 = 12
    *   FactFallingFn(3, 1) -> 3
    *   FactFallingFn(3, 0) -> 1

---

### 3. FactRisingFn(n, k)
Computes the rising factorial (the upper Pochhammer symbol). It multiplies a sequence of k increasing factors starting from n.

*   Definition: n * (n + 1) * (n + 2) * ... * (n + k - 1)
*   Boundary condition: If k = 0, the empty product evaluates to 1.
*   Examples:
    *   FactRisingFn(4, 3) -> 4 * 5 * 6 = 120
    *   FactRisingFn(2, 2) -> 2 * 3 = 6

---

### 4. CombFn(n, k)
Computes the standard binomial coefficient (the number of distinct combinations, commonly expressed as "n choose k"). This function uses optimized paths and falling factorials to evaluate combinations linearly without calculating the full factorials of large numbers, which minimizes rounding noise and precision loss.

*   Definition: FactFallingFn(n, k) / FactFn(k)
*   Boundary conditions: If k = 0 or n = k, the function short-circuits and evaluates to 1. If k > n, the evaluation path yields 0.
*   Examples:
    *   CombFn(4, 2) -> (4 * 3) / (2 * 1) = 6
    *   CombFn(3, 0) -> 1

---

### 5. BinomialFn(n, k)
An alias mapping directly to CombFn(n, k). It provides a redundant syntactic layout ensuring code readability and standard terminology within statistical and polynomial expansions throughout this library.

*   Definition: Same as CombFn(n, k)
*   Examples:
    *   BinomialFn(3, 1) -> 3
    *   BinomialFn(5, 2) -> 10

---
