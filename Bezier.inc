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

#macro Arr_1E(E0)

    array[1] { E0 }

#end // macro Arr_1E


#macro Arr_2E(E0, E1)

    array[2] { E0, E1 }

#end // macro Arr_2E


#macro Arr_3E(E0, E1, E2)

    array[3] { E0, E1, E2 }

#end // macro Arr_3E


#macro Arr_4E(E0, E1, E2, E3)

    array[4] { E0, E1, E2, E3 }

#end // macro Arr_4E

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro u_E(Array)

    Array[0]

#end // macro u_E


#macro v_E(Array)

    Array[1]

#end // macro v_E


#macro w_E(Array)

    Array[2]

#end // macro w_E


#macro s_E(Array)

    Array[3]

#end // macro s_E

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro I_E(Array)

    Array[0]

#end // macro I_E


#macro J_E(Array)

    Array[1]

#end // macro J_E


#macro K_E(Array)

    Array[2]

#end // macro K_E


#macro L_E(Array)

    Array[3]

#end // macro L_E

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro x_E(Array)

    Array[0]

#end // macro x_E


#macro y_E(Array)

    Array[1]

#end // macro y_E


#macro z_E(Array)

    Array[2]

#end // macro z_E


#macro t_E(Array)

    Array[3]

#end // macro t_E

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro u_C(vP)

    vP.x

#end // macro u_C


#macro v_C(vP)

    vP.y

#end // macro v_C


#macro w_C(vP)

    vP.z

#end // macro w_C


#macro s_C(vP)

    vP.t

#end // macro s_C

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro ExtractComponent_1N(Vectors_1N, vC)

    #local N = dimensions(Vectors_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(Vectors_1N, 1);
    #local LastI = SizeI - 1;
    #local CC_1N = array[SizeI];
    #for (I, 0, LastI)
        #local CC_1N[I] =
            vdot(Vectors_1N[I], vC)
        ;
    #end // for

    CC_1N

#end // macro ExtractComponent_1N


#macro ExtractComponent_2N(Vectors_2N, vC)

    #local N = dimensions(Vectors_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(Vectors_2N, 1);
    #local SizeJ = dimension_size(Vectors_2N, 2);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local CC_2N = array[SizeI][SizeJ];
    #for (J, 0, LastJ)
        #for (I, 0, LastI)
            #local CC_2N[I][J] =
                vdot(Vectors_2N[I][J], vC)
            ;
        #end // for
    #end // for

    CC_2N

#end // macro ExtractComponent_2N


#macro ExtractComponent_3N(Vectors_3N, vC)

    #local N = dimensions(Vectors_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(Vectors_3N, 1);
    #local SizeJ = dimension_size(Vectors_3N, 2);
    #local SizeK = dimension_size(Vectors_3N, 3);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local CC_3N = array[SizeI][SizeJ][SizeK];
    #for (K, 0, LastK)
        #for (J, 0, LastJ)
            #for (I, 0, LastI)
                #local CC_3N[I][J][K] =
                    vdot(Vectors_3N[I][J][K], vC)
                ;
            #end // for
        #end // for
    #end // for

    CC_3N

#end // macro ExtractComponent_3N


#macro ExtractComponent_4N(Vectors_4N, vC)

    #local N = dimensions(Vectors_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Vectors_4N, 1);
    #local SizeJ = dimension_size(Vectors_4N, 2);
    #local SizeK = dimension_size(Vectors_4N, 3);
    #local SizeL = dimension_size(Vectors_4N, 4);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local LastL = SizeL - 1;
    #local CC_4N = array[SizeI][SizeJ][SizeK][SizeL];
    #for (L, 0, LastL)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI)
                    #local CC_4N[I][J][K][L] =
                        vdot(Vectors_4N[I][J][K][L], vC)
                    ;
                #end // for
            #end // for
        #end // for
    #end // for

    CC_4N

#end // macro ExtractComponent_4N

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_1N_OuterProduct_2N(ArrayI_1N, ArrayJ_1N)

    #local NI = dimensions(ArrayI_1N);
    #if (NI != 1)
        #error "NI is not 1"
    #end // if
    #local NJ = dimensions(ArrayJ_1N);
    #if (NJ != 1)
        #error "NJ is not 1"
    #end // if
    #local SizeI = dimension_size(ArrayI_1N, 1);
    #local SizeJ = dimension_size(ArrayJ_1N, 1);
    #local OO_2N = array[SizeI][SizeJ];
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #for (J, 0, LastJ)
        #for (I, 0, LastI)
            #local OO_2N[I][J] =
                ArrayI_1N[I]*ArrayJ_1N[J]
            ;
        #end // for
    #end // for

    OO_2N

#end // macro From_1N_OuterProduct_2N

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro UniformWeights_1N(DimensionsSizes_I, Constant)

    #local M = dimensions(DimensionsSizes_I);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local N = dimension_size(DimensionsSizes_I, 1);
    #if (N != 1)
        #error "N is not 1"
    #end // if

    From_Fn_1A_Array_1N(
        DimensionsSizes_I,
        function(_i) { Constant }
    )

#end // macro UniformWeights_1N


#macro UniformWeights_2N(DimensionsSizes_IJ, Constant)

    #local M = dimensions(DimensionsSizes_IJ);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local N = dimension_size(DimensionsSizes_IJ, 1);
    #if (N != 2)
        #error "N is not 2"
    #end // if

    From_Fn_2A_Array_2N(
        DimensionsSizes_IJ,
        function(_i, _j) { Constant }
    )

#end // macro UniformWeights_2N


#macro UniformWeights_3N(DimensionsSizes_IJK, Constant)

    #local M = dimensions(DimensionsSizes_IJK);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local N = dimension_size(DimensionsSizes_IJK, 1);
    #if (N != 3)
        #error "N is not 3"
    #end // if

    From_Fn_3A_Array_3N(
        DimensionsSizes_IJK,
        function(_i, _j, _k) { Constant }
    )

#end // macro UniformWeights_3N


#macro UniformWeights_4N(DimensionsSizes_IJKL, Constant)

    #local M = dimensions(DimensionsSizes_IJKL);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local N = dimension_size(DimensionsSizes_IJKL, 1);
    #if (N != 4)
        #error "N is not 4"
    #end // if

    From_Fn_4A_Array_4N(
        DimensionsSizes_IJKL,
        function(_i, _j, _k, _l) { Constant }
    )

#end // macro UniformWeights_4N

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro BernsteinBasisFunction_1A(N, R)

    #local C = BinomialFn(N, R);
    #local M = N - R;

    function(_t) { C*PowFn(_t, R)*PowFn(1 - _t, M) }

#end // macro BernsteinBasisFunction_1A


#macro BernsteinBasisFunctions_1A_1N(Degree)

    #local _Fns_1A_1N = array[Degree+1];
    #for (I, 0, Degree)
        #local _Fns_1A_1N[I] =
            BernsteinBasisFunction_1A(
                Degree, I
            )
        ;
    #end // for

    _Fns_1A_1N

