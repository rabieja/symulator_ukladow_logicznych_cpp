#ifndef engine_H
#define engine_H

#include <bits/stdc++.h>
#include "electronic_device.h"
#include "logic_gate.h"
#include "const_input.h"

using namespace std;

class engine{
    public:
        void run();
        electronic_device * make_element(int id, string type, int in_1, int in_2);
        electronic_device * make_element_gate(int id, string type, int in_1, int in_2);
        void generate_document(int n, electronic_device *element);
        bool count_signal(int n, electronic_device *element);
};
#endif
