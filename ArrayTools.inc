// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A
/*

https://github.com/t-o-k/POV-Ray-bezier

Copyright (c) 2025-2026 Tor Olav Kristensen, http://subcube.com

Use of this source code is governed by the GNU Lesser General Public License version 3,
which can be found in the LICENSE file.

*/
// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

#version 3.7;

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

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

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A
