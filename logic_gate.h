#ifndef logic_gate_H
#define logic_gate_H

#include <bits/stdc++.h>
#include "electronic_device.h"

using namespace std;

class logic_gate : public electronic_device{
   public:
        virtual bool get_output(int n) = 0;
};
#endif
