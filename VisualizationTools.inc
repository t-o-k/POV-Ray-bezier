// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A
/*

https://github.com/t-o-k/POV-Ray-bezier

Copyright (c) 2025-2026 Tor Olav Kristensen, http://subcube.com

Use of this source code is governed by the GNU Lesser General Public License version 3,
which can be found in the LICENSE file.

*/
// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7 ======= 8 ======= 9 ======= A

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

#macro From_1N_ShowPoints_2D(Points_1N_2D, Radius)

    #local N = dimensions(Points_1N_2D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(Points_1N_2D, 1);
    #local LastI = SizeI - 1;

    #if (Radius > 0.0)
        #for (I, 0, LastI)
            Sphere_2D(
                Points_1N_2D[I],
                Radius
            )
        #end // for
    #end // if

#end // macro From_1N_ShowPoints_2D


#macro From_3N_ShowPoints_2D(Points_3N_2D, Radius)

    #local N = dimensions(Points_3N_2D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(Points_3N_2D, 1);
    #local SizeJ = dimension_size(Points_3N_2D, 2);
    #local SizeK = dimension_size(Points_3N_2D, 3);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;

    #if (Radius > 0.0)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI)
                    Sphere_2D(
                        Points_3N_2D[I][J][K],
                        Radius
                    )
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_3N_ShowPoints_2D


#macro From_4N_ShowPoints_2D(Points_4N_2D, Radius)

    #local N = dimensions(Points_4N_2D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Points_4N_2D, 1);
    #local SizeJ = dimension_size(Points_4N_2D, 2);
    #local SizeK = dimension_size(Points_4N_2D, 3);
    #local SizeL = dimension_size(Points_4N_2D, 4);
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
                            Points_4N_2D[I][J][K][L],
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

#macro From_1N_ShowPoints_3D(Points_1N_3D, Radius)

    #local N = dimensions(Points_1N_3D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(Points_1N_3D, 1);
    #local LastI = SizeI - 1;

    #if (Radius > 0.0)
        #for (I, 0, LastI)
            sphere {
                Points_1N_3D[I],
                Radius
            }
        #end // for
    #end // if

#end // macro From_1N_ShowPoints_3D


#macro From_2N_ShowPoints_3D(Points_2N_3D, Radius)

    #local N = dimensions(Points_2N_3D);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(Points_2N_3D, 1);
    #local SizeJ = dimension_size(Points_2N_3D, 2);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;

    #if (Radius > 0.0)
        #for (J, 0, LastJ)
            #for (I, 0, LastI)
                sphere {
                    Points_2N_3D[I][J],
                    Radius
                }
            #end // for
        #end // for
    #end // if

#end // macro From_2N_ShowPoints_3D


#macro From_3N_ShowPoints_3D(Points_3N_3D, Radius)

    #local N = dimensions(Points_3N_3D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(Points_3N_3D, 1);
    #local SizeJ = dimension_size(Points_3N_3D, 2);
    #local SizeK = dimension_size(Points_3N_3D, 3);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;

    #if (Radius > 0.0)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI)
                    sphere {
                        Points_3N_3D[I][J][K],
                        Radius
                    }
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_3N_ShowPoints_3D


#macro From_4N_ShowPoints_3D(Points_4N_3D, Radius)

    #local N = dimensions(Points_4N_3D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Points_4N_3D, 1);
    #local SizeJ = dimension_size(Points_4N_3D, 2);
    #local SizeK = dimension_size(Points_4N_3D, 3);
    #local SizeL = dimension_size(Points_4N_3D, 4);
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
                            Points_4N_3D[I][J][K][L],
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

#macro From_1N_ShowLines_2D(Points_1N_2D, Radius_I)

    #local N = dimensions(Points_1N_2D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Radius_I) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_I, 1) != 1)
        #error "Is not 1"
    #end // if
    #local SizeI = dimension_size(Points_1N_2D, 1);
    #local RadiusI = I_E(Radius_I);
    #local LastI = SizeI - 1;

    #if (RadiusI > 0.0)
        #for (I, 0, LastI - 1)
            Cylinder_2D(
                Points_1N_2D[I  ],
                Points_1N_2D[I+1],
                RadiusI
            )
        #end // for
    #end // if

