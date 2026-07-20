// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B
/*

https://github.com/t-o-k/POV-Ray-bezier

Copyright (c) 2025-2026 Tor Olav Kristensen, http://subcube.com

Use of this source code is governed by the GNU Lesser General Public License version 3,
which can be found in the LICENSE file.

*/
// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#version 3.7;

#declare NIL = 1e-12; // Used to prevent division by zero in functions made by some macros 

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

#macro E_FundamentalFn(Array)

    Array[0]

#end // macro E_FundamentalFn


#macro F_FundamentalFn(Array)

    Array[1]

#end // macro F_FundamentalFn


#macro G_FundamentalFn(Array)

    Array[2]

#end // macro G_FundamentalFn


#macro L_FundamentalFn(Array)

    Array[0]

#end // L_FundamentalFn


#macro M_FundamentalFn(Array)

    Array[1]

#end // M_FundamentalFn


#macro N_FundamentalFn(Array)

    Array[2]

#end // N_FundamentalFn

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#declare _NoNegativeZeroFn =
    function(_a) { select(_a, _a, 0, _a) }
;

#declare AvoidZeroFn =
    function(_a) {
        select(
            _a,
            min(_a, -NIL),
            +NIL,
            max(+NIL, _a)
        )
    }
;

// To avoid unnecessary parse warnings about zero power
#declare PowFn =
    function(_b, _n) { pow(_b, _n) }
;

#declare FactFn =
    function(_n) {
        select(
            _n,
            0,
            prod(_i, 1, _n, _i)
        )
    }
;

#declare FactFallingFn =
    function(_n, _k) {
        select(
            _k,
            0,
            select(
                _n,
                _NoNegativeZeroFn(
                    prod(_i, _n - _k + 1, _n, _i)
                ), 
                select(
                    _n - _k,
                    0,
                    _NoNegativeZeroFn(
                        prod(_i, _n - _k + 1, _n, _i)
                    )
                )
            )
        )
    }
;
#declare FactRisingFn =
    function(_n, _k) {
        select(
            _k,
            0,
            select(
                _n,
                select(
                    _n + _k - 1, 
                    _NoNegativeZeroFn(
                        prod(_i, _n, _n + _k - 1, _i)
                    ),
                    0
                ),
                _NoNegativeZeroFn(
                    prod(_i, _n, _n + _k - 1, _i)
                )
            )
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
            _k,
            0,
            select(
                _n - _k,
                0,
                select(
                    _n - 2*_k,
                    FactFallingFn(_n, _n - _k)/FactFn(_n - _k),
                    FactFallingFn(_n, _k)/FactFn(_k)
                )
            )
        )
    }
;

#declare BinomialFn =
    function(_n, _k) {
        select(
            _k,
            0,
            select(
                _n - _k,
                0,
                select(
                    _n - 2*_k,
                    FactFallingFn(_n, _n - _k)/FactFn(_n - _k),
                    FactFallingFn(_n, _k)/FactFn(_k)
                )
            )
        )
    }
;

#declare _BernsteinCoefficientFn =
    function(_n, _r, _p) {
        PowFn(-1, _p - _r)*CombFn(_n, _p)*CombFn(_p, _r)
    }
;


/*
Inefficient and numerically unstable version

#macro BernsteinFunction_1A(N, R)

    function(_t) {
        sum(
            _p, R, N,
            _BernsteinCoefficientFn(N, R, _p)
            *
            PowFn(_t, _p)
        )
    }

#end // macro BernsteinFunction_1A
*/


/*
Inefficient and numerically unstable version

#macro BernsteinFunction_1A(N, R)

    #local C = BinomialFn(N, R);
    #local M = N - R;

    function(_t) { C*PowFn(_t, R)*PowFn(1 - _t, M) }

#end // macro BernsteinFunction_1A
*/


/*
Numerically unstable version

#macro BernsteinFunction_1A(N, R)

    function(_t) {
        0.0
        #for (P, R, N)
            #local C = _BernsteinCoefficientFn(N, R, P);
            + C*PowFn(_t, P)
        #end // for
    }

#end // macro BernsteinFunction_1A
*/


#macro _HornerRecurse(Coefficients, I)

    #if (I > 0)
        (_HornerRecurse(Coefficients, I - 1)*_t + Coefficients[I])
    #else
        Coefficients[0]
    #end // if

#end // macro _HornerRecurse


#macro HornerPolynomialFunction_1A(Coefficients)

    #local Size = dimension_size(Coefficients, 1);

    function(_t) {
        _HornerRecurse(Coefficients, Size - 1)
    }

#end // macro HornerPolynomialFunction_1A


#macro BernsteinFunction_1A(N, R)

    #if (R < 0)
        #error "Polynomial index R cannot be negative."
    #end // if
    #if (R > N)
        #error "Polynomial index R cannot exceed degree N."
    #end // if

    #local Size = N + 1;
    #local Coeffs = array[Size];
    #for (I, 0, N - R)
        #local P = N - I; 
        #local Coeffs[I] = _BernsteinCoefficientFn(N, R, P);
    #end // for
    #for (I, N - R + 1, N)
        #local Coeffs[I] = 0.0;
    #end // for

    HornerPolynomialFunction_1A(Coeffs)

#end // macro BernsteinFunction_1A


#macro DerBernsteinFunction_1A(N, R, D)

    #if (R < 0)
        #error "Polynomial index R cannot be negative."
    #end // if
    #if (R > N)
        #error "Polynomial index R cannot exceed degree N."
    #end // if
    #if (D < 0)
        #error "Derivation order D cannot be negative."
    #end // if

    #local S = max(R, D);
    #if (S > N)
        #local Coeffs = array[1] { 0.0 };
    #else
        #local Size = N - D + 1;
        #local Coeffs = array[Size];
        #for (I, 0, N - S)
            #local P = N - I; 
            #local C = _BernsteinCoefficientFn(N, R, P);
            #local Coeffs[I] = C*FactFallingFn(P, D);
        #end // for
        #for (I, N - S + 1, N - D)
            #local Coeffs[I] = 0.0;
        #end // for
    #end // if

    HornerPolynomialFunction_1A(Coeffs)

#end // macro DerBernsteinFunction_1A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#declare DotFn =
    function(_x0, _y0, _z0, _x1, _y1, _z1) {
        _x0*_x1 + _y0*_y1 + _z0*_z1
    }
;

#declare CrossFnX =
    function(_x0, _y0, _z0, _x1, _y1, _z1) {
        _y0*_z1 - _z0*_y1
    }
;
#declare CrossFnY =
    function(_x0, _y0, _z0, _x1, _y1, _z1) {
        _z0*_x1 - _x0*_z1
    }
;
#declare CrossFnZ =
    function(_x0, _y0, _z0, _x1, _y1, _z1) {
        _x0*_y1 - _y0*_x1
    }
;

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro MinFunction_Constant_1A(_Fn_1A, Const)

    function(_u) { min(_Fn_1A(_u), Const) }

#end // macro MinFunction_Constant_1A


#macro MinFunction_Constant_2A(_Fn_2A, Const)

    function(_u, _v) { min(_Fn_2A(_u, _v), Const) }

#end // macro MinFunction_Constant_2A


#macro MinFunction_Constant_3A(_Fn_3A, Const)

    function(_u, _v, _w) { min(_Fn_3A(_u, _v, _w), Const) }

#end // macro MinFunction_Constant_3A


#macro MinFunction_Constant_4A(_Fn_4A, Const)

    function(_u, _v, _w, _s) { min(_Fn_4A(_u, _v, _w, _s), Const) }

#end // macro MinFunction_Constant_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro MaxFunction_Constant_1A(_Fn_1A, Const)

    function(_u) { max(_Fn_1A(_u), Const) }

#end // macro MaxFunction_Constant_1A


#macro MaxFunction_Constant_2A(_Fn_2A, Const)

    function(_u, _v) { max(_Fn_2A(_u, _v), Const) }

#end // macro MaxFunction_Constant_2A


#macro MaxFunction_Constant_3A(_Fn_3A, Const)

    function(_u, _v, _w) { max(_Fn_3A(_u, _v, _w), Const) }

#end // macro MaxFunction_Constant_3A


#macro MaxFunction_Constant_4A(_Fn_4A, Const)

    function(_u, _v, _w, _s) { max(_Fn_4A(_u, _v, _w, _s), Const) }

#end // macro MaxFunction_Constant_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro MultiplyFunction_Constant_1A(_Fn_1A, Const)

    function(_u) {
        _Fn_1A(_u)
        *
        Const
    }

#end // macro MultiplyFunction_Constant_1A


#macro MultiplyFunction_Constant_2A(_Fn_2A, Const)

    function(_u, _v) {
        _Fn_2A(_u, _v)
        *
        Const
    }

#end // macro MultiplyFunction_Constant_2A


#macro MultiplyFunction_Constant_3A(_Fn_3A, Const)

    function(_u, _v, _w) {
        _Fn_3A(_u, _v, _w)
        *
        Const
    }

#end // macro MultiplyFunction_Constant_3A


#macro MultiplyFunction_Constant_4A(_Fn_4A, Const)

    function(_u, _v, _w, _s) {
        _Fn_4A(_u, _v, _w, _s)
        *
        Const
    }

#end // macro MultiplyFunction_Constant_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro DivideFunction_Constant_1A(_Fn_1A, Const)

    #if (Const = 0.0)
        #error "Const is zero"
    #end
    function(_u) {
        _Fn_1A(_u)
        /
        Const
    }

#end // macro DivideFunction_Constant_1A


#macro DivideFunction_Constant_2A(_Fn_2A, Const)

    #if (Const = 0.0)
        #error "Const is zero"
    #end
    function(_u, _v) {
        _Fn_2A(_u, _v)
        /
        Const
    }

#end // macro DivideFunction_Constant_2A


#macro DivideFunction_Constant_3A(_Fn_3A, Const)

    #if (Const = 0.0)
        #error "Const is zero"
    #end
    function(_u, _v, _w) {
        _Fn_3A(_u, _v, _w)
        /
        Const
    }

#end // macro DivideFunction_Constant_3A


#macro DivideFunction_Constant_4A(_Fn_4A, Const)

    #if (Const = 0.0)
        #error "Const is zero"
    #end
    function(_u, _v, _w, _s) {
        _Fn_4A(_u, _v, _w, _s)
        /
        Const
    }

#end // macro DivideFunction_Constant_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro PowFunction_Constant_1A(_Fn_1A, Const)

    function(_u) {
        PowFn(_Fn_1A(_u), Const)
    }

#end // macro PowFunction_Constant_1A


#macro PowFunction_Constant_2A(_Fn_2A, Const)

    function(_u, _v) {
        PowFn(_Fn_2A(_u, _v), Const)
    }

#end // macro PowFunction_Constant_2A


#macro PowFunction_Constant_3A(_Fn_3A, Const)

    function(_u, _v, _w) {
        PowFn(_Fn_3A(_u, _v, _w), Const)
    }

#end // macro PowFunction_Constant_3A


#macro PowFunction_Constant_4A(_Fn_4A, Const)

    function(_u, _v, _w, _s) {
        PowFn(_Fn_4A(_u, _v, _w, _s), Const)
    }

#end // macro PowFunction_Constant_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro SqrtFunction_1A(_Fn_1A)

    PowFunction_Constant_1A(_Fn_1A, 0.5)

#end // macro SqrtFunction_1A


#macro SqrtFunction_2A(_Fn_2A)

    PowFunction_Constant_2A(_Fn_2A, 0.5)

#end // macro SqrtFunction_2A


#macro SqrtFunction_3A(_Fn_3A)

    PowFunction_Constant_3A(_Fn_3A, 0.5)

#end // macro SqrtFunction_3A


#macro SqrtFunction_4A(_Fn_4A)

    PowFunction_Constant_4A(_Fn_4A, 0.5)

#end // macro SqrtFunction_4A


#macro Sqrt_Safe_Function_1A(_Fn_1A)

    PowFunction_Constant_1A(
        MaxFunction_Constant_1A(
            _Fn_1A,
            0.0
        ),
        0.5
    )

#end // macro Sqrt_Safe_Function_1A


#macro Sqrt_Safe_Function_2A(_Fn_2A)

    PowFunction_Constant_2A(
        MaxFunction_Constant_2A(
            _Fn_2A,
            0.0
        ),
        0.5
    )

#end // macro Sqrt_Safe_Function_2A


#macro Sqrt_Safe_Function_3A(_Fn_3A)

    PowFunction_Constant_3A(
        MaxFunction_Constant_3A(
            _Fn_3A,
            0.0
        ),
        0.5
    )

#end // macro Sqrt_Safe_Function_3A


#macro Sqrt_Safe_Function_4A(_Fn_4A)

    PowFunction_Constant_4A(
        MaxFunction_Constant_4A(
            _Fn_4A,
            0.0
        ),
        0.5
    )

#end // macro Sqrt_Safe_Function_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro SqFunction_1A(_Fn_1A)

    PowFunction_Constant_1A(_Fn_1A, 2)

#end // macro SqFunction_1A


#macro SqFunction_2A(_Fn_2A)

    PowFunction_Constant_2A(_Fn_2A, 2)

#end // macro SqFunction_2A


#macro SqFunction_3A(_Fn_3A)

    PowFunction_Constant_3A(_Fn_3A, 2)

#end // macro SqFunction_3A


#macro SqFunction_4A(_Fn_4A)

    PowFunction_Constant_4A(_Fn_4A, 2)

#end // macro SqFunction_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro SubtractFunction_1A(_Fn0_1A, _Fn1_1A)

    function(_u) {
        _Fn0_1A(_u)
        -
        _Fn1_1A(_u)
    }

#end // macro SubtractFunction_1A


#macro SubtractFunction_2A(_Fn0_2A, _Fn1_2A)

    function(_u, _v) {
        _Fn0_2A(_u, _v)
        -
        _Fn1_2A(_u, _v)
    }

#end // macro SubtractFunction_2A


#macro SubtractFunction_3A(_Fn0_3A, _Fn1_3A)

    function(_u, _v, _w) {
        _Fn0_3A(_u, _v, _w)
        -
        _Fn1_3A(_u, _v, _w)
    }

#end // macro SubtractFunction_3A


#macro SubtractFunction_4A(_Fn0_4A, _Fn1_4A)

    function(_u, _v, _w, _s) {
        _Fn0_4A(_u, _v, _w, _s)
        -
        _Fn1_4A(_u, _v, _w, _s)
    }

