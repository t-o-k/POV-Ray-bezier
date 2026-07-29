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

#macro From_1N_RationalBezierFunction_1A(Values_1N, Weights_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Weights_1N) != 1)
        #error "Is not 1"
    #end // if

    DivideFunction_1A(
        From_1N_BezierFunction_1A(
            MultiplyArrays_1N(
                Weights_1N, Values_1N
            )
        ),
        From_1N_BezierFunction_1A(
            Weights_1N
        )
    )

#end // macro From_1N_RationalBezierFunction_1A


#macro From_2N_RationalBezierFunction_2A(Values_2N, Weights_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != 2)
        #error "Is not 2"
    #end // if

    DivideFunction_2A(
        From_2N_BezierFunction_2A(
            MultiplyArrays_2N(
                Weights_2N, Values_2N
            )
        ),
        From_2N_BezierFunction_2A(
            Weights_2N
        )
    )

#end // macro From_2N_RationalBezierFunction_2A


#macro From_3N_RationalBezierFunction_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if

    DivideFunction_3A(
        From_3N_BezierFunction_3A(
            MultiplyArrays_3N(
                Weights_3N, Values_3N
            )
        ),
        From_3N_BezierFunction_3A(
            Weights_3N
        )
    )

#end // macro From_3N_RationalBezierFunction_3A


#macro From_4N_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if

    DivideFunction_4A(
        From_4N_BezierFunction_4A(
            MultiplyArrays_4N(
                Weights_4N, Values_4N
            )
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        )
    )

#end // macro From_4N_RationalBezierFunction_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_1N_RationalBezierFunctions_1A_2D(Points_1N_2D, Weights_1N)

    #local N = dimensions(Points_1N_2D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Weights_1N) != N)
        #error "Is not equal to N"
    #end // if

    Arr_2E(
        From_1N_RationalBezierFunction_1A(
            From_1N_ExtractComponent_1N(Points_1N_2D, x),
            Weights_1N
        ),
        From_1N_RationalBezierFunction_1A(
            From_1N_ExtractComponent_1N(Points_1N_2D, y),
            Weights_1N
        )
    )

#end // macro From_1N_RationalBezierFunctions_1A_2D


#macro From_2N_RationalBezierFunctions_2A_2D(Points_2N_2D, Weights_2N)

    #local N = dimensions(Points_2N_2D);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != N)
        #error "Is not equal to N"
    #end // if

    Arr_2E(
        From_2N_RationalBezierFunction_2A(
            From_2N_ExtractComponent_2N(Points_2N_2D, x),
            Weights_2N
        ),
        From_2N_RationalBezierFunction_2A(
            From_2N_ExtractComponent_2N(Points_2N_2D, y),
            Weights_2N
        )
    )

#end // macro From_2N_RationalBezierFunctions_2A_2D


#macro From_3N_RationalBezierFunctions_3A_2D(Points_3N_2D, Weights_3N)

    #local N = dimensions(Points_3N_2D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != N)
        #error "Is not equal to N"
    #end // if

    Arr_2E(
        From_3N_RationalBezierFunction_3A(
            From_3N_ExtractComponent_3N(Points_3N_2D, x),
            Weights_3N
        ),
        From_3N_RationalBezierFunction_3A(
            From_3N_ExtractComponent_3N(Points_3N_2D, y),
            Weights_3N
        )
    )

#end // macro From_3N_RationalBezierFunctions_3A_2D


#macro From_4N_RationalBezierFunctions_4A_2D(Points_4N_2D, Weights_4N)

    #local N = dimensions(Points_4N_2D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != N)
        #error "Is not equal to N"
    #end // if

    Arr_2E(
        From_4N_RationalBezierFunction_4A(
            From_4N_ExtractComponent_4N(Points_4N_2D, x),
            Weights_4N
        ),
        From_4N_RationalBezierFunction_4A(
            From_4N_ExtractComponent_4N(Points_4N_2D, y),
            Weights_4N
        )
    )

#end // macro From_4N_RationalBezierFunctions_4A_2D


#macro From_1N_RationalBezierFunctions_1A_3D(Points_1N_3D, Weights_1N)

    #local N = dimensions(Points_1N_3D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Weights_1N) != N)
        #error "Is not equal to N"
    #end // if

    Arr_3E(
        From_1N_RationalBezierFunction_1A(
            From_1N_ExtractComponent_1N(Points_1N_3D, x),
            Weights_1N
        ),
        From_1N_RationalBezierFunction_1A(
            From_1N_ExtractComponent_1N(Points_1N_3D, y),
            Weights_1N
        ),
        From_1N_RationalBezierFunction_1A(
            From_1N_ExtractComponent_1N(Points_1N_3D, z),
            Weights_1N
        )
    )

