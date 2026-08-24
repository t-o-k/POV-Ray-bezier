// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A
/*

https://github.com/t-o-k/POV-Ray-bezier

Copyright (c) 2025-2026 Tor Olav Kristensen, http://subcube.com

Use of this source code is governed by the GNU Lesser General Public License version 3,
which can be found in the LICENSE file.

*/
// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#version 3.7;

#declare NUM_DIFF_STEP_SIZE = 1e-4;

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_DerU_Function_1A(_Function_1A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;

    function(_u) {
        (
            _Function_1A(_u + H)
            -
            _Function_1A(_u - H)
        )/H2
    }

#end // macro Est_DerU_Function_1A


#macro Est_Der1_Functions_1A(_Function_1A)

    Arr_1E(
        Est_DerU_Function_1A(_Function_1A)
    )

#end // macro Est_Der1_Functions_1A


#macro Est_GradientMagnitude_Function_1A(_Function_1A)

    _LengthFunction_1A_1D(
        Est_Der1_Functions_1A(_Function_1A)
    )

#end // Est_GradientMagnitude_Function_1A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_DerU_Function_2A(_Function_2A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;

    function(_u, _v) {
        (
            _Function_2A(_u + H, _v)
            -
            _Function_2A(_u - H, _v)
        )/H2
    }

#end // macro Est_DerU_Function_2A


#macro Est_DerV_Function_2A(_Function_2A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;

    function(_u, _v) {
        (
            _Function_2A(_u, _v + H)
            -
            _Function_2A(_u, _v - H)
        )/H2
    }

#end // macro Est_DerV_Function_2A


#macro Est_Der1_Functions_2A(_Function_2A)

    Arr_2E(
        Est_DerU_Function_2A(_Function_2A),
        Est_DerV_Function_2A(_Function_2A)
    )

#end // macro Est_Der1_Functions_2A


#macro Est_GradientMagnitude_Function_2A(_Function_2A)

    _LengthFunction_2A_2D(
        Est_Der1_Functions_2A(_Function_2A)
    )

#end // Est_GradientMagnitude_Function_2A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_DerU_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;

    function(_u, _v, _w) {
        (
            _Function_3A(_u + H, _v, _w)
            -
            _Function_3A(_u - H, _v, _w)
        )/H2
    }

#end // macro Est_DerU_Function_3A


#macro Est_DerV_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;

    function(_u, _v, _w) {
        (
            _Function_3A(_u, _v + H, _w)
            -
            _Function_3A(_u, _v - H, _w)
        )/H2
    }

#end // macro Est_DerV_Function_3A


#macro Est_DerW_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;

    function(_u, _v, _w) {
        (
            _Function_3A(_u, _v, _w + H)
            -
            _Function_3A(_u, _v, _w - H)
        )/H2
    }

#end // macro Est_DerW_Function_3A


#macro Est_Der1_Functions_3A(_Function_3A)

    Arr_3E(
        Est_DerU_Function_3A(_Function_3A),
        Est_DerV_Function_3A(_Function_3A),
        Est_DerW_Function_3A(_Function_3A)
    )

#end // macro Est_Der1_Functions_3A


#macro Est_GradientMagnitude_Function_3A(_Function_3A)

    _LengthFunction_3A_3D(
        Est_Der1_Functions_3A(_Function_3A)
    )

#end // Est_GradientMagnitude_Function_3A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_DerU_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;

    function(_u, _v, _w, _s) {
        (
            _Function_4A(_u + H, _v, _w, _s)
            -
            _Function_4A(_u - H, _v, _w, _s)
        )/H2
    }

#end // macro Est_DerU_Function_4A


#macro Est_DerV_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;

    function(_u, _v, _w, _s) {
        (
            _Function_4A(_u, _v + H, _w, _s)
            -
            _Function_4A(_u, _v - H, _w, _s)
        )/H2
    }

#end // macro Est_DerV_Function_4A


#macro Est_DerW_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;

    function(_u, _v, _w, _s) {
        (
            _Function_4A(_u, _v, _w + H, _s)
            -
            _Function_4A(_u, _v, _w - H, _s)
        )/H2
    }

#end // macro Est_DerW_Function_4A


#macro Est_DerS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;

    function(_u, _v, _w, _s) {
        (
            _Function_4A(_u, _v, _w, _s + H)
            -
            _Function_4A(_u, _v, _w, _s - H)
        )/H2
    }

#end // macro Est_DerS_Function_4A


#macro Est_Der1_Functions_4A(_Function_4A)

    Arr_4E(
        Est_DerU_Function_4A(_Function_4A),
        Est_DerV_Function_4A(_Function_4A),
        Est_DerW_Function_4A(_Function_4A),
        Est_DerS_Function_4A(_Function_4A)
    )

#end // macro Est_Der1_Functions_4A


#macro Est_GradientMagnitude_Function_4A(_Function_4A)

    _LengthFunction_4A_4D(
        Est_Der1_Functions_4A(_Function_4A)
    )

#end // Est_GradientMagnitude_Function_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_DerUU_Function_1A(_Function_1A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H, 2);

    function(_u) {
        (
            (
                _Function_1A(_u + H)
                +
                _Function_1A(_u - H)
            )
            -
            _Function_1A(_u)*2
        )/HH
    }

#end // macro Est_DerUU_Function_1A


#macro Est_Der2_Functions_1A(_Function_1A)

    Arr_1E(
        Est_DerUU_Function_1A(_Function_1A)
    )

#end // macro Est_Der2_Functions_1A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_DerUU_Function_2A(_Function_2A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H, 2);

    function(_u, _v) {
        (
            (
                _Function_2A(_u + H, _v)
                +
                _Function_2A(_u - H, _v)
            )
            -
            _Function_2A(_u, _v)*2
        )/HH
    }

#end // macro Est_DerUU_Function_2A


#macro Est_DerUV_Function_2A(_Function_2A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH4 = pow(H, 2)*4;

    function(_u, _v) {
        (
            (
                _Function_2A(_u + H, _v + H)
                -
                _Function_2A(_u + H, _v - H)
            )
            -
            (
                _Function_2A(_u - H, _v + H)
                -
                _Function_2A(_u - H, _v - H)
            )
        )/HH4
    }

#end // macro Est_DerUV_Function_2A


#macro Est_DerVV_Function_2A(_Function_2A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H, 2);

    function(_u, _v) {
        (
            (
                _Function_2A(_u, _v + H)
                +
                _Function_2A(_u, _v - H)
            )
            -
            _Function_2A(_u, _v)*2
        )/HH
    }

#end // macro Est_DerVV_Function_2A


#macro Est_Der2_Functions_2A(_Function_2A)

    Arr_3E(
        Est_DerUU_Function_2A(_Function_2A),
        Est_DerUV_Function_2A(_Function_2A),
        Est_DerVV_Function_2A(_Function_2A)
    )

#end // macro Est_Der2_Functions_2A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_DerUU_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H, 2);

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u + H, _v, _w)
                +
                _Function_3A(_u - H, _v, _w)
            )
            -
            _Function_3A(_u, _v, _w)*2
        )/HH
    }

#end // macro Est_DerUU_Function_3A


#macro Est_DerUV_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH4 = pow(H, 2)*4;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u + H, _v + H, _w)
                -
                _Function_3A(_u + H, _v - H, _w)
            )
            -
            (
                _Function_3A(_u - H, _v + H, _w)
                -
                _Function_3A(_u - H, _v - H, _w)
            )
        )/HH4
    }

#end // macro Est_DerUV_Function_3A


#macro Est_DerUW_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH4 = pow(H, 2)*4;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u + H, _v, _w + H)
                -
                _Function_3A(_u + H, _v, _w - H)
            )
            -
            (
                _Function_3A(_u - H, _v, _w + H)
                -
                _Function_3A(_u - H, _v, _w - H)
            )
        )/HH4
    }

#end // macro Est_DerUW_Function_3A


#macro Est_DerVV_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H, 2);

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u, _v + H, _w)
                +
                _Function_3A(_u, _v - H, _w)
            )
            -
            _Function_3A(_u, _v, _w)*2
        )/HH
    }

#end // macro Est_DerVV_Function_3A


#macro Est_DerVW_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH4 = pow(H, 2)*4;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u, _v + H, _w + H)
                -
                _Function_3A(_u, _v + H, _w - H)
            )
            -
            (
                _Function_3A(_u, _v - H, _w + H)
                -
                _Function_3A(_u, _v - H, _w - H)
            )
        )/HH4
    }

#end // macro Est_DerVW_Function_3A


#macro Est_DerWW_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H, 2);

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u, _v, _w + H)
                +
                _Function_3A(_u, _v, _w - H)
            )
            -
            _Function_3A(_u, _v, _w)*2
        )/HH
    }

#end // Est_DerWW_Function_3A


#macro Est_Der2_Functions_3A(_Function_3A)

    Arr_6E(
        Est_DerUU_Function_3A(_Function_3A),
        Est_DerUV_Function_3A(_Function_3A),
        Est_DerUW_Function_3A(_Function_3A),
        Est_DerVV_Function_3A(_Function_3A),
        Est_DerVW_Function_3A(_Function_3A),
        Est_DerWW_Function_3A(_Function_3A)
    )

#end // macro Est_Der2_Functions_3A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_DerUU_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H, 2);

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H, _v, _w, _s)
                +
                _Function_4A(_u - H, _v, _w, _s)
            )
            -
            _Function_4A(_u, _v, _w, _s)*2
        )/HH
    }