#end // macro SubtractFunction_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro AddFunction_1A(_Fn0_1A, _Fn1_1A)

    function(_u) {
        _Fn0_1A(_u)
        +
        _Fn1_1A(_u)
    }

#end // macro AddFunction_1A


#macro AddFunction_2A(_Fn0_2A, _Fn1_2A)

    function(_u, _v) {
        _Fn0_2A(_u, _v)
        +
        _Fn1_2A(_u, _v)
    }

#end // macro AddFunction_2A


#macro AddFunction_3A(_Fn0_3A, _Fn1_3A)

    function(_u, _v, _w) {
        _Fn0_3A(_u, _v, _w)
        +
        _Fn1_3A(_u, _v, _w)
    }

#end // macro AddFunction_3A


#macro AddFunction_4A(_Fn0_4A, _Fn1_4A)

    function(_u, _v, _w, _s) {
        _Fn0_4A(_u, _v, _w, _s)
        +
        _Fn1_4A(_u, _v, _w, _s)
    }

#end // macro AddFunction_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro MultiplyFunction_1A(_Fn0_1A, _Fn1_1A)

    function(_u) {
        _Fn0_1A(_u)
        *
        _Fn1_1A(_u)
    }

#end // macro MultiplyFunction_1A


#macro MultiplyFunction_2A(_Fn0_2A, _Fn1_2A)

    function(_u, _v) {
        _Fn0_2A(_u, _v)
        *
        _Fn1_2A(_u, _v)
    }

#end // macro MultiplyFunction_2A


#macro MultiplyFunction_3A(_Fn0_3A, _Fn1_3A)

    function(_u, _v, _w) {
        _Fn0_3A(_u, _v, _w)
        *
        _Fn1_3A(_u, _v, _w)
    }

#end // macro MultiplyFunction_3A


#macro MultiplyFunction_4A(_Fn0_4A, _Fn1_4A)

    function(_u, _v, _w, _s) {
        _Fn0_4A(_u, _v, _w, _s)
        *
        _Fn1_4A(_u, _v, _w, _s)
    }

#end // macro MultiplyFunction_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro DivideFunction_1A(_Num_Fn_1A, _Den_Fn_1A)

    function(_u) {
        _Num_Fn_1A(_u)
        /
        _Den_Fn_1A(_u)
    }

#end // macro DivideFunction_1A


#macro DivideFunction_2A(_Num_Fn_2A, _Den_Fn_2A)

    function(_u, _v) {
        _Num_Fn_2A(_u, _v)
        /
        _Den_Fn_2A(_u, _v)
    }

#end // macro DivideFunction_2A


#macro DivideFunction_3A(_Num_Fn_3A, _Den_Fn_3A)

    function(_u, _v, _w) {
        _Num_Fn_3A(_u, _v, _w)
        /
        _Den_Fn_3A(_u, _v, _w)
    }

#end // macro DivideFunction_3A


#macro DivideFunction_4A(_Num_Fn_4A, _Den_Fn_4A)

    function(_u, _v, _w, _s) {
        _Num_Fn_4A(_u, _v, _w, _s)
        /
        _Den_Fn_4A(_u, _v, _w, _s)
    }

#end // macro DivideFunction_4A


#macro DivideFunction_Safe_1A(_Num_Fn_1A, _Den_Fn_1A)

    function(_u) {
        _Num_Fn_1A(_u)
        /
        AvoidZeroFn(
            _Den_Fn_1A(_u)
        )
    }

#end // macro DivideFunction_Safe_1A


#macro DivideFunction_Safe_2A(_Num_Fn_2A, _Den_Fn_2A)

    function(_u, _v) {
        _Num_Fn_2A(_u, _v)
        /
        AvoidZeroFn(
            _Den_Fn_2A(_u, _v)
        )
    }

#end // macro DivideFunction_Safe_2A


#macro DivideFunction_Safe_3A(_Num_Fn_3A, _Den_Fn_3A)

    function(_u, _v, _w) {
        _Num_Fn_3A(_u, _v, _w)
        /
        AvoidZeroFn(
            _Den_Fn_3A(_u, _v, _w)
        )
    }

#end // macro DivideFunction_Safe_3A


#macro DivideFunction_Safe_4A(_Num_Fn_4A, _Den_Fn_4A)

    function(_u, _v, _w, _s) {
        _Num_Fn_4A(_u, _v, _w, _s)
        /
        AvoidZeroFn(
            _Den_Fn_4A(_u, _v, _w, _s)
        )
    }

#end // macro DivideFunction_Safe_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro _QuadraticRootsFunctions_1A(B_Fn_1A, SqrtDiscr_Fn_1A, Num_Fn_1A)

    Arr_2E(
        DivideFunction_Safe_1A(
            AddFunction_1A(
                B_Fn_1A,
                SqrtDiscr_Fn_1A
            ),
            Num_Fn_1A
        ),
        DivideFunction_Safe_1A(
            SubtractFunction_1A(
                B_Fn_1A,
                SqrtDiscr_Fn_1A
            ),
            Num_Fn_1A
        )
    )

#end // macro _QuadraticRootsFunctions_1A


#macro QuadraticRootsFunctions_1A(A_Fn_1A, B_Fn_1A, C_Fn_1A)

    _QuadraticRootsFunctions_1A(
        B_Fn_1A,
        Sqrt_Safe_Function_1A(
            SubtractFunction_1A(
                SqFunction_1A(
                    B_Fn_1A
                ),
                MultiplyFunction_Constant_1A(
                    MultiplyFunction_1A(
                        A_Fn_1A,
                        C_Fn_1A
                    ),
                    4
                )
            )
        ),
        MultiplyFunction_Constant_1A(
            A_Fn_1A,
            2
        )
    )

#end // macro QuadraticRootsFunctions_1A


#macro _QuadraticRootsFunctions_2A(B_Fn_2A, SqrtDiscr_Fn_2A, Num_Fn_2A)

    Arr_2E(
        DivideFunction_Safe_2A(
            AddFunction_2A(
                B_Fn_2A,
                SqrtDiscr_Fn_2A
            ),
            Num_Fn_2A
        ),
        DivideFunction_Safe_2A(
            SubtractFunction_2A(
                B_Fn_2A,
                SqrtDiscr_Fn_2A
            ),
            Num_Fn_2A
        )
    )

#end // macro _QuadraticRootsFunctions_2A


#macro QuadraticRootsFunctions_2A(A_Fn_2A, B_Fn_2A, C_Fn_2A)

    _QuadraticRootsFunctions_2A(
        B_Fn_2A,
        Sqrt_Safe_Function_2A(
            SubtractFunction_2A(
                SqFunction_2A(
                    B_Fn_2A
                ),
                MultiplyFunction_Constant_2A(
                    MultiplyFunction_2A(
                        A_Fn_2A,
                        C_Fn_2A
                    ),
                    4
                )
            )
        ),
        MultiplyFunction_Constant_2A(
            A_Fn_2A,
            2
        )
    )

#end // macro QuadraticRootsFunctions_2A


#macro _QuadraticRootsFunctions_3A(B_Fn_3A, SqrtDiscr_Fn_3A, Num_Fn_3A)

    Arr_2E(
        DivideFunction_Safe_3A(
            AddFunction_3A(
                B_Fn_3A,
                SqrtDiscr_Fn_3A
            ),
            Num_Fn_3A
        ),
        DivideFunction_Safe_3A(
            SubtractFunction_3A(
                B_Fn_3A,
                SqrtDiscr_Fn_3A
            ),
            Num_Fn_3A
        )
    )

#end // macro _QuadraticRootsFunctions_3A


#macro QuadraticRootsFunctions_3A(A_Fn_3A, B_Fn_3A, C_Fn_3A)

    _QuadraticRootsFunctions_3A(
        B_Fn_3A,
        Sqrt_Safe_Function_3A(
            SubtractFunction_3A(
                SqFunction_3A(
                    B_Fn_3A
                ),
                MultiplyFunction_Constant_3A(
                    MultiplyFunction_3A(
                        A_Fn_3A,
                        C_Fn_3A
                    ),
                    4
                )
            )
        ),
        MultiplyFunction_Constant_3A(
            A_Fn_3A,
            2
        )
    )

#end // macro QuadraticRootsFunctions_3A


#macro _QuadraticRootsFunctions_4A(B_Fn_4A, SqrtDiscr_Fn_4A, Num_Fn_4A)

    Arr_2E(
        DivideFunction_Safe_4A(
            AddFunction_4A(
                B_Fn_4A,
                SqrtDiscr_Fn_4A
            ),
            Num_Fn_4A
        ),
        DivideFunction_Safe_4A(
            SubtractFunction_4A(
                B_Fn_4A,
                SqrtDiscr_Fn_4A
            ),
            Num_Fn_4A
        )
    )

#end // macro _QuadraticRootsFunctions_4A


#macro QuadraticRootsFunctions_4A(A_Fn_4A, B_Fn_4A, C_Fn_4A)

    _QuadraticRootsFunctions_4A(
        B_Fn_4A,
        Sqrt_Safe_Function_4A(
            SubtractFunction_4A(
                SqFunction_4A(
                    B_Fn_4A
                ),
                MultiplyFunction_Constant_4A(
                    MultiplyFunction_4A(
                        A_Fn_4A,
                        C_Fn_4A
                    ),
                    4
                )
            )
        ),
        MultiplyFunction_Constant_4A(
            A_Fn_4A,
            2
        )
    )

#end // macro QuadraticRootsFunctions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro WeightedFunction_1A(_U_Fns_1A_1N, Weights_1N)

    #local M = dimensions(_U_Fns_1A_1N);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local N = dimensions(Weights_1N);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(Weights_1N, 1);
    #if (dimension_size(_U_Fns_1A_1N, 1) != SizeI)
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
                    - _U_Fns_1A_1N[I](_u)
                    #break
                #case (+1.0)
                    + _U_Fns_1A_1N[I](_u)
                    #break
                #else
                    + Q*_U_Fns_1A_1N[I](_u)
            #end // switch
        #end // for
    }

#end // macro WeightedFunction_1A


