#include<iostream>
using namespace std;
const int N=40;

void RR(int AT[], int BT[], int n, int temp[], int TQ)
{
    int time, counter, remain=n, flag=0;
    double ttat=0, twt=0, atat, awt;

    cout<<"\n-------------------------------------------------------------------------------------------------------------";

    cout<<"\nProcess\tArrival_time\tBurst_time\tTurn_around_time\tWaiting_time";

    cout<<"\n-------------------------------------------------------------------------------------------------------------";

    for(time=0, counter=0; remain!=0;)
    {
        if( BT[counter]<=TQ && BT[counter]>0 )
        {

            time=time+BT[counter];
            BT[counter]=0;
            flag=1;


        }
        else if( BT[counter]>0)
        {
            time=time+TQ;
            BT[counter]=BT[counter]-TQ;


        }
        if( BT[counter]==0 && flag==1)
        {
            remain--;


            cout<<"\n"<<counter+1<<"\t\t"<<AT[counter]<<"\t\t"<<temp[counter]<<"\t\t"<<time-AT[counter]<<"\t\t"<<time-AT[counter]-temp[counter];
            ttat=ttat+time-AT[counter];
            twt=twt+time-AT[counter]-temp[counter];
            flag=0;

        }
        if(counter==n-1)
        {
            counter=0;
        }
        else
        {
            if(AT[counter+1]<=time)
                counter++;
            else
                counter=0;
        }
    }
    awt=(float(twt)/n);
    atat=(float(ttat)/n);

    cout<<"\n-------------------------------------------------------------------------------------------------------------";

    cout<<"\nAverage Waiting Time :"<<awt;
    cout<<"\nAverage Turn Around Time :"<<atat;
    cout<<"\n-------------------------------------------------------------------------------------------------------------";


}

int main()
{
    int AT[N], BT[N], temp[N], n,TQ;


    cout<<"\nEnter total number of processes:\t";
    cin>>n;

    cout<<"\nEnter Time Quantum:";
    cin>>TQ;

    cout<<"\nEnter process details:";
    for(int i=0; i<n; i++)
    {
        cout<<"\nprocess:"<<i+1;
        cout<<"\nEnter Arrival and Burst Time:\t";
        cin>>AT[i]>>BT[i];
        temp[i]=BT[i];

    }
    RR(AT, BT, n, temp, TQ);
    return 0;

}
