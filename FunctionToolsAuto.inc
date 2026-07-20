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
