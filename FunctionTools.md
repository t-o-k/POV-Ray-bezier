# Include File: FunctionTools.inc

Technical reference for the utility functions and macros defined in `FunctionTools.inc`.

---

## Section 1: Mathematical Utility Functions

Scalar arithmetic wrapper functions to handle edge cases and interpreter behavior within the POV-Ray function layer.

---

### 1. PowFn(b, n)
A functional wrapper around POV-Ray's native `pow(A, B)` function. It isolates the operation inside a declared function block to suppress parsing-stage alerts for operations like `pow(0, 0)`, deferring evaluation to the rendering stage.

*   Definition: pow(b, n)
*   Domain Constraints: Subject to IEEE 754 floating-point constraints at runtime (e.g., negative bases with fractional exponents yield invalid results).
*   Examples:
    *   PowFn(2, 3) -> 8.0
    *   PowFn(-1, 2) -> 1.0
    *   PowFn(0, 0) -> 1.0
    *   PowFn(2.5, 2) -> 6.25
    *   PowFn(4, 0.5) -> 2.0

---

### 2. AvoidZeroFn(a)
A safety function used to prevent division-by-zero errors. If the argument is too close to zero, it forces the value outwards to a defined minimum threshold based on the constant `NIL` (1e-12), preserving the original positive or negative sign.

*   Definition: Returns a, but guarantees the value is never closer to zero than +/-1e-12.
*   Examples:
    *   AvoidZeroFn(0.5) -> 0.5
    *   AvoidZeroFn(0.0) -> 1e-12
    *   AvoidZeroFn(-1e-15) -> -1e-12

---

## Section 2: Core Combinatorial Functions

Scalar functions used to calculate coefficients for polynomial expansions, basis transformations, and analytical derivatives throughout this library.

WARNING: These functions are strictly designed for non-negative integers. They do not implement continuous Gamma function extensions and will return mathematically invalid values if supplied with fractional floating-point arguments.

By utilizing conditional evaluation, execution paths are isolated to prevent division-by-zero, arithmetic underflow, and invalid floating-point operations (such as not a number NaN or indeterminate IND forms).

---

### Technical Overview

*   FactFn(n): Range constraints: n >= 0, returns >= 1. Sequential product upwards from 1 to n.
*   FactFallingFn(n, k): Range constraints: n >= 0, k >= 0. Sequential product downwards for k factors.
*   FactRisingFn(n, k): Range constraints: n >= 0, k >= 0. Sequential product upwards for k factors.
*   CombFn(n, k): Range constraints: n >= 0, 0 <= k <= n. Calculates combinations (n choose k).
*   BinomialFn(n, k): Alias mapping directly to CombFn(n, k).

---

### 3. FactFn(n)
Computes the standard factorial (n!) for a non-negative integer.

*   Definition: n! = 1 * 2 * 3 * ... * n
*   Boundary Condition: If n = 0, the empty product evaluates to 1.
*   Examples:
    *   FactFn(3) -> 6
    *   FactFn(0) -> 1

---

### 4. FactFallingFn(n, k)
Computes the falling factorial (lower Pochhammer symbol, representing permutation count P(n, k)). It multiplies a sequence of k decreasing factors starting from n. Used to compute shifting coefficients for analytical differentiation.

*   Definition: n * (n - 1) * (n - 2) * ... * (n - k + 1)
*   Boundary Condition: If k = 0, the empty product evaluates to 1.
*   Examples:
    *   FactFallingFn(4, 2) -> 12
    *   FactFallingFn(3, 1) -> 3
    *   FactFallingFn(3, 0) -> 1

---

### 5. FactRisingFn(n, k)
Computes the rising factorial (upper Pochhammer symbol). It multiplies a sequence of k increasing factors starting from n.

*   Definition: n * (n + 1) * (n + 2) * ... * (n + k - 1)
*   Boundary Condition: If k = 0, the empty product evaluates to 1.
*   Examples:
    *   FactRisingFn(4, 3) -> 120
    *   FactRisingFn(2, 2) -> 6

---

### 6. CombFn(n, k)
Computes the standard binomial coefficient (combinations, "n choose k"). It uses falling factorials to evaluate combinations linearly without full factorials, minimizing rounding noise and precision loss.

*   Definition: FactFallingFn(n, k) / FactFn(k)
*   Boundary Conditions: If k = 0 or n = k, evaluates to 1. If k > n, evaluates to 0.
*   Examples:
    *   CombFn(4, 2) -> 6
    *   CombFn(3, 0) -> 1

---

### 7. BinomialFn(n, k)
An alias mapping directly to `CombFn(n, k)` to ensure standard terminology within statistical and polynomial expansions throughout this library.

*   Definition: Same as CombFn(n, k)
*   Examples:
    *   BinomialFn(3, 1) -> 3
    *   BinomialFn(5, 2) -> 10

---
