// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= 10
/*

https://github.com/t-o-k/POV-Ray-bezier

Copyright (c) 2025-2026 Tor Olav Kristensen, http://subcube.com

Use of this source code is governed by the GNU Lesser General Public License version 3,
which can be found in the LICENSE file.

*/
// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= 10

#version 3.7;

#declare NUM_DIFF_STEP_SIZE = 1e-4;

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

#macro Est_Der1U_Function_1A(_Function_1A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;

    function(_u) {
        (
            _Function_1A(_u + H1)
            -
            _Function_1A(_u - H1)
        )/H2
    }

#end // macro Est_Der1U_Function_1A


#macro Est_Der1_Functions_1A(_Function_1A)

    Arr_1E(
        Est_Der1U_Function_1A(_Function_1A)
    )

#end // macro Est_Der1_Functions_1A


#macro Est_GradientMagnitude_Function_1A(_Function_1A)

    _LengthFunction_1A_1D(
        Est_Der1_Functions_1A(_Function_1A)
    )

#end // Est_GradientMagnitude_Function_1A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_Der1U_Function_2A(_Function_2A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;

    function(_u, _v) {
        (
            _Function_2A(_u + H1, _v)
            -
            _Function_2A(_u - H1, _v)
        )/H2
    }

#end // macro Est_Der1U_Function_2A


#macro Est_Der1V_Function_2A(_Function_2A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;

    function(_u, _v) {
        (
            _Function_2A(_u, _v + H1)
            -
            _Function_2A(_u, _v - H1)
        )/H2
    }

#end // macro Est_Der1V_Function_2A


#macro Est_Der1_Functions_2A(_Function_2A)

    Arr_2E(
        Est_Der1U_Function_2A(_Function_2A),
        Est_Der1V_Function_2A(_Function_2A)
    )

#end // macro Est_Der1_Functions_2A


#macro Est_GradientMagnitude_Function_2A(_Function_2A)

    _LengthFunction_2A_2D(
        Est_Der1_Functions_2A(_Function_2A)
    )

#end // Est_GradientMagnitude_Function_2A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_Der1U_Function_3A(_Function_3A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;

    function(_u, _v, _w) {
        (
            _Function_3A(_u + H1, _v, _w)
            -
            _Function_3A(_u - H1, _v, _w)
        )/H2
    }

#end // macro Est_Der1U_Function_3A


#macro Est_Der1V_Function_3A(_Function_3A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;

    function(_u, _v, _w) {
        (
            _Function_3A(_u, _v + H1, _w)
            -
            _Function_3A(_u, _v - H1, _w)
        )/H2
    }

#end // macro Est_Der1V_Function_3A


#macro Est_Der1W_Function_3A(_Function_3A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;

    function(_u, _v, _w) {
        (
            _Function_3A(_u, _v, _w + H1)
            -
            _Function_3A(_u, _v, _w - H1)
        )/H2
    }

#end // macro Est_Der1W_Function_3A


#macro Est_Der1_Functions_3A(_Function_3A)

    Arr_3E(
        Est_Der1U_Function_3A(_Function_3A),
        Est_Der1V_Function_3A(_Function_3A),
        Est_Der1W_Function_3A(_Function_3A)
    )

#end // macro Est_Der1_Functions_3A


#macro Est_GradientMagnitude_Function_3A(_Function_3A)

    _LengthFunction_3A_3D(
        Est_Der1_Functions_3A(_Function_3A)
    )

#end // Est_GradientMagnitude_Function_3A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_Der1U_Function_4A(_Function_4A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;

    function(_u, _v, _w, _s) {
        (
            _Function_4A(_u + H1, _v, _w, _s)
            -
            _Function_4A(_u - H1, _v, _w, _s)
        )/H2
    }

#end // macro Est_Der1U_Function_4A


