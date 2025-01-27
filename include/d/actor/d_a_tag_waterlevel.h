#ifndef D_A_TAG_WATERLEVEL_H
#define D_A_TAG_WATERLEVEL_H

#include "f_op/f_op_actor.h"

namespace daTagWaterlevel {
    class Act_c : public fopAc_ac_c {
    public:
        void get_now() {}
        void get_state() {}
        void prm_get_sch() const {}
    
        s32 _create();
        BOOL _delete();
        void bgm_proc();
        BOOL _execute();
        BOOL _draw();
    
    public:
        /* Place member variables here */
    };
};

#endif /* D_A_TAG_WATERLEVEL_H */
