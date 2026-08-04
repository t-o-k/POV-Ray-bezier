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
