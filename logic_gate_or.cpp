#include "logic_gate_or.h"
#include <bits/stdc++.h>

using namespace std;



bool logic_gate_or::get_output(int n){
    if(this->output.time == n){
        return this->output.value;
    }else{
        bool value_output;
        value_output = this->input_1->get_output(n) or this->input_2->get_output(n);
        this->output.value = value_output;
        this->output.time = n;        
        return value_output;
    }
}