#macro Est_Der1V_Function_4A(_Function_4A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;

    function(_u, _v, _w, _s) {
        (
            _Function_4A(_u, _v + H1, _w, _s)
            -
            _Function_4A(_u, _v - H1, _w, _s)
        )/H2
    }

#end // macro Est_Der1V_Function_4A


#macro Est_Der1W_Function_4A(_Function_4A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;

    function(_u, _v, _w, _s) {
        (
            _Function_4A(_u, _v, _w + H1, _s)
            -
            _Function_4A(_u, _v, _w - H1, _s)
        )/H2
    }

#end // macro Est_Der1W_Function_4A


#macro Est_Der1S_Function_4A(_Function_4A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;

    function(_u, _v, _w, _s) {
        (
            _Function_4A(_u, _v, _w, _s + H1)
            -
            _Function_4A(_u, _v, _w, _s - H1)
        )/H2
    }

#end // macro Est_Der1S_Function_4A


#macro Est_Der1_Functions_4A(_Function_4A)

    Arr_4E(
        Est_Der1U_Function_4A(_Function_4A),
        Est_Der1V_Function_4A(_Function_4A),
        Est_Der1W_Function_4A(_Function_4A),
        Est_Der1S_Function_4A(_Function_4A)
    )

#end // macro Est_Der1_Functions_4A


#macro Est_GradientMagnitude_Function_4A(_Function_4A)

    _LengthFunction_4A_4D(
        Est_Der1_Functions_4A(_Function_4A)
    )

#end // Est_GradientMagnitude_Function_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_Der2U_Function_1A(_Function_1A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H1, 2);

    function(_u) {
        (
            (
                _Function_1A(_u + H1)
                +
                _Function_1A(_u - H1)
            )
            -
            _Function_1A(_u)*2
        )/HH
    }

#end // macro Est_Der2U_Function_1A


#macro Est_Der2_Functions_1A(_Function_1A)

    Arr_1E(
        Est_Der2U_Function_1A(_Function_1A)
    )

#end // macro Est_Der2_Functions_1A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_Der2U_Function_2A(_Function_2A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H1, 2);

    function(_u, _v) {
        (
            (
                _Function_2A(_u + H1, _v)
                +
                _Function_2A(_u - H1, _v)
            )
            -
            _Function_2A(_u, _v)*2
        )/HH
    }

#end // macro Est_Der2U_Function_2A


#macro Est_Der2V_Function_2A(_Function_2A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H1, 2);

    function(_u, _v) {
        (
            (
                _Function_2A(_u, _v + H1)
                +
                _Function_2A(_u, _v - H1)
            )
            -
            _Function_2A(_u, _v)*2
        )/HH
    }

#end // macro Est_Der2V_Function_2A


#macro Est_Der2_Functions_2A(_Function_2A)

    Arr_2E(
        Est_Der2U_Function_2A(_Function_2A),
        Est_Der2V_Function_2A(_Function_2A)
    )

#end // macro Est_Der2_Functions_2A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_Der2U_Function_3A(_Function_3A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H1, 2);

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u + H1, _v, _w)
                +
                _Function_3A(_u - H1, _v, _w)
            )
            -
            _Function_3A(_u, _v, _w)*2
        )/HH
    }

#end // macro Est_Der2U_Function_3A


#macro Est_Der2V_Function_3A(_Function_3A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H1, 2);

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u, _v + H1, _w)
                +
                _Function_3A(_u, _v - H1, _w)
            )
            -
            _Function_3A(_u, _v, _w)*2
        )/HH
    }

#end // macro Est_Der2V_Function_3A


#macro Est_Der2W_Function_3A(_Function_3A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H1, 2);

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u, _v, _w + H1)
                +
                _Function_3A(_u, _v, _w - H1)
            )
            -
            _Function_3A(_u, _v, _w)*2
        )/HH
    }

#end // Est_Der2W_Function_3A


