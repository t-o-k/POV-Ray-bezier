// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= 10
/*

https://github.com/t-o-k/POV-Ray-bezier

Copyright (c) 2025-2026 Tor Olav Kristensen, http://subcube.com

Use of this source code is governed by the GNU Lesser General Public License version 3,
which can be found in the LICENSE file.

*/
// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= 10

#version 3.7;

#declare MIN_CYLINDER_LENGTH = 1e-6;

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

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

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

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


// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

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

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

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

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#declare _NoNegativeZeroFn =
    function(_a) { select(_a, _a, 0, _a) }
;

// To avoid unnecessary parse warnings about zero power
#declare PowFn =
    function(_b, _n) { pow(_b, _n) }
;

#declare FactFn =
    function(_n) {
        prod(_i, 1, _n, _i)
    }
;

#declare FactFallingFn =
    function(_n, _k) {
        _NoNegativeZeroFn(
            prod(_i, _n - _k + 1, _n, _i)
        )
    }
;

#declare FactRisingFn =
    function(_n, _k) {
        _NoNegativeZeroFn(
            prod(_i, _n, _n + _k - 1, _i)
        )
    }
;

#declare PermFn =
    function(_n, _k) {
        FactFallingFn(_n, _k)
    }
;

#declare CombFn =
    function(_n, _k) {
        select(
            _n - 2*_k,
            FactFallingFn(_n, _n - _k)/FactFn(_n - _k),
            FactFallingFn(_n, _k)/FactFn(_k)
        )
    }
;

#declare BinomialFn =
    function(_n, _k) {
        select(
            _n - 2*_k,
            FactFallingFn(_n, _n - _k)/FactFn(_n - _k),
            FactFallingFn(_n, _k)/FactFn(_k)
        )
    }
;

#declare BernsteinCoefficientFn =
    function(_p, _k, _n) {
        PowFn(-1, _p - _k)*CombFn(_n, _p)*CombFn(_p, _k)
    }
;

// B(k, n)(t)
#declare BernsteinFn =
    function(_k, _n, _t) {
        sum(
            _i, _k, _n,
            BernsteinCoefficientFn(_i, _k, _n)
            *
            PowFn(_t, _i)
        )
    }
;


#macro BernsteinFunction(K, N)

    function(_t) {
        sum(
            _i, K, N,
            BernsteinCoefficientFn(_i, K, N)
            *
            PowFn(_t, _i)
        )
    }

#end // macro BernsteinFunction

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro DivideFunctions_1A(_Num_Function_1A, _Den_Function_1A)

    function(_u) {
        _Num_Function_1A(_u)
        /
        _Den_Function_1A(_u)
    }

#end // macro DivideFunctions_1A


#macro DivideFunctions_2A(_Num_Function_2A, _Den_Function_2A)

    function(_u, _v) {
        _Num_Function_2A(_u, _v)
        /
        _Den_Function_2A(_u, _v)
    }

#end // macro DivideFunctions_2A


#macro DivideFunctions_3A(_Num_Function_3A, _Den_Function_3A)

    function(_u, _v, _w) {
        _Num_Function_3A(_u, _v, _w)
        /
        _Den_Function_3A(_u, _v, _w)
    }

#end // macro DivideFunctions_3A


#macro DivideFunctions_4A(_Num_Function_4A, _Den_Function_4A)

    function(_u, _v, _w, _s) {
        _Num_Function_4A(_u, _v, _w, _s)
        /
        _Den_Function_4A(_u, _v, _w, _s)
    }

#end // macro DivideFunctions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Der1_RationalFunction_1A(_NumFn1A, _DenFn1A, _D1NumFn1A, _D1DenFn1A)

    function(_u) {
        (
            _D1NumFn1A(_u)
            -
            _D1DenFn1A(_u)
            *
            _NumFn1A(_u)
            /
            _DenFn1A(_u)
        )
        /
        _DenFn1A(_u)
    }

#end // macro Der1_RationalFunction_1A


#macro Der1_RationalFunction_2A(_NumFn2A, _DenFn2A, _D1NumFn2A, _D1DenFn2A)

    function(_u, _v) {
        (
            _D1NumFn2A(_u, _v)
            -
            _D1DenFn2A(_u, _v)
            *
            _NumFn2A(_u, _v)
            /
            _DenFn2A(_u, _v)
        )
        /
        _DenFn2A(_u, _v)
    }

#end // macro Der1_RationalFunction_2A


#macro Der1_RationalFunction_3A(_NumFn3A, _DenFn3A, _D1NumFn3A, _D1DenFn3A)

    function(_u, _v, _w) {
        (
            _D1NumFn3A(_u, _v, _w)
            -
            _D1DenFn3A(_u, _v, _w)
            *
            _NumFn3A(_u, _v, _w)
            /
            _DenFn3A(_u, _v, _w)
        )
        /
        _DenFn3A(_u, _v, _w)
    }

#end // macro Der1_RationalFunction_3A


#macro Der1_RationalFunction_4A(_NumFn4A, _DenFn4A, _D1NumFn4A, _D1DenFn4A)

    function(_u, _v, _w, _s) {
        (
            _D1NumFn4A(_u, _v, _w, _s)
            -
            _D1DenFn4A(_u, _v, _w, _s)
            *
            _NumFn4A(_u, _v, _w, _s)
            /
            _DenFn4A(_u, _v, _w, _s)
        )
        /
        _DenFn4A(_u, _v, _w, _s)
    }

#end // macro Der1_RationalFunction_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Der2_RationalFunction_1A(_NumFn1A, _DenFn1A, _D1NumFn1A, _D1DenFn1A, _D2NumFn1A, _D2DenFn1A)

    function(_u) {
        (
            _D2NumFn1A(_u)*pow(_DenFn1A(_u), 2)
            -
            (
                2*_D1NumFn1A(_u)*_D1DenFn1A(_u)
                +
                _NumFn1A(_u)*_D2DenFn1A(_u)
            )*_DenFn1A(_u)
            +
            2*_NumFn1A(_u)*pow(_D1DenFn1A(_u), 2)
        )/pow(_DenFn1A(_u), 3)
    }

#end // macro Der2_RationalFunction_1A


#macro Der2_RationalFunction_2A(_NumFn2A, _DenFn2A, _D1NumFn2A, _D1DenFn2A, _D2NumFn2A, _D2DenFn2A)

    function(_u, _v) {
        (
            _D2NumFn2A(_u, _v)*pow(_DenFn2A(_u, _v), 2)
            -
            (
                2*_D1NumFn2A(_u, _v)*_D1DenFn2A(_u, _v)
                +
                _NumFn2A(_u, _v)*_D2DenFn2A(_u, _v)
            )*_DenFn2A(_u, _v)
            + 
            2*_NumFn2A(_u, _v)*pow(_D1DenFn2A(_u, _v), 2)
        )/pow(_DenFn2A(_u, _v), 3)
    }

#end // macro Der2_RationalFunction_2A


#macro Der2_RationalFunction_3A(_NumFn3A, _DenFn3A, _D1NumFn3A, _D1DenFn3A, _D2NumFn3A, _D2DenFn3A)

    function(_u, _v, _w) {
        (
            _D2NumFn3A(_u, _v, _w)*pow(_DenFn3A(_u, _v, _w), 2)
            -
            (
                2*_D1NumFn3A(_u, _v, _w)*_D1DenFn3A(_u, _v, _w)
                +
                _NumFn3A(_u, _v, _w)*_D2DenFn3A(_u, _v, _w)
            )*_DenFn3A(_u, _v, _w)
            + 
            2*_NumFn3A(_u, _v, _w)*pow(_D1DenFn3A(_u, _v, _w), 2)
        )/pow(_DenFn3A(_u, _v, _w), 3)
    }

#end // macro Der2_RationalFunction_3A


#macro Der2_RationalFunction_4A(_NumFn4A, _DenFn4A, _D1NumFn4A, _D1DenFn4A, _D2NumFn4A, _D2DenFn4A)

    function(_u, _v, _w, _s) {
        (
            _D2NumFn4A(_u, _v, _w, _s)*pow(_DenFn4A(_u, _v, _w, _s), 2)
            -
            (
                2*_D1NumFn4A(_u, _v, _w, _s)*_D1DenFn4A(_u, _v, _w, _s)
                +
                _NumFn4A(_u, _v, _w, _s)*_D2DenFn4A(_u, _v, _w, _s)
            )*_DenFn4A(_u, _v, _w, _s)
            + 
            2*_NumFn4A(_u, _v, _w, _s)*pow(_D1DenFn4A(_u, _v, _w, _s), 2)
        )/pow(_DenFn4A(_u, _v, _w, _s), 3)
    }

#end // macro Der2_RationalFunction_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

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

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro ExtractComponent_1N(VV_1N, vC)

    #local N = dimensions(VV_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(VV_1N, 1);
    #local LastI = SizeI - 1;
    #local CC1N = array[SizeI];
    #for (I, 0, LastI)
        #local CC1N[I] =
            vdot(VV_1N[I], vC)
        ;
    #end // for

    CC1N

#end // macro ExtractComponent_1N


#macro ExtractComponent_2N(VV_2N, vC)

    #local N = dimensions(VV_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(VV_2N, 1);
    #local SizeJ = dimension_size(VV_2N, 2);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local CC2N = array[SizeI][SizeJ];
    #for (J, 0, LastJ)
        #for (I, 0, LastI)
            #local CC2N[I][J] =
                vdot(VV_2N[I][J], vC)
            ;
        #end // for
    #end // for

    CC2N

#end // macro ExtractComponent_2N


#macro ExtractComponent_3N(VV_3N, vC)

    #local N = dimensions(VV_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(VV_3N, 1);
    #local SizeJ = dimension_size(VV_3N, 2);
    #local SizeK = dimension_size(VV_3N, 3);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local CC3N = array[SizeI][SizeJ][SizeK];
    #for (K, 0, LastK)
        #for (J, 0, LastJ)
            #for (I, 0, LastI)
                #local CC3N[I][J][K] =
                    vdot(VV_3N[I][J][K], vC)
                ;
            #end // for
        #end // for
    #end // for

    CC3N

#end // macro ExtractComponent_3N


#macro ExtractComponent_4N(VV_4N, vC)

    #local N = dimensions(VV_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(VV_4N, 1);
    #local SizeJ = dimension_size(VV_4N, 2);
    #local SizeK = dimension_size(VV_4N, 3);
    #local SizeL = dimension_size(VV_4N, 4);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local LastL = SizeL - 1;
    #local CC4N = array[SizeI][SizeJ][SizeK][SizeL];
    #for (L, 0, LastL)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI)
                    #local CC4N[I][J][K][L] =
                        vdot(VV_4N[I][J][K][L], vC)
                    ;
                #end // for
            #end // for
        #end // for
    #end // for

    CC4N

#end // macro ExtractComponent_4N


#macro ExtractComponent(VV, vC)

    #local N = dimensions(VV);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if
    #switch (N)
        #case (1)  // 1N
            #local CC =
                ExtractComponent_1N(VV, vC)
            ;
            #break
        #case (2)  // 2N
            #local CC =
                ExtractComponent_2N(VV, vC)
            ;
            #break
        #case (3)  // 3N
            #local CC =
                ExtractComponent_3N(VV, vC)
            ;
            #break
        #case (4)  // 4N
            #local CC =
                ExtractComponent_4N(VV, vC)
            ;
            #break
        #else
            #error "!"
    #end // switch

    CC

#end // macro ExtractComponent

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= 10

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
    #local AA2N = array[SizeI][SizeJ];
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #for (J, 0, LastJ)
        #for (I, 0, LastI)
            #local AA2N[I][J] =
                ArrayI_1N[I]*ArrayJ_1N[J]
            ;
        #end // for
    #end // for

    AA2N

#end // macro From_1N_OuterProduct_2N

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= 10

#macro From_1N_WrapArray(Array_1N, WrapCount)

    #local N = dimensions(Array_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(WrapCount) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(WrapCount, 1) != 1)
        #error "Is not 1"
    #end // if
    #local SizeI = dimension_size(Array_1N, 1);
    #local WrapCountI = I_E(WrapCount);
    #local NewSizeI = SizeI + WrapCountI;
    #local AA1N = array[NewSizeI];
    #for (I, 0, NewSizeI - 1)
        #local IM = mod(I, SizeI);
        #local AA1N[I] =
            Array_1N[IM]
        ;
    #end // for

    AA1N

#end // macro From_1N_WrapArray


#macro From_2N_WrapArray(Array_2N, WrapCount)

    #local N = dimensions(Array_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(WrapCount) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(WrapCount, 1) != 2)
        #error "Is not 2"
    #end // if
    #local SizeI = dimension_size(Array_2N, 1);
    #local SizeJ = dimension_size(Array_2N, 2);
    #local WrapCountI = I_E(WrapCount);
    #local WrapCountJ = J_E(WrapCount);
    #local NewSizeI = SizeI + WrapCountI;
    #local NewSizeJ = SizeJ + WrapCountJ;
    #local AA2N = array[NewSizeI][NewSizeJ];
    #for (J, 0, NewSizeJ - 1)
        #local JM = mod(J, SizeJ);
        #for (I, 0, NewSizeI - 1)
            #local IM = mod(I, SizeI);
            #local AA2N[I][J] =
                Array_2N[IM][JM]
            ;
        #end // for
    #end // for

    AA2N

#end // macro From_2N_WrapArray


#macro From_3N_WrapArray(Array_3N, WrapCount)

    #local N = dimensions(Array_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(WrapCount) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(WrapCount, 1) != 3)
        #error "Is not 3"
    #end // if
    #local SizeI = dimension_size(Array_3N, 1);
    #local SizeJ = dimension_size(Array_3N, 2);
    #local SizeK = dimension_size(Array_3N, 3);
    #local WrapCountI = I_E(WrapCount);
    #local WrapCountJ = J_E(WrapCount);
    #local WrapCountK = K_E(WrapCount);
    #local NewSizeI = SizeI + WrapCountI;
    #local NewSizeJ = SizeJ + WrapCountJ;
    #local NewSizeK = SizeK + WrapCountK;
    #local AA3N = array[NewSizeI][NewSizeJ][NewSizeK];
    #for (K, 0, NewSizeK - 1)
        #local KM = mod(K, SizeK);
        #for (J, 0, NewSizeJ - 1)
            #local JM = mod(J, SizeJ);
            #for (I, 0, NewSizeI - 1)
                #local IM = mod(I, SizeI);
                #local AA3N[I][J][K] =
                    Array_3N[IM][JM][KM]
                ;
            #end // for
        #end // for
    #end // for

    AA3N

#end // macro From_3N_WrapArray


#macro From_4N_WrapArray(Array_4N, WrapCount)

    #local N = dimensions(Array_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(WrapCount) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(WrapCount, 1) != 4)
        #error "Is not 4"
    #end // if
    #local SizeI = dimension_size(Array_4N, 1);
    #local SizeJ = dimension_size(Array_4N, 2);
    #local SizeK = dimension_size(Array_4N, 3);
    #local SizeL = dimension_size(Array_4N, 4);
    #local WrapCountI = I_E(WrapCount);
    #local WrapCountJ = J_E(WrapCount);
    #local WrapCountK = K_E(WrapCount);
    #local WrapCountL = L_E(WrapCount);
    #local NewSizeI = SizeI + WrapCountI;
    #local NewSizeJ = SizeJ + WrapCountJ;
    #local NewSizeK = SizeK + WrapCountK;
    #local NewSizeL = SizeL + WrapCountL;
    #local AA4N = array[NewSizeI][NewSizeJ][NewSizeK][NewSizeL];
    #for (L, 0, NewSizeL - 1)
        #local LM = mod(L, SizeL);
        #for (K, 0, NewSizeK - 1)
            #local KM = mod(K, SizeK);
            #for (J, 0, NewSizeJ - 1)
                #local JM = mod(J, SizeJ);
                #for (I, 0, NewSizeI - 1)
                    #local IM = mod(I, SizeI);
                    #local AA4N[I][J][K][L] =
                        Array_4N[IM][JM][KM][LM]
                    ;
                #end // for
            #end // for
        #end // for
    #end // for

    AA4N

#end // macro From_4N_WrapArray


#macro WrapArray(Array, WrapCount)

    #local N = dimensions(Array);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if
    #if (dimensions(WrapCount) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(WrapCount, 1) != N)
        #error "Is not equal to N"
    #end // if
    #switch (N)
        #case (1)  // 1N
            #local AA =
                From_1N_WrapArray(
                    Array, WrapCount
                )
            ;
            #break
        #case (2)  // 2N
            #local AA =
                From_2N_WrapArray(
                    Array, WrapCount
                )
            ;
            #break
        #case (3)  // 3N
            #local AA =
                From_3N_WrapArray(
                    Array, WrapCount
                )
            ;
            #break
        #case (4)  // 4N
            #local AA =
                From_4N_WrapArray(
                    Array, WrapCount
                )
            ;
            #break
        #else
            #error "!"
    #end // switch

    AA

#end // macro WrapArray

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= 10

#macro MultiplyArrays_1N(Array0_1N, Array1_1N)

    #local N0 = dimensions(Array0_1N);
    #if (N0 != 1)
        #error "N0 is not 1"
    #end // if
    #local N1 = dimensions(Array1_1N);
    #if (N1 != 1)
        #error "N1 is not 1"
    #end // if
    #local SizeI = dimension_size(Array0_1N, 1);
    #if (dimension_size(Array1_1N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #local AA1N = array[SizeI];
    #local LastI = SizeI - 1;
    #for (I, 0, LastI)
        #local AA1N[I] =
            Array0_1N[I]
            *
            Array1_1N[I]
        ;
    #end // for

    AA1N

#end // macro MultiplyArrays_1N


#macro MultiplyArrays_2N(Array0_2N, Array1_2N)

    #local N0 = dimensions(Array0_2N);
    #if (N0 != 2)
        #error "N0 is not 2"
    #end // if
    #local N1 = dimensions(Array1_2N);
    #if (N1 != 2)
        #error "N1 is not 2"
    #end // if
    #local SizeI = dimension_size(Array0_2N, 1);
    #local SizeJ = dimension_size(Array0_2N, 2);
    #if (dimension_size(Array1_2N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #if (dimension_size(Array1_2N, 2) != SizeJ)
        #error "Is not equal to SizeJ"
    #end // if
    #local AA2N = array[SizeI][SizeJ];
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #for (J, 0, LastJ)
        #for (I, 0, LastI)
            #local AA2N[I][J] =
                Array0_2N[I][J]
                *
                Array1_2N[I][J]
            ;
        #end // for
    #end // for

    AA2N

#end // macro MultiplyArrays_2N


#macro MultiplyArrays_3N(Array0_3N, Array1_3N)

    #local N0 = dimensions(Array0_3N);
    #if (N0 != 3)
        #error "N0 is not 3"
    #end // if
    #local N1 = dimensions(Array1_3N);
    #if (N1 != 3)
        #error "N1 is not 3"
    #end // if
    #local SizeI = dimension_size(Array0_3N, 1);
    #local SizeJ = dimension_size(Array0_3N, 2);
    #local SizeK = dimension_size(Array0_3N, 3);
    #if (dimension_size(Array1_3N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #if (dimension_size(Array1_3N, 2) != SizeJ)
        #error "Is not equal to SizeJ"
    #end // if
    #if (dimension_size(Array1_3N, 3) != SizeK)
        #error "Is not equal to SizeK"
    #end // if
    #local AA3N = array[SizeI][SizeJ][SizeK];
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #for (K, 0, LastK)
        #for (J, 0, LastJ)
            #for (I, 0, LastI)
                #local AA3N[I][J][K] =
                    Array0_3N[I][J][K]
                    *
                    Array1_3N[I][J][K]
                ;
            #end // for
        #end // for
    #end // for

    AA3N

#end // macro MultiplyArrays_3N


#macro MultiplyArrays_4N(Array0_4N, Array1_4N)

    #local N0 = dimensions(Array0_4N);
    #if (N0 != 4)
        #error "N0 is not 4"
    #end // if
    #local N1 = dimensions(Array1_4N);
    #if (N1 != 4)
        #error "N1 is not 4"
    #end // if
    #local SizeI = dimension_size(Array0_4N, 1);
    #local SizeJ = dimension_size(Array0_4N, 2);
    #local SizeK = dimension_size(Array0_4N, 3);
    #local SizeL = dimension_size(Array0_4N, 4);
    #if (dimension_size(Array1_4N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #if (dimension_size(Array1_4N, 2) != SizeJ)
        #error "Is not equal to SizeJ"
    #end // if
    #if (dimension_size(Array1_4N, 3) != SizeK)
        #error "Is not equal to SizeK"
    #end // if
    #if (dimension_size(Array1_4N, 4) != SizeL)
        #error "Is not equal to SizeL"
    #end // if
    #local AA4N = array[SizeI][SizeJ][SizeK][SizeL];
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local LastL = SizeL - 1;
    #for (L, 0, LastL)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI)
                    #local AA4N =
                        Array0_4N[I][J][K][L]
                        *
                        Array1_4N[I][J][K][L]
                    ;
                #end // for
            #end // for
        #end // for
    #end // for

    AA4N

#end // macro MultiplyArrays_4N


#macro MultiplyArrays(Array0, Array1)

    #local N0 = dimensions(Array0);
    #if (!((N0 = 1) | (N0 = 2) | (N0 = 3) | (N0 = 4)))
        #error "N0 is neither 1, 2, 3 nor 4"
    #end // if
    #local N1 = dimensions(Array1);
    #if (N1 != N0)
        #error "N0 and N1 are not equal"
    #end // if
            
    #switch (N0)
        #case (1)
            #local AA =
                MultiplyArrays_1N(
                    Array0, Array1
                )
            ;
            #break
        #case (2)
            #local AA =
                MultiplyArrays_2N(
                    Array0, Array1
                 )
            ;
            #break
        #case (3)
            #local AA =
                MultiplyArrays_3N(
                    Array0, Array1
                )
            ;
            #break
        #case (4)
            #local AA =
                MultiplyArrays_4N(
                    Array0, Array1
                )
            ;
            #break
        #else
            #error "!"
    #end // switch

    AA

