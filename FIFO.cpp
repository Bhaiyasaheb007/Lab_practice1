/*bhaiyasaheb chaudhari*/

#include<bits/stdc++.h>
using namespace std;
const int N=100;

void FIFO_page_replacement(int pages[],int frame_size, int n)
{
    int mark[N];
    queue<int> q;
    int page_faults=0, page_hits=0;

    for(int i=0; i<n; i++)
    {
        if(mark[pages[i]]==true)
        {
            page_hits++;
        }
        else
        {
             q.push(pages[i]);
             mark[pages[i]]=true;

            if(q.size()>frame_size)
            {
                int e=q.front();
                mark[e]=false;
                q.pop();


            }

            page_faults++;
        }
    }
    cout<<"\n------------------------------------";
    cout<<"\nPage Faults:"<<page_faults;
    cout<<"\nPage Hits:"<<page_hits;
    cout<<"\n------------------------------------";
}
int main()
{
    int pages[N];
    int frame_size;
    int n;

    cout<<"\nEnter frame size:";
    cin>>frame_size;

    cout<<"\nEnter page reference stream size:";
    cin>>n;

    cout<<"\nEnter page reference stream:";
    for(int i=0; i<n; i++)
    {
        cin>>pages[i];
    }

    FIFO_page_replacement(pages, frame_size, n);
    return 0;
}