#macro Est_Der2_Functions_3A(_Function_3A)

    Arr_3E(
        Est_Der2U_Function_3A(_Function_3A),
        Est_Der2V_Function_3A(_Function_3A),
        Est_Der2W_Function_3A(_Function_3A)
    )

#end // macro Est_Der2_Functions_3A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_Der2U_Function_4A(_Function_4A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H1, 2);

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u + H1, _v, _w, _s)
                +
                _Function_4A(_u - H1, _v, _w, _s)
            )
            -
            _Function_4A(_u, _v, _w, _s)*2
        )/HH
    }

#end // macro Est_Der2U_Function_4A


#macro Est_Der2V_Function_4A(_Function_4A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H1, 2);

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v + H1, _w, _s)
                +
                _Function_4A(_u, _v - H1, _w, _s)
            )
            -
            _Function_4A(_u, _v, _w, _s)*2
        )/HH
    }

#end // macro Est_Der2V_Function_4A


#macro Est_Der2W_Function_4A(_Function_4A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H1, 2);

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v, _w + H1, _s)
                +
                _Function_4A(_u, _v, _w - H1, _s)
            )
            -
            _Function_4A(_u, _v, _w, _s)*2
        )/HH
    }

#end // macro Est_Der2W_Function_4A


#macro Est_Der2S_Function_4A(_Function_4A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local HH = pow(H1, 2);

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v, _w, _s + H1)
                +
                _Function_4A(_u, _v, _w, _s - H1)
            )
            -
            _Function_4A(_u, _v, _w, _s)*2
        )/HH
    }

#end // macro Est_Der2S_Function_4A


#macro Est_Der2_Functions_4A(_Function_4A)

    Arr_4E(
        Est_Der2U_Function_4A(_Function_4A),
        Est_Der2V_Function_4A(_Function_4A),
        Est_Der2W_Function_4A(_Function_4A),
        Est_Der2S_Function_4A(_Function_4A)
    )

#end // macro Est_Der2_Functions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_Der3U_Function_1A(_Function_1A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;
    #local HHH2 = pow(H1, 3)*2;

    function(_u) {
        (
            (
                _Function_1A(_u - H1)
                -
                _Function_1A(_u + H1)
            )*2
            +
            (
                _Function_1A(_u + H2)
                -
                _Function_1A(_u - H2)
            )
        )/HHH2
    }

#end // macro Est_Der3U_Function_1A


#macro Est_Der3_Functions_1A(_Function_1A)

    Arr_1E(
        Est_Der3U_Function_1A(_Function_1A)
    )

#end // macro Est_Der3_Functions_1A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_Der3U_Function_2A(_Function_2A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;
    #local HHH2 = pow(H1, 3)*2;

    function(_u, _v) {
        (
            (
                _Function_2A(_u - H1, _v)
                -
                _Function_2A(_u + H1, _v)
            )*2
            +
            (
                _Function_2A(_u + H2, _v)
                -
                _Function_2A(_u - H2, _v)
            )
        )/HHH2
    }

#end // macro Est_Der3U_Function_2A


#macro Est_Der3V_Function_2A(_Function_2A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;
    #local HHH2 = pow(H1, 3)*2;

    function(_u, _v) {
        (
            (
                _Function_2A(_u, _v - H1)
                -
                _Function_2A(_u, _v + H1)
            )*2
            +
            (
                _Function_2A(_u, _v + H2)
                -
                _Function_2A(_u, _v - H2)
            )
        )/HHH2
    }

#end // macro Est_Der3V_Function_2A


#macro Est_Der3_Functions_2A(_Function_2A)

    Arr_2E(
        Est_Der3U_Function_2A(_Function_2A),
        Est_Der3V_Function_2A(_Function_2A)
    )

