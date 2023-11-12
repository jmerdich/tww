//
// Generated by dtk
// Translation Unit: J3DTevs.cpp
//

#include "JSystem/J3DGraphBase/J3DTevs.h"
#include "JSystem/J3DGraphBase/J3DSys.h"
#include "JSystem/J3DGraphBase/J3DTexture.h"
#include "JSystem/J3DGraphBase/J3DTransform.h"

/* 802EBC94-802EBD48       .text load__11J3DLightObjCFUl */
void J3DLightObj::load(u32 lightIdx) const {
    GDOverflowCheck(0x48);
    J3DGDSetLightPos(GXLightID(1 << lightIdx), mInfo.mLightPosition.x, mInfo.mLightPosition.y, mInfo.mLightPosition.z);
    J3DGDSetLightAttn(GXLightID(1 << lightIdx), mInfo.mCosAtten.x, mInfo.mCosAtten.y, mInfo.mCosAtten.z, mInfo.mDistAtten.x, mInfo.mDistAtten.y, mInfo.mDistAtten.z);
    J3DGDSetLightColor(GXLightID(1 << lightIdx), mInfo.mColor);
    J3DGDSetLightDir(GXLightID(1 << lightIdx), mInfo.mLightDirection.x, mInfo.mLightDirection.y, mInfo.mLightDirection.z);
}

/* 802EBD48-802EBF40       .text loadTexCoordGens__FUlP11J3DTexCoord */
void loadTexCoordGens(u32 num, J3DTexCoord* pTexCoord) {
    GDOverflowCheck(num * 8 + 10);
    J3DGDWriteXFCmdHdr(0x1040, num);
    for (int i = 0; i < num; i++) {
        J3DGDSetTexCoordGen(
            GXTexGenType(pTexCoord[i].getTexGenType()),
            GXTexGenSrc(pTexCoord[i].getTexGenSrc())
        );
    }
    static u32 dualReg = 61;
    J3DGDWriteXFCmdHdr(0x1050, num);
    for (int i = 0; i < num; i++) {
        J3DGDWrite_u32(dualReg);
    }
}

