/*bhaiyasaheb chaudhari*/

#include<bits/stdc++.h>
using namespace std;
const int N=40;
struct process{
    int pid;
    int bt;

};

bool compare(process a, process b)
{
    return a.pid<b.pid;
}

void FCFS(process pro[], int n)
{
    int twt=0, ttat=0, wt[N],tat[N];
    double atat=0, awt=0;

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
    cout<<"\n-----------------------------------------------------------------------------------------";
    cout<<"\nProcess\tBurst_Time\tTurn_Around_time\tWaiting_Time";
    cout<<"\n-----------------------------------------------------------------------------------------";
    for(int i=0; i<n; i++)
    {
        cout<<"\n"<<pro[i].pid<<"\t"<<pro[i].bt<<"\t\t"<<tat[i]<<"\t\t"<<wt[i];
    }
    cout<<"\n-----------------------------------------------------------------------------------------";
    cout<<"\nAverage Waiting Time:"<<awt;
    cout<<"\nAverage Turn Around Time:"<<atat;
    cout<<"\n-----------------------------------------------------------------------------------------";

}
int main()
{
    process pro[N];
    int n;
    int pro_element=2;

    cout<<"\nEnter total number of processes:";
    cin>>n;

    cout<<"\nEnter process details:";
    for(int i=0; i<n; i++)
    {
        cout<<"\nBurst Time of Process:"<<i+1;
        pro[i].pid=i+1;
        cin>>pro[i].bt;
    }

    sort(pro, pro+pro_element, compare);

    FCFS(pro, n);
    return 0;


}
