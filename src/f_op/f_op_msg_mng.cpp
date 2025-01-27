//
// Generated by dtk
// Translation Unit: f_op_msg_mng.cpp
//

#include "f_op/f_op_msg_mng.h"
#include "f_op/f_op_scene_mng.h"
#include "f_pc/f_pc_manager.h"
#include "f_pc/f_pc_layer_iter.h"
#include "f_pc/f_pc_searcher.h"
#include "d/d_com_inf_game.h"
#include "JSystem/J2DGraph/J2DPicture.h"
#include "JSystem/J2DGraph/J2DScreen.h"
#include "dolphin/types.h"
#include "SSystem/SComponent/c_malloc.h"

class mesg_header;
class fopMsgM_pane_alpha_class;

class fopMsgM_f2d_class {
};

class MyPicture : public J2DPicture {
public:
    virtual ~MyPicture() {}
    virtual void drawSelf(f32, f32);
    virtual void drawSelf(f32, f32, Mtx*);
    void drawFullSet2(f32, f32, f32, f32, J2DBinding, J2DMirror, bool, Mtx*);
};

/* 8002ABB4-8002AC1C       .text drawSelf__9MyPictureFff */
void MyPicture::drawSelf(f32 x, f32 y) {
    /* Nonmatching */
    Mtx mtx;
    MTXIdentity(mtx);
    drawSelf(x, y, &mtx);
}

/* 8002AC1C-8002AC90       .text drawSelf__9MyPictureFffPA3_A4_f */
void MyPicture::drawSelf(f32, f32, Mtx*) {
    /* Nonmatching */
}

/* 8002AC90-8002AD4C       .text drawFullSet2__9MyPictureFffff10J2DBinding9J2DMirrorbPA3_A4_f */
void MyPicture::drawFullSet2(f32, f32, f32, f32, J2DBinding, J2DMirror, bool, Mtx*) {
    /* Nonmatching */
}

/* 8002AD4C-8002AE28       .text fopMsgM_hyrule_language_check__FUl */
void fopMsgM_hyrule_language_check(u32) {
    /* Nonmatching */
}

/* 8002AE28-8002AED4       .text fopMsgM_setStageLayer__FPv */
s32 fopMsgM_setStageLayer(void* proc) {
    scene_class* stageProc = fopScnM_SearchByID(g_dComIfG_gameInfo.play.getRoomControl()->mProcID);
    JUT_ASSERT(0x189, stageProc != 0);
    u32 layer = fpcM_LayerID(stageProc);
    fpcM_ChangeLayerID(proc, layer);
}

/* 8002AED4-8002AEF4       .text fopMsgM_SearchByID__FUi */
msg_class* fopMsgM_SearchByID(unsigned int pid) {
    return (msg_class*)fpcEx_SearchByID(pid);
}

/* 8002AEF4-8002AF24       .text fopMsgM_SearchByName__Fs */
msg_class* fopMsgM_SearchByName(s16 proc_name) {
    return (msg_class*)fpcLyIt_AllJudge(fpcSch_JudgeForPName, &proc_name);
}

/* 8002AF24-8002AF44       .text fopMsgM_IsExecuting__FUi */
bool fopMsgM_IsExecuting(u32) {
    /* Nonmatching */
}

/* 8002AF44-8002AF4C       .text fopMsgM_GetAppend__FPv */
fopMsg_prm_class* fopMsgM_GetAppend(void* i_this) {
    return (fopMsg_prm_class*) fpcM_GetAppend(i_this);
}

/* 8002AF4C-8002AF6C       .text fopMsgM_Delete__FPv */
void fopMsgM_Delete(void* i_this) {
    fpcM_Delete(i_this);
}

/* 8002AF6C-8002B030       .text createAppend__FP10fopAc_ac_cP4cXyzPUlPUlUi */
fopMsg_prm_class* createAppend(fopAc_ac_c* actor, cXyz* pos, u32* msg_id, u32* p4, unsigned int p5) {
    fopMsg_prm_class* params = (fopMsg_prm_class*) cMl::memalignB(-4, sizeof(fopMsg_prm_class));
    if (params == NULL)
        return NULL;

    params->mpActor = actor;
    if (msg_id != NULL)
        params->mMsgID = *msg_id;
    if (p4 != NULL)
        params->field_0x14 = *p4;

    if (pos != NULL) {
        params->mPos = *pos;
    } else {
        cXyz zero;
        zero.setall(0.0f);
        params->mPos = zero;
    }
    params->field_0x18 = p5;

    return params;
}

/* 8002B030-8002B0CC       .text createMGameTermAppend__FssiiUi */
void createMGameTermAppend(s16, s16, int, int, unsigned int) {
    /* Nonmatching */
}

/* 8002B0CC-8002B1C8       .text createTimerAppend__FiUsUcUcffffUi */
void createTimerAppend(int, u16, u8, u8, f32, f32, f32, f32, unsigned int) {
    /* Nonmatching */
}

/* 8002B1C8-8002B23C       .text fopMsgM_create__FsP10fopAc_ac_cP4cXyzPUlPUlPFPv_i */
s32 fopMsgM_create(s16, fopAc_ac_c*, cXyz*, u32*, u32*, int (*)(void*)) {
    /* Nonmatching */
}

/* 8002B23C-8002B2B0       .text fop_MGameTerm_create__FsssiiPFPv_i */
void fop_MGameTerm_create(s16, s16, s16, int, int, int (*)(void*)) {
    /* Nonmatching */
}

