//
// Generated by dtk
// Translation Unit: J3DAnimation.cpp
//

#include "JSystem/J3DGraphAnimator/J3DAnimation.h"
#include "dolphin/types.h"

/* 802EF5D8-802EF608       .text init__12J3DFrameCtrlFs */
void J3DFrameCtrl::init(s16 end) {
    mAttribute = 2;
    mState = 0;
    mStart = 0;
    mEnd = end;
    mLoop = 0;
    mRate = 1.0f;
    mFrame = 0.0f;
}

/* 802EF608-802EFBA8       .text checkPass__12J3DFrameCtrlFf */
BOOL J3DFrameCtrl::checkPass(f32 pass_frame) {
    f32 cur_frame = mFrame;
    f32 next_frame = cur_frame + mRate;

    switch (mAttribute) {
    case LOOP_ONCE_e:
    case LOOP_ONCE_RESET_e:
        if (next_frame < mStart) {
            next_frame = mStart;
        }

        if (next_frame >= mEnd) {
            next_frame = mEnd - 0.001f;
        }

        if (cur_frame <= next_frame) {
            if (cur_frame <= pass_frame && pass_frame < next_frame) {
                return true;
            } else {
                return false;
            }
        }

        if (next_frame <= pass_frame && pass_frame < cur_frame) {
            return true;
        }
        return false;
    case LOOP_REPEAT_e:
        if (cur_frame < mStart) {
            while (next_frame < mStart) {
                if (mLoop - mStart <= 0.0f) {
                    break;
                }
                next_frame += mLoop - mStart;
            }

            if (next_frame <= pass_frame && pass_frame < mLoop) {
                return true;
            } else {
                return false;
            }
        } else if (mEnd <= cur_frame) {
            while (next_frame >= mEnd) {            
                if (mEnd - mLoop <= 0.0f) {
                    break;
                }
                next_frame -= mEnd - mLoop;
            }

            if (mLoop <= pass_frame && pass_frame < next_frame) {
                return true;
            } else {
                return false;
            }
        } else if (next_frame < mStart) {
            while (next_frame < mStart) {            
                if (mLoop - mStart <= 0.0f) {
                    break;
                }
                next_frame += mLoop - mStart;
            }

            if ((mStart <= pass_frame && pass_frame < cur_frame) || (next_frame <= pass_frame && pass_frame < mLoop)) {
                return true;
            } else {
                return false;
            }
        } else if (mEnd <= next_frame) {
            while (next_frame >= mEnd) {            
                if (mEnd - mLoop <= 0.0f) {
                    break;
                }

                next_frame -= mEnd - mLoop;
            }

            if ((cur_frame <= pass_frame && pass_frame < mEnd) || (mLoop <= pass_frame && pass_frame < next_frame)) {
                return true;
            } else {
                return false;
            }
        } else if (cur_frame <= next_frame) {
            if (cur_frame <= pass_frame && pass_frame < next_frame) {
                return true;
            } else {
                return false;
            }
        } else if (next_frame <= pass_frame && pass_frame < cur_frame) {
            return true;
        }
        return false;
    case LOOP_MIRROR_ONCE_e:
    case LOOP_MIRROR_REPEAT_e:
        if (next_frame >= mEnd) {
            next_frame = mEnd - 0.001f;
        }

        if (next_frame < mStart) {
            next_frame = mStart;
        }

        if (cur_frame <= next_frame) {
            if (cur_frame <= pass_frame && pass_frame < next_frame) {
                return true;
            } else {
                return false;
            }
        }

        if (next_frame <= pass_frame && pass_frame < cur_frame) {
            return true;
        }
        return false;
    default:
        return false;
    }
}

