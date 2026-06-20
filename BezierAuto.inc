// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B
/*

https://github.com/t-o-k/POV-Ray-bezier

Copyright (c) 2025-2026 Tor Olav Kristensen, http://subcube.com

Use of this source code is governed by the GNU Lesser General Public License version 3,
which can be found in the LICENSE file.

*/
// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#version 3.7;

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro ExtractComponent(Vectors, vC)

    #local N = dimensions(Vectors);

    #switch (N)
        #case (1)  // 1N
            #local CC =
                ExtractComponent_1N(Vectors, vC)
            ;
            #break
        #case (2)  // 2N
            #local CC =
                ExtractComponent_2N(Vectors, vC)
            ;
            #break
        #case (3)  // 3N
            #local CC =
                ExtractComponent_3N(Vectors, vC)
            ;
            #break
        #case (4)  // 4N
            #local CC =
                ExtractComponent_4N(Vectors, vC)
            ;
            #break
        #else
            #error "N is neither 1, 2, 3 nor 4"
    #end // switch

    CC

#end // macro ExtractComponent


#macro UniformWeights(DimensionSizes, Constant)

    #local M = dimensions(DimensionSizes);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local N = dimension_size(DimensionSizes, 1);
    #switch (N)
        #case (1)  // 1N
            #local WW =
                UniformWeights_1N(
                    DimensionSizes, Constant
                )
            ;
            #break
        #case (2)  // 2N
            #local WW =
                UniformWeights_2N(
                    DimensionSizes, Constant
                )
            ;
            #break
        #case (3)  // 3N
            #local WW =
                UniformWeights_3N(
                    DimensionSizes, Constant
                )
            ;
            #break
        #case (4)  // 4N
            #local WW =
                UniformWeights_4N(
                    DimensionSizes, Constant
                )
            ;
            #break
        #else
            #error "N is neither 1, 2, 3 nor 4"
    #end // switch

    WW

#end // macro UniformWeights


#macro BezierFunction(Values)

    #local N = dimensions(Values);

    #switch (N)
        #case (1)  // 1A 1N
            From_1N_BezierFunction_1A(
                Values
            )
            #break
        #case (2)  // 2A 2N
            From_2N_BezierFunction_2A(
                Values
            )
            #break
        #case (3)  // 3A 3N
            From_3N_BezierFunction_3A(
                Values
            )
            #break
        #case (4)  // 4A 4N
            From_4N_BezierFunction_4A(
                Values
            )
            #break
        #else
            #error "N is neither 1, 2, 3 nor 4"
    #end // switch

#end // macro BezierFunction


#macro BezierFunctions_2D(Points_2D)

    #local N = dimensions(Points_2D);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if

    Arr_2E(
        BezierFunction(
            ExtractComponent(Points_2D, x)
        ),
        BezierFunction(
            ExtractComponent(Points_2D, y)
        )
    )

#end // macro BezierFunctions_2D


#macro BezierFunctions_3D(Points_3D)

    #local N = dimensions(Points_3D);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if

    Arr_3E(
        BezierFunction(
            ExtractComponent(Points_3D, x)
        ),
        BezierFunction(
            ExtractComponent(Points_3D, y)
        ),
        BezierFunction(
            ExtractComponent(Points_3D, z)
        )
    )

#end // macro BezierFunctions_3D


#macro RationalBezierFunction(Values, Weights)

    #local N = dimensions(Values);
    #if (dimensions(Weights) != N)
        #error "Is not equal to N"
    #end // if

    #switch (N)
        #case (1)  // 1N
            From_1N_RationalBezierFunction_1A(
                Values, Weights
            )
            #break
        #case (2)  // 2N
            From_2N_RationalBezierFunction_2A(
                Values, Weights
            )
            #break
        #case (3)  // 3N
            From_3N_RationalBezierFunction_3A(
                Values, Weights
            )
            #break
        #case (4)  // 4N
            From_4N_RationalBezierFunction_4A(
                Values, Weights
            )
            #break
        #else
            #error "N is neither 1, 2, 3 nor 4"
    #end // switch

