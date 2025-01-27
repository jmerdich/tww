/**
 * d_a_player_food.inc
 *
 * Code relating to the All-Purpose Bait and Hyoi Pear items.
 * 
 * This file is not a standalone translation unit and is instead directly 
 * included into d_a_player_main.cpp.
 * 
 * The original name of this file is not known, but a best guess was taken 
 * based on the original names of the functions it contains.
 */

#include "d/actor/d_a_player_main.h"
#include "f_op/f_op_camera.h"

/* 80154334-801543A0       .text setHyoiModel__9daPy_lk_cFv */
void daPy_lk_c::setHyoiModel() {
    if (mHeldItemType == ANIMAL_ESA) {
        return;
    }
    JKRHeap* oldHeap = setItemHeap();
    initModel(&mpHeldItemModel, LINK_BDL_HYOINOMI, 0x13000022);
    mDoExt_setCurrentHeap(oldHeap);
    mHeldItemType = ANIMAL_ESA;
}

/* 801543A0-801546F4       .text procFoodThrow_init__9daPy_lk_cFv */
BOOL daPy_lk_c::procFoodThrow_init() {
    if (mCurProcID == PROC_FOOD_THROW_e) {
        return TRUE;
    }
    if (m3630 != -1) {
        mDoAud_seStart(JA_SE_ITEM_TARGET_OUT, NULL, 0, 0);
        return FALSE;
    }
    
    dBgS* bgs = dComIfG_Bgsp(); // This is kinda weird, maybe fakematch
    
    if (!dComIfGp_event_runCheck()) {
        if (!dComIfGp_event_compulsory(this, NULL, -1)) {
            return FALSE;
        } else {
            mDemo.setSpecialDemoType();
        }
    } else {
        deleteEquipItem(0);
    }
    
    int temp = checkShipRideUseItem(1);
    
    commonProcInit(PROC_FOOD_THROW_e);
    
    if (temp == 0) {
        f32 offset1 = cM_ssin(shape_angle.y) * 150.0f;
        f32 offset2 = cM_scos(shape_angle.y) * 150.0f;
        cXyz start;
        start.set(
            mAttentionInfo.mPosition.x,
            mAttentionInfo.mPosition.y - 50.0f,
            mAttentionInfo.mPosition.z
        );
        cXyz end;
        end.set(
            start.x + offset1,
            start.y,
            start.z + offset2
        );
        mLinkLinChk.Set(&start, &end, this);
        if (bgs->LineCross(&mLinkLinChk)) {
            end.x = start.x - offset1;
            end.z = start.z - offset2;
            mLinkLinChk.Set(&start, &end, this);
            if (!dComIfG_Bgsp()->LineCross(&mLinkLinChk)) {
                shape_angle.y += 0x8000;
            } else {
                end.x = start.x + offset2;
                end.z = start.z - offset1;
                mLinkLinChk.Set(&start, &end, this);
                if (!dComIfG_Bgsp()->LineCross(&mLinkLinChk)) {
                    shape_angle.y += 0x4000;
                } else {
                    end.x = start.x - offset2;
                    end.z = start.z + offset1;
                    mLinkLinChk.Set(&start, &end, this);
                    if (!dComIfG_Bgsp()->LineCross(&mLinkLinChk)) {
                        shape_angle.y -= 0x4000;
                    }
                }
            }
        }
    }
    current.angle.y = shape_angle.y;
    mVelocity = 0.0f;
    
    daPy_matAnm_c::m_maba_flg = 0;
    daPy_matAnm_c::m_maba_timer = 1;
    setSingleMoveAnime(ANM_UNK_C4, daPy_HIO_food_c0::m.field_0x4, daPy_HIO_food_c0::m.field_0x8, daPy_HIO_food_c0::m.field_0x0, daPy_HIO_food_c0::m.field_0xC);
    keepItemData();
    
    if (mDemo.getDemoType() == 5) {
        m3570 = 6;
        dCam_getBody()->StartEventCamera(0x12, fopAcM_GetID(this), "Type", &m3570, 0);
    }
    
    initShipRideUseItem(temp, 2);
    m3630 = -1;
    
    return TRUE;
}

/* 801546F4-80154880       .text procFoodThrow__9daPy_lk_cFv */
BOOL daPy_lk_c::procFoodThrow() {
    /* Nonmatching */
}

/* 80154880-80154A48       .text procFoodSet_init__9daPy_lk_cFv */
BOOL daPy_lk_c::procFoodSet_init() {
    /* Nonmatching */
}

/* 80154A48-80154B80       .text procFoodSet__9daPy_lk_cFv */
BOOL daPy_lk_c::procFoodSet() {
    /* Nonmatching */
}
