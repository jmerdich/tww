#ifndef D_A_NPC_BTSW_H
#define D_A_NPC_BTSW_H

#include "f_op/f_op_actor.h"

class daNpc_Btsw_c : public fopAc_ac_c {
public:
    void getAttentionBasePos() {}
    void setAction(int (daNpc_Btsw_c::*)(void*), void*) {}

    void initTexPatternAnm(bool);
    void playTexPatternAnm();
    void setAnm(signed char);
    void chkAttention(cXyz, short);
    void eventOrder();
    void checkOrder();
    void next_msgStatus(unsigned long*);
    void getMsg();
    void anmAtr(unsigned short);
    void CreateInit();
    void set_mtx();
    void setAttention();
    void lookBack();
    void wait01();
    void talk01();
    void wait_action(void*);
    void dummy_event_action(void*);
    void checkNextMailThrowOK();
    void TimerCountDown();
    void shiwake_game_action(void*);
    void getdemo_action(void*);
    BOOL _draw();
    BOOL _execute();
    BOOL _delete();
    s32 _create();
    void CreateHeap();

public:
    /* Place member variables here */
};

#endif /* D_A_NPC_BTSW_H */
