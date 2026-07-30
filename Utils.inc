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


#macro Arr_5E(E0, E1, E2, E3, E4)

    array[5] { E0, E1, E2, E3, E4 }

#end // macro Arr_5E


#macro Arr_6E(E0, E1, E2, E3, E4, E5)

    array[6] { E0, E1, E2, E3, E4, E5 }

#end // macro Arr_6E


#macro Arr_7E(E0, E1, E2, E3, E4, E5, E6)

    array[7] { E0, E1, E2, E3, E4, E5, E6 }

#end // macro Arr_7E


#macro Arr_8E(E0, E1, E2, E3, E4, E5, E6, E7)

    array[8] { E0, E1, E2, E3, E4, E5, E6, E7 }

#end // macro Arr_8E


#macro Arr_9E(E0, E1, E2, E3, E4, E5, E6, E7, E8)

    array[9] { E0, E1, E2, E3, E4, E5, E6, E7, E8 }

#end // macro Arr_9E


#macro Arr_10E(E0, E1, E2, E3, E4, E5, E6, E7, E8, E9)

    array[10] { E0, E1, E2, E3, E4, E5, E6, E7, E8, E9 }

#end // macro Arr_10E


#macro Arr_11E(E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10)

    array[11] { E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10 }

#end // macro Arr_11E


#macro Arr_12E(E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11)

    array[12] { E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11 }

#end // macro Arr_12E


#macro Arr_13E(E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12)

    array[13] { E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12 }

#end // macro Arr_13E


#macro Arr_14E(E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13)

    array[14] { E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13 }

#end // macro Arr_14E


#macro Arr_15E(E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14)

    array[15] { E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14 }

#end // macro Arr_15E


#macro Arr_16E(E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15)

    array[16] { E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15 }

#end // macro Arr_16E


#macro Arr_17E(E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15, E16)

    array[17] { E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15, E16 }

#end // macro Arr_17E


#macro Arr_18E(E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15, E16, E17)

    array[18] { E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15, E16, E17 }

#end // macro Arr_18E


#macro Arr_19E(E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15, E16, E17, E18)

    array[19] { E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15, E16, E17, E18 }

#end // macro Arr_19E


#macro Arr_20E(E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15, E16, E17, E18, E19)

    array[20] { E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15, E16, E17, E18, E19 }

#end // macro Arr_20E

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B

#macro DimSize_I(Array)

    dimension_size(Array, 1)

#end // macro DimSize_I


#macro DimSize_J(Array)

    dimension_size(Array, 2)

#end // macro DimSize_J


#macro DimSize_K(Array)

    dimension_size(Array, 3)

#end // macro DimSize_K


#macro DimSize_L(Array)

    dimension_size(Array, 4)

#end // macro DimSize_L

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A ======= B
