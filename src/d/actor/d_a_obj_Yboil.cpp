//
// Generated by dtk
// Translation Unit: d_a_obj_Yboil.cpp
//

#include "d/actor/d_a_obj_Yboil.h"
#include "d/d_a_obj.h"
#include "d/d_com_inf_game.h"
#include "d/d_kankyo.h"
#include "m_Do/m_Do_mtx.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTAssert.h"

/* 00000078-00000098       .text CheckCreateHeap__FP10fopAc_ac_c */
static s32 CheckCreateHeap(fopAc_ac_c* i_this) {
    return ((daObjYboil_c*)i_this)->CreateHeap();
}

/* 00000098-00000368       .text CreateHeap__12daObjYboil_cFv */
BOOL daObjYboil_c::CreateHeap() {
    /* Nonmatching */
    J3DModelData* modelData;
    J3DAnmTransform* bck;
    J3DAnmTextureSRTKey* btk;
    J3DAnmTevRegKey* brk;

    modelData = (J3DModelData*)dComIfG_getObjectRes("Yboil", 0x06);
    JUT_ASSERT(92, modelData != 0);
    bck = (J3DAnmTransform*)dComIfG_getObjectRes("Yboil", 0x09);
    JUT_ASSERT(96, bck != 0);
    btk = (J3DAnmTextureSRTKey*)dComIfG_getObjectRes("Yboil", 0x0F);
    JUT_ASSERT(100, btk != 0);
    brk = (J3DAnmTevRegKey*)dComIfG_getObjectRes("Yboil", 0x0C);
    JUT_ASSERT(104, brk != 0);

    for (s32 i = 0; i < 50; i++) {
        mModel[i] = mDoExt_J3DModel__create(modelData, 0x80000, 0x11000222);
        if (mModel[i] == NULL)
            return FALSE;

        if (!mBckAnm[i].init(modelData, bck, TRUE, J3DFrameCtrl::LOOP_ONCE_e, 1.0f, 0, -1, false))
            return FALSE;
        if (!mBtkAnm[i].init(modelData, btk, TRUE, J3DFrameCtrl::LOOP_ONCE_e, 1.0f, 0, -1, false, 0))
            return FALSE;
        if (!mBrkAnm[i].init(modelData, brk, TRUE, J3DFrameCtrl::LOOP_ONCE_e, 1.0f, 0, -1, false, 0))
            return FALSE;
    }

    return TRUE;
}

/* 00000368-00000470       .text pos_reset__12daObjYboil_cFi */
void daObjYboil_c::pos_reset(int i) {
    /* Nonmatching */
    mMdlScale[i].setall(mScaleMin + cM_rndF(mScaleMax - mScaleMin));
    f32 dist = 1300.0f + cM_rndF(1400.0f);
    f32 angle = cM_rndF(65536.0f);
    mMdlPos[i].x = current.pos.x + dist * cM_ssin(angle);
    mMdlPos[i].y = current.pos.y;
    mMdlPos[i].z = current.pos.z + dist * cM_scos(angle);
}

/* 00000470-000005CC       .text CreateInit__12daObjYboil_cFv */
void daObjYboil_c::CreateInit() {
    /* Nonmatching */
    mScaleMin = 0.5f;
    mScaleMax = 1.0f;

    for (s32 i = 0; i < 50; i++) {
        pos_reset(i);
        fopAcM_SetMtx(this, mModel[i]->getBaseTRMtx());
        fopAcM_setCullSizeBox(this, -3000.0f, -0.0f, -3000.0f, 3000.0f, 200.0f, 3000.0f);
        fopAcM_setCullSizeFar(this, 1.0f);
        f32 frame = cM_rndF(29.9999f);
        mBckAnm[i].setFrame((s32)frame);
        mBtkAnm[i].setFrame((s32)frame);
        mBrkAnm[i].setFrame((s32)frame);
        mMdlTimer[i] = 0;
    }
    set_mtx();
}

/* 000005CC-0000066C       .text set_mtx__12daObjYboil_cFv */
void daObjYboil_c::set_mtx() {
    for (s32 i = 0; i < 50; i++) {
        mModel[i]->setBaseScale(mMdlScale[i]);
        mDoMtx_stack_c::transS(mMdlPos[i]);
        mModel[i]->setBaseTRMtx(mDoMtx_stack_c::get());
    }
}