/* 8002B2B0-8002B324       .text fop_Timer_create__FsUcUsUcUcffffPFPv_i */
void fop_Timer_create(s16, u8, u16, u8, u8, f32, f32, f32, f32, int (*)(void*)) {
    /* Nonmatching */
}

/* 8002B324-8002B520       .text fopMsgM_messageTypeSelect__FP10fopAc_ac_cP4cXyzPUlPUl */
void fopMsgM_messageTypeSelect(fopAc_ac_c*, cXyz*, u32*, u32*) {
    /* Nonmatching */
}

/* 8002B568-8002B634       .text fopMsgM_searchMessageNumber__FUl */
u32 fopMsgM_searchMessageNumber(u32) {
    /* Nonmatching */
}

/* 8002B634-8002B778       .text fopMsgM_messageSet__FUlP10fopAc_ac_c */
int fopMsgM_messageSet(u32, fopAc_ac_c*) {
    /* Nonmatching */
}

/* 8002B778-8002B8A4       .text fopMsgM_messageSet__FUlP4cXyz */
int fopMsgM_messageSet(u32, cXyz*) {
    /* Nonmatching */
}

/* 8002B8A4-8002B9C4       .text fopMsgM_messageSet__FUl */
int fopMsgM_messageSet(u32) {
    /* Nonmatching */
}

/* 8002B9C4-8002BA4C       .text fopMsgM_scopeMessageSet__FUl */
void fopMsgM_scopeMessageSet(u32) {
    /* Nonmatching */
}

/* 8002BA4C-8002BB78       .text fopMsgM_tactMessageSet__Fv */
u32 fopMsgM_tactMessageSet() {
    /* Nonmatching */
}

/* 8002BB78-8002BDBC       .text fopMsgM_messageGet__FPcUl */
char* fopMsgM_messageGet(char*, u32) {
    /* Nonmatching */
}

/* 8002BE04-8002C02C       .text fopMsgM_passwordGet__FPcUl */
void fopMsgM_passwordGet(char*, u32) {
    /* Nonmatching */
}

/* 8002C02C-8002C568       .text fopMsgM_selectMessageGet__FP7J2DPaneP7J2DPanePcPcPcPcUl */
void fopMsgM_selectMessageGet(J2DPane*, J2DPane*, char*, char*, char*, char*, u32) {
    /* Nonmatching */
}

/* 8002C568-8002C574       .text fopMsgM_demoMsgFlagOn__Fv */
void fopMsgM_demoMsgFlagOn() {
    /* Nonmatching */
}

/* 8002C574-8002C580       .text fopMsgM_demoMsgFlagOff__Fv */
void fopMsgM_demoMsgFlagOff() {
    /* Nonmatching */
}

/* 8002C580-8002C588       .text fopMsgM_demoMsgFlagCheck__Fv */
void fopMsgM_demoMsgFlagCheck() {
    /* Nonmatching */
}

/* 8002C588-8002C594       .text fopMsgM_tactMsgFlagOn__Fv */
void fopMsgM_tactMsgFlagOn() {
    /* Nonmatching */
}

/* 8002C594-8002C5A0       .text fopMsgM_tactMsgFlagOff__Fv */
void fopMsgM_tactMsgFlagOff() {
    /* Nonmatching */
}

/* 8002C5A0-8002C5A8       .text fopMsgM_tactMsgFlagCheck__Fv */
void fopMsgM_tactMsgFlagCheck() {
    /* Nonmatching */
}

/* 8002C5A8-8002C5B4       .text fopMsgM_nextMsgFlagOff__Fv */
void fopMsgM_nextMsgFlagOff() {
    /* Nonmatching */
}

/* 8002C5B4-8002C5BC       .text fopMsgM_nextMsgFlagCheck__Fv */
void fopMsgM_nextMsgFlagCheck() {
    /* Nonmatching */
}

/* 8002C5BC-8002C624       .text fopMsgM_getScopeMode__Fv */
void fopMsgM_getScopeMode() {
    /* Nonmatching */
}

/* 8002C624-8002C650       .text fopMsgM_forceSendOn__Fv */
void fopMsgM_forceSendOn() {
    /* Nonmatching */
}

/* 8002C650-8002C65C       .text fopMsgM_forceSendOff__Fv */
void fopMsgM_forceSendOff() {
    /* Nonmatching */
}

/* 8002C65C-8002C664       .text fopMsgM_checkForceSend__Fv */
void fopMsgM_checkForceSend() {
    /* Nonmatching */
}

/* 8002C664-8002C670       .text fopMsgM_messageSendOn__Fv */
void fopMsgM_messageSendOn() {
    /* Nonmatching */
}

/* 8002C670-8002C67C       .text fopMsgM_messageSendOff__Fv */
void fopMsgM_messageSendOff() {
    /* Nonmatching */
}

/* 8002C67C-8002C684       .text fopMsgM_checkMessageSend__Fv */
void fopMsgM_checkMessageSend() {
    /* Nonmatching */
}

/* 8002C684-8002C6B0       .text fopMsgM_releaseScopeMode__Fv */
void fopMsgM_releaseScopeMode() {
    /* Nonmatching */
}

/* 8002C6B0-8002C6C4       .text fopMsgM_outFontTex__Fi */
void fopMsgM_outFontTex(int) {
    /* Nonmatching */
}