#macro WeightedFunction_2A(_U_Fns_1A_1N, _V_Fns_1A_1N, Weights_2N)

    #local M =
        max(
            dimensions(_U_Fns_1A_1N),
            dimensions(_V_Fns_1A_1N)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local N = dimensions(Weights_2N);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(Weights_2N, 1);
    #local SizeJ = dimension_size(Weights_2N, 2);
    #if (dimension_size(_U_Fns_1A_1N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #if (dimension_size(_V_Fns_1A_1N, 1) != SizeJ)
        #error "Is not equal to SizeJ"
    #end // if
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;

    function(_u, _v) {
        0.0
        #for (J, 0, LastJ)
            + _V_Fns_1A_1N[J](_v)*
            (
                0.0
                #for (I, 0, LastI)
                    #local Q = Weights_2N[I][J];
                    #switch (Q)
                        #case (0.0)
                            #break
                        #case (-1.0)
                            - _U_Fns_1A_1N[I](_u)
                            #break
                        #case (+1.0)
                            + _U_Fns_1A_1N[I](_u)
                            #break
                        #else
                            + Q*_U_Fns_1A_1N[I](_u)
                    #end // switch
                #end // for
            )
        #end // for
    }

#end // macro WeightedFunction_2A


#macro WeightedFunction_3A(_U_Fns_1A_1N, _V_Fns_1A_1N, _W_Fns_1A_1N, Weights_3N)

    #local M =
        max(
            dimensions(_U_Fns_1A_1N),
            dimensions(_V_Fns_1A_1N),
            dimensions(_W_Fns_1A_1N)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local N = dimensions(Weights_3N);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(Weights_3N, 1);
    #local SizeJ = dimension_size(Weights_3N, 2);
    #local SizeK = dimension_size(Weights_3N, 3);
    #if (dimension_size(_U_Fns_1A_1N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #if (dimension_size(_V_Fns_1A_1N, 1) != SizeJ)
        #error "Is not equal to SizeJ"
    #end // if
    #if (dimension_size(_W_Fns_1A_1N, 1) != SizeK)
        #error "Is not equal to SizeK"
    #end // if
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;

    function(_u, _v, _w) {
        0.0
        #for (K, 0, LastK)
            + _W_Fns_1A_1N[K](_w)*
            (
                0.0
                #for (J, 0, LastJ)
                    + _V_Fns_1A_1N[J](_v)*
                    (
                        0.0
                        #for (I, 0, LastI)
                            #local Q = Weights_3N[I][J][K];
                            #switch (Q)
                                #case (0.0)
                                    #break
                                #case (-1.0)
                                    - _U_Fns_1A_1N[I](_u)
                                    #break
                                #case (+1.0)
                                    + _U_Fns_1A_1N[I](_u)
                                    #break
                                #else
                                    + Q*_U_Fns_1A_1N[I](_u)
                            #end // switch
                        #end // for
                    )
                #end // for
            )
        #end // for
    }

#end // macro WeightedFunction_3A


#macro WeightedFunction_4A(_U_Fns_1A_1N, _V_Fns_1A_1N, _W_Fns_1A_1N, _S_Fns_1A_1N, Weights_4N)

    #local M =
        max(
            dimensions(_U_Fns_1A_1N),
            dimensions(_V_Fns_1A_1N),
            dimensions(_W_Fns_1A_1N),
            dimensions(_S_Fns_1A_1N)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local N = dimensions(Weights_4N);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Weights_4N, 1);
    #local SizeJ = dimension_size(Weights_4N, 2);
    #local SizeK = dimension_size(Weights_4N, 3);
    #local SizeL = dimension_size(Weights_4N, 4);
    #if (dimension_size(_U_Fns_1A_1N, 1) != SizeI)
        #error "Is not equal to SizeI"
    #end // if
    #if (dimension_size(_V_Fns_1A_1N, 1) != SizeJ)
        #error "Is not equal to SizeJ"
    #end // if
    #if (dimension_size(_W_Fns_1A_1N, 1) != SizeK)
        #error "Is not equal to SizeK"
    #end // if
    #if (dimension_size(_S_Fns_1A_1N, 1) != SizeL)
        #error "Is not equal to SizeL"
    #end // if
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;
    #local LastL = SizeL - 1;

    function(_u, _v, _w, _s) {
        0.0
        #for (L, 0, LastL)
            + _S_Fns_1A_1N[L](_s)*
            (
                0.0
                #for (K, 0, LastK)
                    + _W_Fns_1A_1N[K](_w)*
                    (
                        0.0
                        #for (J, 0, LastJ)
                            + _V_Fns_1A_1N[J](_v)*
                            (
                                0.0
                                #for (I, 0, LastI)
                                    #local Q = Weights_4N[I][J][K][L];
                                    #switch (Q)
                                        #case (0.0)
                                            #break
                                        #case (-1.0)
                                            - _U_Fns_1A_1N[I](_u)
                                            #break
                                        #case (+1.0)
                                            + _U_Fns_1A_1N[I](_u)
                                            #break
                                        #else
                                            + Q*_U_Fns_1A_1N[I](_u)
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

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro LengthFunction_1A_1D(_Fns_1A_1D)

    #local M = dimensions(_Fns_1A_1D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_1A_1D, 1);
    #if (D != 1)
        #error "D is not 1"
    #end // if

    function(_u) {
        abs(
            x_E(_Fns_1A_1D)(_u)
        )
    }

#end // LengthFunction_1A_1D


#macro LengthFunction_1A_2D(_Fns_1A_2D)

    #local M = dimensions(_Fns_1A_2D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_1A_2D, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if

    function(_u) {
        f_r(
            x_E(_Fns_1A_2D)(_u),
            y_E(_Fns_1A_2D)(_u),
            0.0
        )
    }

#end // LengthFunction_1A_2D


#macro LengthFunction_1A_3D(_Fns_1A_3D)

    #local M = dimensions(_Fns_1A_3D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_1A_3D, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if

    function(_u) {
        f_r(
            x_E(_Fns_1A_3D)(_u),
            y_E(_Fns_1A_3D)(_u),
            z_E(_Fns_1A_3D)(_u)
        )
    }

#end // LengthFunction_1A_3D


#macro LengthFunction_1A_4D(_Fns_1A_4D)

    #local M = dimensions(_Fns_1A_4D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_1A_4D, 1);
    #if (D != 4)
        #error "D is not 4"
    #end // if

    function(_u) {
        sqrt(
            pow(x_E(_Fns_1A_4D)(_u), 2)
            +
            pow(y_E(_Fns_1A_4D)(_u), 2)
            +
            pow(z_E(_Fns_1A_4D)(_u), 2)
            +
            pow(t_E(_Fns_1A_4D)(_u), 2)
        )
    }

#end // LengthFunction_1A_4D


#macro LengthFunction_1A(_Fns_1A)

    #local M = dimensions(_Fns_1A);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_1A, 1);

    #switch (D)
        #case (1)
            LengthFunction_1A_1D(
                _Fns_1A
            )
            #break
        #case (2)
            LengthFunction_1A_2D(
                _Fns_1A
            )
            #break
        #case (3)
            LengthFunction_1A_3D(
                _Fns_1A
            )
            #break
        #case (4)
            LengthFunction_1A_4D(
                _Fns_1A
            )
            #break
        #else
            #error "D is neither 1, 2, 3 nor 4"
    #end // switch

#end // LengthFunction_1A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro LengthFunction_2A_1D(_Fns_2A_1D)

    #local M = dimensions(_Fns_2A_1D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_2A_1D, 1);
    #if (D != 1)
        #error "D is not 1"
    #end // if

    function(_u, _v) {
        abs(
            x_E(_Fns_2A_1D)(_u, _v)
        )
    }

#end // LengthFunction_2A_1D


#macro LengthFunction_2A_2D(_Fns_2A_2D)

    #local M = dimensions(_Fns_2A_2D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_2A_2D, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if

    function(_u, _v) {
        f_r(
            x_E(_Fns_2A_2D)(_u, _v),
            y_E(_Fns_2A_2D)(_u, _v),
            0.0
        )
    }

#end // LengthFunction_2A_2D


#macro LengthFunction_2A_3D(_Fns_2A_3D)

    #local M = dimensions(_Fns_2A_3D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_2A_3D, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if

    function(_u, _v) {
        f_r(
            x_E(_Fns_2A_3D)(_u, _v),
            y_E(_Fns_2A_3D)(_u, _v),
            z_E(_Fns_2A_3D)(_u, _v)
        )
    }

#end // LengthFunction_2A_3D


#macro LengthFunction_2A_4D(_Fns_2A_4D)

    #local M = dimensions(_Fns_2A_4D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_2A_4D, 1);
    #if (D != 4)
        #error "D is not 4"
    #end // if

    function(_u, _v) {
        sqrt(
            pow(x_E(_Fns_2A_4D)(_u, _v), 2)
            +
            pow(y_E(_Fns_2A_4D)(_u, _v), 2)
            +
            pow(z_E(_Fns_2A_4D)(_u, _v), 2)
            +
            pow(t_E(_Fns_2A_4D)(_u, _v), 2)
        )
    }

#end // LengthFunction_2A_4D


#macro LengthFunction_2A(_Fns_2A)

    #local M = dimensions(_Fns_2A);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_2A, 1);

    #switch (D)
        #case (1)
            LengthFunction_2A_1D(
                _Fns_2A
            )
            #break
        #case (2)
            LengthFunction_2A_2D(
                _Fns_2A
            )
            #break
        #case (3)
            LengthFunction_2A_3D(
                _Fns_2A
            )
            #break
        #case (4)
            LengthFunction_2A_4D(
                _Fns_2A
            )
            #break
        #else
            #error "D is neither 1, 2, 3 nor 4"
    #end // switch

#end // LengthFunction_2A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro LengthFunction_3A_1D(_Fns_3A_1D)

    #local M = dimensions(_Fns_3A_1D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_3A_1D, 1);
    #if (D != 1)
        #error "D is not 1"
    #end // if

    function(_u, _v, _w) {
        abs(
            x_E(_Fns_3A_1D)(_u, _v, _w)
        )
    }

#end // LengthFunction_3A_1D


#macro LengthFunction_3A_2D(_Fns_3A_2D)

    #local M = dimensions(_Fns_3A_2D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_3A_2D, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if

    function(_u, _v, _w) {
        f_r(
            x_E(_Fns_3A_2D)(_u, _v, _w),
            y_E(_Fns_3A_2D)(_u, _v, _w),
            0.0
        )
    }

#end // LengthFunction_3A_2D


#macro LengthFunction_3A_3D(_Fns_3A_3D)

    #local M = dimensions(_Fns_3A_3D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_3A_3D, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if

    function(_u, _v, _w) {
        f_r(
            x_E(_Fns_3A_3D)(_u, _v, _w),
            y_E(_Fns_3A_3D)(_u, _v, _w),
            z_E(_Fns_3A_3D)(_u, _v, _w)
        )
    }

#end // LengthFunction_3A_3D


#macro LengthFunction_3A_4D(_Fns_3A_4D)

    #local M = dimensions(_Fns_3A_4D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_3A_4D, 1);
    #if (D != 4)
        #error "D is not 4"
    #end // if

    function(_u, _v, _w) {
        sqrt(
            pow(x_E(_Fns_3A_4D)(_u, _v, _w), 2)
            +
            pow(y_E(_Fns_3A_4D)(_u, _v, _w), 2)
            +
            pow(z_E(_Fns_3A_4D)(_u, _v, _w), 2)
            +
            pow(t_E(_Fns_3A_4D)(_u, _v, _w), 2)
        )
    }

#end // LengthFunction_3A_4D


#macro LengthFunction_3A(_Fns_3A)

    #local M = dimensions(_Fns_3A);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_3A, 1);

    #switch (D)
        #case (1)
            LengthFunction_3A_1D(
                _Fns_3A
            )
            #break
        #case (2)
            LengthFunction_3A_2D(
                _Fns_3A
            )
            #break
        #case (3)
            LengthFunction_3A_3D(
                _Fns_3A
            )
            #break
        #case (4)
            LengthFunction_3A_4D(
                _Fns_3A
            )
            #break
        #else
            #error "D is neither 1, 2, 3 nor 4"
    #end // switch

#end // LengthFunction_3A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro LengthFunction_4A_1D(_Fns_4A_1D)

    #local M = dimensions(_Fns_4A_1D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_4A_1D, 1);
    #if (D != 1)
        #error "D is not 1"
    #end // if

    function(_u, _v, _w, _s) {
        abs(
            x_E(_Fns_4A_1D)(_u, _v, _w, _s)
        )
    }

#end // LengthFunction_4A_1D


#macro LengthFunction_4A_2D(_Fns_4A_2D)

    #local M = dimensions(_Fns_4A_2D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_4A_2D, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if

    function(_u, _v, _w, _s) {
        f_r(
            x_E(_Fns_4A_2D)(_u, _v, _w, _s),
            y_E(_Fns_4A_2D)(_u, _v, _w, _s),
            0.0
        )
    }

#end // LengthFunction_4A_2D


#macro LengthFunction_4A_3D(_Fns_4A_3D)

    #local M = dimensions(_Fns_4A_3D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_4A_3D, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if

    function(_u, _v, _w, _s) {
        f_r(
            x_E(_Fns_4A_3D)(_u, _v, _w, _s),
            y_E(_Fns_4A_3D)(_u, _v, _w, _s),
            z_E(_Fns_4A_3D)(_u, _v, _w, _s)
        )
    }

#end // LengthFunction_4A_3D


#macro LengthFunction_4A_4D(_Fns_4A_4D)

    #local M = dimensions(_Fns_4A_4D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_4A_4D, 1);
    #if (D != 4)
        #error "D is not 4"
    #end // if

    function(_u, _v, _w, _s) {
        sqrt(
            pow(x_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
            +
            pow(y_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
            +
            pow(z_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
            +
            pow(t_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
        )
    }

#end // LengthFunction_4A_4D


#macro LengthFunction_4A(_Fns_4A)

    #local M = dimensions(_Fns_4A);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_4A, 1);

    #switch (D)
        #case (1)
            LengthFunction_4A_1D(
                _Fns_4A
            )
            #break
        #case (2)
            LengthFunction_4A_2D(
                _Fns_4A
            )
            #break
        #case (3)
            LengthFunction_4A_3D(
                _Fns_4A
            )
            #break
        #case (4)
            LengthFunction_4A_4D(
                _Fns_4A
            )
            #break
        #else
            #error "D is neither 1, 2, 3 nor 4"
    #end // switch

#end // LengthFunction_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro DotFunction_1A_2D(_Fns0_1A_2D, _Fns1_1A_2D)

    #local M =
        max(
            dimensions(_Fns0_1A_2D),
            dimensions(_Fns1_1A_2D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_1A_2D, 1);
    #if (D1 != 2)
        #error "D1 is not 2"
    #end // if
    #local D2 = dimension_size(_Fns1_1A_2D, 1);
    #if (D2 != 2)
        #error "D2 is not 2"
    #end // if

    function(_u) {
        x_E(_Fns0_1A_2D)(_u)*x_E(_Fns1_1A_2D)(_u)
        +
        y_E(_Fns0_1A_2D)(_u)*y_E(_Fns1_1A_2D)(_u)
    }

#end // macro DotFunction_1A_2D


#macro DotFunction_1A_3D(_Fns0_1A_3D, _Fns1_1A_3D)

    #local M =
        max(
            dimensions(_Fns0_1A_3D),
            dimensions(_Fns1_1A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_1A_3D, 1);
    #if (D1 != 3)
        #error "D1 is not 3"
    #end // if
    #local D2 = dimension_size(_Fns1_1A_3D, 1);
    #if (D2 != 3)
        #error "D2 is not 3"
    #end // if

    function(_u) {
        x_E(_Fns0_1A_3D)(_u)*x_E(_Fns1_1A_3D)(_u)
        +
        y_E(_Fns0_1A_3D)(_u)*y_E(_Fns1_1A_3D)(_u)
        +
        z_E(_Fns0_1A_3D)(_u)*z_E(_Fns1_1A_3D)(_u)
    }

#end // macro DotFunction_1A_3D


#macro DotFunction_1A_4D(_Fns0_1A_4D, _Fns1_1A_4D)

    #local M =
        max(
            dimensions(_Fns0_1A_4D),
            dimensions(_Fns1_1A_4D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_1A_4D, 1);
    #if (D1 != 4)
        #error "D1 is not 4"
    #end // if
    #local D2 = dimension_size(_Fns1_1A_4D, 1);
    #if (D2 != 4)
        #error "D2 is not 4"
    #end // if

    function(_u) {
        x_E(_Fns0_1A_4D)(_u)*x_E(_Fns1_1A_4D)(_u)
        +
        y_E(_Fns0_1A_4D)(_u)*y_E(_Fns1_1A_4D)(_u)
        +
        z_E(_Fns0_1A_4D)(_u)*z_E(_Fns1_1A_4D)(_u)
        +
        t_E(_Fns0_1A_4D)(_u)*t_E(_Fns1_1A_4D)(_u)
    }

#end // macro DotFunction_1A_4D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro DotFunction_2A_2D(_Fns0_2A_2D, _Fns1_2A_2D)

    #local M =
        max(
            dimensions(_Fns0_2A_2D),
            dimensions(_Fns1_2A_2D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_2A_2D, 1);
    #if (D1 != 2)
        #error "D1 is not 2"
    #end // if
    #local D2 = dimension_size(_Fns1_2A_2D, 1);
    #if (D2 != 2)
        #error "D2 is not 2"
    #end // if

    function(_u, _v) {
        x_E(_Fns0_2A_2D)(_u, _v)*x_E(_Fns1_2A_2D)(_u, _v)
        +
        y_E(_Fns0_2A_2D)(_u, _v)*y_E(_Fns1_2A_2D)(_u, _v)
    }

#end // macro DotFunction_2A_2D


#macro DotFunction_2A_3D(_Fns0_2A_3D, _Fns1_2A_3D)

    #local M =
        max(
            dimensions(_Fns0_2A_3D),
            dimensions(_Fns1_2A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_2A_3D, 1);
    #if (D1 != 3)
        #error "D1 is not 3"
    #end // if
    #local D2 = dimension_size(_Fns1_2A_3D, 1);
    #if (D2 != 3)
        #error "D2 is not 3"
    #end // if

    function(_u, _v) {
        x_E(_Fns0_2A_3D)(_u, _v)*x_E(_Fns1_2A_3D)(_u, _v)
        +
        y_E(_Fns0_2A_3D)(_u, _v)*y_E(_Fns1_2A_3D)(_u, _v)
        +
        z_E(_Fns0_2A_3D)(_u, _v)*z_E(_Fns1_2A_3D)(_u, _v)
    }

#end // macro DotFunction_2A_3D


#macro DotFunction_2A_4D(_Fns0_2A_4D, _Fns1_2A_4D)

    #local M =
        max(
            dimensions(_Fns0_2A_4D),
            dimensions(_Fns1_2A_4D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_2A_4D, 1);
    #if (D1 != 4)
        #error "D1 is not 4"
    #end // if
    #local D2 = dimension_size(_Fns1_2A_4D, 1);
    #if (D2 != 4)
        #error "D2 is not 4"
    #end // if

    function(_u, _v) {
        x_E(_Fns0_2A_4D)(_u, _v)*x_E(_Fns1_2A_4D)(_u, _v)
        +
        y_E(_Fns0_2A_4D)(_u, _v)*y_E(_Fns1_2A_4D)(_u, _v)
        +
        z_E(_Fns0_2A_4D)(_u, _v)*z_E(_Fns1_2A_4D)(_u, _v)
        +
        t_E(_Fns0_2A_4D)(_u, _v)*t_E(_Fns1_2A_4D)(_u, _v)
    }

#end // macro DotFunction_2A_4D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro DotFunction_3A_2D(_Fns0_3A_2D, _Fns1_3A_2D)

    #local M =
        max(
            dimensions(_Fns0_3A_2D),
            dimensions(_Fns1_3A_2D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_3A_2D, 1);
    #if (D1 != 2)
        #error "D1 is not 2"
    #end // if
    #local D2 = dimension_size(_Fns1_3A_2D, 1);
    #if (D2 != 2)
        #error "D2 is not 2"
    #end // if

    function(_u, _v, _w) {
        x_E(_Fns0_3A_2D)(_u, _v, _w)*x_E(_Fns1_3A_2D)(_u, _v, _w)
        +
        y_E(_Fns0_3A_2D)(_u, _v, _w)*y_E(_Fns1_3A_2D)(_u, _v, _w)
    }

#end // macro DotFunction_3A_2D


#macro DotFunction_3A_3D(_Fns0_3A_3D, _Fns1_3A_3D)

    #local M =
        max(
            dimensions(_Fns0_3A_3D),
            dimensions(_Fns1_3A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_3A_3D, 1);
    #if (D1 != 3)
        #error "D1 is not 3"
    #end // if
    #local D2 = dimension_size(_Fns1_3A_3D, 1);
    #if (D2 != 3)
        #error "D2 is not 3"
    #end // if

    function(_u, _v, _w) {
        x_E(_Fns0_3A_3D)(_u, _v, _w)*x_E(_Fns1_3A_3D)(_u, _v, _w)
        +
        y_E(_Fns0_3A_3D)(_u, _v, _w)*y_E(_Fns1_3A_3D)(_u, _v, _w)
        +
        z_E(_Fns0_3A_3D)(_u, _v, _w)*z_E(_Fns1_3A_3D)(_u, _v, _w)
    }

#end // macro DotFunction_3A_3D


#macro DotFunction_3A_4D(_Fns0_3A_4D, _Fns1_3A_4D)

    #local M =
        max(
            dimensions(_Fns0_3A_4D),
            dimensions(_Fns1_3A_4D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_3A_4D, 1);
    #if (D1 != 4)
        #error "D1 is not 4"
    #end // if
    #local D2 = dimension_size(_Fns1_3A_4D, 1);
    #if (D2 != 4)
        #error "D2 is not 4"
    #end // if

    function(_u, _v, _w) {
        x_E(_Fns0_3A_4D)(_u, _v, _w)*x_E(_Fns1_3A_4D)(_u, _v, _w)
        +
        y_E(_Fns0_3A_4D)(_u, _v, _w)*y_E(_Fns1_3A_4D)(_u, _v, _w)
        +
        z_E(_Fns0_3A_4D)(_u, _v, _w)*z_E(_Fns1_3A_4D)(_u, _v, _w)
        +
        t_E(_Fns0_3A_4D)(_u, _v, _w)*t_E(_Fns1_3A_4D)(_u, _v, _w)
    }

#end // macro DotFunction_3A_4D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro DotFunction_4A_2D(_Fns0_4A_2D, _Fns1_4A_2D)

    #local M =
        max(
            dimensions(_Fns0_4A_2D),
            dimensions(_Fns1_4A_2D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_4A_2D, 1);
    #if (D1 != 2)
        #error "D1 is not 2"
    #end // if
    #local D2 = dimension_size(_Fns1_4A_2D, 1);
    #if (D2 != 2)
        #error "D2 is not 2"
    #end // if

    function(_u, _v, _w, _s) {
        x_E(_Fns0_4A_2D)(_u, _v, _w, _s)*x_E(_Fns1_4A_2D)(_u, _v, _w, _s)
        +
        y_E(_Fns0_4A_2D)(_u, _v, _w, _s)*y_E(_Fns1_4A_2D)(_u, _v, _w, _s)
    }

#end // macro DotFunction_4A_2D


#macro DotFunction_4A_3D(_Fns0_4A_3D, _Fns1_4A_3D)

    #local M =
        max(
            dimensions(_Fns0_4A_3D),
            dimensions(_Fns1_4A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_4A_3D, 1);
    #if (D1 != 3)
        #error "D1 is not 3"
    #end // if
    #local D2 = dimension_size(_Fns1_4A_3D, 1);
    #if (D2 != 3)
        #error "D2 is not 3"
    #end // if

    function(_u, _v, _w, _s) {
        x_E(_Fns0_4A_3D)(_u, _v, _w, _s)*x_E(_Fns1_4A_3D)(_u, _v, _w, _s)
        +
        y_E(_Fns0_4A_3D)(_u, _v, _w, _s)*y_E(_Fns1_4A_3D)(_u, _v, _w, _s)
        +
        z_E(_Fns0_4A_3D)(_u, _v, _w, _s)*z_E(_Fns1_4A_3D)(_u, _v, _w, _s)
    }

#end // macro DotFunction_4A_3D


#macro DotFunction_4A_4D(_Fns0_4A_4D, _Fns1_4A_4D)

    #local M =
        max(
            dimensions(_Fns0_4A_4D),
            dimensions(_Fns1_4A_4D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_4A_4D, 1);
    #if (D1 != 4)
        #error "D1 is not 4"
    #end // if
    #local D2 = dimension_size(_Fns1_4A_4D, 1);
    #if (D2 != 4)
        #error "D2 is not 4"
    #end // if

    function(_u, _v, _w, _s) {
        x_E(_Fns0_4A_4D)(_u, _v, _w, _s)*x_E(_Fns1_4A_4D)(_u, _v, _w, _s)
        +
        y_E(_Fns0_4A_4D)(_u, _v, _w, _s)*y_E(_Fns1_4A_4D)(_u, _v, _w, _s)
        +
        z_E(_Fns0_4A_4D)(_u, _v, _w, _s)*z_E(_Fns1_4A_4D)(_u, _v, _w, _s)
        +
        t_E(_Fns0_4A_4D)(_u, _v, _w, _s)*t_E(_Fns1_4A_4D)(_u, _v, _w, _s)
    }

#end // macro DotFunction_4A_4D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro CrossFunctions_1A_3D(_Fns0_1A_3D, _Fns1_1A_3D)

    #local M =
        max(
            dimensions(_Fns0_1A_3D),
            dimensions(_Fns1_1A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_1A_3D, 1);
    #if (D1 != 3)
        #error "D1 is not 3"
    #end // if
    #local D2 = dimension_size(_Fns1_1A_3D, 1);
    #if (D2 != 3)
        #error "D2 is not 3"
    #end // if

    Arr_3E(
        function(_u) {
            y_E(_Fns0_1A_3D)(_u)*z_E(_Fns1_1A_3D)(_u)
            -
            z_E(_Fns0_1A_3D)(_u)*y_E(_Fns1_1A_3D)(_u)
        },
        function(_u) {
            z_E(_Fns0_1A_3D)(_u)*x_E(_Fns1_1A_3D)(_u)
            -
            x_E(_Fns0_1A_3D)(_u)*z_E(_Fns1_1A_3D)(_u)
        },
        function(_u) {
            x_E(_Fns0_1A_3D)(_u)*y_E(_Fns1_1A_3D)(_u)
            -
            y_E(_Fns0_1A_3D)(_u)*x_E(_Fns1_1A_3D)(_u)
        }
    )

#end // macro CrossFunctions_1A_3D


#macro CrossFunctions_2A_3D(_Fns0_2A_3D, _Fns1_2A_3D)

    #local M =
        max(
            dimensions(_Fns0_2A_3D),
            dimensions(_Fns1_2A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_2A_3D, 1);
    #if (D1 != 3)
        #error "D1 is not 3"
    #end // if
    #local D2 = dimension_size(_Fns1_2A_3D, 1);
    #if (D2 != 3)
        #error "D2 is not 3"
    #end // if

    Arr_3E(
        function(_u, _v) {
            y_E(_Fns0_2A_3D)(_u, _v)*z_E(_Fns1_2A_3D)(_u, _v)
            -
            z_E(_Fns0_2A_3D)(_u, _v)*y_E(_Fns1_2A_3D)(_u, _v)
        },
        function(_u, _v) {
            z_E(_Fns0_2A_3D)(_u, _v)*x_E(_Fns1_2A_3D)(_u, _v)
            -
            x_E(_Fns0_2A_3D)(_u, _v)*z_E(_Fns1_2A_3D)(_u, _v)
        },
        function(_u, _v) {
            x_E(_Fns0_2A_3D)(_u, _v)*y_E(_Fns1_2A_3D)(_u, _v)
            -
            y_E(_Fns0_2A_3D)(_u, _v)*x_E(_Fns1_2A_3D)(_u, _v)
        }
    )

#end // macro CrossFunctions_2A_3D


#macro CrossFunctions_3A_3D(_Fns0_3A_3D, _Fns1_3A_3D)

    #local M =
        max(
            dimensions(_Fns0_3A_3D),
            dimensions(_Fns1_3A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_3A_3D, 1);
    #if (D1 != 3)
        #error "D1 is not 3"
    #end // if
    #local D2 = dimension_size(_Fns1_3A_3D, 1);
    #if (D2 != 3)
        #error "D2 is not 3"
    #end // if

    Arr_3E(
        function(_u, _v, _w) {
            y_E(_Fns0_3A_3D)(_u, _v, _w)*z_E(_Fns1_3A_3D)(_u, _v, _w)
            -
            z_E(_Fns0_3A_3D)(_u, _v, _w)*y_E(_Fns1_3A_3D)(_u, _v, _w)
        },
        function(_u, _v, _w) {
            z_E(_Fns0_3A_3D)(_u, _v, _w)*x_E(_Fns1_3A_3D)(_u, _v, _w)
            -
            x_E(_Fns0_3A_3D)(_u, _v, _w)*z_E(_Fns1_3A_3D)(_u, _v, _w)
        },
        function(_u, _v, _w) {
            x_E(_Fns0_3A_3D)(_u, _v, _w)*y_E(_Fns1_3A_3D)(_u, _v, _w)
            -
            y_E(_Fns0_3A_3D)(_u, _v, _w)*x_E(_Fns1_3A_3D)(_u, _v, _w)
        }
    )

#end // macro CrossFunctions_3A_3D


#macro CrossFunctions_4A_3D(_Fns0_4A_3D, _Fns1_4A_3D)

    #local M =
        max(
            dimensions(_Fns0_4A_3D),
            dimensions(_Fns1_4A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D1 = dimension_size(_Fns0_4A_3D, 1);
    #if (D1 != 3)
        #error "D1 is not 3"
    #end // if
    #local D2 = dimension_size(_Fns1_4A_3D, 1);
    #if (D2 != 3)
        #error "D2 is not 3"
    #end // if

    Arr_3E(
        function(_u, _v, _w, _s) {
            y_E(_Fns0_4A_3D)(_u, _v, _w, _s)*z_E(_Fns1_4A_3D)(_u, _v, _w, _s)
            -
            z_E(_Fns0_4A_3D)(_u, _v, _w, _s)*y_E(_Fns1_4A_3D)(_u, _v, _w, _s)
        },
        function(_u, _v, _w, _s) {
            z_E(_Fns0_4A_3D)(_u, _v, _w, _s)*x_E(_Fns1_4A_3D)(_u, _v, _w, _s)
            -
            x_E(_Fns0_4A_3D)(_u, _v, _w, _s)*z_E(_Fns1_4A_3D)(_u, _v, _w, _s)
        },
        function(_u, _v, _w, _s) {
            x_E(_Fns0_4A_3D)(_u, _v, _w, _s)*y_E(_Fns1_4A_3D)(_u, _v, _w, _s)
            -
            y_E(_Fns0_4A_3D)(_u, _v, _w, _s)*x_E(_Fns1_4A_3D)(_u, _v, _w, _s)
        }
    )

#end // macro CrossFunctions_4A_3D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro NormalizedFunctions_1A_2D(_Fns_1A_2D)

    #local M = dimensions(_Fns_1A_2D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_1A_2D, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if

    Arr_2E(
        function(_u) {
            x_E(_Fns_1A_2D)(_u)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_1A_2D)(_u),
                    y_E(_Fns_1A_2D)(_u),
                    0
                )
            )
        },
        function(_u) {
            y_E(_Fns_1A_2D)(_u)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_1A_2D)(_u),
                    y_E(_Fns_1A_2D)(_u),
                    0
                )
            )
        }
    )

#end // macro NormalizedFunctions_1A_2D


#macro NormalizedFunctions_1A_3D(_Fns_1A_3D)

    #local M = dimensions(_Fns_1A_3D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_1A_3D, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if

    Arr_3E(
        function(_u) {
            x_E(_Fns_1A_3D)(_u)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_1A_3D)(_u),
                    y_E(_Fns_1A_3D)(_u),
                    z_E(_Fns_1A_3D)(_u)
                )
            )
        },
        function(_u) {
            y_E(_Fns_1A_3D)(_u)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_1A_3D)(_u),
                    y_E(_Fns_1A_3D)(_u),
                    z_E(_Fns_1A_3D)(_u)
                )
            )
        },
        function(_u) {
            z_E(_Fns_1A_3D)(_u)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_1A_3D)(_u),
                    y_E(_Fns_1A_3D)(_u),
                    z_E(_Fns_1A_3D)(_u)
                )
            )
        }
    )

#end // macro NormalizedFunctions_1A_3D


#macro NormalizedFunctions_1A_4D(_Fns_1A_4D)

    #local M = dimensions(_Fns_1A_4D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_1A_4D, 1);
    #if (D != 4)
        #error "D is not 4"
    #end // if

    Arr_4E(
        function(_u) {
            x_E(_Fns_1A_4D)(_u)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_1A_4D)(_u), 2)
                    +
                    pow(y_E(_Fns_1A_4D)(_u), 2)
                    +
                    pow(z_E(_Fns_1A_4D)(_u), 2)
                    +
                    pow(t_E(_Fns_1A_4D)(_u), 2)
                )
            )
        },
        function(_u) {
            y_E(_Fns_1A_4D)(_u)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_1A_4D)(_u), 2)
                    +
                    pow(y_E(_Fns_1A_4D)(_u), 2)
                    +
                    pow(z_E(_Fns_1A_4D)(_u), 2)
                    +
                    pow(t_E(_Fns_1A_4D)(_u), 2)
                )
            )
        },
        function(_u) {
            z_E(_Fns_1A_4D)(_u)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_1A_4D)(_u), 2)
                    +
                    pow(y_E(_Fns_1A_4D)(_u), 2)
                    +
                    pow(z_E(_Fns_1A_4D)(_u), 2)
                    +
                    pow(t_E(_Fns_1A_4D)(_u), 2)
                )
            )
        },
        function(_u) {
            t_E(_Fns_1A_4D)(_u)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_1A_4D)(_u), 2)
                    +
                    pow(y_E(_Fns_1A_4D)(_u), 2)
                    +
                    pow(z_E(_Fns_1A_4D)(_u), 2)
                    +
                    pow(t_E(_Fns_1A_4D)(_u), 2)
                )
            )
        }
    )