#end // macro From_1N_RationalBezierFunctions_1A_3D


#macro From_2N_RationalBezierFunctions_2A_3D(Points_2N_3D, Weights_2N)

    #local N = dimensions(Points_2N_3D);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != N)
        #error "Is not equal to N"
    #end // if

    Arr_3E(
        From_2N_RationalBezierFunction_2A(
            From_2N_ExtractComponent_2N(Points_2N_3D, x),
            Weights_2N
        ),
        From_2N_RationalBezierFunction_2A(
            From_2N_ExtractComponent_2N(Points_2N_3D, y),
            Weights_2N
        ),
        From_2N_RationalBezierFunction_2A(
            From_2N_ExtractComponent_2N(Points_2N_3D, z),
            Weights_2N
        )
    )

#end // macro From_2N_RationalBezierFunctions_2A_3D


#macro From_3N_RationalBezierFunctions_3A_3D(Points_3N_3D, Weights_3N)

    #local N = dimensions(Points_3N_3D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != N)
        #error "Is not equal to N"
    #end // if

    Arr_3E(
        From_3N_RationalBezierFunction_3A(
            From_3N_ExtractComponent_3N(Points_3N_3D, x),
            Weights_3N
        ),
        From_3N_RationalBezierFunction_3A(
            From_3N_ExtractComponent_3N(Points_3N_3D, y),
            Weights_3N
        ),
        From_3N_RationalBezierFunction_3A(
            From_3N_ExtractComponent_3N(Points_3N_3D, z),
            Weights_3N
        )
    )

#end // macro From_3N_RationalBezierFunctions_3A_3D


#macro From_4N_RationalBezierFunctions_4A_3D(Points_4N_3D, Weights_4N)

    #local N = dimensions(Points_4N_3D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != N)
        #error "Is not equal to N"
    #end // if

    Arr_3E(
        From_4N_RationalBezierFunction_4A(
            From_4N_ExtractComponent_4N(Points_4N_3D, x),
            Weights_4N
        ),
        From_4N_RationalBezierFunction_4A(
            From_4N_ExtractComponent_4N(Points_4N_3D, y),
            Weights_4N
        ),
        From_4N_RationalBezierFunction_4A(
            From_4N_ExtractComponent_4N(Points_4N_3D, z),
            Weights_4N
        )
    )

#end // macro From_4N_RationalBezierFunctions_4A_3D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro RationalDegreeElevate_I_1N(ValuesOrPoints_1N, Weights_1N, NoOfDegrees)

    #local WeightedValuesOrPoints_1N =
        MultiplyArrays_1N(
            ValuesOrPoints_1N,
            Weights_1N
        )
    ;
    #local ElevatedWeightedValuesOrPoints_1N =
        DegreeElevate_I_1N(
            WeightedValuesOrPoints_1N,
            NoOfDegrees
        )
    ;
    #local ElevatedWeights_1N =
        DegreeElevate_I_1N(
            Weights_1N,
            NoOfDegrees
        )
    ;

    DivideArrays_1N(
        ElevatedWeightedValuesOrPoints_1N,
        ElevatedWeights_1N
    )

#end // macro RationalDegreeElevate_I_1N


#macro RationalDegreeElevate_I_2N(ValuesOrPoints_2N, Weights_2N, NoOfDegrees)

    #local WeightedValuesOrPoints_2N =
        MultiplyArrays_2N(
            ValuesOrPoints_2N,
            Weights_2N
        )
    ;
    #local ElevatedWeightedValuesOrPoints_2N =
        DegreeElevate_I_2N(
            WeightedValuesOrPoints_2N,
            NoOfDegrees
        )
    ;
    #local ElevatedWeights_2N =
        DegreeElevate_I_2N(
            Weights_2N,
            NoOfDegrees
        )
    ;

    DivideArrays_2N(
        ElevatedWeightedValuesOrPoints_2N,
        ElevatedWeights_2N
    )

#end // macro RationalDegreeElevate_I_2N