s32 daObjYboil_c::_create() {
    fopAcM_SetupActor(this, daObjYboil_c);

    s32 ret;
    if (dComIfGs_isEventBit(0x1902)) {
        ret = cPhs_UNK3_e;
    } else {
        ret = dComIfG_resLoad(&mPhs, "Yboil");
        if (ret == cPhs_COMPLEATE_e) {
            if (!fopAcM_entrySolidHeap(this, (heapCallbackFunc)CheckCreateHeap, 0x14500)) {
                ret = cPhs_ERROR_e;
            } else {
                CreateInit();
            }
        }
    }
    return ret;
}

bool daObjYboil_c::_delete() {
    if (fpcM_CreateResult(this) != cPhs_UNK3_e) {
        dComIfG_resDelete(&mPhs, "Yboil");
    }
    return true;
}

u32 daObjYboil_c::prm_get_swSave() const {
    return daObj::PrmAbstract<Prm_e>(this, PRM_SWSAVE_W, PRM_SWSAVE_S);
}

bool daObjYboil_c::_execute() {
    /* Nonmatching */
    for (s32 i = 0; i < 50; i++) {
        if (mMdlTimer[i] == 0) {
            mBckAnm[i].play();
            mBtkAnm[i].play();
            mBrkAnm[i].play();

            if (mBckAnm[i].isStop()) {
                mBckAnm[i].setFrame(0.0f);
                mBckAnm[i].setPlaySpeed(1.0f);
                mBtkAnm[i].setFrame(0.0f);
                mBtkAnm[i].setPlaySpeed(1.0f);
                mBrkAnm[i].setFrame(0.0f);
                mBrkAnm[i].setPlaySpeed(1.0f);
                mMdlTimer[i] = 1 + (s32)cM_rndF(3.999f);
            }
        } else {
            if (!fopAcM_isSwitch(this, prm_get_swSave())) {
                mMdlTimer[i]--;
                if (mMdlTimer[i] == 0)
                    pos_reset(i);
            }
        }
    }
    set_mtx();
    return true;
}

/* 0000066C-000007D8       .text daObjYboil_Create__FPv */
s32 daObjYboil_Create(void* i_this) {
    return ((daObjYboil_c*)i_this)->_create();
}

/* 000009F0-00000A2C       .text daObjYboil_Delete__FPv */
BOOL daObjYboil_Delete(void* i_this) {
    return ((daObjYboil_c*)i_this)->_delete();
}

/* 00000A2C-00000A50       .text daObjYboil_Draw__FPv */
BOOL daObjYboil_Draw(void* i_this) {
    return ((daObjYboil_c*)i_this)->_draw();
}

void daObjYboil_c::set_sea_material(J3DMaterial* material) {
    for (; material != NULL; material = material->getNext()) {
        GXColor amb, dif;
        dKy_get_seacolor(&amb, &dif);
        material->getTevColor(0)->mColor.r = amb.r;
        material->getTevColor(0)->mColor.g = amb.g;
        material->getTevColor(0)->mColor.b = amb.b;

        material->getTevKColor(0)->mColor.r = dif.r;
        material->getTevKColor(0)->mColor.g = dif.g;
        material->getTevKColor(0)->mColor.b = dif.b;
    }
}

/* 00000A50-00000C6C       .text _draw__12daObjYboil_cFv */
bool daObjYboil_c::_draw() {
    dComIfGd_setListBG();
    g_env_light.settingTevStruct(TEV_TYPE_BG0, &current.pos, &mTevStr);
    for (s32 i = 0; i < 50; i++) {
        g_env_light.setLightTevColorType(mModel[i], &mTevStr);
        set_sea_material(mModel[i]->getModelData()->getJointNodePointer(0)->getMesh());
        mBckAnm[i].entry(mModel[i]->getModelData());
        mBtkAnm[i].entry(mModel[i]->getModelData());
        mBrkAnm[i].entry(mModel[i]->getModelData());
        mDoExt_modelUpdateDL(mModel[i]);
    }
    dComIfGd_setList();
    return true;
}

/* 00000C6C-00000DF4       .text daObjYboil_Execute__FPv */
BOOL daObjYboil_Execute(void* i_this) {
    return ((daObjYboil_c*)i_this)->_execute();
}

/* 00000DF4-00000DFC       .text daObjYboil_IsDelete__FPv */
BOOL daObjYboil_IsDelete(void* i_this) {
    return TRUE;
}
