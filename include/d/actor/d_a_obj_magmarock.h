#ifndef D_A_OBJ_MAGMAROCK_H
#define D_A_OBJ_MAGMAROCK_H

#include "f_op/f_op_actor.h"

namespace daObjMagmarock {
    class Act_c : public fopAc_ac_c {
    public:
        void MeltDownRequest() {}
        inline s32 _create();
        inline BOOL _delete();
        inline BOOL _draw();
        inline BOOL _execute();
        void checkProcess(void (daObjMagmarock::Act_c::*)()) {}
        void setProcess(void (daObjMagmarock::Act_c::*)()) {}
    
        void set_mtx();
        void demo_move();
        void ControlEffect();
        void play_anim();
        void appear_proc_init();
        void appear_proc();
        void wait_proc_init();
        void wait_proc();
        void stay_proc_init();
        void stay_proc();
        void quake_proc_init();
        void quake_proc();
        void vanish_proc_init();
        void vanish_proc();
        void CreateHeap();
        void CreateInit();
        void LiftUpRequest(cXyz&);
        void BeforeLiftRequest(cXyz&);
        void calc_ground_quat();
    
    public:
        /* Place member variables here */
    };
};

#endif /* D_A_OBJ_MAGMAROCK_H */
