#ifndef logic_gate_xnor_H
#define logic_gate_xnor_H

#include <bits/stdc++.h>
#include "logic_gate.h"

using namespace std;

class logic_gate_xnor : public logic_gate{
    public:
        bool get_output(int n);
};
#endif