#end // macro MultiplyArrays

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro DivideArrays_1N(Array0_1N, Array1_1N)

    #local N0 = dimensions(Array0_1N);
    #if (N0 != 1)
        #error "N0 is not 1"
    #end // if
    #local N1 = dimensions(Array1_1N);
    #if (N1 != 1)
        #error "N1 is not 1"
    #end // if
    #local SizeI = dimension_size(Array0_1N, 1);
    #if (dimension_size(Array1_1N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #local AA1N = array[SizeI];
    #local LastI = SizeI - 1;
    #for (I, 0, LastI)
        #local AA1N[I] =
            Array0_1N[I]
            /
            Array1_1N[I]
        ;
    #end // for

    AA1N

#end // macro DivideArrays_1N


#macro DivideArrays_2N(Array0_2N, Array1_2N)

    #local N0 = dimensions(Array0_2N);
    #if (N0 != 2)
        #error "N0 is not 2"
    #end // if
    #local N1 = dimensions(Array1_2N);
    #if (N1 != 2)
        #error "N1 is not 2"
    #end // if
    #local SizeI = dimension_size(Array0_2N, 1);
    #local SizeJ = dimension_size(Array0_2N, 2);
    #if (dimension_size(Array1_2N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #if (dimension_size(Array1_2N, 2) != SizeJ)
        #error "Is not equal to SizeJ"
    #end // if
    #local AA2N = array[SizeI][SizeJ];
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #for (J, 0, LastJ)
        #for (I, 0, LastI)
            #local AA2N[I][J] =
                Array0_2N[I][J]
                /
                Array1_2N[I][J]
            ;
        #end // for
    #end // for

    AA2N

#end // macro DivideArrays_2N


#macro DivideArrays_3N(Array0_3N, Array1_3N)

    #local N0 = dimensions(Array0_3N);
    #if (N0 != 3)
        #error "N0 is not 3"
    #end // if
    #local N1 = dimensions(Array1_3N);
    #if (N1 != 3)
        #error "N1 is not 3"
    #end // if
    #local SizeI = dimension_size(Array0_3N, 1);
    #local SizeJ = dimension_size(Array0_3N, 2);
    #local SizeK = dimension_size(Array0_3N, 3);
    #if (dimension_size(Array1_3N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #if (dimension_size(Array1_3N, 2) != SizeJ)
        #error "Is not equal to SizeJ"
    #end // if
    #if (dimension_size(Array1_3N, 3) != SizeK)
        #error "Is not equal to SizeK"
    #end // if
    #local AA3N = array[SizeI][SizeJ][SizeK];
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #for (K, 0, LastK)
        #for (J, 0, LastJ)
            #for (I, 0, LastI)
                #local AA3N[I][J][K] =
                    Array0_3N[I][J][K]
                    /
                    Array1_3N[I][J][K]
                ;
            #end // for
        #end // for
    #end // for

    AA3N

#end // macro DivideArrays_3N


#macro DivideArrays_4N(Array0_4N, Array1_4N)

    #local N0 = dimensions(Array0_4N);
    #if (N0 != 4)
        #error "N0 is not 4"
    #end // if
    #local N1 = dimensions(Array1_4N);
    #if (N1 != 4)
        #error "N1 is not 4"
    #end // if
    #local SizeI = dimension_size(Array0_4N, 1);
    #local SizeJ = dimension_size(Array0_4N, 2);
    #local SizeK = dimension_size(Array0_4N, 3);
    #local SizeL = dimension_size(Array0_4N, 4);
    #if (dimension_size(Array1_4N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #if (dimension_size(Array1_4N, 2) != SizeJ)
        #error "Is not equal to SizeJ"
    #end // if
    #if (dimension_size(Array1_4N, 3) != SizeK)
        #error "Is not equal to SizeK"
    #end // if
    #if (dimension_size(Array1_4N, 4) != SizeL)
        #error "Is not equal to SizeL"
    #end // if
    #local AA4N = array[SizeI][SizeJ][SizeK][SizeL];
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local LastL = SizeL - 1;
    #for (L, 0, LastL)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI)
                    #local AA4N[I][J][K][L] =
                        Array0_4N[I][J][K][L]
                        /
                        Array1_4N[I][J][K][L]
                    ;
                #end // for
            #end // for
        #end // for
    #end // for

    AA4N

#end // macro DivideArrays_4N


#macro DivideArrays(Array0, Array1)

    #local N0 = dimensions(Array0);
    #if (!((N0 = 1) | (N0 = 2) | (N0 = 3) | (N0 = 4)))
        #error "N0 is neither 1, 2, 3 nor 4"
    #end // if
    #local N1 = dimensions(Array1);
    #if (N1 != N0)
        #error "N0 and N1 are not equal"
    #end // if
            
    #switch (N0)
        #case (1)
            #local AA =
                DivideArrays_1N(
                    Array0, Array1
                )
            ;
            #break
        #case (2)
            #local AA =
                DivideArrays_2N(
                    Array0, Array1
                )
            ;
            #break
        #case (3)
            #local AA =
                DivideArrays_3N(
                    Array0, Array1
                )
            ;
            #break
        #case (4)
            #local AA =
                DivideArrays_4N(
                    Array0, Array1
                )
            ;
            #break
        #else
            #error "!"
    #end // switch

    AA

#end // macro DivideArrays

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Sphere_2D(pC, Radius)

    #local U0 = pC.u;
    #local V0 = pC.v;

    sphere { <U0, V0, 0>, Radius }

#end // macro Sphere_2D


#macro Cylinder_2D(pA, pB, Radius)

    #local U0 = pA.u;
    #local V0 = pA.v;
    #local U1 = pB.u;
    #local V1 = pB.v;
    #local p0 = <U0, V0, 0>;
    #local p1 = <U1, V1, 0>;

    #if (vlength(p1 - p0) >= MIN_CYLINDER_LENGTH)
        cylinder { p0, p1, Radius }
    #end // if

#end // macro Cylinder_2D


#macro Cylinder_3D(pA, pB, Radius)

    #if (vlength(pB - pA) >= MIN_CYLINDER_LENGTH)
        cylinder { pA, pB, Radius }
    #end // if

#end // macro Cylinder_3D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_1N_ShowPoints_2D(Points_1N2D, Radius)

    #local N = dimensions(Points_1N2D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(Points_1N2D, 1);
    #local LastI = SizeI - 1;

    #if (Radius > 0.0)
        #for (I, 0, LastI)
            Sphere_2D(
                Points_1N2D[I],
                Radius
            )
        #end // for
    #end // if

#end // macro From_1N_ShowPoints_2D


#macro From_3N_ShowPoints_2D(Points_3N2D, Radius)

    #local N = dimensions(Points_3N2D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(Points_3N2D, 1);
    #local SizeJ = dimension_size(Points_3N2D, 2);
    #local SizeK = dimension_size(Points_3N2D, 3);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;

    #if (Radius > 0.0)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI)
                    Sphere_2D(
                        Points_3N2D[I][J][K],
                        Radius
                    )
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_3N_ShowPoints_2D


#macro From_4N_ShowPoints_2D(Points_4N2D, Radius)

    #local N = dimensions(Points_4N2D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Points_4N2D, 1);
    #local SizeJ = dimension_size(Points_4N2D, 2);
    #local SizeK = dimension_size(Points_4N2D, 3);
    #local SizeL = dimension_size(Points_4N2D, 4);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local LastL = SizeL - 1;

    #if (Radius > 0.0)
        #for (L, 0, LastL)
            #for (K, 0, LastK)
                #for (J, 0, LastJ)
                    #for (I, 0, LastI)
                        Sphere_2D(
                            Points_4N2D[I][J][K][L],
                            Radius
                        )
                    #end // for
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_4N_ShowPoints_2D


#macro ShowPoints_2D(Points_2D, Radius)

    #local N = dimensions(Points_2D);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if

    #switch (N)
        #case (1)
            From_1N_ShowPoints_2D(
                Points_2D, Radius
            )
            #break
        #case (2)
            From_2N_ShowPoints_2D(
                Points_2D, Radius
            )
            #break
        #case (3)
            From_3N_ShowPoints_2D(
                Points_2D, Radius
            )
            #break
        #case (4)
            From_4N_ShowPoints_2D(
                Points_2D, Radius
            )
            #break
        #else
            #error "!"
    #end // switch

#end // macro ShowPoints_2D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= 10

#macro From_1N_ShowPoints_3D(Points_1N3D, Radius)

    #local N = dimensions(Points_1N3D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(Points_1N3D, 1);
    #local LastI = SizeI - 1;

    #if (Radius > 0.0)
        #for (I, 0, LastI)
            sphere {
                Points_1N3D[I],
                Radius
            }
        #end // for
    #end // if

#end // macro From_1N_ShowPoints_3D


#macro From_2N_ShowPoints_3D(Points_2N3D, Radius)

    #local N = dimensions(Points_2N3D);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(Points_2N3D, 1);
    #local SizeJ = dimension_size(Points_2N3D, 2);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;

    #if (Radius > 0.0)
        #for (J, 0, LastJ)
            #for (I, 0, LastI)
                sphere {
                    Points_2N3D[I][J],
                    Radius
                }
            #end // for
        #end // for
    #end // if

#end // macro From_2N_ShowPoints_3D


#macro From_3N_ShowPoints_3D(Points_3N3D, Radius)

    #local N = dimensions(Points_3N3D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(Points_3N3D, 1);
    #local SizeJ = dimension_size(Points_3N3D, 2);
    #local SizeK = dimension_size(Points_3N3D, 3);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;

    #if (Radius > 0.0)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI)
                    sphere {
                        Points_3N3D[I][J][K],
                        Radius
                    }
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_3N_ShowPoints_3D


#macro From_4N_ShowPoints_3D(Points_4N3D, Radius)

    #local N = dimensions(Points_4N3D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Points_4N3D, 1);
    #local SizeJ = dimension_size(Points_4N3D, 2);
    #local SizeK = dimension_size(Points_4N3D, 3);
    #local SizeL = dimension_size(Points_4N3D, 4);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local LastL = SizeL - 1;

    #if (Radius > 0.0)
        #for (L, 0, LastL)
            #for (K, 0, LastK)
                #for (J, 0, LastJ)
                    #for (I, 0, LastI)
                        sphere {
                            Points_4N3D[I][J][K][L],
                            Radius
                        }
                    #end // for
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_4N_ShowPoints_3D


#macro ShowPoints_3D(Points_3D, Radius)

    #local N = dimensions(Points_3D);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if

    #switch (N)
        #case (1)
            From_1N_ShowPoints_3D(
                Points_3D, Radius
            )
            #break
        #case (2)
            From_2N_ShowPoints_3D(
                Points_3D, Radius
            )
            #break
        #case (3)
            From_3N_ShowPoints_3D(
                Points_3D, Radius
            )
            #break
        #case (4)
            From_4N_ShowPoints_3D(
                Points_3D, Radius
            )
            #break
        #else
            #error "!"
    #end // switch

#end // macro ShowPoints_3D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= 10

#macro From_1N_ShowLines_2D(Points_1N2D, Radius_I)

    #local N = dimensions(Points_1N2D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Radius_I) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_I, 1) != 1)
        #error "Is not 1"
    #end // if
    #local SizeI = dimension_size(Points_1N2D, 1);
    #local RadiusI = I_E(Radius_I);
    #local LastI = SizeI - 1;

    #if (RadiusI > 0.0)
        #for (I, 0, LastI - 1)
            Cylinder_2D(
                Points_1N2D[I  ],
                Points_1N2D[I+1],
                RadiusI
            )
        #end // for
    #end // if

#end // macro From_1N_ShowLines_2D


#macro From_2N_ShowLines_2D(Points_2N2D, Radius_IJ)

    #local N = dimensions(Points_2N2D);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Radius_IJ) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJ, 1) != 2)
        #error "Is not 2"
    #end // if
    #local SizeI = dimension_size(Points_2N2D, 1);
    #local SizeJ = dimension_size(Points_2N2D, 2);
    #local RadiusI = I_E(Radius_IJ);
    #local RadiusJ = J_E(Radius_IJ);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;

    #if (RadiusI > 0.0)
        #for (J, 0, LastJ)
            #for (I, 0, LastI - 1)
                Cylinder_2D(
                    Points_2N2D[I  ][J],
                    Points_2N2D[I+1][J],
                    RadiusI
                )
            #end // for
        #end // for
    #end // if
    #if (RadiusJ > 0.0)
        #for (I, 0, LastI)
            #for (J, 0, LastJ - 1)
                Cylinder_2D(
                    Points_2N2D[I][J  ],
                    Points_2N2D[I][J+1],
                    RadiusJ
                )
            #end // for
        #end // for
    #end // if

#end // macro From_2N_ShowLines_2D


#macro From_3N_ShowLines_2D(Points_3N2D, Radius_IJK)

    #local N = dimensions(Points_3N2D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Radius_IJK) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJK, 1) != 3)
        #error "Is not 3"
    #end // if
    #local SizeI = dimension_size(Points_3N2D, 1);
    #local SizeJ = dimension_size(Points_3N2D, 2);
    #local SizeK = dimension_size(Points_3N2D, 3);
    #local RadiusI = I_E(Radius_IJK);
    #local RadiusJ = J_E(Radius_IJK);
    #local RadiusK = K_E(Radius_IJK);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;

    #if (RadiusI > 0.0)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI - 1)
                    Cylinder_2D(
                        Points_3N2D[I  ][J][K],
                        Points_3N2D[I+1][J][K],
                        RadiusI
                    )
                #end // for
            #end // for
        #end // for
    #end // if
    #if (RadiusJ > 0.0)
        #for (I, 0, LastI)
            #for (K, 0, LastK)
                #for (J, 0, LastJ - 1)
                    Cylinder_2D(
                        Points_3N2D[I][J  ][K],
                        Points_3N2D[I][J+1][K],
                        RadiusJ
                    )
                #end // for
            #end // for
        #end // for
    #end // if
    #if (RadiusK > 0.0)
        #for (J, 0, LastJ)
            #for (I, 0, LastI)
                #for (K, 0, LastK - 1)
                    Cylinder_2D(
                        Points_3N2D[I][J][K  ],
                        Points_3N2D[I][J][K+1],
                        RadiusK
                    )
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_3N_ShowLines_2D


#macro From_4N_ShowLines_2D(Points_4N2D, Radius_IJKL)

    #local N = dimensions(Points_4N2D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Radius_IJKL) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJKL, 1) != 4)
        #error "Is not 4"
    #end // if
    #local SizeI = dimension_size(Points_4N2D, 1);
    #local SizeJ = dimension_size(Points_4N2D, 2);
    #local SizeK = dimension_size(Points_4N2D, 3);
    #local SizeL = dimension_size(Points_4N2D, 4);
    #local RadiusI = I_E(Radius_IJKL);
    #local RadiusJ = J_E(Radius_IJKL);
    #local RadiusK = K_E(Radius_IJKL);
    #local RadiusL = L_E(Radius_IJKL);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local LastL = SizeL - 1;

    #if (RadiusI > 0.0)
        #for (L, 0, LastL)
            #for (K, 0, LastK)
                #for (J, 0, LastJ)
                    #for (I, 0, LastI - 1)
                        Cylinder_2D(
                            Points_4N2D[I  ][J][K][L],
                            Points_4N2D[I+1][J][K][L],
                            RadiusI
                        )
                    #end // for
                #end // for
            #end // for
        #end // for
    #end // if
    #if (RadiusJ > 0.0)
        #for (I, 0, LastI)
            #for (L, 0, LastL)
                #for (K, 0, LastK)
                    #for (J, 0, LastJ - 1)
                        Cylinder_2D(
                            Points_4N2D[I][J  ][K][L],
                            Points_4N2D[I][J+1][K][L],
                            RadiusJ
                        )
                    #end // for
                #end // for
            #end // for
        #end // for
    #end // if
    #if (RadiusK > 0.0)
        #for (J, 0, LastJ)
            #for (I, 0, LastI)
                #for (L, 0, LastL)
                    #for (K, 0, LastK - 1)
                        Cylinder_2D(
                            Points_4N2D[I][J][K  ][L],
                            Points_4N2D[I][J][K+1][L],
                            RadiusK
                        )
                    #end // for
                #end // for
            #end // for
        #end // for
    #end // if
    #if (RadiusL > 0.0)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI)
                    #for (L, 0, LastL - 1)
                        Cylinder_2D(
                            Points_4N2D[I][J][K][L  ],
                            Points_4N2D[I][J][K][L+1],
                            RadiusL
                        )
                    #end // for
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_4N_ShowLines_2D


#macro ShowLines_2D(Points_2D, Radii)

    #local N = dimensions(Points_2D);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if
    #if (dimensions(Radii) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radii, 1) != N)
        #error "Is not equal to N"
    #end // if

    #switch (N)
        #case (1)  // 1N
            From_1N_ShowLines_2D(
                Points_2D, Radii
            )
            #break
        #case (2)  // 2N
            From_2N_ShowLines_2D(
                Points_2D, Radii
            )
            #break
        #case (3)  // 3N
            From_3N_ShowLines_2D(
                Points_2D, Radii
            )
            #break
        #case (4)  // 4N
            From_4N_ShowLines_2D(
                Points_2D, Radii
            )
            #break
        #else
            #error "!"
    #end // switch

#end // macro ShowLines_2D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= 10

#macro From_1N_ShowLines_3D(Points_1N3D, Radius_I)

    #local N = dimensions(Points_1N3D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Radius_I) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_I, 1) != 1)
        #error "Is not 1"
    #end // if
    #local SizeI = dimension_size(Points_1N3D, 1);
    #local RadiusI = I_E(Radius_I);
    #local LastI = SizeI - 1;

    #if (RadiusI > 0.0)
        #for (I, 0, LastI - 1)
            Cylinder_3D(
                Points_1N3D[I  ],
                Points_1N3D[I+1],
                RadiusI
            )
        #end // for
    #end // if

#end // macro From_1N_ShowLines_3D


#macro From_2N_ShowLines_3D(Points_2N3D, Radius_IJ)

    #local N = dimensions(Points_2N3D);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Radius_IJ) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJ, 1) != 2)
        #error "Is not 2"
    #end // if
    #local SizeI = dimension_size(Points_2N3D, 1);
    #local SizeJ = dimension_size(Points_2N3D, 2);
    #local RadiusI = I_E(Radius_IJ);
    #local RadiusJ = J_E(Radius_IJ);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;

    #if (RadiusI > 0.0)
        #for (J, 0, LastJ)
            #for (I, 0, LastI - 1)
                Cylinder_3D(
                    Points_2N3D[I  ][J],
                    Points_2N3D[I+1][J],
                    RadiusI
                )
            #end // for
        #end // for
    #end // if
    #if (RadiusJ > 0.0)
        #for (I, 0, LastI)
            #for (J, 0, LastJ - 1)
                Cylinder_3D(
                    Points_2N3D[I][J  ],
                    Points_2N3D[I][J+1],
                    RadiusJ
                )
            #end // for
        #end // for
    #end // if

#end // macro From_2N_ShowLines_3D


#macro From_3N_ShowLines_3D(Points_3N3D, Radius_IJK)

    #local N = dimensions(Points_3N3D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Radius_IJK) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJK, 1) != 3)
        #error "Is not 3"
    #end // if
    #local SizeI = dimension_size(Points_3N3D, 1);
    #local SizeJ = dimension_size(Points_3N3D, 2);
    #local SizeK = dimension_size(Points_3N3D, 3);
    #local RadiusI = I_E(Radius_IJK);
    #local RadiusJ = J_E(Radius_IJK);
    #local RadiusK = K_E(Radius_IJK);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;

    #if (RadiusI > 0.0)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI - 1)
                    Cylinder_3D(
                        Points_3N3D[I  ][J][K],
                        Points_3N3D[I+1][J][K],
                        RadiusI
                    )
                #end // for
            #end // for
        #end // for
    #end // if
    #if (RadiusJ > 0.0)
        #for (I, 0, LastI)
            #for (K, 0, LastK)
                #for (J, 0, LastJ - 1)
                    Cylinder_3D(
                        Points_3N3D[I][J  ][K],
                        Points_3N3D[I][J+1][K],
                        RadiusJ
                    )
                #end // for
            #end // for
        #end // for
    #end // if
    #if (RadiusK > 0.0)
        #for (J, 0, LastJ)
            #for (I, 0, LastI)
                #for (K, 0, LastK - 1)
                    Cylinder_3D(
                        Points_3N3D[I][J][K  ],
                        Points_3N3D[I][J][K+1],
                        RadiusK
                    )
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_3N_ShowLines_3D


