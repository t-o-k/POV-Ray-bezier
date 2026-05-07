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

#macro From_1N_ShowPoints_2D(Points_1N2D, Radius)

    #local N = dimensions(Points_1N2D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(Points_1N2D, 1);
    #local LastI = SizeI - 1;

    #if (Radius > 0.0)
        #for (I, 0, LastI)
            Sphere_2D(
                Points_1N2D[I],
                Radius
            )
        #end // for
    #end // if

#end // macro From_1N_ShowPoints_2D


#macro From_3N_ShowPoints_2D(Points_3N2D, Radius)

    #local N = dimensions(Points_3N2D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(Points_3N2D, 1);
    #local SizeJ = dimension_size(Points_3N2D, 2);
    #local SizeK = dimension_size(Points_3N2D, 3);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;

    #if (Radius > 0.0)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI)
                    Sphere_2D(
                        Points_3N2D[I][J][K],
                        Radius
                    )
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_3N_ShowPoints_2D


#macro From_4N_ShowPoints_2D(Points_4N2D, Radius)

    #local N = dimensions(Points_4N2D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Points_4N2D, 1);
    #local SizeJ = dimension_size(Points_4N2D, 2);
    #local SizeK = dimension_size(Points_4N2D, 3);
    #local SizeL = dimension_size(Points_4N2D, 4);
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
                            Points_4N2D[I][J][K][L],
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

#macro From_1N_ShowPoints_3D(Points_1N3D, Radius)

    #local N = dimensions(Points_1N3D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #local SizeI = dimension_size(Points_1N3D, 1);
    #local LastI = SizeI - 1;

    #if (Radius > 0.0)
        #for (I, 0, LastI)
            sphere {
                Points_1N3D[I],
                Radius
            }
        #end // for
    #end // if

#end // macro From_1N_ShowPoints_3D


#macro From_2N_ShowPoints_3D(Points_2N3D, Radius)

    #local N = dimensions(Points_2N3D);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #local SizeI = dimension_size(Points_2N3D, 1);
    #local SizeJ = dimension_size(Points_2N3D, 2);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;

    #if (Radius > 0.0)
        #for (J, 0, LastJ)
            #for (I, 0, LastI)
                sphere {
                    Points_2N3D[I][J],
                    Radius
                }
            #end // for
        #end // for
    #end // if

#end // macro From_2N_ShowPoints_3D


#macro From_3N_ShowPoints_3D(Points_3N3D, Radius)

    #local N = dimensions(Points_3N3D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #local SizeI = dimension_size(Points_3N3D, 1);
    #local SizeJ = dimension_size(Points_3N3D, 2);
    #local SizeK = dimension_size(Points_3N3D, 3);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;
    #local LastK = SizeK - 1;

    #if (Radius > 0.0)
        #for (K, 0, LastK)
            #for (J, 0, LastJ)
                #for (I, 0, LastI)
                    sphere {
                        Points_3N3D[I][J][K],
                        Radius
                    }
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_3N_ShowPoints_3D


#macro From_4N_ShowPoints_3D(Points_4N3D, Radius)

    #local N = dimensions(Points_4N3D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #local SizeI = dimension_size(Points_4N3D, 1);
    #local SizeJ = dimension_size(Points_4N3D, 2);
    #local SizeK = dimension_size(Points_4N3D, 3);
    #local SizeL = dimension_size(Points_4N3D, 4);
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
                            Points_4N3D[I][J][K][L],
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

#macro From_1N_ShowLines_2D(Points_1N2D, Radius_I)

    #local N = dimensions(Points_1N2D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Radius_I) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_I, 1) != 1)
        #error "Is not 1"
    #end // if
    #local SizeI = dimension_size(Points_1N2D, 1);
    #local RadiusI = I_E(Radius_I);
    #local LastI = SizeI - 1;

    #if (RadiusI > 0.0)
        #for (I, 0, LastI - 1)
            Cylinder_2D(
                Points_1N2D[I  ],
                Points_1N2D[I+1],
                RadiusI
            )
        #end // for
    #end // if

#end // macro From_1N_ShowLines_2D


#macro From_2N_ShowLines_2D(Points_2N2D, Radius_IJ)

    #local N = dimensions(Points_2N2D);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Radius_IJ) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJ, 1) != 2)
        #error "Is not 2"
    #end // if
    #local SizeI = dimension_size(Points_2N2D, 1);
    #local SizeJ = dimension_size(Points_2N2D, 2);
    #local RadiusI = I_E(Radius_IJ);
    #local RadiusJ = J_E(Radius_IJ);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;

    #if (RadiusI > 0.0)
        #for (J, 0, LastJ)
            #for (I, 0, LastI - 1)
                Cylinder_2D(
                    Points_2N2D[I  ][J],
                    Points_2N2D[I+1][J],
                    RadiusI
                )
            #end // for
        #end // for
    #end // if
    #if (RadiusJ > 0.0)
        #for (I, 0, LastI)
            #for (J, 0, LastJ - 1)
                Cylinder_2D(
                    Points_2N2D[I][J  ],
                    Points_2N2D[I][J+1],
                    RadiusJ
                )
            #end // for
        #end // for
    #end // if

