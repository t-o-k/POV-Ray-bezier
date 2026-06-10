# Bézier Geometry for POV-Ray

The `Bezier.inc` library is a POV-Ray SDL toolkit for working with Bézier curves, surfaces, and higher-dimensional analogues.
It is aimed at advanced POV-Ray users who need precise mathematical control over curved geometry.

It works with POV-Ray v3.7. It may also work with POV-Ray v3.8, but that has not been tested. 

**_NB: This is work in progress, so anything may change at any time._**

Here is what it provides:

## Mathematical foundations

- Combinatorial primitives: FactFn, CombFn, BinomialFn, FactFallingFn, FactRisingFn
- Bernstein basis functions and coefficients

## Function generation

- Converts arrays of control points into POV-Ray function objects that can be evaluated at any parameter value
- Supports 1 to 4 parameters (curves, surfaces, volumes, hyper-volumes)
- Both polynomial and rational (weighted) Bézier forms

## Differentiation

- Numerical derivatives via central differences (Est_Der*)
- Analytical derivatives via hodograph control polygons (Hodograph_*)

## Control point manipulation

- Array arithmetic: MultiplyArrays_*N, DivideArrays_*N, AddArrays_*N
- Component extraction: ExtractComponent_*N
- Array wrapping: From_?N_WrapArray
- Outer products: From_1N_OuterProduct_2N
- Degree elevation: DegreeElevate_?_?N (polynomial) and RationalDegreeElevate_?_?N (rational)

## Visualization / inspection

- Renders control cages as spheres and cylinders: From_?N_ShowPoints_*D, From_?N_ShowLines_*D, From_?N_ShowGrid_3D
- Renders sampled meshes: DrawPatch_3D
- Sampling: From_?A_SampleFunctions_?N_?D

## Naming conventions

- _?N suffix = number of array dimensions (1N through 4N)
- _?A suffix = number of function parameters / arity (1A through 4A)
- _?D suffix = coordinate space dimension (2D or 3D)
