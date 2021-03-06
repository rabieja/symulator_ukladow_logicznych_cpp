#include "generator.h"
#include <bits/stdc++.h>

using namespace std;

bool generator::get_output(int n){
    if(this->output.time == n){
        return this->output.value;
    }else{
        bool value_output;
        if((n/this->period)%2 != 0){
            value_output = this->input_1->get_output(n);
        }else value_output =  not this->input_1->get_output(n);
        this->output.value = value_output;
        this->output.time = n;        
        return value_output;
    }
}