/* 802EFBA8-802EFFE4       .text update__12J3DFrameCtrlFv */
void J3DFrameCtrl::update() {
    mState = 0;
    mFrame += mRate;
    switch (mAttribute) {
    case LOOP_ONCE_e:
        if (mFrame < mStart) {
            mFrame = mStart;
            mRate = 0.0f;
            mState |= 1;
        }
        if (mFrame >= mEnd) {
            mFrame = mEnd - 0.001f;
            mRate = 0.0f;
            mState |= 1;
        }
        break;
    case LOOP_ONCE_RESET_e:
        if (mFrame < mStart) {
            mFrame = mStart;
            mRate = 0.0f;
            mState |= 1;
        }
        if (mFrame >= mEnd) {
            mFrame = mStart;
            mRate = 0.0f;
            mState |= 1;
        }
        break;
    case LOOP_REPEAT_e:
        while (mFrame < mStart) {
            mState |= 2;
            if (mLoop - mStart <= 0.0f) {
                break;
            }
            mFrame += mLoop - mStart;
        }
        while (mFrame >= mEnd) {
            mState |= 2;
            if (mEnd - mLoop <= 0.0f) {
                break;
            }
            mFrame -= mEnd - mLoop;
        }
        break;
    case LOOP_MIRROR_ONCE_e:
        if (mFrame >= mEnd) {
            mFrame = mEnd - 0.001f;
            mRate = -mRate;
        }
        if (mFrame < mStart) {
            mFrame = mStart;
            mRate = 0.0f;
            mState |= 1;
        }
        break;
    case LOOP_MIRROR_REPEAT_e:
        if (mFrame >= mEnd) {
            mFrame = mEnd - 0.001f;
            mRate = -mRate;
        }
        if (mFrame < mStart) {
            mFrame = mStart;
            mRate = -mRate;
            mState |= 2;
        }
        break;
    }
}

/* 802EFFE4-802F06D8       .text getTransform__19J3DAnmTransformFullCFUsP16J3DTransformInfo */
void J3DAnmTransformFull::getTransform(u16, J3DTransformInfo*) const {
    /* Nonmatching */
}

/* 802F06D8-802F072C       .text J3DHermiteInterpolationS__FfPsPsPsPsPsPs */
f32 J3DHermiteInterpolationS(f32 t, s16* time0, s16* value0, s16* tangent0, s16* time1, s16* value1, s16* tangent1) {
    /* Nonmatching */
}

/* 802F072C-802F0954       .text J3DGetKeyFrameInterpolationS__FfP18J3DAnmKeyTableBasePs */
void J3DGetKeyFrameInterpolationS(f32, J3DAnmKeyTableBase*, s16*) {
    /* Nonmatching */
}

/* 802F0954-802F0E20       .text calcTransform__18J3DAnmTransformKeyCFfUsP16J3DTransformInfo */
void J3DAnmTransformKey::calcTransform(f32, u16, J3DTransformInfo*) const {
    /* Nonmatching */
}

/* 802F0E20-802F10D4       .text calcTransform__19J3DAnmTextureSRTKeyCFfUsP17J3DTextureSRTInfo */
void J3DAnmTextureSRTKey::calcTransform(f32, u16, J3DTextureSRTInfo*) const {
    /* Nonmatching */
}

/* 802F10D4-802F1188       .text getWeight__17J3DAnmClusterFullCFUs */
f32 J3DAnmClusterFull::getWeight(u16 idx) const {
    u16 maxFrame = getAnmTable()[idx].mMaxFrame;
    if (0.0f <= getFrame() && getFrame() < maxFrame)
        return mWeight[(s32)getFrame() + getAnmTable()[idx].mOffset];
    if (getFrame() < 0.0f)
        return mWeight[getAnmTable()[idx].mOffset];
    else
        return mWeight[maxFrame - 1 + getAnmTable()[idx].mOffset];
}

/* 802F1188-802F120C       .text getWeight__16J3DAnmClusterKeyCFUs */
f32 J3DAnmClusterKey::getWeight(u16) const {
    /* Nonmatching */
}

/* 802F120C-802F14B4       .text getColor__18J3DAnmVtxColorFullCFUcUsP8_GXColor */
void J3DAnmVtxColorFull::getColor(u8, u16, GXColor* dst) const {
    /* Nonmatching */
}

/* 802F14B4-802F17D0       .text getColor__17J3DAnmVtxColorKeyCFUcUsP8_GXColor */
void J3DAnmVtxColorKey::getColor(u8, u16, GXColor* dst) const {
    /* Nonmatching */
}

