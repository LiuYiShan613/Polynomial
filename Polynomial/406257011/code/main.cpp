#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <math.h>

#include "highestPower.h"
#include "display.h"
#include "derivative.h"
#include "compute.h"

using namespace std;

//切割string字串
void splitStr2Vec(string s, vector<string>& buf)
{
	int current = 0; //最初由 0 的位置開始找
	int next;
	while (1)
	{
		next = s.find_first_of(" ", current);
		if (next != current)
		{
			string tmp = s.substr(current, next - current);
			if (tmp.size() != 0) //忽略空字串
				buf.push_back(tmp);
		}
		if (next == string::npos) break;
		current = next + 1; //下次由 next + 1 的位置開始找起。
	}
}


//主程式
int main() {

    //float x=0;

    //cout << "Please input x :";
    //cin >> x;

    std::vector<std::string> nums;
    std::ifstream inp("polydata.txt",ios::in);

     if(inp.fail()){
        cout << "error" << endl;
        exit(1);
     }//若檔案讀取失敗則印出error
     else{
            std::string s;
            while (std::getline(inp, s)) {

                float x=0;
                cout << "Please input x :";
                cin >> x;

                vector<string> buf;
                int c = 0;
                splitStr2Vec(s, buf);
                string k[100];
                int i=0,j;
                for (string tmp : buf){
                        k[i]=tmp;
                        i++;
                        c++;//計算每行數字個數
                }

                float cnum[c];

                for(j=0 ;j<c; j++){
                    cnum[j] = stof(k[j]);
                }

                int h = highestPower(cnum);//最高次方

                float ccnum[c];

                display(h, cnum);//印出f(x)

                derivative(h, cnum, ccnum);//印出f'(x)

                compute(h, cnum, x);//計算f(x)、f'(x)值
                cout << endl;

                nums.push_back(s);

            }
            inp.close();

     }
    inp.close();
    return 0;
}






