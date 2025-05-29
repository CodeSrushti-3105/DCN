#include<iostream>
#include<cmath>
using namespace std;

string xorOp(string dividend, string divisor){
    string result = "";
    for(int i=0; i<divisor.length(); i++){
        if(dividend[i] == divisor[i]){
            result += '0';
        }else{
            result += '1';
        }
    }
    return result;
}

string CRC(string data, string divisor){
    int n = divisor.length();
    string temp = data.substr(0,n);
    int dataIdx = n;
    while(dataIdx < data.length()){
        if(temp[0] == '1'){
            temp = xorOp(divisor,temp) + data[dataIdx];
        }else{
            temp = xorOp(string(n,'0'),temp) + data[dataIdx];
        }
        dataIdx++;
        temp = temp.substr(1);
    }
    if(temp[0] == '1'){
        temp = xorOp(divisor,temp);
    }else{
        temp = xorOp(string(n,'0'),temp);
    }
    return temp.substr(1);
}
int main(){
    string data,divisor;
    cout<<"Enter the data: ";
    cin>>data;
    cout<<"Enter the divisor: ";
    cin>>divisor;

    int m = divisor.length() - 1;
    string appendData = data + string(m,'0');
    string crc = CRC(appendData,divisor);
    string transmitted = data + crc;

    cout<<"Transmitted data: "<<transmitted<<endl;
    string rD;
    cout<<"Enter received data: ";
    cin>>rD;

    string remainder = CRC(rD,divisor);
    bool error = false;
    for(char bit : remainder){
        if(bit == '1'){
            error = true;
            break;
        }
    }
    if(error){
        cout<<"Error detected!\n";
    }else{
        cout<<"No error detected\n";
    }
    return 0;
}