/* 8002C6C4-8002C6D8       .text fopMsgM_outFontColorWhite__Fi */
void fopMsgM_outFontColorWhite(int) {
    /* Nonmatching */
}

/* 8002C6D8-8002C9B0       .text fopMsgM_outFontSet__FP10J2DPictureP10J2DPicturePsUlUc */
void fopMsgM_outFontSet(J2DPicture*, J2DPicture*, s16*, u32, u8) {
    /* Nonmatching */
}

/* 8002C9B0-8002CBDC       .text fopMsgM_outFontSet__FP10J2DPicturePsUlUc */
void fopMsgM_outFontSet(J2DPicture*, s16*, u32, u8) {
    /* Nonmatching */
}

/* 8002CBDC-8002CEB0       .text fopMsgM_outFontStickAnimePiece__FP10J2DPictureP10J2DPicturess */
void fopMsgM_outFontStickAnimePiece(J2DPicture*, J2DPicture*, s16, s16) {
    /* Nonmatching */
}

/* 8002CEB0-8002D088       .text fopMsgM_outFontStickAnimePiece__FP10J2DPicturess */
void fopMsgM_outFontStickAnimePiece(J2DPicture*, s16, s16) {
    /* Nonmatching */
}

/* 8002D0E4-8002D2B8       .text fopMsgM_outFontStickAnime__FP10J2DPictureP10J2DPicturePiPiiPs */
void fopMsgM_outFontStickAnime(J2DPicture*, J2DPicture*, int*, int*, int, s16*) {
    /* Nonmatching */
}

/* 8002D2B8-8002D464       .text fopMsgM_outFontStickAnime__FP10J2DPicturePiPiPiPiPs */
void fopMsgM_outFontStickAnime(J2DPicture*, int*, int*, int*, int*, s16*) {
    /* Nonmatching */
}

/* 8002D464-8002D620       .text fopMsgM_outFontStickAnime2__FP10J2DPictureP10J2DPicturePiPiiPsUc */
void fopMsgM_outFontStickAnime2(J2DPicture*, J2DPicture*, int*, int*, int, s16*, u8) {
    /* Nonmatching */
}

/* 8002D620-8002D7D0       .text fopMsgM_outFontStickAnime2__FP10J2DPicturePiPiPiPiPsUc */
void fopMsgM_outFontStickAnime2(J2DPicture*, int*, int*, int*, int*, s16*, u8) {
    /* Nonmatching */
}

/* 8002D7D0-8002D95C       .text fopMsgM_outFontStickAnime__FP10J2DPictureP10J2DPicturePiPiiPsUc */
void fopMsgM_outFontStickAnime(J2DPicture*, J2DPicture*, int*, int*, int, s16*, u8) {
    /* Nonmatching */
}

/* 8002D95C-8002DAE4       .text fopMsgM_outFontStickAnime__FP10J2DPicturePiPiPiPiPsUc */
void fopMsgM_outFontStickAnime(J2DPicture*, int*, int*, int*, int*, s16*, u8) {
    /* Nonmatching */
}

/* 8002DAE4-8002DC74       .text fopMsgM_outFontArrow__FP10J2DPictureP10J2DPicturePiPiiUc */
void fopMsgM_outFontArrow(J2DPicture*, J2DPicture*, int*, int*, int, u8) {
    /* Nonmatching */
}

/* 8002DC74-8002DD98       .text fopMsgM_outFontArrow__FP10J2DPicturePiPiPiPiUc */
void fopMsgM_outFontArrow(J2DPicture*, int*, int*, int*, int*, u8) {
    /* Nonmatching */
}

/* 8002DD98-8002DFB4       .text fopMsgM_outFontDraw__FP10J2DPictureP10J2DPictureiiiPsUcUc */
void fopMsgM_outFontDraw(J2DPicture*, J2DPicture*, int, int, int, s16*, u8, u8) {
    /* Nonmatching */
}

/* 8002DFB4-8002E204       .text fopMsgM_outFontDraw2__FP10J2DPictureP10J2DPictureiiiiPsUcUc */
void fopMsgM_outFontDraw2(J2DPicture*, J2DPicture*, int, int, int, int, s16*, u8, u8) {
    /* Nonmatching */
}

/* 8002E204-8002E254       .text fopMsgM_Create__FsPFPv_iPv */
u32 fopMsgM_Create(s16, int (*)(void*), void*) {
    /* Nonmatching */
}

class fopMsgM_msgGet_c {
public:
    virtual ~fopMsgM_msgGet_c() {};
    mesg_header* getMesgHeader(u32);
    void* getMesgInfo(mesg_header*);
    void* getMesgData(mesg_header*);
    void* getMesgEntry(mesg_header*);
    void* getMessage(mesg_header*);
};

/* 8002E254-8002E2D8       .text getMesgHeader__16fopMsgM_msgGet_cFUl */
mesg_header* fopMsgM_msgGet_c::getMesgHeader(u32) {
    /* Nonmatching */
}

/* 8002E2D8-8002E2E0       .text getMesgInfo__16fopMsgM_msgGet_cFP11mesg_header */
void* fopMsgM_msgGet_c::getMesgInfo(mesg_header*) {
    /* Nonmatching */
}

/* 8002E2E0-8002E308       .text getMesgData__16fopMsgM_msgGet_cFP11mesg_header */
void* fopMsgM_msgGet_c::getMesgData(mesg_header*) {
    /* Nonmatching */
}