#end // macro Est_DerUU_Function_4A


#macro Est_DerUV_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH4 = pow(H, 2)*4;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H, _v + H, _w, _s)
                -
                _Function_4A(_u + H, _v - H, _w, _s)
            )
            -
            (
                _Function_4A(_u - H, _v + H, _w, _s)
                -
                _Function_4A(_u - H, _v - H, _w, _s)
            )
        )/HH4
    }

#end // macro Est_DerUV_Function_4A


#macro Est_DerUW_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH4 = pow(H, 2)*4;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H, _v, _w + H, _s)
                -
                _Function_4A(_u + H, _v, _w - H, _s)
            )
            -
            (
                _Function_4A(_u - H, _v, _w + H, _s)
                -
                _Function_4A(_u - H, _v, _w - H, _s)
            )
        )/HH4
    }

#end // macro Est_DerUW_Function_4A


#macro Est_DerUS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH4 = pow(H, 2)*4;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H, _v, _w, _s + H)
                -
                _Function_4A(_u + H, _v, _w, _s - H)
            )
            -
            (
                _Function_4A(_u - H, _v, _w, _s + H)
                -
                _Function_4A(_u - H, _v, _w, _s - H)
            )
        )/HH4
    }

#end // macro Est_DerUS_Function_4A


#macro Est_DerVV_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H, 2);

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v + H, _w, _s)
                +
                _Function_4A(_u, _v - H, _w, _s)
            )
            -
            _Function_4A(_u, _v, _w, _s)*2
        )/HH
    }

#end // macro Est_DerVV_Function_4A


#macro Est_DerVW_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH4 = pow(H, 2)*4;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v + H, _w + H, _s)
                -
                _Function_4A(_u, _v + H, _w - H, _s)
            )
            -
            (
                _Function_4A(_u, _v - H, _w + H, _s)
                -
                _Function_4A(_u, _v - H, _w - H, _s)
            )
        )/HH4
    }

#end // macro Est_DerVW_Function_4A


#macro Est_DerVS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH4 = pow(H, 2)*4;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v + H, _w, _s + H)
                -
                _Function_4A(_u, _v + H, _w, _s - H)
            )
            -
            (
                _Function_4A(_u, _v - H, _w, _s + H)
                -
                _Function_4A(_u, _v - H, _w, _s - H)
            )
        )/HH4
    }

#end // macro Est_DerVS_Function_4A


#macro Est_DerWW_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H, 2);

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v, _w + H, _s)
                +
                _Function_4A(_u, _v, _w - H, _s)
            )
            -
            _Function_4A(_u, _v, _w, _s)*2
        )/HH
    }

#end // macro Est_DerWW_Function_4A


#macro Est_DerWS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH4 = pow(H, 2)*4;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v, _w + H, _s + H)
                -
                _Function_4A(_u, _v, _w + H, _s - H)
            )
            -
            (
                _Function_4A(_u, _v, _w - H, _s + H)
                -
                _Function_4A(_u, _v, _w - H, _s - H)
            )
        )/HH4
    }

#end // macro Est_DerWS_Function_4A


#macro Est_DerSS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H, 2);

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v, _w, _s + H)
                +
                _Function_4A(_u, _v, _w, _s - H)
            )
            -
            _Function_4A(_u, _v, _w, _s)*2
        )/HH
    }

#end // macro Est_DerSS_Function_4A


#macro Est_Der2_Functions_4A(_Function_4A)

    Arr_10E(
        Est_DerUU_Function_4A(_Function_4A),
        Est_DerUV_Function_4A(_Function_4A),
        Est_DerUW_Function_4A(_Function_4A),
        Est_DerUS_Function_4A(_Function_4A),
        Est_DerVV_Function_4A(_Function_4A),
        Est_DerVW_Function_4A(_Function_4A),
        Est_DerVS_Function_4A(_Function_4A),
        Est_DerWW_Function_4A(_Function_4A),
        Est_DerWS_Function_4A(_Function_4A),
        Est_DerSS_Function_4A(_Function_4A)
    )

#end // macro Est_Der2_Functions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_DerUUU_Function_1A(_Function_1A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HHH2 = pow(H, 3)*2;

    function(_u) {
        (
            (
                _Function_1A(_u + H2)
                -
                _Function_1A(_u - H2)
            )
            -
            (
                _Function_1A(_u + H)
                -
                _Function_1A(_u - H)
            )*2
        )/HHH2
    }

#end // macro Est_DerUUU_Function_1A


#macro Est_Der3_Functions_1A(_Function_1A)

    Arr_1E(
        Est_DerUUU_Function_1A(_Function_1A)
    )

#end // macro Est_Der3_Functions_1A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_DerUUU_Function_2A(_Function_2A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v) {
        (
            (
                _Function_2A(_u + H2, _v)
                -
                _Function_2A(_u - H2, _v)
            )
            -
            (
                _Function_2A(_u + H, _v)
                -
                _Function_2A(_u - H, _v)
            )*2
        )/HHH2
    }

#end // macro Est_DerUUU_Function_2A


#macro Est_DerUUV_Function_2A(_Function_2A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v) {
        (
            (
                _Function_2A(_u + H, _v + H)
                -
                _Function_2A(_u + H, _v - H)
            )
            -
            (
                _Function_2A(_u, _v + H)
                -
                _Function_2A(_u, _v - H)
            )*2
            +
            (
                _Function_2A(_u - H, _v + H)
                -
                _Function_2A(_u - H, _v - H)
            )
        )/HHH2
    }

#end // macro Est_DerUUV_Function_2A


#macro Est_DerUVV_Function_2A(_Function_2A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v) {
        (
            (
                _Function_2A(_u + H, _v + H)
                -
                _Function_2A(_u - H, _v + H)
            )
            -
            (
                _Function_2A(_u + H, _v)
                -
                _Function_2A(_u - H, _v)
            )*2
            +
            (
                _Function_2A(_u + H, _v - H)
                -
                _Function_2A(_u - H, _v - H)
            )
        )/HHH2
    }

#end // macro Est_DerUVV_Function_2A


#macro Est_DerVVV_Function_2A(_Function_2A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v) {
        (
            (
                _Function_2A(_u, _v + H2)
                -
                _Function_2A(_u, _v - H2)
            )
            -
            (
                _Function_2A(_u, _v + H)
                -
                _Function_2A(_u, _v - H)
            )*2
        )/HHH2
    }

#end // macro Est_DerVVV_Function_2A


#macro Est_Der3_Functions_2A(_Function_2A)

    Arr_4E(
        Est_DerUUU_Function_2A(_Function_2A),
        Est_DerUUV_Function_2A(_Function_2A),
        Est_DerUVV_Function_2A(_Function_2A),
        Est_DerVVV_Function_2A(_Function_2A)
    )

#end // macro Est_Der3_Functions_2A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_DerUUU_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u + H2, _v, _w)
                -
                _Function_3A(_u - H2, _v, _w)
            )
            -
            (
                _Function_3A(_u + H, _v, _w)
                -
                _Function_3A(_u - H, _v, _w)
            )*2
        )/HHH2
    }

#end // macro Est_DerUUU_Function_3A


#macro Est_DerUUV_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u + H, _v + H, _w)
                -
                _Function_3A(_u + H, _v - H, _w)
            )
            -
            (
                _Function_3A(_u, _v + H, _w)
                -
                _Function_3A(_u, _v - H, _w)
            )*2
            +
            (
                _Function_3A(_u - H, _v + H, _w)
                -
                _Function_3A(_u - H, _v - H, _w)
            )
        )/HHH2
    }

#end // macro Est_DerUUV_Function_3A


#macro Est_DerUUW_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u + H, _v, _w + H)
                -
                _Function_3A(_u + H, _v, _w - H)
            )
            -
            (
                _Function_3A(_u, _v, _w + H)
                -
                _Function_3A(_u, _v, _w - H)
            )*2
            +
            (
                _Function_3A(_u - H, _v, _w + H)
                -
                _Function_3A(_u - H, _v, _w - H)
            )
        )/HHH2
    }

#end // macro Est_DerUUW_Function_3A


#macro Est_DerUVV_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u + H, _v + H, _w)
                -
                _Function_3A(_u - H, _v + H, _w)
            )
            -
            (
                _Function_3A(_u + H, _v, _w)
                -
                _Function_3A(_u - H, _v, _w)
            )*2
            +
            (
                _Function_3A(_u + H, _v - H, _w)
                -
                _Function_3A(_u - H, _v - H, _w)
            )
        )/HHH2
    }

#end // macro Est_DerUVV_Function_3A


#macro Est_DerUVW_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH8 = pow(H, 3)*8;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u + H, _v + H, _w + H)
                -
                _Function_3A(_u + H, _v + H, _w - H)
                -
                _Function_3A(_u + H, _v - H, _w + H)
                +
                _Function_3A(_u + H, _v - H, _w - H)
            )
            -
            (
                _Function_3A(_u - H, _v + H, _w + H)
                -
                _Function_3A(_u - H, _v + H, _w - H)
                -
                _Function_3A(_u - H, _v - H, _w + H)
                +
                _Function_3A(_u - H, _v - H, _w - H)
            )
        )/HHH8
    }

#end // macro Est_DerUVW_Function_3A


#macro Est_DerUWW_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u + H, _v, _w + H)
                -
                _Function_3A(_u - H, _v, _w + H)
            )
            -
            (
                _Function_3A(_u + H, _v, _w)
                -
                _Function_3A(_u - H, _v, _w)
            )*2
            +
            (
                _Function_3A(_u + H, _v, _w - H)
                -
                _Function_3A(_u - H, _v, _w - H)
            )
        )/HHH2
    }

