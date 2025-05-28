#include<iostream>
#include<ctime>
using namespace std;
const int MAX = 10;
void goBackN(int frames, int windowSize){
    int base = 0;
    int next = 0;
    int sentCount = 0;
    srand(static_cast<unsigned>(time(nullptr)));
    cout<<"Simulating frames...\n";
    while(base<frames){
        while (next < frames && next < base + windowSize) {
            cout << "Sending " << next << endl;
            next++;
            sentCount++;
        }
        if(rand()%2==0){
            cout<<"Ack lost for: "<<base<<endl;
            next = base;
        }else{
            cout<<"Ack received for: "<<base<<endl;
            base++;
        }
    }
    cout<<"Success\n";
}
int main(){
    int frames,windowSize;
    cout<<"Enter the number of frames: ";
    cin>>frames;
    cout<<"Enter the window size: ";
    cin>>windowSize;

    goBackN(frames,windowSize);
    return 0;
}
