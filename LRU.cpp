/*bhaiyasaheb chaudhari*/

#include<bits/stdc++.h>
using namespace std;
const int N=100;

void LRU_page_replacement(int pages[], int frame_size, int n)
{
    unordered_set<int> s;
    unordered_map<int,int> indexes;
    int page_faults=0, page_hits=0;

    for(int i=0; i<n; i++)
    {
        if(s.find(pages[i])!=s.end())
        {

            indexes[pages[i]]=i;
            page_hits++;

        }
        else
        {
            if(s.size()<frame_size)
            {
                s.insert(pages[i]);
                indexes[pages[i]]=i;

            }
            else
            {
                int lru=INT_MAX,val;

                for(auto it=s.begin(); it!=s.end(); it++)
                {
                    if(indexes[*it]<lru)
                    {
                        lru=indexes[*it];
                        val=*it;
                    }

                }
                s.erase(val);
                s.insert(pages[i]);
                indexes[pages[i]]=i;

            }
            page_faults++;
        }
    }
    cout<<"\n---------------------------------";
    cout<<"\nPage Faults:"<<page_faults;
    cout<<"\nPage Hits:"<<page_hits;
    cout<<"\n---------------------------------";
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

    LRU_page_replacement(pages, frame_size, n);
    return 0;

}
