/***************************************************************************************
/ Modify variable done (number of matches already completed) in Line 47
/ Modify points table (around line 90)
/ Modify the number in bitset command equal to number of remaining matches just below the points table
****************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define CSK 0
#define DC 1
#define KKR 2
#define KXIP 3
#define MI 4
#define RCB 5
#define RR 6
#define SRH 7

int twopower(int n)
{
    return 1<<n;
}

struct match
{
    int home;
    int away;
};

int n_largest(vector<int> a, int n)
{
    sort(a.begin(),a.end());
    return a[8-n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string teams[8] = {"CSK","DC","KKR","KXIP","MI","RCB","RR","SRH"};
    vector<double> sure_top4(8,0);
    vector<double> maybe_top4(8,0);
    vector<double> sure_top2(8,0);
    vector<double> maybe_top2(8,0);

    int done      = 41;
    int total     = 56;
    int remaining = total-done;

    int x = twopower(remaining);
    string s;

    match results[total+1];
    results[42].home = RCB;
    results[43].home = KKR;
    results[44].home = CSK;
    results[45].home = RR;
    results[46].home = DC;
    results[47].home = KKR;
    results[48].home = SRH;
    results[49].home = RCB;
    results[50].home = CSK;
    results[51].home = MI;
    results[52].home = KXIP;
    results[53].home = DC;
    results[54].home = RCB;
    results[55].home = KXIP;
    results[56].home = MI;

    results[42].away = KXIP;
    results[43].away = RR;
    results[44].away = MI;
    results[45].away = SRH;
    results[46].away = RCB;
    results[47].away = MI;
    results[48].away = KXIP;
    results[49].away = RR;
    results[50].away = DC;
    results[51].away = SRH;
    results[52].away = KKR;
    results[53].away = RR;
    results[54].away = SRH;
    results[55].away = CSK;
    results[56].away = KKR;
    vector<int> points;

    for(int t=0;t<x;t++)
    {
    	points.clear();
        points.push_back(16);   //CSK
        points.push_back(14);   //DC
        points.push_back(8);    //KKR
        points.push_back(10);   //KXIP
        points.push_back(12);   //MI
        points.push_back(6);    //RCB
        points.push_back(6);    //RR
        points.push_back(10);    //SRH

        s = std::bitset<15>(t).to_string();

        for(int i=0;i<remaining;i++)
        {
            if(s[i]=='0')
                points[results[done+i+1].home] += 2;
            else
                points[results[done+i+1].away] += 2;
        }

        int fourth = n_largest(points,4);
        int fifth  = n_largest(points,5);

        if(fourth==fifth)
            for(int i=0;i<8;i++)
            {
                if(points[i]>fourth)
                    sure_top4[i]++;
                if(points[i]>=fourth)
                    maybe_top4[i]++;
            }
        else
            for(int i=0;i<8;i++)
            {
                if(points[i]>=fourth)
                {
                    sure_top4[i]++;
                    maybe_top4[i]++;
                }
            }

        int second = n_largest(points,2);
        int third  = n_largest(points,3);

        if(second==third)
            for(int i=0;i<8;i++)
            {
                if(points[i]>second)
                    sure_top2[i]++;
                if(points[i]>=second)
                    maybe_top2[i]++;
            }
        else
            for(int i=0;i<8;i++)
            {
                if(points[i]>=second)
                {
                    sure_top2[i]++;
                    maybe_top2[i]++;
                }
            }
    }

    //Converting to percentage
    for(int i=0;i<8;i++)
    {
        sure_top2[i] /= x;
        sure_top2[i] *= 100;
        maybe_top2[i] /= x;
        maybe_top2[i] *= 100;
        sure_top4[i] /= x;
        sure_top4[i] *= 100;
        maybe_top4[i] /= x;
        maybe_top4[i] *= 100;
    }

    for(int i=0;i<8;i++)
        printf("%s \t SURE_TOP4 : %2.2f \t MAYBE_TOP4 : %2.2f \t SURE_TOP2 : %2.2f \t MAYBE_TOP2 : %2.2f\n",teams[i].c_str(),sure_top4[i],maybe_top4[i],sure_top2[i],maybe_top2[i]);

    return 0;
}