#end // macro From_2N_ShowLines_2D


#macro From_3N_ShowLines_2D(Points_3N2D, Radius_IJK)

    #local N = dimensions(Points_3N2D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Radius_IJK) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJK, 1) != 3)
        #error "Is not 3"
    #end // if
    #local SizeI = dimension_size(Points_3N2D, 1);
    #local SizeJ = dimension_size(Points_3N2D, 2);
    #local SizeK = dimension_size(Points_3N2D, 3);
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
                        Points_3N2D[I  ][J][K],
                        Points_3N2D[I+1][J][K],
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
                        Points_3N2D[I][J  ][K],
                        Points_3N2D[I][J+1][K],
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
                        Points_3N2D[I][J][K  ],
                        Points_3N2D[I][J][K+1],
                        RadiusK
                    )
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_3N_ShowLines_2D


#macro From_4N_ShowLines_2D(Points_4N2D, Radius_IJKL)

    #local N = dimensions(Points_4N2D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Radius_IJKL) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJKL, 1) != 4)
        #error "Is not 4"
    #end // if
    #local SizeI = dimension_size(Points_4N2D, 1);
    #local SizeJ = dimension_size(Points_4N2D, 2);
    #local SizeK = dimension_size(Points_4N2D, 3);
    #local SizeL = dimension_size(Points_4N2D, 4);
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
                            Points_4N2D[I  ][J][K][L],
                            Points_4N2D[I+1][J][K][L],
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
                            Points_4N2D[I][J  ][K][L],
                            Points_4N2D[I][J+1][K][L],
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
                            Points_4N2D[I][J][K  ][L],
                            Points_4N2D[I][J][K+1][L],
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
                            Points_4N2D[I][J][K][L  ],
                            Points_4N2D[I][J][K][L+1],
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

#macro From_1N_ShowLines_3D(Points_1N3D, Radius_I)

    #local N = dimensions(Points_1N3D);
    #if (N != 1)
        #error "N is not 1"
    #end // if
    #if (dimensions(Radius_I) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_I, 1) != 1)
        #error "Is not 1"
    #end // if
    #local SizeI = dimension_size(Points_1N3D, 1);
    #local RadiusI = I_E(Radius_I);
    #local LastI = SizeI - 1;

    #if (RadiusI > 0.0)
        #for (I, 0, LastI - 1)
            Cylinder_3D(
                Points_1N3D[I  ],
                Points_1N3D[I+1],
                RadiusI
            )
        #end // for
    #end // if

#end // macro From_1N_ShowLines_3D


#macro From_2N_ShowLines_3D(Points_2N3D, Radius_IJ)

    #local N = dimensions(Points_2N3D);
    #if (N != 2)
        #error "N is not 2"
    #end // if
    #if (dimensions(Radius_IJ) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJ, 1) != 2)
        #error "Is not 2"
    #end // if
    #local SizeI = dimension_size(Points_2N3D, 1);
    #local SizeJ = dimension_size(Points_2N3D, 2);
    #local RadiusI = I_E(Radius_IJ);
    #local RadiusJ = J_E(Radius_IJ);
    #local LastI = SizeI - 1;
    #local LastJ = SizeJ - 1;

    #if (RadiusI > 0.0)
        #for (J, 0, LastJ)
            #for (I, 0, LastI - 1)
                Cylinder_3D(
                    Points_2N3D[I  ][J],
                    Points_2N3D[I+1][J],
                    RadiusI
                )
            #end // for
        #end // for
    #end // if
    #if (RadiusJ > 0.0)
        #for (I, 0, LastI)
            #for (J, 0, LastJ - 1)
                Cylinder_3D(
                    Points_2N3D[I][J  ],
                    Points_2N3D[I][J+1],
                    RadiusJ
                )
            #end // for
        #end // for
    #end // if

#end // macro From_2N_ShowLines_3D


#macro From_3N_ShowLines_3D(Points_3N3D, Radius_IJK)

    #local N = dimensions(Points_3N3D);
    #if (N != 3)
        #error "N is not 3"
    #end // if
    #if (dimensions(Radius_IJK) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJK, 1) != 3)
        #error "Is not 3"
    #end // if
    #local SizeI = dimension_size(Points_3N3D, 1);
    #local SizeJ = dimension_size(Points_3N3D, 2);
    #local SizeK = dimension_size(Points_3N3D, 3);
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
                        Points_3N3D[I  ][J][K],
                        Points_3N3D[I+1][J][K],
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
                        Points_3N3D[I][J  ][K],
                        Points_3N3D[I][J+1][K],
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
                        Points_3N3D[I][J][K  ],
                        Points_3N3D[I][J][K+1],
                        RadiusK
                    )
                #end // for
            #end // for
        #end // for
    #end // if

