#include "engine.h"
#include <bits/stdc++.h>

#include "electronic_device.h"
#include "logic_gate.h"
#include "logic_gate_and.h"
#include "logic_gate_nand.h"
#include "logic_gate_not.h"
#include "logic_gate_or.h"
#include "logic_gate_xor.h"
#include "logic_gate_nor.h"
#include "logic_gate_xnor.h"
#include "generator.h"
#include "const_input.h"
#include "flip_flop_d_latch.h"
#include "flip_flop_jk.h"


using namespace std;

electronic_device* engine::make_element(int id, string type, int in_1, int in_2){
     if(type == "const_input"){
        const_input *e_d = new const_input();
        e_d->id = id;
        e_d->type = type;
        if(in_1 == 0){
            e_d->output.value = false;
        }else e_d->output.value = true;
        
        return e_d;
    }
}
electronic_device* engine::make_element_gate(int id, string type, int in_1, int in_2){
        if(type == "flip_flop_jk"){
            flip_flop_jk *e_d = new flip_flop_jk();
            e_d->id = id;
            e_d->type = type;
            e_d->output.value = 0;
            e_d->output.time = -1;            
            return e_d;
        }else if(type == "flip_flop_d_latch"){
            flip_flop_d_latch *e_d = new flip_flop_d_latch();
            e_d->id = id;
            e_d->type = type;
            e_d->output.value = 0;
            e_d->output.time = -1;
            return e_d;
        }else if(type == "generator"){
            generator *e_d = new generator();
            e_d->id = id;
            e_d->type = type;
            e_d->period = in_2;
            e_d->output.value = 0;
            e_d->output.time = -1;

            return e_d;
        }else if(type == "logic_gate_and"){
            logic_gate_and *e_d = new logic_gate_and();
            e_d->id = id;
            e_d->type = type;
            e_d->output.value = 0;
            e_d->output.time = -1;
            
            return e_d;
        }else if(type == "logic_gate_nand"){
            logic_gate_nand *e_d = new logic_gate_nand();
            e_d->id = id;
            e_d->type = type;
            e_d->output.value = 0;
            e_d->output.time = -1;

            return e_d;
        }else if(type == "logic_gate_or"){
            logic_gate_or *e_d = new logic_gate_or();
            e_d->id = id;
            e_d->type = type;
            e_d->output.value = 0;
            e_d->output.time = -1;

            return e_d;
        }else if(type == "logic_gate_nor"){
            logic_gate_nor *e_d = new logic_gate_nor();
            e_d->id = id;
            e_d->type = type;
            e_d->output.value = 0;
            e_d->output.time = -1;

            return e_d;
        }else if(type == "logic_gate_xnor"){
            logic_gate_xnor *e_d = new logic_gate_xnor();
            e_d->id = id;
            e_d->type = type;
            e_d->output.value = 0;
            e_d->output.time = -1;

            return e_d;
        }else if(type == "logic_gate_xor"){
            logic_gate_xor *e_d = new logic_gate_xor();
            e_d->id = id;
            e_d->type = type;
            e_d->output.value = 0;
            e_d->output.time = -1;

            return e_d;
        }else if(type == "logic_gate_not"){
            logic_gate_not *e_d = new logic_gate_not();
            e_d->id = id;
            e_d->type = type;
            e_d->output.value = 0;
            e_d->output.time = -1;

            return e_d;
        }
}

bool engine::count_signal(int n, electronic_device *element){
    bool value =0;
    value = element->get_output(n);
    return value;
}
void engine::generate_document(int n, electronic_device *element){
    bool value;
    string name;
    name = element->type;
    name += "wynik.txt";
    ofstream data_file(name);
 //   data_file.open("wynik.txt");

    for(int i=0; i<=n-1; i++){
        value = count_signal(i, element);
        data_file << "time: " << i << " value: " << value << endl;
    }
    data_file.close();

}
void engine::run(){
    int id, in_1, in_2;
    string type;
    vector <int> candidat_first;
    vector <electronic_device *> element_list;

    fstream data_file;
    data_file.open("dane.txt");

    while(!data_file.eof()){
        data_file >> id >> type >> in_1 >> in_2;
        if(type[0] == 'l' || type[0] == 'g' ||  type[0] == 'f'){

            element_list.push_back(make_element_gate(id, type, in_1, in_2));

            for(int i=0; i<=element_list.size()-1; i++){
                if(element_list[i]->id == in_1){
                    element_list[element_list.size()-1]->input_1 = element_list[i];
                }
                if(element_list[i]->id == in_2 && type != "logic_gate_not" && type != "generator"){
                    element_list[element_list.size()-1]->input_2 = element_list[i];
                }
            }
        }else{
                element_list.push_back(make_element(id, type, in_1, in_2));
        }      
    }element_list.pop_back();
    data_file.close();
/*for(int i=0; i<=element_list.size()-1; i++){
cout << element_list[i]->type;
}
*/

    int n, k;
    while(k != -1){
        cout << "Podaj id obiektu dla ktorego generujemy raport lub zakoncz wpisując -1";
        cin >> k;
        if(k == -1){
            break;
        }else{
            cout << "Podaj czas";
            cin >> n;
        }
        for(int i=0; i<=element_list.size()-1; i++){
            if(element_list[i]->id == k){
                generate_document(n,element_list[i]);
            }
        }
    }
}
