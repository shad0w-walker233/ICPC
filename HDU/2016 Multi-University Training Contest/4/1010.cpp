#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
string ss[70]={
"Cleveland Cavaliers","Golden State Warriors","San Antonio Spurs","Miami Heat","Miami Heat","Dallas Mavericks","L.A. Lakers","L.A. Lakers","Boston Celtics","San Antonio Spurs","Miami Heat","San Antonio Spurs","Detroit Pistons","San Antonio Spurs","L.A. Lakers","L.A. Lakers","L.A. Lakers","San Antonio Spurs","Chicago Bulls","Chicago Bulls","Chicago Bulls","Houston Rockets","Houston Rockets","Chicago Bulls","Chicago Bulls","Chicago Bulls","Detroit Pistons","Detroit Pistons","L.A. Lakers","L.A. Lakers","Boston Celtics","L.A. Lakers","Boston Celtics","Philadelphia 76ers","L.A. Lakers","Boston Celtics","L.A. Lakers","Seattle Sonics","Washington Bullets","Portland Trail Blazers","Boston Celtics","Golden State Warriors","Boston Celtics","New York Knicks","L.A. Lakers","Milwaukee Bucks","New York Knicks","Boston Celtics","Boston Celtics","Philadelphia 76ers","Boston Celtics","Boston Celtics","Boston Celtics","Boston Celtics","Boston Celtics","Boston Celtics","Boston Celtics","Boston Celtics","St. Louis Hawks","Boston Celtics","Philadelphia Warriors","Syracuse Nats","Minneapolis Lakers","Minneapolis Lakers","Minneapolis Lakers","Rochester Royals","Minneapolis Lakers","Minneapolis Lakers","Baltimore Bullets","Philadelphia Warriors"
};

int main()
{
	int k,i,t;
	string s;
	scanf("%d",&t);
	getchar();
	for(k=1;k<=t;k++){
		int cnt=0;
		getline(cin,s);
		printf("Case #%d: ",k);
		for(i=0;i<70;i++){
			if(s==ss[i]) cnt++;
		}
		printf("%d\n",cnt);
	}
 return 0;
}