#end // macro From_3N_ShowLines_3D


#macro From_4N_ShowLines_3D(Points_4N3D, Radius_IJKL)

    #local N = dimensions(Points_4N3D);
    #if (N != 4)
        #error "N is not 4"
    #end // if
    #if (dimensions(Radius_IJKL) != 1)
        #error "Is not 1"
    #end // if
    #if (dimension_size(Radius_IJKL, 1) != 4)
        #error "Is not 4"
    #end // if
    #local SizeI = dimension_size(Points_4N3D, 1);
    #local SizeJ = dimension_size(Points_4N3D, 2);
    #local SizeK = dimension_size(Points_4N3D, 3);
    #local SizeL = dimension_size(Points_4N3D, 4);
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
                            Points_4N3D[I  ][J][K][L],
                            Points_4N3D[I+1][J][K][L],
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
                            Points_4N3D[I][J  ][K][L],
                            Points_4N3D[I][J+1][K][L],
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
                            Points_4N3D[I][J][K  ][L],
                            Points_4N3D[I][J][K+1][L],
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
                            Points_4N3D[I][J][K][L  ],
                            Points_4N3D[I][J][K][L+1],
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

#macro From_1N_ShowGrid_2D(Points_1N2D, Radius)

    #local N = dimensions(Points_1N2D);
    #if (N != 1)
        #error "N is not 1"
    #end // if

    From_1N_ShowPoints_2D(
        Points_1N2D, Radius
    )
    From_1N_ShowLines_2D(
        Points_1N2D, Arr_1E(Radius)
    )

#end // macro From_1N_ShowGrid_2D


#macro From_2N_ShowGrid_2D(Points_2N2D, Radius)

    #local N = dimensions(Points_2N2D);
    #if (N != 2)
        #error "N is not 2"
    #end // if

    From_2N_ShowPoints_2D(
        Points_2N2D, Radius
     )
    From_2N_ShowLines_2D(
        Points_2N2D, Arr_2E(Radius, Radius)
    )

#end // macro From_2N_ShowGrid_2D


#macro From_3N_ShowGrid_2D(Points_3N2D, Radius)

    #local N = dimensions(Points_3N2D);
    #if (N != 3)
        #error "N is not 3"
    #end // if

    From_3N_ShowPoints_2D(
        Points_3N2D, Radius
     )
    From_3N_ShowLines_2D(
        Points_3N2D, Arr_3E(Radius, Radius, Radius)
    )

#end // macro From_3N_ShowGrid_2D


#macro From_4N_ShowGrid_2D(Points_4N2D, Radius)

    #local N = dimensions(Points_4N2D);
    #if (N != 4)
        #error "N is not 4"
    #end // if

    From_4N_ShowPoints_2D(
        Points_4N2D, Radius
     )
    From_4N_ShowLines_2D(
        Points_4N2D, Arr_4E(Radius, Radius, Radius, Radius)
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

#macro From_1N_ShowGrid_3D(Points_1N3D, Radius)

    #local N = dimensions(Points_1N3D);
    #if (N != 1)
        #error "N is not 1"
    #end // if

    From_1N_ShowPoints_3D(
        Points_1N3D, Radius
    )
    From_1N_ShowLines_3D(
        Points_1N3D, Arr_1E(Radius)
    )

#end // macro From_1N_ShowGrid_3D


#macro From_2N_ShowGrid_3D(Points_2N3D, Radius)

    #local N = dimensions(Points_2N3D);
    #if (N != 2)
        #error "N is not 2"
    #end // if

    From_2N_ShowPoints_3D(
        Points_2N3D, Radius
    )
    From_2N_ShowLines_3D(
        Points_2N3D, Arr_2E(Radius, Radius)
    )

#end // macro From_2N_ShowGrid_3D


#macro From_3N_ShowGrid_3D(Points_3N3D, Radius)

    #local N = dimensions(Points_3N3D);
    #if (N != 3)
        #error "N is not 3"
    #end // if

    From_3N_ShowPoints_3D(
        Points_3N3D, Radius
    )
    From_3N_ShowLines_3D(
        Points_3N3D, Arr_3E(Radius, Radius, Radius)
    )

#end // macro From_3N_ShowGrid_3D


#macro From_4N_ShowGrid_3D(Points_4N3D, Radius)

    #local N = dimensions(Points_4N3D);
    #if (N != 4)
        #error "N is not 4"
    #end // if

    From_4N_ShowPoints_3D(
        Points_4N3D, Radius
    )
    From_4N_ShowLines_3D(
        Points_4N3D, Arr_4E(Radius, Radius, Radius, Radius)
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