#end // macro Est_DerUWW_Function_3A


#macro Est_DerVVV_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u, _v + H2, _w)
                -
                _Function_3A(_u, _v - H2, _w)
            )
            -
            (
                _Function_3A(_u, _v + H, _w)
                -
                _Function_3A(_u, _v - H, _w)
            )*2
        )/HHH2
    }

#end // macro Est_DerVVV_Function_3A


#macro Est_DerVVW_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u, _v + H, _w + H)
                -
                _Function_3A(_u, _v + H, _w - H)
            )
            -
            (
                _Function_3A(_u, _v, _w + H)
                -
                _Function_3A(_u, _v, _w - H)
            )*2
            +
            (
                _Function_3A(_u, _v - H, _w + H)
                -
                _Function_3A(_u, _v - H, _w - H)
            )
        )/HHH2
    }

#end // macro Est_DerVVW_Function_3A


#macro Est_DerVWW_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u, _v + H, _w + H)
                -
                _Function_3A(_u, _v - H, _w + H)
            )
            -
            (
                _Function_3A(_u, _v + H, _w)
                -
                _Function_3A(_u, _v - H, _w)
            )*2
            +
            (
                _Function_3A(_u, _v + H, _w - H)
                -
                _Function_3A(_u, _v - H, _w - H)
            )
        )/HHH2
    }

#end // macro Est_DerVWW_Function_3A


#macro Est_DerWWW_Function_3A(_Function_3A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u, _v, _w + H2)
                -
                _Function_3A(_u, _v, _w - H2)
            )
            -
            (
                _Function_3A(_u, _v, _w + H)
                -
                _Function_3A(_u, _v, _w - H)
            )*2
        )/HHH2
    }

#end // macro Est_DerWWW_Function_3A


#macro Est_Der3_Functions_3A(_Function_3A)

    Arr_10E(
        Est_DerUUU_Function_3A(_Function_3A),
        Est_DerUUV_Function_3A(_Function_3A),
        Est_DerUUW_Function_3A(_Function_3A),
        Est_DerUVV_Function_3A(_Function_3A),
        Est_DerUVW_Function_3A(_Function_3A),
        Est_DerUWW_Function_3A(_Function_3A),
        Est_DerVVV_Function_3A(_Function_3A),
        Est_DerVVW_Function_3A(_Function_3A),
        Est_DerVWW_Function_3A(_Function_3A),
        Est_DerWWW_Function_3A(_Function_3A)
    )

#end // macro Est_Der3_Functions_3A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_DerUUU_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H2, _v, _w, _s)
                -
                _Function_4A(_u - H2, _v, _w, _s)
            )
            -
            (
                _Function_4A(_u + H, _v, _w, _s)
                -
                _Function_4A(_u - H, _v, _w, _s)
            )*2
        )/HHH2
    }

#end // macro Est_DerUUU_Function_4A


#macro Est_DerUUV_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H, _v + H, _w, _s)
                -
                _Function_4A(_u + H, _v - H, _w, _s)
            )
            -
            (
                _Function_4A(_u, _v + H, _w, _s)
                -
                _Function_4A(_u, _v - H, _w, _s)
            )*2
            +
            (
                _Function_4A(_u - H, _v + H, _w, _s)
                -
                _Function_4A(_u - H, _v - H, _w, _s)
            )
        )/HHH2
    }

#end // macro Est_DerUUV_Function_4A


#macro Est_DerUUW_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H, _v, _w + H, _s)
                -
                _Function_4A(_u + H, _v, _w - H, _s)
            )
            -
            (
                _Function_4A(_u, _v, _w + H, _s)
                -
                _Function_4A(_u, _v, _w - H, _s)
            )*2
            +
            (
                _Function_4A(_u - H, _v, _w + H, _s)
                -
                _Function_4A(_u - H, _v, _w - H, _s)
            )
        )/HHH2
    }

#end // macro Est_DerUUW_Function_4A


#macro Est_DerUUS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H, _v, _w, _s + H)
                -
                _Function_4A(_u + H, _v, _w, _s - H)
            )
            -
            (
                _Function_4A(_u, _v, _w, _s + H)
                -
                _Function_4A(_u, _v, _w, _s - H)
            )*2
            +
            (
                _Function_4A(_u - H, _v, _w, _s + H)
                -
                _Function_4A(_u - H, _v, _w, _s - H)
            )
        )/HHH2
    }

#end // macro Est_DerUUS_Function_4A


#macro Est_DerUVV_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H, _v + H, _w, _s)
                -
                _Function_4A(_u - H, _v + H, _w, _s)
            )
            -
            (
                _Function_4A(_u + H, _v, _w, _s)
                -
                _Function_4A(_u - H, _v, _w, _s)
            )*2
            +
            (
                _Function_4A(_u + H, _v - H, _w, _s)
                -
                _Function_4A(_u - H, _v - H, _w, _s)
            )
        )/HHH2
    }

#end // macro Est_DerUVV_Function_4A


#macro Est_DerUVW_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH8 = pow(H, 3)*8;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H, _v + H, _w + H, _s)
                -
                _Function_4A(_u + H, _v + H, _w - H, _s)
                -
                _Function_4A(_u + H, _v - H, _w + H, _s)
                +
                _Function_4A(_u + H, _v - H, _w - H, _s)
            )
            -
            (
                _Function_4A(_u - H, _v + H, _w + H, _s)
                -
                _Function_4A(_u - H, _v + H, _w - H, _s)
                -
                _Function_4A(_u - H, _v - H, _w + H, _s)
                +
                _Function_4A(_u - H, _v - H, _w - H, _s)
            )
        )/HHH8
    }

#end // macro Est_DerUVW_Function_4A


#macro Est_DerUVS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH8 = pow(H, 3)*8;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H, _v + H, _w, _s + H)
                -
                _Function_4A(_u + H, _v + H, _w, _s - H)
                -
                _Function_4A(_u + H, _v - H, _w, _s + H)
                +
                _Function_4A(_u + H, _v - H, _w, _s - H)
            )
            -
            (
                _Function_4A(_u - H, _v + H, _w, _s + H)
                -
                _Function_4A(_u - H, _v + H, _w, _s - H)
                -
                _Function_4A(_u - H, _v - H, _w, _s + H)
                +
                _Function_4A(_u - H, _v - H, _w, _s - H)
            )
        )/HHH8
    }

#end // macro Est_DerUVS_Function_4A


#macro Est_DerUWW_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H, _v, _w + H, _s)
                -
                _Function_4A(_u - H, _v, _w + H, _s)
            )
            -
            (
                _Function_4A(_u + H, _v, _w, _s)
                -
                _Function_4A(_u - H, _v, _w, _s)
            )*2
            +
            (
                _Function_4A(_u + H, _v, _w - H, _s)
                -
                _Function_4A(_u - H, _v, _w - H, _s)
            )
        )/HHH2
    }

#end // macro Est_DerUWW_Function_4A


#macro Est_DerUWS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH8 = pow(H, 3)*8;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H, _v, _w + H, _s + H)
                -
                _Function_4A(_u + H, _v, _w + H, _s - H)
                -
                _Function_4A(_u + H, _v, _w - H, _s + H)
                +
                _Function_4A(_u + H, _v, _w - H, _s - H)
            )
            -
            (
                _Function_4A(_u - H, _v, _w + H, _s + H)
                -
                _Function_4A(_u - H, _v, _w + H, _s - H)
                -
                _Function_4A(_u - H, _v, _w - H, _s + H)
                +
                _Function_4A(_u - H, _v, _w - H, _s - H)
            )
        )/HHH8
    }

#end // macro Est_DerUWS_Function_4A


#macro Est_DerUSS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H, _v, _w, _s + H)
                -
                _Function_4A(_u - H, _v, _w, _s + H)
            )
            -
            (
                _Function_4A(_u + H, _v, _w, _s)
                -
                _Function_4A(_u - H, _v, _w, _s)
            )*2
            +
            (
                _Function_4A(_u + H, _v, _w, _s - H)
                -
                _Function_4A(_u - H, _v, _w, _s - H)
            )
        )/HHH2
    }

#end // macro Est_DerUSS_Function_4A


#macro Est_DerVVV_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v + H2, _w, _s)
                -
                _Function_4A(_u, _v - H2, _w, _s)
            )
            -
            (
                _Function_4A(_u, _v + H, _w, _s)
                -
                _Function_4A(_u, _v - H, _w, _s)
            )*2
        )/HHH2
    }

#end // macro Est_DerVVV_Function_4A


#macro Est_DerVVW_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v + H, _w + H, _s)
                -
                _Function_4A(_u, _v + H, _w - H, _s)
            )
            -
            (
                _Function_4A(_u, _v, _w + H, _s)
                -
                _Function_4A(_u, _v, _w - H, _s)
            )*2
            +
            (
                _Function_4A(_u, _v - H, _w + H, _s)
                -
                _Function_4A(_u, _v - H, _w - H, _s)
            )
        )/HHH2
    }

#end // macro Est_DerVVW_Function_4A


#macro Est_DerVVS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v + H, _w, _s + H)
                -
                _Function_4A(_u, _v + H, _w, _s - H)
            )
            -
            (
                _Function_4A(_u, _v, _w, _s + H)
                -
                _Function_4A(_u, _v, _w, _s - H)
            )*2
            +
            (
                _Function_4A(_u, _v - H, _w, _s + H)
                -
                _Function_4A(_u, _v - H, _w, _s - H)
            )
        )/HHH2
    }

