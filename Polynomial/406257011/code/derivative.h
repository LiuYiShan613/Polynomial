#include<iostream>
using namespace std;

void derivative(int highestPow, float coff[], float dev_coff[]);

//Εγ₯άf'(x)
void derivative(int highestPow, float coff[], float dev_coff[]){

    cout << "f'(x) = ";
    if(highestPow==0){
            cout << 0;
    }
    else{

        for(int i=0; i<=highestPow+1; i++){
            if(i<2) continue;
            dev_coff[i-2] = coff[i]*(i-1);
        }

        for(int i=0; i<highestPow; i++){

                if(dev_coff[i] != 0){
                    cout << dev_coff[i];
                }
                if(coff[i] == 0){
                    continue;
                }
                for(int j=0 ; j<i; j++){
                    cout << "*x";
                }
                if(i!=highestPow-1 && dev_coff[i] != 0){
                    cout << " + ";
                }

        }
    }
    cout << endl;
}