/* 8002E308-8002E378       .text getMesgEntry__16fopMsgM_msgGet_cFP11mesg_header */
void* fopMsgM_msgGet_c::getMesgEntry(mesg_header*) {
    /* Nonmatching */
}

/* 8002E378-8002E430       .text getMessage__16fopMsgM_msgGet_cFP11mesg_header */
void* fopMsgM_msgGet_c::getMessage(mesg_header*) {
    /* Nonmatching */
}

class fopMsgM_itemMsgGet_c {
public:
    virtual ~fopMsgM_itemMsgGet_c() {};
    mesg_header* getMesgHeader(u32);
    void* getMesgInfo(mesg_header*);
    void* getMesgData(mesg_header*);
    void* getMesgEntry(mesg_header*);
    void* getMessage(mesg_header*);
};

/* 8002E430-8002E4AC       .text getMesgHeader__20fopMsgM_itemMsgGet_cFUl */
mesg_header* fopMsgM_itemMsgGet_c::getMesgHeader(u32) {
    /* Nonmatching */
}

/* 8002E4AC-8002E4B4       .text getMesgInfo__20fopMsgM_itemMsgGet_cFP11mesg_header */
void* fopMsgM_itemMsgGet_c::getMesgInfo(mesg_header*) {
    /* Nonmatching */
}

/* 8002E4B4-8002E4DC       .text getMesgData__20fopMsgM_itemMsgGet_cFP11mesg_header */
void* fopMsgM_itemMsgGet_c::getMesgData(mesg_header*) {
    /* Nonmatching */
}

/* 8002E4DC-8002E54C       .text getMesgEntry__20fopMsgM_itemMsgGet_cFP11mesg_header */
void* fopMsgM_itemMsgGet_c::getMesgEntry(mesg_header*) {
    /* Nonmatching */
}

/* 8002E54C-8002E5FC       .text getMessage__20fopMsgM_itemMsgGet_cFP11mesg_header */
void* fopMsgM_itemMsgGet_c::getMessage(mesg_header*) {
    /* Nonmatching */
}

class fopMsgM_msgDataProc_c {
public:
    fopMsgM_msgDataProc_c() {}
    virtual ~fopMsgM_msgDataProc_c() {};
    void dataInit();
    void charLength(int, int, bool);
    void rubyLength(int, bool);
    void stringLength();
    void stringShift();
    void iconSelect(int, u8);
    void iconIdxRefresh();
    void selectCheck2(J2DPane*, int, int, int);
    void selectCheck3(J2DPane*, int, int, int);
    void selectCheckYoko(J2DPane*, int, int, int);
    void inputNumber(int);
    void selectArrow(J2DPicture*, f32, f32, f32, f32);
    void selectArrow(J2DPicture*, f32, f32);
    void colorAnime(J2DPicture*);
    void stringSet();
    void setSelectFlagYokoOn();
    void setSelectFlagOn();
    void setHandSendFlagOn();
    void setAutoSendFlagOn();
    void getHandSendFlag();
    void getAutoSendFlag();
    void getString(char*, u32);
    void getString(char*, char*, char*, char*, u32, f32*, f32*, int*);
    void getRubyString(char*, char*, char*, char*, char*, char*, f32*, f32*, int*);
    void tag_len_kaisen_game(int*, f32*, int*, int*, int*);
    void tag_len_rupee(int*, f32*, int*, int*, int*);
    void tag_len_num_input(int*, f32*, int*, int*, int*);
    void tag_len_sword_game(int*, f32*, int*, int*, int*);
    void tag_len_letter_game(int*, f32*, int*, int*, int*);
    void tag_len_letter_game_max(int*, f32*, int*, int*, int*);
    void tag_len_fish(int*, f32*, int*, int*, int*);
    void tag_len_fish_rupee(int*, f32*, int*, int*, int*);
    void tag_len_letter(int*, f32*, int*, int*, int*);
    void tag_len_rescue(int*, f32*, int*, int*, int*);
    void tag_len_forest_timer(int*, f32*, int*, int*, int*);
    void tag_len_birdman(int*, f32*, int*, int*, int*);
    void tag_len_point(int*, f32*, int*, int*, int*);
    void tag_len_get_pendant(int*, f32*, int*, int*, int*);
    void tag_len_rev_pendant(int*, f32*, int*, int*, int*);
    void tag_len_pig_timer(int*, f32*, int*, int*, int*);
    void tag_len_get_bomb(int*, f32*, int*, int*, int*);
    void tag_len_get_arrow(int*, f32*, int*, int*, int*);
    void tag_len_stock_bokobaba(int*, f32*, int*, int*, int*);
    void tag_len_stock_dokuro(int*, f32*, int*, int*, int*);
    void tag_len_stock_chuchu(int*, f32*, int*, int*, int*);
    void tag_len_stock_pendant(int*, f32*, int*, int*, int*);
    void tag_len_stock_hane(int*, f32*, int*, int*, int*);
    void tag_len_stock_kenshi(int*, f32*, int*, int*, int*);
    void tag_len_terry_rupee(int*, f32*, int*, int*, int*);
    void tag_len_input_bokobaba(int*, f32*, int*, int*, int*);
    void tag_len_input_dokuro(int*, f32*, int*, int*, int*);
    void tag_len_input_chuchu(int*, f32*, int*, int*, int*);
    void tag_len_input_pendant(int*, f32*, int*, int*, int*);
    void tag_len_input_hane(int*, f32*, int*, int*, int*);
    void tag_len_input_kenshi(int*, f32*, int*, int*, int*);
    void tag_kaisen_game();
    void tag_rupee();
    void tag_num_input();
    void tag_sword_game();
    void tag_letter_game();
    void tag_letter_game_max();
    void tag_fish();
    void tag_fish_rupee();
    void tag_letter();
    void tag_rescue();
    void tag_forest_timer();
    void tag_birdman();
    void tag_point();
    void tag_get_pendant();
    void tag_rev_pendant();
    void tag_pig_timer();
    void tag_get_bomb();
    void tag_get_arrow();
    void tag_stock_bokobaba();
    void tag_stock_dokuro();
    void tag_stock_chuchu();
    void tag_stock_pendant();
    void tag_stock_hane();
    void tag_stock_kenshi();
    void tag_terry_rupee();
    void tag_input_bokobaba();
    void tag_input_dokuro();
    void tag_input_chuchu();
    void tag_input_pendant();
    void tag_input_hane();
    void tag_input_kenshi();
};

