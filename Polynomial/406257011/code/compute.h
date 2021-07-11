#include<iostream>
#include <math.h>
using namespace std;


void compute(int highestPow, float coff[], float x);

//��X f(x) �M f'(x) ��
void compute(int highestPow, float coff[], float x){


    float powvalue = 0;//f(x) value

    float derivative = 0;//f'(x) value

    for(int i=0; i<=highestPow+1; i++){

            float tpowvalue = 0;

            if(i==0) continue;

            tpowvalue = coff[i]*pow(x, i-1);

            powvalue += tpowvalue;

    }

    for(int i=0; i<=highestPow +1; i++){

            float dpowvalue = 0;

            if(i<2) continue;

            dpowvalue = coff[i]*(i-1)*pow(x, i-2);

            derivative += dpowvalue;

    }


    cout <<"f (" << x << ") = ";
    printf("%.4f", powvalue) ;
    cout<< endl;

    cout <<"f'(" << x << ") = ";
    printf("%.4f", derivative) ;
    cout<< endl;

}