/* 802F17D0-802F1868       .text searchUpdateMaterialID__11J3DAnmColorFP16J3DMaterialTable */
void J3DAnmColor::searchUpdateMaterialID(J3DMaterialTable* table) {
    for (u16 i = 0; i < getUpdateMaterialNum(); i++) {
        s32 materialID = table->getMaterialName()->getIndex(getUpdateMaterialName()->getName(i));
        if (materialID != -1)
            mUpdateMaterialID[i] = materialID;
        else
            mUpdateMaterialID[i] = 0xFFFF;
    }
}

/* 802F1868-802F188C       .text searchUpdateMaterialID__11J3DAnmColorFP12J3DModelData */
void J3DAnmColor::searchUpdateMaterialID(J3DModelData* modelData) {
    searchUpdateMaterialID(&modelData->getMaterialTable());
}

/* 802F188C-802F1BDC       .text getColor__15J3DAnmColorFullCFUsP8_GXColor */
void J3DAnmColorFull::getColor(u16 idx, GXColor* dst) const {
    {
        u16 maxFrame = getAnmTable()[idx].mRMaxFrame;
        if (getFrame() < 0.0f)
            dst->r = mColorR[getAnmTable()[idx].mROffset];
        if (getFrame() >= maxFrame)
            dst->r = mColorR[maxFrame - 1 + getAnmTable()[idx].mROffset];
        if (0.0f <= getFrame() && getFrame() < maxFrame)
            dst->r = mColorR[(s32)getFrame() + getAnmTable()[idx].mROffset];
    }
    {
        u16 maxFrame = getAnmTable()[idx].mGMaxFrame;
        if (getFrame() < 0.0f)
            dst->g = mColorG[getAnmTable()[idx].mGOffset];
        if (getFrame() >= maxFrame)
            dst->g = mColorG[maxFrame - 1 + getAnmTable()[idx].mGOffset];
        if (0.0f <= getFrame() && getFrame() < maxFrame)
            dst->g = mColorG[(s32)getFrame() + getAnmTable()[idx].mGOffset];
    }
    {
        u16 maxFrame = getAnmTable()[idx].mBMaxFrame;
        if (getFrame() < 0.0f)
            dst->b = mColorB[getAnmTable()[idx].mBOffset];
        if (getFrame() >= maxFrame)
            dst->b = mColorB[maxFrame - 1 + getAnmTable()[idx].mBOffset];
        if (0.0f <= getFrame() && getFrame() < maxFrame)
            dst->b = mColorB[(s32)getFrame() + getAnmTable()[idx].mBOffset];
    }
    {
        u16 maxFrame = getAnmTable()[idx].mAMaxFrame;
        if (getFrame() < 0.0f)
            dst->a = mColorA[getAnmTable()[idx].mAOffset];
        if (getFrame() >= maxFrame)
            dst->a = mColorA[maxFrame - 1 + getAnmTable()[idx].mAOffset];
        if (0.0f <= getFrame() && getFrame() < maxFrame)
            dst->a = mColorA[(s32)getFrame() + getAnmTable()[idx].mAOffset];
    }
}

/* 802F1BDC-802F1F20       .text getColor__14J3DAnmColorKeyCFUsP8_GXColor */
void J3DAnmColorKey::getColor(u16 idx, GXColor* dst) const {
    /* Nonmatching */
}

/* 802F1F20-802F200C       .text getTexNo__16J3DAnmTexPatternCFUsPUs */
void J3DAnmTexPattern::getTexNo(u16 idx, u16* dst) const {
    u16 maxFrame = getAnmTable()[idx].mMaxFrame;
    if (0.0f <= getFrame() && getFrame() < maxFrame)
        *dst = mTextureIndex[(s32)getFrame() + getAnmTable()[idx].mOffset];
    if (getFrame() < 0.0f)
        *dst = mTextureIndex[getAnmTable()[idx].mOffset];
    if (getFrame() >= maxFrame)
        *dst = mTextureIndex[maxFrame - 1 + getAnmTable()[idx].mOffset];
}

/* 802F200C-802F20EC       .text getVisibility__20J3DAnmVisibilityFullCFUsPUc */
void J3DAnmVisibilityFull::getVisibility(u16 idx, u8* dst) const {
    u16 maxFrame = getAnmTable()[idx].mMaxFrame;
    if (0.0f <= getFrame() && getFrame() < maxFrame)
        *dst = mVisibility[(s32)getFrame() + getAnmTable()[idx].mOffset];
    if (getFrame() < 0.0f)
        *dst = mVisibility[getAnmTable()[idx].mOffset];
    if (getFrame() >= maxFrame)
        *dst = mVisibility[maxFrame - 1 + getAnmTable()[idx].mOffset];
}