/* 8002E7DC-8002E95C       .text dataInit__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::dataInit() {
    /* Nonmatching */
}

/* 8002E95C-8002EA58       .text charLength__21fopMsgM_msgDataProc_cFiib */
void fopMsgM_msgDataProc_c::charLength(int, int, bool) {
    /* Nonmatching */
}

/* 8002EA58-8002EB4C       .text rubyLength__21fopMsgM_msgDataProc_cFib */
void fopMsgM_msgDataProc_c::rubyLength(int, bool) {
    /* Nonmatching */
}

/* 8002EB4C-80031064       .text stringLength__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::stringLength() {
    /* Nonmatching */
}

/* 800310E4-800312B4       .text stringShift__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::stringShift() {
    /* Nonmatching */
}

/* 800312B4-80031420       .text iconSelect__21fopMsgM_msgDataProc_cFiUc */
void fopMsgM_msgDataProc_c::iconSelect(int, u8) {
    /* Nonmatching */
}

/* 80031420-8003144C       .text iconIdxRefresh__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::iconIdxRefresh() {
    /* Nonmatching */
}

/* 8003144C-80031808       .text fopMsgM_arrowAnime__FP10J2DPicturePs */
void fopMsgM_arrowAnime(J2DPicture*, s16*) {
    /* Nonmatching */
}

/* 80031808-800319D8       .text selectCheck2__21fopMsgM_msgDataProc_cFP7J2DPaneiii */
void fopMsgM_msgDataProc_c::selectCheck2(J2DPane*, int, int, int) {
    /* Nonmatching */
}

/* 800319D8-80031C38       .text selectCheck3__21fopMsgM_msgDataProc_cFP7J2DPaneiii */
void fopMsgM_msgDataProc_c::selectCheck3(J2DPane*, int, int, int) {
    /* Nonmatching */
}

/* 80031C38-80031E04       .text selectCheckYoko__21fopMsgM_msgDataProc_cFP7J2DPaneiii */
void fopMsgM_msgDataProc_c::selectCheckYoko(J2DPane*, int, int, int) {
    /* Nonmatching */
}

/* 80031E04-800320E0       .text inputNumber__21fopMsgM_msgDataProc_cFi */
void fopMsgM_msgDataProc_c::inputNumber(int) {
    /* Nonmatching */
}

/* 800320E0-800321CC       .text selectArrow__21fopMsgM_msgDataProc_cFP10J2DPictureffff */
void fopMsgM_msgDataProc_c::selectArrow(J2DPicture*, f32, f32, f32, f32) {
    /* Nonmatching */
}

/* 800321CC-80032288       .text selectArrow__21fopMsgM_msgDataProc_cFP10J2DPictureff */
void fopMsgM_msgDataProc_c::selectArrow(J2DPicture*, f32, f32) {
    /* Nonmatching */
}

/* 80032288-800322B4       .text colorAnime__21fopMsgM_msgDataProc_cFP10J2DPicture */
void fopMsgM_msgDataProc_c::colorAnime(J2DPicture*) {
    /* Nonmatching */
}

/* 800322B4-80034F3C       .text stringSet__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::stringSet() {
    /* Nonmatching */
}

/* 80034F5C-80034F68       .text setSelectFlagYokoOn__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::setSelectFlagYokoOn() {
    /* Nonmatching */
}

/* 80034F68-80034F74       .text setSelectFlagOn__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::setSelectFlagOn() {
    /* Nonmatching */
}

/* 80034F74-80034F80       .text setHandSendFlagOn__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::setHandSendFlagOn() {
    /* Nonmatching */
}

/* 80034F80-80034F8C       .text setAutoSendFlagOn__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::setAutoSendFlagOn() {
    /* Nonmatching */
}

/* 80034F8C-80034F94       .text getHandSendFlag__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::getHandSendFlag() {
    /* Nonmatching */
}

/* 80034F94-80034F9C       .text getAutoSendFlag__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::getAutoSendFlag() {
    /* Nonmatching */
}

/* 80034FE0-80034FF4       .text fopMsgM_itemNumIdx__FUc */
void fopMsgM_itemNumIdx(u8) {
    /* Nonmatching */
}

/* 80034FF4-80035060       .text fopMsgM_itemNum__FUc */
void fopMsgM_itemNum(u8) {
    /* Nonmatching */
}

/* 80035060-800350B8       .text fopMsgM_getColorTable__FUs */
void fopMsgM_getColorTable(u16) {
    /* Nonmatching */
}