#end // macro NormalizedFunctions_1A_4D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro NormalizedFunctions_2A_2D(_Fns_2A_2D)

    #local M = dimensions(_Fns_2A_2D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_2A_2D, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if

    Arr_2E(
        function(_u, _v) {
            x_E(_Fns_2A_2D)(_u, _v)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_2A_2D)(_u, _v),
                    y_E(_Fns_2A_2D)(_u, _v),
                    0
                )
            )
        },
        function(_u, _v) {
            y_E(_Fns_2A_2D)(_u, _v)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_2A_2D)(_u, _v),
                    y_E(_Fns_2A_2D)(_u, _v),
                    0
                )
            )
        }
    )

#end // macro NormalizedFunctions_2A_2D


#macro NormalizedFunctions_2A_3D(_Fns_2A_3D)

    #local M = dimensions(_Fns_2A_3D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_2A_3D, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if

    Arr_3E(
        function(_u, _v) {
            x_E(_Fns_2A_3D)(_u, _v)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_2A_3D)(_u, _v),
                    y_E(_Fns_2A_3D)(_u, _v),
                    z_E(_Fns_2A_3D)(_u, _v)
                )
            )
        },
        function(_u, _v) {
            y_E(_Fns_2A_3D)(_u, _v)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_2A_3D)(_u, _v),
                    y_E(_Fns_2A_3D)(_u, _v),
                    z_E(_Fns_2A_3D)(_u, _v)
                )
            )
        },
        function(_u, _v) {
            z_E(_Fns_2A_3D)(_u, _v)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_2A_3D)(_u, _v),
                    y_E(_Fns_2A_3D)(_u, _v),
                    z_E(_Fns_2A_3D)(_u, _v)
                )
            )
        }
    )

