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

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

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

#macro MultiplyFunctions_1A(_Fn0_1A, _Fn1_1A)

    function(_u) {
        _Fn0_1A(_u)
        *
        _Fn1_1A(_u)
    }

#end // macro MultiplyFunctions_1A


#macro MultiplyFunctions_2A(_Fn0_2A, _Fn1_2A)

    function(_u, _v) {
        _Fn0_2A(_u, _v)
        *
        _Fn1_2A(_u, _v)
    }

#end // macro MultiplyFunctions_2A


#macro MultiplyFunctions_3A(_Fn0_3A, _Fn1_3A)

    function(_u, _v, _w) {
        _Fn0_3A(_u, _v, _w)
        *
        _Fn1_3A(_u, _v, _w)
    }

#end // macro MultiplyFunctions_3A


#macro MultiplyFunctions_4A(_Fn0_4A, _Fn1_4A)

    function(_u, _v, _w, _s) {
        _Fn0_4A(_u, _v, _w, _s)
        *
        _Fn1_4A(_u, _v, _w, _s)
    }

#end // macro MultiplyFunctions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro DivideFunctions_1A(_Num_Fn_1A, _Den_Fn_1A)

    function(_u) {
        _Num_Fn_1A(_u)
        /
        _Den_Fn_1A(_u)
    }

#end // macro DivideFunctions_1A


#macro DivideFunctions_2A(_Num_Fn_2A, _Den_Fn_2A)

    function(_u, _v) {
        _Num_Fn_2A(_u, _v)
        /
        _Den_Fn_2A(_u, _v)
    }

#end // macro DivideFunctions_2A


#macro DivideFunctions_3A(_Num_Fn_3A, _Den_Fn_3A)

    function(_u, _v, _w) {
        _Num_Fn_3A(_u, _v, _w)
        /
        _Den_Fn_3A(_u, _v, _w)
    }

#end // macro DivideFunctions_3A


#macro DivideFunctions_4A(_Num_Fn_4A, _Den_Fn_4A)

    function(_u, _v, _w, _s) {
        _Num_Fn_4A(_u, _v, _w, _s)
        /
        _Den_Fn_4A(_u, _v, _w, _s)
    }

#end // macro DivideFunctions_4A


#macro DivideFunctions_Safe_1A(_Num_Fn_1A, _Den_Fn_1A)

    function(_u) {
        _Num_Fn_1A(_u)
        /
        AvoidZeroFn(
            _Den_Fn_1A(_u)
        )
    }

#end // macro DivideFunctions_Safe_1A


#macro DivideFunctions_Safe_2A(_Num_Fn_2A, _Den_Fn_2A)

    function(_u, _v) {
        _Num_Fn_2A(_u, _v)
        /
        AvoidZeroFn(
            _Den_Fn_2A(_u, _v)
        )
    }

#end // macro DivideFunctions_Safe_2A


#macro DivideFunctions_Safe_3A(_Num_Fn_3A, _Den_Fn_3A)

    function(_u, _v, _w) {
        _Num_Fn_3A(_u, _v, _w)
        /
        AvoidZeroFn(
            _Den_Fn_3A(_u, _v, _w)
        )
    }

#end // macro DivideFunctions_Safe_3A


#macro DivideFunctions_Safe_4A(_Num_Fn_4A, _Den_Fn_4A)

    function(_u, _v, _w, _s) {
        _Num_Fn_4A(_u, _v, _w, _s)
        /
        AvoidZeroFn(
            _Den_Fn_4A(_u, _v, _w, _s)
        )
    }

#end // macro DivideFunctions_Safe_4A

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
    #if (!((D = 1) | (D = 2) | (D = 3) | (D = 4)))
        #error "D is neither 1, 2, 3 nor 4"
    #end // if

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
            #error "!"
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
    #if (!((D = 1) | (D = 2) | (D = 3) | (D = 4)))
        #error "D is neither 1, 2, 3 nor 4"
    #end // if

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
            #error "!"
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
    #if (!((D = 1) | (D = 2) | (D = 3) | (D = 4)))
        #error "D is neither 1, 2, 3 nor 4"
    #end // if

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
            #error "!"
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
    #if (!((D = 1) | (D = 2) | (D = 3) | (D = 4)))
        #error "D is neither 1, 2, 3 nor 4"
    #end // if

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
            #error "!"
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
                    #error "!"
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
                    #error "!"
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
                    #error "!"
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
                    #error "!"
            #end // switch
            #break
        #else
            #error "!"
    #end // switch

#end // SampleFunctions

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B
