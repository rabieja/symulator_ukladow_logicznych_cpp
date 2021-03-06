#ifndef flip_flop_d_latch_H
#define flip_flop_d_latch_H

#include <bits/stdc++.h>
#include "electronic_device.h"


using namespace std;

class flip_flop_d_latch : public electronic_device{
    public:
        bool get_output(int n);
};
#endif
