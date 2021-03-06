#ifndef generator_H
#define generator_H

#include <bits/stdc++.h>
#include "electronic_device.h"

using namespace std;

class generator : public electronic_device{
    public:
        int period;
    public:
        bool get_output(int sec);
};
#endif
