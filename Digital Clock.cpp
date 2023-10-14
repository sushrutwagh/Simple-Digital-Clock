#include <iostream>
#include <chrono>
#include <thread>
#include<windows.h>

using namespace std;

int main()
{
    int sec=0,hour=0,mins=0,ampm,pt=0;
    string check;
    cout<<"Enter the hours : ";
    cin>>hour;
    hour=hour%12;
    cout<<"Enter the mins : ";
    cin>>mins;
    mins=mins%60;
    cout<<"Enter the secs : ";
    cin>>sec;
    sec=sec%60;
    do{
       cout<<"am / pm ?";
        cin>>check;
        if(check=="am"){
            ampm=1;
            pt=1;
        }
        else if(check=="pm"){
            ampm=0;
            pt=1;
        }
    }while(pt!=1);
 while(true){
            sec=(sec%60)+ 1;
        if(sec>=60){
            mins=(mins%60)+ 1;
            sec=0;
            if(mins>=60){
                hour=(hour%12)+ 1;
                mins=0;
                if(hour>=12){
                    hour=0;
                    if(ampm==1){
                        ampm=0;
                    }
                    else if(ampm==0){
                        ampm=1;
                    }
                }
            }
        }
        cout<<hour<<":"<<mins<<":"<<sec<<" ";
        if(ampm==1){
            cout<<"am"<<endl;
        }
        else if(ampm==0){
            cout<<"pm"<<endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");
    }

}

