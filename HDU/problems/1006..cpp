#include<stdio.h>
#include<math.h>
#include<time.h>
//float ans[121]={100.000,98.340,96.694,95.062,93.443,91.839,90.249,88.673,87.110,85.562,84.027,82.507,81.001,79.508,78.030,76.565,75.114,73.676,72.252,70.841,69.445,68.063,66.694,65.340,64.000,62.673,61.361,60.062,58.778,57.507,56.251,55.008,53.779,52.562,51.360,50.172,48.997,47.838,46.692,45.560,44.443,43.339,42.249,41.173,40.111,39.064,38.030,37.010,36.002,35.008,34.029,33.063,32.111,31.174,30.250,29.340,28.444,27.563,26.695,25.841,25.001,24.175,23.363,22.565,21.779,21.007,20.250,19.506,18.776,18.060,17.359,16.671,15.997,15.338,14.693,14.061,13.444,12.841,12.252,11.675,11.112,10.563,10.028,9.507,9.000,8.507,8.028,7.562,7.111,6.674,6.251,5.842,5.446,5.065,4.697,4.342,4.001,3.674,3.361,3.062,2.777,2.506,2.249,2.005,1.776,1.561,1.360,1.172,0.999,0.840,0.695,0.562,0.444,0.340,0.249,0.173,0.110,0.062,0.027,0.007,0.000};

 int figure(int x,int y)
 {
 	int t=abs(x-y);
 	if(t>5529600) return 11059200-t;
 	else return t;
 }

 int run(float n)
 {
 	int i,j,ans=0;
	int d1=0,d2=0,d3=0,p,min;
	n*=30720;
	for(i=1;i<=11059200;i++){
		d1+=720;d1%=11059200;
		d2+=12;d2%=11059200;
		d3+=1;
		if(figure(d1,d2)>=n&&figure(d1,d3)>=n&&figure(d1,d3)>=n) ans++;
		}
	return ans;
 }

int main()
{
	int begin;
	float n;
	while(1){
		scanf("%f",&n);
		begin=clock();
		if(n==-1) return 0;
		if(n>=120) printf("0.000\n");
		else printf("%.3f\n",float(run(n))/110592);
		printf("%d\n",clock()-begin);
	}
 return 0;
}