#end // macro NormalizedFunctions_2A_3D


#macro NormalizedFunctions_2A_4D(_Fns_2A_4D)

    #local M = dimensions(_Fns_2A_4D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_2A_4D, 1);
    #if (D != 4)
        #error "D is not 4"
    #end // if

    Arr_4E(
        function(_u, _v) {
            x_E(_Fns_2A_4D)(_u, _v)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_2A_4D)(_u, _v), 2)
                    +
                    pow(y_E(_Fns_2A_4D)(_u, _v), 2)
                    +
                    pow(z_E(_Fns_2A_4D)(_u, _v), 2)
                    +
                    pow(t_E(_Fns_2A_4D)(_u, _v), 2)
                )
            )
        },
        function(_u, _v) {
            y_E(_Fns_2A_4D)(_u, _v)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_2A_4D)(_u, _v), 2)
                    +
                    pow(y_E(_Fns_2A_4D)(_u, _v), 2)
                    +
                    pow(z_E(_Fns_2A_4D)(_u, _v), 2)
                    +
                    pow(t_E(_Fns_2A_4D)(_u, _v), 2)
                )
            )
        },
        function(_u, _v) {
            z_E(_Fns_2A_4D)(_u, _v)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_2A_4D)(_u, _v), 2)
                    +
                    pow(y_E(_Fns_2A_4D)(_u, _v), 2)
                    +
                    pow(z_E(_Fns_2A_4D)(_u, _v), 2)
                    +
                    pow(t_E(_Fns_2A_4D)(_u, _v), 2)
                )
            )
        },
        function(_u, _v) {
            t_E(_Fns_2A_4D)(_u, _v)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_2A_4D)(_u, _v), 2)
                    +
                    pow(y_E(_Fns_2A_4D)(_u, _v), 2)
                    +
                    pow(z_E(_Fns_2A_4D)(_u, _v), 2)
                    +
                    pow(t_E(_Fns_2A_4D)(_u, _v), 2)
                )
            )
        }
    )

#end // macro NormalizedFunctions_2A_4D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro NormalizedFunctions_3A_2D(_Fns_3A_2D)

    #local M = dimensions(_Fns_3A_2D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_3A_2D, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if

    Arr_2E(
        function(_u, _v, _w) {
            x_E(_Fns_3A_2D)(_u, _v, _w)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_3A_2D)(_u, _v, _w),
                    y_E(_Fns_3A_2D)(_u, _v, _w),
                    0
                )
            )
        },
        function(_u, _v, _w) {
            y_E(_Fns_3A_2D)(_u, _v, _w)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_3A_2D)(_u, _v, _w),
                    y_E(_Fns_3A_2D)(_u, _v, _w),
                    0
                )
            )
        }
    )

#end // macro NormalizedFunctions_3A_2D


#macro NormalizedFunctions_3A_3D(_Fns_3A_3D)

    #local M = dimensions(_Fns_3A_3D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_3A_3D, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if

    Arr_3E(
        function(_u, _v, _w) {
            x_E(_Fns_3A_3D)(_u, _v, _w)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_3A_3D)(_u, _v, _w),
                    y_E(_Fns_3A_3D)(_u, _v, _w),
                    z_E(_Fns_3A_3D)(_u, _v, _w)
                )
            )
        },
        function(_u, _v, _w) {
            y_E(_Fns_3A_3D)(_u, _v, _w)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_3A_3D)(_u, _v, _w),
                    y_E(_Fns_3A_3D)(_u, _v, _w),
                    z_E(_Fns_3A_3D)(_u, _v, _w)
                )
            )
        },
        function(_u, _v, _w) {
            z_E(_Fns_3A_3D)(_u, _v, _w)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_3A_3D)(_u, _v, _w),
                    y_E(_Fns_3A_3D)(_u, _v, _w),
                    z_E(_Fns_3A_3D)(_u, _v, _w)
                )
            )
        }
    )

#end // macro NormalizedFunctions_3A_3D


#macro NormalizedFunctions_3A_4D(_Fns_3A_4D)

    #local M = dimensions(_Fns_3A_4D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_3A_4D, 1);
    #if (D != 4)
        #error "D is not 4"
    #end // if

    Arr_4E(
        function(_u, _v, _w) {
            x_E(_Fns_3A_4D)(_u, _v, _w)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_3A_4D)(_u, _v, _w), 2)
                    +
                    pow(y_E(_Fns_3A_4D)(_u, _v, _w), 2)
                    +
                    pow(z_E(_Fns_3A_4D)(_u, _v, _w), 2)
                    +
                    pow(t_E(_Fns_3A_4D)(_u, _v, _w), 2)
                )
            )
        },
        function(_u, _v, _w) {
            y_E(_Fns_3A_4D)(_u, _v, _w)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_3A_4D)(_u, _v, _w), 2)
                    +
                    pow(y_E(_Fns_3A_4D)(_u, _v, _w), 2)
                    +
                    pow(z_E(_Fns_3A_4D)(_u, _v, _w), 2)
                    +
                    pow(t_E(_Fns_3A_4D)(_u, _v, _w), 2)
                )
            )
        },
        function(_u, _v, _w) {
            z_E(_Fns_3A_4D)(_u, _v, _w)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_3A_4D)(_u, _v, _w), 2)
                    +
                    pow(y_E(_Fns_3A_4D)(_u, _v, _w), 2)
                    +
                    pow(z_E(_Fns_3A_4D)(_u, _v, _w), 2)
                    +
                    pow(t_E(_Fns_3A_4D)(_u, _v, _w), 2)
                )
            )
        },
        function(_u, _v, _w) {
            t_E(_Fns_3A_4D)(_u, _v, _w)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_3A_4D)(_u, _v, _w), 2)
                    +
                    pow(y_E(_Fns_3A_4D)(_u, _v, _w), 2)
                    +
                    pow(z_E(_Fns_3A_4D)(_u, _v, _w), 2)
                    +
                    pow(t_E(_Fns_3A_4D)(_u, _v, _w), 2)
                )
            )
        }
    )

#end // macro NormalizedFunctions_3A_4D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro NormalizedFunctions_4A_2D(_Fns_4A_2D)

    #local M = dimensions(_Fns_4A_2D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_4A_2D, 1);
    #if (D != 2)
        #error "D is not 2"
    #end // if

    Arr_2E(
        function(_u, _v, _w, _s) {
            x_E(_Fns_4A_2D)(_u, _v, _w, _s)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_4A_2D)(_u, _v, _w, _s),
                    y_E(_Fns_4A_2D)(_u, _v, _w, _s),
                    0
                )
            )
        },
        function(_u, _v, _w, _s) {
            y_E(_Fns_4A_2D)(_u, _v, _w, _s)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_4A_2D)(_u, _v, _w, _s),
                    y_E(_Fns_4A_2D)(_u, _v, _w, _s),
                    0
                )
            )
        }
    )

#end // macro NormalizedFunctions_4A_2D


#macro NormalizedFunctions_4A_3D(_Fns_4A_3D)

    #local M = dimensions(_Fns_4A_3D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_4A_3D, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if

    Arr_3E(
        function(_u, _v, _w, _s) {
            x_E(_Fns_4A_3D)(_u, _v, _w, _s)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_4A_3D)(_u, _v, _w, _s),
                    y_E(_Fns_4A_3D)(_u, _v, _w, _s),
                    z_E(_Fns_4A_3D)(_u, _v, _w, _s)
                )
            )
        },
        function(_u, _v, _w, _s) {
            y_E(_Fns_4A_3D)(_u, _v, _w, _s)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_4A_3D)(_u, _v, _w, _s),
                    y_E(_Fns_4A_3D)(_u, _v, _w, _s),
                    z_E(_Fns_4A_3D)(_u, _v, _w, _s)
                )
            )
        },
        function(_u, _v, _w, _s) {
            z_E(_Fns_4A_3D)(_u, _v, _w, _s)
            /
            max(
                NIL,
                f_r(
                    x_E(_Fns_4A_3D)(_u, _v, _w, _s),
                    y_E(_Fns_4A_3D)(_u, _v, _w, _s),
                    z_E(_Fns_4A_3D)(_u, _v, _w, _s)
                )
            )
        }
    )

#end // macro NormalizedFunctions_4A_3D


