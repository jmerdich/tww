#ifndef D_A_ARROW_ICEEFF_H
#define D_A_ARROW_ICEEFF_H

#include "f_op/f_op_actor.h"

class daArrow_Iceeff_c : public fopAc_ac_c {
public:
    inline s32 _create();
    inline BOOL _delete();
    inline BOOL _draw();
    inline BOOL _execute();

    void CreateHeap();
    void CreateInit();
    void set_mtx();

public:
    /* Place member variables here */
};

#endif /* D_A_ARROW_ICEEFF_H */