/* 800350B8-80035170       .text fopMsgM_int_to_char__FPcib */
void fopMsgM_int_to_char(char*, int, bool) {
    /* Nonmatching */
}

/* 80035170-800351E8       .text fopMsgM_int_to_char2__FPci */
void fopMsgM_int_to_char2(char*, int) {
    /* Nonmatching */
}

/* 800351E8-80035408       .text getString__21fopMsgM_msgDataProc_cFPcUl */
void fopMsgM_msgDataProc_c::getString(char*, u32) {
    /* Nonmatching */
}

/* 80035408-80035A24       .text getString__21fopMsgM_msgDataProc_cFPcPcPcPcUlPfPfPi */
void fopMsgM_msgDataProc_c::getString(char*, char*, char*, char*, u32, f32*, f32*, int*) {
    /* Nonmatching */
}

/* 80035A24-80035D28       .text getRubyString__21fopMsgM_msgDataProc_cFPcPcPcPcPcPcPfPfPi */
void fopMsgM_msgDataProc_c::getRubyString(char*, char*, char*, char*, char*, char*, f32*, f32*, int*) {
    /* Nonmatching */
}

/* 80035D28-80035E40       .text tag_len_kaisen_game__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_kaisen_game(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80035E40-80035F68       .text tag_len_rupee__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_rupee(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80035F68-80036068       .text tag_len_num_input__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_num_input(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80036068-80036190       .text tag_len_sword_game__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_sword_game(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80036190-80036280       .text tag_len_letter_game__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_letter_game(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80036280-80036384       .text tag_len_letter_game_max__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_letter_game_max(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80036384-80036474       .text tag_len_fish__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_fish(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80036474-800365A0       .text tag_len_fish_rupee__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_fish_rupee(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 800365A0-800366C8       .text tag_len_letter__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_letter(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 800366C8-800367CC       .text tag_len_rescue__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_rescue(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 800367CC-8003693C       .text tag_len_forest_timer__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_forest_timer(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 8003693C-80036A64       .text tag_len_birdman__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_birdman(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80036A64-80036B9C       .text tag_len_point__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_point(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80036B9C-80036CC4       .text tag_len_get_pendant__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_get_pendant(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80036CC4-80036E18       .text tag_len_rev_pendant__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_rev_pendant(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80036E18-80036F74       .text tag_len_pig_timer__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_pig_timer(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80036F74-8003709C       .text tag_len_get_bomb__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_get_bomb(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 8003709C-800371C4       .text tag_len_get_arrow__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_get_arrow(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 800371C4-800372E4       .text tag_len_stock_bokobaba__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_stock_bokobaba(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 800372E4-80037404       .text tag_len_stock_dokuro__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_stock_dokuro(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80037404-80037500       .text tag_len_stock_chuchu__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_stock_chuchu(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80037500-80037620       .text tag_len_stock_pendant__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_stock_pendant(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80037620-80037740       .text tag_len_stock_hane__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_stock_hane(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80037740-80037860       .text tag_len_stock_kenshi__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_stock_kenshi(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80037860-80037980       .text tag_len_terry_rupee__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_terry_rupee(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80037980-80037A80       .text tag_len_input_bokobaba__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_input_bokobaba(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80037A80-80037B80       .text tag_len_input_dokuro__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_input_dokuro(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80037B80-80037C80       .text tag_len_input_chuchu__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_input_chuchu(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80037C80-80037D80       .text tag_len_input_pendant__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_input_pendant(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80037D80-80037E80       .text tag_len_input_hane__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_input_hane(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80037E80-80037F80       .text tag_len_input_kenshi__21fopMsgM_msgDataProc_cFPiPfPiPiPi */
void fopMsgM_msgDataProc_c::tag_len_input_kenshi(int*, f32*, int*, int*, int*) {
    /* Nonmatching */
}

/* 80037F80-80038178       .text tag_kaisen_game__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_kaisen_game() {
    /* Nonmatching */
}

/* 80038178-80038330       .text tag_rupee__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_rupee() {
    /* Nonmatching */
}

/* 80038330-80038538       .text tag_num_input__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_num_input() {
    /* Nonmatching */
}

/* 80038538-8003872C       .text tag_sword_game__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_sword_game() {
    /* Nonmatching */
}

/* 8003872C-800388AC       .text tag_letter_game__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_letter_game() {
    /* Nonmatching */
}

/* 800388AC-80038A40       .text tag_letter_game_max__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_letter_game_max() {
    /* Nonmatching */
}

/* 80038A40-80038BC0       .text tag_fish__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_fish() {
    /* Nonmatching */
}

/* 80038BC0-80038D7C       .text tag_fish_rupee__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_fish_rupee() {
    /* Nonmatching */
}

/* 80038D7C-80038F70       .text tag_letter__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_letter() {
    /* Nonmatching */
}

/* 80038F70-8003912C       .text tag_rescue__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_rescue() {
    /* Nonmatching */
}

/* 8003912C-800394B4       .text tag_forest_timer__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_forest_timer() {
    /* Nonmatching */
}

/* 800394B4-8003966C       .text tag_birdman__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_birdman() {
    /* Nonmatching */
}

/* 8003966C-80039834       .text tag_point__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_point() {
    /* Nonmatching */
}

/* 80039834-80039A28       .text tag_get_pendant__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_get_pendant() {
    /* Nonmatching */
}

/* 80039A28-80039C2C       .text tag_rev_pendant__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_rev_pendant() {
    /* Nonmatching */
}