#end // macro RationalBezierFunction


#macro RationalBezierFunctions_2D(Points_2D, Weights)

    #local N = dimensions(Points_2D);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if
    #if (dimensions(Weights) != N)
        #error "Is not equal to N"
    #end // if
 
    Arr_2E(
        RationalBezierFunction(
            ExtractComponent(Points_2D, x), Weights
        ),
        RationalBezierFunction(
            ExtractComponent(Points_2D, y), Weights
        )
    )

#end // macro RationalBezierFunctions_2D


#macro RationalBezierFunctions_3D(Points_3D, Weights)

    #local N = dimensions(Points_3D);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if
    #if (dimensions(Weights) != N)
        #error "Is not equal to N"
    #end // if

    Arr_3E(
        RationalBezierFunction(
            ExtractComponent(Points_3D, x), Weights
        ),
        RationalBezierFunction(
            ExtractComponent(Points_3D, y), Weights
        ),
        RationalBezierFunction(
            ExtractComponent(Points_3D, z), Weights
        )
    )

#end // macro RationalBezierFunctions_3D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro Der1_BezierFunctions(Values)

    #local N = dimensions(Values);

    #switch (N)
        #case (1)
            Der1_BezierFunctions_1A(
                Values
            )
            #break
        #case (2)
            Der1_BezierFunctions_2A(
                Values
             )
            #break
        #case (3)
            Der1_BezierFunctions_3A(
                Values
            )
            #break
        #case (4)
            Der1_BezierFunctions_4A(
                Values
            )
            #break
        #else
            #error "N is neither 1, 2, 3 nor 4"
    #end // switch

#end // macro Der1_BezierFunctions


#macro Der2_BezierFunctions(Values)

    #local N = dimensions(Values);

    #switch (N)
        #case (1)
            Der2_BezierFunctions_1A(
                Values
            )
            #break
        #case (2)
            Der2_BezierFunctions_2A(
                Values
             )
            #break
        #case (3)
            Der2_BezierFunctions_3A(
                Values
            )
            #break
        #case (4)
            Der2_BezierFunctions_4A(
                Values
            )
            #break
        #else
            #error "N is neither 1, 2, 3 nor 4"
    #end // switch

#end // macro Der2_BezierFunctions


#macro Der1_RationalBezierFunctions(Values, Weights)

    #local N = dimensions(Values);
    #if (dimensions(Weights) != N)
        #error "Is not equal to N"
    #end // if

    #switch (N)
        #case (1)
            Der1_RationalBezierFunctions_1A(
                Values, Weights
            )
            #break
        #case (2)
            Der1_RationalBezierFunctions_2A(
                Values, Weights
             )
            #break
        #case (3)
            Der1_RationalBezierFunctions_3A(
                Values, Weights
            )
            #break
        #case (4)
            Der1_RationalBezierFunctions_4A(
                Values, Weights
            )
            #break
        #else
            #error "N is neither 1, 2, 3 nor 4"
    #end // switch

#end // macro Der1_RationalBezierFunctions


#macro Der2_RationalBezierFunctions(Values, Weights)

    #local N = dimensions(Values);
    #if (dimensions(Weights) != N)
        #error "Is not equal to N"
    #end // if

    #switch (N)
        #case (1)
            Der2_RationalBezierFunctions_1A(
                Values, Weights
            )
            #break
        #case (2)
            Der2_RationalBezierFunctions_2A(
                Values, Weights
             )
            #break
        #case (3)
            Der2_RationalBezierFunctions_3A(
                Values, Weights
            )
            #break
        #case (4)
            Der2_RationalBezierFunctions_4A(
                Values, Weights
            )
            #break
        #else
            #error "N is neither 1, 2, 3 nor 4"
    #end // switch

#end // macro Der2_RationalBezierFunctions

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B
