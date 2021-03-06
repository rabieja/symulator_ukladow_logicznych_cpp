#include "flip_flop_jk.h"
#include <bits/stdc++.h>

using namespace std;

bool flip_flop_jk::get_output(int n){
//input_1 = wejscie j input_2 = wejscie k
    bool j, k;
    if(this->output.time == n){   
        return this->output.value;
    }else{
        j = this->input_1->get_output(n);
        k = this->input_2->get_output(n);
        if(j == 1 && k == 1){ 
            this->output.value = not this->output.value;
            this->output.time = n;
            return this->output.value;
        }else if(j == 1 && k == 0){
            this->output.value = 1;
            this->output.time = n;
            return this->output.value;
        }else if(j == 0 && k == 1){
            this->output.value = 0;
            this->output.time = n;
            return this->output.value;
        }else{
            this->output.time = n;
            return this->output.value;
        }
    }
}