#macro RationalDegreeElevate_J_2N(ValuesOrPoints_2N, Weights_2N, NoOfDegrees)

    #local WeightedValuesOrPoints_2N =
        MultiplyArrays_2N(
            ValuesOrPoints_2N,
            Weights_2N
        )
    ;
    #local ElevatedWeightedValuesOrPoints_2N =
        DegreeElevate_J_2N(
            WeightedValuesOrPoints_2N,
            NoOfDegrees
        )
    ;
    #local ElevatedWeights_2N =
        DegreeElevate_J_2N(
            Weights_2N,
            NoOfDegrees
        )
    ;

    DivideArrays_2N(
        ElevatedWeightedValuesOrPoints_2N,
        ElevatedWeights_2N
    )

#end // macro RationalDegreeElevate_J_2N


#macro RationalDegreeElevate_I_3N(ValuesOrPoints_3N, Weights_3N, NoOfDegrees)

    #local WeightedValuesOrPoints_3N =
        MultiplyArrays_3N(
            ValuesOrPoints_3N,
            Weights_3N
        )
    ;
    #local ElevatedWeightedValuesOrPoints_3N =
        DegreeElevate_I_3N(
            WeightedValuesOrPoints_3N,
            NoOfDegrees
        )
    ;
    #local ElevatedWeights_3N =
        DegreeElevate_I_3N(
            Weights_3N,
            NoOfDegrees
        )
    ;

    DivideArrays_3N(
        ElevatedWeightedValuesOrPoints_3N,
        ElevatedWeights_3N
    )

#end // macro RationalDegreeElevate_I_3N


#macro RationalDegreeElevate_J_3N(ValuesOrPoints_3N, Weights_3N, NoOfDegrees)

    #local WeightedValuesOrPoints_3N =
        MultiplyArrays_3N(
            ValuesOrPoints_3N,
            Weights_3N
        )
    ;
    #local ElevatedWeightedValuesOrPoints_3N =
        DegreeElevate_J_3N(
            WeightedValuesOrPoints_3N,
            NoOfDegrees
        )
    ;
    #local ElevatedWeights_3N =
        DegreeElevate_J_3N(
            Weights_3N,
            NoOfDegrees
        )
    ;

    DivideArrays_3N(
        ElevatedWeightedValuesOrPoints_3N,
        ElevatedWeights_3N
    )

#end // macro RationalDegreeElevate_J_3N


#macro RationalDegreeElevate_K_3N(ValuesOrPoints_3N, Weights_3N, NoOfDegrees)

    #local WeightedValuesOrPoints_3N =
        MultiplyArrays_3N(
            ValuesOrPoints_3N,
            Weights_3N
        )
    ;
    #local ElevatedWeightedValuesOrPoints_3N =
        DegreeElevate_K_3N(
            WeightedValuesOrPoints_3N,
            NoOfDegrees
        )
    ;
    #local ElevatedWeights_3N =
        DegreeElevate_K_3N(
            Weights_3N,
            NoOfDegrees
        )
    ;

    DivideArrays_3N(
        ElevatedWeightedValuesOrPoints_3N,
        ElevatedWeights_3N
    )

#end // macro RationalDegreeElevate_K_3N


#macro RationalDegreeElevate_I_4N(ValuesOrPoints_4N, Weights_4N, NoOfDegrees)

    #local WeightedValuesOrPoints_4N =
        MultiplyArrays_4N(
            ValuesOrPoints_4N,
            Weights_4N
        )
    ;
    #local ElevatedWeightedValuesOrPoints_4N =
        DegreeElevate_I_4N(
            WeightedValuesOrPoints_4N,
            NoOfDegrees
        )
    ;
    #local ElevatedWeights_4N =
        DegreeElevate_I_4N(
            Weights_4N,
            NoOfDegrees
        )
    ;

    DivideArrays_4N(
        ElevatedWeightedValuesOrPoints_4N,
        ElevatedWeights_4N
    )

#end // macro RationalDegreeElevate_I_4N


#macro RationalDegreeElevate_J_4N(ValuesOrPoints_4N, Weights_4N, NoOfDegrees)

    #local WeightedValuesOrPoints_4N =
        MultiplyArrays_4N(
            ValuesOrPoints_4N,
            Weights_4N
        )
    ;
    #local ElevatedWeightedValuesOrPoints_4N =
        DegreeElevate_J_4N(
            WeightedValuesOrPoints_4N,
            NoOfDegrees
        )
    ;
    #local ElevatedWeights_4N =
        DegreeElevate_J_4N(
            Weights_4N,
            NoOfDegrees
        )
    ;

    DivideArrays_4N(
        ElevatedWeightedValuesOrPoints_4N,
        ElevatedWeights_4N
    )

