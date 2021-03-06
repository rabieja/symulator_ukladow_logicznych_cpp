#ifndef electronic_device_H
#define electronic_device_H

#include <bits/stdc++.h>

using namespace std;


struct devices_output{
    int time;
    bool value;
};
class electronic_device{
    public:
        int id;
        string type;
        devices_output output;
        electronic_device *input_1;
        electronic_device *input_2;
    public:
        virtual bool get_output(int n) = 0;
};
#endif