#end // macro Est_DerVVS_Function_4A


#macro Est_DerVWW_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v + H, _w + H, _s)
                -
                _Function_4A(_u, _v - H, _w + H, _s)
            )
            -
            (
                _Function_4A(_u, _v + H, _w, _s)
                -
                _Function_4A(_u, _v - H, _w, _s)
            )*2
            +
            (
                _Function_4A(_u, _v + H, _w - H, _s)
                -
                _Function_4A(_u, _v - H, _w - H, _s)
            )
        )/HHH2
    }

#end // macro Est_DerVWW_Function_4A


#macro Est_DerVWS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH8 = pow(H, 3)*8;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v + H, _w + H, _s + H)
                -
                _Function_4A(_u, _v + H, _w + H, _s - H)
                -
                _Function_4A(_u, _v + H, _w - H, _s + H)
                +
                _Function_4A(_u, _v + H, _w - H, _s - H)
            )
            -
            (
                _Function_4A(_u, _v - H, _w + H, _s + H)
                -
                _Function_4A(_u, _v - H, _w + H, _s - H)
                -
                _Function_4A(_u, _v - H, _w - H, _s + H)
                +
                _Function_4A(_u, _v - H, _w - H, _s - H)
            )
        )/HHH8
    }

#end // macro Est_DerVWS_Function_4A


#macro Est_DerVSS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v + H, _w, _s + H)
                -
                _Function_4A(_u, _v - H, _w, _s + H)
            )
            -
            (
                _Function_4A(_u, _v + H, _w, _s)
                -
                _Function_4A(_u, _v - H, _w, _s)
            )*2
            +
            (
                _Function_4A(_u, _v + H, _w, _s - H)
                -
                _Function_4A(_u, _v - H, _w, _s - H)
            )
        )/HHH2
    }

#end // macro Est_DerVSS_Function_4A


#macro Est_DerWWW_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v, _w + H2, _s)
                -
                _Function_4A(_u, _v, _w - H2, _s)
            )
            -
            (
                _Function_4A(_u, _v, _w + H, _s)
                -
                _Function_4A(_u, _v, _w - H, _s)
            )*2
        )/HHH2
    }

#end // macro Est_DerWWW_Function_4A


#macro Est_DerWWS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v, _w + H, _s + H)
                -
                _Function_4A(_u, _v, _w + H, _s - H)
            )
            -
            (
                _Function_4A(_u, _v, _w, _s + H)
                -
                _Function_4A(_u, _v, _w, _s - H)
            )*2
            +
            (
                _Function_4A(_u, _v, _w - H, _s + H)
                -
                _Function_4A(_u, _v, _w - H, _s - H)
            )
        )/HHH2
    }

#end // macro Est_DerWWS_Function_4A


#macro Est_DerWSS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v, _w + H, _s + H)
                -
                _Function_4A(_u, _v, _w - H, _s + H)
            )
            -
            (
                _Function_4A(_u, _v, _w + H, _s)
                -
                _Function_4A(_u, _v, _w - H, _s)
            )*2
            +
            (
                _Function_4A(_u, _v, _w + H, _s - H)
                -
                _Function_4A(_u, _v, _w - H, _s - H)
            )
        )/HHH2
    }

#end // macro Est_DerWSS_Function_4A


#macro Est_DerSSS_Function_4A(_Function_4A)

    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HHH2 = pow(H, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v, _w, _s + H2)
                -
                _Function_4A(_u, _v, _w, _s - H2)
            )
            -
            (
                _Function_4A(_u, _v, _w, _s + H)
                -
                _Function_4A(_u, _v, _w, _s - H)
            )*2
        )/HHH2
    }

#end // macro Est_DerSSS_Function_4A


#macro Est_Der3_Functions_4A(_Function_4A)

    Arr_20E(
        Est_DerUUU_Function_4A(_Function_4A),
        Est_DerUUV_Function_4A(_Function_4A),
        Est_DerUUW_Function_4A(_Function_4A),
        Est_DerUUS_Function_4A(_Function_4A),
        Est_DerUVV_Function_4A(_Function_4A),
        Est_DerUVW_Function_4A(_Function_4A),
        Est_DerUVS_Function_4A(_Function_4A),
        Est_DerUWW_Function_4A(_Function_4A),
        Est_DerUWS_Function_4A(_Function_4A),
        Est_DerUSS_Function_4A(_Function_4A),
        Est_DerVVV_Function_4A(_Function_4A),
        Est_DerVVW_Function_4A(_Function_4A),
        Est_DerVVS_Function_4A(_Function_4A),
        Est_DerVWW_Function_4A(_Function_4A),
        Est_DerVWS_Function_4A(_Function_4A),
        Est_DerVSS_Function_4A(_Function_4A),
        Est_DerWWW_Function_4A(_Function_4A),
        Est_DerWWS_Function_4A(_Function_4A),
        Est_DerWSS_Function_4A(_Function_4A),
        Est_DerSSS_Function_4A(_Function_4A)
    )

#end // macro Est_Der3_Functions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro _SortDerivationString(DerivationString, Arity)

    #local BaseStr = "uvws";
    #if ((Arity < 1) | (strlen(BaseStr) < Arity))
        #error "Arity is outside valid range"
    #end // if
    #local DerStr = strlwr(DerivationString);
    #local Len = strlen(DerStr);
    #local SortedStr = "";
    #if (Len > 0)
        #local OrderStr = substr(BaseStr, 1, Arity);
        #local OrderLen = strlen(OrderStr);
        #for (TargetIdx, 1, OrderLen)
            #local TargetChar = substr(OrderStr, TargetIdx, 1);
            #for (I, 1, Len)
                #local Char = substr(DerStr, I, 1);
                #if (strcmp(Char, TargetChar) = 0)
                    #local SortedStr = concat(SortedStr, Char);
                #end // if
            #end // for I
        #end // for TargetIdx
        #if (strlen(SortedStr) != Len)
            #error "Invalid character detected for the given arity" 
        #end // if
    #end // if

    SortedStr

#end // macro _SortDerivationString


#declare _CharWeight_Fn =
    function(_c) {
        select(
            _c - 115,
            0,
            4, // s
            select(
                _c - 117,
                0,
                1, // u
                select(
                    _c - 118,
                    0,
                    2, // v
                    select(
                        _c - 119,
                        0,
                        3, // w
                        0
                    )
                )
            )
        )
    }
;

#macro _DerStrToNum(DerivationString)

    #local DerStr = strlwr(DerivationString);
    #local Len = strlen(DerStr);
    #local Sum = 0;
    #for (I, 0, Len - 1)
        #local Char = substr(DerStr, Len - I, 1);
        #local Sum = Sum + _CharWeight_Fn(asc(Char))*pow(10, I);
    #end // for

    Sum

#end // macro _DerStrToNum


#macro Est_Der_Function_1A(_Function_1A, DerivationString)

    #local DerStr = _SortDerivationString(DerivationString, 1);
    #local Order = strlen(DerStr);
    #if (Order > 3)
        #error "Derivative order higher than 3 is not supported."
    #end // if
    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HH = pow(H, 2);
    #local HHH2 = HH*H2;

    function(_u) {
        select(
            Order - 0, // Order 0
            0,
            _Function_1A(_u),
            select(
                Order - 1, // Order 1: u
                0,
                (
                    _Function_1A(_u + H)
                    -
                    _Function_1A(_u - H)
                )/H2,
                select(
                    Order - 2, // Order 2: uu
                    0,
                    (
                        (
                            _Function_1A(_u + H)
                            +
                            _Function_1A(_u - H)
                        )
                        -
                        _Function_1A(_u)*2
                    )/HH,
                    select(
                        Order - 3, // Order 3: uuu
                        0,
                        (
                            (
                                _Function_1A(_u + H2)
                                -
                                _Function_1A(_u - H2)
                            )
                            -
                            (
                                _Function_1A(_u + H)
                                -
                                _Function_1A(_u - H)
                            )*2
                        )/HHH2,
                        0
                    )
                )
            )
        )
    }

#end // macro Est_Der_Function_1A