/* 802EBF40-802EC358       .text calc__9J3DTexMtxFv */
void J3DTexMtx::calc() {
    Mtx44 mtx1;
    Mtx44 mtx2;

    Mtx qMtx = {
        0.5f, 0.0f, 0.5f, 0.0f,
        0.0f, -0.5f, 0.5f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
    };
    Mtx qMtx2 = {
        0.5f, 0.0f, 0.0f, 0.5f,
        0.0f, -0.5f, 0.0f, 0.5f,
        0.0f, 0.0f, 1.0f, 0.0f,
    };

    u32 mode = mTexMtxInfo.mInfo & 0x7f;
    u32 extra = (mTexMtxInfo.mInfo >> 7) & 1;

    if (mode == J3DTexMtxMode_Projmap || mode == J3DTexMtxMode_ViewProjmap || mode == J3DTexMtxMode_EnvmapEffectMtx) {
        if (extra == 0) {
            J3DGetTextureMtx(mTexMtxInfo.mSRT, mTexMtxInfo.mCenter, mtx2);
        } else if (extra == 1) {
            J3DGetTextureMtxMaya(mTexMtxInfo.mSRT, mtx2);
        }
        MTXConcat(mtx2, qMtx, mtx2);
        J3DMtxProjConcat(mtx2, mTexMtxInfo.mEffectMtx, mtx1);
        MTXConcat(mtx1, mViewMtx, mMtx);
    } else if (mode == J3DTexMtxMode_Envmap) {
        if (extra == 0) {
            J3DGetTextureMtx(mTexMtxInfo.mSRT, mTexMtxInfo.mCenter, mtx1);
        } else if (extra == 1) {
            J3DGetTextureMtxMaya(mTexMtxInfo.mSRT, mtx1);
        }
        MTXConcat(mtx1, qMtx, mtx1);
        MTXConcat(mtx1, mViewMtx, mMtx);
    } else if (mode == J3DTexMtxMode_EnvmapOldEffectMtx) {
        if (extra == 0) {
            J3DGetTextureMtxOld(mTexMtxInfo.mSRT, mTexMtxInfo.mCenter, mtx2);
        } else if (extra == 1) {
            J3DGetTextureMtxMayaOld(mTexMtxInfo.mSRT, mtx2);
        }
        MTXConcat(mtx2, qMtx2, mtx2);
        J3DMtxProjConcat(mtx2, mTexMtxInfo.mEffectMtx, mtx1);
        MTXConcat(mtx1, mViewMtx, mMtx);
    } else if (mode == J3DTexMtxMode_EnvmapOld) {
        if (extra == 0) {
            J3DGetTextureMtxOld(mTexMtxInfo.mSRT, mTexMtxInfo.mCenter, mtx1);
        } else if (extra == 1) {
            J3DGetTextureMtxMayaOld(mTexMtxInfo.mSRT, mtx1);
        }
        MTXConcat(mtx1, qMtx2, mtx1);
        MTXConcat(mtx1, mViewMtx, mMtx);
    } else if (mode == J3DTexMtxMode_EnvmapBasic) {
        if (extra == 0) {
            J3DGetTextureMtxOld(mTexMtxInfo.mSRT, mTexMtxInfo.mCenter, mtx1);
        } else if (extra == 1) {
            J3DGetTextureMtxMayaOld(mTexMtxInfo.mSRT, mtx1);
        }
        MTXConcat(mtx1, mViewMtx, mMtx);
    } else if (mode == J3DTexMtxMode_ProjmapBasic || mode == J3DTexMtxMode_ViewProjmapBasic || mode == J3DTexMtxMode_Unknown5) {
        if (extra == 0) {
            J3DGetTextureMtxOld(mTexMtxInfo.mSRT, mTexMtxInfo.mCenter, mtx2);
        } else if (extra == 1) {
            J3DGetTextureMtxMayaOld(mTexMtxInfo.mSRT, mtx2);
        }
        J3DMtxProjConcat(mtx2, mTexMtxInfo.mEffectMtx, mtx1);
        MTXConcat(mtx1, mViewMtx, mMtx);
    } else if (mode == J3DTexMtxMode_Unknown4) {
        if (extra == 0) {
            J3DGetTextureMtxOld(mTexMtxInfo.mSRT, mTexMtxInfo.mCenter, mtx2);
        } else if (extra == 1) {
            J3DGetTextureMtxMayaOld(mTexMtxInfo.mSRT, mtx2);
        }
        J3DMtxProjConcat(mtx2, mTexMtxInfo.mEffectMtx, mMtx);
    } else {
        if (extra == 0) {
            J3DGetTextureMtxOld(mTexMtxInfo.mSRT, mTexMtxInfo.mCenter, mMtx);
        } else if (extra == 1) {
            J3DGetTextureMtxMayaOld(mTexMtxInfo.mSRT, mMtx);
        }
    }
}

/* 802EC358-802EC37C       .text isTexNoReg__FPv */
bool isTexNoReg(void* param_0) {
    u8 r31 = ((u8*)param_0)[1];
    if (r31 >= 0x80 && r31 <= 0xbb) {
        return true;
    }
    return false;
}

/* 802EC37C-802EC388       .text getTexNoReg__FPv */
u16 getTexNoReg(void* param_0) {
    return *(u32*)((u8*)param_0 + 1);
}

