//
// Generated by dtk
// Translation Unit: d_a_hot_floor.cpp
//

#include "f_op/f_op_actor_mng.h"
#include "JSystem/JParticle/JPAParticle.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "d/d_bg_w.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"

class daHot_Floor_c : public fopAc_ac_c {
public:
    void set_mtx_init();
    void set_mtx();
    s32 CreateInit();
    inline s32 _create();
    inline bool _execute();
    inline bool _draw();
    inline bool _delete();
    inline bool create_heap();

    static const char M_arcname[];

public:
    /* 0x290 */ request_of_phase_process_class mPhs;
    /* 0x298 */ u32 field_0x298;
    /* 0x298 */ u32 field_0x29c;
    /* 0x2A0 */ mDoExt_brkAnm mBrkAnm;
    /* 0x2B8 */ f32 mSpawnTimer;
    /* 0x2BC */ u32 field_0x2bc;
    /* 0x2C0 */ mDoExt_btkAnm mBtkAnm;
    /* 0x2D4 */ JPABaseEmitter * mEmitter1;
    /* 0x2D8 */ JPABaseEmitter * mEmitter2;
    /* 0x2DC */ bool mbSpawnParticle;
    /* 0x2E0 */ Mtx mtx[5];
    /* 0x3D0 */ Mtx * mtx_p;
    /* 0x3D4 */ u32 field_0x3d4;
};

const char daHot_Floor_c::M_arcname[8] = "Ylesr00";

/* 00000078-00000108       .text set_mtx_init__13daHot_Floor_cFv */
void daHot_Floor_c::set_mtx_init() {
    mDoMtx_stack_c::transS(getPosition());
    mDoMtx_stack_c::ZXYrotM(shape_angle);
    for (s32 i = 0; i < 5; i++)
        mDoMtx_copy(mDoMtx_stack_c::get(), mtx[i]);
}

/* 00000108-00000218       .text set_mtx__13daHot_Floor_cFv */
void daHot_Floor_c::set_mtx() {
    for (s32 i = 4; i > 0; i--)
        mDoMtx_copy(mtx[i - 1], mtx[i]);
    if (mtx_p != NULL) {
        cXyz pos = cXyz::Zero;
        mDoMtx_stack_c::copy(*mtx_p);
        mDoMtx_stack_c::transM(0.0f, 5.0f, -5.0f);
        mDoMtx_copy(mDoMtx_stack_c::get(), mtx[0]);
        mDoMtx_stack_c::multVec(&pos, &current.pos);
        if (mEmitter2 != NULL)
            JPASetRMtxTVecfromMtx(mtx[0], mEmitter2->mGlobalRotation, mEmitter2->mGlobalTranslation);
        if (mEmitter1 != NULL)
            JPASetRMtxTVecfromMtx(mtx[0], mEmitter1->mGlobalRotation, mEmitter1->mGlobalTranslation);
    }
    mtx_p = NULL;
}

/* 00000218-00000264       .text CreateInit__13daHot_Floor_cFv */
s32 daHot_Floor_c::CreateInit() {
    mbSpawnParticle = true;
    mSpawnTimer = 0.0f;
    set_mtx_init();
    fopAcM_SetMtx(this, mtx[0]);
    return cPhs_COMPLEATE_e;
}

s32 daHot_Floor_c::_create() {
    fopAcM_SetupActor(this, daHot_Floor_c);
    return CreateInit();
}

bool daHot_Floor_c::_delete() {
    if (mEmitter2 != NULL)
        mEmitter2->becomeInvalidEmitter();
    if (mEmitter1 != NULL)
        mEmitter1->becomeInvalidEmitter();
    return TRUE;
}

bool daHot_Floor_c::_execute() {
    if (mbSpawnParticle) {
        if (mEmitter2 == NULL && !(fopAcM_GetParam(this) & 1))
            mEmitter2 = dComIfGp_particle_set(0x814c, &current.pos);
        if (mEmitter1 == NULL && !(fopAcM_GetParam(this) & 2))
            mEmitter1 = dComIfGp_particle_set(0x8120, &current.pos);
        cLib_chaseF(&mSpawnTimer, 60.0f, 5.0f);
        mbSpawnParticle = false;
    } else {
        cLib_chaseF(&mSpawnTimer, 0.0f, 0.4f);
        if (mSpawnTimer < 20.0f) {
            if (mEmitter2 != NULL) {
                mEmitter2->becomeInvalidEmitter();
                mEmitter2 = NULL;
            }
            if (mEmitter1 != NULL) {
                mEmitter1->becomeInvalidEmitter();
                mEmitter1 = NULL;
            }
        }
        if (mSpawnTimer <= 0.4f)
            fopAcM_delete(this);
    }

    set_mtx();
    return FALSE;
}

bool daHot_Floor_c::_draw() {
    return TRUE;
}

/* 00000264-000002F8       .text daHot_FloorCreate__FPv */
s32 daHot_FloorCreate(void* i_this) {
    return ((daHot_Floor_c*)i_this)->_create();
}

/* 000003F8-00000440       .text daHot_FloorDelete__FPv */
BOOL daHot_FloorDelete(void* i_this) {
    return ((daHot_Floor_c*)i_this)->_delete();
}

/* 00000440-00000604       .text daHot_FloorExecute__FPv */
BOOL daHot_FloorExecute(void* i_this) {
    return ((daHot_Floor_c*)i_this)->_execute();
}

/* 00000604-0000060C       .text daHot_FloorDraw__FPv */
BOOL daHot_FloorDraw(void* i_this) {
    return ((daHot_Floor_c*)i_this)->_draw();
}

/* 0000060C-00000614       .text daHot_FloorIsDelete__FPv */
BOOL daHot_FloorIsDelete(void* i_this) {
    return TRUE;
}

static actor_method_class l_daHot_Floor_Method = {
    (process_method_func)daHot_FloorCreate,
    (process_method_func)daHot_FloorDelete,
    (process_method_func)daHot_FloorExecute,
    (process_method_func)daHot_FloorIsDelete,
    (process_method_func)daHot_FloorDraw,
};

actor_process_profile_definition g_profile_Hot_Floor = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 7,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Hot_Floor,
    /* Proc SubMtd  */ &g_fpcLf_Method.mBase,
    /* Size         */ sizeof(daHot_Floor_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x00DB,
    /* Actor SubMtd */ &l_daHot_Floor_Method,
    /* Status       */ fopAcStts_UNK40000_e | fopAcStts_CULL_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_0_e,
};