#macro NormalizedFunctions_4A_4D(_Fns_4A_4D)

    #local M = dimensions(_Fns_4A_4D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_4A_4D, 1);
    #if (D != 4)
        #error "D is not 4"
    #end // if

    Arr_4E(
        function(_u, _v, _w, _s) {
            x_E(_Fns_4A_4D)(_u, _v, _w, _s)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                    +
                    pow(y_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                    +
                    pow(z_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                    +
                    pow(t_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                )
            )
        },
        function(_u, _v, _w, _s) {
            y_E(_Fns_4A_4D)(_u, _v, _w, _s)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                    +
                    pow(y_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                    +
                    pow(z_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                    +
                    pow(t_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                )
            )
        },
        function(_u, _v, _w, _s) {
            z_E(_Fns_4A_4D)(_u, _v, _w, _s)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                    +
                    pow(y_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                    +
                    pow(z_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                    +
                    pow(t_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                )
            )
        },
        function(_u, _v, _w, _s) {
            t_E(_Fns_4A_4D)(_u, _v, _w, _s)
            /
            max(
                NIL,
                sqrt(
                    pow(x_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                    +
                    pow(y_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                    +
                    pow(z_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                    +
                    pow(t_E(_Fns_4A_4D)(_u, _v, _w, _s), 2)
                )
            )
        }
    )

#end // macro NormalizedFunctions_4A_4D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro FirstFundamentalFormFunctions_2A_3D(_D1_U_Fns_2A_3D, _D1_V_Fns_2A_3D)

    #local M =
        max(
            dimensions(_D1_U_Fns_2A_3D),
            dimensions(_D1_V_Fns_2A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local MinD =
        min(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1)
       )
    ;
    #if (MinD != 3)
        #error "MinD is not 3"
    #end // if
    #local MaxD =
        max(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1)
       )
    ;
    #if (MaxD != 3)
        #error "MaxD is not 3"
    #end // if

    Arr_3E(
        DotFunction_2A_3D(_D1_U_Fns_2A_3D, _D1_U_Fns_2A_3D), // E
        DotFunction_2A_3D(_D1_U_Fns_2A_3D, _D1_V_Fns_2A_3D), // F
        DotFunction_2A_3D(_D1_V_Fns_2A_3D, _D1_V_Fns_2A_3D)  // G
    )

#end // macro FirstFundamentalFormFunctions_2A_3D


#macro _SecondFundamentalFormFunctions_2A_3D(_D2_UU_Fns_2A_3D, _D2_UV_Fns_2A_3D, _D2_VV_Fns_2A_3D, _Normal_Fns_2A_3D)

    #local M =
        max(
            dimensions(_D2_UU_Fns_2A_3D),
            dimensions(_D2_UV_Fns_2A_3D),
            dimensions(_D2_VV_Fns_2A_3D),
            dimensions(_Normal_Fns_2A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local MinD =
        min(
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1),
            dimension_size(_Normal_Fns_2A_3D, 1)
       )
    ;
    #if (MinD != 3)
        #error "MinD is not 3"
    #end // if
    #local MaxD =
        max(
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1),
            dimension_size(_Normal_Fns_2A_3D, 1)
       )
    ;
    #if (MaxD != 3)
        #error "MaxD is not 3"
    #end // if

    Arr_3E(
        DotFunction_2A_3D(_D2_UU_Fns_2A_3D, _Normal_Fns_2A_3D), // L
        DotFunction_2A_3D(_D2_UV_Fns_2A_3D, _Normal_Fns_2A_3D), // M
        DotFunction_2A_3D(_D2_VV_Fns_2A_3D, _Normal_Fns_2A_3D)  // N
    )

#end // macro _SecondFundamentalFormFunctions_2A_3D


#macro SecondFundamentalFormFunctions_2A_3D(_D1_U_Fns_2A_3D, _D1_V_Fns_2A_3D, _D2_UU_Fns_2A_3D, _D2_UV_Fns_2A_3D, _D2_VV_Fns_2A_3D)

    #local M =
        max(
            dimensions(_D1_U_Fns_2A_3D),
            dimensions(_D1_V_Fns_2A_3D),
            dimensions(_D2_UU_Fns_2A_3D),
            dimensions(_D2_UV_Fns_2A_3D),
            dimensions(_D2_VV_Fns_2A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local MinD =
        min(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1),
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1)
       )
    ;
    #if (MinD != 3)
        #error "MinD is not 3"
    #end // if
    #local MaxD =
        max(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1),
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1)
       )
    ;
    #if (MaxD != 3)
        #error "MaxD is not 3"
    #end // if

    _SecondFundamentalFormFunctions_2A_3D(
        _D2_UU_Fns_2A_3D,
        _D2_UV_Fns_2A_3D,
        _D2_VV_Fns_2A_3D,
        NormalizedFunctions_2A_3D(
            CrossFunctions_2A_3D(
                _D1_U_Fns_2A_3D,
                _D1_V_Fns_2A_3D
            )
        )
    )

#end // macro SecondFundamentalFormFunctions_2A_3D

/*
This does not work:

#macro FundamentalForm1st_Determinant_2A_3D(_FundamentalForm1st_Fns_2A_3D)

    #local M = dimensions(_FundamentalForm1st_Fns_2A_3D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_FundamentalForm1st_Fns_2A_3D, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if

    // Formula: E*G - F^2

    SubtractFunction_2A(
        MultiplyFunction_2A(
            E_FundamentalFn(_FundamentalForm1st_Fns_2A_3D),
            G_FundamentalFn(_FundamentalForm1st_Fns_2A_3D)
        ),
        PowFunction_Constant_2A(
            F_FundamentalFn(_FundamentalForm1st_Fns_2A_3D),
            2
        )
    )

#end // macro FundamentalForm1st_Determinant_2A_3D
*/


#macro FundamentalForm1st_Determinant_2A_3D(_FundamentalForm1st_Fns_2A_3D)

    #local M = dimensions(_FundamentalForm1st_Fns_2A_3D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_FundamentalForm1st_Fns_2A_3D, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if

    // Formula: E*G - F^2

    SubtractFunction_2A(
        MultiplyFunction_2A(
            _FundamentalForm1st_Fns_2A_3D[0], // E
            _FundamentalForm1st_Fns_2A_3D[2]  // G
        ),
        PowFunction_Constant_2A(
            _FundamentalForm1st_Fns_2A_3D[1], // F
            2
        )
    )

#end // macro FundamentalForm1st_Determinant_2A_3D


/*
This does not work:

#macro FundamentalForm2nd_Determinant_2A_3D(_FundamentalForm2nd_Fns_2A_3D)

    #local M = dimensions(_FundamentalForm2nd_Fns_2A_3D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_FundamentalForm2nd_Fns_2A_3D, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if

    // Formula: L*N - M^2

    SubtractFunction_2A(
        MultiplyFunction_2A(
            L_FundamentalFn(_FundamentalForm2nd_Fns_2A_3D),
            N_FundamentalFn(_FundamentalForm2nd_Fns_2A_3D)
        ),
        PowFunction_Constant_2A(
            M_FundamentalFn(_FundamentalForm2nd_Fns_2A_3D),
            2
        )
    )

#end // macro FundamentalForm2nd_Determinant_2A_3D
*/


#macro FundamentalForm2nd_Determinant_2A_3D(_FundamentalForm2nd_Fns_2A_3D)

    #local M = dimensions(_FundamentalForm2nd_Fns_2A_3D);
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_FundamentalForm2nd_Fns_2A_3D, 1);
    #if (D != 3)
        #error "D is not 3"
    #end // if

    // Formula: L*N - M^2

    SubtractFunction_2A(
        MultiplyFunction_2A(
            _FundamentalForm2nd_Fns_2A_3D[0],
            _FundamentalForm2nd_Fns_2A_3D[2]
        ),
        PowFunction_Constant_2A(
            _FundamentalForm2nd_Fns_2A_3D[1],
            2
        )
    )

#end // macro FundamentalForm2nd_Determinant_2A_3D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro _AltGaussianCurvatureFunction_2A_3D(_FundamentalForm1st_Fns_2A_3D, _FundamentalForm2nd_Fns_2A_3D)

    #local M =
        max(
            dimensions(_FundamentalForm1st_Fns_2A_3D),
            dimensions(_FundamentalForm2nd_Fns_2A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local MinD =
        min(
            dimension_size(_FundamentalForm1st_Fns_2A_3D, 1),
            dimension_size(_FundamentalForm2nd_Fns_2A_3D, 1)
       )
    ;
    #if (MinD != 3)
        #error "MinD is not 3"
    #end // if
    #local MaxD =
        max(
            dimension_size(_FundamentalForm1st_Fns_2A_3D, 1),
            dimension_size(_FundamentalForm2nd_Fns_2A_3D, 1)
       )
    ;
    #if (MaxD != 3)
        #error "MaxD is not 3"
    #end // if

    // Formula: (L*N - M^2)/(E*G - F^2)

    DivideFunction_Safe_2A(
        FundamentalForm2nd_Determinant_2A_3D(_FundamentalForm2nd_Fns_2A_3D),
        FundamentalForm1st_Determinant_2A_3D(_FundamentalForm1st_Fns_2A_3D)
    )

#end // macro _AltGaussianCurvatureFunction_2A_3D


#macro AltGaussianCurvatureFunction_2A_3D(_D1_U_Fns_2A_3D, _D1_V_Fns_2A_3D, _D2_UU_Fns_2A_3D, _D2_UV_Fns_2A_3D, _D2_VV_Fns_2A_3D)

    #local M =
        max(
            dimensions(_D1_U_Fns_2A_3D),
            dimensions(_D1_V_Fns_2A_3D),
            dimensions(_D2_UU_Fns_2A_3D),
            dimensions(_D2_UV_Fns_2A_3D),
            dimensions(_D2_VV_Fns_2A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local MinD =
        min(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1),
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1)
       )
    ;
    #if (MinD != 3)
        #error "MinD is not 3"
    #end // if
    #local MaxD =
        max(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1),
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1)
       )
    ;
    #if (MaxD != 3)
        #error "MaxD is not 3"
    #end // if

    _AltGaussianCurvatureFunction_2A_3D(
        FirstFundamentalFormFunctions_2A_3D(
            _D1_U_Fns_2A_3D,
            _D1_V_Fns_2A_3D
        ),
        SecondFundamentalFormFunctions_2A_3D(
            _D1_U_Fns_2A_3D, 
            _D1_V_Fns_2A_3D,
            _D2_UU_Fns_2A_3D,
            _D2_UV_Fns_2A_3D,
            _D2_VV_Fns_2A_3D
        )
    )

#end // macro AltGaussianCurvatureFunction_2A_3D


#macro _GaussianCurvatureFunction_2A_3D(_D2_UU_Fns_2A_3D, _D2_UV_Fns_2A_3D, _D2_VV_Fns_2A_3D, _Normal_Fns_2A_3D)

    #local M =
        max(
            dimensions(_D2_UU_Fns_2A_3D),
            dimensions(_D2_UV_Fns_2A_3D),
            dimensions(_D2_VV_Fns_2A_3D),
            dimensions(_Normal_Fns_2A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local MinD =
        min(
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1),
            dimension_size(_Normal_Fns_2A_3D, 1)
       )
    ;
    #if (MinD != 3)
        #error "MinD is not 3"
    #end // if
    #local MaxD =
        max(
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1),
            dimension_size(_Normal_Fns_2A_3D, 1)
       )
    ;
    #if (MaxD != 3)
        #error "MaxD is not 3"
    #end // if

    DivideFunction_Safe_2A(
        SubtractFunction_2A(
            MultiplyFunction_2A(
                DotFunction_2A_3D(_D2_UU_Fns_2A_3D, _Normal_Fns_2A_3D), // L
                DotFunction_2A_3D(_D2_VV_Fns_2A_3D, _Normal_Fns_2A_3D)  // N
            ),
            PowFunction_Constant_2A(
                DotFunction_2A_3D(_D2_UV_Fns_2A_3D, _Normal_Fns_2A_3D), // M
                2
            )
        ),
        PowFunction_Constant_2A(
            DotFunction_2A_3D(_Normal_Fns_2A_3D, _Normal_Fns_2A_3D),
            2
        )
    )

#end // macro _GaussianCurvatureFunction_2A_3D


#macro GaussianCurvatureFunction_2A_3D(_D1_U_Fns_2A_3D, _D1_V_Fns_2A_3D, _D2_UU_Fns_2A_3D, _D2_UV_Fns_2A_3D, _D2_VV_Fns_2A_3D)

    #local M =
        max(
            dimensions(_D1_U_Fns_2A_3D),
            dimensions(_D1_V_Fns_2A_3D),
            dimensions(_D2_UU_Fns_2A_3D),
            dimensions(_D2_UV_Fns_2A_3D),
            dimensions(_D2_VV_Fns_2A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local MinD =
        min(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1),
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1)
       )
    ;
    #if (MinD != 3)
        #error "MinD is not 3"
    #end // if
    #local MaxD =
        max(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1),
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1)
        )
    ;
    #if (MaxD != 3)
        #error "MaxD is not 3"
    #end // if

    _GaussianCurvatureFunction_2A_3D(
        _D2_UU_Fns_2A_3D,
        _D2_UV_Fns_2A_3D,
        _D2_VV_Fns_2A_3D,
        CrossFunctions_2A_3D(
            _D1_U_Fns_2A_3D,
            _D1_V_Fns_2A_3D
        )
    )

#end // macro GaussianCurvatureFunction_2A_3D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

/*
This does not work:

#macro _AltMeanCurvatureFunction_2A_3D(_FundamentalForm1st_Fns_2A_3D, _FundamentalForm2nd_Fns_2A_3D)

    #local M =
        max(
            dimensions(_FundamentalForm1st_Fns_2A_3D),
            dimensions(_FundamentalForm2nd_Fns_2A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local MinD =
        min(
            dimension_size(_FundamentalForm1st_Fns_2A_3D, 1),
            dimension_size(_FundamentalForm2nd_Fns_2A_3D, 1)
       )
    ;
    #if (MinD != 3)
        #error "MinD is not 3"
    #end // if
    #local MaxD =
        max(
            dimension_size(_FundamentalForm1st_Fns_2A_3D, 1),
            dimension_size(_FundamentalForm2nd_Fns_2A_3D, 1)
       )
    ;
    #if (MaxD != 3)
        #error "MaxD is not 3"
    #end // if

    // Formula: (E*N + G*L - 2*F*M)/(2*(E*G - F^2))

    DivideFunction_Safe_2A(
        SubtractFunction_2A(
            AddFunction_2A(
                MultiplyFunction_2A(
                    E_FundamentalFn(_FundamentalForm1st_Fns_2A_3D),
                    N_FundamentalFn(_FundamentalForm2nd_Fns_2A_3D)
                ),
                MultiplyFunction_2A(
                    G_FundamentalFn(_FundamentalForm1st_Fns_2A_3D),
                    L_FundamentalFn(_FundamentalForm2nd_Fns_2A_3D)
                )
            ),
            MultiplyFunction_Constant_2A(
                MultiplyFunction_2A(
                    F_FundamentalFn(_FundamentalForm1st_Fns_2A_3D),
                    M_FundamentalFn(_FundamentalForm2nd_Fns_2A_3D)
                ),
                2
            )
        ),
        MultiplyFunction_Constant_2A(
            FundamentalForm1st_Determinant_2A_3D(
                _FundamentalForm1st_Fns_2A_3D
            ),
            2
        )
    )

#end // macro _AltMeanCurvatureFunction_2A_3D
*/


#macro _AltMeanCurvatureFunction_2A_3D(_FundamentalForm1st_Fns_2A_3D, _FundamentalForm2nd_Fns_2A_3D)

    #local M =
        max(
            dimensions(_FundamentalForm1st_Fns_2A_3D),
            dimensions(_FundamentalForm2nd_Fns_2A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local MinD =
        min(
            dimension_size(_FundamentalForm1st_Fns_2A_3D, 1),
            dimension_size(_FundamentalForm2nd_Fns_2A_3D, 1)
       )
    ;
    #if (MinD != 3)
        #error "MinD is not 3"
    #end // if
    #local MaxD =
        max(
            dimension_size(_FundamentalForm1st_Fns_2A_3D, 1),
            dimension_size(_FundamentalForm2nd_Fns_2A_3D, 1)
       )
    ;
    #if (MaxD != 3)
        #error "MaxD is not 3"
    #end // if

    // Formula: (E*N + G*L - 2*F*M)/(2*(E*G - F^2))

    DivideFunction_Safe_2A(
        SubtractFunction_2A(
            AddFunction_2A(
                MultiplyFunction_2A(
                    _FundamentalForm1st_Fns_2A_3D[0], // E
                    _FundamentalForm2nd_Fns_2A_3D[2]  // N
                ),
                MultiplyFunction_2A(
                    _FundamentalForm1st_Fns_2A_3D[2], // G
                    _FundamentalForm2nd_Fns_2A_3D[0]  // L
                )
            ),
            MultiplyFunction_Constant_2A(
                MultiplyFunction_2A(
                    _FundamentalForm1st_Fns_2A_3D[1], // F
                    _FundamentalForm2nd_Fns_2A_3D[1]  // M
                ),
                2
            )
        ),
        MultiplyFunction_Constant_2A(
            FundamentalForm1st_Determinant_2A_3D(
                _FundamentalForm1st_Fns_2A_3D
            ),
            2
        )
    )

#end // macro _AltMeanCurvatureFunction_2A_3D


#macro AltMeanCurvatureFunction_2A_3D(_D1_U_Fns_2A_3D, _D1_V_Fns_2A_3D, _D2_UU_Fns_2A_3D, _D2_UV_Fns_2A_3D, _D2_VV_Fns_2A_3D)

    #local M =
        max(
            dimensions(_D1_U_Fns_2A_3D),
            dimensions(_D1_V_Fns_2A_3D),
            dimensions(_D2_UU_Fns_2A_3D),
            dimensions(_D2_UV_Fns_2A_3D),
            dimensions(_D2_VV_Fns_2A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local MinD =
        min(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1),
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1)
       )
    ;
    #if (MinD != 3)
        #error "MinD is not 3"
    #end // if
    #local MaxD =
        max(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1),
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1)
       )
    ;
    #if (MaxD != 3)
        #error "MaxD is not 3"
    #end // if

    _AltMeanCurvatureFunction_2A_3D(
        FirstFundamentalFormFunctions_2A_3D(
            _D1_U_Fns_2A_3D,
            _D1_V_Fns_2A_3D
        ),
        SecondFundamentalFormFunctions_2A_3D(
            _D1_U_Fns_2A_3D, 
            _D1_V_Fns_2A_3D,
            _D2_UU_Fns_2A_3D,
            _D2_UV_Fns_2A_3D,
            _D2_VV_Fns_2A_3D
        )
    )

#end // macro AltMeanCurvatureFunction_2A_3D


#macro _MeanCurvatureFunction_2A_3D(_D1_U_Fns_2A_3D, _D1_V_Fns_2A_3D, _D2_UU_Fns_2A_3D, _D2_UV_Fns_2A_3D, _D2_VV_Fns_2A_3D, _Normal_Fns_2A_3D)

     #local M =
        max(
            dimensions(_D1_U_Fns_2A_3D),
            dimensions(_D1_V_Fns_2A_3D),
            dimensions(_D2_UU_Fns_2A_3D),
            dimensions(_D2_UV_Fns_2A_3D),
            dimensions(_D2_VV_Fns_2A_3D),
            dimensions(_Normal_Fns_2A_3D)
       )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local MinD =
        min(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1),
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1),
            dimension_size(_Normal_Fns_2A_3D, 1)
       )
    ;
    #if (MinD != 3)
        #error "MinD is not 3"
    #end // if
    #local MaxD =
        max(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1),
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1),
            dimension_size(_Normal_Fns_2A_3D, 1)
       )
    ;
    #if (MaxD != 3)
        #error "MaxD is not 3"
    #end // if

    // Formula: (E*N + G*L - 2*F*M)/(2*(N.N)^1.5)

    DivideFunction_Safe_2A(
        SubtractFunction_2A(
            AddFunction_2A(
                MultiplyFunction_2A(
                    DotFunction_2A_3D(_D1_U_Fns_2A_3D, _D1_U_Fns_2A_3D),   // E
                    DotFunction_2A_3D(_D2_VV_Fns_2A_3D, _Normal_Fns_2A_3D) // N
                ),
                MultiplyFunction_2A(
                    DotFunction_2A_3D(_D1_V_Fns_2A_3D, _D1_V_Fns_2A_3D),   // G
                    DotFunction_2A_3D(_D2_UU_Fns_2A_3D, _Normal_Fns_2A_3D) // L
                )
            ),
            MultiplyFunction_Constant_2A(
                MultiplyFunction_2A(
                    DotFunction_2A_3D(_D1_U_Fns_2A_3D, _D1_V_Fns_2A_3D),   // F
                    DotFunction_2A_3D(_D2_UV_Fns_2A_3D, _Normal_Fns_2A_3D) // M
                ),
                2
            )
        ),
        MultiplyFunction_Constant_2A(
            PowFunction_Constant_2A(
                DotFunction_2A_3D(_Normal_Fns_2A_3D, _Normal_Fns_2A_3D),
                1.5
            ),
            2
        )
    )

