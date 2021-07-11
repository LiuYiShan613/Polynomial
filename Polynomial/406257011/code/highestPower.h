#include<iostream>

int highestPower(float coff[]);

//取得最高次項
int highestPower(float coff[]){

    int pow = 0;
    for(int i=0; i< sizeof(coff)-1; i++){
        if(i==0){
            pow = coff[i];
        }
    }

    return pow;
}