#end // macro RationalDegreeElevate_J_4N


#macro RationalDegreeElevate_K_4N(ValuesOrPoints_4N, Weights_4N, NoOfDegrees)

    #local WeightedValuesOrPoints_4N =
        MultiplyArrays_4N(
            ValuesOrPoints_4N,
            Weights_4N
        )
    ;
    #local ElevatedWeightedValuesOrPoints_4N =
        DegreeElevate_K_4N(
            WeightedValuesOrPoints_4N,
            NoOfDegrees
        )
    ;
    #local ElevatedWeights_4N =
        DegreeElevate_K_4N(
            Weights_4N,
            NoOfDegrees
        )
    ;

    DivideArrays_4N(
        ElevatedWeightedValuesOrPoints_4N,
        ElevatedWeights_4N
    )

#end // macro RationalDegreeElevate_K_4N


#macro RationalDegreeElevate_L_4N(ValuesOrPoints_4N, Weights_4N, NoOfDegrees)

    #local WeightedValuesOrPoints_4N =
        MultiplyArrays_4N(
            ValuesOrPoints_4N,
            Weights_4N
        )
    ;
    #local ElevatedWeightedValuesOrPoints_4N =
        DegreeElevate_L_4N(
            WeightedValuesOrPoints_4N,
            NoOfDegrees
        )
    ;
    #local ElevatedWeights_4N =
        DegreeElevate_L_4N(
            Weights_4N,
            NoOfDegrees
        )
    ;

    DivideArrays_4N(
        ElevatedWeightedValuesOrPoints_4N,
        ElevatedWeights_4N
    )

#end // macro RationalDegreeElevate_L_4N

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_1N_DerU_RationalBezierFunction_1A(Values_1N, Weights_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Weights_1N) != 1)
        #error "Is not 1"
    #end // if
    #if (DimSize_I(Values_1N) != DimSize_I(Weights_1N))
        #error "Are not equal"
    #end // if
    #if (DimSize_I(Values_1N) < 2)
        #error "Is less than 2"
    #end // if
    #local WeightedValues_1N =
        MultiplyArrays_1N(
            Values_1N, Weights_1N
        )
    ;

    Der1_RationalFunction_1A(
        From_1N_BezierFunction_1A(
            WeightedValues_1N
        ),
        From_1N_BezierFunction_1A(
            Weights_1N
        ),
        From_1N_BezierFunction_1A(
            Hodograph_I_1N(
                WeightedValues_1N, 1
            )
        ),
        From_1N_BezierFunction_1A(
            Hodograph_I_1N(
                Weights_1N, 1
            )
        )
    )

#end // macro From_1N_DerU_RationalBezierFunction_1A


#macro Der1_RationalBezierFunctions_1A(Values_1N, Weights_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Weights_1N) != 1)
        #error "Is not 1"
    #end // if
    #if (DimSize_I(Values_1N) != DimSize_I(Weights_1N))
        #error "Are not equal"
    #end // if

    Arr_1E(
        From_1N_DerU_RationalBezierFunction_1A(
            Values_1N, Weights_1N
        )
    )

