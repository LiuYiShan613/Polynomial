#include<iostream>
using namespace std;

void display(int highestPow, float coff[]);

//Εγ₯άf(x)
void display(int highestPow, float coff[]){

    cout << "f (x) = ";
    for(int i=0; i<=highestPow+1; i++){

            if(i==0) continue;

            if(coff[i] == 0 && highestPow == 0){
                cout << 0 ;
            }
            else{

                if(coff[i] != 0 ){
                    cout << coff[i];
                }
                if(coff[i] == 0){
                    continue;
                }

                for(int j=1 ; j<i; j++){
                    cout << "*x";
                }
                if(i!=highestPow+1){
                    cout << " + ";
                }
            }


    }
    cout << endl;

}
