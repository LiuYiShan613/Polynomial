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

//����string�r��
void splitStr2Vec(string s, vector<string>& buf)
{
	int current = 0; //�̪�� 0 ����m�}�l��
	int next;
	while (1)
	{
		next = s.find_first_of(" ", current);
		if (next != current)
		{
			string tmp = s.substr(current, next - current);
			if (tmp.size() != 0) //�����Ŧr��
				buf.push_back(tmp);
		}
		if (next == string::npos) break;
		current = next + 1; //�U���� next + 1 ����m�}�l��_�C
	}
}


//�D�{��
int main() {

    //float x=0;

    //cout << "Please input x :";
    //cin >> x;

    std::vector<std::string> nums;
    std::ifstream inp("polydata.txt",ios::in);

     if(inp.fail()){
        cout << "error" << endl;
        exit(1);
     }//�Y�ɮ�Ū�����ѫh�L�Xerror
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
                        c++;//�p��C��Ʀr�Ӽ�
                }

                float cnum[c];

                for(j=0 ;j<c; j++){
                    cnum[j] = stof(k[j]);
                }

                int h = highestPower(cnum);//�̰�����

                float ccnum[c];

                display(h, cnum);//�L�Xf(x)

                derivative(h, cnum, ccnum);//�L�Xf'(x)

                compute(h, cnum, x);//�p��f(x)�Bf'(x)��
                cout << endl;

                nums.push_back(s);

            }
            inp.close();

     }
    inp.close();
    return 0;
}