#macro Est_Der_Function_2A(_Function_2A, DerivationString)

    #local DerStr = _SortDerivationString(DerivationString, 2);
    #local Order = strlen(DerStr);
    #if (Order > 3)
        #error "Derivative order higher than 3 is not supported."
    #end // if
    #local SelectDer = _DerStrToNum(DerStr);
    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HH = pow(H, 2);
    #local HH4 = HH*4;
    #local HHH2 = HH*H2;
    #local ID_U = _DerStrToNum("u");
    #local ID_V = _DerStrToNum("v");    
    #local ID_UU = _DerStrToNum("uu");
    #local ID_UV = _DerStrToNum("uv");
    #local ID_VV = _DerStrToNum("vv");
    #local ID_UUU = _DerStrToNum("uuu");
    #local ID_UUV = _DerStrToNum("uuv");
    #local ID_UVV = _DerStrToNum("uvv");
    #local ID_VVV = _DerStrToNum("vvv");

    function(_u, _v) {
        select(
            Order - 0, // Order 0
            0,
            _Function_2A(_u, _v),
            select(
                Order - 1, // Order 1: u, v
                0,
                select(
                    SelectDer - ID_U,
                    0,
                    (
                        _Function_2A(_u + H, _v)
                        -
                        _Function_2A(_u - H, _v)
                    )/H2,
                    select(
                        SelectDer - ID_V,
                        0,
                        (
                            _Function_2A(_u, _v + H)
                            -
                            _Function_2A(_u, _v - H)
                        )/H2,
                        0
                    )
                ),
                select(
                    Order - 2, // Order 2: uu, uv, vv
                    0,
                    select(
                        SelectDer - ID_UU,
                        0,
                        (
                            (
                                _Function_2A(_u + H, _v)
                                +
                                _Function_2A(_u - H, _v)
                            )
                            -
                            _Function_2A(_u, _v)*2
                        )/HH,
                        select(
                            SelectDer - ID_UV,
                            0,
                            (
                                (
                                    _Function_2A(_u + H, _v + H)
                                    -
                                    _Function_2A(_u + H, _v - H)
                                )
                                -
                                (
                                    _Function_2A(_u - H, _v + H)
                                    -
                                    _Function_2A(_u - H, _v - H)
                                )
                            )/HH4,
                            select(
                                SelectDer - ID_VV,
                                0,
                                (
                                    (
                                        _Function_2A(_u, _v + H)
                                        +
                                        _Function_2A(_u, _v - H)
                                    )
                                    -
                                    _Function_2A(_u, _v)*2
                                )/HH,
                                0
                            )
                        )
                    ),
                    select(
                        Order - 3, // Order 3: uuu, uuv, uvv, vvv
                        0,
                        select(
                            SelectDer - ID_UUU,
                            0,
                            (
                                (
                                    _Function_2A(_u + H2, _v)
                                    -
                                    _Function_2A(_u - H2, _v)
                                )
                                -
                                (
                                    _Function_2A(_u + H, _v)
                                    -
                                    _Function_2A(_u - H, _v)
                                )*2
                            )/HHH2,
                            select(
                                SelectDer - ID_UUV,
                                0,
                                (
                                    (
                                        _Function_2A(_u + H, _v + H)
                                        -
                                        _Function_2A(_u + H, _v - H)
                                    )
                                    +
                                    (
                                        _Function_2A(_u - H, _v + H)
                                        -
                                        _Function_2A(_u - H, _v - H)
                                    )
                                    -
                                    (
                                        _Function_2A(_u, _v + H)
                                        -
                                        _Function_2A(_u, _v - H)
                                    )*2
                                )/HHH2,
                                select(
                                    SelectDer - ID_UVV,
                                    0,
                                    (
                                        (
                                            _Function_2A(_u + H, _v + H)
                                            -
                                            _Function_2A(_u - H, _v + H)
                                        )
                                        +
                                        (
                                            _Function_2A(_u + H, _v - H)
                                            -
                                            _Function_2A(_u - H, _v - H)
                                        )
                                        -
                                        (
                                            _Function_2A(_u + H, _v)
                                            -
                                            _Function_2A(_u - H, _v)
                                        )*2
                                    )/HHH2,
                                    select(
                                        SelectDer - ID_VVV,
                                        0,
                                        (
                                            (
                                                _Function_2A(_u, _v + H2)
                                                -
                                                _Function_2A(_u, _v - H2)
                                            )
                                            -
                                            (
                                                _Function_2A(_u, _v + H)
                                                -
                                                _Function_2A(_u, _v - H)
                                            )*2
                                        )/HHH2,
                                        0
                                    )
                                )
                            )
                        ),
                        0
                    )
                )
            )
        )
    }

#end // macro Est_Der_Function_2A


#macro Est_Der_Function_3A(_Function_3A, DerivationString)

    #local DerStr = _SortDerivationString(DerivationString, 3);
    #local Order = strlen(DerStr);
    #if (Order > 3)
        #error "Derivative order higher than 3 is not supported."
    #end // if
    #local SelectDer = _DerStrToNum(DerStr);
    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HH = pow(H, 2);
    #local HH4 = HH*4;
    #local HHH2 = HH*H2;
    #local HHH8 = HHH2*4;
    #local ID_U = _DerStrToNum("u");
    #local ID_V = _DerStrToNum("v");    
    #local ID_W = _DerStrToNum("w");    
    #local ID_UU = _DerStrToNum("uu");
    #local ID_UV = _DerStrToNum("uv");
    #local ID_UW = _DerStrToNum("uw");
    #local ID_VV = _DerStrToNum("vv");
    #local ID_VW = _DerStrToNum("vw");
    #local ID_WW = _DerStrToNum("ww");
    #local ID_UUU = _DerStrToNum("uuu");
    #local ID_UUV = _DerStrToNum("uuv");
    #local ID_UUW = _DerStrToNum("uuw");
    #local ID_UVV = _DerStrToNum("uvv");
    #local ID_UVW = _DerStrToNum("uvw");
    #local ID_UWW = _DerStrToNum("uww");
    #local ID_VVV = _DerStrToNum("vvv");
    #local ID_VVW = _DerStrToNum("vvw");
    #local ID_VWW = _DerStrToNum("vww");
    #local ID_WWW = _DerStrToNum("www");

    function(_u, _v, _w) {
        select(
            Order - 0, // Order 0
            0,
            _Function_3A(_u, _v, _w),
            select(
                Order - 1, // Order 1: u, v, w
                0,
                select(
                    SelectDer - ID_U,
                    0,
                    (
                        _Function_3A(_u + H, _v, _w)
                        -
                        _Function_3A(_u - H, _v, _w)
                    )/H2,
                    select(
                        SelectDer - ID_V,
                        0,
                        (
                            _Function_3A(_u, _v + H, _w)
                            -
                            _Function_3A(_u, _v - H, _w)
                        )/H2,
                        select(
                            SelectDer - ID_W,
                            0,
                            (
                                _Function_3A(_u, _v, _w + H)
                                -
                                _Function_3A(_u, _v, _w - H)
                            )/H2,
                            0
                        )
                    )
                ),
                select(
                    Order - 2, // Order 2: uu, uv, uw, vv, vw, ww
                    0,
                    select(
                        SelectDer - ID_UU,
                        0,
                        (
                            (
                                _Function_3A(_u + H, _v, _w)
                                +
                                _Function_3A(_u - H, _v, _w)
                            )
                            -
                            _Function_3A(_u, _v, _w)*2
                        )/HH,
                        select(
                            SelectDer - ID_UV,
                            0,
                            (
                                (
                                    _Function_3A(_u + H, _v + H, _w)
                                    -
                                    _Function_3A(_u + H, _v - H, _w)
                                )
                                -
                                (
                                    _Function_3A(_u - H, _v + H, _w)
                                    -
                                    _Function_3A(_u - H, _v - H, _w)
                                )
                            )/HH4,
                            select(
                                SelectDer - ID_UW,
                                0,
                                (
                                    (
                                        _Function_3A(_u + H, _v, _w + H)
                                        -
                                        _Function_3A(_u + H, _v, _w - H)
                                    )
                                    -
                                    (
                                        _Function_3A(_u - H, _v, _w + H)
                                        -
                                        _Function_3A(_u - H, _v, _w - H)
                                    )
                                )/HH4,
                                select(
                                    SelectDer - ID_VV,
                                    0,
                                    (
                                        (
                                            _Function_3A(_u, _v + H, _w)
                                            +
                                            _Function_3A(_u, _v - H, _w)
                                        )
                                        -
                                        _Function_3A(_u, _v, _w)*2
                                    )/HH,
                                    select(
                                        SelectDer - ID_VW,
                                        0,
                                        (
                                            (
                                                _Function_3A(_u, _v + H, _w + H)
                                                -
                                                _Function_3A(_u, _v + H, _w - H)
                                            )
                                            -
                                            (
                                                _Function_3A(_u, _v - H, _w + H)
                                                -
                                                _Function_3A(_u, _v - H, _w - H)
                                            )
                                        )/HH4,
                                        select(
                                            SelectDer - ID_WW,
                                            0,
                                            (
                                                (
                                                    _Function_3A(_u, _v, _w + H)
                                                    +
                                                    _Function_3A(_u, _v, _w - H)
                                                )
                                                -
                                                _Function_3A(_u, _v, _w)*2
                                            )/HH,
                                            0
                                        )
                                    )
                                )
                            )
                        )
                    ),
                    select(
                        Order - 3, // Order 3: uuu, uuv, uuw, uvv, uvw, uww, vvv, vvw, vww, www
                        0,
                        select(
                            SelectDer - ID_UUU,
                            0,
                            (
                                (
                                    _Function_3A(_u + H2, _v, _w)
                                    -
                                    _Function_3A(_u - H2, _v, _w)
                                )
                                -
                                (
                                    _Function_3A(_u + H, _v, _w)
                                    -
                                    _Function_3A(_u - H, _v, _w)
                                )*2
                            )/HHH2,
                            select(
                                SelectDer - ID_UUV,
                                0,
                                (
                                    (
                                        _Function_3A(_u + H, _v + H, _w)
                                        -
                                        _Function_3A(_u + H, _v - H, _w)
                                    )
                                    -
                                    (
                                        _Function_3A(_u, _v + H, _w)
                                        -
                                        _Function_3A(_u, _v - H, _w)
                                    )*2
                                    +
                                    (
                                        _Function_3A(_u - H, _v + H, _w)
                                        -
                                        _Function_3A(_u - H, _v - H, _w)
                                    )
                                )/HHH2,
                                select(
                                    SelectDer - ID_UUW,
                                    0,
                                    (
                                        (
                                            _Function_3A(_u + H, _v, _w + H)
                                            -
                                            _Function_3A(_u + H, _v, _w - H)
                                        )
                                        -
                                        (
                                            _Function_3A(_u, _v, _w + H)
                                            -
                                            _Function_3A(_u, _v, _w - H)
                                        )*2
                                        +
                                        (
                                            _Function_3A(_u - H, _v, _w + H)
                                            -
                                            _Function_3A(_u - H, _v, _w - H)
                                        )
                                    )/HHH2,
                                    select(
                                        SelectDer - ID_UVV,
                                        0,
                                        (
                                            (
                                                _Function_3A(_u + H, _v + H, _w)
                                                -
                                                _Function_3A(_u - H, _v + H, _w)
                                            )
                                            -
                                            (
                                                _Function_3A(_u + H, _v, _w)
                                                -
                                                _Function_3A(_u - H, _v, _w)
                                            )*2
                                            +
                                            (
                                                _Function_3A(_u + H, _v - H, _w)
                                                -
                                                _Function_3A(_u - H, _v - H, _w)
                                            )
                                        )/HHH2,
                                        select(
                                            SelectDer - ID_UVW,
                                            0,
                                            (
                                                (
                                                    _Function_3A(_u + H, _v + H, _w + H)
                                                    -
                                                    _Function_3A(_u + H, _v + H, _w - H)
                                                    -
                                                    _Function_3A(_u + H, _v - H, _w + H)
                                                    +
                                                    _Function_3A(_u + H, _v - H, _w - H)
                                                )
                                                -
                                                (
                                                    _Function_3A(_u - H, _v + H, _w + H)
                                                    -
                                                    _Function_3A(_u - H, _v + H, _w - H)
                                                    -
                                                    _Function_3A(_u - H, _v - H, _w + H)
                                                    +
                                                    _Function_3A(_u - H, _v - H, _w - H)
                                                )
                                            )/HHH8,
                                            select(
                                                SelectDer - ID_UWW,
                                                0,
                                                (
                                                    (
                                                        _Function_3A(_u + H, _v, _w + H)
                                                        -
                                                        _Function_3A(_u - H, _v, _w + H)
                                                    )
                                                    -
                                                    (
                                                        _Function_3A(_u + H, _v, _w)
                                                        -
                                                        _Function_3A(_u - H, _v, _w)
                                                    )*2
                                                    +
                                                    (
                                                        _Function_3A(_u + H, _v, _w - H)
                                                        -
                                                        _Function_3A(_u - H, _v, _w - H)
                                                    )
                                                )/HHH2,
                                                select(
                                                    SelectDer - ID_VVV,
                                                    0,
                                                    (
                                                        (
                                                            _Function_3A(_u, _v + H2, _w)
                                                            -
                                                            _Function_3A(_u, _v - H2, _w)
                                                        )
                                                        -
                                                        (
                                                            _Function_3A(_u, _v + H, _w)
                                                            -
                                                            _Function_3A(_u, _v - H, _w)
                                                        )*2
                                                    )/HHH2,
                                                    select(
                                                        SelectDer - ID_VVW,
                                                        0,
                                                        (
                                                            (
                                                                _Function_3A(_u, _v + H, _w + H)
                                                                -
                                                                _Function_3A(_u, _v + H, _w - H)
                                                            )
                                                            -
                                                            (
                                                                _Function_3A(_u, _v, _w + H)
                                                                -
                                                                _Function_3A(_u, _v, _w - H)
                                                            )*2
                                                            +
                                                            (
                                                                _Function_3A(_u, _v - H, _w + H)
                                                                -
                                                                _Function_3A(_u, _v - H, _w - H)
                                                            )
                                                        )/HHH2,
                                                        select(
                                                            SelectDer - ID_VWW,
                                                            0,
                                                            (
                                                                (
                                                                    _Function_3A(_u, _v + H, _w + H)
                                                                    -
                                                                    _Function_3A(_u, _v - H, _w + H)
                                                                )
                                                                -
                                                                (
                                                                    _Function_3A(_u, _v + H, _w)
                                                                    -
                                                                    _Function_3A(_u, _v - H, _w)
                                                                )*2
                                                                +
                                                                (
                                                                    _Function_3A(_u, _v + H, _w - H)
                                                                    -
                                                                    _Function_3A(_u, _v - H, _w - H)
                                                                )
                                                            )/HHH2,
                                                            select(
                                                                SelectDer - ID_WWW,
                                                                0,
                                                                (
                                                                    (
                                                                        _Function_3A(_u, _v, _w + H2)
                                                                        -
                                                                        _Function_3A(_u, _v, _w - H2)
                                                                    )
                                                                    -
                                                                    (
                                                                        _Function_3A(_u, _v, _w + H)
                                                                        -
                                                                        _Function_3A(_u, _v, _w - H)
                                                                    )*2
                                                                )/HHH2,
                                                                0
                                                            )
                                                        )
                                                    )
                                                )
                                            )
                                        )
                                    )
                                )
                            )
                        ),
                        0
                    )
                )
            )
        )
    }

