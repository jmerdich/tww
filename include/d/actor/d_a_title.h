#ifndef D_A_TITLE_H
#define D_A_TITLE_H

#include "f_op/f_op_actor.h"

class daTitle_proc_c {
public:
    static void daTitle_Kirakira_Sound_flag_on();
};

class daTitle_c : public fopAc_ac_c {
public:
    inline s32 create();
    inline BOOL draw();
    inline BOOL execute();

public:
    /* Place member variables here */
};

#endif /* D_A_TITLE_H */
