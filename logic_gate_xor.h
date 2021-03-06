#ifndef logic_gate_xor_H
#define logic_gate_xor_H

#include <bits/stdc++.h>
#include "logic_gate.h"

using namespace std;

class logic_gate_xor : public logic_gate{
    public:
        bool get_output(int n);
};
#endif
