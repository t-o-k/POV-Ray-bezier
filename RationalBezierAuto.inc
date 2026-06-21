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
