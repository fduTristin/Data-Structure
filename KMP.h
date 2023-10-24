#include<string>
#include<iostream>
#define maxsize 10000

using namespace std;

//get the "next array"
void get_next(int next[],string s)
{
    int j = 0,k = -1;
    next[0] = -1;
    while(j<s.size()-1)
    {
        if(k == -1||s[j] == s[k])
        {
            j++;k++;
            next[j] = k;
        }
        else k = next[k];
    }
}

int KMP(const string& s,const string& subs)
{
    int next[maxsize],i=0,j=0;
    get_next(next,s);
    while(i<s.size()&&j<subs.size())
    {
        if(j==-1||s[i]==subs[j])
        {
            i++;j++;
        }
        else j = next[j];
    }
    if(j>=subs.size())
    {
        return (i-subs.size());
    }
    else return -1;
}