/* 80039C2C-80039FA0       .text tag_pig_timer__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_pig_timer() {
    /* Nonmatching */
}

/* 80039FA0-8003A194       .text tag_get_bomb__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_get_bomb() {
    /* Nonmatching */
}

/* 8003A194-8003A388       .text tag_get_arrow__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_get_arrow() {
    /* Nonmatching */
}

/* 8003A388-8003A574       .text tag_stock_bokobaba__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_stock_bokobaba() {
    /* Nonmatching */
}

/* 8003A574-8003A760       .text tag_stock_dokuro__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_stock_dokuro() {
    /* Nonmatching */
}

/* 8003A760-8003A914       .text tag_stock_chuchu__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_stock_chuchu() {
    /* Nonmatching */
}

/* 8003A914-8003AB00       .text tag_stock_pendant__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_stock_pendant() {
    /* Nonmatching */
}

/* 8003AB00-8003ACEC       .text tag_stock_hane__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_stock_hane() {
    /* Nonmatching */
}

/* 8003ACEC-8003AED8       .text tag_stock_kenshi__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_stock_kenshi() {
    /* Nonmatching */
}

/* 8003AED8-8003B088       .text tag_terry_rupee__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_terry_rupee() {
    /* Nonmatching */
}

/* 8003B088-8003B21C       .text tag_input_bokobaba__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_input_bokobaba() {
    /* Nonmatching */
}

/* 8003B21C-8003B3B0       .text tag_input_dokuro__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_input_dokuro() {
    /* Nonmatching */
}

/* 8003B3B0-8003B544       .text tag_input_chuchu__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_input_chuchu() {
    /* Nonmatching */
}

/* 8003B544-8003B6D8       .text tag_input_pendant__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_input_pendant() {
    /* Nonmatching */
}

/* 8003B6D8-8003B86C       .text tag_input_hane__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_input_hane() {
    /* Nonmatching */
}

/* 8003B86C-8003BA00       .text tag_input_kenshi__21fopMsgM_msgDataProc_cFv */
void fopMsgM_msgDataProc_c::tag_input_kenshi() {
    /* Nonmatching */
}

/* 8003BA00-8003BA40       .text fopMsgM_centerPosCalc__F17fopMsgM_f2d_class17fopMsgM_f2d_class */
void fopMsgM_centerPosCalc(fopMsgM_f2d_class, fopMsgM_f2d_class) {
    /* Nonmatching */
}

/* 8003BA40-8003BB34       .text fopMsgM_pane_parts_set__FP18fopMsgM_pane_class */
void fopMsgM_pane_parts_set(fopMsgM_pane_class* pane) {
    /* Nonmatching */
}

/* 8003BB34-8003BB4C       .text fopMsgM_pane_parts_set__FP24fopMsgM_pane_alpha_class */
void fopMsgM_pane_parts_set(fopMsgM_pane_alpha_class* paneAlpha) {
    /* Nonmatching */
}

/* 8003BB4C-8003BB78       .text fopMsgM_setPaneData__FP18fopMsgM_pane_classP7J2DPane */
void fopMsgM_setPaneData(fopMsgM_pane_class* pane, J2DPane*) {
    /* Nonmatching */
}

/* 8003BB78-8003BBCC       .text fopMsgM_setPaneData__FP18fopMsgM_pane_classP9J2DScreenUl */
void fopMsgM_setPaneData(fopMsgM_pane_class* pane, J2DScreen*, u32) {
    /* Nonmatching */
}

/* 8003BBCC-8003BBF8       .text fopMsgM_setPaneData__FP24fopMsgM_pane_alpha_classP7J2DPane */
void fopMsgM_setPaneData(fopMsgM_pane_alpha_class* paneAlpha, J2DPane*) {
    /* Nonmatching */
}

/* 8003BBF8-8003BC88       .text fopMsgM_setPaneData__FP24fopMsgM_pane_alpha_classP9J2DScreenUl */
void fopMsgM_setPaneData(fopMsgM_pane_alpha_class* paneAlpha, J2DScreen*, u32) {
    /* Nonmatching */
}

/* 8003BC88-8003BCC0       .text fopMsgM_paneTrans__FP18fopMsgM_pane_classff */
void fopMsgM_paneTrans(fopMsgM_pane_class* pane, f32, f32) {
    /* Nonmatching */
}

/* 8003BCC0-8003BCEC       .text fopMsgM_paneScaleX__FP18fopMsgM_pane_classf */
void fopMsgM_paneScaleX(fopMsgM_pane_class* pane, f32 s) {
    pane->mSize.x = pane->mSizeOrig.x * s;
    fopMsgM_cposMove(pane);
}

/* 8003BCEC-8003BD18       .text fopMsgM_paneScaleY__FP18fopMsgM_pane_classf */
void fopMsgM_paneScaleY(fopMsgM_pane_class* pane, f32 s) {
    pane->mSize.y = pane->mSizeOrig.y * s;
    fopMsgM_cposMove(pane);
}

/* 8003BD18-8003BD50       .text fopMsgM_paneScale__FP18fopMsgM_pane_classff */
void fopMsgM_paneScale(fopMsgM_pane_class* pane, f32 sx, f32 sy) {
    pane->mSize.x = pane->mSizeOrig.x * sx;
    pane->mSize.y = pane->mSizeOrig.y * sy;
    fopMsgM_cposMove(pane);
}

