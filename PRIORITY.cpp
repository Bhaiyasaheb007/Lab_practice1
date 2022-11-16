#include<bits/stdc++.h>
using namespace std;
const int N=40;

struct process{
    int pid;
    int bt;
    int priority;

};

bool compare(process a, process b)
{
    return a.priority>b.priority;
}

Priority(process pro[], int n)
{
    int wt[N], tat[N], twt=0, ttat=0;
    double awt=0, atat=0;

    cout<<"\n-------------------------------------------------------------------------------------";
    cout<<"\nSequence in which processes gets executed:";


    for(int i=0; i<n; i++)
    {
        cout<<pro[i].pid<<" ";

    }
    cout<<"\n-------------------------------------------------------------------------------------";

    wt[0]=0;
    for(int i=1; i<n; i++)
    {
        wt[i]=wt[i-1]+pro[i-1].bt;
    }

    for(int i=0; i<n; i++)
    {
        tat[i]=wt[i]+pro[i].bt;
        twt=twt+wt[i];
        ttat=ttat+tat[i];

    }

    awt=(float(twt)/n);
    atat=(float(ttat)/n);

    cout<<"\n---------------------------------------------------------------------------------------";
    cout<<"\nProcess\tBurst_Time\tTurn_Around_Time\tWaiting_Time\n";
    cout<<"\n---------------------------------------------------------------------------------------";

    for(int i=0; i<n; i++)
    {
        cout<<"\n"<<pro[i].pid<<"\t"<<pro[i].bt<<"\t\t"<<tat[i]<<"\t\t"<<wt[i];

    }

    cout<<"\n---------------------------------------------------------------------------------------";
    cout<<"\nAverage Waiting Time:"<<awt;
    cout<<"\nAverage Turn Around Time:"<<atat;
    cout<<"\n---------------------------------------------------------------------------------------";


}
int main()
{
    process pro[N];
    int n;
    int pro_element=3;

    cout<<"\nGreater Number Greater Priority\n";

    cout<<"\nEnter total number of processes:";
    cin>>n;

    cout<<"\nEnter  process details:\n";
    for(int i=0; i<n; i++)
    {
        cout<<"\nProcess:"<<i+1;
        cout<<"\nBurst Time and Priority:\t";
        pro[i].pid=i+1;
        cin>>pro[i].bt;
        cin>>pro[i].priority;

    }

    sort(pro, pro+pro_element, compare);

    Priority(pro,n);
    return 0;


}