#end // macro _MeanCurvatureFunction_2A_3D


#macro MeanCurvatureFunction_2A_3D(_D1_U_Fns_2A_3D, _D1_V_Fns_2A_3D, _D2_UU_Fns_2A_3D, _D2_UV_Fns_2A_3D, _D2_VV_Fns_2A_3D)

    #local M =
        max(
            dimensions(_D1_U_Fns_2A_3D),
            dimensions(_D1_V_Fns_2A_3D),
            dimensions(_D2_UU_Fns_2A_3D),
            dimensions(_D2_UV_Fns_2A_3D),
            dimensions(_D2_VV_Fns_2A_3D)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local MinD =
        min(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1),
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1)
       )
    ;
    #if (MinD != 3)
        #error "MinD is not 3"
    #end // if
    #local MaxD =
        max(
            dimension_size(_D1_U_Fns_2A_3D, 1),
            dimension_size(_D1_V_Fns_2A_3D, 1),
            dimension_size(_D2_UU_Fns_2A_3D, 1),
            dimension_size(_D2_UV_Fns_2A_3D, 1),
            dimension_size(_D2_VV_Fns_2A_3D, 1)
        )
    ;
    #if (MaxD != 3)
        #error "MaxD is not 3"
    #end // if

    _MeanCurvatureFunction_2A_3D(
        _D1_U_Fns_2A_3D,
        _D1_V_Fns_2A_3D,
        _D2_UU_Fns_2A_3D,
        _D2_UV_Fns_2A_3D,
        _D2_VV_Fns_2A_3D,
        CrossFunctions_2A_3D(
            _D1_U_Fns_2A_3D,
            _D1_V_Fns_2A_3D
        )
    )

#end // macro MeanCurvatureFunction_2A_3D

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro Der1_RationalFunction_1A(_NumFn_1A, _DenFn_1A, _D1NumFn_1A, _D1DenFn_1A)

    function(_u) {
        (
            _D1NumFn_1A(_u)
            -
            _D1DenFn_1A(_u)
            *
            _NumFn_1A(_u)
            /
            _DenFn_1A(_u)
        )
        /
        _DenFn_1A(_u)
    }

#end // macro Der1_RationalFunction_1A


#macro Der1_RationalFunction_2A(_NumFn_2A, _DenFn_2A, _D1NumFn_2A, _D1DenFn_2A)

    function(_u, _v) {
        (
            _D1NumFn_2A(_u, _v)
            -
            _D1DenFn_2A(_u, _v)
            *
            _NumFn_2A(_u, _v)
            /
            _DenFn_2A(_u, _v)
        )
        /
        _DenFn_2A(_u, _v)
    }

#end // macro Der1_RationalFunction_2A


#macro Der1_RationalFunction_3A(_NumFn_3A, _DenFn_3A, _D1NumFn_3A, _D1DenFn_3A)

    function(_u, _v, _w) {
        (
            _D1NumFn_3A(_u, _v, _w)
            -
            _D1DenFn_3A(_u, _v, _w)
            *
            _NumFn_3A(_u, _v, _w)
            /
            _DenFn_3A(_u, _v, _w)
        )
        /
        _DenFn_3A(_u, _v, _w)
    }

#end // macro Der1_RationalFunction_3A


#macro Der1_RationalFunction_4A(_NumFn_4A, _DenFn_4A, _D1NumFn_4A, _D1DenFn_4A)

    function(_u, _v, _w, _s) {
        (
            _D1NumFn_4A(_u, _v, _w, _s)
            -
            _D1DenFn_4A(_u, _v, _w, _s)
            *
            _NumFn_4A(_u, _v, _w, _s)
            /
            _DenFn_4A(_u, _v, _w, _s)
        )
        /
        _DenFn_4A(_u, _v, _w, _s)
    }

#end // macro Der1_RationalFunction_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro Der2_RationalFunction_1A(_NumFn_1A, _DenFn_1A, _D1NumFn_1A, _D1DenFn_1A, _D2NumFn_1A, _D2DenFn_1A)

    function(_u) {
        (
            _D2NumFn_1A(_u)*pow(_DenFn_1A(_u), 2)
            -
            (
                2*_D1NumFn_1A(_u)*_D1DenFn_1A(_u)
                +
                _NumFn_1A(_u)*_D2DenFn_1A(_u)
            )*_DenFn_1A(_u)
            +
            2*_NumFn_1A(_u)*pow(_D1DenFn_1A(_u), 2)
        )/pow(_DenFn_1A(_u), 3)
    }

#end // macro Der2_RationalFunction_1A


#macro Der2_RationalFunction_2A(_NumFn_2A, _DenFn_2A, _D1NumFn_2A, _D1DenFn_2A, _D2NumFn_2A, _D2DenFn_2A)

    function(_u, _v) {
        (
            _D2NumFn_2A(_u, _v)*pow(_DenFn_2A(_u, _v), 2)
            -
            (
                2*_D1NumFn_2A(_u, _v)*_D1DenFn_2A(_u, _v)
                +
                _NumFn_2A(_u, _v)*_D2DenFn_2A(_u, _v)
            )*_DenFn_2A(_u, _v)
            + 
            2*_NumFn_2A(_u, _v)*pow(_D1DenFn_2A(_u, _v), 2)
        )/pow(_DenFn_2A(_u, _v), 3)
    }

#end // macro Der2_RationalFunction_2A


#macro Der2_RationalFunction_3A(_NumFn_3A, _DenFn_3A, _D1NumFn_3A, _D1DenFn_3A, _D2NumFn_3A, _D2DenFn_3A)

    function(_u, _v, _w) {
        (
            _D2NumFn_3A(_u, _v, _w)*pow(_DenFn_3A(_u, _v, _w), 2)
            -
            (
                2*_D1NumFn_3A(_u, _v, _w)*_D1DenFn_3A(_u, _v, _w)
                +
                _NumFn_3A(_u, _v, _w)*_D2DenFn_3A(_u, _v, _w)
            )*_DenFn_3A(_u, _v, _w)
            + 
            2*_NumFn_3A(_u, _v, _w)*pow(_D1DenFn_3A(_u, _v, _w), 2)
        )/pow(_DenFn_3A(_u, _v, _w), 3)
    }

#end // macro Der2_RationalFunction_3A


#macro Der2_RationalFunction_4A(_NumFn_4A, _DenFn_4A, _D1NumFn_4A, _D1DenFn_4A, _D2NumFn_4A, _D2DenFn_4A)

    function(_u, _v, _w, _s) {
        (
            _D2NumFn_4A(_u, _v, _w, _s)*pow(_DenFn_4A(_u, _v, _w, _s), 2)
            -
            (
                2*_D1NumFn_4A(_u, _v, _w, _s)*_D1DenFn_4A(_u, _v, _w, _s)
                +
                _NumFn_4A(_u, _v, _w, _s)*_D2DenFn_4A(_u, _v, _w, _s)
            )*_DenFn_4A(_u, _v, _w, _s)
            + 
            2*_NumFn_4A(_u, _v, _w, _s)*pow(_D1DenFn_4A(_u, _v, _w, _s), 2)
        )/pow(_DenFn_4A(_u, _v, _w, _s), 3)
    }

#end // macro Der2_RationalFunction_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro From_1A_SampleFunctions_1N_1D(_Fns_1A_1D, Min_U, Max_U, Res_U)

    #local M =
        max(
            dimensions(_Fns_1A_1D),
            dimensions(Min_U),
            dimensions(Max_U),
            dimensions(Res_U)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_1A_1D, 1);
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
    #local PP_1N_1D = array[ResU];
    #local U = MinU;
    #for (I, 0, ResU - 1)
        #local PP_1N_1D[I] =
            x_E(_Fns_1A_1D)(U)
        ;
        #local U = U + dU;
    #end // for

    PP_1N_1D

#end // From_1A_SampleFunctions_1N_1D


#macro From_1A_SampleFunctions_1N_2D(_Fns_1A_2D, Min_U, Max_U, Res_U)

    #local M =
        max(
            dimensions(_Fns_1A_2D),
            dimensions(Min_U),
            dimensions(Max_U),
            dimensions(Res_U)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_1A_2D, 1);
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
    #local PP_1N_2D = array[ResU];
    #local U = MinU;
    #for (I, 0, ResU - 1)
        #local PP_1N_2D[I] =
            <
                x_E(_Fns_1A_2D)(U),
                y_E(_Fns_1A_2D)(U)
            >
        ;
        #local U = U + dU;
    #end // for

    PP_1N_2D

#end // From_1A_SampleFunctions_1N_2D


#macro From_1A_SampleFunctions_1N_3D(_Fns_1A_3D, Min_U, Max_U, Res_U)

    #local M =
        max(
            dimensions(_Fns_1A_3D),
            dimensions(Min_U),
            dimensions(Max_U),
            dimensions(Res_U)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_1A_3D, 1);
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
    #local PP_1N_3D = array[ResU];
    #local U = MinU;
    #for (I, 0, ResU - 1)
        #local PP_1N_3D[I] =
            <
                x_E(_Fns_1A_3D)(U),
                y_E(_Fns_1A_3D)(U),
                z_E(_Fns_1A_3D)(U)
            >
        ;
        #local U = U + dU;
    #end // for

    PP_1N_3D

#end // From_1A_SampleFunctions_1N_3D


#macro From_1A_SampleFunctions_1N_4D(_Fns_1A_4D, Min_U, Max_U, Res_U)

    #local M =
        max(
            dimensions(_Fns_1A_4D),
            dimensions(Min_U),
            dimensions(Max_U),
            dimensions(Res_U)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_1A_4D, 1);
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
    #local PP_1N_4D = array[ResU];
    #local U = MinU;
    #for (I, 0, ResU - 1)
        #local PP_1N_4D[I] =
            <
                x_E(_Fns_1A_4D)(U),
                y_E(_Fns_1A_4D)(U),
                z_E(_Fns_1A_4D)(U),
                t_E(_Fns_1A_4D)(U)
            >
        ;
        #local U = U + dU;
    #end // for

    PP_1N_4D

#end // From_1A_SampleFunctions_1N_4D


