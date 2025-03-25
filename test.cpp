#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

const int PAGE_SIZE = 4096;        //4KB=4096, 8KB=8192, 16KB=16384

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
    ifstream file("../data/test", ios::binary | ios::ate);
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