#end // macro Est_Der_Function_3A


#macro Est_Der_Function_4A(_Function_4A, DerivationString)

    #local DerStr = _SortDerivationString(DerivationString, 4);
    #local Order = strlen(DerStr);
    #if (Order > 3)
        #error "Derivative order higher than 3 is not supported."
    #end // if
    #local SelectDer = _DerStrToNum(DerStr);
    #local H = NUM_DIFF_STEP_SIZE;
    #local H2 = H*2;
    #local HH = pow(H, 2);
    #local HH4 = HH*4;
    #local HHH2 = HH*H2;
    #local HHH8 = HHH2*4;
    #local ID_U = _DerStrToNum("u");
    #local ID_V = _DerStrToNum("v");    
    #local ID_W = _DerStrToNum("w");    
    #local ID_S = _DerStrToNum("s");    
    #local ID_UU = _DerStrToNum("uu");
    #local ID_UV = _DerStrToNum("uv");
    #local ID_UW = _DerStrToNum("uw");
    #local ID_US = _DerStrToNum("us");
    #local ID_VV = _DerStrToNum("vv");
    #local ID_VW = _DerStrToNum("vw");
    #local ID_VS = _DerStrToNum("vs");
    #local ID_WW = _DerStrToNum("ww");
    #local ID_WS = _DerStrToNum("ws");
    #local ID_SS = _DerStrToNum("ss");
    #local ID_UUU = _DerStrToNum("uuu");
    #local ID_UUV = _DerStrToNum("uuv");
    #local ID_UUW = _DerStrToNum("uuw");
    #local ID_UUS = _DerStrToNum("uus");
    #local ID_UVV = _DerStrToNum("uvv");
    #local ID_UVW = _DerStrToNum("uvw");
    #local ID_UVS = _DerStrToNum("uvs");
    #local ID_UWW = _DerStrToNum("uww");
    #local ID_UWS = _DerStrToNum("uws");
    #local ID_USS = _DerStrToNum("uss");
    #local ID_VVV = _DerStrToNum("vvv");
    #local ID_VVW = _DerStrToNum("vvw");
    #local ID_VVS = _DerStrToNum("vvs");
    #local ID_VWW = _DerStrToNum("vww");
    #local ID_VWS = _DerStrToNum("vws");
    #local ID_VSS = _DerStrToNum("vss");
    #local ID_WWW = _DerStrToNum("www");
    #local ID_WWS = _DerStrToNum("wws");
    #local ID_WSS = _DerStrToNum("wss");
    #local ID_SSS = _DerStrToNum("sss");

    function(_u, _v, _w, _s) {
        select(
            Order - 0, // Order 0
            0,
            _Function_4A(_u, _v, _w, _s),
            select(
                Order - 1, // Order 1: u, v, w, s
                0,
                select(
                    SelectDer - ID_U,
                    0,
                    (
                        _Function_4A(_u + H, _v, _w, _s)
                        -
                        _Function_4A(_u - H, _v, _w, _s)
                    )/H2,
                    select(
                        SelectDer - ID_V,
                        0,
                        (
                            _Function_4A(_u, _v + H, _w, _s)
                            -
                            _Function_4A(_u, _v - H, _w, _s)
                        )/H2,
                        select(
                            SelectDer - ID_W,
                            0,
                            (
                                _Function_4A(_u, _v, _w + H, _s)
                                -
                                _Function_4A(_u, _v, _w - H, _s)
                            )/H2,
                            select(
                                SelectDer - ID_S,
                                0,
                                (
                                    _Function_4A(_u, _v, _w, _s + H)
                                    -
                                    _Function_4A(_u, _v, _w, _s - H)
                                )/H2,
                                0
                            )
                        )
                    )
                ),
                select(
                    Order - 2, // Order 2: uu, uv, uw, us, vv, vw, vs, ww, ws, ss
                    0,
                    select(
                        SelectDer - ID_UU,
                        0,
                        (
                            (
                                _Function_4A(_u + H, _v, _w, _s)
                                +
                                _Function_4A(_u - H, _v, _w, _s)
                            )
                            -
                            _Function_4A(_u, _v, _w, _s)*2
                        )/HH,
                        select(
                            SelectDer - ID_UV,
                            0,
                            (
                                (
                                    _Function_4A(_u + H, _v + H, _w, _s)
                                    -
                                    _Function_4A(_u + H, _v - H, _w, _s)
                                )
                                -
                                (
                                    _Function_4A(_u - H, _v + H, _w, _s)
                                    -
                                    _Function_4A(_u - H, _v - H, _w, _s)
                                )
                            )/HH4,
                            select(
                                SelectDer - ID_UW,
                                0,
                                (
                                    (
                                        _Function_4A(_u + H, _v, _w + H, _s)
                                        -
                                        _Function_4A(_u + H, _v, _w - H, _s)
                                    )
                                    -
                                    (
                                        _Function_4A(_u - H, _v, _w + H, _s)
                                        -
                                        _Function_4A(_u - H, _v, _w - H, _s)
                                    )
                                )/HH4,
                                select(
                                    SelectDer - ID_US,
                                    0,
                                    (
                                        (
                                            _Function_4A(_u + H, _v, _w, _s + H)
                                            -
                                            _Function_4A(_u + H, _v, _w, _s - H)
                                        )
                                        -
                                        (
                                            _Function_4A(_u - H, _v, _w, _s + H)
                                            -
                                            _Function_4A(_u - H, _v, _w, _s - H)
                                        )
                                    )/HH4,
                                    select(
                                        SelectDer - ID_VV,
                                        0,
                                        (
                                            (
                                                _Function_4A(_u, _v + H, _w, _s)
                                                +
                                                _Function_4A(_u, _v - H, _w, _s)
                                            )
                                            -
                                            _Function_4A(_u, _v, _w, _s)*2
                                        )/HH,
                                        select(
                                            SelectDer - ID_VW,
                                            0,
                                            (
                                                (
                                                    _Function_4A(_u, _v + H, _w + H, _s)
                                                    -
                                                    _Function_4A(_u, _v + H, _w - H, _s)
                                                )
                                                -
                                                (
                                                    _Function_4A(_u, _v - H, _w + H, _s)
                                                    -
                                                    _Function_4A(_u, _v - H, _w - H, _s)
                                                )
                                            )/HH4,
                                            select(
                                                SelectDer - ID_VS,
                                                0,
                                                (
                                                    (
                                                        _Function_4A(_u, _v + H, _w, _s + H)
                                                        -
                                                        _Function_4A(_u, _v + H, _w, _s - H)
                                                    )
                                                    -
                                                    (
                                                        _Function_4A(_u, _v - H, _w, _s + H)
                                                        -
                                                        _Function_4A(_u, _v - H, _w, _s - H)
                                                    )
                                                )/HH4,
                                                select(
                                                    SelectDer - ID_WW,
                                                    0,
                                                    (
                                                        (
                                                            _Function_4A(_u, _v, _w + H, _s)
                                                            +
                                                            _Function_4A(_u, _v, _w - H, _s)
                                                        )
                                                        -
                                                        _Function_4A(_u, _v, _w, _s)*2
                                                    )/HH,
                                                    select(
                                                        SelectDer - ID_WS,
                                                        0,
                                                        (
                                                            (
                                                                _Function_4A(_u, _v, _w + H, _s + H)
                                                                -
                                                                _Function_4A(_u, _v, _w + H, _s - H)
                                                            )
                                                            -
                                                            (
                                                                _Function_4A(_u, _v, _w - H, _s + H)
                                                                -
                                                                _Function_4A(_u, _v, _w - H, _s - H)
                                                            )
                                                        )/HH4,
                                                        select(
                                                            SelectDer - ID_SS,
                                                            0,
                                                            (
                                                                (
                                                                    _Function_4A(_u, _v, _w, _s + H)
                                                                    +
                                                                    _Function_4A(_u, _v, _w, _s - H)
                                                                )
                                                                -
                                                                _Function_4A(_u, _v, _w, _s)*2
                                                            )/HH,
                                                            0
                                                        )
                                                    )
                                                )
                                            )
                                        )
                                    )
                                )
                            )
                        )
                    ),
                    select(
                        Order - 3, // Order 3: uuu, uuv, uuw, uus, uvv, uvw, uvs, uww, uws, uss, vvv, vvw, vvs, vww, vws, vss, www, wws, wss, sss
                        0,
                        select(
                            SelectDer - ID_UUU,
                            0,
                            (
                                (
                                    _Function_4A(_u + H2, _v, _w, _s)
                                    -
                                    _Function_4A(_u - H2, _v, _w, _s)
                                )
                                -
                                (
                                    _Function_4A(_u + H, _v, _w, _s)
                                    -
                                    _Function_4A(_u - H, _v, _w, _s)
                                )*2
                            )/HHH2,
                            select(
                                SelectDer - ID_UUV,
                                0,
                                (
                                    (
                                        _Function_4A(_u + H, _v + H, _w, _s)
                                        -
                                        _Function_4A(_u + H, _v - H, _w, _s)
                                    )
                                    -
                                    (
                                        _Function_4A(_u, _v + H, _w, _s)
                                        -
                                        _Function_4A(_u, _v - H, _w, _s)
                                    )*2
                                    +
                                    (
                                        _Function_4A(_u - H, _v + H, _w, _s)
                                        -
                                        _Function_4A(_u - H, _v - H, _w, _s)
                                    )
                                )/HHH2,
                                select(
                                    SelectDer - ID_UUW,
                                    0,
                                    (
                                        (
                                            _Function_4A(_u + H, _v, _w + H, _s)
                                            -
                                            _Function_4A(_u + H, _v, _w - H, _s)
                                        )
                                        -
                                        (
                                            _Function_4A(_u, _v, _w + H, _s)
                                            -
                                            _Function_4A(_u, _v, _w - H, _s)
                                        )*2
                                        +
                                        (
                                            _Function_4A(_u - H, _v, _w + H, _s)
                                            -
                                            _Function_4A(_u - H, _v, _w - H, _s)
                                        )
                                    )/HHH2,
                                    select(
                                        SelectDer - ID_UUS,
                                        0,
                                        (
                                            (
                                                _Function_4A(_u + H, _v, _w, _s + H)
                                                -
                                                _Function_4A(_u + H, _v, _w, _s - H)
                                            )
                                            -
                                            (
                                                _Function_4A(_u, _v, _w, _s + H)
                                                -
                                                _Function_4A(_u, _v, _w, _s - H)
                                            )*2
                                            +
                                            (
                                                _Function_4A(_u - H, _v, _w, _s + H)
                                                -
                                                _Function_4A(_u - H, _v, _w, _s - H)
                                            )
                                        )/HHH2,
                                        select(
                                            SelectDer - ID_UVV,
                                            0,
                                            (
                                                (
                                                    _Function_4A(_u + H, _v + H, _w, _s)
                                                    -
                                                    _Function_4A(_u - H, _v + H, _w, _s)
                                                )
                                                -
                                                (
                                                    _Function_4A(_u + H, _v, _w, _s)
                                                    -
                                                    _Function_4A(_u - H, _v, _w, _s)
                                                )*2
                                                +
                                                (
                                                    _Function_4A(_u + H, _v - H, _w, _s)
                                                    -
                                                    _Function_4A(_u - H, _v - H, _w, _s)
                                                )
                                            )/HHH2,
                                            select(
                                                SelectDer - ID_UVW,
                                                0,
                                                (
                                                    (
                                                        _Function_4A(_u + H, _v + H, _w + H, _s)
                                                        -
                                                        _Function_4A(_u + H, _v + H, _w - H, _s)
                                                        -
                                                        _Function_4A(_u + H, _v - H, _w + H, _s)
                                                        +
                                                        _Function_4A(_u + H, _v - H, _w - H, _s)
                                                    )
                                                    -
                                                    (
                                                        _Function_4A(_u - H, _v + H, _w + H, _s)
                                                        -
                                                        _Function_4A(_u - H, _v + H, _w - H, _s)
                                                        -
                                                        _Function_4A(_u - H, _v - H, _w + H, _s)
                                                        +
                                                        _Function_4A(_u - H, _v - H, _w - H, _s)
                                                    )
                                                )/HHH8,
                                                select(
                                                    SelectDer - ID_UVS,
                                                    0,
                                                    (
                                                        (
                                                            _Function_4A(_u + H, _v + H, _w, _s + H)
                                                            -
                                                            _Function_4A(_u + H, _v + H, _w, _s - H)
                                                            -
                                                            _Function_4A(_u + H, _v - H, _w, _s + H)
                                                            +
                                                            _Function_4A(_u + H, _v - H, _w, _s - H)
                                                        )
                                                        -
                                                        (
                                                            _Function_4A(_u - H, _v + H, _w, _s + H)
                                                            -
                                                            _Function_4A(_u - H, _v + H, _w, _s - H)
                                                            -
                                                            _Function_4A(_u - H, _v - H, _w, _s + H)
                                                            +
                                                            _Function_4A(_u - H, _v - H, _w, _s - H)
                                                        )
                                                    )/HHH8,
                                                    select(
                                                        SelectDer - ID_UWW,
                                                        0,
                                                        (
                                                            (
                                                                _Function_4A(_u + H, _v, _w + H, _s)
                                                                -
                                                                _Function_4A(_u - H, _v, _w + H, _s)
                                                            )
                                                            -
                                                            (
                                                                _Function_4A(_u + H, _v, _w, _s)
                                                                -
                                                                _Function_4A(_u - H, _v, _w, _s)
                                                            )*2
                                                            +
                                                            (
                                                                _Function_4A(_u + H, _v, _w - H, _s)
                                                                -
                                                                _Function_4A(_u - H, _v, _w - H, _s)
                                                            )
                                                        )/HHH2,
                                                        select(
                                                            SelectDer - ID_UWS,
                                                            0,
                                                            (
                                                                (
                                                                    _Function_4A(_u + H, _v, _w + H, _s + H)
                                                                    -
                                                                    _Function_4A(_u + H, _v, _w + H, _s - H)
                                                                    -
                                                                    _Function_4A(_u + H, _v, _w - H, _s + H)
                                                                    +
                                                                    _Function_4A(_u + H, _v, _w - H, _s - H)
                                                                )
                                                                -
                                                                (
                                                                    _Function_4A(_u - H, _v, _w + H, _s + H)
                                                                    -
                                                                    _Function_4A(_u - H, _v, _w + H, _s - H)
                                                                    -
                                                                    _Function_4A(_u - H, _v, _w - H, _s + H)
                                                                    +
                                                                    _Function_4A(_u - H, _v, _w - H, _s - H)
                                                                )
                                                            )/HHH8,
                                                            select(
                                                                SelectDer - ID_USS,
                                                                0,
                                                                (
                                                                    (
                                                                        _Function_4A(_u + H, _v, _w, _s + H)
                                                                        -
                                                                        _Function_4A(_u - H, _v, _w, _s + H)
                                                                    )
                                                                    -
                                                                    (
                                                                        _Function_4A(_u + H, _v, _w, _s)
                                                                        -
                                                                        _Function_4A(_u - H, _v, _w, _s)
                                                                    )*2
                                                                    +
                                                                    (
                                                                        _Function_4A(_u + H, _v, _w, _s - H)
                                                                        -
                                                                        _Function_4A(_u - H, _v, _w, _s - H)
                                                                    )
                                                                )/HHH2,
                                                                select(
                                                                    SelectDer - ID_VVV,
                                                                    0,
                                                                    (
                                                                        (
                                                                            _Function_4A(_u, _v + H2, _w, _s)
                                                                            -
                                                                            _Function_4A(_u, _v - H2, _w, _s)
                                                                        )
                                                                        -
                                                                        (
                                                                            _Function_4A(_u, _v + H, _w, _s)
                                                                            -
                                                                            _Function_4A(_u, _v - H, _w, _s)
                                                                        )*2
                                                                    )/HHH2,
                                                                    select(
                                                                        SelectDer - ID_VVW,
                                                                        0,
                                                                        (
                                                                            (
                                                                                _Function_4A(_u, _v + H, _w + H, _s)
                                                                                -
                                                                                _Function_4A(_u, _v + H, _w - H, _s)
                                                                            )
                                                                            -
                                                                            (
                                                                                _Function_4A(_u, _v, _w + H, _s)
                                                                                -
                                                                                _Function_4A(_u, _v, _w - H, _s)
                                                                            )*2
                                                                            +
                                                                            (
                                                                                _Function_4A(_u, _v - H, _w + H, _s)
                                                                                -
                                                                                _Function_4A(_u, _v - H, _w - H, _s)
                                                                            )
                                                                        )/HHH2,
                                                                        select(
                                                                            SelectDer - ID_VVS,
                                                                            0,
                                                                            (
                                                                                (
                                                                                    _Function_4A(_u, _v + H, _w, _s + H)
                                                                                    -
                                                                                    _Function_4A(_u, _v + H, _w, _s - H)
                                                                                )
                                                                                -
                                                                                (
                                                                                    _Function_4A(_u, _v, _w, _s + H)
                                                                                    -
                                                                                    _Function_4A(_u, _v, _w, _s - H)
                                                                                )*2
                                                                                +
                                                                                (
                                                                                    _Function_4A(_u, _v - H, _w, _s + H)
                                                                                    -
                                                                                    _Function_4A(_u, _v - H, _w, _s - H)
                                                                                )
                                                                            )/HHH2,
                                                                            select(
                                                                                SelectDer - ID_VWW,
                                                                                0,
                                                                                (
                                                                                    (
                                                                                        _Function_4A(_u, _v + H, _w + H, _s)
                                                                                        -
                                                                                        _Function_4A(_u, _v - H, _w + H, _s)
                                                                                    )
                                                                                    -
                                                                                    (
                                                                                        _Function_4A(_u, _v + H, _w, _s)
                                                                                        -
                                                                                        _Function_4A(_u, _v - H, _w, _s)
                                                                                    )*2
                                                                                    +
                                                                                    (
                                                                                        _Function_4A(_u, _v + H, _w - H, _s)
                                                                                        -
                                                                                        _Function_4A(_u, _v - H, _w - H, _s)
                                                                                    )
                                                                                )/HHH2,
                                                                                select(
                                                                                    SelectDer - ID_VWS,
                                                                                    0,
                                                                                    (
                                                                                        (
                                                                                            _Function_4A(_u, _v + H, _w + H, _s + H)
                                                                                            -
                                                                                            _Function_4A(_u, _v + H, _w + H, _s - H)
                                                                                            -
                                                                                            _Function_4A(_u, _v + H, _w - H, _s + H)
                                                                                            +
                                                                                            _Function_4A(_u, _v + H, _w - H, _s - H)
                                                                                        )
                                                                                        -
                                                                                        (
                                                                                            _Function_4A(_u, _v - H, _w + H, _s + H)
                                                                                            -
                                                                                            _Function_4A(_u, _v - H, _w + H, _s - H)
                                                                                            -
                                                                                            _Function_4A(_u, _v - H, _w - H, _s + H)
                                                                                            +
                                                                                            _Function_4A(_u, _v - H, _w - H, _s - H)
                                                                                        )
                                                                                    )/HHH8,
                                                                                    select(
                                                                                        SelectDer - ID_VSS,
                                                                                        0,
                                                                                        (
                                                                                            (
                                                                                                _Function_4A(_u, _v + H, _w, _s + H)
                                                                                                -
                                                                                                _Function_4A(_u, _v - H, _w, _s + H)
                                                                                            )
                                                                                            -
                                                                                            (
                                                                                                _Function_4A(_u, _v + H, _w, _s)
                                                                                                -
                                                                                                _Function_4A(_u, _v - H, _w, _s)
                                                                                            )*2
                                                                                            +
                                                                                            (
                                                                                                _Function_4A(_u, _v + H, _w, _s - H)
                                                                                                -
                                                                                                _Function_4A(_u, _v - H, _w, _s - H)
                                                                                            )
                                                                                        )/HHH2,
                                                                                        select(
                                                                                            SelectDer - ID_WWW,
                                                                                            0,
                                                                                            (
                                                                                                (
                                                                                                    _Function_4A(_u, _v, _w + H2, _s)
                                                                                                    -
                                                                                                    _Function_4A(_u, _v, _w - H2, _s)
                                                                                                )
                                                                                                -
                                                                                                (
                                                                                                    _Function_4A(_u, _v, _w + H, _s)
                                                                                                    -
                                                                                                    _Function_4A(_u, _v, _w - H, _s)
                                                                                                )*2
                                                                                            )/HHH2,
                                                                                            select(
                                                                                                SelectDer - ID_WWS,
                                                                                                0,
                                                                                                (
                                                                                                    (
                                                                                                        _Function_4A(_u, _v, _w + H, _s + H)
                                                                                                        -
                                                                                                        _Function_4A(_u, _v, _w + H, _s - H)
                                                                                                    )
                                                                                                    -
                                                                                                    (
                                                                                                        _Function_4A(_u, _v, _w, _s + H)
                                                                                                        -
                                                                                                        _Function_4A(_u, _v, _w, _s - H)
                                                                                                    )*2
                                                                                                    +
                                                                                                    (
                                                                                                        _Function_4A(_u, _v, _w - H, _s + H)
                                                                                                        -
                                                                                                        _Function_4A(_u, _v, _w - H, _s - H)
                                                                                                    )
                                                                                                )/HHH2,
                                                                                                select(
                                                                                                    SelectDer - ID_WSS,
                                                                                                    0,
                                                                                                    (
                                                                                                        (
                                                                                                            _Function_4A(_u, _v, _w + H, _s + H)
                                                                                                            -
                                                                                                            _Function_4A(_u, _v, _w - H, _s + H)
                                                                                                        )
                                                                                                        -
                                                                                                        (
                                                                                                            _Function_4A(_u, _v, _w + H, _s)
                                                                                                            -
                                                                                                            _Function_4A(_u, _v, _w - H, _s)
                                                                                                        )*2
                                                                                                        +
                                                                                                        (
                                                                                                            _Function_4A(_u, _v, _w + H, _s - H)
                                                                                                            -
                                                                                                            _Function_4A(_u, _v, _w - H, _s - H)
                                                                                                        )
                                                                                                    )/HHH2,
                                                                                                    select(
                                                                                                        SelectDer - ID_SSS,
                                                                                                        0,
                                                                                                        (
                                                                                                            (
                                                                                                                _Function_4A(_u, _v, _w, _s + H2)
                                                                                                                -
                                                                                                                _Function_4A(_u, _v, _w, _s - H2)
                                                                                                            )
                                                                                                            -
                                                                                                            (
                                                                                                                _Function_4A(_u, _v, _w, _s + H)
                                                                                                                -
                                                                                                                _Function_4A(_u, _v, _w, _s - H)
                                                                                                            )*2
                                                                                                        )/HHH2,
                                                                                                        0
                                                                                                    )
                                                                                                )
                                                                                            )
                                                                                        )
                                                                                    )
                                                                                )
                                                                            )
                                                                        )
                                                                    )
                                                                )
                                                            )
                                                        )
                                                    )
                                                )
                                            )
                                        )
                                    )
                                )
                            )
                        ),
                        0
                    )
                )
            )
        )
    }

#end // macro Est_Der_Function_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A