#macro From_2A_SampleFunctions_2N_1D(_Fns_2A_1D, Min_UV, Max_UV, Res_UV)

    #local M =
        max(
            dimensions(_Fns_2A_1D),
            dimensions(Min_UV),
            dimensions(Max_UV),
            dimensions(Res_UV)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_2A_1D, 1);
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
    #local PP_2N_1D = array[ResU][ResV];
    #local V = MinV;
    #for (J, 0, ResV - 1)
        #local U = MinU;
        #for (I, 0, ResU - 1)
            #local PP_2N_1D[I][J] =
                x_E(_Fns_2A_1D)(U, V)
            ;
            #local U = U + dU;
        #end // for
        #local V = V + dV;
    #end // for

    PP_2N_1D

#end // From_2A_SampleFunctions_2N_1D


#macro From_2A_SampleFunctions_2N_2D(_Fns_2A_2D, Min_UV, Max_UV, Res_UV)

    #local M =
        max(
            dimensions(_Fns_2A_2D),
            dimensions(Min_UV),
            dimensions(Max_UV),
            dimensions(Res_UV)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_2A_2D, 1);
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
    #local PP_2N_2D = array[ResU][ResV];
    #local V = MinV;
    #for (J, 0, ResV - 1)
        #local U = MinU;
        #for (I, 0, ResU - 1)
            #local PP_2N_2D[I][J] =
                <
                    x_E(_Fns_2A_2D)(U, V),
                    y_E(_Fns_2A_2D)(U, V)
                >
            ;
            #local U = U + dU;
        #end // for
        #local V = V + dV;
    #end // for

    PP_2N_2D

#end // From_2A_SampleFunctions_2N_2D


#macro From_2A_SampleFunctions_2N_3D(_Fns_2A_3D, Min_UV, Max_UV, Res_UV)

    #local M =
        max(
            dimensions(_Fns_2A_3D),
            dimensions(Min_UV),
            dimensions(Max_UV),
            dimensions(Res_UV)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_2A_3D, 1);
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
    #local PP_2N_3D = array[ResU][ResV];
    #local V = MinV;
    #for (J, 0, ResV - 1)
        #local U = MinU;
        #for (I, 0, ResU - 1)
            #local PP_2N_3D[I][J] =
                <
                    x_E(_Fns_2A_3D)(U, V),
                    y_E(_Fns_2A_3D)(U, V),
                    z_E(_Fns_2A_3D)(U, V)
                >
            ;
            #local U = U + dU;
        #end // for
        #local V = V + dV;
    #end // for

    PP_2N_3D

#end // From_2A_SampleFunctions_2N_3D


#macro From_2A_SampleFunctions_2N_4D(_Fns_2A_4D, Min_UV, Max_UV, Res_UV)

    #local M =
        max(
            dimensions(_Fns_2A_4D),
            dimensions(Min_UV),
            dimensions(Max_UV),
            dimensions(Res_UV)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_2A_4D, 1);
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
    #local PP_2N_4D = array[ResU][ResV];
    #local V = MinV;
    #for (J, 0, ResV - 1)
        #local U = MinU;
        #for (I, 0, ResU - 1)
            #local PP_2N_4D[I][J] =
                <
                    x_E(_Fns_2A_4D)(U, V),
                    y_E(_Fns_2A_4D)(U, V),
                    z_E(_Fns_2A_4D)(U, V),
                    t_E(_Fns_2A_4D)(U, V)
                >
            ;
            #local U = U + dU;
        #end // for
        #local V = V + dV;
    #end // for

    PP_2N_4D

#end // From_2A_SampleFunctions_2N_4D


#macro From_3A_SampleFunctions_3N_1D(_Fns_3A_1D, Min_UVW, Max_UVW, Res_UVW)

    #local M =
        max(
            dimensions(_Fns_3A_1D),
            dimensions(Min_UVW),
            dimensions(Max_UVW),
            dimensions(Res_UVW)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_3A_1D, 1);
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
    #local PP_3N_1D = array[ResU][ResV][ResW];
    #local W = MinW;
    #for (K, 0, ResW - 1)
        #local V = MinV;
        #for (J, 0, ResV - 1)
            #local U = MinU;
            #for (I, 0, ResU - 1)
                #local PP_3N_1D[I][J][K] =
                    x_E(_Fns_3A_1D)(U, V, W)
                ;
                #local U = U + dU;
            #end // for
            #local V = V + dV;
        #end // for
        #local W = W + dW;
    #end // for

    PP_3N_1D

#end // From_3A_SampleFunctions_3N_1D


#macro From_3A_SampleFunctions_3N_2D(_Fns_3A_2D, Min_UVW, Max_UVW, Res_UVW)

    #local M =
        max(
            dimensions(_Fns_3A_2D),
            dimensions(Min_UVW),
            dimensions(Max_UVW),
            dimensions(Res_UVW)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_3A_2D, 1);
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
    #local PP_3N_2D = array[ResU][ResV][ResW];
    #local W = MinW;
    #for (K, 0, ResW - 1)
        #local V = MinV;
        #for (J, 0, ResV - 1)
            #local U = MinU;
            #for (I, 0, ResU - 1)
                #local PP_3N_2D[I][J][K] =
                    <
                        x_E(_Fns_3A_2D)(U, V, W),
                        y_E(_Fns_3A_2D)(U, V, W)
                    >
                ;
                #local U = U + dU;
            #end // for
            #local V = V + dV;
        #end // for
        #local W = W + dW;
    #end // for

    PP_3N_2D

#end // From_3A_SampleFunctions_3N_2D


#macro From_3A_SampleFunctions_3N_3D(_Fns_3A_3D, Min_UVW, Max_UVW, Res_UVW)

    #local M =
        max(
            dimensions(_Fns_3A_3D),
            dimensions(Min_UVW),
            dimensions(Max_UVW),
            dimensions(Res_UVW)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_3A_3D, 1);
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
    #local PP_3N_3D = array[ResU][ResV][ResW];
    #local W = MinW;
    #for (K, 0, ResW - 1)
        #local V = MinV;
        #for (J, 0, ResV - 1)
            #local U = MinU;
            #for (I, 0, ResU - 1)
                #local PP_3N_3D[I][J][K] =
                    <
                        x_E(_Fns_3A_3D)(U, V, W),
                        y_E(_Fns_3A_3D)(U, V, W),
                        z_E(_Fns_3A_3D)(U, V, W)
                    >
                ;
                #local U = U + dU;
            #end // for
            #local V = V + dV;
        #end // for
        #local W = W + dW;
    #end // for

    PP_3N_3D

#end // From_3A_SampleFunctions_3N_3D


#macro From_3A_SampleFunctions_3N_4D(_Fns_3A_4D, Min_UVW, Max_UVW, Res_UVW)

    #local M =
        max(
            dimensions(_Fns_3A_4D),
            dimensions(Min_UVW),
            dimensions(Max_UVW),
            dimensions(Res_UVW)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_3A_4D, 1);
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
    #local PP_3N_4D = array[ResU][ResV][ResW];
    #local W = MinW;
    #for (K, 0, ResW - 1)
        #local V = MinV;
        #for (J, 0, ResV - 1)
            #local U = MinU;
            #for (I, 0, ResU - 1)
                #local PP_3N_4D[I][J][K] =
                    <
                        x_E(_Fns_3A_4D)(U, V, W),
                        y_E(_Fns_3A_4D)(U, V, W),
                        z_E(_Fns_3A_4D)(U, V, W),
                        t_E(_Fns_3A_4D)(U, V, W)
                    >
                ;
                #local U = U + dU;
            #end // for
            #local V = V + dV;
        #end // for
        #local W = W + dW;
    #end // for

    PP_3N_4D

#end // From_3A_SampleFunctions_3N_4D


#macro From_4A_SampleFunctions_4N_1D(_Fns_4A_1D, Min_UVWS, Max_UVWS, Res_UVWS)

    #local M =
        max(
            dimensions(_Fns_4A_1D),
            dimensions(Min_UVWS),
            dimensions(Max_UVWS),
            dimensions(Res_UVWS)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_4A_1D, 1);
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
    #local PP_4N_1D = array[ResU][ResV][ResW][ResS];
    #local S = MinS;
    #for (L, 0, ResS - 1)
        #local W = MinW;
        #for (K, 0, ResW - 1)
            #local V = MinV;
            #for (J, 0, ResV - 1)
                #local U = MinU;
                #for (I, 0, ResU - 1)
                    #local PP_4N_1D[I][J][K][L] =
                        x_E(_Fns_4A_1D)(U, V, W, S)
                    ;
                    #local U = U + dU;
                #end // for
                #local V = V + dV;
            #end // for
            #local W = W + dW;
        #end // for
        #local S = S + dS;
    #end // for

    PP_4N_1D

#end // From_4A_SampleFunctions_4N_1D


#macro From_4A_SampleFunctions_4N_2D(_Fns_4A_2D, Min_UVWS, Max_UVWS, Res_UVWS)

    #local M =
        max(
            dimensions(_Fns_4A_2D),
            dimensions(Min_UVWS),
            dimensions(Max_UVWS),
            dimensions(Res_UVWS)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_4A_2D, 1);
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
    #local PP_4N_2D = array[ResU][ResV][ResW][ResS];
    #local S = MinS;
    #for (L, 0, ResS - 1)
        #local W = MinW;
        #for (K, 0, ResW - 1)
            #local V = MinV;
            #for (J, 0, ResV - 1)
                #local U = MinU;
                #for (I, 0, ResU - 1)
                    #local PP_4N_2D[I][J][K][L] =
                        <
                            x_E(_Fns_4A_2D)(U, V, W, S),
                            y_E(_Fns_4A_2D)(U, V, W, S)
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

    PP_4N_2D

#end // From_4A_SampleFunctions_4N_2D


#macro From_4A_SampleFunctions_4N_3D(_Fns_4A_3D, Min_UVWS, Max_UVWS, Res_UVWS)

    #local M =
        max(
            dimensions(_Fns_4A_3D),
            dimensions(Min_UVWS),
            dimensions(Max_UVWS),
            dimensions(Res_UVWS)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_4A_3D, 1);
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
    #local PP_4N_3D = array[ResU][ResV][ResW][ResS];
    #local S = MinS;
    #for (L, 0, ResS - 1)
        #local W = MinW;
        #for (K, 0, ResW - 1)
            #local V = MinV;
            #for (J, 0, ResV - 1)
                #local U = MinU;
                #for (I, 0, ResU - 1)
                    #local PP_4N_3D[I][J][K][L] =
                        <
                            x_E(_Fns_4A_3D)(U, V, W, S),
                            y_E(_Fns_4A_3D)(U, V, W, S),
                            z_E(_Fns_4A_3D)(U, V, W, S)
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

    PP_4N_3D

#end // From_4A_SampleFunctions_4N_3D


#macro From_4A_SampleFunctions_4N_4D(_Fns_4A_4D, Min_UVWS, Max_UVWS, Res_UVWS)

    #local M =
        max(
            dimensions(_Fns_4A_4D),
            dimensions(Min_UVWS),
            dimensions(Max_UVWS),
            dimensions(Res_UVWS)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Fns_4A_4D, 1);
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
    #local PP_4N_4D = array[ResU][ResV][ResW][ResS];
    #local S = MinS;
    #for (L, 0, ResS - 1)
        #local W = MinW;
        #for (K, 0, ResW - 1)
            #local V = MinV;
            #for (J, 0, ResV - 1)
                #local U = MinU;
                #for (I, 0, ResU - 1)
                    #local PP_4N_4D[I][J][K][L] =
                        <
                            x_E(_Fns_4A_4D)(U, V, W, S),
                            y_E(_Fns_4A_4D)(U, V, W, S),
                            z_E(_Fns_4A_4D)(U, V, W, S),
                            t_E(_Fns_4A_4D)(U, V, W, S)
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

    PP_4N_4D

#end // From_4A_SampleFunctions_4N_4D


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
    #switch (D)
        #case (1)  // 1D
            #switch (A)
                #case (1)  // 1A (1N)
                    #local PP =
                        From_1A_SampleFunctions_1N_1D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (2)  // 2A (2N)
                    #local PP =
                        From_2A_SampleFunctions_2N_1D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (3)  // 3A (3N)
                    #local PP =
                        From_3A_SampleFunctions_3N_1D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (4)  // 4A (4N)
                    #local PP =
                        From_4A_SampleFunctions_4N_1D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #else
                    #error "A is neither 1, 2, 3 nor 4"
            #end // switch
            #break
        #case (2)  // 2D
            #switch (A)
                #case (1)  // 1A (1N)
                    #local PP =
                        From_1A_SampleFunctions_1N_2D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (2)  // 2A (2N)
                    #local PP =
                        From_2A_SampleFunctions_2N_2D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (3)  // 3A (3N)
                    #local PP =
                        From_3A_SampleFunctions_3N_2D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (4)  // 4A (4N)
                    #local PP =
                        From_4A_SampleFunctions_4N_2D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #else
                    #error "A is neither 1, 2, 3 nor 4"
            #end // switch
            #break
        #case (3)  // 3D
            #switch (A)
                #case (1)  // 1A (1N)
                    #local PP =
                        From_1A_SampleFunctions_1N_3D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (2)  // 2A (2N)
                    #local PP =
                        From_2A_SampleFunctions_2N_3D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (3)  // 3A (3N)
                    #local PP =
                        From_3A_SampleFunctions_3N_3D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (4)  // 4A (4N)
                    #local PP =
                        From_4A_SampleFunctions_4N_3D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #else
                    #error "A is neither 1, 2, 3 nor 4"
            #end // switch
            #break
        #case (4)  // 4D
            #switch (A)
                #case (1)  // 1A (1N)
                    #local PP =
                        From_1A_SampleFunctions_1N_4D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (2)  // 2A (2N)
                    #local PP =
                        From_2A_SampleFunctions_2N_4D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (3)  // 3A (3N)
                    #local PP =
                        From_3A_SampleFunctions_3N_4D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #case (4)  // 4A (4N)
                    #local PP =
                        From_4A_SampleFunctions_4N_4D(
                            _Functions, Min, Max, Res
                        )
                    ;
                    #break
                #else
                    #error "A is neither 1, 2, 3 nor 4"
            #end // switch
            #break
        #else
            #error "D is neither 1, 2, 3 nor 4"
    #end // switch

#end // SampleFunctions

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B