#end // macro Est_Der3_Functions_2A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_Der3U_Function_3A(_Function_3A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;
    #local HHH2 = pow(H1, 3)*2;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u - H1, _v, _w)
                -
                _Function_3A(_u + H1, _v, _w)
            )*2
            +
            (
                _Function_3A(_u + H2, _v, _w)
                -
                _Function_3A(_u - H2, _v, _w)
            )
        )/HHH2
    }

#end // macro Est_Der3U_Function_3A


#macro Est_Der3V_Function_3A(_Function_3A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;
    #local HHH2 = pow(H1, 3)*2;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u, _v - H1, _w)
                -
                _Function_3A(_u, _v + H1, _w)
            )*2
            +
            (
                _Function_3A(_u, _v + H2, _w)
                -
                _Function_3A(_u, _v - H2, _w)
            )
        )/HHH2
    }

#end // macro Est_Der3V_Function_3A


#macro Est_Der3W_Function_3A(_Function_3A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;
    #local HHH2 = pow(H1, 3)*2;

    function(_u, _v, _w) {
        (
            (
                _Function_3A(_u, _v, _w - H1)
                -
                _Function_3A(_u, _v, _w + H1)
            )*2
            +
            (
                _Function_3A(_u, _v, _w + H2)
                -
                _Function_3A(_u, _v, _w - H2)
            )
        )/HHH2
    }

#end // macro Est_Der3W_Function_3A


#macro Est_Der3_Functions_3A(_Function_3A)

    Arr_3E(
        Est_Der3U_Function_3A(_Function_3A),
        Est_Der3V_Function_3A(_Function_3A),
        Est_Der3W_Function_3A(_Function_3A)
    )

#end // macro Est_Der3_Functions_3A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#macro Est_Der3U_Function_4A(_Function_4A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;
    #local HHH2 = pow(H1, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u - H1, _v, _w, _s)
                -
                _Function_4A(_u + H1, _v, _w, _s)
            )*2
            +
            (
                _Function_4A(_u + H2, _v, _w, _s)
                -
                _Function_4A(_u - H2, _v, _w, _s)
            )
        )/HHH2
    }

#end // macro Est_Der3U_Function_4A


#macro Est_Der3V_Function_4A(_Function_4A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;
    #local HHH2 = pow(H1, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v - H1, _w, _s)
                -
                _Function_4A(_u, _v + H1, _w, _s)
            )*2
            +
            (
                _Function_4A(_u, _v + H2, _w, _s)
                -
                _Function_4A(_u, _v - H2, _w, _s)
            )
        )/HHH2
    }

#end // macro Est_Der3V_Function_4A


#macro Est_Der3W_Function_4A(_Function_4A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;
    #local HHH2 = pow(H1, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v, _w - H1, _s)
                -
                _Function_4A(_u, _v, _w + H1, _s)
            )*2
            +
            (
                _Function_4A(_u, _v, _w + H2, _s)
                -
                _Function_4A(_u, _v, _w - H2, _s)
            )
        )/HHH2
    }

#end // macro Est_Der3W_Function_4A


#macro Est_Der3S_Function_4A(_Function_4A)

    #local H1 = NUM_DIFF_STEP_SIZE;
    #local H2 = H1*2;
    #local HHH2 = pow(H1, 3)*2;

    function(_u, _v, _w, _s) {
        (
            (
                _Function_4A(_u, _v, _w, _s - H1)
                -
                _Function_4A(_u, _v, _w, _s + H1)
            )*2
            +
            (
                _Function_4A(_u, _v, _w, _s + H2)
                -
                _Function_4A(_u, _v, _w, _s - H2)
            )
        )/HHH2
    }

#end // macro Est_Der3S_Function_4A


#macro Est_Der3_Functions_4A(_Function_4A)

    Arr_4E(
        Est_Der3U_Function_4A(_Function_4A),
        Est_Der3V_Function_4A(_Function_4A),
        Est_Der3W_Function_4A(_Function_4A),
        Est_Der3S_Function_4A(_Function_4A)
    )

#end // macro Est_Der3_Functions_4A

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A
