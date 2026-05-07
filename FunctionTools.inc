// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= 10
/*

https://github.com/t-o-k/POV-Ray-bezier

Copyright (c) 2025-2026 Tor Olav Kristensen, http://subcube.com

Use of this source code is governed by the GNU Lesser General Public License version 3,
which can be found in the LICENSE file.

*/
// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= 10

#version 3.7;

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
