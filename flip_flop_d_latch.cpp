#include "flip_flop_d_latch.h"
#include <bits/stdc++.h>

using namespace std;

bool flip_flop_d_latch::get_output(int n){
//input_1 = wejscie D input_2 = wejscie C
    if(this->output.time == n || this->input_2->get_output(n) == 0){
        this->output.time = n;        
        return this->output.value;
    }else if(this->input_2->get_output(n) == 1){
        this->output.time = n;
        bool value_output = this->input_1->get_output(n);
        this->output.value = value_output;
        return value_output;
    }
}