#macro From_4N_ShowLines_3D(Points_4N3D, Radius_IJKL)

    #local N = dimensions(Points_4N3D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Radius_IJKL) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJKL, 1) != 4)
        #error "Is not 4"
    #end // if
    #local SizeI = dimension_size(Points_4N3D, 1);
    #local SizeJ = dimension_size(Points_4N3D, 2);
    #local SizeK = dimension_size(Points_4N3D, 3);
    #local SizeL = dimension_size(Points_4N3D, 4);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local LastL = SizeL - 1;
    #local RadiusI = I_E(Radius_IJKL);
    #local RadiusJ = J_E(Radius_IJKL);
    #local RadiusK = K_E(Radius_IJKL);
    #local RadiusL = L_E(Radius_IJKL);

    #if (RadiusI > 0.0)
        #for (L, 0, LastL)
            #for (K, 0, LastK)
                #for (J, 0, LastJ)
                    #for (I, 0, LastI - 1)
                        Cylinder_3D(
                            Points_4N3D[I  ][J][K][L],
                            Points_4N3D[I+1][J][K][L],
                            RadiusI
                        )
                    #end // for
                #end // for
            #end // for
        #end // for
    #end // if
    #if (RadiusJ > 0.0)
        #for (I, 0, LastI)
            #for (L, 0, LastL)
                #for (K, 0, LastK)
                    #for (J, 0, LastJ - 1)
                        Cylinder_3D(
                            Points_4N3D[I][J  ][K][L],
                            Points_4N3D[I][J+1][K][L],
                            RadiusJ
                        )
                    #end // for
                #end // for
            #end // for
        #end // for
    #end // if
    #if (RadiusK > 0.0)
        #for (J, 0, LastJ)
            #for (I, 0, LastI)
                #for (L, 0, LastL)
                    #for (K, 0, LastK - 1)
                        Cylinder_3D(
                            Points_4N3D[I][J][K  ][L],
                            Points_4N3D[I][J][K+1][L],
                            RadiusK
                        )
                    #end // for
                #end // for
            #end // for
        #end // for
    #end // if
    #if (RadiusL > 0.0)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI)
                    #for (L, 0, LastL - 1)
                        Cylinder_3D(
                            Points_4N3D[I][J][K][L  ],
                            Points_4N3D[I][J][K][L+1],
                            RadiusL
                        )
                    #end // for
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_4N_ShowLines_3D


#macro ShowLines_3D(Points_3D, Radii)

    #local N = dimensions(Points_3D);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if
    #if (dimensions(Radii) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radii, 1) != N)
        #error "Is not equal to N"
    #end // if

    #switch (N)
        #case (1)  // 1N
            From_1N_ShowLines_3D(
                Points_3D, Radii
             )
            #break
        #case (2)  // 2N
            From_2N_ShowLines_3D(
                Points_3D, Radii
            )
            #break
        #case (3)  // 3N
            From_3N_ShowLines_3D(
                Points_3D, Radii
            )
            #break
        #case (4)  // 4N
            From_4N_ShowLines_3D(
                Points_3D, Radii
            )
            #break
        #else
            #error "!"
    #end // switch

#end // macro ShowLines_3D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_1N_ShowGrid_2D(Points_1N2D, Radius)

    #local N = dimensions(Points_1N2D);
    #if (N != 1)
        #error "N is not 1"
    #end // if

    From_1N_ShowPoints_2D(
        Points_1N2D, Radius
    )
    From_1N_ShowLines_2D(
        Points_1N2D, Arr_1E(Radius)
    )

#end // macro From_1N_ShowGrid_2D


#macro From_2N_ShowGrid_2D(Points_2N2D, Radius)

    #local N = dimensions(Points_2N2D);
    #if (N != 2)
        #error "N is not 2"
    #end // if

    From_2N_ShowPoints_2D(
        Points_2N2D, Radius
     )
    From_2N_ShowLines_2D(
        Points_2N2D, Arr_2E(Radius, Radius)
    )

#end // macro From_2N_ShowGrid_2D


#macro From_3N_ShowGrid_2D(Points_3N2D, Radius)

    #local N = dimensions(Points_3N2D);
    #if (N != 3)
        #error "N is not 3"
    #end // if

    From_3N_ShowPoints_2D(
        Points_3N2D, Radius
     )
    From_3N_ShowLines_2D(
        Points_3N2D, Arr_3E(Radius, Radius, Radius)
    )

#end // macro From_3N_ShowGrid_2D


#macro From_4N_ShowGrid_2D(Points_4N2D, Radius)

    #local N = dimensions(Points_4N2D);
    #if (N != 4)
        #error "N is not 4"
    #end // if

    From_4N_ShowPoints_2D(
        Points_4N2D, Radius
     )
    From_4N_ShowLines_2D(
        Points_4N2D, Arr_4E(Radius, Radius, Radius, Radius)
     )

#end // macro From_4N_ShowGrid_2D


#macro ShowGrid_2D(Points_2D, Radius)

    #local N = dimensions(Points_2D);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if

    #switch (N)
        #case (1)  // 1N
            From_1N_ShowGrid_2D(
                Points_2D, Radius
            )
            #break
        #case (2)  // 2N
            From_2N_ShowGrid_2D(
                Points_2D, Radius
            )
            #break
        #case (3)  // 3N
            From_3N_ShowGrid_2D(
                Points_2D, Radius
            )
            #break
        #case (4)  // 4N
            From_4N_ShowGrid_2D(
                Points_2D, Radius
            )
            #break
        #else
            #error "!"
    #end // switch

#end // macro ShowGrid_2D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_1N_ShowGrid_3D(Points_1N3D, Radius)

    #local N = dimensions(Points_1N3D);
    #if (N != 1)
        #error "N is not 1"
    #end // if

    From_1N_ShowPoints_3D(
        Points_1N3D, Radius
    )
    From_1N_ShowLines_3D(
        Points_1N3D, Arr_1E(Radius)
    )

#end // macro From_1N_ShowGrid_3D


#macro From_2N_ShowGrid_3D(Points_2N3D, Radius)

    #local N = dimensions(Points_2N3D);
    #if (N != 2)
        #error "N is not 2"
    #end // if

    From_2N_ShowPoints_3D(
        Points_2N3D, Radius
    )
    From_2N_ShowLines_3D(
        Points_2N3D, Arr_2E(Radius, Radius)
    )

#end // macro From_2N_ShowGrid_3D


#macro From_3N_ShowGrid_3D(Points_3N3D, Radius)

    #local N = dimensions(Points_3N3D);
    #if (N != 3)
        #error "N is not 3"
    #end // if

    From_3N_ShowPoints_3D(
        Points_3N3D, Radius
    )
    From_3N_ShowLines_3D(
        Points_3N3D, Arr_3E(Radius, Radius, Radius)
    )

#end // macro From_3N_ShowGrid_3D


#macro From_4N_ShowGrid_3D(Points_4N3D, Radius)

    #local N = dimensions(Points_4N3D);
    #if (N != 4)
        #error "N is not 4"
    #end // if

    From_4N_ShowPoints_3D(
        Points_4N3D, Radius
    )
    From_4N_ShowLines_3D(
        Points_4N3D, Arr_4E(Radius, Radius, Radius, Radius)
    )

#end // macro From_4N_ShowGrid_3D


#macro ShowGrid_3D(Points_3D, Radius)

    #local N = dimensions(Points_3D);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if

    #switch (N)
        #case (1)  // 1N
            From_1N_ShowGrid_3D(
                Points_3D, Radius
            )
            #break
        #case (2)  // 2N
            From_2N_ShowGrid_3D(
                Points_3D, Radius
            )
            #break
        #case (3)  // 3N
            From_3N_ShowGrid_3D(
                Points_3D, Radius
            )
            #break
        #case (4)  // 4N
            From_4N_ShowGrid_3D(
                Points_3D, Radius
            )
            #break
        #else
            #error "!"
    #end // switch

