
#include "TAfin.h"



TAfin::TAfin(){
    _matrizAfin = new float*[N_AFIN];
    
    for(int i = 0; i < N_AFIN; i++){
        _matrizAfin[i] = new float[N_AFIN];
    }
}