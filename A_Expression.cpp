#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int  sum=0,sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0;

    for(int i=0; i<=3; i++)
    {
        sum=a+(b*c);
        sum1=a*b*c;
        sum2=(a*b)+c;
        sum3=a*(b+c);
        sum4=(a+b)*c;
        sum5=a+b+c;
        sum6=(a*c)+b;

    }
    if(sum>=sum1 && sum>=sum2 && sum>=sum3 && sum>=sum4 &&sum>=sum5 &&sum>=sum6)
    {
        cout<<sum<<endl;
    }
    else if(sum1>=sum && sum1>=sum2 && sum1>=sum3 && sum1>=sum4 &&sum1>=sum5 &&sum1>=sum6)
    {
        cout<<sum1<<endl;
    }
    else if( sum2>=sum && sum2>=sum1 && sum2>=sum3  &&sum2>=sum4 &&sum2>=sum5 &&sum2>=sum6)
    {
        cout<<sum2<<endl;
    }
    else if (sum3>=sum  && sum3>=sum1 && sum3>=sum2 && sum3>=sum4 &&sum3>=sum5 &&sum3>=sum6)
    {
        cout<<sum3<<endl;
    }
    else if(sum4>=sum && sum4>=sum1 && sum4>=sum2 && sum4>=sum3&&sum4>=sum5 &&sum4>=sum6 )
    {

        cout<<sum4<<endl;
    }
    else if(sum5>=sum && sum5>=sum1 && sum5>=sum2 && sum5>=sum3&&sum5>=sum4 &&sum5>=sum6 )
    {

        cout<<sum5<<endl;
    }
    else if(sum6>=sum && sum6>=sum1 && sum5>=sum2 && sum6>=sum3&&sum6>=sum4 &&sum6>=sum5 )
    {

        cout<<sum6<<endl;
    }
}