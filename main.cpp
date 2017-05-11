#include <iostream>
#include<cstring>

using namespace std;

   char nibble_in_hex(uint8_t i ){
       char a;

    switch(i)
    {
    case 0:a='0';break;
    case 1:a='1';break;
    case 2:a='2';break;
    case 3:a='3';break;
    case 4:a='4';break;
    case 5:a='5';break;
    case 6:a='6';break;
    case 7:a='7';break;
    case 8:a='8';break;
    case 9:a='9';break;
    case 10:a='A';break;
    case 11:a='B';break;
    case 12:a='C';break;
    case 13:a='D';break;
    case 14:a='E';break;
    case 15:a='F';break;
    }
return a;
   }


void printbyte(uint8_t byte){
    uint8_t low = (byte & 0b00001111);
    uint8_t high = byte >>4;
    cout<<nibble_in_hex(high)<<nibble_in_hex(low);
}
void print_in_hex( const void* data, size_t size){
    const uint8_t* p = reinterpret_cast<const uint8_t*>(data);
    for(size_t i=0; i<size; i++ ){
        printbyte(p[i]); cout<<"  ";
    }
}
struct student{
    char name[17];
    uint16_t year;
    float ball;
    unsigned int sex : 1;
    unsigned int srok;
    student* batya;
};

int main() {
    student s[3];

    s[0].ball=4.3;
    strcpy(s[0].name,"KudashkinA");
    s[0].sex=1;
    s[0].srok=0;
    s[0].year=2016;
    s[0].batya= nullptr;

    s[1].ball=4.5;
    strcpy(s[1].name,"ChikaevA");
    s[1].sex=1;
    s[1].srok=0;
    s[1].year=2016;
    s[1].batya=&s[0];

    s[2].ball=4.8;
    strcpy(s[2].name,"PupkinV");
    s[2].sex=1;
    s[2].srok=0;
    s[2].year=2016;
    s[2].batya=&s[0];


    for(size_t i=0;i<3;i++) {
        print_in_hex(&s[i], sizeof(s[i]));
        cout<<"\n";
    }
    return 0;
}