#end // macro Der1_RationalBezierFunctions_1A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_2N_DerU_RationalBezierFunction_2A(Values_2N, Weights_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != 2)
        #error "Is not 2"
    #end // if
    #if (DimSize_I(Values_2N) != DimSize_I(Weights_2N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_2N) != DimSize_J(Weights_2N))
        #error "Are not equal"
    #end // if
    #if (DimSize_I(Values_2N) < 2)
        #error "Is less than 2"
    #end // if
    #local WeightedValues_2N =
        MultiplyArrays_2N(
            Values_2N, Weights_2N
        )
    ;

    Der1_RationalFunction_2A(
        From_2N_BezierFunction_2A(
            WeightedValues_2N
        ),
        From_2N_BezierFunction_2A(
            Weights_2N
        ),
        From_2N_BezierFunction_2A(
            Hodograph_I_2N(
                WeightedValues_2N, 1
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_I_2N(
                Weights_2N, 1
            )
        )
    )

#end // macro From_2N_DerU_RationalBezierFunction_2A


#macro From_2N_DerV_RationalBezierFunction_2A(Values_2N, Weights_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != 2)
        #error "Is not 2"
    #end // if
    #if (DimSize_I(Values_2N) != DimSize_I(Weights_2N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_2N) != DimSize_J(Weights_2N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_2N) < 2)
        #error "Is less than 2"
    #end // if
    #local WeightedValues_2N =
        MultiplyArrays_2N(
            Values_2N, Weights_2N
        )
    ;

    Der1_RationalFunction_2A(
        From_2N_BezierFunction_2A(
            WeightedValues_2N
        ),
        From_2N_BezierFunction_2A(
            Weights_2N
        ),
        From_2N_BezierFunction_2A(
            Hodograph_J_2N(
                WeightedValues_2N, 1
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_J_2N(
                Weights_2N, 1
            )
        )
    )

#end // macro From_2N_DerV_RationalBezierFunction_2A


#macro Der1_RationalBezierFunctions_2A(Values_2N, Weights_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != 2)
        #error "Is not 2"
    #end // if
    #if (DimSize_I(Values_2N) != DimSize_I(Weights_2N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_2N) != DimSize_J(Weights_2N))
        #error "Are not equal"
    #end // if

    Arr_2E(
        From_2N_DerU_RationalBezierFunction_2A(
            Values_2N, Weights_2N
        ),
        From_2N_DerV_RationalBezierFunction_2A(
            Values_2N, Weights_2N
        )
    )

#end // macro Der1_RationalBezierFunctions_2A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_3N_DerU_RationalBezierFunction_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (DimSize_I(Values_3N) != DimSize_I(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_3N) != DimSize_J(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_3N) != DimSize_K(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_I(Values_3N) < 2)
        #error "Is less than 2"
    #end // if
    #local WeightedValues_3N =
        MultiplyArrays_3N(
            Values_3N, Weights_3N
        )
    ;

    Der1_RationalFunction_3A(
        From_3N_BezierFunction_3A(
            WeightedValues_3N
        ),
        From_3N_BezierFunction_3A(
            Weights_3N
        ),
        From_3N_BezierFunction_3A(
            Hodograph_I_3N(
                WeightedValues_3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_I_3N(
                Weights_3N, 1
            )
        )
    )

#end // macro From_3N_DerU_RationalBezierFunction_3A


#macro From_3N_DerV_RationalBezierFunction_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (DimSize_I(Values_3N) != DimSize_I(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_3N) != DimSize_J(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_3N) != DimSize_K(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_3N) < 2)
        #error "Is less than 2"
    #end // if
    #local WeightedValues_3N =
        MultiplyArrays_3N(
            Values_3N, Weights_3N
        )
    ;

    Der1_RationalFunction_3A(
        From_3N_BezierFunction_3A(
            WeightedValues_3N
        ),
        From_3N_BezierFunction_3A(
            Weights_3N
        ),
        From_3N_BezierFunction_3A(
            Hodograph_J_3N(
                WeightedValues_3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_J_3N(
                Weights_3N, 1
            )
        )
    )

#end // macro From_3N_DerV_RationalBezierFunction_3A


#macro From_3N_DerW_RationalBezierFunction_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (DimSize_I(Values_3N) != DimSize_I(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_3N) != DimSize_J(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_3N) != DimSize_K(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_3N) < 2)
        #error "Is less than 2"
    #end // if
    #local WeightedValues_3N =
        MultiplyArrays_3N(
            Values_3N, Weights_3N
        )
    ;

    Der1_RationalFunction_3A(
        From_3N_BezierFunction_3A(
            WeightedValues_3N
        ),
        From_3N_BezierFunction_3A(
            Weights_3N
        ),
        From_3N_BezierFunction_3A(
            Hodograph_K_3N(
                WeightedValues_3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_K_3N(
                Weights_3N, 1
            )
        )
    )

#end // macro From_3N_DerW_RationalBezierFunction_3A


#macro Der1_RationalBezierFunctions_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (DimSize_I(Values_3N) != DimSize_I(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_3N) != DimSize_J(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_3N) != DimSize_K(Weights_3N))
        #error "Are not equal"
    #end // if

    Arr_3E(
        From_3N_DerU_RationalBezierFunction_3A(
            Values_3N, Weights_3N
        ),
        From_3N_DerV_RationalBezierFunction_3A(
            Values_3N, Weights_3N
        ),
        From_3N_DerW_RationalBezierFunction_3A(
            Values_3N, Weights_3N
        )
    )

#end // macro Der1_RationalBezierFunctions_3A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_4N_DerU_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (DimSize_I(Values_4N) != DimSize_I(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_4N) != DimSize_J(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_4N) != DimSize_K(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_L(Values_4N) != DimSize_L(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_I(Values_4N) < 2)
        #error "Is less than 2"
    #end // if
    #local WeightedValues_4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der1_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            WeightedValues_4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_I_4N(
                WeightedValues_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_I_4N(
                Weights_4N, 1
            )
        )
    )

#end // macro From_4N_DerU_RationalBezierFunction_4A


#macro From_4N_DerV_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (DimSize_I(Values_4N) != DimSize_I(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_4N) != DimSize_J(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_4N) != DimSize_K(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_L(Values_4N) != DimSize_L(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_4N) < 2)
        #error "Is less than 2"
    #end // if
    #local WeightedValues_4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der1_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            WeightedValues_4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_J_4N(
                WeightedValues_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_J_4N(
                Weights_4N, 1
            )
        )
    )

#end // macro From_4N_DerV_RationalBezierFunction_4A


#macro From_4N_DerW_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (DimSize_I(Values_4N) != DimSize_I(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_4N) != DimSize_J(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_4N) != DimSize_K(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_L(Values_4N) != DimSize_L(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_4N) < 2)
        #error "Is less than 2"
    #end // if
    #local WeightedValues_4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der1_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            WeightedValues_4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_K_4N(
                WeightedValues_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_K_4N(
                Weights_4N, 1
            )
        )
    )