#end // macro From_1N_ShowLines_2D


#macro From_2N_ShowLines_2D(Points_2N_2D, Radius_IJ)

    #local N = dimensions(Points_2N_2D);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Radius_IJ) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJ, 1) != 2)
        #error "Is not 2"
    #end // if
    #local SizeI = dimension_size(Points_2N_2D, 1);
    #local SizeJ = dimension_size(Points_2N_2D, 2);
    #local RadiusI = I_E(Radius_IJ);
    #local RadiusJ = J_E(Radius_IJ);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;

    #if (RadiusI > 0.0)
        #for (J, 0, LastJ)
            #for (I, 0, LastI - 1)
                Cylinder_2D(
                    Points_2N_2D[I  ][J],
                    Points_2N_2D[I+1][J],
                    RadiusI
                )
            #end // for
        #end // for
    #end // if
    #if (RadiusJ > 0.0)
        #for (I, 0, LastI)
            #for (J, 0, LastJ - 1)
                Cylinder_2D(
                    Points_2N_2D[I][J  ],
                    Points_2N_2D[I][J+1],
                    RadiusJ
                )
            #end // for
        #end // for
    #end // if

#end // macro From_2N_ShowLines_2D


#macro From_3N_ShowLines_2D(Points_3N_2D, Radius_IJK)

    #local N = dimensions(Points_3N_2D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Radius_IJK) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJK, 1) != 3)
        #error "Is not 3"
    #end // if
    #local SizeI = dimension_size(Points_3N_2D, 1);
    #local SizeJ = dimension_size(Points_3N_2D, 2);
    #local SizeK = dimension_size(Points_3N_2D, 3);
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
                        Points_3N_2D[I  ][J][K],
                        Points_3N_2D[I+1][J][K],
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
                        Points_3N_2D[I][J  ][K],
                        Points_3N_2D[I][J+1][K],
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
                        Points_3N_2D[I][J][K  ],
                        Points_3N_2D[I][J][K+1],
                        RadiusK
                    )
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_3N_ShowLines_2D


#macro From_4N_ShowLines_2D(Points_4N_2D, Radius_IJKL)

    #local N = dimensions(Points_4N_2D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Radius_IJKL) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJKL, 1) != 4)
        #error "Is not 4"
    #end // if
    #local SizeI = dimension_size(Points_4N_2D, 1);
    #local SizeJ = dimension_size(Points_4N_2D, 2);
    #local SizeK = dimension_size(Points_4N_2D, 3);
    #local SizeL = dimension_size(Points_4N_2D, 4);
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
                            Points_4N_2D[I  ][J][K][L],
                            Points_4N_2D[I+1][J][K][L],
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
                            Points_4N_2D[I][J  ][K][L],
                            Points_4N_2D[I][J+1][K][L],
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
                            Points_4N_2D[I][J][K  ][L],
                            Points_4N_2D[I][J][K+1][L],
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
                            Points_4N_2D[I][J][K][L  ],
                            Points_4N_2D[I][J][K][L+1],
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

#macro From_1N_ShowLines_3D(Points_1N_3D, Radius_I)

    #local N = dimensions(Points_1N_3D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Radius_I) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_I, 1) != 1)
        #error "Is not 1"
    #end // if
    #local SizeI = dimension_size(Points_1N_3D, 1);
    #local RadiusI = I_E(Radius_I);
    #local LastI = SizeI - 1;

    #if (RadiusI > 0.0)
        #for (I, 0, LastI - 1)
            Cylinder_3D(
                Points_1N_3D[I  ],
                Points_1N_3D[I+1],
                RadiusI
            )
        #end // for
    #end // if