/* 8003BD50-8003BD88       .text fopMsgM_paneScaleXY__FP18fopMsgM_pane_classf */
void fopMsgM_paneScaleXY(fopMsgM_pane_class* pane, f32 s) {
    pane->mSize.x = pane->mSizeOrig.x * s;
    pane->mSize.y = pane->mSizeOrig.y * s;
    fopMsgM_cposMove(pane);
}

/* 8003BD88-8003BE14       .text fopMsgM_cposMove__FP18fopMsgM_pane_class */
void fopMsgM_cposMove(fopMsgM_pane_class* pane) {
    pane->mPosTopLeft.x = pane->mPosCenter.x - pane->mSize.x / 2.0f;
    pane->mPosTopLeft.y = pane->mPosCenter.y - pane->mSize.y / 2.0f;
    pane->scrn->move(pane->mPosTopLeft.x, pane->mPosTopLeft.y);
    pane->scrn->resize(pane->mSize.x, pane->mSize.y);
}

/* 8003BE14-8003BE24       .text fopMsgM_setAlpha__FP18fopMsgM_pane_class */
void fopMsgM_setAlpha(fopMsgM_pane_class* pane) {
    pane->scrn->setAlpha(pane->mAlpha);
}

/* 8003BE24-8003BE30       .text fopMsgM_setInitAlpha__FP18fopMsgM_pane_class */
void fopMsgM_setInitAlpha(fopMsgM_pane_class* pane) {
    pane->mAlpha = pane->mAlphaOrig;
}

/* 8003BE30-8003BE6C       .text fopMsgM_setNowAlpha__FP18fopMsgM_pane_classf */
void fopMsgM_setNowAlpha(fopMsgM_pane_class* pane, f32 v) {
    pane->mAlpha = pane->mAlphaOrig * v;
}

/* 8003BE6C-8003BE78       .text fopMsgM_setNowAlphaZero__FP18fopMsgM_pane_class */
void fopMsgM_setNowAlphaZero(fopMsgM_pane_class* pane) {
    pane->mAlpha = 0;
}

/* 8003BE78-8003BE88       .text fopMsgM_setAlpha__FP24fopMsgM_pane_alpha_class */
void fopMsgM_setAlpha(fopMsgM_pane_alpha_class* paneAlpha) {
    /* Nonmatching */
}

/* 8003BE88-8003BEC4       .text fopMsgM_setNowAlpha__FP24fopMsgM_pane_alpha_classf */
void fopMsgM_setNowAlpha(fopMsgM_pane_alpha_class* paneAlpha, f32) {
    /* Nonmatching */
}

/* 8003BEC4-8003C07C       .text fopMsgM_valueIncrease__FiiUc */
f32 fopMsgM_valueIncrease(int, int, u8) {
    /* Nonmatching */
}

/* 8003C07C-8003C0F8       .text fopMsgM_blendInit__FP18fopMsgM_pane_classPCc */
void fopMsgM_blendInit(fopMsgM_pane_class* pane, const char* data) {
    ((J2DPicture*)pane->scrn)->insert(data, ((J2DPicture*)pane->scrn)->getNumTexture(), 1.0f);
    J2DPicture* pic = (J2DPicture*)pane->scrn;
    pic->setBlendColorRatio(0.0f, 1.0f, 1.0f, 1.0f);
    pic->setBlendAlphaRatio(0.0f, 1.0f, 1.0f, 1.0f);
}

/* 8003C0F8-8003C16C       .text fopMsgM_blendInit__FP10J2DPicturePCc */
void fopMsgM_blendInit(J2DPicture* pic, const char* data) {
    pic->insert(data, pic->getNumTexture(), 1.0f);
    pic->setBlendColorRatio(0.0f, 1.0f, 1.0f, 1.0f);
    pic->setBlendAlphaRatio(0.0f, 1.0f, 1.0f, 1.0f);
}

/* 8003C16C-8003C1D4       .text fopMsgM_blendDraw__FP18fopMsgM_pane_classPCc */
void fopMsgM_blendDraw(fopMsgM_pane_class* pane, const char* data) {
    J2DPicture* pic = (J2DPicture*)pane->scrn;
    pic->show();
    pic->remove(pic->getNumTexture() - 1);
    pic->insert(data, pic->getNumTexture(), 1.0f);
}

/* 8003C1D4-8003C234       .text fopMsgM_blendDraw__FP10J2DPicturePCc */
void fopMsgM_blendDraw(J2DPicture* pic, const char* data) {
    pic->show();
    pic->remove(pic->getNumTexture() - 1);
    pic->insert(data, pic->getNumTexture(), 1.0f);
}

/* 8003C234-8003C380       .text fopMsgM_setFontsizeCenter__FPcPcPcPcii */
void fopMsgM_setFontsizeCenter(char*, char*, char*, char*, int, int) {
    /* Nonmatching */
}

/* 8003C380-8003C414       .text fopMsgM_setFontsizeCenter2__FPcPcPcPciiii */
void fopMsgM_setFontsizeCenter2(char*, char*, char*, char*, int, int, int, int) {
    /* Nonmatching */
}

/* 8003C414-8003C450       .text fopMsgM_createExpHeap__FUl */
void fopMsgM_createExpHeap(u32) {
    /* Nonmatching */
}

/* 8003C450-8003C470       .text fopMsgM_destroyExpHeap__FP10JKRExpHeap */
void fopMsgM_destroyExpHeap(JKRExpHeap*) {
    /* Nonmatching */
}
