#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <bitset>

using namespace std;
string IN_FILE_PATH = "silesia/dickens";
string OUT_FILE_PATH = "output";

vector<int> binary_processing(string tbytes, bool is_24){   //little endian, big endian 이런거 잘 알아보고 결정..?
    vector<int> output_states;

    if (is_24){
        for (int i=0; i<24; i+=3){
            int state_int = stoi(tbytes.substr(i, 3), nullptr, 2);
            output_states.push_back(state_int);
        }
    }

    else{
        int size = tbytes.size();
        for (int i=0; i<size; i+=3){
            if (i+3 > size){                    //여기도 바꿔야될듯
                int state_int = stoi(tbytes.substr(i, size-i), nullptr, 2);
                output_states.push_back(state_int);
            }
            int state_int = stoi(tbytes.substr(i, 3), nullptr, 2);
            output_states.push_back(state_int);
        }
    }
    
    return output_states;
}

int main(){
    freopen("output", "a", stdout);
    ifstream inFile(IN_FILE_PATH, ios::binary); // 바이너리 모드로 파일 열기
    if (!inFile) {
        cerr << "파일을 열 수 없습니다." << endl;
        return 1;
    }

    int state_cnt[8] = {0};
    char byte[3];   
    while (inFile.read(byte, 3)){               
        ostringstream oss;
        for (int i=0; i<3; i++){
            bitset<8> buf2(static_cast<unsigned char>(byte[i]));
            oss << buf2;
        }
        string tbytes = oss.str();

        vector<int> states = binary_processing(tbytes, true);
        for (int i=0; i<8; i++){
            state_cnt[states[i]]++;
        }
    }

    if (inFile.gcount() > 0) {  // 파일 끝에서 남은 바이트가 있을 경우
        ostringstream oss;
        for (int i = 0; i < inFile.gcount(); i++) {
            bitset<8> buf2(static_cast<unsigned char>(byte[i]));
            oss << buf2;
        }
        string tbytes = oss.str();

        vector<int> states = binary_processing(tbytes, false);
        for (int i = 0; i < 8; i++) {
            state_cnt[states[i]]++;
        }
    }

    cout << "<" << IN_FILE_PATH << ">" << endl;
    for (int i=0; i<8; i++){
        cout << "State " << i <<": " << state_cnt[i] << endl;
    }
    cout << endl;
    
    inFile.close(); // 파일 닫기
    return 0;
}