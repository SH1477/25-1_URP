#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

const int PAGE_SIZE = 16384;        //4KB=4096, 8KB=8192, 16KB=16384

void printBits(const unsigned char* page, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        bitset<8> bits(page[i]);
        cout << bits << " ";
        if ((i + 1) % 8 == 0) cout << endl;  // print 1byte each
    }
    cout << endl;
}

void Num_state(unsigned char** pages, int total_page){
    int state=0, state0=0, state1=0, state2=0, state3=0, state4=0, state5=0, state6=0, state7=0;
    int state0_0=0, state1_0=0, state2_0=0, state3_0=0, state4_0=0, state5_0=0, state6_0=0, state7_0=0;
    int state0_1=0, state1_1=0, state2_1=0, state3_1=0, state4_1=0, state5_1=0, state6_1=0, state7_1=0;
    int state0_2=0, state1_2=0, state2_2=0, state3_2=0, state4_2=0, state5_2=0, state6_2=0, state7_2=0;
    int state0_3=0, state1_3=0, state2_3=0, state3_3=0, state4_3=0, state5_3=0, state6_3=0, state7_3=0;
    int state0_4=0, state1_4=0, state2_4=0, state3_4=0, state4_4=0, state5_4=0, state6_4=0, state7_4=0;
    int state0_5=0, state1_5=0, state2_5=0, state3_5=0, state4_5=0, state5_5=0, state6_5=0, state7_5=0;
    int state0_6=0, state1_6=0, state2_6=0, state3_6=0, state4_6=0, state5_6=0, state6_6=0, state7_6=0;
    int state0_7=0, state1_7=0, state2_7=0, state3_7=0, state4_7=0, state5_7=0, state6_7=0, state7_7=0;

    while(total_page % 3 != 0) {
        total_page = total_page - 1;
    }
    for (int i = 0; i < total_page; i=i+3) {
        for (int j = 0; j < PAGE_SIZE; j++){
            for (int k = 0; k < 8; k++){
                bool LSB = (pages[i][j] >> k) & 1;
                bool CSB = (pages[i+1][j] >> k) & 1;
                bool MSB = (pages[i+2][j] >> k) & 1;
                state = (MSB<<2) + (CSB<<1) + LSB;

                if(k == 0) {
                    if(state == 7) state0_0++;
                    else if(state == 3) state1_0++;
                    else if(state == 1) state2_0++;
                    else if(state == 5) state3_0++;
                    else if(state == 4) state4_0++;
                    else if(state == 0) state5_0++;
                    else if(state == 2) state6_0++;
                    else state7_0++;
                }
                else if(k == 1) {
                    if(state == 7) state0_1++;
                    else if(state == 3) state1_1++;
                    else if(state == 1) state2_1++;
                    else if(state == 5) state3_1++;
                    else if(state == 4) state4_1++;
                    else if(state == 0) state5_1++;
                    else if(state == 2) state6_1++;
                    else state7_1++;
                }
                else if(k == 2) {
                    if(state == 7) state0_2++;
                    else if(state == 3) state1_2++;
                    else if(state == 1) state2_2++;
                    else if(state == 5) state3_2++;
                    else if(state == 4) state4_2++;
                    else if(state == 0) state5_2++;
                    else if(state == 2) state6_2++;
                    else state7_2++;
                }
                else if(k == 3) {
                    if(state == 7) state0_3++;
                    else if(state == 3) state1_3++;
                    else if(state == 1) state2_3++;
                    else if(state == 5) state3_3++;
                    else if(state == 4) state4_3++;
                    else if(state == 0) state5_3++;
                    else if(state == 2) state6_3++;
                    else state7_3++;
                }
                else if(k == 4) {
                    if(state == 7) state0_4++;
                    else if(state == 3) state1_4++;
                    else if(state == 1) state2_4++;
                    else if(state == 5) state3_4++;
                    else if(state == 4) state4_4++;
                    else if(state == 0) state5_4++;
                    else if(state == 2) state6_4++;
                    else state7_4++;
                }
                else if(k == 5) {
                    if(state == 7) state0_5++;
                    else if(state == 3) state1_5++;
                    else if(state == 1) state2_5++;
                    else if(state == 5) state3_5++;
                    else if(state == 4) state4_5++;
                    else if(state == 0) state5_5++;
                    else if(state == 2) state6_5++;
                    else state7_5++;
                }
                else if(k == 6) {
                    if(state == 7) state0_6++;
                    else if(state == 3) state1_6++;
                    else if(state == 1) state2_6++;
                    else if(state == 5) state3_6++;
                    else if(state == 4) state4_6++;
                    else if(state == 0) state5_6++;
                    else if(state == 2) state6_6++;
                    else state7_6++;
                }
                else {
                    if(state == 7) state0_7++;
                    else if(state == 3) state1_7++;
                    else if(state == 1) state2_7++;
                    else if(state == 5) state3_7++;
                    else if(state == 4) state4_7++;
                    else if(state == 0) state5_7++;
                    else if(state == 2) state6_7++;
                    else state7_7++;
                }
                if(state == 7) state0++;
                else if(state == 3) state1++;
                else if(state == 1) state2++;
                else if(state == 5) state3++;
                else if(state == 4) state4++;
                else if(state == 0) state5++;
                else if(state == 2) state6++;
                else state7++;
            }
        }
        //cout << i+1 << "th page" << endl;
    }
    cout << "1st bit ==> " << "state0: " << state0_0 << " state1: " << state1_0 << " state2: " << state2_0 << " state3: " << state3_0 << " state4: " << state4_0 << " state5: " << state5_0 << " state6: " << state6_0 << " state7: " << state7_0 << " ==> total: " << state0_0 + state1_0 + state2_0 + state3_0 + state4_0 + state5_0 + state6_0 + state7_0 << endl;
    cout << "2nd bit ==> " << "state0: " << state0_1 << " state1: " << state1_1 << " state2: " << state2_1 << " state3: " << state3_1 << " state4: " << state4_1 << " state5: " << state5_1 << " state6: " << state6_1 << " state7: " << state7_1 << " ==> total: " << state0_1 + state1_1 + state2_1 + state3_1 + state4_1 + state5_1 + state6_1 + state7_1 << endl;
    cout << "3rd bit ==> " << "state0: " << state0_2 << " state1: " << state1_2 << " state2: " << state2_2 << " state3: " << state3_2 << " state4: " << state4_2 << " state5: " << state5_2 << " state6: " << state6_2 << " state7: " << state7_2 << " ==> total: " << state0_2 + state1_2 + state2_2 + state3_2 + state4_2 + state5_2 + state6_2 + state7_2 << endl;
    cout << "4th bit ==> " << "state0: " << state0_3 << " state1: " << state1_3 << " state2: " << state2_3 << " state3: " << state3_3 << " state4: " << state4_3 << " state5: " << state5_3 << " state6: " << state6_3 << " state7: " << state7_3 << " ==> total: " << state0_3 + state1_3 + state2_3 + state3_3 + state4_3 + state5_3 + state6_3 + state7_3 << endl;
    cout << "5th bit ==> " << "state0: " << state0_4 << " state1: " << state1_4 << " state2: " << state2_4 << " state3: " << state3_4 << " state4: " << state4_4 << " state5: " << state5_4 << " state6: " << state6_4 << " state7: " << state7_4 << " ==> total: " << state0_4 + state1_4 + state2_4 + state3_4 + state4_4 + state5_4 + state6_4 + state7_4 << endl;
    cout << "6th bit ==> " << "state0: " << state0_5 << " state1: " << state1_5 << " state2: " << state2_5 << " state3: " << state3_5 << " state4: " << state4_5 << " state5: " << state5_5 << " state6: " << state6_5 << " state7: " << state7_5 << " ==> total: " << state0_5 + state1_5 + state2_5 + state3_5 + state4_5 + state5_5 + state6_5 + state7_5 << endl;
    cout << "7th bit ==> " << "state0: " << state0_6 << " state1: " << state1_6 << " state2: " << state2_6 << " state3: " << state3_6 << " state4: " << state4_6 << " state5: " << state5_6 << " state6: " << state6_6 << " state7: " << state7_6 << " ==> total: " << state0_6 + state1_6 + state2_6 + state3_6 + state4_6 + state5_6 + state6_6 + state7_6 << endl;
    cout << "8th bit ==> " << "state0: " << state0_7 << " state1: " << state1_7 << " state2: " << state2_7 << " state3: " << state3_7 << " state4: " << state4_7 << " state5: " << state5_7 << " state6: " << state6_7 << " state7: " << state7_7 << " ==> total: " << state0_7 + state1_7 + state2_7 + state3_7 + state4_7 + state5_7 + state6_7 + state7_7 << endl;

    cout << endl << "total status of file" << endl;
    cout << "number of state0 (111): " << state0 << endl;
    cout << "number of state1 (011): " << state1 << endl;
    cout << "number of state2 (001): " << state2 << endl;
    cout << "number of state3 (101): " << state3 << endl;
    cout << "number of state4 (100): " << state4 << endl;
    cout << "number of state5 (000): " << state5 << endl;
    cout << "number of state6 (010): " << state6 << endl;
    cout << "number of state7 (110): " << state7 << endl;
}