#end // macro From_1N_ShowLines_3D


#macro From_2N_ShowLines_3D(Points_2N_3D, Radius_IJ)

    #local N = dimensions(Points_2N_3D);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Radius_IJ) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJ, 1) != 2)
        #error "Is not 2"
    #end // if
    #local SizeI = dimension_size(Points_2N_3D, 1);
    #local SizeJ = dimension_size(Points_2N_3D, 2);
    #local RadiusI = I_E(Radius_IJ);
    #local RadiusJ = J_E(Radius_IJ);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;

    #if (RadiusI > 0.0)
        #for (J, 0, LastJ)
            #for (I, 0, LastI - 1)
                Cylinder_3D(
                    Points_2N_3D[I  ][J],
                    Points_2N_3D[I+1][J],
                    RadiusI
                )
            #end // for
        #end // for
    #end // if
    #if (RadiusJ > 0.0)
        #for (I, 0, LastI)
            #for (J, 0, LastJ - 1)
                Cylinder_3D(
                    Points_2N_3D[I][J  ],
                    Points_2N_3D[I][J+1],
                    RadiusJ
                )
            #end // for
        #end // for
    #end // if

#end // macro From_2N_ShowLines_3D


#macro From_3N_ShowLines_3D(Points_3N_3D, Radius_IJK)

    #local N = dimensions(Points_3N_3D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Radius_IJK) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJK, 1) != 3)
        #error "Is not 3"
    #end // if
    #local SizeI = dimension_size(Points_3N_3D, 1);
    #local SizeJ = dimension_size(Points_3N_3D, 2);
    #local SizeK = dimension_size(Points_3N_3D, 3);
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
                        Points_3N_3D[I  ][J][K],
                        Points_3N_3D[I+1][J][K],
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
                        Points_3N_3D[I][J  ][K],
                        Points_3N_3D[I][J+1][K],
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
                        Points_3N_3D[I][J][K  ],
                        Points_3N_3D[I][J][K+1],
                        RadiusK
                    )
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_3N_ShowLines_3D


#macro From_4N_ShowLines_3D(Points_4N_3D, Radius_IJKL)

    #local N = dimensions(Points_4N_3D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Radius_IJKL) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJKL, 1) != 4)
        #error "Is not 4"
    #end // if
    #local SizeI = dimension_size(Points_4N_3D, 1);
    #local SizeJ = dimension_size(Points_4N_3D, 2);
    #local SizeK = dimension_size(Points_4N_3D, 3);
    #local SizeL = dimension_size(Points_4N_3D, 4);
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
                            Points_4N_3D[I  ][J][K][L],
                            Points_4N_3D[I+1][J][K][L],
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
                            Points_4N_3D[I][J  ][K][L],
                            Points_4N_3D[I][J+1][K][L],
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
                            Points_4N_3D[I][J][K  ][L],
                            Points_4N_3D[I][J][K+1][L],
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
                            Points_4N_3D[I][J][K][L  ],
                            Points_4N_3D[I][J][K][L+1],
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

#macro From_1N_ShowGrid_2D(Points_1N_2D, Radius)

    #local N = dimensions(Points_1N_2D);
    #if (N != 1)
        #error "N is not 1"
    #end // if

    From_1N_ShowPoints_2D(
        Points_1N_2D, Radius
    )
    From_1N_ShowLines_2D(
        Points_1N_2D, Arr_1E(Radius)
    )

#end // macro From_1N_ShowGrid_2D


#macro From_2N_ShowGrid_2D(Points_2N_2D, Radius)

    #local N = dimensions(Points_2N_2D);
    #if (N != 2)
        #error "N is not 2"
    #end // if

    From_2N_ShowPoints_2D(
        Points_2N_2D, Radius
     )
    From_2N_ShowLines_2D(
        Points_2N_2D, Arr_2E(Radius, Radius)
    )

#end // macro From_2N_ShowGrid_2D


