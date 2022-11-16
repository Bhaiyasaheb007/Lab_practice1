/*bhaiyasaheb chaudhari*/

#include<bits/stdc++.h>
using namespace std;
const int N=100;

bool Search(vector<int> frame, int key)
{
    for(int i=0; i<frame.size(); i++)
    {
        if(frame[i]==key)
            return true;

    }
     return false;
}

int Find_position(vector<int>& frame, int pages[], int frame_size, int n, int index)
{
    int rep_pos=-1, farthest=index;

    for(int i=0; i<frame.size(); i++)
    {
        int j;
        for(j=index; j<n; j++)
        {
            if(frame[i]==pages[j])
            {
                if(farthest<j)
                {
                    farthest=j;
                    rep_pos=i;
                }
                break;
            }

        }
        if(j==n)
            return i;
    }
    return (rep_pos==-1?0:rep_pos);
}
void OPR_page_replacement(int pages[], int frame_size, int n)
{
    vector<int> frame;
    int page_faults=0, page_hits=0;

    for(int i=0; i<n; i++)
    {
        if(Search(frame, pages[i]))
        {
            page_hits++;


        }
        else
        {
            if(frame.size()<frame_size)
            {
                frame.push_back(pages[i]);
            }
            else
            {
                int pos=Find_position(frame, pages, frame_size, n,i+1);
                frame[pos]=pages[i];
            }
            page_faults++;
        }
    }
    cout<<"\n-------------------------------------------";
    cout<<"\nPage Faults"<<page_faults;
    cout<<"\npage Hits"<<page_hits;
    cout<<"\n-------------------------------------------";
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
        cin>>pages[i];

    OPR_page_replacement(pages, frame_size, n);
    return 0;
}