int main() {

    //file input
    ifstream file("../data/samba", ios::binary | ios::ate);
    if (!file) {
        cerr << "can't open the file!" << endl;
        return 1;
    }

    file.seekg(0, ios::end);
    streamsize fileSize = file.tellg();
    file.seekg(0, ios::beg);

    int totalPages = (fileSize + PAGE_SIZE - 1) / PAGE_SIZE;

    // initial lize array
    unsigned char** pages = new unsigned char*[totalPages];

    // store the data to array
    for (int page_num = 0; page_num < totalPages; ++page_num) {

        pages[page_num] = new unsigned char[PAGE_SIZE];

        if(page_num == totalPages-1){
            int read_bytes = fileSize % PAGE_SIZE;

            if (read_bytes == 0){
                file.read(reinterpret_cast<char*>(pages[page_num]), PAGE_SIZE);
            }
            else{
                file.read(reinterpret_cast<char*>(pages[page_num]), read_bytes);
                for(int bytes_num = read_bytes; bytes_num < PAGE_SIZE; bytes_num++){
                    pages[page_num][bytes_num] = 0xFF;      //padding with 1 at last page
                }
            }
        }
        else{
            file.read(reinterpret_cast<char*>(pages[page_num]), PAGE_SIZE);
        }
        //printBits(pages[page_num], PAGE_SIZE);        //for tracing bit
    }

    cout << "file size: " << fileSize << " Byte (" << totalPages << " page)" << endl;
    
    Num_state(pages, totalPages);

    file.close();

    // free to memory
    for (int i = 0; i < totalPages; ++i) {
        delete[] pages[i];
    }
    delete[] pages;

    return 0;
}