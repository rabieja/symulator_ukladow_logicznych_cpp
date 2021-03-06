#ifndef logic_gate_nand_H
#define logic_gate_nand_H

#include <bits/stdc++.h>
#include "logic_gate.h"

using namespace std;

class logic_gate_nand : public logic_gate{
    public:
        bool get_output(int n);
};
#endif