#macro From_3N_ShowGrid_2D(Points_3N_2D, Radius)

    #local N = dimensions(Points_3N_2D);
    #if (N != 3)
        #error "N is not 3"
    #end // if

    From_3N_ShowPoints_2D(
        Points_3N_2D, Radius
     )
    From_3N_ShowLines_2D(
        Points_3N_2D, Arr_3E(Radius, Radius, Radius)
    )

#end // macro From_3N_ShowGrid_2D


#macro From_4N_ShowGrid_2D(Points_4N_2D, Radius)

    #local N = dimensions(Points_4N_2D);
    #if (N != 4)
        #error "N is not 4"
    #end // if

    From_4N_ShowPoints_2D(
        Points_4N_2D, Radius
     )
    From_4N_ShowLines_2D(
        Points_4N_2D, Arr_4E(Radius, Radius, Radius, Radius)
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

#macro From_1N_ShowGrid_3D(Points_1N_3D, Radius)

    #local N = dimensions(Points_1N_3D);
    #if (N != 1)
        #error "N is not 1"
    #end // if

    From_1N_ShowPoints_3D(
        Points_1N_3D, Radius
    )
    From_1N_ShowLines_3D(
        Points_1N_3D, Arr_1E(Radius)
    )

#end // macro From_1N_ShowGrid_3D


#macro From_2N_ShowGrid_3D(Points_2N_3D, Radius)

    #local N = dimensions(Points_2N_3D);
    #if (N != 2)
        #error "N is not 2"
    #end // if

    From_2N_ShowPoints_3D(
        Points_2N_3D, Radius
    )
    From_2N_ShowLines_3D(
        Points_2N_3D, Arr_2E(Radius, Radius)
    )

#end // macro From_2N_ShowGrid_3D


#macro From_3N_ShowGrid_3D(Points_3N_3D, Radius)

    #local N = dimensions(Points_3N_3D);
    #if (N != 3)
        #error "N is not 3"
    #end // if

    From_3N_ShowPoints_3D(
        Points_3N_3D, Radius
    )
    From_3N_ShowLines_3D(
        Points_3N_3D, Arr_3E(Radius, Radius, Radius)
    )

#end // macro From_3N_ShowGrid_3D


#macro From_4N_ShowGrid_3D(Points_4N_3D, Radius)

    #local N = dimensions(Points_4N_3D);
    #if (N != 4)
        #error "N is not 4"
    #end // if

    From_4N_ShowPoints_3D(
        Points_4N_3D, Radius
    )
    From_4N_ShowLines_3D(
        Points_4N_3D, Arr_4E(Radius, Radius, Radius, Radius)
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

#macro From_1A_ShowFunctions_2D(_Functions_1A_2D, Min_U, Max_U, Res_U, Radius_U)

    #local M =
        max(
            dimensions(_Functions_1A_2D),
            dimensions(Min_U),
            dimensions(Max_U),
            dimensions(Res_U),
            dimensions(Radius_U)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_1A_2D, 1);
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
                x_E(_Functions_1A_2D)(U),
                y_E(_Functions_1A_2D)(U)
            >
        ;
        Sphere_2D(p0, RadiusU)
        #if (dU > 0.0)
            #for (I, 1, IntervalsU)
                #local U = U + dU;
                #local p1 =
                    <
                        x_E(_Functions_1A_2D)(U),
                        y_E(_Functions_1A_2D)(U)
                    >
                ;
                Cylinder_2D(p0, p1, RadiusU)
                Sphere_2D(p1, RadiusU)
                #local p0 = p1;
            #end // for
        #end // if
    #end // if

#end // macro From_1A_ShowFunctions_2D


#macro From_2A_ShowFunctions_2D(_Functions_2A_2D, Min_UV, Max_UV, Div_UV, Res_UV, Radius_UV)

    #local M =
        max(
            dimensions(_Functions_2A_2D),
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
    #local D = dimension_size(_Functions_2A_2D, 1);
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
                    function(_u) { x_E(_Functions_2A_2D)(_u, V) },
                    function(_u) { y_E(_Functions_2A_2D)(_u, V) }
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
                    function(_v) { x_E(_Functions_2A_2D)(U, _v) },
                    function(_v) { y_E(_Functions_2A_2D)(U, _v) }
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


#macro From_3A_ShowFunctions_2D(_Functions_3A_2D, Min_UVW, Max_UVW, Div_UVW, Res_UVW, Radius_UVW)

    #local M =
        max(
            dimensions(_Functions_3A_2D),
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
    #local D = dimension_size(_Functions_3A_2D, 1);
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
                        function(_u) { x_E(_Functions_3A_2D)(_u, V, W) },
                        function(_u) { y_E(_Functions_3A_2D)(_u, V, W) }
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
                        function(_v) { x_E(_Functions_3A_2D)(U, _v, W) },
                        function(_v) { y_E(_Functions_3A_2D)(U, _v, W) }
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
                        function(_w) { x_E(_Functions_3A_2D)(U, V, _w) },
                        function(_w) { y_E(_Functions_3A_2D)(U, V, _w) }
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


#macro From_4A_ShowFunctions_2D(_Functions_4A_2D, Min_UVWS, Max_UVWS, Div_UVWS, Res_UVWS, Radius_UVWS)

    #local M =
        max(
            dimensions(_Functions_4A_2D),
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
    #local D = dimension_size(_Functions_4A_2D, 1);
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
                            function(_u) { x_E(_Functions_4A_2D)(_u, V, W, S) },
                            function(_u) { y_E(_Functions_4A_2D)(_u, V, W, S) }
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
                            function(_v) { x_E(_Functions_4A_2D)(U, _v, W, S) },
                            function(_v) { y_E(_Functions_4A_2D)(U, _v, W, S) }
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
                            function(_w) { x_E(_Functions_4A_2D)(U, V, _w, S) },
                            function(_w) { y_E(_Functions_4A_2D)(U, V, _w, S) }
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
                            function(_s) { x_E(_Functions_4A_2D)(U, V, W, _s) },
                            function(_s) { y_E(_Functions_4A_2D)(U, V, W, _s) }
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

#macro From_1A_ShowFunctions_3D(_Functions_1A_3D, Min_U, Max_U, Res_U, Radius_U)

    #local M =
        max(
            dimensions(_Functions_1A_3D),
            dimensions(Min_U),
            dimensions(Max_U),
            dimensions(Res_U),
            dimensions(Radius_U)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_1A_3D, 1);
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
                x_E(_Functions_1A_3D)(U),
                y_E(_Functions_1A_3D)(U),
                z_E(_Functions_1A_3D)(U)
            >
        ;
        sphere { p0, RadiusU }
        #if (dU > 0.0)
            #for (I, 1, IntervalsU)
                #local U = U + dU;
                #local p1 =
                    <
                        x_E(_Functions_1A_3D)(U),
                        y_E(_Functions_1A_3D)(U),
                        z_E(_Functions_1A_3D)(U)
                    >
                ;
                Cylinder_3D(p0, p1, RadiusU)
                sphere { p1, RadiusU }
                #local p0 = p1;
            #end // for
        #end // if
    #end // if

#end // macro From_1A_ShowFunctions_3D


#macro From_2A_ShowFunctions_3D(_Functions_2A_3D, Min_UV, Max_UV, Div_UV, Res_UV, Radius_UV)

    #local M =
        max(
            dimensions(_Functions_2A_3D),
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
    #local D = dimension_size(_Functions_2A_3D, 1);
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
                    function(_u) { x_E(_Functions_2A_3D)(_u, V) },
                    function(_u) { y_E(_Functions_2A_3D)(_u, V) },
                    function(_u) { z_E(_Functions_2A_3D)(_u, V) }
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
                    function(_v) { x_E(_Functions_2A_3D)(U, _v) },
                    function(_v) { y_E(_Functions_2A_3D)(U, _v) },
                    function(_v) { z_E(_Functions_2A_3D)(U, _v) }
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


#macro From_3A_ShowFunctions_3D(_Functions_3A_3D, Min_UVW, Max_UVW, Div_UVW, Res_UVW, Radius_UVW)

    #local M =
        max(
            dimensions(_Functions_3A_3D),
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
    #local D = dimension_size(_Functions_3A_3D, 1);
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
                        function(_u) { x_E(_Functions_3A_3D)(_u, V, W) },
                        function(_u) { y_E(_Functions_3A_3D)(_u, V, W) },
                        function(_u) { z_E(_Functions_3A_3D)(_u, V, W) }
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
                        function(_v) { x_E(_Functions_3A_3D)(U, _v, W) },
                        function(_v) { y_E(_Functions_3A_3D)(U, _v, W) },
                        function(_v) { z_E(_Functions_3A_3D)(U, _v, W) }
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
                        function(_w) { x_E(_Functions_3A_3D)(U, V, _w) },
                        function(_w) { y_E(_Functions_3A_3D)(U, V, _w) },
                        function(_w) { z_E(_Functions_3A_3D)(U, V, _w) }
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


#macro From_4A_ShowFunctions_3D(_Functions_4A_3D, Min_UVWS, Max_UVWS, Div_UVWS, Res_UVWS, Radius_UVWS)

    #local M =
        max(
            dimensions(_Functions_4A_3D),
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
    #local D = dimension_size(_Functions_4A_3D, 1);
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
                            function(_u) { x_E(_Functions_4A_3D)(_u, V, W, S) },
                            function(_u) { y_E(_Functions_4A_3D)(_u, V, W, S) },
                            function(_u) { z_E(_Functions_4A_3D)(_u, V, W, S) }
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
                            function(_v) { x_E(_Functions_4A_3D)(U, _v, W, S) },
                            function(_v) { y_E(_Functions_4A_3D)(U, _v, W, S) },
                            function(_v) { z_E(_Functions_4A_3D)(U, _v, W, S) }
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
                            function(_w) { x_E(_Functions_4A_3D)(U, V, _w, S) },
                            function(_w) { y_E(_Functions_4A_3D)(U, V, _w, S) },
                            function(_w) { z_E(_Functions_4A_3D)(U, V, _w, S) }
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
                            function(_s) { x_E(_Functions_4A_3D)(U, V, W, _s) },
                            function(_s) { y_E(_Functions_4A_3D)(U, V, W, _s) },
                            function(_s) { z_E(_Functions_4A_3D)(U, V, W, _s) }
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

#macro DrawPatch_3D(_Functions_2A_3D, Min_UV, Max_UV, Div_UV)

    #local M =
        max(
            dimensions(_Functions_2A_3D),
            dimensions(Min_UV),
            dimensions(Max_UV),
            dimensions(Div_UV)
        )
    ;
    #if (M != 1)
        #error "M is not 1"
    #end // if
    #local D = dimension_size(_Functions_2A_3D, 1);
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
                        x_E(_Functions_2A_3D)(U0, V0),
                        y_E(_Functions_2A_3D)(U0, V0),
                        z_E(_Functions_2A_3D)(U0, V0)
                    >
                ;
                #local p10 =
                    <
                        x_E(_Functions_2A_3D)(U1, V0),
                        y_E(_Functions_2A_3D)(U1, V0),
                        z_E(_Functions_2A_3D)(U1, V0)
                    >;
                #local p01 =
                    <
                        x_E(_Functions_2A_3D)(U0, V1),
                        y_E(_Functions_2A_3D)(U0, V1),
                        z_E(_Functions_2A_3D)(U0, V1)
                    >
                ;
                #local p11 =
                    <
                        x_E(_Functions_2A_3D)(U1, V1),
                        y_E(_Functions_2A_3D)(U1, V1),
                        z_E(_Functions_2A_3D)(U1, V1)
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