#end // macro From_4N_DerW_RationalBezierFunction_4A


#macro From_4N_DerS_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (DimSize_I(Values_4N) != DimSize_I(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_4N) != DimSize_J(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_4N) != DimSize_K(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_L(Values_4N) != DimSize_L(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_L(Values_4N) < 2)
        #error "Is less than 2"
    #end // if
    #local WeightedValues_4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der1_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            WeightedValues_4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_L_4N(
                WeightedValues_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_L_4N(
                Weights_4N, 1
            )
        )
    )

#end // macro From_4N_DerS_RationalBezierFunction_4A


#macro Der1_RationalBezierFunctions_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (DimSize_I(Values_4N) != DimSize_I(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_4N) != DimSize_J(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_4N) != DimSize_K(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_L(Values_4N) != DimSize_L(Weights_4N))
        #error "Are not equal"
    #end // if

    Arr_4E(
        From_4N_DerU_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        ),
        From_4N_DerV_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        ),
        From_4N_DerW_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        ),
        From_4N_DerS_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        )
    )

#end // macro Der1_RationalBezierFunctions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_1N_DerUU_RationalBezierFunction_1A(Values_1N, Weights_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Weights_1N) != 1)
        #error "Is not 1"
    #end // if
    #if (DimSize_I(Values_1N) != DimSize_I(Weights_1N))
        #error "Are not equal"
    #end // if
    #if (DimSize_I(Values_1N) < 3)
        #error "Is less than 3"
    #end // if
    #local WeightedValues_1N =
        MultiplyArrays_1N(
            Values_1N, Weights_1N
        )
    ;

    Der2_RationalFunction_1A(
        From_1N_BezierFunction_1A(
            WeightedValues_1N
        ),
        From_1N_BezierFunction_1A(
            Weights_1N
        ),
        From_1N_BezierFunction_1A(
            Hodograph_I_1N(
                WeightedValues_1N, 1
            )
        ),
        From_1N_BezierFunction_1A(
            Hodograph_I_1N(
                Weights_1N, 1
            )
        ),
        From_1N_BezierFunction_1A(
            Hodograph_I_1N(
                WeightedValues_1N, 2
            )
        ),
        From_1N_BezierFunction_1A(
            Hodograph_I_1N(
                Weights_1N, 2
            )
        )
    )

#end // macro From_1N_DerUU_RationalBezierFunction_1A


#macro Der2_RationalBezierFunctions_1A(Values_1N, Weights_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Weights_1N) != 1)
        #error "Is not 1"
    #end // if
    #if (DimSize_I(Values_1N) != DimSize_I(Weights_1N))
        #error "Are not equal"
    #end // if

    Arr_1E(
        From_1N_DerUU_RationalBezierFunction_1A(
            Values_1N, Weights_1N
        )
    )