/* 802F20EC-802F2184       .text searchUpdateMaterialID__16J3DAnmTexPatternFP16J3DMaterialTable */
void J3DAnmTexPattern::searchUpdateMaterialID(J3DMaterialTable* table) {
    for (u16 i = 0; i < getUpdateMaterialNum(); i++) {
        s32 materialID = table->getMaterialName()->getIndex(getUpdateMaterialName()->getName(i));
        if (materialID != -1)
            mUpdateMaterialID[i] = materialID;
        else
            mUpdateMaterialID[i] = 0xFFFF;
    }
}

/* 802F2184-802F21A8       .text searchUpdateMaterialID__16J3DAnmTexPatternFP12J3DModelData */
void J3DAnmTexPattern::searchUpdateMaterialID(J3DModelData* modelData) {
    searchUpdateMaterialID(&modelData->getMaterialTable());
}

/* 802F21A8-802F22BC       .text searchUpdateMaterialID__19J3DAnmTextureSRTKeyFP16J3DMaterialTable */
void J3DAnmTextureSRTKey::searchUpdateMaterialID(J3DMaterialTable* table) {
    for (u16 i = 0; i < getUpdateMaterialNum(); i++) {
        s32 materialID = table->getMaterialName()->getIndex(getUpdateMaterialName()->getName(i));
        if (materialID != -1)
            mUpdateMaterialID[i] = materialID;
        else
            mUpdateMaterialID[i] = 0xFFFF;
    }
    for (u16 i = 0; i < getPostUpdateMaterialNum(); i++) {
        s32 materialID = table->getMaterialName()->getIndex(getPostUpdateMaterialName()->getName(i));
        if (materialID != -1)
            mPostUpdateMaterialID[i] = materialID;
        else
            mPostUpdateMaterialID[i] = 0xFFFF;
    }
}

/* 802F22BC-802F22E0       .text searchUpdateMaterialID__19J3DAnmTextureSRTKeyFP12J3DModelData */
void J3DAnmTextureSRTKey::searchUpdateMaterialID(J3DModelData* modelData) {
    searchUpdateMaterialID(&modelData->getMaterialTable());
}

/* 802F22E0-802F2624       .text getTevColorReg__15J3DAnmTevRegKeyCFUsP11_GXColorS10 */
void J3DAnmTevRegKey::getTevColorReg(u16 idx, GXColorS10* dst) const {
    /* Nonmatching */
}

/* 802F2624-802F2968       .text getTevKonstReg__15J3DAnmTevRegKeyCFUsP8_GXColor */
void J3DAnmTevRegKey::getTevKonstReg(u16 idx, GXColor* dst) const {
    /* Nonmatching */
}

/* 802F2968-802F2A64       .text searchUpdateMaterialID__15J3DAnmTevRegKeyFP16J3DMaterialTable */
void J3DAnmTevRegKey::searchUpdateMaterialID(J3DMaterialTable* table) {
    for (u16 i = 0; i < getCRegUpdateMaterialNum(); i++) {
        s32 materialID = table->getMaterialName()->getIndex(getCRegUpdateMaterialName()->getName(i));
        if (materialID != -1)
            mCRegUpdateMaterialID[i] = materialID;
        else
            mCRegUpdateMaterialID[i] = 0xFFFF;
    }
    for (u16 i = 0; i < getKRegUpdateMaterialNum(); i++) {
        s32 materialID = table->getMaterialName()->getIndex(getKRegUpdateMaterialName()->getName(i));
        if (materialID != -1)
            mKRegUpdateMaterialID[i] = materialID;
        else
            mKRegUpdateMaterialID[i] = 0xFFFF;
    }
}

/* 802F2A64-802F2A88       .text searchUpdateMaterialID__15J3DAnmTevRegKeyFP12J3DModelData */
void J3DAnmTevRegKey::searchUpdateMaterialID(J3DModelData* modelData) {
    searchUpdateMaterialID(&modelData->getMaterialTable());
}