/* 802EC388-802EC530       .text loadTexNo__FUlRCUs */
void loadTexNo(u32 param_0, const u16& param_1) {
    ResTIMG* resTIMG = j3dSys.getTexture()->getResTIMG(param_1);
    J3DSys::sTexCoordScaleTable[param_0].field_0x00 = resTIMG->width;
    J3DSys::sTexCoordScaleTable[param_0].field_0x02 = resTIMG->height;
    GDOverflowCheck(0x14);
    J3DGDSetTexImgPtr(GXTexMapID(param_0), (u8*)resTIMG + resTIMG->imageOffset);
    J3DGDSetTexImgAttr(GXTexMapID(param_0), resTIMG->width, resTIMG->height, GXTexFmt(resTIMG->format & 0x0f));
    J3DGDSetTexLookupMode(GXTexMapID(param_0), GXTexWrapMode(resTIMG->wrapS), GXTexWrapMode(resTIMG->wrapT), GXTexFilter(resTIMG->minFilter), GXTexFilter(resTIMG->magFilter), resTIMG->minLOD * 0.125f, resTIMG->maxLOD * 0.125f, resTIMG->LODBias * 0.01f, resTIMG->biasClamp, resTIMG->doEdgeLOD, GXAnisotropy(resTIMG->maxAnisotropy));
    if (resTIMG->indexTexture == true) {
        GXTlutSize tlutSize = resTIMG->numColors > 16 ? GX_TLUT_256 : GX_TLUT_16;
        GDOverflowCheck(0x14);
        J3DGDLoadTlut((u8*)resTIMG + resTIMG->paletteOffset, (param_0 << 13) + 0xf0000, tlutSize);
        J3DGDSetTexTlut(GXTexMapID(param_0), (param_0 << 13) + 0xf0000, GXTlutFmt(resTIMG->colorFormat));
    }
}

/* 802EC530-802EC554       .text patchTexNo_PtrToIdx__FUlRCUs */
void patchTexNo_PtrToIdx(u32 texID, const u16& idx) {
    J3DGDSetTexImgPtrRaw(GXTexMapID(texID), idx);
}

/* 802EC554-802EC588       .text loadNBTScale__FR11J3DNBTScale */
void loadNBTScale(J3DNBTScale& param_0) {
    if (param_0.mbHasScale == true) {
        j3dSys.setNBTScale(&param_0.mScale);
    } else {
        j3dSys.setNBTScale(NULL);
    }
}

const J3DLightInfo j3dDefaultLightInfo = {
    0.0f, 0.0f, 0.0f,
    0.0f, -1.0f, 0.0f,
    0xff, 0xff, 0xff, 0xff,
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
};

const J3DTexCoordInfo j3dDefaultTexCoordInfo[8] = {
    {GX_MTX2x4, GX_TG_TEX0, GX_IDENTITY}, {GX_MTX2x4, GX_TG_TEX1, GX_IDENTITY},
    {GX_MTX2x4, GX_TG_TEX2, GX_IDENTITY}, {GX_MTX2x4, GX_TG_TEX3, GX_IDENTITY},
    {GX_MTX2x4, GX_TG_TEX4, GX_IDENTITY}, {GX_MTX2x4, GX_TG_TEX5, GX_IDENTITY},
    {GX_MTX2x4, GX_TG_TEX6, GX_IDENTITY}, {GX_MTX2x4, GX_TG_TEX7, GX_IDENTITY},
};

const J3DTexMtxInfo j3dDefaultTexMtxInfo = {
    0x01, 0x00, 0xFF, 0xFF,
    0.0f, 0.0f, 0.0f,
    1.0f, 1.0f, 0, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
};

const J3DIndTexMtxInfo j3dDefaultIndTexMtxInfo = {
    0.5f, 0.0f, 0.0f,
    0.0f, 0.5f, 0.0f,
    1,
};

const J3DTevStageInfo j3dDefaultTevStageInfo = {
    0x04, 0x0A, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x05, 0x07, 0x07, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x00,
};

const J3DIndTevStageInfo j3dDefaultIndTevStageInfo = {};

const J3DFogInfo j3dDefaultFogInfo = {
    0, 0, 0x140,
    0.0f, 0.0f, 0.1f, 10000.0f,
    0xFF, 0xFF, 0xFF, 0x00,
};

const J3DNBTScaleInfo j3dDefaultNBTScaleInfo = {
    0,
    1.0f, 1.0f, 1.0f
};

static u8 j3dTexCoordTable[7623];