#end // macro Der2_RationalBezierFunctions_1A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_2N_DerUU_RationalBezierFunction_2A(Values_2N, Weights_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != 2)
        #error "Is not 2"
    #end // if
    #if (DimSize_I(Values_2N) != DimSize_I(Weights_2N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_2N) != DimSize_J(Weights_2N))
        #error "Are not equal"
    #end // if
    #if (DimSize_I(Values_2N) < 3)
        #error "Is less than 3"
    #end // if
    #local WeightedValues_2N =
        MultiplyArrays_2N(
            Values_2N, Weights_2N
        )
    ;

    Der2_RationalFunction_2A(
        From_2N_BezierFunction_2A(
            WeightedValues_2N
        ),
        From_2N_BezierFunction_2A(
            Weights_2N
        ),
        From_2N_BezierFunction_2A(
            Hodograph_I_2N(
                WeightedValues_2N, 1
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_I_2N(
                Weights_2N, 1
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_I_2N(
                WeightedValues_2N, 2
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_I_2N(
                Weights_2N, 2
            )
        )
    )

#end // macro From_2N_DerUU_RationalBezierFunction_2A


#macro From_2N_DerVV_RationalBezierFunction_2A(Values_2N, Weights_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != 2)
        #error "Is not 2"
    #end // if
    #if (DimSize_I(Values_2N) != DimSize_I(Weights_2N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_2N) != DimSize_J(Weights_2N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_2N) < 3)
        #error "Is less than 3"
    #end // if
    #local WeightedValues_2N =
        MultiplyArrays_2N(
            Values_2N, Weights_2N
        )
    ;

    Der2_RationalFunction_2A(
        From_2N_BezierFunction_2A(
            WeightedValues_2N
        ),
        From_2N_BezierFunction_2A(
            Weights_2N
        ),
        From_2N_BezierFunction_2A(
            Hodograph_J_2N(
                WeightedValues_2N, 1
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_J_2N(
                Weights_2N, 1
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_J_2N(
                WeightedValues_2N, 2
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_J_2N(
                Weights_2N, 2
            )
        )
    )

#end // macro From_2N_DerVV_RationalBezierFunction_2A


#macro Der2_RationalBezierFunctions_2A(Values_2N, Weights_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != 2)
        #error "Is not 2"
    #end // if
    #if (DimSize_I(Values_2N) != DimSize_I(Weights_2N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_2N) != DimSize_J(Weights_2N))
        #error "Are not equal"
    #end // if

    Arr_2E(
        From_2N_DerUU_RationalBezierFunction_2A(
            Values_2N, Weights_2N
        ),
        From_2N_DerVV_RationalBezierFunction_2A(
            Values_2N, Weights_2N
        )
    )

#end // macro Der2_RationalBezierFunctions_2A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_3N_DerUU_RationalBezierFunction_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (DimSize_I(Values_3N) != DimSize_I(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_3N) != DimSize_J(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_3N) != DimSize_K(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_I(Values_3N) < 3)
        #error "Is less than 3"
    #end // if
    #local WeightedValues_3N =
        MultiplyArrays_3N(
            Values_3N, Weights_3N
        )
    ;

    Der2_RationalFunction_3A(
        From_3N_BezierFunction_3A(
            WeightedValues_3N
        ),
        From_3N_BezierFunction_3A(
            Weights_3N
        ),
        From_3N_BezierFunction_3A(
            Hodograph_I_3N(
                WeightedValues_3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_I_3N(
                Weights_3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_I_3N(
                WeightedValues_3N, 2
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_I_3N(
                Weights_3N, 2
            )
        )
    )

#end // macro From_3N_DerUU_RationalBezierFunction_3A


#macro From_3N_DerVV_RationalBezierFunction_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (DimSize_I(Values_3N) != DimSize_I(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_3N) != DimSize_J(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_3N) != DimSize_K(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_3N) < 3)
        #error "Is less than 3"
    #end // if
    #local WeightedValues_3N =
        MultiplyArrays_3N(
            Values_3N, Weights_3N
        )
    ;

    Der2_RationalFunction_3A(
        From_3N_BezierFunction_3A(
            WeightedValues_3N
        ),
        From_3N_BezierFunction_3A(
            Weights_3N
        ),
        From_3N_BezierFunction_3A(
            Hodograph_J_3N(
                WeightedValues_3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_J_3N(
                Weights_3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_J_3N(
                WeightedValues_3N, 2
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_J_3N(
                Weights_3N, 2
            )
        )
    )

#end // macro From_3N_DerVV_RationalBezierFunction_3A


#macro From_3N_DerWW_RationalBezierFunction_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (DimSize_I(Values_3N) != DimSize_I(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_3N) != DimSize_J(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_3N) != DimSize_K(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_3N) < 3)
        #error "Is less than 3"
    #end // if
    #local WeightedValues_3N =
        MultiplyArrays_3N(
            Values_3N, Weights_3N
        )
    ;

    Der2_RationalFunction_3A(
        From_3N_BezierFunction_3A(
            WeightedValues_3N
        ),
        From_3N_BezierFunction_3A(
            Weights_3N
        ),
        From_3N_BezierFunction_3A(
            Hodograph_K_3N(
                WeightedValues_3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_K_3N(
                Weights_3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_K_3N(
                WeightedValues_3N, 2
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_K_3N(
                Weights_3N, 2
            )
        )
    )

#end // macro From_3N_DerWW_RationalBezierFunction_3A


#macro Der2_RationalBezierFunctions_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (DimSize_I(Values_3N) != DimSize_I(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_3N) != DimSize_J(Weights_3N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_3N) != DimSize_K(Weights_3N))
        #error "Are not equal"
    #end // if

    Arr_3E(
        From_3N_DerUU_RationalBezierFunction_3A(
            Values_3N, Weights_3N
        ),
        From_3N_DerVV_RationalBezierFunction_3A(
            Values_3N, Weights_3N
        ),
        From_3N_DerWW_RationalBezierFunction_3A(
            Values_3N, Weights_3N
        )
    )

#end // macro Der2_RationalBezierFunctions_3A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_4N_DerUU_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (DimSize_I(Values_4N) != DimSize_I(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_4N) != DimSize_J(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_4N) != DimSize_K(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_L(Values_4N) != DimSize_L(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_I(Values_4N) < 3)
        #error "Is less than 3"
    #end // if
    #local WeightedValues_4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der2_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            WeightedValues_4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_I_4N(
                WeightedValues_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_I_4N(
                Weights_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_I_4N(
                WeightedValues_4N, 2
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_I_4N(
                Weights_4N, 2
            )
        )
    )

#end // macro From_4N_DerUU_RationalBezierFunction_4A


#macro From_4N_DerVV_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (DimSize_I(Values_4N) != DimSize_I(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_4N) != DimSize_J(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_4N) != DimSize_K(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_L(Values_4N) != DimSize_L(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_4N) < 3)
        #error "Is less than 3"
    #end // if
    #local WeightedValues_4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der2_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            WeightedValues_4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_J_4N(
                WeightedValues_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_J_4N(
                Weights_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_J_4N(
                WeightedValues_4N, 2
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_J_4N(
                Weights_4N, 2
            )
        )
    )

#end // macro From_4N_DerVV_RationalBezierFunction_4A


#macro From_4N_DerWW_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (DimSize_I(Values_4N) != DimSize_I(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_4N) != DimSize_J(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_4N) != DimSize_K(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_L(Values_4N) != DimSize_L(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_4N) < 3)
        #error "Is less than 3"
    #end // if
    #local WeightedValues_4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der2_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            WeightedValues_4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_K_4N(
                WeightedValues_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_K_4N(
                Weights_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_K_4N(
                WeightedValues_4N, 2
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_K_4N(
                Weights_4N, 2
            )
        )
    )

#end // macro From_4N_DerWW_RationalBezierFunction_4A


#macro From_4N_DerSS_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (DimSize_I(Values_4N) != DimSize_I(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_4N) != DimSize_J(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_4N) != DimSize_K(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_L(Values_4N) != DimSize_L(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_L(Values_4N) < 3)
        #error "Is less than 3"
    #end // if
    #local WeightedValues_4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der2_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            WeightedValues_4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_L_4N(
                WeightedValues_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_L_4N(
                Weights_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_L_4N(
                WeightedValues_4N, 2
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_L_4N(
                Weights_4N, 2
            )
        )
    )

#end // macro From_4N_DerSS_RationalBezierFunction_4A


#macro Der2_RationalBezierFunctions_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (DimSize_I(Values_4N) != DimSize_I(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_J(Values_4N) != DimSize_J(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_K(Values_4N) != DimSize_K(Weights_4N))
        #error "Are not equal"
    #end // if
    #if (DimSize_L(Values_4N) != DimSize_L(Weights_4N))
        #error "Are not equal"
    #end // if

    Arr_4E(
        From_4N_DerUU_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        ),
        From_4N_DerVV_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        ),
        From_4N_DerWW_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        ),
        From_4N_DerSS_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        )
    )

#end // macro Der2_RationalBezierFunctions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B
