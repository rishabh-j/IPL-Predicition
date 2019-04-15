/***************************************************************************************
/ Modify variable done (number of matches already completed) in Line 47
/ Modify points table in Lines 116-123
/ Modify the number in bitset command equal to number of remaining matches in Line 128
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

    int done      = 30;
    int total     = 56;
    int remaining = total-done;

    int x = twopower(remaining);
    string s;

    match results[total+1];
    results[31].home = MI;
    results[32].home = KXIP;
    results[33].home = SRH;
    results[34].home = DC;
    results[35].home = KKR;
    results[36].home = RR;
    results[37].home = DC;
    results[38].home = SRH;
    results[39].home = RCB;
    results[40].home = RR;
    results[41].home = CSK;
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


    results[31].away = RCB;
    results[32].away = RR;
    results[33].away = CSK;
    results[34].away = MI;
    results[35].away = RCB;
    results[36].away = MI;
    results[37].away = KXIP;
    results[38].away = KKR;
    results[39].away = CSK;
    results[40].away = DC;
    results[41].away = SRH;
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

    int step = x/1000;
    vector<int> points;

    for(int t=0;t<x;t++)
    {
    	points.clear();
        points.push_back(14);   //CSK
        points.push_back(10);   //DC
        points.push_back(8);    //KKR
        points.push_back(8);    //KXIP
        points.push_back(8);    //MI
        points.push_back(2);    //RCB
        points.push_back(4);    //RR
        points.push_back(6);    //SRH

        if(t%step==0)
            printf("Step : %d\n", t/step);

        s = std::bitset<26>(t).to_string();

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

    //Sort by sure_top4 (using bubble sort since there are only 8 elements and it is done only once)
    for(int i=0;i<8;i++)
        for(int j=i+1;j<8;j++)
            if(sure_top4[j]>sure_top4[i])
            {
                swap(teams[i],teams[j]);
                swap(sure_top4[i],sure_top4[j]);
                swap(maybe_top4[i],maybe_top4[j]);
                swap(sure_top2[i],sure_top2[j]);
                swap(maybe_top2[i],maybe_top2[j]);
            }

    for(int i=0;i<8;i++)
        printf("%s \t SURE_TOP4 : %2.2f \t MAYBE_TOP4 : %2.2f \t SURE_TOP2 : %2.2f \t MAYBE_TOP2 : %2.2f\n",teams[i].c_str(),pakka_top4[i],maybe_top4[i],pakka_top2[i],maybe_top2[i]);

    return 0;
}
