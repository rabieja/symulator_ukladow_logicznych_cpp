#ifndef logic_gate_nor_H
#define logic_gate_nor_H

#include <bits/stdc++.h>
#include "logic_gate.h"

using namespace std;

class logic_gate_nor : public logic_gate{
    public:
        bool get_output(int n);
};
#endif
