#include<iostream>
using namespace std;
const int N=40;

void SRTF(int AT[], int BT[], int RT[], int n)
{
    int twt=0, ttat=0, time, counter=0, complete, smallest;
    double awt, atat;
    RT[N-1]=999;

    cout<<"\n----------------------------------------------------------------------------------------------";
    cout<<"\nProcess\tArrival\tBurst\tTAT\tWT";
    cout<<"\n----------------------------------------------------------------------------------------------";


    for(time=0; counter!=n; time++)
    {
        smallest=N-1;
        for(int i=0; i<n; i++)
        {
            if(AT[i]<=time && RT[i]<RT[smallest] && RT[i]>0)
            {
                smallest=i;
            }


        }

            RT[smallest]--;
            if(RT[smallest]==0)
            {
                counter++;
                complete=time+1;
                cout<<"\n"<<smallest+1<<"\t"<<AT[smallest]<<"\t"<<BT[smallest]<<"\t"<<complete-AT[smallest]<<"\t"<<complete-AT[smallest]-BT[smallest];
                ttat=ttat+complete-AT[smallest];
                twt=twt+complete-AT[smallest]-BT[smallest];
            }
    }
    cout<<"\n----------------------------------------------------------------------------------------------";

    awt=(float(twt)/n);
    atat=(float(ttat)/n);
    cout<<"\nAverage Waiting Time :"<<awt;
    cout<<"\nAverage Turn Around Time :"<<atat;
    cout<<"\n----------------------------------------------------------------------------------------------";
}

int main()
{
    int AT[N], BT[N], RT[N], n;

    cout<<"\nEnter total number of processes:";
    cin>>n;

    cout<<"\nEnter process details";
    for(int i=0; i<n; i++)
    {
        cout<<"\nProcess:"<<i+1;
        cout<<"\nEnter Arrival and Burst time:\t";
        cin>>AT[i]>>BT[i];
        RT[i]=BT[i];

    }

    SRTF(AT, BT, RT, n);
    return 0;
}
