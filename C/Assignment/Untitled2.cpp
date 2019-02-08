#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n1,n2;cin>>n1;int a[n1],i,j;
    for(i=0;i<n1;i++) cin>>a[i];
    cin>>n2;int m[n2];
    for(i=0;i<n2;i++) cin>>m[i];
    int as=0,bs=0;
    string s;cin>>s;
    if(s=="Even")
    {
    	for(i=0;i<n1;i+=2)
    	{
    		as+=(a[i]-m[i]);
    		bs+=(m[i]-a[i]);
		}
	}
	else
	{
		for(i=1;i<n1;i+=2)
		{
			as+=(a[i]-m[i]);
    		bs+=(m[i]-a[i]);
		}
	}
    return 0;
}