/* 802EC588-802EC630       .text makeTexCoordTable__Fv */
void makeTexCoordTable() {
    u8 texMtx[] = {
        GX_TEXMTX0,
        GX_TEXMTX1,
        GX_TEXMTX2,
        GX_TEXMTX3,
        GX_TEXMTX4,
        GX_TEXMTX5,
        GX_TEXMTX6,
        GX_TEXMTX7,
        GX_TEXMTX8,
        GX_TEXMTX9,
        GX_IDENTITY,
    };

    u8* table = j3dTexCoordTable;
    for (u32 i = 0; i < 11; i++) {
        for (u32 j = 0; j < 21; j++) {
            for (int k = 0; k < ARRAY_SIZE(texMtx); k++) {
                u32 idx = j * 11 + i * 0xe7 + k;
                table[idx * 3 + 0] = i;
                table[idx * 3 + 1] = j;
                table[idx * 3 + 2] = texMtx[k];
            }
        }
    }
}

u8 j3dTevSwapTableTable[1024];
u8 j3dAlphaCmpTable[768];

/* 802EC630-802EC69C       .text makeAlphaCmpTable__Fv */
void makeAlphaCmpTable() {
    u8* table = j3dAlphaCmpTable;
    for (u32 i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            for (u32 k = 0; k < 8; k++) {
                u32 idx = i * 32 + j * 8 + k;
                table[idx * 3 + 0] = i;
                table[idx * 3 + 1] = j;
                table[idx * 3 + 2] = k;
            }
        }
    }
}

J3DZModeInfo j3dZModeTable[0x20];

/* 802EC69C-802EC708       .text makeZModeTable__Fv */
void makeZModeTable() {
    J3DZModeInfo* table = j3dZModeTable;
    for (int i = 0; i < 2; i++) {
        for (u32 j = 0; j < 8; j++) {
            for (int k = 0; k < 2; k++) {
                u32 idx = j * 2 + i * 16 + k;
                table[idx].mCompareEnable = i;
                table[idx].mFunc = j;
                table[idx].mUpdateEnable = k;
            }
        }
    }
}

/* 802EC708-802EC74C       .text makeTevSwapTable__Fv */
void makeTevSwapTable() {
    u8* table = j3dTevSwapTableTable;
    int i = 0;
    do {
        table[0] = i >> 6;
        table[1] = (i >> 4) & 3;
        table[2] = (i >> 2) & 3;
        table[3] = i & 3;
        i++;
        table += 4;
    } while (i < 256);
}

const GXColor j3dDefaultColInfo = {0xFF, 0xFF, 0xFF, 0xFF};
const GXColor j3dDefaultAmbInfo = {0x32, 0x32, 0x32, 0x32};
const u8 j3dDefaultColorChanNum = 0x01;
const J3DTevOrderInfo j3dDefaultTevOrderInfoNull = {GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL};
const J3DIndTexOrderInfo j3dDefaultIndTexOrderNull = {GX_TEXCOORD_NULL, GX_TEXMAP_NULL};
const GXColorS10 j3dDefaultTevColor = {0xFF, 0xFF, 0xFF, 0xFF};
const J3DIndTexCoordScaleInfo j3dDefaultIndTexCoordScaleInfo = {};
const GXColor j3dDefaultTevKColor = {0xFF, 0xFF, 0xFF, 0xFF};
const J3DTevSwapModeInfo j3dDefaultTevSwapMode = {};
const J3DTevSwapModeTableInfo j3dDefaultTevSwapModeTable = {0, 1, 2, 3};
const J3DBlendInfo j3dDefaultBlendInfo = {GX_BM_BLEND, GX_BL_SRC_ALPHA, GX_BL_INV_SRC_ALPHA, GX_LO_NOOP};
const J3DColorChanInfo j3dDefaultColorChanInfo = {0, 0, 0, 2, 2, 0, 0xFF, 0xFF};
const u8 j3dDefaultTevSwapTableID = 0x1B;
const u16 j3dDefaultAlphaCmpID = 0xE7;
const u16 j3dDefaultZModeID = 0x17;