#end // macro BernsteinBasisFunctions_1A_1N

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_1N_BezierFunction_1A(Values_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(Values_1N, 1);

    WeightedFunction_1A(
        BernsteinBasisFunctions_1A_1N(SizeI - 1),
        Values_1N
    )

#end // macro From_1N_BezierFunction_1A


#macro From_2N_BezierFunction_2A(Values_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(Values_2N, 1);
    #local SizeJ = dimension_size(Values_2N, 2);

    WeightedFunction_2A(
        BernsteinBasisFunctions_1A_1N(SizeI - 1),
        BernsteinBasisFunctions_1A_1N(SizeJ - 1),
        Values_2N
    )

#end // macro From_2N_BezierFunction_2A


#macro From_3N_BezierFunction_3A(Values_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(Values_3N, 1);
    #local SizeJ = dimension_size(Values_3N, 2);
    #local SizeK = dimension_size(Values_3N, 3);

    WeightedFunction_3A(
        BernsteinBasisFunctions_1A_1N(SizeI - 1),
        BernsteinBasisFunctions_1A_1N(SizeJ - 1),
        BernsteinBasisFunctions_1A_1N(SizeK - 1),
        Values_3N
    )

#end // macro From_3N_BezierFunction_3A


#macro From_4N_BezierFunction_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Values_4N, 1);
    #local SizeJ = dimension_size(Values_4N, 2);
    #local SizeK = dimension_size(Values_4N, 3);
    #local SizeL = dimension_size(Values_4N, 4);

    WeightedFunction_4A(
        BernsteinBasisFunctions_1A_1N(SizeI - 1),
        BernsteinBasisFunctions_1A_1N(SizeJ - 1),
        BernsteinBasisFunctions_1A_1N(SizeK - 1),
        BernsteinBasisFunctions_1A_1N(SizeL - 1),
        Values_4N
    )

#end // macro From_4N_BezierFunction_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_1N_BezierFunctions_1A_2D(Points_1N_2D)

    #local N = dimensions(Points_1N_2D);
    #if (N != 1)
        #error "N is not 1"
    #end // if

    Arr_2E(
        From_1N_BezierFunction_1A(
            From_1N_ExtractComponent_1N(Points_1N_2D, x)
        ),
        From_1N_BezierFunction_1A(
            From_1N_ExtractComponent_1N(Points_1N_2D, y)
        )
    )

#end // macro From_1N_BezierFunctions_1A_2D


#macro From_2N_BezierFunctions_2A_2D(Points_2N_2D)

    #local N = dimensions(Points_2N_2D);
    #if (N != 2)
        #error "N is not 2"
    #end // if

    Arr_2E(
        From_2N_BezierFunction_2A(
            From_2N_ExtractComponent_2N(Points_2N_2D, x)
        ),
        From_2N_BezierFunction_2A(
            From_2N_ExtractComponent_2N(Points_2N_2D, y)
        )
    )

#end // macro From_2N_BezierFunctions_2A_2D


#macro From_3N_BezierFunctions_3A_2D(Points_3N_2D)

    #local N = dimensions(Points_3N_2D);
    #if (N != 3)
        #error "N is not 3"
    #end // if

    Arr_2E(
        From_3N_BezierFunction_3A(
            From_3N_ExtractComponent_3N(Points_3N_2D, x)
        ),
        From_3N_BezierFunction_3A(
            From_3N_ExtractComponent_3N(Points_3N_2D, y)
        )
    )

#end // macro From_3N_BezierFunctions_3A_2D


#macro From_4N_BezierFunctions_4A_2D(Points_4N_2D)

    #local N = dimensions(Points_4N_2D);
    #if (N != 4)
        #error "N is not 4"
    #end // if

    Arr_2E(
        From_4N_BezierFunction_4A(
            From_4N_ExtractComponent_4N(Points_4N_2D, x)
        ),
        From_4N_BezierFunction_4A(
            From_4N_ExtractComponent_4N(Points_4N_2D, y)
        )
    )

#end // macro From_4N_BezierFunctions_4A_2D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_1N_BezierFunctions_1A_3D(Points_1N_3D)

    #local N = dimensions(Points_1N_3D);
    #if (N != 1)
        #error "N is not 1"
    #end // if

    Arr_3E(
        From_1N_BezierFunction_1A(
            From_1N_ExtractComponent_1N(Points_1N_3D, x)
        ),
        From_1N_BezierFunction_1A(
            From_1N_ExtractComponent_1N(Points_1N_3D, y)
        ),
        From_1N_BezierFunction_1A(
            From_1N_ExtractComponent_1N(Points_1N_3D, z)
        )
    )

#end // macro From_1N_BezierFunctions_1A_3D


#macro From_2N_BezierFunctions_2A_3D(Points_2N_3D)

    #local N = dimensions(Points_2N_3D);
    #if (N != 2)
        #error "N is not 2"
    #end // if

    Arr_3E(
        From_2N_BezierFunction_2A(
            From_2N_ExtractComponent_2N(Points_2N_3D, x)
        ),
        From_2N_BezierFunction_2A(
            From_2N_ExtractComponent_2N(Points_2N_3D, y)
        ),
        From_2N_BezierFunction_2A(
            From_2N_ExtractComponent_2N(Points_2N_3D, z)
        )
    )

#end // macro From_2N_BezierFunctions_2A_3D


#macro From_3N_BezierFunctions_3A_3D(Points_3N_3D)

    #local N = dimensions(Points_3N_3D);
    #if (N != 3)
        #error "N is not 3"
    #end // if

    Arr_3E(
        From_3N_BezierFunction_3A(
            From_3N_ExtractComponent_3N(Points_3N_3D, x)
        ),
        From_3N_BezierFunction_3A(
            From_3N_ExtractComponent_3N(Points_3N_3D, y)
        ),
        From_3N_BezierFunction_3A(
            From_3N_ExtractComponent_3N(Points_3N_3D, z)
        )
    )

#end // macro From_3N_BezierFunctions_3A_3D


#macro From_4N_BezierFunctions_4A_3D(Points_4N_3D)

    #local N = dimensions(Points_4N_3D);
    #if (N != 4)
        #error "N is not 4"
    #end // if

    Arr_3E(
        From_4N_BezierFunction_4A(
            From_4N_ExtractComponent_4N(Points_4N_3D, x)
        ),
        From_4N_BezierFunction_4A(
            From_4N_ExtractComponent_4N(Points_4N_3D, y)
        ),
        From_4N_BezierFunction_4A(
            From_4N_ExtractComponent_4N(Points_4N_3D, z)
        )
    )

#end // macro From_4N_BezierFunctions_4A_3D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#declare ElevationCoefficientFn =
    function(_d, _n, _i, _s) {
        BinomialFn(_d, _s)
        *
        FactRisingFn(_i + 1, _s)
        *
        FactRisingFn(_n - _i, _d - _s)
    }
;


#macro DegreeElevate_I_1N(ValuesOrPoints_1N, NoOfDegrees)

    #local N = dimensions(ValuesOrPoints_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_1N, 1);
    #local NewSizeI = SizeI + NoOfDegrees;
    #local VV_1N = array[NewSizeI];
    #local DI =
        FactRisingFn(
            SizeI,
            NoOfDegrees
        )
    ;
    #local p0 = 0*ValuesOrPoints_1N[0];
    #local VV_1N[0] = ValuesOrPoints_1N[0];
    #for (I, 1, NewSizeI - 2)
        #local pSum = p0;
        #for (Io, max(I - NoOfDegrees, 0), min(SizeI - 1, I))
            #local EC =
                ElevationCoefficientFn(
                    NoOfDegrees,
                    SizeI,
                    Io,  // original index
                    I - Io  // shift
                )
            ;
            #local pSum = pSum + EC*ValuesOrPoints_1N[Io];
        #end // for
        #local VV_1N[I] = pSum/DI;
    #end // for
    #local VV_1N[NewSizeI-1] = ValuesOrPoints_1N[SizeI-1];

    VV_1N

#end // macro DegreeElevate_I_1N


#macro DegreeElevate_I_2N(ValuesOrPoints_2N, NoOfDegrees)

    #local N = dimensions(ValuesOrPoints_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_2N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_2N, 2);
    #local NewSizeI = SizeI + NoOfDegrees;
    #local VV_2N = array[NewSizeI][SizeJ];
    #local DI =
        FactRisingFn(
            SizeI,
            NoOfDegrees
        )
    ;
    #local p0 = 0*ValuesOrPoints_2N[0][0];
    #for (J, 0, SizeJ - 1)
        #local VV_2N[0][J] = ValuesOrPoints_2N[0][J];
        #for (I, 1, NewSizeI - 2)
            #local pSum = p0;
            #for (Io, max(0, I - NoOfDegrees), min(SizeI - 1, I))
                #local EC =
                    ElevationCoefficientFn(
                        NoOfDegrees,
                        SizeI,
                        Io,  // original index
                        I - Io  // shift
                    )
                ;
                #local pSum = pSum + EC*ValuesOrPoints_2N[Io][J];
            #end // for
            #local VV_2N[I][J] = pSum/DI;
        #end // for
        #local VV_2N[NewSizeI-1][J] = ValuesOrPoints_2N[SizeI-1][J];
    #end // for

    VV_2N

#end // macro DegreeElevate_I_2N


#macro DegreeElevate_J_2N(ValuesOrPoints_2N, NoOfDegrees)

    #local N = dimensions(ValuesOrPoints_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_2N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_2N, 2);
    #local NewSizeJ = SizeJ + NoOfDegrees;
    #local VV_2N = array[SizeI][NewSizeJ];
    #local DJ =
        FactRisingFn(
            SizeJ,
            NoOfDegrees
        )
    ;
    #local p0 = 0*ValuesOrPoints_2N[0][0];
    #for (I, 0, SizeI - 1)
        #local VV_2N[I][0] = ValuesOrPoints_2N[I][0];
        #for (J, 1, NewSizeJ - 2)
            #local pSum = p0;
            #for (Jo, max(0, J - NoOfDegrees), min(SizeJ - 1, J))
                #local EC =
                    ElevationCoefficientFn(
                        NoOfDegrees,
                        SizeJ,
                        Jo,  // original index
                        J - Jo  // shift
                    )
                ;
                #local pSum = pSum + EC*ValuesOrPoints_2N[I][Jo];
            #end // for
            #local VV_2N[I][J] = pSum/DJ;
        #end // for
        #local VV_2N[I][NewSizeJ-1] = ValuesOrPoints_2N[I][SizeJ-1];
    #end // for

    VV_2N

#end // macro DegreeElevate_J_2N


#macro DegreeElevate_I_3N(ValuesOrPoints_3N, NoOfDegrees)

    #local N = dimensions(ValuesOrPoints_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_3N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_3N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_3N, 3);
    #local NewSizeI = SizeI + NoOfDegrees;
    #local VV_3N = array[NewSizeI][SizeJ][SizeK];
    #local DI =
        FactRisingFn(
            SizeI,
            NoOfDegrees
        )
    ;
    #local p0 = 0*ValuesOrPoints_3N[0][0][0];
    #for (K, 0, SizeK - 1)
        #for (J, 0, SizeJ - 1)
            #local VV_3N[0][J][K] = ValuesOrPoints_3N[0][J][K];
            #for (I, 1, NewSizeI - 2)
                #local pSum = p0;
                #for (Io, max(I - NoOfDegrees, 0), min(SizeI - 1, I))
                    #local EC =
                        ElevationCoefficientFn(
                            NoOfDegrees,
                            SizeI,
                            Io,  // original index
                            I - Io  // shift
                        )
                    ;
                    #local pSum = pSum + EC*ValuesOrPoints_3N[Io][J][K];
                #end // for
                #local VV_3N[I][J][K] = pSum/DI;
            #end // for
            #local VV_3N[NewSizeI-1][J][K] = ValuesOrPoints_3N[SizeI-1][J][K];
        #end // for
    #end // for

    VV_3N

#end // macro DegreeElevate_I_3N


#macro DegreeElevate_J_3N(ValuesOrPoints_3N, NoOfDegrees)

    #local N = dimensions(ValuesOrPoints_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_3N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_3N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_3N, 3);
    #local NewSizeJ = SizeJ + NoOfDegrees;
    #local VV_3N = array[SizeI][NewSizeJ][SizeK];
    #local DJ =
        FactRisingFn(
            SizeJ,
            NoOfDegrees
        )
    ;
    #local p0 = 0*ValuesOrPoints_3N[0][0][0];
    #for (I, 0, SizeI - 1)
        #for (K, 0, SizeK - 1)
            #local VV_3N[I][0][K] = ValuesOrPoints_3N[I][0][K];
            #for (J, 1, NewSizeJ - 2)
                #local pSum = p0;
                #for (Jo, max(J - NoOfDegrees, 0), min(SizeJ - 1, J))
                    #local EC =
                        ElevationCoefficientFn(
                            NoOfDegrees,
                            SizeJ,
                            Jo,  // original index
                            J - Jo // shift
                        )
                    ;
                    #local pSum = pSum + EC*ValuesOrPoints_3N[I][Jo][K];
                #end // for
                #local VV_3N[I][J][K] = pSum/DJ;
            #end // for
            #local VV_3N[I][NewSizeJ-1][K] = ValuesOrPoints_3N[I][SizeJ-1][K];
        #end // for
    #end // for

    VV_3N

#end // macro DegreeElevate_J_3N


#macro DegreeElevate_K_3N(ValuesOrPoints_3N, NoOfDegrees)

    #local N = dimensions(ValuesOrPoints_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_3N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_3N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_3N, 3);
    #local NewSizeK = SizeK + NoOfDegrees;
    #local VV_3N = array[SizeI][SizeJ][NewSizeK];
    #local DK =
        FactRisingFn(
            SizeK,
            NoOfDegrees
        )
    ;
    #local p0 = 0*ValuesOrPoints_3N[0][0][0];
    #for (J, 0, SizeJ - 1)
        #for (I, 0, SizeI - 1)
            #local VV_3N[I][J][0] = ValuesOrPoints_3N[I][J][0];
            #for (K, 1, NewSizeK - 2)
                #local pSum = p0;
                #for (Ko, max(K - NoOfDegrees, 0), min(SizeK - 1, K))
                    #local EC =
                        ElevationCoefficientFn(
                            NoOfDegrees,
                            SizeK,
                            Ko,  // original index
                            K - Ko  // shift
                        )
                    ;
                    #local pSum = pSum + EC*ValuesOrPoints_3N[I][J][Ko];
                #end // for
                #local VV_3N[I][J][K] = pSum/DK;
            #end // for
            #local VV_3N[I][J][NewSizeK-1] = ValuesOrPoints_3N[I][J][SizeK-1];
        #end // for
    #end // for

    VV_3N
 
#end // macro DegreeElevate_K_3N


#macro DegreeElevate_I_4N(ValuesOrPoints_4N, NoOfDegrees)

    #local N = dimensions(ValuesOrPoints_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_4N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_4N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_4N, 3);
    #local SizeL = dimension_size(ValuesOrPoints_4N, 4);
    #local NewSizeI = SizeI + NoOfDegrees;
    #local VV_4N = array[NewSizeI][SizeJ][SizeK][SizeL];
    #local DI =
        FactRisingFn(
            SizeI,
            NoOfDegrees
        )
    ;
    #local p0 = 0*ValuesOrPoints_4N[0][0][0][0];
    #for (L, 0, SizeL - 1)
        #for (K, 0, SizeK - 1)
            #for (J, 0, SizeJ - 1)
                #local VV_4N[0][J][K][L] = ValuesOrPoints_4N[0][J][K][L];
                #for (I, 1, NewSizeI - 2)
                    #local pSum = p0;
                    #for (Io, max(I - NoOfDegrees, 0), min(SizeI - 1, I))
                        #local EC =
                            ElevationCoefficientFn(
                                NoOfDegrees,
                                SizeI,
                                Io,  // original index
                                I - Io  // shift
                            )
                        ;
                        #local pSum = pSum + EC*ValuesOrPoints_4N[Io][J][K][L];
                    #end // for
                    #local VV_4N[I][J][K][L] = pSum/DI;
                #end // for
                #local VV_4N[NewSizeI-1][J][K][L] = ValuesOrPoints_4N[SizeI-1][J][K][L];
            #end // for
        #end // for
    #end // for

    VV_4N

#end // macro DegreeElevate_I_4N


#macro DegreeElevate_J_4N(ValuesOrPoints_4N, NoOfDegrees)

    #local N = dimensions(ValuesOrPoints_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_4N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_4N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_4N, 3);
    #local SizeL = dimension_size(ValuesOrPoints_4N, 4);
    #local NewSizeJ = SizeJ + NoOfDegrees;
    #local VV_4N = array[SizeI][NewSizeJ][SizeK][SizeL];
    #local DJ =
        FactRisingFn(
            SizeJ,
            NoOfDegrees
        )
    ;
    #local p0 = 0*ValuesOrPoints_4N[0][0][0][0];
    #for (I, 0, SizeI - 1)
        #for (L, 0, SizeL - 1)
            #for (K, 0, SizeK - 1)
                #local VV_4N[I][0][K][L] = ValuesOrPoints_4N[I][0][K][L];
                #for (J, 1, NewSizeJ - 2)
                    #local pSum = p0;
                    #for (Jo, max(J - NoOfDegrees, 0), min(SizeJ - 1, J))
                        #local EC =
                            ElevationCoefficientFn(
                                NoOfDegrees,
                                SizeJ,
                                Jo,  // original index
                                J - Jo  // shift
                            )
                        ;
                        #local pSum = pSum + EC*ValuesOrPoints_4N[I][Jo][K][L];
                    #end // for
                    #local VV_4N[I][J][K][L] = pSum/DJ;
                #end // for
                #local VV_4N[I][NewSizeJ-1][K][L] = ValuesOrPoints_4N[I][SizeJ-1][K][L];
            #end // for
        #end // for
    #end // for

    VV_4N

#end // macro DegreeElevate_J_4N


#macro DegreeElevate_K_4N(ValuesOrPoints_4N, NoOfDegrees)

    #local N = dimensions(ValuesOrPoints_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_4N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_4N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_4N, 3);
    #local SizeL = dimension_size(ValuesOrPoints_4N, 4);
    #local NewSizeK = SizeK + NoOfDegrees;
    #local VV_4N = array[SizeI][SizeJ][NewSizeK][SizeL];
    #local DK =
        FactRisingFn(
            SizeK,
            NoOfDegrees
        )
    ;
    #local p0 = 0*ValuesOrPoints_4N[0][0][0][0];
    #for (J, 0, SizeJ - 1)
        #for (I, 0, SizeI - 1)
            #for (L, 0, SizeL - 1)
                #local VV_4N[I][J][0][L] = ValuesOrPoints_4N[I][J][0][L];
                #for (K, 1, NewSizeK - 2)
                    #local pSum = p0;
                    #for (Ko, max(K - NoOfDegrees, 0), min(SizeK - 1, K))
                        #local EC =
                            ElevationCoefficientFn(
                                NoOfDegrees,
                                SizeK,
                                Ko,  // original index
                                K - Ko  // shift
                            )
                        ;
                        #local pSum = pSum + EC*ValuesOrPoints_4N[I][J][Ko][L];
                    #end // for
                    #local VV_4N[I][J][K][L] = pSum/DK;
                #end // for
                #local VV_4N[I][J][NewSizeK-1][L] = ValuesOrPoints_4N[I][J][SizeK-1][L];
            #end // for
        #end // for
    #end // for

    VV_4N

#end // macro DegreeElevate_K_4N


#macro DegreeElevate_L_4N(ValuesOrPoints_4N, NoOfDegrees)

    #local N = dimensions(ValuesOrPoints_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_4N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_4N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_4N, 3);
    #local SizeL = dimension_size(ValuesOrPoints_4N, 4);
    #local NewSizeL = SizeL + NoOfDegrees;
    #local VV_4N = array[SizeI][SizeJ][SizeK][NewSizeL];
    #local DL =
        FactRisingFn(
            SizeL,
            NoOfDegrees
        )
    ;
    #local p0 = 0*ValuesOrPoints_4N[0][0][0][0];
    #for (K, 0, SizeK - 1)
        #for (J, 0, SizeJ - 1)
            #for (I, 0, SizeI - 1)
                #local VV_4N[I][J][K][0] = ValuesOrPoints_4N[I][J][K][0];
                #for (L, 1, NewSizeL - 2)
                    #local pSum = p0;
                    #for (Lo, max(L - NoOfDegrees, 0), min(SizeL - 1, L))
                        #local EC =
                            ElevationCoefficientFn(
                                NoOfDegrees,
                                SizeL,
                                Lo,  // original index
                                L - Lo  // shift
                            )
                        ;
                        #local pSum = pSum + EC*ValuesOrPoints_4N[I][J][K][Lo];
                    #end // for
                    #local VV_4N[I][J][K][L] = pSum/DL;
                #end // for
                #local VV_4N[I][J][K][NewSizeL-1] = ValuesOrPoints_4N[I][J][K][SizeL-1];
            #end // for
        #end // for
    #end // for

    VV_4N

#end // macro DegreeElevate_L_4N

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro _HodographCoefficients(M)

    #local CC = array[M+1];
    #for (I, 0, M)
        #local CC[I] =
            pow(-1, M + I)*BinomialFn(M, I)
        ;
    #end // for

    CC

#end // macro _HodographCoefficients


#macro Hodograph_I_1N(ValuesOrPoints_1N, M)

    #local N = dimensions(ValuesOrPoints_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_1N, 1);
    #local p0 = 0*ValuesOrPoints_1N[0];
    #if (M < SizeI)
        #local CC = _HodographCoefficients(M);
        #local NewSizeI = SizeI - M;   
        #local VV_1N = array[NewSizeI];
        #for (I, 0, NewSizeI - 1)
            #local pSum = p0;
            #for (A, 0, M)
                #local pSum =
                    pSum + CC[A]*ValuesOrPoints_1N[I+A]
                ;
            #end // for
            #local VV_1N[I] = FactFallingFn(SizeI - 1, M)*pSum;
        #end // for
    #else
        #local VV_1N = array[1];
        #local VV_1N[0] = p0;
    #end // if

    VV_1N

#end // macro Hodograph_I_1N


#macro Hodograph_I_2N(ValuesOrPoints_2N, M)

    #local N = dimensions(ValuesOrPoints_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_2N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_2N, 2);
    #local p0 = 0*ValuesOrPoints_2N[0][0];
    #if (M < SizeI)
        #local CC = _HodographCoefficients(M);
        #local NewSizeI = SizeI - M;
        #local VV_2N = array[NewSizeI][SizeJ];
        #for (J, 0, SizeJ - 1)
            #for (I, 0, NewSizeI - 1)
                #local pSum = p0;
                #for (A, 0, M)
                    #local pSum =
                        pSum + CC[A]*ValuesOrPoints_2N[I+A][J]
                    ;
                #end // for
                #local VV_2N[I][J] =
                    FactFallingFn(SizeI - 1, M)*pSum
                ;
            #end // for
        #end // for
    #else
        #local VV_2N = array[1][SizeJ];
        #for (J, 0, SizeJ - 1)
            #local VV_2N[0][J] = p0;
        #end // for
    #end // if

    VV_2N

#end // macro Hodograph_I_2N


#macro Hodograph_J_2N(ValuesOrPoints_2N, M)

    #local N = dimensions(ValuesOrPoints_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_2N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_2N, 2);
    #local p0 = 0*ValuesOrPoints_2N[0][0];
    #if (M < SizeJ)
        #local CC = _HodographCoefficients(M);
        #local NewSizeJ = SizeJ - M;
        #local VV_2N = array[SizeI][NewSizeJ];
        #for (I, 0, SizeI - 1)
            #for (J, 0, NewSizeJ - 1)
                #local pSum = p0;
                #for (A, 0, M)
                    #local pSum =
                        pSum + CC[A]*ValuesOrPoints_2N[I][J+A]
                    ;
                #end // for
                #local VV_2N[I][J] =
                    FactFallingFn(SizeJ - 1, M)*pSum
                ;
            #end // for
        #end // for
    #else
        #local VV_2N = array[SizeI][1];
        #for (I, 0, SizeI - 1)
            #local VV_2N[I][0] = p0;
        #end // for
    #end // if

    VV_2N

#end // macro Hodograph_J_2N


#macro Hodograph_I_3N(ValuesOrPoints_3N, M)

    #local N = dimensions(ValuesOrPoints_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_3N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_3N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_3N, 3);
    #local p0 = 0*ValuesOrPoints_3N[0][0][0];
    #if (M < SizeI)
        #local CC = _HodographCoefficients(M);
        #local NewSizeI = SizeI - M;
        #local VV_3N = array[NewSizeI][SizeJ][SizeK];
        #for (K, 0, SizeK - 1)
            #for (J, 0, SizeJ - 1)
                #for (I, 0, NewSizeI - 1)
                    #local pSum = p0;
                    #for (A, 0, M)
                        #local pSum =
                            pSum + CC[A]*ValuesOrPoints_3N[I+A][J][K]
                        ;
                    #end // for
                    #local VV_3N[I][J][K] =
                        FactFallingFn(SizeI - 1, M)*pSum
                    ;
                #end // for
            #end // for
        #end // for
    #else
        #local VV_3N = array[1][SizeJ][SizeK];
        #for (K, 0, SizeK - 1)
            #for (J, 0, SizeJ - 1)
                #local VV_3N[0][J][K] = p0;
            #end // for
        #end // for
    #end // if

    VV_3N

#end // macro Hodograph_I_3N


#macro Hodograph_J_3N(ValuesOrPoints_3N, M)

    #local N = dimensions(ValuesOrPoints_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_3N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_3N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_3N, 3);
    #local p0 = 0*ValuesOrPoints_3N[0][0][0];
    #if (M < SizeJ)
        #local CC = _HodographCoefficients(M);
        #local NewSizeJ = SizeJ - M;
        #local VV_3N = array[SizeI][NewSizeJ][SizeK];
        #for (I, 0, SizeI - 1)
            #for (K, 0, SizeK - 1)
                #for (J, 0, NewSizeJ - 1)
                    #local pSum = p0;
                    #for (A, 0, M)
                        #local pSum =
                            pSum + CC[A]*ValuesOrPoints_3N[I][J+A][K]
                        ;
                    #end // for
                    #local VV_3N[I][J][K] =
                        FactFallingFn(SizeJ - 1, M)*pSum
                    ;
                #end // for
            #end // for
        #end // for
    #else
        #local VV_3N = array[SizeI][1][SizeK];
        #for (I, 0, SizeI - 1)
            #for (K, 0, SizeK - 1)
                #local VV_3N[I][0][K] = p0;
            #end // for
        #end // for
    #end // if

    VV_3N

#end // macro Hodograph_J_3N


#macro Hodograph_K_3N(ValuesOrPoints_3N, M)

    #local N = dimensions(ValuesOrPoints_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_3N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_3N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_3N, 3);
    #local p0 = 0*ValuesOrPoints_3N[0][0][0];
    #if (M < SizeK)
        #local CC = _HodographCoefficients(M);
        #local NewSizeK = SizeK - M;
        #local VV_3N = array[SizeI][SizeJ][NewSizeK];
        #for (J, 0, SizeJ - 1)
            #for (I, 0, SizeI - 1)
                #for (K, 0, NewSizeK - 1)
                    #local pSum = p0;
                    #for (A, 0, M)
                        #local pSum =
                            pSum + CC[A]*ValuesOrPoints_3N[I][J][K+A]
                        ;
                    #end // for
                    #local VV_3N[I][J][K] =
                        FactFallingFn(SizeK - 1, M)*pSum
                    ;
                #end // for
            #end // for
        #end // for
    #else
        #local VV_3N = array[SizeI][SizeJ][1];
        #for (J, 0, SizeJ - 1)
            #for (I, 0, SizeI - 1)
                #local VV_3N[I][J][0] = p0;
            #end // for
        #end // for
    #end // if

    VV_3N

#end // macro Hodograph_K_3N


#macro Hodograph_I_4N(ValuesOrPoints_4N, M)

    #local N = dimensions(ValuesOrPoints_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_4N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_4N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_4N, 3);
    #local SizeL = dimension_size(ValuesOrPoints_4N, 4);
    #local p0 = 0*ValuesOrPoints_4N[0][0][0][0];
    #if (M < SizeI)
        #local CC = _HodographCoefficients(M);
        #local NewSizeI = SizeI - M;
        #local VV_4N = array[NewSizeI][SizeJ][SizeK][SizeL];
        #for (L, 0, SizeL - 1)
            #for (K, 0, SizeK - 1)
                #for (J, 0, SizeJ - 1)
                    #for (I, 0, NewSizeI - 1)
                        #local pSum = p0;
                        #for (A, 0, M)
                            #local pSum =
                                pSum + CC[A]*ValuesOrPoints_4N[I+A][J][K][L]
                            ;
                        #end // for
                        #local VV_4N[I][J][K][L] =
                            FactFallingFn(SizeI - 1, M)*pSum
                        ;
                    #end // for
                #end // for
            #end // for
        #end // for
    #else
        #local VV_4N = array[1][SizeJ][SizeK][SizeL];
        #for (L, 0, SizeL - 1)
            #for (K, 0, SizeK - 1)
                #for (J, 0, SizeJ - 1)
                    #local VV_4N[0][J][K][L] = p0;
                #end // for
            #end // for
        #end // for
    #end // if

    VV_4N

#end // macro Hodograph_I_4N


#macro Hodograph_J_4N(ValuesOrPoints_4N, M)

    #local N = dimensions(ValuesOrPoints_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_4N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_4N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_4N, 3);
    #local SizeL = dimension_size(ValuesOrPoints_4N, 4);
    #local p0 = 0*ValuesOrPoints_4N[0][0][0][0];
    #if (M < SizeJ)
        #local CC = _HodographCoefficients(M);
        #local NewSizeJ = SizeJ - M;
        #local VV_4N = array[SizeI][NewSizeJ][SizeK][SizeL];
        #for (I, 0, SizeI - 1)
            #for (L, 0, SizeL - 1)
                #for (K, 0, SizeK - 1)
                    #for (J, 0, NewSizeJ - 1)
                        #local pSum = p0;
                        #for (A, 0, M)
                            #local pSum =
                                pSum + CC[A]*ValuesOrPoints_4N[I][J+A][K][L]
                            ;
                        #end // for
                        #local VV_4N[I][J][K][L] =
                            FactFallingFn(SizeJ - 1, M)*pSum
                        ;
                    #end // for
                #end // for
            #end // for
        #end // for
    #else
        #local VV_4N = array[SizeI][1][SizeK][SizeL];
        #for (I, 0, SizeI - 1)
            #for (L, 0, SizeL - 1)
                #for (K, 0, SizeK - 1)
                    #local VV_4N[I][0][K][L] = p0;
                #end // for
            #end // for
        #end // for
    #end // if

    VV_4N

#end // macro Hodograph_J_4N


#macro Hodograph_K_4N(ValuesOrPoints_4N, M)

    #local N = dimensions(ValuesOrPoints_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_4N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_4N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_4N, 3);
    #local SizeL = dimension_size(ValuesOrPoints_4N, 4);
    #local p0 = 0*ValuesOrPoints_4N[0][0][0][0];
    #if (M < SizeK)
        #local CC = _HodographCoefficients(M);
        #local NewSizeK = SizeK - M;
        #local VV_4N = array[SizeI][SizeJ][NewSizeK][SizeL];
        #for (J, 0, SizeJ - 1)
            #for (I, 0, SizeI - 1)
                #for (L, 0, SizeL - 1)
                    #for (K, 0, NewSizeK - 1)
                        #local pSum = p0;
                        #for (A, 0, M)
                            #local pSum =
                                pSum + CC[A]*ValuesOrPoints_4N[I][J][K+A][L]
                            ;
                        #end // for
                        #local VV_4N[I][J][K][L] =
                            FactFallingFn(SizeK - 1, M)*pSum
                        ;
                    #end // for
                #end // for
            #end // for
        #end // for
    #else
        #local VV_4N = array[SizeI][SizeJ][1][SizeL];
        #for (J, 0, SizeJ - 1)
            #for (I, 0, SizeI - 1)
                #for (L, 0, SizeL - 1)
                    #local VV_4N[I][J][0][L] = p0;
                #end // for
            #end // for
        #end // for
    #end // if

    VV_4N

#end // macro Hodograph_K_4N


#macro Hodograph_L_4N(ValuesOrPoints_4N, M)

    #local N = dimensions(ValuesOrPoints_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(ValuesOrPoints_4N, 1);
    #local SizeJ = dimension_size(ValuesOrPoints_4N, 2);
    #local SizeK = dimension_size(ValuesOrPoints_4N, 3);
    #local SizeL = dimension_size(ValuesOrPoints_4N, 4);
    #local p0 = 0*ValuesOrPoints_4N[0][0][0][0];
    #if (M < SizeL)
        #local CC = _HodographCoefficients(M);
        #local NewSizeL = SizeL - M;
        #local VV_4N = array[SizeI][SizeJ][SizeK][NewSizeL];
        #for (K, 0, SizeK - 1)
            #for (J, 0, SizeJ - 1)
                #for (I, 0, SizeI - 1)
                    #for (L, 0, NewSizeL - 1)
                        #local pSum = p0;
                        #for (A, 0, M)
                            #local pSum =
                                pSum + CC[A]*ValuesOrPoints_4N[I][J][K][L+A]
                            ;
                        #end // for
                        #local VV_4N[I][J][K][L] =
                            FactFallingFn(SizeL - 1, M)*pSum
                        ;
                    #end // for
                #end // for
            #end // for
        #end // for
    #else
        #local VV_4N = array[SizeI][SizeJ][SizeK][1];
        #for (K, 0, SizeK - 1)
            #for (J, 0, SizeJ - 1)
                #for (I, 0, SizeI - 1)
                    #local VV_4N[I][J][K][0] = p0;
                #end // for
            #end // for
        #end // for
    #end // if

    VV_4N

#end // macro Hodograph_L_4N

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_1N_Der1U_BezierFunction_1A(Values_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimension_size(Values_1N, 1) < 2)
        #error "Is less than 2"
    #end // if

    From_1N_BezierFunction_1A(
        Hodograph_I_1N(
            Values_1N, 1
        )
    )
    
#end // macro From_1N_Der1U_BezierFunction_1A


#macro Der1_BezierFunctions_1A(Values_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if

    Arr_1E(
        From_1N_Der1U_BezierFunction_1A(
            Values_1N
        )
    )

#end // macro Der1_BezierFunctions_1A


#macro From_2N_Der1U_BezierFunction_2A(Values_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimension_size(Values_2N, 1) < 2)
        #error "Is less than 2"
    #end // if

    From_2N_BezierFunction_2A(
        Hodograph_I_2N(
            Values_2N, 1
        )
    )
    
#end // macro From_2N_Der1U_BezierFunction_2A


#macro From_2N_Der1V_BezierFunction_2A(Values_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimension_size(Values_2N, 2) < 2)
        #error "Is less than 2"
    #end // if

    From_2N_BezierFunction_2A(
        Hodograph_J_2N(
            Values_2N, 1
        )
    )
    
#end // macro From_2N_Der1V_BezierFunction_2A


#macro Der1_BezierFunctions_2A(Values_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if

    Arr_2E(
        From_2N_Der1U_BezierFunction_2A(
            Values_2N
        ),
        From_2N_Der1V_BezierFunction_2A(
            Values_2N
        )
    )

#end // macro Der1_BezierFunctions_2A


#macro From_3N_Der1U_BezierFunction_3A(Values_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimension_size(Values_3N, 1) < 2)
        #error "Is less than 2"
    #end // if

    From_3N_BezierFunction_3A(
        Hodograph_I_3N(
            Values_3N, 1
        )
    )
    
#end // macro From_3N_Der1U_BezierFunction_3A


#macro From_3N_Der1V_BezierFunction_3A(Values_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimension_size(Values_3N, 2) < 2)
        #error "Is less than 2"
    #end // if

    From_3N_BezierFunction_3A(
        Hodograph_J_3N(
            Values_3N, 1
        )
    )
    
#end // macro From_3N_Der1V_BezierFunction_3A


#macro From_3N_Der1W_BezierFunction_3A(Values_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimension_size(Values_3N, 3) < 2)
        #error "Is less than 2"
    #end // if

    From_3N_BezierFunction_3A(
        Hodograph_K_3N(
            Values_3N, 1
        )
    )
    
#end // macro From_3N_Der1W_BezierFunction_3A


#macro Der1_BezierFunctions_3A(Values_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if

    Arr_3E(
        From_3N_Der1U_BezierFunction_3A(
            Values_3N
        ),
        From_3N_Der1V_BezierFunction_3A(
            Values_3N
        ),
        From_3N_Der1W_BezierFunction_3A(
            Values_3N
        )
    )

#end // macro Der1_BezierFunctions_3A


#macro From_4N_Der1U_BezierFunction_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimension_size(Values_4N, 1) < 2)
        #error "Is less than 2"
    #end // if

    From_4N_BezierFunction_4A(
        Hodograph_I_4N(
            Values_4N, 1
        )
    )
    
#end // macro From_4N_Der1U_BezierFunction_4A


#macro From_4N_Der1V_BezierFunction_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimension_size(Values_4N, 2) < 2)
        #error "Is less than 2"
    #end // if

    From_4N_BezierFunction_4A(
        Hodograph_J_4N(
            Values_4N, 1
        )
    )
    
#end // macro From_4N_Der1V_BezierFunction_4A


#macro From_4N_Der1W_BezierFunction_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimension_size(Values_4N, 3) < 2)
        #error "Is less than 2"
    #end // if

    From_4N_BezierFunction_4A(
        Hodograph_K_4N(
            Values_4N, 1
        )
    )
    
#end // macro From_4N_Der1W_BezierFunction_4A


#macro From_4N_Der1S_BezierFunction_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimension_size(Values_4N, 4) < 2)
        #error "Is less than 2"
    #end // if

    From_4N_BezierFunction_4A(
        Hodograph_L_4N(
            Values_4N, 1
        )
    )
    
#end // macro From_4N_Der1S_BezierFunction_4A


#macro Der1_BezierFunctions_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if

    Arr_4E(
        From_4N_Der1U_BezierFunction_4A(
            Values_4N
        ),
        From_4N_Der1V_BezierFunction_4A(
            Values_4N
        ),
        From_4N_Der1W_BezierFunction_4A(
            Values_4N
        ),
        From_4N_Der1S_BezierFunction_4A(
            Values_4N
        )
    )

#end // macro Der1_BezierFunctions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_1N_Der2U_BezierFunction_1A(Values_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimension_size(Values_1N, 1) < 3)
        #error "Is less than 3"
    #end // if

    From_1N_BezierFunction_1A(
        Hodograph_I_1N(
            Values_1N, 2
        )
    )
    
#end // macro From_1N_Der2U_BezierFunction_1A


#macro Der2_BezierFunctions_1A(Values_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if

    Arr_1E(
        From_1N_Der2U_BezierFunction_1A(
            Values_1N
        )
    )

#end // macro Der2_BezierFunctions_1A


#macro From_2N_Der2U_BezierFunction_2A(Values_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimension_size(Values_2N, 1) < 3)
        #error "Is less than 3"
    #end // if

    From_2N_BezierFunction_2A(
        Hodograph_I_2N(
            Values_2N, 2
        )
    )
    
#end // macro From_2N_Der2U_BezierFunction_2A


#macro From_2N_Der2V_BezierFunction_2A(Values_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimension_size(Values_2N, 2) < 3)
        #error "Is less than 3"
    #end // if

    From_2N_BezierFunction_2A(
        Hodograph_J_2N(
            Values_2N, 2
        )
    )
    
#end // macro From_2N_Der2V_BezierFunction_2A


#macro Der2_BezierFunctions_2A(Values_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if

    Arr_2E(
        From_2N_Der2U_BezierFunction_2A(
            Values_2N
        ),
        From_2N_Der2V_BezierFunction_2A(
            Values_2N
        )
    )

#end // macro Der2_BezierFunctions_2A


#macro From_3N_Der2U_BezierFunction_3A(Values_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimension_size(Values_3N, 1) < 3)
        #error "Is less than 3"
    #end // if

    From_3N_BezierFunction_3A(
        Hodograph_I_3N(
            Values_3N, 2
        )
    )
    
#end // macro From_3N_Der2U_BezierFunction_3A


#macro From_3N_Der2V_BezierFunction_3A(Values_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimension_size(Values_3N, 2) < 3)
        #error "Is less than 3"
    #end // if

    From_3N_BezierFunction_3A(
        Hodograph_J_3N(
            Values_3N, 2
        )
    )
    
#end // macro From_3N_Der2V_BezierFunction_3A


#macro From_3N_Der2W_BezierFunction_3A(Values_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimension_size(Values_3N, 3) < 3)
        #error "Is less than 3"
    #end // if

    From_3N_BezierFunction_3A(
        Hodograph_K_3N(
            Values_3N, 2
        )
    )
    
#end // macro From_3N_Der2W_BezierFunction_3A


#macro Der2_BezierFunctions_3A(Values_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if

    Arr_3E(
        From_3N_Der2U_BezierFunction_3A(
            Values_3N
        ),
        From_3N_Der2V_BezierFunction_3A(
            Values_3N
        ),
        From_3N_Der2W_BezierFunction_3A(
            Values_3N
        )
    )

#end // macro Der2_BezierFunctions_3A


#macro From_4N_Der2U_BezierFunction_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimension_size(Values_4N, 1) < 3)
        #error "Is less than 3"
    #end // if

    From_4N_BezierFunction_4A(
        Hodograph_I_4N(
            Values_4N, 2
        )
    )
    
#end // macro From_4N_Der2U_BezierFunction_4A


#macro From_4N_Der2V_BezierFunction_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimension_size(Values_4N, 2) < 3)
        #error "Is less than 3"
    #end // if

    From_4N_BezierFunction_4A(
        Hodograph_J_4N(
            Values_4N, 2
        )
    )
    
#end // macro From_4N_Der2V_BezierFunction_4A


#macro From_4N_Der2W_BezierFunction_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimension_size(Values_4N, 3) < 3)
        #error "Is less than 3"
    #end // if

    From_4N_BezierFunction_4A(
        Hodograph_K_4N(
            Values_4N, 2
        )
    )
    
#end // macro From_4N_Der2W_BezierFunction_4A


#macro From_4N_Der2S_BezierFunction_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimension_size(Values_4N, 4) < 3)
        #error "Is less than 3"
    #end // if

    From_4N_BezierFunction_4A(
        Hodograph_L_4N(
            Values_4N, 2
        )
    )
    
#end // macro From_4N_Der2S_BezierFunction_4A


#macro Der2_BezierFunctions_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if

    Arr_4E(
        From_4N_Der2U_BezierFunction_4A(
            Values_4N
        ),
        From_4N_Der2V_BezierFunction_4A(
            Values_4N
        ),
        From_4N_Der2W_BezierFunction_4A(
            Values_4N
        ),
        From_4N_Der2S_BezierFunction_4A(
            Values_4N
        )
    )

#end // macro Der2_BezierFunctions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_1N_Der3U_BezierFunction_1A(Values_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimension_size(Values_1N, 1) < 3)
        #error "Is less than 4"
    #end // if

    From_1N_BezierFunction_1A(
        Hodograph_I_1N(
            Values_1N, 3
        )
    )
    
#end // macro From_1N_Der3U_BezierFunction_1A


#macro Der3_BezierFunctions_1A(Values_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if

    Arr_1E(
        From_1N_Der3U_BezierFunction_1A(
            Values_1N
        )
    )

#end // macro Der3_BezierFunctions_1A


#macro From_2N_Der3U_BezierFunction_2A(Values_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimension_size(Values_2N, 1) < 3)
        #error "Is less than 4"
    #end // if

    From_2N_BezierFunction_2A(
        Hodograph_I_2N(
            Values_2N, 3
        )
    )
    
#end // macro From_2N_Der3U_BezierFunction_2A


#macro From_2N_Der3V_BezierFunction_2A(Values_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimension_size(Values_2N, 2) < 3)
        #error "Is less than 4"
    #end // if

    From_2N_BezierFunction_2A(
        Hodograph_J_2N(
            Values_2N, 3
        )
    )
    
#end // macro From_2N_Der3V_BezierFunction_2A


#macro Der3_BezierFunctions_2A(Values_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if

    Arr_2E(
        From_2N_Der3U_BezierFunction_2A(
            Values_2N
        ),
        From_2N_Der3V_BezierFunction_2A(
            Values_2N
        )
    )

#end // macro Der3_BezierFunctions_2A


#macro From_3N_Der3U_BezierFunction_3A(Values_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimension_size(Values_3N, 1) < 3)
        #error "Is less than 4"
    #end // if

    From_3N_BezierFunction_3A(
        Hodograph_I_3N(
            Values_3N, 3
        )
    )
    
#end // macro From_3N_Der3U_BezierFunction_3A


#macro From_3N_Der3V_BezierFunction_3A(Values_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimension_size(Values_3N, 2) < 3)
        #error "Is less than 4"
    #end // if

    From_3N_BezierFunction_3A(
        Hodograph_J_3N(
            Values_3N, 3
        )
    )
    
#end // macro From_3N_Der3V_BezierFunction_3A


#macro From_3N_Der3W_BezierFunction_3A(Values_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimension_size(Values_3N, 3) < 3)
        #error "Is less than 4"
    #end // if

    From_3N_BezierFunction_3A(
        Hodograph_K_3N(
            Values_3N, 3
        )
    )
    
#end // macro From_3N_Der3W_BezierFunction_3A


#macro Der3_BezierFunctions_3A(Values_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if

    Arr_3E(
        From_3N_Der3U_BezierFunction_3A(
            Values_3N
        ),
        From_3N_Der3V_BezierFunction_3A(
            Values_3N
        ),
        From_3N_Der3W_BezierFunction_3A(
            Values_3N
        )
    )

#end // macro Der3_BezierFunctions_3A


#macro From_4N_Der3U_BezierFunction_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimension_size(Values_4N, 1) < 3)
        #error "Is less than 4"
    #end // if

    From_4N_BezierFunction_4A(
        Hodograph_I_4N(
            Values_4N, 3
        )
    )
    
#end // macro From_4N_Der3U_BezierFunction_4A


#macro From_4N_Der3V_BezierFunction_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimension_size(Values_4N, 2) < 3)
        #error "Is less than 4"
    #end // if

    From_4N_BezierFunction_4A(
        Hodograph_J_4N(
            Values_4N, 3
        )
    )
    
#end // macro From_4N_Der3V_BezierFunction_4A


#macro From_4N_Der3W_BezierFunction_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimension_size(Values_4N, 3) < 3)
        #error "Is less than 4"
    #end // if

    From_4N_BezierFunction_4A(
        Hodograph_K_4N(
            Values_4N, 3
        )
    )
    
#end // macro From_4N_Der3W_BezierFunction_4A


#macro From_4N_Der3S_BezierFunction_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimension_size(Values_4N, 4) < 3)
        #error "Is less than 4"
    #end // if

    From_4N_BezierFunction_4A(
        Hodograph_L_4N(
            Values_4N, 3
        )
    )
    
#end // macro From_4N_Der3S_BezierFunction_4A


#macro Der3_BezierFunctions_4A(Values_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if

    Arr_4E(
        From_4N_Der3U_BezierFunction_4A(
            Values_4N
        ),
        From_4N_Der3V_BezierFunction_4A(
            Values_4N
        ),
        From_4N_Der3W_BezierFunction_4A(
            Values_4N
        ),
        From_4N_Der3S_BezierFunction_4A(
            Values_4N
        )
    )

#end // macro Der3_BezierFunctions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B
