//
// Generated by dtk
// Translation Unit: osdsp_task.c
//

#include "JSystem/JAudio/osdsp_task.h"
#include "JSystem/JAudio/dspproc.h"
#include "dolphin/dsp.h"
#include "dolphin/os/OSContext.h"

u32 sync_stack[3];
vu8 DSP_prior_yield;
s32 AUDIO_UPDATE_REQUEST;
DSPTaskInfo* DSP_prior_task;

/* 8028ECA0-8028EFA4       .text __DSPHandler */
void __DSPHandler(int interrupt, OSContext* context) {
    /* Nonmatching */
    OSContext funcContext;
    __DSPRegs[5] = ((u16)(__DSPRegs[5]) & ~0x28) | 0x80;
    OSClearContext(&funcContext);
    OSSetCurrentContext(&funcContext);

    if (DSP_prior_yield == 1 || DSP_prior_yield == 0) {
        __DSP_curr_task = DSP_prior_task;
    }

    while (DSPCheckMailFromDSP() == 0);
    u32 mail = DSPReadMailFromDSP();

    if ((__DSP_curr_task->flags & 2) && mail == 0xDCD10002) {
        mail = 0xDCD10003;
    }

    switch (mail) {
    case 0xDCD10000:
        __DSP_curr_task->state = 1;
        if (__DSP_curr_task == DSP_prior_task) {
            DSP_prior_yield = 1;
        }
        if (__DSP_curr_task->init_cb != NULL) {
            __DSP_curr_task->init_cb(__DSP_curr_task);
        }
        break;
    case 0xDCD10001:
        __DSP_curr_task->state = 1;
        if (__DSP_curr_task == DSP_prior_task) {
            DSP_prior_yield = 1;
            Dsp_Update_Request();
        }
        if (__DSP_curr_task->res_cb != NULL) {
            __DSP_curr_task->res_cb(__DSP_curr_task);
        }
        break;
    case 0xDCD10002:
        DSPSendMailToDSP(0xCDD10001);
        while (DSPCheckMailToDSP() != 0);
        __DSP_curr_task->state = 2;
        if (__DSP_curr_task->next == NULL && AUDIO_UPDATE_REQUEST) {
            __DSP_exec_task(__DSP_curr_task, DSP_prior_task);
            AUDIO_UPDATE_REQUEST = 0;
            __DSP_curr_task = DSP_prior_task;
        } else {
            __DSP_exec_task(__DSP_curr_task, __DSP_curr_task->next);
            __DSP_curr_task = __DSP_curr_task->next;
        }
        break;
    case 0xDCD10003:
        if (__DSP_curr_task->done_cb != NULL) {
            __DSP_curr_task->done_cb(__DSP_curr_task);
        }
        DSPSendMailToDSP(0xCDD10001);
        while (DSPCheckMailToDSP() != 0);
        __DSP_curr_task->state = 3;
        if (__DSP_curr_task->next == NULL) {
            __DSP_exec_task(NULL, DSP_prior_task);
            __DSP_remove_task(__DSP_curr_task);
            __DSP_curr_task = DSP_prior_task;
        } else {
            __DSP_exec_task(NULL, __DSP_curr_task->next);
            __DSP_curr_task = __DSP_curr_task->next;
            __DSP_remove_task(__DSP_curr_task->prev);
        }
        break;
    case 0xDCD10004:
        if (__DSP_curr_task->req_cb != NULL) {
            __DSP_curr_task->req_cb(__DSP_curr_task);
        }
        break;
    case 0xDCD10005:
        if (__DSP_first_task == NULL || AUDIO_UPDATE_REQUEST) {
            DSPSendMailToDSP(0xCDD10003);
            while (DSPCheckMailToDSP() != 0);
            AUDIO_UPDATE_REQUEST = 0;
            __DSP_curr_task = DSP_prior_task;
            Dsp_Update_Request();
        } else {
            DSP_prior_yield = 3;
            DSPSendMailToDSP(0xCDD10001);
            while (DSPCheckMailToDSP() != 0);
            __DSP_exec_task(DSP_prior_task, __DSP_first_task);
            __DSP_curr_task = __DSP_first_task;
        }
        break;
    }

    OSClearContext(&funcContext);
    OSSetCurrentContext(context);
}

/* 8028EFC0-8028F010       .text DsyncFrame2__FUlUlUl */
void DsyncFrame2(u32 param_1, u32 param_2, u32 param_3) {
    if (DSP_prior_yield != 1) {
        sync_stack[0] = param_1;
        sync_stack[1] = param_2;
        sync_stack[2] = param_3;
        AUDIO_UPDATE_REQUEST = 1;
        return;
    }
    DsyncFrame(param_1, param_2, param_3);
    AUDIO_UPDATE_REQUEST = 0;
}

/* 8028F020-8028F060       .text Dsp_Update_Request__Fv */
void Dsp_Update_Request() {
    if (AUDIO_UPDATE_REQUEST) {
        DsyncFrame2(sync_stack[0], sync_stack[1], sync_stack[2]);
    }
}

/* 8028F060-8028F074       .text Dsp_Running_Check__Fv */
bool Dsp_Running_Check() {
    /* Nonmatching */
    return DSP_prior_yield == 1;
}

/* 8028F080-8028F08C       .text Dsp_Running_Start__Fv */
void Dsp_Running_Start() {
    DSP_prior_yield = 1;
}
