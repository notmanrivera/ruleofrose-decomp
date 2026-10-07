// libvu0 (SDK 3.0), reconstructed: only what the game's code uses.
#ifndef SDK_LIBVU0_H
#define SDK_LIBVU0_H

typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));

extern "C" {

void sceVu0ApplyMatrix(sceVu0FVECTOR v0, sceVu0FMATRIX m0, sceVu0FVECTOR v1);
void sceVu0OuterProduct(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);
float sceVu0InnerProduct(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
void sceVu0Normalize(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
void sceVu0UnitMatrix(sceVu0FMATRIX m0);
void sceVu0RotMatrixZ(sceVu0FMATRIX m0, sceVu0FMATRIX m1, float rz);
void sceVu0RotMatrixX(sceVu0FMATRIX m0, sceVu0FMATRIX m1, float rx);
void sceVu0RotMatrixY(sceVu0FMATRIX m0, sceVu0FMATRIX m1, float ry);
void sceVpu0Reset(void);

}

#endif