#end // macro ShowGrid_3D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_1A_ShowFunctions_2D(_Functions_2D1A, Min_U, Max_U, Res_U, Radius_U)

    #local M =
        max(
            dimensions(_Functions_2D1A),
            dimensions(Min_U),
            dimensions(Max_U),
            dimensions(Res_U),
            dimensions(Radius_U)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_2D1A, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if
    #if (dimension_size(Min_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Max_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Res_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #local MinU = u_E(Min_U);
    #local MaxU = u_E(Max_U);
    #local ResU = u_E(Res_U);
    #local RadiusU = u_E(Radius_U);
    #local IntervalsU = ResU - 1;
    #if (IntervalsU = 0)
        #local dU = 0.0;
    #else
        #local dU = (MaxU - MinU)/IntervalsU;
    #end // if

    #if (RadiusU > 0.0)
        #local U = MinU;
        #local p0 =
            <
                x_E(_Functions_2D1A)(U),
                y_E(_Functions_2D1A)(U)
            >
        ;
        Sphere_2D(p0, RadiusU)
        #if (dU > 0.0)
            #for (I, 1, IntervalsU)
                #local U = U + dU;
                #local p1 =
                    <
                        x_E(_Functions_2D1A)(U),
                        y_E(_Functions_2D1A)(U)
                    >
                ;
                Cylinder_2D(p0, p1, RadiusU)
                Sphere_2D(p1, RadiusU)
                #local p0 = p1;
            #end // for
        #end // if
    #end // if

#end // macro From_1A_ShowFunctions_2D


#macro From_2A_ShowFunctions_2D(_Functions_2D2A, Min_UV, Max_UV, Div_UV, Res_UV, Radius_UV)

    #local M =
        max(
            dimensions(_Functions_2D2A),
            dimensions(Min_UV),
            dimensions(Max_UV),
            dimensions(Div_UV),
            dimensions(Res_UV),
            dimensions(Radius_UV)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_2D2A, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if
    #if (dimension_size(Min_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Max_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Div_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Res_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Radius_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #local MinU = u_E(Min_UV);
    #local MinV = v_E(Min_UV);
    #local MaxU = u_E(Max_UV);
    #local MaxV = v_E(Max_UV);
    #local DivU = u_E(Div_UV);
    #local DivV = v_E(Div_UV);
    #local ResU = u_E(Res_UV);
    #local ResV = v_E(Res_UV);
    #local RadiusU = u_E(Radius_UV);
    #local RadiusV = v_E(Radius_UV);
    #if (DivU = 0)
        #local dU = 0.0;
    #else
        #local dU = (MaxU - MinU)/DivU;
    #end // if
    #if (DivV = 0)
        #local dV = 0.0;
    #else
        #local dV = (MaxV - MinV)/DivV;
    #end // if
    #local NoI = 1 + select(dU, DivU, 0, DivU);
    #local NoJ = 1 + select(dV, DivV, 0, DivV);

    #if (RadiusU > 0.0)
        #local V = MinV;
        #for (J, 1, NoJ)
            From_1A_ShowFunctions_2D(
                Arr_2E(
                    function(_u) { x_E(_Functions_2D2A)(_u, V) },
                    function(_u) { y_E(_Functions_2D2A)(_u, V) }
                ),
                Arr_1E(MinU),
                Arr_1E(MaxU),
                Arr_1E(ResU),
                Arr_1E(RadiusU)
            )
            #local V = V + dV;
        #end // if
    #end // if
    #if (RadiusV > 0.0)
        #local U = MinU;
        #for (I, 1, NoI)
            From_1A_ShowFunctions_2D(
                Arr_2E(
                    function(_v) { x_E(_Functions_2D2A)(U, _v) },
                    function(_v) { y_E(_Functions_2D2A)(U, _v) }
                ),
                Arr_1E(MinV),
                Arr_1E(MaxV),
                Arr_1E(ResV),
                Arr_1E(RadiusV)
            )
            #local U = U + dU;
        #end // for
    #end // if

#end // macro From_2A_ShowFunctions_2D


#macro From_3A_ShowFunctions_2D(_Functions_2D3A, Min_UVW, Max_UVW, Div_UVW, Res_UVW, Radius_UVW)

    #local M =
        max(
            dimensions(_Functions_2D3A),
            dimensions(Min_UVW),
            dimensions(Max_UVW),
            dimensions(Div_UVW),
            dimensions(Res_UVW),
            dimensions(Radius_UVW)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_2D3A, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if
    #if (dimension_size(Min_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Max_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Div_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Res_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Radius_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #local MinU = u_E(Min_UVW);
    #local MinV = v_E(Min_UVW);
    #local MinW = w_E(Min_UVW);
    #local MaxU = u_E(Max_UVW);
    #local MaxV = v_E(Max_UVW);
    #local MaxW = w_E(Max_UVW);
    #local DivU = u_E(Div_UVW);
    #local DivV = v_E(Div_UVW);
    #local DivW = w_E(Div_UVW);
    #local ResU = u_E(Res_UVW);
    #local ResV = v_E(Res_UVW);
    #local ResW = w_E(Res_UVW);
    #local RadiusU = u_E(Radius_UVW);
    #local RadiusV = v_E(Radius_UVW);
    #local RadiusW = w_E(Radius_UVW);
    #if (DivU = 0)
        #local dU = 0.0;
    #else
        #local dU = (MaxU - MinU)/DivU;
    #end // if
    #if (DivV = 0)
        #local dV = 0.0;
    #else
        #local dV = (MaxV - MinV)/DivV;
    #end // if
    #if (DivW = 0)
        #local dW = 0.0;
    #else
        #local dW = (MaxW - MinW)/DivW;
    #end // if
    #local NoI = 1 + select(dU, DivU, 0, DivU);
    #local NoJ = 1 + select(dV, DivV, 0, DivV);
    #local NoK = 1 + select(dW, DivW, 0, DivW);

    #if (Radius_U > 0.0)
        #local W = MinW;
        #for (K, 1, NoK)
            #local V = MinV;
            #while (J, 1, NoJ)
                From_1A_ShowFunctions_2D(
                    Arr_2E(
                        function(_u) { x_E(_Functions_2D3A)(_u, V, W) },
                        function(_u) { y_E(_Functions_2D3A)(_u, V, W) }
                    ),
                    Arr_1E(MinU),
                    Arr_1E(MaxU),
                    Arr_1E(ResU),
                    Arr_1E(RadiusU)
                )
                #local V = V + dV;
            #end // for
            #local W = W + dW;
        #end // for
    #end // if
    #if (RadiusV > 0.0)
        #local U = MinU;
        #for (I, 1, NoI)
            #local W = MinW;
            #for (K, 1, NoK)
                From_1A_ShowFunctions_2D(
                    Arr_2E(
                        function(_v) { x_E(_Functions_2D3A)(U, _v, W) },
                        function(_v) { y_E(_Functions_2D3A)(U, _v, W) }
                    ),
                    Arr_1E(MinV),
                    Arr_1E(MaxV),
                    Arr_1E(ResV),
                    Arr_1E(RadiusV)
                )
                #local W = W + dW;
            #end // for
            #local U = U + dU;
        #end // for
    #end // if
    #if (RadiusW > 0.0)
        #local V = MinV;
        #while (J, 1, NoJ)
            #local U = MinU;
            #for (I, 1, NoI)
                From_1A_ShowFunctions_2D(
                    Arr_2E(
                        function(_w) { x_E(_Functions_2D3A)(U, V, _w) },
                        function(_w) { y_E(_Functions_2D3A)(U, V, _w) }
                    ),
                    Arr_1E(MinW),
                    Arr_1E(MaxW),
                    Arr_1E(ResW),
                    Arr_1E(RadiusW)
                )
                #local U = U + dU;
            #end // for
            #local V = V + dV;
        #end // for
    #end // if

#end // macro From_3A_ShowFunctions_2D


#macro From_4A_ShowFunctions_2D(_Functions_2D4A, Min_UVWS, Max_UVWS, Div_UVWS, Res_UVWS, Radius_UVWS)

    #local M =
        max(
            dimensions(_Functions_2D4A),
            dimensions(Min_UVWS),
            dimensions(Max_UVWS),
            dimensions(Div_UVWS),
            dimensions(Res_UVWS),
            dimensions(Radius_UVWS)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_2D4A, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if
    #if (dimension_size(Min_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Max_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Div_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Res_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Radius_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #local MinU = u_E(Min_UVWS);
    #local MinV = v_E(Min_UVWS);
    #local MinW = w_E(Min_UVWS);
    #local MinS = s_E(Min_UVWS);
    #local MaxU = u_E(Max_UVWS);
    #local MaxV = v_E(Max_UVWS);
    #local MaxW = w_E(Max_UVWS);
    #local MaxS = s_E(Max_UVWS);
    #local DivU = u_E(Div_UVWS);
    #local DivV = v_E(Div_UVWS);
    #local DivW = w_E(Div_UVWS);
    #local DivS = s_E(Div_UVWS);
    #local ResU = u_E(Res_UVWS);
    #local ResV = v_E(Res_UVWS);
    #local ResW = w_E(Res_UVWS);
    #local ResS = s_E(Res_UVWS);
    #local RadiusU = u_E(Radius_UVWS);
    #local RadiusV = v_E(Radius_UVWS);
    #local RadiusW = w_E(Radius_UVWS);
    #local RadiusS = s_E(Radius_UVWS);
    #if (DivU = 0)
        #local dU = 0.0;
    #else
        #local dU = (MaxU - MinU)/DivU;
    #end // if
    #if (DivV = 0)
        #local dV = 0.0;
    #else
        #local dV = (MaxV - MinV)/DivV;
    #end // if
    #if (DivW = 0)
        #local dW = 0.0;
    #else
        #local dW = (MaxW - MinW)/DivW;
    #end // if
    #if (DivS = 0)
        #local dS = 0.0;
    #else
        #local dS = (MaxS - MinS)/DivS;
    #end // if
    #local NoI = 1 + select(dU, DivU, 0, DivU);
    #local NoJ = 1 + select(dV, DivV, 0, DivV);
    #local NoK = 1 + select(dW, DivW, 0, DivW);
    #local NoL = 1 + select(dS, DivS, 0, DivS);

    #if (RadiusU > 0.0)
        #local S = MinS;
        #for (L, 1, NoL)
            #local W = MinW;
            #for (K, 1, NoK)
                #local V = MinV;
                #for (J, 1, NoJ)
                    From_1A_ShowFunctions_2D(
                        Arr_2E(
                            function(_u) { x_E(_Functions_2D4A)(_u, V, W, S) },
                            function(_u) { y_E(_Functions_2D4A)(_u, V, W, S) }
                        ),
                        Arr_1E(MinU),
                        Arr_1E(MaxU),
                        Arr_1E(ResU),
                        Arr_1E(RadiusU)
                    )
                    #local V = V + dV;
                #end // for
                #local W = W + dW;
            #end // for
            #local S = S + dS;
        #end // for
    #end // if
    #if (RadiusV > 0.0)
        #local U = MinU;
        #for (I, 1, NoI)
            #local S = MinS;
            #for (L, 1, NoL)
                #local W = MinW;
                #for (K, 1, NoK)
                    From_1A_ShowFunctions_2D(
                        Arr_2E(
                            function(_v) { x_E(_Functions_2D4A)(U, _v, W, S) },
                            function(_v) { y_E(_Functions_2D4A)(U, _v, W, S) }
                        ),
                        Arr_1E(MinV),
                        Arr_1E(MaxV),
                        Arr_1E(ResV),
                        Arr_1E(RadiusV)
                    )
                    #local W = W + dW;
                #end // for
                #local S = S + dS;
            #end // for
            #local U = U + dU;
        #end // for
    #end // if
    #if (RadiusW > 0.0)
        #local V = MinV;
        #for (J, 1, NoJ)
            #local U = MinU;
            #for (I, 1, NoI)
                #local S = MinS;
                #for (L, 1, NoL)
                    From_1A_ShowFunctions_2D(
                        Arr_2E(
                            function(_w) { x_E(_Functions_2D4A)(U, V, _w, S) },
                            function(_w) { y_E(_Functions_2D4A)(U, V, _w, S) }
                        ),
                        Arr_1E(MinW),
                        Arr_1E(MaxW),
                        Arr_1E(ResW),
                        Arr_1E(RadiusW)
                    )
                    #local S = S + dS;
                #end // for
                #local U = U + dU;
            #end // for
            #local V = V + dV;
        #end // for
    #end // if
    #if (RadiusS > 0.0)
        #local W = MinW;
        #for (K, 1, NoK)
            #local V = MinV;
            #for (J, 1, NoJ)
                #local U = MinU;
                #for (I, 1, NoI)
                    From_1A_ShowFunctions_2D(
                        Arr_2E(
                            function(_s) { x_E(_Functions_2D4A)(U, V, W, _s) },
                            function(_s) { y_E(_Functions_2D4A)(U, V, W, _s) }
                        ),
                        Arr_1E(MinS),
                        Arr_1E(MaxS),
                        Arr_1E(ResS),
                        Arr_1E(RadiusS)
                    )
                    #local U = U + dU;
                #end // for
                #local V = V + dV;
            #end // for
            #local W = W + dW;
        #end // for
    #end // if

#end // macro From_4A_ShowFunctions_2D


#macro ShowFunctions_2D(_Functions_2D, Min, Max, Div, Res, Radius)

    #local M =
        max(
            dimensions(_Functions_2D),
            dimensions(Min),
            dimensions(Max),
            dimensions(Div),
            dimensions(Res),
            dimensions(Radius)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_2D, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if
    #local Amin =
        min(
            dimension_size(Min, 1),
            dimension_size(Max, 1),
            dimension_size(Div, 1),
            dimension_size(Res, 1),
            dimension_size(Radius, 1)
        )
    ;
    #local Amax =
        max(
            dimension_size(Min, 1),
            dimension_size(Max, 1),
            dimension_size(Div, 1),
            dimension_size(Res, 1),
            dimension_size(Radius, 1)
        )
    ;
    #if (Amin != Amax)
        #error "Amin and Amax are not equal"
    #end // if
    #local A = Amin;
    #if (!((A = 1) | (A = 2) | (A = 3) | (A = 4)))
        #error "A is neither 1, 2, 3 nor 4"
    #end // if
    #switch (A)
        #case (1)  // 1A
            From_1A_ShowFunctions_2D(
                _Functions_2D, Min, Max, Res, Radius
            )
            #break
        #case (2)  // 2A
            From_2A_ShowFunctions_2D(
                _Functions_2D, Min, Max, Div, Res, Radius
            )
            #break
        #case (3)  // 3A
            From_3A_ShowFunctions_2D(
                _Functions_2D, Min, Max, Div, Res, Radius
            )
            #break
        #case (4)  // 4A
            From_4A_ShowFunctions_2D(
                _Functions_2D, Min, Max, Div, Res, Radius
            )
            #break
        #else
            #error "!"
    #end // switch

#end // macro ShowFunctions_2D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_1A_ShowFunctions_3D(_Functions_3D1A, Min_U, Max_U, Res_U, Radius_U)

    #local M =
        max(
            dimensions(_Functions_3D1A),
            dimensions(Min_U),
            dimensions(Max_U),
            dimensions(Res_U),
            dimensions(Radius_U)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_3D1A, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if
    #if (dimension_size(Min_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Max_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Res_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #local MinU = u_E(Min_U);
    #local MaxU = u_E(Max_U);
    #local ResU = u_E(Res_U);
    #local RadiusU = u_E(Radius_U);
    #local IntervalsU = ResU - 1;
    #if (IntervalsU = 0)
        #local dU = 0.0;
    #else
        #local dU = (MaxU - MinU)/IntervalsU;
    #end // if

    #if (RadiusU > 0.0)
        #local U = MinU;
        #local p0 =
            <
                x_E(_Functions_3D1A)(U),
                y_E(_Functions_3D1A)(U),
                z_E(_Functions_3D1A)(U)
            >
        ;
        sphere { p0, RadiusU }
        #if (dU > 0.0)
            #for (I, 1, IntervalsU)
                #local U = U + dU;
                #local p1 =
                    <
                        x_E(_Functions_3D1A)(U),
                        y_E(_Functions_3D1A)(U),
                        z_E(_Functions_3D1A)(U)
                    >
                ;
                Cylinder_3D(p0, p1, RadiusU)
                sphere { p1, RadiusU }
                #local p0 = p1;
            #end // for
        #end // if
    #end // if

#end // macro From_1A_ShowFunctions_3D


#macro From_2A_ShowFunctions_3D(_Functions_3D2A, Min_UV, Max_UV, Div_UV, Res_UV, Radius_UV)

    #local M =
        max(
            dimensions(_Functions_3D2A),
            dimensions(Min_UV),
            dimensions(Max_UV),
            dimensions(Div_UV),
            dimensions(Res_UV),
            dimensions(Radius_UV)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_3D2A, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if
    #if (dimension_size(Min_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Max_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Div_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Res_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Radius_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #local MinU = u_E(Min_UV);
    #local MinV = v_E(Min_UV);
    #local MaxU = u_E(Max_UV);
    #local MaxV = v_E(Max_UV);
    #local DivU = u_E(Div_UV);
    #local DivV = v_E(Div_UV);
    #local ResU = u_E(Res_UV);
    #local ResV = v_E(Res_UV);
    #local RadiusU = u_E(Radius_UV);
    #local RadiusV = v_E(Radius_UV);
    #if (DivU = 0)
        #local dU = 0.0;
    #else
        #local dU = (MaxU - MinU)/DivU;
    #end // if
    #if (DivV = 0)
        #local dV = 0.0;
    #else
        #local dV = (MaxV - MinV)/DivV;
    #end // if
    #local NoI = 1 + select(dU, DivU, 0, DivU);
    #local NoJ = 1 + select(dV, DivV, 0, DivV);

    #if (RadiusU > 0.0)
        #local V = MinV;
        #for (J, 1, NoJ)
            From_1A_ShowFunctions_3D(
                Arr_3E(
                    function(_u) { x_E(_Functions_3D2A)(_u, V) },
                    function(_u) { y_E(_Functions_3D2A)(_u, V) },
                    function(_u) { z_E(_Functions_3D2A)(_u, V) }
                ),
                Arr_1E(MinU),
                Arr_1E(MaxU),
                Arr_1E(ResU),
                Arr_1E(RadiusU)
            )
            #local V = V + dV;
        #end // if
    #end // if
    #if (RadiusV > 0.0)
        #local U = MinU;
        #for (I, 1, NoI)
            From_1A_ShowFunctions_3D(
                Arr_3E(
                    function(_v) { x_E(_Functions_3D2A)(U, _v) },
                    function(_v) { y_E(_Functions_3D2A)(U, _v) },
                    function(_v) { z_E(_Functions_3D2A)(U, _v) }
                ),
                Arr_1E(MinV),
                Arr_1E(MaxV),
                Arr_1E(ResV),
                Arr_1E(RadiusV)
            )
            #local U = U + dU;
        #end // for
    #end // for

#end // macro From_2A_ShowFunctions_3D


#macro From_3A_ShowFunctions_3D(_Functions_3D3A, Min_UVW, Max_UVW, Div_UVW, Res_UVW, Radius_UVW)

    #local M =
        max(
            dimensions(_Functions_3D3A),
            dimensions(Min_UVW),
            dimensions(Max_UVW),
            dimensions(Div_UVW),
            dimensions(Res_UVW),
            dimensions(Radius_UVW)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_3D3A, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if
    #if (dimension_size(Min_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Max_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Div_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Res_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Radius_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #local MinU = u_E(Min_UVW);
    #local MinV = v_E(Min_UVW);
    #local MinW = w_E(Min_UVW);
    #local MaxU = u_E(Max_UVW);
    #local MaxV = v_E(Max_UVW);
    #local MaxW = w_E(Max_UVW);
    #local DivU = u_E(Div_UVW);
    #local DivV = v_E(Div_UVW);
    #local DivW = w_E(Div_UVW);
    #local ResU = u_E(Res_UVW);
    #local ResV = v_E(Res_UVW);
    #local ResW = w_E(Res_UVW);
    #local RadiusU = u_E(Radius_UVW);
    #local RadiusV = v_E(Radius_UVW);
    #local RadiusW = w_E(Radius_UVW);
    #if (DivU = 0)
        #local dU = 0.0;
    #else
        #local dU = (MaxU - MinU)/DivU;
    #end // if
    #if (DivV = 0)
        #local dV = 0.0;
    #else
        #local dV = (MaxV - MinV)/DivV;
    #end // if
    #if (DivW = 0)
        #local dW = 0.0;
    #else
        #local dW = (MaxW - MinW)/DivW;
    #end // if
    #local NoI = 1 + select(dU, DivU, 0, DivU);
    #local NoJ = 1 + select(dV, DivV, 0, DivV);
    #local NoK = 1 + select(dW, DivW, 0, DivW);

    #if (RadiusU > 0.0)
        #local W = MinW;
        #for (K, 1, NoK)
            #local V = MinV;
            #for (J, 1, NoJ)
                From_1A_ShowFunctions_3D(
                    Arr_3E(
                        function(_u) { x_E(_Functions_3D3A)(_u, V, W) },
                        function(_u) { y_E(_Functions_3D3A)(_u, V, W) },
                        function(_u) { z_E(_Functions_3D3A)(_u, V, W) }
                    ),
                    Arr_1E(MinU),
                    Arr_1E(MaxU),
                    Arr_1E(ResU),
                    Arr_1E(RadiusU)
                )
                #local V = V + dV;
            #end // for
            #local W = W + dW;
        #end // for
    #end // if
    #if (RadiusV > 0.0)
        #local U = MinU;
        #for (I, 1, NoI)
            #local W = MinW;
            #for (K, 1, NoK)
                From_1A_ShowFunctions_3D(
                    Arr_3E(
                        function(_v) { x_E(_Functions_3D3A)(U, _v, W) },
                        function(_v) { y_E(_Functions_3D3A)(U, _v, W) },
                        function(_v) { z_E(_Functions_3D3A)(U, _v, W) }
                    ),
                    Arr_1E(MinV),
                    Arr_1E(MaxV),
                    Arr_1E(ResV),
                    Arr_1E(RadiusV)
                )
                #local W = W + dW;
            #end // for
            #local U = U + dU;
        #end // for
    #end // if
    #if (RadiusW > 0.0)
        #local V = MinV;
        #for (J, 1, NoJ)
            #local U = MinU;
            #for (I, 1, NoI)
                From_1A_ShowFunctions_3D(
                    Arr_3E(
                        function(_w) { x_E(_Functions_3D3A)(U, V, _w) },
                        function(_w) { y_E(_Functions_3D3A)(U, V, _w) },
                        function(_w) { z_E(_Functions_3D3A)(U, V, _w) }
                    ),
                    Arr_1E(MinW),
                    Arr_1E(MaxW),
                    Arr_1E(ResW),
                    Arr_1E(RadiusW)
                )
                #local U = U + dU;
            #end // for
            #local V = V + dV;
        #end // for
    #end // if

#end // macro From_3A_ShowFunctions_3D


#macro From_4A_ShowFunctions_3D(_Functions_3D4A, Min_UVWS, Max_UVWS, Div_UVWS, Res_UVWS, Radius_UVWS)

    #local M =
        max(
            dimensions(_Functions_3D4A),
            dimensions(Min_UVWS),
            dimensions(Max_UVWS),
            dimensions(Div_UVWS),
            dimensions(Res_UVWS),
            dimensions(Radius_UVWS)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_3D4A, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if
    #if (dimension_size(Min_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Max_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Div_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Res_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Radius_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #local MinU = u_E(Min_UVWS);
    #local MinV = v_E(Min_UVWS);
    #local MinW = w_E(Min_UVWS);
    #local MinS = s_E(Min_UVWS);
    #local MaxU = u_E(Max_UVWS);
    #local MaxV = v_E(Max_UVWS);
    #local MaxW = w_E(Max_UVWS);
    #local MaxS = s_E(Max_UVWS);
    #local DivU = u_E(Div_UVWS);
    #local DivV = v_E(Div_UVWS);
    #local DivW = w_E(Div_UVWS);
    #local DivS = s_E(Div_UVWS);
    #local ResU = u_E(Res_UVWS);
    #local ResV = v_E(Res_UVWS);
    #local ResW = w_E(Res_UVWS);
    #local ResS = s_E(Res_UVWS);
    #local RadiusU = u_E(Radius_UVWS);
    #local RadiusV = v_E(Radius_UVWS);
    #local RadiusW = w_E(Radius_UVWS);
    #local RadiusS = s_E(Radius_UVWS);
    #if (DivU = 0)
        #local dU = 0.0;
    #else
        #local dU = (MaxU - MinU)/DivU;
    #end // if
    #if (DivV = 0)
        #local dV = 0.0;
    #else
        #local dV = (MaxV - MinV)/DivV;
    #end // if
    #if (DivW = 0)
        #local dW = 0.0;
    #else
        #local dW = (MaxW - MinW)/DivW;
    #end // if
    #if (DivS = 0)
        #local dS = 0.0;
    #else
        #local dS = (MaxS - MinS)/DivS;
    #end // if
    #local NoI = 1 + select(dU, DivU, 0, DivU);
    #local NoJ = 1 + select(dV, DivV, 0, DivV);
    #local NoK = 1 + select(dW, DivW, 0, DivW);
    #local NoL = 1 + select(dS, DivS, 0, DivS);

    #if (RadiusU > 0.0)
        #local S = MinS;
        #for (L, 1, NoL)
            #local W = MinW;
            #for (K, 1, NoK)
                #local V = MinV;
                #for (J, 1, NoJ)
                    From_1A_ShowFunctions_3D(
                        Arr_3E(
                            function(_u) { x_E(_Functions_3D4A)(_u, V, W, S) },
                            function(_u) { y_E(_Functions_3D4A)(_u, V, W, S) },
                            function(_u) { z_E(_Functions_3D4A)(_u, V, W, S) }
                        ),
                        Arr_1E(MinU),
                        Arr_1E(MaxU),
                        Arr_1E(ResU),
                        Arr_1E(RadiusU)
                    )
                    #local V = V + dV;
                #end // for
                #local W = W + dW;
            #end // for
            #local S = S + dS;
        #end // for
    #end // if
    #if (RadiusV > 0.0)
        #local U = MinU;
        #for (I, 1, NoI)
            #local S = MinS;
            #for (L, 1, NoL)
                #local W = MinW;
                #for (K, 1, NoK)
                    From_1A_ShowFunctions_3D(
                        Arr_3E(
                            function(_v) { x_E(_Functions_3D4A)(U, _v, W, S) },
                            function(_v) { y_E(_Functions_3D4A)(U, _v, W, S) },
                            function(_v) { z_E(_Functions_3D4A)(U, _v, W, S) }
                        ),
                        Arr_1E(MinV),
                        Arr_1E(MaxV),
                        Arr_1E(ResV),
                        Arr_1E(RadiusV)
                    )
                    #local W = W + dW;
                #end // for
                #local S = S + dS;
            #end // for
            #local U = U + dU;
        #end // for
    #end // if
    #if (RadiusW > 0.0)
        #local V = MinV;
        #for (J, 1, NoJ)
            #local U = MinU;
            #for (I, 1, NoI)
                #local S = MinS;
                #for (L, 1, NoL)
                    From_1A_ShowFunctions_3D(
                        Arr_3E(
                            function(_w) { x_E(_Functions_3D4A)(U, V, _w, S) },
                            function(_w) { y_E(_Functions_3D4A)(U, V, _w, S) },
                            function(_w) { z_E(_Functions_3D4A)(U, V, _w, S) }
                        ),
                        Arr_1E(MinW),
                        Arr_1E(MaxW),
                        Arr_1E(ResW),
                        Arr_1E(RadiusW)
                    )
                    #local S = S + dS;
                #end // for
                #local U = U + dU;
            #end // for
            #local V = V + dV;
        #end // for
    #end // if
    #if (RadiusS > 0.0)
        #local W = MinW;
        #for (K, 1, NoK)
            #local V = MinV;
            #for (J, 1, NoJ)
                #local U = MinU;
                #for (I, 1, NoI)
                    From_1A_ShowFunctions_3D(
                        Arr_3E(
                            function(_s) { x_E(_Functions_3D4A)(U, V, W, _s) },
                            function(_s) { y_E(_Functions_3D4A)(U, V, W, _s) },
                            function(_s) { z_E(_Functions_3D4A)(U, V, W, _s) }
                        ),
                        Arr_1E(MinS),
                        Arr_1E(MaxS),
                        Arr_1E(ResS),
                        Arr_1E(RadiusS)
                    )
                    #local U = U + dU;
                #end // for
                #local V = V + dV;
            #end // for
            #local W = W + dW;
        #end // for
    #end // if

#end // macro From_4A_ShowFunctions_3D


#macro ShowFunctions_3D(_Functions_3D, Min, Max, Div, Res, Radius)

    #local M =
        max(
            dimensions(_Functions_3D),
            dimensions(Min),
            dimensions(Max),
            dimensions(Div),
            dimensions(Res),
            dimensions(Radius)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_3D, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if
    #local Amin =
        min(
            dimension_size(Min, 1),
            dimension_size(Max, 1),
            dimension_size(Div, 1),
            dimension_size(Res, 1),
            dimension_size(Radius, 1)
        )
    ;
    #local Amax =
        max(
            dimension_size(Min, 1),
            dimension_size(Max, 1),
            dimension_size(Div, 1),
            dimension_size(Res, 1),
            dimension_size(Radius, 1)
        )
    ;
    #if (Amin != Amax)
        #error "Amin and Amax are not equal"
    #end // if
    #local A = Amin;
    #if (!((A = 1) | (A = 2) | (A = 3) | (A = 4)))
        #error "A is neither 1, 2, 3 nor 4"
    #end // if
    #switch (A)
        #case (1)  // 1A
            From_1A_ShowFunctions_3D(
                _Functions_3D, Min, Max, Res, Radius
            )
            #break
        #case (2)  // 2A
            From_2A_ShowFunctions_3D(
                _Functions_3D, Min, Max, Div, Res, Radius
            )
            #break
        #case (3)  // 3A
            From_3A_ShowFunctions_3D(
                _Functions_3D, Min, Max, Div, Res, Radius
            )
            #break
        #case (4)  // 4A
            From_4A_ShowFunctions_3D(
                _Functions_3D, Min, Max, Div, Res, Radius
            )
            #break
        #else
            #error "!"
    #end // switch

#end // macro ShowFunctions_3D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro DrawPatch_3D(_Functions_3D2A, Min_UV, Max_UV, Div_UV)

    #local M =
        max(
            dimensions(_Functions_3D2A),
            dimensions(Min_UV),
            dimensions(Max_UV),
            dimensions(Div_UV)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_3D2A, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if
    #if (dimension_size(Min_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Max_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Div_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #local MinU = u_E(Min_UV);
    #local MinV = v_E(Min_UV);
    #local MaxU = u_E(Max_UV);
    #local MaxV = v_E(Max_UV);
    #local DivU = u_E(Div_UV);
    #local DivV = v_E(Div_UV);
    #local dU = (MaxU - MinU)/DivU;
    #local dV = (MaxV - MinV)/DivV;

    mesh {
        #local U0 = MinU;
        #for (I, 0, DivU - 1)
            #local U1 = U0 + dU;
            #local V0 = MinV;
            #for (J, 0, DivV - 1)
                #local V1 = V0 + dV;
                #local p00 =
                    <
                        x_E(_Functions_3D2A)(U0, V0),
                        y_E(_Functions_3D2A)(U0, V0),
                        z_E(_Functions_3D2A)(U0, V0)
                    >
                ;
                #local p10 =
                    <
                        x_E(_Functions_3D2A)(U1, V0),
                        y_E(_Functions_3D2A)(U1, V0),
                        z_E(_Functions_3D2A)(U1, V0)
                    >;
                #local p01 =
                    <
                        x_E(_Functions_3D2A)(U0, V1),
                        y_E(_Functions_3D2A)(U0, V1),
                        z_E(_Functions_3D2A)(U0, V1)
                    >
                ;
                #local p11 =
                    <
                        x_E(_Functions_3D2A)(U1, V1),
                        y_E(_Functions_3D2A)(U1, V1),
                        z_E(_Functions_3D2A)(U1, V1)
                    >
                ;
                triangle { p00, p10, p11 }
                triangle { p11, p01, p00 }
                #local V0 = V1;
            #end // for
            #local U0 = U1;
        #end // for
    }

#end // macro DrawPatch_3D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro UniformWeights_1N(DimensionsSizes_I, Constant)

    #if (dimensions(DimensionsSizes_I) != 1)
        #error "Is not 1"
    #end // if
    #local N = dimension_size(DimensionsSizes_I, 1);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = I_E(DimensionsSizes_I);
    #local LastI = SizeI - 1;
    #local WW1N = array[SizeI];
    #for (I, 0, LastI)
        #local WW1N[I] = Constant;
    #end // for

    WW1N

#end // macro UniformWeights_1N


#macro UniformWeights_2N(DimensionsSizes_IJ, Constant)

    #if (dimensions(DimensionsSizes_IJ) != 1)
        #error "Is not 1"
    #end // if
    #local N = dimension_size(DimensionsSizes_IJ, 1);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = I_E(DimensionsSizes_IJ);
    #local SizeJ = J_E(DimensionsSizes_IJ);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local WW2N = array[SizeI][SizeJ];
    #for (J, 0, LastJ)
        #for (I, 0, LastI)
            #local WW2N[I][J] = Constant;
        #end // for
    #end // for

    WW2N

#end // macro UniformWeights_2N


#macro UniformWeights_3N(DimensionsSizes_IJK, Constant)

    #if (dimensions(DimensionsSizes_IJK) != 1)
        #error "Is not 1"
    #end // if
    #local N = dimension_size(DimensionsSizes_IJK, 1);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = I_E(DimensionsSizes_IJK);
    #local SizeJ = J_E(DimensionsSizes_IJK);
    #local SizeK = K_E(DimensionsSizes_IJK);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local WW3N = array[SizeI][SizeJ][SizeK];
    #for (K, 0, LastK)
        #for (J, 0, LastJ)
            #for (I, 0, LastI)
                #local WW3N[I][J][K] = Constant;
            #end // for
        #end // for
    #end // for

    WW3N

#end // macro UniformWeights_3N


#macro UniformWeights_4N(DimensionsSizes_IJKL, Constant)

    #if (dimensions(DimensionsSizes_IJKL) != 1)
        #error "Is not 1"
    #end // if
    #local N = dimension_size(DimensionsSizes_IJKL, 1);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = I_E(DimensionsSizes_IJKL);
    #local SizeJ = J_E(DimensionsSizes_IJKL);
    #local SizeK = K_E(DimensionsSizes_IJKL);
    #local SizeL = L_E(DimensionsSizes_IJKL);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local LastL = SizeL - 1;
    #local WW4N = array[SizeI][SizeJ][SizeK][SizeL];
    #for (L, 0, LastL)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI)
                    #local WW4N[I][J][K][L] = Constant;
                #end // for
            #end // for
        #end // for
    #end // for

    WW4N

#end // macro UniformWeights_4N


#macro UniformWeights(DimensionSizes, Constant)

    #if (dimensions(DimensionSizes) != 1)
        #error "Is not 1"
    #end // if
    #local N = dimension_size(DimensionSizes, 1);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if
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
            #error "!"
    #end // switch

    WW

#end // macro UniformWeights

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= 10

#macro From_1A_SampleFunctions_1N1D(_Functions_1D1A, Min_U, Max_U, Res_U)

    #local M =
        max(
            dimensions(_Functions_1D1A),
            dimensions(Min_U),
            dimensions(Max_U),
            dimensions(Res_U)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_1D1A, 1);
    #if (D != 1)
        #error "D is not 1"
    #end // if
    #if (dimension_size(Min_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Max_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Res_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #local MinU = u_E(Min_U);
    #local MaxU = u_E(Max_U);
    #local ResU = u_E(Res_U);
    #local IntervalsU = ResU - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local PP1N1D = array[ResU];
    #local U = MinU;
    #for (I, 0, ResU - 1)
        #local PP1N1D[I] =
            x_E(_Functions_1D1A)(U)
        ;
        #local U = U + dU;
    #end // for

    PP1N1D

#end // From_1A_SampleFunctions_1N1D


#macro From_1A_SampleFunctions_1N2D(_Functions_2D1A, Min_U, Max_U, Res_U)

    #local M =
        max(
            dimensions(_Functions_2D1A),
            dimensions(Min_U),
            dimensions(Max_U),
            dimensions(Res_U)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_2D1A, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if
    #if (dimension_size(Min_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Max_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Res_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #local MinU = u_E(Min_U);
    #local MaxU = u_E(Max_U);
    #local ResU = u_E(Res_U);
    #local IntervalsU = ResU - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local PP1N2D = array[ResU];
    #local U = MinU;
    #for (I, 0, ResU - 1)
        #local PP1N2D[I] =
            <
                x_E(_Functions_2D1A)(U),
                y_E(_Functions_2D1A)(U)
            >
        ;
        #local U = U + dU;
    #end // for

    PP1N2D

#end // From_1A_SampleFunctions_1N2D


#macro From_1A_SampleFunctions_1N3D(_Functions_3D1A, Min_U, Max_U, Res_U)

    #local M =
        max(
            dimensions(_Functions_3D1A),
            dimensions(Min_U),
            dimensions(Max_U),
            dimensions(Res_U)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_3D1A, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if
    #if (dimension_size(Min_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Max_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Res_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #local MinU = u_E(Min_U);
    #local MaxU = u_E(Max_U);
    #local ResU = u_E(Res_U);
    #local IntervalsU = ResU - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local PP1N3D = array[ResU];
    #local U = MinU;
    #for (I, 0, ResU - 1)
        #local PP1N3D[I] =
            <
                x_E(_Functions_3D1A)(U),
                y_E(_Functions_3D1A)(U),
                z_E(_Functions_3D1A)(U)
            >
        ;
        #local U = U + dU;
    #end // for

    PP1N3D

#end // From_1A_SampleFunctions_1N3D


#macro From_1A_SampleFunctions_1N4D(_Functions_4D1A, Min_U, Max_U, Res_U)

    #local M =
        max(
            dimensions(_Functions_4D1A),
            dimensions(Min_U),
            dimensions(Max_U),
            dimensions(Res_U)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_4D1A, 1);
    #if (D != 4)
        #error "D is not 4"
    #end // if
    #if (dimension_size(Min_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Max_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Res_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #local MinU = u_E(Min_U);
    #local MaxU = u_E(Max_U);
    #local ResU = u_E(Res_U);
    #local IntervalsU = ResU - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local PP1N4D = array[ResU];
    #local U = MinU;
    #for (I, 0, ResU - 1)
        #local PP1N4D[I] =
            <
                x_E(_Functions_4D1A)(U),
                y_E(_Functions_4D1A)(U),
                z_E(_Functions_4D1A)(U),
                t_E(_Functions_4D1A)(U)
            >
        ;
        #local U = U + dU;
    #end // for

    PP1N4D

#end // From_1A_SampleFunctions_1N4D


#macro From_2A_SampleFunctions_2N1D(_Functions_1D2A, Min_UV, Max_UV, Res_UV)

    #local M =
        max(
            dimensions(_Functions_1D2A),
            dimensions(Min_UV),
            dimensions(Max_UV),
            dimensions(Res_UV)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_1D2A, 1);
    #if (D != 1)
        #error "D is not 1"
    #end // if
    #if (dimension_size(Min_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Max_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Res_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #local MinU = u_E(Min_UV);
    #local MinV = v_E(Min_UV);
    #local MaxU = u_E(Max_UV);
    #local MaxV = v_E(Max_UV);
    #local ResU = u_E(Res_UV);
    #local ResV = v_E(Res_UV);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local PP2N1D = array[ResU][ResV];
    #local V = MinV;
    #for (J, 0, ResV - 1)
        #local U = MinU;
        #for (I, 0, ResU - 1)
            #local PP2N1D[I][J] =
                x_E(_Functions_1D2A)(U, V)
            ;
            #local U = U + dU;
        #end // for
        #local V = V + dV;
    #end // for

    PP2N1D

#end // From_2A_SampleFunctions_2N1D


#macro From_2A_SampleFunctions_2N2D(_Functions_2D2A, Min_UV, Max_UV, Res_UV)

    #local M =
        max(
            dimensions(_Functions_2D2A),
            dimensions(Min_UV),
            dimensions(Max_UV),
            dimensions(Res_UV)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_2D2A, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if
    #if (dimension_size(Min_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Max_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Res_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #local MinU = u_E(Min_UV);
    #local MinV = v_E(Min_UV);
    #local MaxU = u_E(Max_UV);
    #local MaxV = v_E(Max_UV);
    #local ResU = u_E(Res_UV);
    #local ResV = v_E(Res_UV);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local PP2N2D = array[ResU][ResV];
    #local V = MinV;
    #for (J, 0, ResV - 1)
        #local U = MinU;
        #for (I, 0, ResU - 1)
            #local PP2N2D[I][J] =
                <
                    x_E(_Functions_2D2A)(U, V),
                    y_E(_Functions_2D2A)(U, V)
                >
            ;
            #local U = U + dU;
        #end // for
        #local V = V + dV;
    #end // for

    PP2N2D

#end // From_2A_SampleFunctions_2N2D


#macro From_2A_SampleFunctions_2N3D(_Functions_3D2A, Min_UV, Max_UV, Res_UV)

    #local M =
        max(
            dimensions(_Functions_3D2A),
            dimensions(Min_UV),
            dimensions(Max_UV),
            dimensions(Res_UV)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_3D2A, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if
    #if (dimension_size(Min_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Max_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Res_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #local MinU = u_E(Min_UV);
    #local MinV = v_E(Min_UV);
    #local MaxU = u_E(Max_UV);
    #local MaxV = v_E(Max_UV);
    #local ResU = u_E(Res_UV);
    #local ResV = v_E(Res_UV);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local PP2N3D = array[ResU][ResV];
    #local V = MinV;
    #for (J, 0, ResV - 1)
        #local U = MinU;
        #for (I, 0, ResU - 1)
            #local PP2N3D[I][J] =
                <
                    x_E(_Functions_3D2A)(U, V),
                    y_E(_Functions_3D2A)(U, V),
                    z_E(_Functions_3D2A)(U, V)
                >
            ;
            #local U = U + dU;
        #end // for
        #local V = V + dV;
    #end // for

    PP2N3D

#end // From_2A_SampleFunctions_2N3D


#macro From_2A_SampleFunctions_2N4D(_Functions_4D2A, Min_UV, Max_UV, Res_UV)

    #local M =
        max(
            dimensions(_Functions_4D2A),
            dimensions(Min_UV),
            dimensions(Max_UV),
            dimensions(Res_UV)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_4D2A, 1);
    #if (D != 4)
        #error "D is not 4"
    #end // if
    #if (dimension_size(Min_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Max_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Res_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #local MinU = u_E(Min_UV);
    #local MinV = v_E(Min_UV);
    #local MaxU = u_E(Max_UV);
    #local MaxV = v_E(Max_UV);
    #local ResU = u_E(Res_UV);
    #local ResV = v_E(Res_UV);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local PP2N4D = array[ResU][ResV];
    #local V = MinV;
    #for (J, 0, ResV - 1)
        #local U = MinU;
        #for (I, 0, ResU - 1)
            #local PP2N4D[I][J] =
                <
                    x_E(_Functions_4D2A)(U, V),
                    y_E(_Functions_4D2A)(U, V),
                    z_E(_Functions_4D2A)(U, V),
                    t_E(_Functions_4D2A)(U, V)
                >
            ;
            #local U = U + dU;
        #end // for
        #local V = V + dV;
    #end // for

    PP2N4D

#end // From_2A_SampleFunctions_2N4D


#macro From_3A_SampleFunctions_3N1D(_Functions_1D3A, Min_UVW, Max_UVW, Res_UVW)

    #local M =
        max(
            dimensions(_Functions_1D3A),
            dimensions(Min_UVW),
            dimensions(Max_UVW),
            dimensions(Res_UVW)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_1D3A, 1);
    #if (D != 1)
        #error "D is not 1"
    #end // if
    #if (dimension_size(Min_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Max_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Res_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #local MinU = u_E(Min_UVW);
    #local MinV = v_E(Min_UVW);
    #local MinW = w_E(Min_UVW);
    #local MaxU = u_E(Max_UVW);
    #local MaxV = v_E(Max_UVW);
    #local MaxW = w_E(Max_UVW);
    #local ResU = u_E(Res_UVW);
    #local ResV = v_E(Res_UVW);
    #local ResW = w_E(Res_UVW);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local IntervalsW = ResW - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local dW = (MaxW - MinW)/IntervalsW;
    #local PP3N1D = array[ResU][ResV][ResW];
    #local W = MinW;
    #for (K, 0, ResW - 1)
        #local V = MinV;
        #for (J, 0, ResV - 1)
            #local U = MinU;
            #for (I, 0, ResU - 1)
                #local PP3N1D[I][J][K] =
                    x_E(_Functions_1D3A)(U, V, W)
                ;
                #local U = U + dU;
            #end // for
            #local V = V + dV;
        #end // for
        #local W = W + dW;
    #end // for

    PP3N1D

#end // From_3A_SampleFunctions_3N1D


#macro From_3A_SampleFunctions_3N2D(_Functions_2D3A, Min_UVW, Max_UVW, Res_UVW)

    #local M =
        max(
            dimensions(_Functions_2D3A),
            dimensions(Min_UVW),
            dimensions(Max_UVW),
            dimensions(Res_UVW)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_2D3A, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if
    #if (dimension_size(Min_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Max_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Res_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #local MinU = u_E(Min_UVW);
    #local MinV = v_E(Min_UVW);
    #local MinW = w_E(Min_UVW);
    #local MaxU = u_E(Max_UVW);
    #local MaxV = v_E(Max_UVW);
    #local MaxW = w_E(Max_UVW);
    #local ResU = u_E(Res_UVW);
    #local ResV = v_E(Res_UVW);
    #local ResW = w_E(Res_UVW);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local IntervalsW = ResW - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local dW = (MaxW - MinW)/IntervalsW;
    #local PP3N2D = array[ResU][ResV][ResW];
    #local W = MinW;
    #for (K, 0, ResW - 1)
        #local V = MinV;
        #for (J, 0, ResV - 1)
            #local U = MinU;
            #for (I, 0, ResU - 1)
                #local PP3N2D[I][J][K] =
                    <
                        x_E(_Functions_2D3A)(U, V, W),
                        y_E(_Functions_2D3A)(U, V, W)
                    >
                ;
                #local U = U + dU;
            #end // for
            #local V = V + dV;
        #end // for
        #local W = W + dW;
    #end // for

    PP3N2D

#end // From_3A_SampleFunctions_3N2D


#macro From_3A_SampleFunctions_3N3D(_Functions_3D3A, Min_UVW, Max_UVW, Res_UVW)

    #local M =
        max(
            dimensions(_Functions_3D3A),
            dimensions(Min_UVW),
            dimensions(Max_UVW),
            dimensions(Res_UVW)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_3D3A, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if
    #if (dimension_size(Min_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Max_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Res_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #local MinU = u_E(Min_UVW);
    #local MinV = v_E(Min_UVW);
    #local MinW = w_E(Min_UVW);
    #local MaxU = u_E(Max_UVW);
    #local MaxV = v_E(Max_UVW);
    #local MaxW = w_E(Max_UVW);
    #local ResU = u_E(Res_UVW);
    #local ResV = v_E(Res_UVW);
    #local ResW = w_E(Res_UVW);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local IntervalsW = ResW - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local dW = (MaxW - MinW)/IntervalsW;
    #local PP3N3D = array[ResU][ResV][ResW];
    #local W = MinW;
    #for (K, 0, ResW - 1)
        #local V = MinV;
        #for (J, 0, ResV - 1)
            #local U = MinU;
            #for (I, 0, ResU - 1)
                #local PP3N3D[I][J][K] =
                    <
                        x_E(_Functions_3D3A)(U, V, W),
                        y_E(_Functions_3D3A)(U, V, W),
                        z_E(_Functions_3D3A)(U, V, W)
                    >
                ;
                #local U = U + dU;
            #end // for
            #local V = V + dV;
        #end // for
        #local W = W + dW;
    #end // for

    PP3N3D

#end // From_3A_SampleFunctions_3N3D


#macro From_3A_SampleFunctions_3N4D(_Functions_4D3A, Min_UVW, Max_UVW, Res_UVW)

    #local M =
        max(
            dimensions(_Functions_4D3A),
            dimensions(Min_UVW),
            dimensions(Max_UVW),
            dimensions(Res_UVW)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_4D3A, 1);
    #if (D != 4)
        #error "D is not 4"
    #end // if
    #if (dimension_size(Min_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Max_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Res_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #local MinU = u_E(Min_UVW);
    #local MinV = v_E(Min_UVW);
    #local MinW = w_E(Min_UVW);
    #local MaxU = u_E(Max_UVW);
    #local MaxV = v_E(Max_UVW);
    #local MaxW = w_E(Max_UVW);
    #local ResU = u_E(Res_UVW);
    #local ResV = v_E(Res_UVW);
    #local ResW = w_E(Res_UVW);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local IntervalsW = ResW - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local dW = (MaxW - MinW)/IntervalsW;
    #local PP3N4D = array[ResU][ResV][ResW];
    #local W = MinW;
    #for (K, 0, ResW - 1)
        #local V = MinV;
        #for (J, 0, ResV - 1)
            #local U = MinU;
            #for (I, 0, ResU - 1)
                #local PP3N4D[I][J][K] =
                    <
                        x_E(_Functions_4D3A)(U, V, W),
                        y_E(_Functions_4D3A)(U, V, W),
                        z_E(_Functions_4D3A)(U, V, W),
                        t_E(_Functions_4D3A)(U, V, W)
                    >
                ;
                #local U = U + dU;
            #end // for
            #local V = V + dV;
        #end // for
        #local W = W + dW;
    #end // for

    PP3N4D

#end // From_3A_SampleFunctions_3N4D


#macro From_4A_SampleFunctions_4N1D(_Functions_1D4A, Min_UVWS, Max_UVWS, Res_UVWS)

    #local M =
        max(
            dimensions(_Functions_1D4A),
            dimensions(Min_UVWS),
            dimensions(Max_UVWS),
            dimensions(Res_UVWS)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_1D4A, 1);
    #if (D != 1)
        #error "D is not 1"
    #end // if
    #if (dimension_size(Min_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Max_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Res_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #local MinU = u_E(Min_UVWS);
    #local MinV = v_E(Min_UVWS);
    #local MinW = w_E(Min_UVWS);
    #local MinS = s_E(Min_UVWS);
    #local MaxU = u_E(Max_UVWS);
    #local MaxV = v_E(Max_UVWS);
    #local MaxW = w_E(Max_UVWS);
    #local MaxS = s_E(Max_UVWS);
    #local ResU = u_E(Res_UVWS);
    #local ResV = v_E(Res_UVWS);
    #local ResW = w_E(Res_UVWS);
    #local ResS = s_E(Res_UVWS);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local IntervalsW = ResW - 1;
    #local IntervalsS = ResS - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local dW = (MaxW - MinW)/IntervalsW;
    #local dS = (MaxS - MinS)/IntervalsS;
    #local PP4N1D = array[ResU][ResV][ResW][ResS];
    #local S = MinS;
    #for (L, 0, ResS - 1)
        #local W = MinW;
        #for (K, 0, ResW - 1)
            #local V = MinV;
            #for (J, 0, ResV - 1)
                #local U = MinU;
                #for (I, 0, ResU - 1)
                    #local PP4N1D[I][J][K][L] =
                        x_E(_Functions_1D4A)(U, V, W, S)
                    ;
                    #local U = U + dU;
                #end // for
                #local V = V + dV;
            #end // for
            #local W = W + dW;
        #end // for
        #local S = S + dS;
    #end // for

    PP4N1D

#end // From_4A_SampleFunctions_4N1D


#macro From_4A_SampleFunctions_4N2D(_Functions_2D4A, Min_UVWS, Max_UVWS, Res_UVWS)

    #local M =
        max(
            dimensions(_Functions_2D4A),
            dimensions(Min_UVWS),
            dimensions(Max_UVWS),
            dimensions(Res_UVWS)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_2D4A, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if
    #if (dimension_size(Min_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Max_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Res_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #local MinU = u_E(Min_UVWS);
    #local MinV = v_E(Min_UVWS);
    #local MinW = w_E(Min_UVWS);
    #local MinS = s_E(Min_UVWS);
    #local MaxU = u_E(Max_UVWS);
    #local MaxV = v_E(Max_UVWS);
    #local MaxW = w_E(Max_UVWS);
    #local MaxS = s_E(Max_UVWS);
    #local ResU = u_E(Res_UVWS);
    #local ResV = v_E(Res_UVWS);
    #local ResW = w_E(Res_UVWS);
    #local ResS = s_E(Res_UVWS);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local IntervalsW = ResW - 1;
    #local IntervalsS = ResS - 1;
    #local dU = (MaxV - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local dW = (MaxW - MinW)/IntervalsW;
    #local dS = (MaxS - MinS)/IntervalsS;
    #local PP4N2D = array[ResU][ResV][ResW][ResS];
    #local S = MinS;
    #for (L, 0, ResS - 1)
        #local W = MinW;
        #for (K, 0, ResW - 1)
            #local V = MinV;
            #for (J, 0, ResV - 1)
                #local U = MinU;
                #for (I, 0, ResU - 1)
                    #local PP4N2D[I][J][K][L] =
                        <
                            x_E(_Functions_2D4A)(U, V, W, S),
                            y_E(_Functions_2D4A)(U, V, W, S)
                        >
                    ;
                    #local U = U + dU;
                #end // for
                #local V = V + dV;
            #end // for
            #local W = W + dW;
        #end // for
        #local S = S + dS;
    #end // for

    PP4N2D

#end // From_4A_SampleFunctions_4N2D


#macro From_4A_SampleFunctions_4N3D(_Functions_3D4A, Min_UVWS, Max_UVWS, Res_UVWS)

    #local M =
        max(
            dimensions(_Functions_3D4A),
            dimensions(Min_UVWS),
            dimensions(Max_UVWS),
            dimensions(Res_UVWS)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_3D4A, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if
    #if (dimension_size(Min_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Max_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Res_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #local MinU = u_E(Min_UVWS);
    #local MinV = v_E(Min_UVWS);
    #local MinW = w_E(Min_UVWS);
    #local MinS = s_E(Min_UVWS);
    #local MaxU = u_E(Max_UVWS);
    #local MaxV = v_E(Max_UVWS);
    #local MaxW = w_E(Max_UVWS);
    #local MaxS = s_E(Max_UVWS);
    #local ResU = u_E(Res_UVWS);
    #local ResV = v_E(Res_UVWS);
    #local ResW = w_E(Res_UVWS);
    #local ResS = s_E(Res_UVWS);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local IntervalsW = ResW - 1;
    #local IntervalsS = ResS - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local dW = (MaxW - MinW)/IntervalsW;
    #local dS = (MaxS - MinS)/IntervalsS;
    #local PP4N3D = array[ResU][ResV][ResW][ResS];
    #local S = MinS;
    #for (L, 0, ResS - 1)
        #local W = MinW;
        #for (K, 0, ResW - 1)
            #local V = MinV;
            #for (J, 0, ResV - 1)
                #local U = MinU;
                #for (I, 0, ResU - 1)
                    #local PP4N3D[I][J][K][L] =
                        <
                            x_E(_Functions_3D4A)(U, V, W, S),
                            y_E(_Functions_3D4A)(U, V, W, S),
                            z_E(_Functions_3D4A)(U, V, W, S)
                        >
                    ;
                    #local U = U + dU;
                #end // for
                #local V = V + dV;
            #end // for
            #local W = W + dW;
        #end // for
        #local S = S + dS;
    #end // for

    PP4N3D

#end // From_4A_SampleFunctions_4N3D


#macro From_4A_SampleFunctions_4N4D(_Functions_4D4A, Min_UVWS, Max_UVWS, Res_UVWS)

    #local M =
        max(
            dimensions(_Functions_4D4A),
            dimensions(Min_UVWS),
            dimensions(Max_UVWS),
            dimensions(Res_UVWS)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_4D4A, 1);
    #if (D != 4)
        #error "D is not 4"
    #end // if
    #if (dimension_size(Min_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Max_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Res_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #local MinU = u_E(Min_UVWS);
    #local MinV = v_E(Min_UVWS);
    #local MinW = w_E(Min_UVWS);
    #local MinS = s_E(Min_UVWS);
    #local MaxU = u_E(Max_UVWS);
    #local MaxV = v_E(Max_UVWS);
    #local MaxW = w_E(Max_UVWS);
    #local MaxS = s_E(Max_UVWS);
    #local ResU = u_E(Res_UVWS);
    #local ResV = v_E(Res_UVWS);
    #local ResW = w_E(Res_UVWS);
    #local ResS = s_E(Res_UVWS);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local IntervalsW = ResW - 1;
    #local IntervalsS = ResS - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local dW = (MaxW - MinW)/IntervalsW;
    #local dS = (MaxS - MinS)/IntervalsS;
    #local PP4N4D = array[ResU][ResV][ResW][ResS];
    #local S = MinS;
    #for (L, 0, ResS - 1)
        #local W = MinW;
        #for (K, 0, ResW - 1)
            #local V = MinV;
            #for (J, 0, ResV - 1)
                #local U = MinU;
                #for (I, 0, ResU - 1)
                    #local PP4N4D[I][J][K][L] =
                        <
                            x_E(_Functions_4D4A)(U, V, W, S),
                            y_E(_Functions_4D4A)(U, V, W, S),
                            z_E(_Functions_4D4A)(U, V, W, S),
                            t_E(_Functions_4D4A)(U, V, W, S)
                        >
                    ;
                    #local U = U + dU;
                #end // for
                #local V = V + dV;
            #end // for
            #local W = W + dW;
        #end // for
        #local S = S + dS;
    #end // for

    PP4N4D

#end // From_4A_SampleFunctions_4N4D


#macro SampleFunctions(_Functions, Min, Max, Res)

    #local M =
        max(
            dimensions(_Functions),
            dimensions(Min),
            dimensions(Max),
            dimensions(Res)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions, 1);
    #if (!((D = 1) | (D = 2) | (D = 3) | (D = 4)))
        #error "D is neither 1, 2, 3 nor 4"
    #end // if
    #local Amin =
        min(
            dimension_size(Min, 1),
            dimension_size(Max, 1),
            dimension_size(Res, 1),
        )
    ;
    #local Amax =
        max(
            dimension_size(Min, 1),
            dimension_size(Max, 1),
            dimension_size(Res, 1),
        )
    ;
    #if (Amin != Amax)
        #error "Amin and Amax are not equal"
    #end // if
    #local A = Amin;
    #if (!((A = 1) | (A = 2) | (A = 3) | (A = 4)))
        #error "A is neither 1, 2, 3 nor 4"
    #end // if
    #switch (D)
        #case (1)  // 1D
            #switch (A)
                #case (1)  // 1A (1N)
                    #local PP =
                        From_1A_SampleFunctions_1N1D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (2)  // 2A (2N)
                    #local PP =
                        From_2A_SampleFunctions_2N1D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (3)  // 3A (3N)
                    #local PP =
                        From_3A_SampleFunctions_3N1D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (4)  // 4A (4N)
                    #local PP =
                        From_4A_SampleFunctions_4N1D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #else
                    #error "!"
            #end // switch
            #break
        #case (2)  // 2D
            #switch (A)
                #case (1)  // 1A (1N)
                    #local PP =
                        From_1A_SampleFunctions_1N2D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (2)  // 2A (2N)
                    #local PP =
                        From_2A_SampleFunctions_2N2D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (3)  // 3A (3N)
                    #local PP =
                        From_3A_SampleFunctions_3N2D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (4)  // 4A (4N)
                    #local PP =
                        From_4A_SampleFunctions_4N2D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #else
                    #error "!"
            #end // switch
            #break
        #case (3)  // 3D
            #switch (A)
                #case (1)  // 1A (1N)
                    #local PP =
                        From_1A_SampleFunctions_1N3D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (2)  // 2A (2N)
                    #local PP =
                        From_2A_SampleFunctions_2N3D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (3)  // 3A (3N)
                    #local PP =
                        From_3A_SampleFunctions_3N3D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (4)  // 4A (4N)
                    #local PP =
                        From_4A_SampleFunctions_4N3D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #else
                    #error "!"
            #end // switch
            #break
        #case (4)  // 4D
            #switch (A)
                #case (1)  // 1A (1N)
                    #local PP =
                        From_1A_SampleFunctions_1N4D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (2)  // 2A (2N)
                    #local PP =
                        From_2A_SampleFunctions_2N4D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (3)  // 3A (3N)
                    #local PP =
                        From_3A_SampleFunctions_3N4D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (4)  // 4A (4N)
                    #local PP =
                        From_4A_SampleFunctions_4N4D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #else
                    #error "!"
            #end // switch
            #break
        #else
            #error "!"
    #end // switch

#end // SampleFunctions

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro LinearGrid_1N1D(Min_U, Max_U, Res_U)

    #local M =
        max(
            dimensions(Min_U),
            dimensions(Max_U),
            dimensions(Res_U)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #if (dimension_size(Min_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Max_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Res_U, 1) != 1)
        #error "Is not 1"
    #end // if
    #local MinU = u_E(Min_U);
    #local MaxU = u_E(Max_U);
    #local ResU = u_E(Res_U);
    #local IntervalsU = ResU - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local PP1N1D = array[ResU];
    #local U = MinU;
    #for (I, 0, ResU - 1)
        #local PP1N1D[I] =
            U
        ;
        #local U = U + dU;
    #end // for

    PP1N1D

#end // LinearGrid_1N1D


#macro LinearGrid_2N2D(Min_UV, Max_UV, Res_UV)

    #local M =
        max(
            dimensions(Min_UV),
            dimensions(Max_UV),
            dimensions(Res_UV)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #if (dimension_size(Min_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Max_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Res_UV, 1) != 2)
        #error "Is not 2"
    #end // if
    #local MinU = u_E(Min_UV);
    #local MinV = v_E(Min_UV);
    #local MaxU = u_E(Max_UV);
    #local MaxV = v_E(Max_UV);
    #local ResU = u_E(Res_UV);
    #local ResV = v_E(Res_UV);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local PP2N2D = array[ResU][ResV];
    #local V = MinV;
    #for (J, 0, ResV - 1)
        #local U = MinU;
        #for (I, 0, ResU - 1)
            #local PP2N2D[I][J] =
                <U, V>
            ;
            #local U = U + dU;
        #end // for
        #local V = V + dV;
    #end // for

    PP2N2D

#end // LinearGrid_2N2D


#macro LinearGrid_3N3D(Min_UVW, Max_UVW, Res_UVW)

    #local M =
        max(
            dimensions(Min_UVW),
            dimensions(Max_UVW),
            dimensions(Res_UVW)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #if (dimension_size(Min_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Max_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Res_UVW, 1) != 3)
        #error "Is not 3"
    #end // if
    #local MinU = u_E(Min_UVW);
    #local MinV = v_E(Min_UVW);
    #local MinW = w_E(Min_UVW);
    #local MaxU = u_E(Max_UVW);
    #local MaxV = v_E(Max_UVW);
    #local MaxW = w_E(Max_UVW);
    #local ResU = u_E(Res_UVW);
    #local ResV = v_E(Res_UVW);
    #local ResW = w_E(Res_UVW);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local IntervalsW = ResW - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local dW = (MaxW - MinW)/IntervalsW;
    #local PP3N3D = array[ResU][ResV][ResW];
    #local W = MinW;
    #for (K, 0, ResW - 1)
        #local V = MinV;
        #for (J, 0, ResV - 1)
            #local U = MinU;
            #for (I, 0, ResU - 1)
                #local PP3N3D[I][J][K] =
                    <U, V, W>
                ;
                #local U = U + dU;
            #end // for
            #local V = V + dV;
        #end // for
        #local W = W + dW;
    #end // for

    PP3N3D

#end // LinearGrid_3N3D


#macro LinearGrid_4N4D(Min_UVWS, Max_UVWS, Res_UVWS)

    #local M =
        max(
            dimensions(Min_UVWS),
            dimensions(Max_UVWS),
            dimensions(Res_UVWS)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #if (dimension_size(Min_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Max_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Res_UVWS, 1) != 4)
        #error "Is not 4"
    #end // if
    #local MinU = u_E(Min_UVWS);
    #local MinV = v_E(Min_UVWS);
    #local MinW = w_E(Min_UVWS);
    #local MinS = s_E(Min_UVWS);
    #local MaxU = u_E(Max_UVWS);
    #local MaxV = v_E(Max_UVWS);
    #local MaxW = w_E(Max_UVWS);
    #local MaxS = s_E(Max_UVWS);
    #local ResU = u_E(Res_UVWS);
    #local ResV = v_E(Res_UVWS);
    #local ResW = w_E(Res_UVWS);
    #local ResS = s_E(Res_UVWS);
    #local IntervalsU = ResU - 1;
    #local IntervalsV = ResV - 1;
    #local IntervalsW = ResW - 1;
    #local IntervalsS = ResS - 1;
    #local dU = (MaxU - MinU)/IntervalsU;
    #local dV = (MaxV - MinV)/IntervalsV;
    #local dW = (MaxW - MinW)/IntervalsW;
    #local dS = (MaxS - MinS)/IntervalsS;
    #local PP4N4D = array[ResU][ResV][ResW][ResS];
    #local S = MinS;
    #for (L, 0, ResS - 1)
        #local W = MinW;
        #for (K, 0, ResW - 1)
            #local V = MinV;
            #for (J, 0, ResV - 1)
                #local U = MinU;
                #for (I, 0, ResU - 1)
                    #local PP4N4D[I][J][K][L] =
                        <U, V, W, S>
                    ;
                    #local U = U + dU;
                #end // for
                #local V = V + dV;
            #end // for
            #local W = W + dW;
        #end // for
        #local S = S + dS;
    #end // for

    PP4N4D

#end // LinearGrid_4N4D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro BernsteinBasisFunction_1A(N, R)

    #local C = BinomialFn(N, R);
    #local M = N - R;

    function(_t) { C*PowFn(_t, R)*PowFn(1 - _t, M) }

#end // macro BernsteinBasisFunction_1A


#macro BernsteinBasisFunctions_1N1A(Degree)

    #local _Fns1N1A = array[Degree+1];
    #for (I, 0, Degree)
        #local _Fns1N1A[I] =
            BernsteinBasisFunction_1A(
                Degree, I
            )
        ;
    #end // for

    _Fns1N1A

#end // macro BernsteinBasisFunctions_1N1A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro WeightedFunction_1A(_U_Fns_1A1N, Weights_1N)

    #if (dimensions(_U_Fns_1A1N) != 1)
        #error "Is not 1"
    #end // if
    #local N = dimensions(Weights_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(Weights_1N, 1);
    #if (dimension_size(_U_Fns_1A1N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #local LastI = SizeI - 1;

    function(_u) {
        0.0
        #for (I, 0, LastI)
            #local Q = Weights_1N[I];
            #switch (Q)
                #case (0.0)
                    #break
                #case (-1.0)
                    -_U_Fns_1A1N[I](_u)
                    #break
                #case (+1.0)
                    + _U_Fns_1A1N[I](_u)
                    #break
                #else
                    + Q*_U_Fns_1A1N[I](_u)
            #end // switch
        #end // for
    }

#end // macro WeightedFunction_1A


#macro WeightedFunction_2A(_U_Fns_1A1N, _V_Fns_1A1N, Weights_2N)

    #if (dimensions(_U_Fns_1A1N) != 1)
        #error "Is not 1"
    #end // if
    #if (dimensions(_V_Fns_1A1N) != 1)
        #error "Is not 1"
    #end // if
    #local N = dimensions(Weights_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(Weights_2N, 1);
    #local SizeJ = dimension_size(Weights_2N, 2);
    #if (dimension_size(_U_Fns_1A1N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #if (dimension_size(_V_Fns_1A1N, 1) != SizeJ)
        #error "Is not equal to SizeJ"
    #end // if
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;

    function(_u, _v) {
        0.0
        #for (J, 0, LastJ)
            + _V_Fns_1A1N[J](_v)*
            (
                0.0
                #for (I, 0, LastI)
                    #local Q = Weights_2N[I][J];
                    #switch (Q)
                        #case (0.0)
                            #break
                        #case (-1.0)
                            - _U_Fns_1A1N[I](_u)
                            #break
                        #case (+1.0)
                            + _U_Fns_1A1N[I](_u)
                            #break
                        #else
                            + Q*_U_Fns_1A1N[I](_u)
                    #end // switch
                #end // for
            )
        #end // for
    }

#end // macro WeightedFunction_2A


#macro WeightedFunction_3A(_U_Fns_1A1N, _V_Fns_1A1N, _W_Fns_1A1N, Weights_3N)

    #if (dimensions(_U_Fns_1A1N) != 1)
        #error "Is not 1"
    #end // if
    #if (dimensions(_V_Fns_1A1N) != 1)
        #error "Is not 1"
    #end // if
    #if (dimensions(_W_Fns_1A1N) != 1)
        #error "Is not 1"
    #end // if
    #local N = dimensions(Weights_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(Weights_3N, 1);
    #local SizeJ = dimension_size(Weights_3N, 2);
    #local SizeK = dimension_size(Weights_3N, 3);
    #if (dimension_size(_U_Fns_1A1N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #if (dimension_size(_V_Fns_1A1N, 1) != SizeJ)
        #error "Is not equal to SizeJ"
    #end // if
    #if (dimension_size(_W_Fns_1A1N, 1) != SizeK)
        #error "Is not equal to SizeK"
    #end // if
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;

    function(_u, _v, _w) {
        0.0
        #for (K, 0, LastK)
            + _W_Fns_1A1N[K](_w)*
            (
                0.0
                #for (J, 0, LastJ)
                    + _V_Fns_1A1N[J](_v)*
                    (
                        0.0
                        #for (I, 0, LastI)
                            #local Q = Weights_3N[I][J][K];
                            #switch (Q)
                                #case (0.0)
                                    #break
                                #case (-1.0)
                                    - _U_Fns_1A1N[I](_u)
                                    #break
                                #case (+1.0)
                                    + _U_Fns_1A1N[I](_u)
                                    #break
                                #else
                                    + Q*_U_Fns_1A1N[I](_u)
                            #end // switch
                        #end // for
                    )
                #end // for
            )
        #end // for
    }

#end // macro WeightedFunction_3A


#macro WeightedFunction_4A(_U_Fns_1A1N, _V_Fns_1A1N, _W_Fns_1A1N, _S_Fns_1A1N, Weights_4N)

    #if (dimensions(_U_Fns_1A1N) != 1)
        #error "Is not 1"
    #end // if
    #if (dimensions(_V_Fns_1A1N) != 1)
        #error "Is not 1"
    #end // if
    #if (dimensions(_W_Fns_1A1N) != 1)
        #error "Is not 1"
    #end // if
    #if (dimensions(_S_Fns_1A1N) != 1)
        #error "Is not 1"
    #end // if
    #local N = dimensions(Weights_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Weights_4N, 1);
    #local SizeJ = dimension_size(Weights_4N, 2);
    #local SizeK = dimension_size(Weights_4N, 3);
    #local SizeL = dimension_size(Weights_4N, 4);
    #if (dimension_size(_U_Fns_1A1N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #if (dimension_size(_V_Fns_1A1N, 1) != SizeJ)
        #error "Is not equal to SizeJ"
    #end // if
    #if (dimension_size(_W_Fns_1A1N, 1) != SizeK)
        #error "Is not equal to SizeK"
    #end // if
    #if (dimension_size(_S_Fns_1A1N, 1) != SizeL)
        #error "Is not equal to SizeL"
    #end // if
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local LastL = SizeL - 1;

    function(_u, _v, _w, _s) {
        0.0
        #for (L, 0, LastL)
            + _S_Fns_1A1N[L](_s)*
            (
                0.0
                #for (K, 0, LastK)
                    + _W_Fns_1A1N[K](_w)*
                    (
                        0.0
                        #for (J, 0, LastJ)
                            + _V_Fns_1A1N[J](_v)*
                            (
                                0.0
                                #for (I, 0, LastI)
                                    #local Q = Weights_4N[I][J][K][L];
                                    #switch (Q)
                                        #case (0.0)
                                            #break
                                        #case (-1.0)
                                            - _U_Fns_1A1N[I](_u)
                                            #break
                                        #case (+1.0)
                                            + _U_Fns_1A1N[I](_u)
                                            #break
                                        #else
                                            + Q*_U_Fns_1A1N[I](_u)
                                    #end // switch
                                #end // for
                            )
                        #end // for
                    )
                #end // for
            )
        #end // for
    }

#end // macro WeightedFunction_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_1N_BezierFunction_1A(Values_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(Values_1N, 1);

    WeightedFunction_1A(
        BernsteinBasisFunctions_1N1A(SizeI - 1),
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
        BernsteinBasisFunctions_1N1A(SizeI - 1),
        BernsteinBasisFunctions_1N1A(SizeJ - 1),
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
        BernsteinBasisFunctions_1N1A(SizeI - 1),
        BernsteinBasisFunctions_1N1A(SizeJ - 1),
        BernsteinBasisFunctions_1N1A(SizeK - 1),
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
        BernsteinBasisFunctions_1N1A(SizeI - 1),
        BernsteinBasisFunctions_1N1A(SizeJ - 1),
        BernsteinBasisFunctions_1N1A(SizeK - 1),
        BernsteinBasisFunctions_1N1A(SizeL - 1),
        Values_4N
    )

#end // macro From_4N_BezierFunction_4A


#macro BezierFunction(Values)

    #local N = dimensions(Values);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if

    #switch (N)
        #case (1)  // 1N1A
            From_1N_BezierFunction_1A(
                Values
            )
            #break
        #case (2)  // 2N2A
            From_2N_BezierFunction_2A(
                Values
            )
            #break
        #case (3)  // 3N3A
            From_3N_BezierFunction_3A(
                Values
            )
            #break
        #case (4)  // 4N4A
            From_4N_BezierFunction_4A(
                Values
            )
            #break
        #else
            #error "!"
    #end // switch

#end // macro BezierFunction

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_1N_RationalBezierFunction_1A(Values_1N, Weights_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Weights_1N) != 1)
        #error "Is not 1"
    #end // if

    DivideFunctions_1A(
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

    DivideFunctions_2A(
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

    DivideFunctions_3A(
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

    DivideFunctions_4A(
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


#macro RationalBezierFunction(Values, Weights)

    #local N = dimensions(Values);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if
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
            #error "!"
    #end // switch

#end // macro RationalBezierFunction

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

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

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

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

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#declare ElevationCoefficientFn =
    function(_d, _n, _i, _s) {
        BinomialFn(_d, _s)
        *
        FactRisingFn(_i + 1, _s)
        *
        FactRisingFn(_n - _i, _d - _s)
    }
;


#macro DegreeElevate_I_1N(Values_1N, NoOfDegrees)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(Values_1N, 1);
    #local NewSizeI = SizeI + NoOfDegrees;
    #local VV1N = array[NewSizeI];
    #local DI =
        FactRisingFn(
            SizeI,
            NoOfDegrees
        )
    ;
    #local p0 = 0*Values_1N[0];
    #local VV1N[0] = Values_1N[0];
    #for (I, 1, NewSizeI - 2)
        #local pSum = p0;
        #for (Io, max(I - NoOfDegrees, 0), min(SizeI - 1, I))
            #local pSum =
                pSum
                +
                ElevationCoefficientFn(
                    NoOfDegrees,
                    SizeI,
                    Io,  // original index
                    I - Io  // shift
                )
                *
                Values_1N[Io]
            ;
        #end // for
        #local VV1N[I] = pSum/DI;
    #end // for
    #local VV1N[NewSizeI-1] = Values_1N[SizeI-1];

    VV1N

#end // macro DegreeElevate_I_1N


#macro DegreeElevate_I_2N(Values_2N, NoOfDegrees)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(Values_2N, 1);
    #local SizeJ = dimension_size(Values_2N, 2);
    #local NewSizeI = SizeI + NoOfDegrees;
    #local VV2N = array[NewSizeI][SizeJ];
    #local DI =
        FactRisingFn(
            SizeI,
            NoOfDegrees
        )
    ;
    #local p0 = 0*Values_2N[0][0];
    #for (J, 0, SizeJ - 1)
        #local VV2N[0][J] = Values_2N[0][J];
        #for (I, 1, NewSizeI - 2)
            #local pSum = p0;
            #for (Io, max(0, I - NoOfDegrees), min(SizeI - 1, I))
                #local pSum =
                    pSum
                    +
                    ElevationCoefficientFn(
                        NoOfDegrees,
                        SizeI,
                        Io,  // original index
                        I - Io  // shift
                    )
                    *
                    Values_2N[Io][J]
                ;
            #end // for
            #local VV2N[I][J] = pSum/DI;
        #end // for
        #local VV2N[NewSizeI-1][J] = Values_2N[SizeI-1][J];
    #end // for

    VV2N

#end // macro DegreeElevate_I_2N


#macro DegreeElevate_J_2N(Values_2N, NoOfDegrees)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(Values_2N, 1);
    #local SizeJ = dimension_size(Values_2N, 2);
    #local NewSizeJ = SizeJ + NoOfDegrees;
    #local VV2N = array[SizeI][NewSizeJ];
    #local DJ =
        FactRisingFn(
            SizeJ,
            NoOfDegrees
        )
    ;
    #local p0 = 0*Values_2N[0][0];
    #for (I, 0, SizeI - 1)
        #local VV2N[I][0] = Values_2N[I][0];
        #for (J, 1, NewSizeJ - 2)
            #local pSum = p0;
            #for (Jo, max(0, J - NoOfDegrees), min(SizeJ - 1, J))
                #local pSum =
                    pSum
                    +
                    ElevationCoefficientFn(
                        NoOfDegrees,
                        SizeJ,
                        Jo,  // original index
                        J - Jo  // shift
                    )
                    *
                    Values_2N[I][Jo]
                ;
            #end // for
            #local VV2N[I][J] = pSum/DJ;
        #end // for
        #local VV2N[I][NewSizeJ-1] = Values_2N[I][SizeJ-1];
    #end // for

    VV2N

#end // macro DegreeElevate_J_2N


#macro DegreeElevate_I_3N(Values_3N, NoOfDegrees)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(Values_3N, 1);
    #local SizeJ = dimension_size(Values_3N, 2);
    #local SizeK = dimension_size(Values_3N, 3);
    #local NewSizeI = SizeI + NoOfDegrees;
    #local VV3N = array[NewSizeI][SizeJ][SizeK];
    #local DI =
        FactRisingFn(
            SizeI,
            NoOfDegrees
        )
    ;
    #local p0 = 0*Values_3N[0][0][0];
    #for (K, 0, SizeK - 1)
        #for (J, 0, SizeJ - 1)
            #local VV3N[0][J][K] = Values_3N[0][J][K];
            #for (I, 1, NewSizeI - 2)
                #local pSum = p0;
                #for (Io, max(I - NoOfDegrees, 0), min(SizeI - 1, I))
                    #local pSum =
                        pSum
                        +
                        ElevationCoefficientFn(
                            NoOfDegrees,
                            SizeI,
                            Io,  // original index
                            I - Io  // shift
                        )
                        *
                        Values_3N[Io][J][K]
                    ;
                #end // for
                #local VV3N[I][J][K] = pSum/DI;
            #end // for
            #local VV3N[NewSizeI-1][J][K] = Values_3N[SizeI-1][J][K];
        #end // for
    #end // for

    VV3N

#end // macro DegreeElevate_I_3N


#macro DegreeElevate_J_3N(Values_3N, NoOfDegrees)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(Values_3N, 1);
    #local SizeJ = dimension_size(Values_3N, 2);
    #local SizeK = dimension_size(Values_3N, 3);
    #local NewSizeJ = SizeJ + NoOfDegrees;
    #local VV3N = array[SizeI][NewSizeJ][SizeK];
    #local DJ =
        FactRisingFn(
            SizeJ,
            NoOfDegrees
        )
    ;
    #local p0 = 0*Values_3N[0][0][0];
    #for (I, 0, SizeI - 1)
        #for (K, 0, SizeK - 1)
            #local VV3N[I][0][K] = Values_3N[I][0][K];
            #for (J, 1, NewSizeJ - 2)
                #local pSum = p0;
                #for (Jo, max(J - NoOfDegrees, 0), min(SizeJ - 1, J))
                    #local pSum =
                        pSum
                        +
                        ElevationCoefficientFn(
                            NoOfDegrees,
                            SizeJ,
                            Jo,  // original index
                            J - Jo // shift
                        )
                        *
                        Values_3N[I][Jo][K]
                    ;
                #end // for
                #local VV3N[I][J][K] = pSum/DJ;
            #end // for
            #local VV3N[I][NewSizeJ-1][K] = Values_3N[I][SizeJ-1][K];
        #end // for
    #end // for

    VV3N

#end // macro DegreeElevate_J_3N


#macro DegreeElevate_K_3N(Values_3N, NoOfDegrees)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(Values_3N, 1);
    #local SizeJ = dimension_size(Values_3N, 2);
    #local SizeK = dimension_size(Values_3N, 3);
    #local NewSizeK = SizeK + NoOfDegrees;
    #local VV3N = array[SizeI][SizeJ][NewSizeK];
    #local DK =
        FactRisingFn(
            SizeK,
            NoOfDegrees
        )
    ;
    #local p0 = 0*Values_3N[0][0][0];
    #for (J, 0, SizeJ - 1)
        #for (I, 0, SizeI - 1)
            #local VV3N[I][J][0] = Values_3N[I][J][0];
            #for (K, 1, NewSizeK - 2)
                #local pSum = p0;
                #for (Ko, max(K - NoOfDegrees, 0), min(SizeK - 1, K))
                    #local pSum =
                        pSum
                        +
                        ElevationCoefficientFn(
                            NoOfDegrees,
                            SizeK,
                            Ko,  // original index
                            K - Ko  // shift
                        )
                        *
                        Values_3N[I][J][Ko]
                    ;
                #end // for
                #local VV3N[I][J][K] = pSum/DK;
            #end // for
            #local VV3N[I][J][NewSizeK-1] = Values_3N[I][J][SizeK-1];
        #end // for
    #end // for

    VV3N
 
#end // macro DegreeElevate_K_3N


#macro DegreeElevate_I_4N(Values_4N, NoOfDegrees)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Values_4N, 1);
    #local SizeJ = dimension_size(Values_4N, 2);
    #local SizeK = dimension_size(Values_4N, 3);
    #local SizeL = dimension_size(Values_4N, 4);
    #local NewSizeI = SizeI + NoOfDegrees;
    #local VV4N = array[NewSizeI][SizeJ][SizeK][SizeL];
    #local DI =
        FactRisingFn(
            SizeI,
            NoOfDegrees
        )
    ;
    #local p0 = 0*Values_4N[0][0][0][0];
    #for (L, 0, SizeL - 1)
        #for (K, 0, SizeK - 1)
            #for (J, 0, SizeJ - 1)
                #local VV4N[0][J][K][L] = Values_4N[0][J][K][L];
                #for (I, 1, NewSizeI - 2)
                    #local pSum = p0;
                    #for (Io, max(I - NoOfDegrees, 0), min(SizeI - 1, I))
                        #local pSum =
                            pSum
                            +
                            ElevationCoefficientFn(
                                NoOfDegrees,
                                SizeI,
                                Io,  // original index
                                I - Io  // shift
                            )
                            *
                            Values_4N[Io][J][K][L]
                        ;
                    #end // for
                    #local VV4N[I][J][K][L] = pSum/DI;
                #end // for
                #local VV4N[NewSizeI-1][J][K][L] = Values_4N[SizeI-1][J][K][L];
            #end // for
        #end // for
    #end // for

    VV4N

#end // macro DegreeElevate_I_4N


#macro DegreeElevate_J_4N(Values_4N, NoOfDegrees)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Values_4N, 1);
    #local SizeJ = dimension_size(Values_4N, 2);
    #local SizeK = dimension_size(Values_4N, 3);
    #local SizeL = dimension_size(Values_4N, 4);
    #local NewSizeJ = SizeJ + NoOfDegrees;
    #local VV4N = array[SizeI][NewSizeJ][SizeK][SizeL];
    #local DJ =
        FactRisingFn(
            SizeJ,
            NoOfDegrees
        )
    ;
    #local p0 = 0*Values_4N[0][0][0][0];
    #for (I, 0, SizeI - 1)
        #for (L, 0, SizeL - 1)
            #for (K, 0, SizeK - 1)
                #local VV4N[I][0][K][L] = Values_4N[I][0][K][L];
                #for (J, 1, NewSizeJ - 2)
                    #local pSum = p0;
                    #for (Jo, max(J - NoOfDegrees, 0), min(SizeJ - 1, J))
                        #local pSum =
                            pSum
                            +
                            ElevationCoefficientFn(
                                NoOfDegrees,
                                SizeJ,
                                Jo,  // original index
                                J - Jo  // shift
                            )
                            *
                            Values_4N[I][Jo][K][L]
                        ;
                    #end // for
                    #local VV4N[I][J][K][L] = pSum/DJ;
                #end // for
                #local VV4N[I][NewSizeJ-1][K][L] = Values_4N[I][SizeJ-1][K][L];
            #end // for
        #end // for
    #end // for

    VV4N

#end // macro DegreeElevate_J_4N


#macro DegreeElevate_K_4N(Values_4N, NoOfDegrees)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Values_4N, 1);
    #local SizeJ = dimension_size(Values_4N, 2);
    #local SizeK = dimension_size(Values_4N, 3);
    #local SizeL = dimension_size(Values_4N, 4);
    #local NewSizeK = SizeK + NoOfDegrees;
    #local VV4N = array[SizeI][SizeJ][NewSizeK][SizeL];
    #local DK =
        FactRisingFn(
            SizeK,
            NoOfDegrees
        )
    ;
    #local p0 = 0*Values_4N[0][0][0][0];
    #for (J, 0, SizeJ - 1)
        #for (I, 0, SizeI - 1)
            #for (L, 0, SizeL - 1)
                #local VV4N[I][J][0][L] = Values_4N[I][J][0][L];
                #for (K, 1, NewSizeK - 2)
                    #local pSum = p0;
                    #for (Ko, max(K - NoOfDegrees, 0), min(SizeK - 1, K))
                        #local pSum =
                            pSum
                            +
                            ElevationCoefficientFn(
                                NoOfDegrees,
                                SizeK,
                                Ko,  // original index
                                K - Ko  // shift
                            )
                            *
                            Values_4N[I][J][Ko][L]
                        ;
                    #end // for
                    #local VV4N[I][J][K][L] = pSum/DK;
                #end // for
                #local VV4N[I][J][NewSizeK-1][L] = Values_4N[I][J][SizeK-1][L];
            #end // for
        #end // for
    #end // for

    VV4N

#end // macro DegreeElevate_K_4N


#macro DegreeElevate_L_4N(Values_4N, NoOfDegrees)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Values_4N, 1);
    #local SizeJ = dimension_size(Values_4N, 2);
    #local SizeK = dimension_size(Values_4N, 3);
    #local SizeL = dimension_size(Values_4N, 4);
    #local NewSizeL = SizeL + NoOfDegrees;
    #local VV4N = array[SizeI][SizeJ][SizeK][NewSizeL];
    #local DL =
        FactRisingFn(
            SizeL,
            NoOfDegrees
        )
    ;
    #local p0 = 0*Values_4N[0][0][0][0];
    #for (K, 0, SizeK - 1)
        #for (J, 0, SizeJ - 1)
            #for (I, 0, SizeI - 1)
                #local VV4N[I][J][K][0] = Values_4N[I][J][K][0];
                #for (L, 1, NewSizeL - 2)
                    #local pSum = p0;
                    #for (Lo, max(L - NoOfDegrees, 0), min(SizeL - 1, L))
                        #local pSum =
                            pSum
                            +
                            ElevationCoefficientFn(
                                NoOfDegrees,
                                SizeL,
                                Lo,  // original index
                                L - Lo  // shift
                            )
                            *
                            Values_4N[I][J][K][Lo]
                        ;
                    #end // for
                    #local VV4N[I][J][K][L] = pSum/DL;
                #end // for
                #local VV4N[I][J][K][NewSizeL-1] = Values_4N[I][J][K][SizeL-1];
            #end // for
        #end // for
    #end // for

    VV4N

#end // macro DegreeElevate_L_4N

#macro RationalDegreeElevate_I_1N(Values_1N, Weights_1N, NoOfDegrees)

    #local WeightedValues_1N =
        MultiplyArrays_1N(
            Values_1N,
            Weights_1N
        )
    ;
    #local ElevatedWeightedValues_1N =
        DegreeElevate_I_1N(
            WeightedValues_1N,
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
        ElevatedWeightedValues_1N,
        ElevatedWeights_1N
    )

#end // macro RationalDegreeElevate_I_1N


#macro RationalDegreeElevate_I_2N(Values_2N, Weights_2N, NoOfDegrees)

    #local WeightedValues_2N =
        MultiplyArrays_2N(
            Values_2N,
            Weights_2N
        )
    ;
    #local ElevatedWeightedValues_2N =
        DegreeElevate_I_2N(
            WeightedValues_2N,
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
        ElevatedWeightedValues_2N,
        ElevatedWeights_2N
    )

#end // macro RationalDegreeElevate_I_2N


#macro RationalDegreeElevate_J_2N(Values_2N, Weights_2N, NoOfDegrees)

    #local WeightedValues_2N =
        MultiplyArrays_2N(
            Values_2N,
            Weights_2N
        )
    ;
    #local ElevatedWeightedValues_2N =
        DegreeElevate_J_2N(
            WeightedValues_2N,
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
        ElevatedWeightedValues_2N,
        ElevatedWeights_2N
    )

#end // macro RationalDegreeElevate_J_2N


#macro RationalDegreeElevate_I_3N(Values_3N, Weights_3N, NoOfDegrees)

    #local WeightedValues_3N =
        MultiplyArrays_3N(
            Values_3N,
            Weights_3N
        )
    ;
    #local ElevatedWeightedValues_3N =
        DegreeElevate_I_3N(
            WeightedValues_3N,
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
        ElevatedWeightedValues_3N,
        ElevatedWeights_3N
    )

#end // macro RationalDegreeElevate_I_3N


#macro RationalDegreeElevate_J_3N(Values_3N, Weights_3N, NoOfDegrees)

    #local WeightedValues_3N =
        MultiplyArrays_3N(
            Values_3N,
            Weights_3N
        )
    ;
    #local ElevatedWeightedValues_3N =
        DegreeElevate_J_3N(
            WeightedValues_3N,
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
        ElevatedWeightedValues_3N,
        ElevatedWeights_3N
    )

#end // macro RationalDegreeElevate_J_3N


#macro RationalDegreeElevate_K_3N(Values_3N, Weights_3N, NoOfDegrees)

    #local WeightedValues_3N =
        MultiplyArrays_3N(
            Values_3N,
            Weights_3N
        )
    ;
    #local ElevatedWeightedValues_3N =
        DegreeElevate_K_3N(
            WeightedValues_3N,
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
        ElevatedWeightedValues_3N,
        ElevatedWeights_3N
    )

#end // macro RationalDegreeElevate_K_3N


#macro RationalDegreeElevate_I_4N(Values_4N, Weights_4N, NoOfDegrees)

    #local WeightedValues_4N =
        MultiplyArrays_4N(
            Values_4N,
            Weights_4N
        )
    ;
    #local ElevatedWeightedValues_4N =
        DegreeElevate_I_4N(
            WeightedValues_4N,
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
        ElevatedWeightedValues_4N,
        ElevatedWeights_4N
    )

#end // macro RationalDegreeElevate_I_4N


#macro RationalDegreeElevate_J_4N(Values_4N, Weights_4N, NoOfDegrees)

    #local WeightedValues_4N =
        MultiplyArrays_4N(
            Values_4N,
            Weights_4N
        )
    ;
    #local ElevatedWeightedValues_4N =
        DegreeElevate_J_4N(
            WeightedValues_4N,
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
        ElevatedWeightedValues_4N,
        ElevatedWeights_4N
    )

#end // macro RationalDegreeElevate_J_4N


#macro RationalDegreeElevate_K_4N(Values_4N, Weights_4N, NoOfDegrees)

    #local WeightedValues_4N =
        MultiplyArrays_4N(
            Values_4N,
            Weights_4N
        )
    ;
    #local ElevatedWeightedValues_4N =
        DegreeElevate_K_4N(
            WeightedValues_4N,
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
        ElevatedWeightedValues_4N,
        ElevatedWeights_4N
    )

#end // macro RationalDegreeElevate_K_4N


#macro RationalDegreeElevate_L_4N(Values_4N, Weights_4N, NoOfDegrees)

    #local WeightedValues_4N =
        MultiplyArrays_4N(
            Values_4N,
            Weights_4N
        )
    ;
    #local ElevatedWeightedValues_4N =
        DegreeElevate_L_4N(
            WeightedValues_4N,
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
        ElevatedWeightedValues_4N,
        ElevatedWeights_4N
    )

#end // macro RationalDegreeElevate_L_4N

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro _HodographCoefficients(M)

    #local CC = array[M+1];
    #for (I, 0, M)
        #local CC[I] =
            pow(-1, M + I)*BinomialFn(M, I)
        ;
    #end // for

    CC

#end // macro _HodographCoefficients


#macro Hodograph_I_1N(Values_1N, M)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local CC = _HodographCoefficients(M);
    #local SizeI = dimension_size(Values_1N, 1);
    #local NewSizeI = SizeI - M;   
    #local VV1N = array[NewSizeI];
    #local p0 = 0*Values_1N[0];
    #for (I, 0, NewSizeI - 1)
        #local pSum = p0;
        #for (A, 0, M)
            #local pSum =
                pSum + CC[A]*Values_1N[I+A]
            ;
        #end // for
        #local VV1N[I] = FactFallingFn(SizeI - 1, M)*pSum;
    #end // for

    VV1N

#end // macro Hodograph_I_1N


#macro Hodograph_I_2N(Values_2N, M)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local CC = _HodographCoefficients(M);
    #local SizeI = dimension_size(Values_2N, 1);
    #local SizeJ = dimension_size(Values_2N, 2);
    #local NewSizeI = SizeI - M;
    #local VV2N = array[NewSizeI][SizeJ];
    #local p0 = 0*Values_2N[0][0];
    #for (J, 0, SizeJ - 1)
        #for (I, 0, NewSizeI - 1)
            #local pSum = p0;
            #for (A, 0, M)
                #local pSum =
                    pSum + CC[A]*Values_2N[I+A][J]
                ;
            #end // for
            #local VV2N[I][J] =
                FactFallingFn(SizeI - 1, M)*pSum
            ;
        #end // for
    #end // for

    VV2N

#end // macro Hodograph_I_2N


#macro Hodograph_J_2N(Values_2N, M)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local CC = _HodographCoefficients(M);
    #local SizeI = dimension_size(Values_2N, 1);
    #local SizeJ = dimension_size(Values_2N, 2);
    #local NewSizeJ = SizeJ - M;
    #local VV2N = array[SizeI][NewSizeJ];
    #local p0 = 0*Values_2N[0][0];
    #for (I, 0, SizeI - 1)
        #for (J, 0, NewSizeJ - 1)
            #local pSum = p0;
            #for (A, 0, M)
                #local pSum =
                    pSum + CC[A]*Values_2N[I][J+A]
                ;
            #end // for
            #local VV2N[I][J] =
                FactFallingFn(SizeJ - 1, M)*pSum
            ;
        #end // for
    #end // for

    VV2N

#end // macro Hodograph_J_2N


#macro Hodograph_I_3N(Values_3N, M)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local CC = _HodographCoefficients(M);
    #local SizeI = dimension_size(Values_3N, 1);
    #local SizeJ = dimension_size(Values_3N, 2);
    #local SizeK = dimension_size(Values_3N, 3);
    #local NewSizeI = SizeI - M;
    #local VV3N = array[NewSizeI][SizeJ][SizeK];
    #local p0 = 0*Values_3N[0][0][0];
    #for (K, 0, SizeK - 1)
        #for (J, 0, SizeJ - 1)
            #for (I, 0, NewSizeI - 1)
                #local pSum = p0;
                #for (A, 0, M)
                    #local pSum =
                        pSum + CC[A]*Values_3N[I+A][J][K]
                    ;
                #end // for
                #local VV3N[I][J][K] =
                    FactFallingFn(SizeI - 1, M)*pSum
                ;
            #end // for
        #end // for
    #end // for

    VV3N

#end // macro Hodograph_I_3N


#macro Hodograph_J_3N(Values_3N, M)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local CC = _HodographCoefficients(M);
    #local SizeI = dimension_size(Values_3N, 1);
    #local SizeJ = dimension_size(Values_3N, 2);
    #local SizeK = dimension_size(Values_3N, 3);
    #local NewSizeJ = SizeJ - M;
    #local VV3N = array[SizeI][NewSizeJ][SizeK];
    #local p0 = 0*Values_3N[0][0][0];
    #for (I, 0, SizeI - 1)
        #for (K, 0, SizeK - 1)
            #for (J, 0, NewSizeJ - 1)
                #local pSum = p0;
                #for (A, 0, M)
                    #local pSum =
                        pSum + CC[A]*Values_3N[I][J+A][K]
                    ;
                #end // for
                #local VV3N[I][J][K] =
                    FactFallingFn(SizeJ - 1, M)*pSum
                ;
            #end // for
        #end // for
    #end // for

    VV3N

#end // macro Hodograph_J_3N


#macro Hodograph_K_3N(Values_3N, M)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local CC = _HodographCoefficients(M);
    #local SizeI = dimension_size(Values_3N, 1);
    #local SizeJ = dimension_size(Values_3N, 2);
    #local SizeK = dimension_size(Values_3N, 3);
    #local NewSizeK = SizeK - M;
    #local VV3N = array[SizeI][SizeJ][NewSizeK];
    #local p0 = 0*Values_3N[0][0][0];
    #for (J, 0, SizeJ - 1)
        #for (I, 0, SizeI - 1)
            #for (K, 0, NewSizeK - 1)
                #local pSum = p0;
                #for (A, 0, M)
                    #local pSum =
                        pSum + CC[A]*Values_3N[I][J][K+A]
                    ;
                #end // for
                #local VV3N[I][J][K] =
                    FactFallingFn(SizeK - 1, M)*pSum
                ;
            #end // for
        #end // for
    #end // for

    VV3N

#end // macro Hodograph_K_3N


#macro Hodograph_I_4N(Values_4N, M)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local CC = _HodographCoefficients(M);
    #local SizeI = dimension_size(Values_4N, 1);
    #local SizeJ = dimension_size(Values_4N, 2);
    #local SizeK = dimension_size(Values_4N, 3);
    #local SizeL = dimension_size(Values_4N, 4);
    #local NewSizeI = SizeI - M;
    #local VV4N = array[NewSizeI][SizeJ][SizeK][SizeL];
    #local p0 = 0*Values_4N[0][0][0][0];
    #for (L, 0, SizeL - 1)
        #for (K, 0, SizeK - 1)
            #for (J, 0, SizeJ - 1)
                #for (I, 0, NewSizeI - 1)
                    #local pSum = p0;
                    #for (A, 0, M)
                        #local pSum =
                            pSum + CC[A]*Values_4N[I+A][J][K][L]
                        ;
                    #end // for
                    #local VV4N[I][J][K][L] =
                        FactFallingFn(SizeI - 1, M)*pSum
                    ;
                #end // for
            #end // for
        #end // for
    #end // for

    VV4N

#end // macro Hodograph_I_4N


#macro Hodograph_J_4N(Values_4N, M)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local CC = _HodographCoefficients(M);
    #local SizeI = dimension_size(Values_4N, 1);
    #local SizeJ = dimension_size(Values_4N, 2);
    #local SizeK = dimension_size(Values_4N, 3);
    #local SizeL = dimension_size(Values_4N, 4);
    #local NewSizeJ = SizeJ - M;
    #local VV4N = array[SizeI][NewSizeJ][SizeK][SizeL];
    #local p0 = 0*Values_4N[0][0][0][0];
    #for (I, 0, SizeI - 1)
        #for (L, 0, SizeL - 1)
            #for (K, 0, SizeK - 1)
                #for (J, 0, NewSizeJ - 1)
                    #local pSum = p0;
                    #for (A, 0, M)
                        #local pSum =
                            pSum + CC[A]*Values_4N[I][J+A][K][L]
                        ;
                    #end // for
                    #local VV4N[I][J][K][L] =
                        FactFallingFn(SizeJ - 1, M)*pSum
                    ;
                #end // for
            #end // for
        #end // for
    #end // for

    VV4N

#end // macro Hodograph_J_4N


#macro Hodograph_K_4N(Values_4N, M)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local CC = _HodographCoefficients(M);
    #local SizeI = dimension_size(Values_4N, 1);
    #local SizeJ = dimension_size(Values_4N, 2);
    #local SizeK = dimension_size(Values_4N, 3);
    #local SizeL = dimension_size(Values_4N, 4);
    #local NewSizeK = SizeK - M;
    #local VV4N = array[SizeI][SizeJ][NewSizeK][SizeL];
    #local p0 = 0*Values_4N[0][0][0][0];
    #for (J, 0, SizeJ - 1)
        #for (I, 0, SizeI - 1)
            #for (L, 0, SizeL - 1)
                #for (K, 0, NewSizeK - 1)
                    #local pSum = p0;
                    #for (A, 0, M)
                        #local pSum =
                            pSum + CC[A]*Values_4N[I][J][K+A][L]
                        ;
                    #end // for
                    #local VV4N[I][J][K][L] =
                        FactFallingFn(SizeK - 1, M)*pSum
                    ;
                #end // for
            #end // for
        #end // for
    #end // for

    VV4N

#end // macro Hodograph_K_4N


#macro Hodograph_L_4N(Values_4N, M)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local CC = _HodographCoefficients(M);
    #local SizeI = dimension_size(Values_4N, 1);
    #local SizeJ = dimension_size(Values_4N, 2);
    #local SizeK = dimension_size(Values_4N, 3);
    #local SizeL = dimension_size(Values_4N, 4);
    #local NewSizeL = SizeL - M;
    #local VV4N = array[SizeI][SizeJ][SizeK][NewSizeL];
    #local p0 = 0*Values_4N[0][0][0][0];
    #for (K, 0, SizeK - 1)
        #for (J, 0, SizeJ - 1)
            #for (I, 0, SizeI - 1)
                #for (L, 0, NewSizeL - 1)
                    #local pSum = p0;
                    #for (A, 0, M)
                        #local pSum =
                            pSum + CC[A]*Values_4N[I][J][K][L+A]
                        ;
                    #end // for
                    #local VV4N[I][J][K][L] =
                        FactFallingFn(SizeL - 1, M)*pSum
                    ;
                #end // for
            #end // for
        #end // for
    #end // for

    VV4N

#end // macro Hodograph_L_4N

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

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

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Der1_BezierFunctions(Values)

    #local N = dimensions(Values);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if

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
            #error "!"
    #end // switch

#end // macro Der1_BezierFunctions

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

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

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Der2_BezierFunctions(Values)

    #local N = dimensions(Values);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if

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
            #error "!"
    #end // switch

#end // macro Der2_BezierFunctions

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_1N_Der1U_RationalBezierFunction_1A(Values_1N, Weights_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Weights_1N) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Values_1N, 1) != dimension_size(Weights_1N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_1N, 1) < 2)
        #error "Is less than 2"
    #end // if
    #local VVWW1N =
        MultiplyArrays_1N(
            Values_1N, Weights_1N
        )
    ;

    Der1_RationalFunction_1A(
        From_1N_BezierFunction_1A(
            VVWW1N
        ),
        From_1N_BezierFunction_1A(
            Weights_1N
        ),
        From_1N_BezierFunction_1A(
            Hodograph_I_1N(
                VVWW1N, 1
            )
        ),
        From_1N_BezierFunction_1A(
            Hodograph_I_1N(
                Weights_1N, 1
            )
        )
    )

#end // macro From_1N_Der1U_RationalBezierFunction_1A


#macro Der1_RationalBezierFunctions_1A(Values_1N, Weights_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Weights_1N) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Values_1N, 1) != dimension_size(Weights_1N, 1))
        #error "Are not equal"
    #end // if

    Arr_1E(
        From_1N_Der1U_RationalBezierFunction_1A(
            Values_1N, Weights_1N
        )
    )

#end // macro Der1_RationalBezierFunctions_1A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_2N_Der1U_RationalBezierFunction_2A(Values_2N, Weights_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Values_2N, 1) != dimension_size(Weights_2N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_2N, 2) != dimension_size(Weights_2N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_2N, 1) < 2)
        #error "Is less than 2"
    #end // if
    #local VVWW2N =
        MultiplyArrays_2N(
            Values_2N, Weights_2N
        )
    ;

    Der1_RationalFunction_2A(
        From_2N_BezierFunction_2A(
            VVWW2N
        ),
        From_2N_BezierFunction_2A(
            Weights_2N
        ),
        From_2N_BezierFunction_2A(
            Hodograph_I_2N(
                VVWW2N, 1
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_I_2N(
                Weights_2N, 1
            )
        )
    )

#end // macro From_2N_Der1U_RationalBezierFunction_2A


#macro From_2N_Der1V_RationalBezierFunction_2A(Values_2N, Weights_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Values_2N, 1) != dimension_size(Weights_2N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_2N, 2) != dimension_size(Weights_2N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_2N, 2) < 2)
        #error "Is less than 2"
    #end // if
    #local VVWW2N =
        MultiplyArrays_2N(
            Values_2N, Weights_2N
        )
    ;

    Der1_RationalFunction_2A(
        From_2N_BezierFunction_2A(
            VVWW2N
        ),
        From_2N_BezierFunction_2A(
            Weights_2N
        ),
        From_2N_BezierFunction_2A(
            Hodograph_J_2N(
                VVWW2N, 1
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_J_2N(
                Weights_2N, 1
            )
        )
    )

#end // macro From_2N_Der1V_RationalBezierFunction_2A


#macro Der1_RationalBezierFunctions_2A(Values_2N, Weights_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Values_2N, 1) != dimension_size(Weights_2N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_2N, 2) != dimension_size(Weights_2N, 2))
        #error "Are not equal"
    #end // if

    Arr_2E(
        From_2N_Der1U_RationalBezierFunction_2A(
            Values_2N, Weights_2N
        ),
        From_2N_Der1V_RationalBezierFunction_2A(
            Values_2N, Weights_2N
        )
    )

#end // macro Der1_RationalBezierFunctions_2A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_3N_Der1U_RationalBezierFunction_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Values_3N, 1) != dimension_size(Weights_3N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 2) != dimension_size(Weights_3N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 3) != dimension_size(Weights_3N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 1) < 2)
        #error "Is less than 2"
    #end // if
    #local VVWW3N =
        MultiplyArrays_3N(
            Values_3N, Weights_3N
        )
    ;

    Der1_RationalFunction_3A(
        From_3N_BezierFunction_3A(
            VVWW3N
        ),
        From_3N_BezierFunction_3A(
            Weights_3N
        ),
        From_3N_BezierFunction_3A(
            Hodograph_I_3N(
                VVWW3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_I_3N(
                Weights_3N, 1
            )
        )
    )

#end // macro From_3N_Der1U_RationalBezierFunction_3A


#macro From_3N_Der1V_RationalBezierFunction_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Values_3N, 1) != dimension_size(Weights_3N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 2) != dimension_size(Weights_3N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 3) != dimension_size(Weights_3N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 2) < 2)
        #error "Is less than 2"
    #end // if
    #local VVWW3N =
        MultiplyArrays_3N(
            Values_3N, Weights_3N
        )
    ;

    Der1_RationalFunction_3A(
        From_3N_BezierFunction_3A(
            VVWW3N
        ),
        From_3N_BezierFunction_3A(
            Weights_3N
        ),
        From_3N_BezierFunction_3A(
            Hodograph_J_3N(
                VVWW3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_J_3N(
                Weights_3N, 1
            )
        )
    )

#end // macro From_3N_Der1V_RationalBezierFunction_3A


#macro From_3N_Der1W_RationalBezierFunction_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Values_3N, 1) != dimension_size(Weights_3N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 2) != dimension_size(Weights_3N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 3) != dimension_size(Weights_3N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 3) < 2)
        #error "Is less than 2"
    #end // if
    #local VVWW3N =
        MultiplyArrays_3N(
            Values_3N, Weights_3N
        )
    ;

    Der1_RationalFunction_3A(
        From_3N_BezierFunction_3A(
            VVWW3N
        ),
        From_3N_BezierFunction_3A(
            Weights_3N
        ),
        From_3N_BezierFunction_3A(
            Hodograph_K_3N(
                VVWW3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_K_3N(
                Weights_3N, 1
            )
        )
    )

#end // macro From_3N_Der1W_RationalBezierFunction_3A


#macro Der1_RationalBezierFunctions_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Values_3N, 1) != dimension_size(Weights_3N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 2) != dimension_size(Weights_3N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 3) != dimension_size(Weights_3N, 3))
        #error "Are not equal"
    #end // if

    Arr_3E(
        From_3N_Der1U_RationalBezierFunction_3A(
            Values_3N, Weights_3N
        ),
        From_3N_Der1V_RationalBezierFunction_3A(
            Values_3N, Weights_3N
        ),
        From_3N_Der1W_RationalBezierFunction_3A(
            Values_3N, Weights_3N
        )
    )

#end // macro Der1_RationalBezierFunctions_3A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_4N_Der1U_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Values_4N, 1) != dimension_size(Weights_4N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 2) != dimension_size(Weights_4N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 3) != dimension_size(Weights_4N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 4) != dimension_size(Weights_4N, 4))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 1) < 2)
        #error "Is less than 2"
    #end // if
    #local VVWW4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der1_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            VVWW4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_I_4N(
                VVWW4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_I_4N(
                Weights_4N, 1
            )
        )
    )

#end // macro From_4N_Der1U_RationalBezierFunction_4A


#macro From_4N_Der1V_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Values_4N, 1) != dimension_size(Weights_4N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 2) != dimension_size(Weights_4N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 3) != dimension_size(Weights_4N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 4) != dimension_size(Weights_4N, 4))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 2) < 2)
        #error "Is less than 2"
    #end // if
    #local VVWW4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der1_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            VVWW4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_J_4N(
                VVWW4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_J_4N(
                Weights_4N, 1
            )
        )
    )

#end // macro From_4N_Der1V_RationalBezierFunction_4A


#macro From_4N_Der1W_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Values_4N, 1) != dimension_size(Weights_4N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 2) != dimension_size(Weights_4N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 3) != dimension_size(Weights_4N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 4) != dimension_size(Weights_4N, 4))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 3) < 2)
        #error "Is less than 2"
    #end // if
    #local VVWW4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der1_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            VVWW4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_K_4N(
                VVWW4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_K_4N(
                Weights_4N, 1
            )
        )
    )

#end // macro From_4N_Der1W_RationalBezierFunction_4A


#macro From_4N_Der1S_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Values_4N, 1) != dimension_size(Weights_4N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 2) != dimension_size(Weights_4N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 3) != dimension_size(Weights_4N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 4) != dimension_size(Weights_4N, 4))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 4) < 2)
        #error "Is less than 2"
    #end // if
    #local VVWW4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der1_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            VVWW4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_L_4N(
                VVWW4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_L_4N(
                Weights_4N, 1
            )
        )
    )

#end // macro From_4N_Der1S_RationalBezierFunction_4A


#macro Der1_RationalBezierFunctions_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if

    Arr_4E(
        From_4N_Der1U_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        ),
        From_4N_Der1V_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        ),
        From_4N_Der1W_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        ),
        From_4N_Der1S_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        )
    )

#end // macro Der1_RationalBezierFunctions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Der1_RationalBezierFunctions(Values, Weights)

    #local N = dimensions(Values);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if
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
            #error "!"
    #end // switch

#end // macro Der1_RationalBezierFunctions

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_1N_Der2U_RationalBezierFunction_1A(Values_1N, Weights_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Weights_1N) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Values_1N, 1) != dimension_size(Weights_1N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_1N, 1) < 3)
        #error "Is less than 3"
    #end // if
    #local VVWW1N =
        MultiplyArrays_1N(
            Values_1N, Weights_1N
        )
    ;

    Der2_RationalFunction_1A(
        From_1N_BezierFunction_1A(
            VVWW1N
        ),
        From_1N_BezierFunction_1A(
            Weights_1N
        ),
        From_1N_BezierFunction_1A(
            Hodograph_I_1N(
                VVWW1N, 1
            )
        ),
        From_1N_BezierFunction_1A(
            Hodograph_I_1N(
                Weights_1N, 1
            )
        ),
        From_1N_BezierFunction_1A(
            Hodograph_I_1N(
                VVWW1N, 2
            )
        ),
        From_1N_BezierFunction_1A(
            Hodograph_I_1N(
                Weights_1N, 2
            )
        )
    )

#end // macro From_1N_Der2U_RationalBezierFunction_1A


#macro Der2_RationalBezierFunctions_1A(Values_1N, Weights_1N)

    #local N = dimensions(Values_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Weights_1N) != 1)
        #error "Is not 1"
    #end // if

    Arr_1E(
        From_1N_Der2U_RationalBezierFunction_1A(
            Values_1N, Weights_1N
        )
    )

#end // macro Der2_RationalBezierFunctions_1A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_2N_Der2U_RationalBezierFunction_2A(Values_2N, Weights_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Values_2N, 1) != dimension_size(Weights_2N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_2N, 2) != dimension_size(Weights_2N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_2N, 1) < 3)
        #error "Is less than 3"
    #end // if
    #local VVWW2N =
        MultiplyArrays_2N(
            Values_2N, Weights_2N
        )
    ;

    Der2_RationalFunction_2A(
        From_2N_BezierFunction_2A(
            VVWW2N
        ),
        From_2N_BezierFunction_2A(
            Weights_2N
        ),
        From_2N_BezierFunction_2A(
            Hodograph_I_2N(
                VVWW2N, 1
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_I_2N(
                Weights_2N, 1
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_I_2N(
                VVWW2N, 2
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_I_2N(
                Weights_2N, 2
            )
        )
    )

#end // macro From_2N_Der2U_RationalBezierFunction_2A


#macro From_2N_Der2V_RationalBezierFunction_2A(Values_2N, Weights_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != 2)
        #error "Is not 2"
    #end // if
    #if (dimension_size(Values_2N, 1) != dimension_size(Weights_2N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_2N, 2) != dimension_size(Weights_2N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_2N, 2) < 3)
        #error "Is less than 3"
    #end // if
    #local VVWW2N =
        MultiplyArrays_2N(
            Values_2N, Weights_2N
        )
    ;

    Der2_RationalFunction_2A(
        From_2N_BezierFunction_2A(
            VVWW2N
        ),
        From_2N_BezierFunction_2A(
            Weights_2N
        ),
        From_2N_BezierFunction_2A(
            Hodograph_J_2N(
                VVWW2N, 1
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_J_2N(
                Weights_2N, 1
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_J_2N(
                VVWW2N, 2
            )
        ),
        From_2N_BezierFunction_2A(
            Hodograph_J_2N(
                Weights_2N, 2
            )
        )
    )

#end // macro From_2N_Der2V_RationalBezierFunction_2A


#macro Der2_RationalBezierFunctions_2A(Values_2N, Weights_2N)

    #local N = dimensions(Values_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Weights_2N) != 2)
        #error "Is not 2"
    #end // if

    Arr_2E(
        From_2N_Der2U_RationalBezierFunction_2A(
            Values_2N, Weights_2N
        ),
        From_2N_Der2V_RationalBezierFunction_2A(
            Values_2N, Weights_2N
        )
    )

#end // macro Der2_RationalBezierFunctions_2A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_3N_Der2U_RationalBezierFunction_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Values_3N, 1) != dimension_size(Weights_3N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 2) != dimension_size(Weights_3N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 3) != dimension_size(Weights_3N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 1) < 3)
        #error "Is less than 3"
    #end // if
    #local VVWW3N =
        MultiplyArrays_3N(
            Values_3N, Weights_3N
        )
    ;

    Der2_RationalFunction_3A(
        From_3N_BezierFunction_3A(
            VVWW3N
        ),
        From_3N_BezierFunction_3A(
            Weights_3N
        ),
        From_3N_BezierFunction_3A(
            Hodograph_I_3N(
                VVWW3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_I_3N(
                Weights_3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_I_3N(
                VVWW3N, 2
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_I_3N(
                Weights_3N, 2
            )
        )
    )

#end // macro From_3N_Der2U_RationalBezierFunction_3A


#macro From_3N_Der2V_RationalBezierFunction_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Values_3N, 1) != dimension_size(Weights_3N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 2) != dimension_size(Weights_3N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 3) != dimension_size(Weights_3N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 2) < 3)
        #error "Is less than 3"
    #end // if
    #local VVWW3N =
        MultiplyArrays_3N(
            Values_3N, Weights_3N
        )
    ;

    Der2_RationalFunction_3A(
        From_3N_BezierFunction_3A(
            VVWW3N
        ),
        From_3N_BezierFunction_3A(
            Weights_3N
        ),
        From_3N_BezierFunction_3A(
            Hodograph_J_3N(
                VVWW3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_J_3N(
                Weights_3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_J_3N(
                VVWW3N, 2
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_J_3N(
                Weights_3N, 2
            )
        )
    )

#end // macro From_3N_Der2V_RationalBezierFunction_3A


#macro From_3N_Der2W_RationalBezierFunction_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if
    #if (dimension_size(Values_3N, 1) != dimension_size(Weights_3N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 2) != dimension_size(Weights_3N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 3) != dimension_size(Weights_3N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_3N, 3) < 3)
        #error "Is less than 3"
    #end // if
    #local VVWW3N =
        MultiplyArrays_3N(
            Values_3N, Weights_3N
        )
    ;

    Der2_RationalFunction_3A(
        From_3N_BezierFunction_3A(
            VVWW3N
        ),
        From_3N_BezierFunction_3A(
            Weights_3N
        ),
        From_3N_BezierFunction_3A(
            Hodograph_K_3N(
                VVWW3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_K_3N(
                Weights_3N, 1
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_K_3N(
                VVWW3N, 2
            )
        ),
        From_3N_BezierFunction_3A(
            Hodograph_K_3N(
                Weights_3N, 2
            )
        )
    )

#end // macro From_3N_Der2W_RationalBezierFunction_3A


#macro Der2_RationalBezierFunctions_3A(Values_3N, Weights_3N)

    #local N = dimensions(Values_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Weights_3N) != 3)
        #error "Is not 3"
    #end // if

    Arr_3E(
        From_3N_Der2U_RationalBezierFunction_3A(
            Values_3N, Weights_3N
        ),
        From_3N_Der2V_RationalBezierFunction_3A(
            Values_3N, Weights_3N
        ),
        From_3N_Der2W_RationalBezierFunction_3A(
            Values_3N, Weights_3N
        )
    )

#end // macro Der2_RationalBezierFunctions_3A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro From_4N_Der2U_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Values_4N, 1) != dimension_size(Weights_4N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 2) != dimension_size(Weights_4N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 3) != dimension_size(Weights_4N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 4) != dimension_size(Weights_4N, 4))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 1) < 3)
        #error "Is less than 3"
    #end // if
    #local VVWW4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der2_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            VVWW4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_I_4N(
                VVWW4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_I_4N(
                Weights_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_I_4N(
                VVWW4N, 2
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_I_4N(
                Weights_4N, 2
            )
        )
    )

#end // macro From_4N_Der2U_RationalBezierFunction_4A


#macro From_4N_Der2V_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Values_4N, 1) != dimension_size(Weights_4N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 2) != dimension_size(Weights_4N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 3) != dimension_size(Weights_4N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 4) != dimension_size(Weights_4N, 4))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 2) < 3)
        #error "Is less than 3"
    #end // if
    #local VVWW4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der2_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            VVWW4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_J_4N(
                VVWW4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_J_4N(
                Weights_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_J_4N(
                VVWW4N, 2
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_J_4N(
                Weights_4N, 2
            )
        )
    )

#end // macro From_4N_Der2V_RationalBezierFunction_4A


#macro From_4N_Der2W_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Values_4N, 1) != dimension_size(Weights_4N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 2) != dimension_size(Weights_4N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 3) != dimension_size(Weights_4N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 4) != dimension_size(Weights_4N, 4))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 3) < 3)
        #error "Is less than 3"
    #end // if
    #local VVWW4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der2_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            VVWW4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_K_4N(
                VVWW4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_K_4N(
                Weights_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_K_4N(
                VVWW4N, 2
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_K_4N(
                Weights_4N, 2
            )
        )
    )

#end // macro From_4N_Der2W_RationalBezierFunction_4A


#macro From_4N_Der2S_RationalBezierFunction_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if
    #if (dimension_size(Values_4N, 1) != dimension_size(Weights_4N, 1))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 2) != dimension_size(Weights_4N, 2))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 3) != dimension_size(Weights_4N, 3))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 4) != dimension_size(Weights_4N, 4))
        #error "Are not equal"
    #end // if
    #if (dimension_size(Values_4N, 4) < 3)
        #error "Is less than 3"
    #end // if
    #local VVWW4N =
        MultiplyArrays_4N(
            Values_4N, Weights_4N
        )
    ;

    Der2_RationalFunction_4A(
        From_4N_BezierFunction_4A(
            VVWW4N
        ),
        From_4N_BezierFunction_4A(
            Weights_4N
        ),
        From_4N_BezierFunction_4A(
            Hodograph_L_4N(
                VVWW4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_L_4N(
                Weights_4N, 1
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_L_4N(
                VVWW4N, 2
            )
        ),
        From_4N_BezierFunction_4A(
            Hodograph_L_4N(
                Weights_4N, 2
            )
        )
    )

#end // macro From_4N_Der2S_RationalBezierFunction_4A


#macro Der2_RationalBezierFunctions_4A(Values_4N, Weights_4N)

    #local N = dimensions(Values_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Weights_4N) != 4)
        #error "Is not 4"
    #end // if

    Arr_4E(
        From_4N_Der2U_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        ),
        From_4N_Der2V_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        ),
        From_4N_Der2W_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        ),
        From_4N_Der2S_RationalBezierFunction_4A(
            Values_4N, Weights_4N
        )
    )

#end // macro Der2_RationalBezierFunctions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Der2_RationalBezierFunctions(Values, Weights)

    #local N = dimensions(Values);
    #if (!((N = 1) | (N = 2) | (N = 3) | (N = 4)))
        #error "N is neither 1, 2, 3 nor 4"
    #end // if
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
            #error "!"
    #end // switch

#end // macro Der2_RationalBezierFunctions

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A
