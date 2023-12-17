#include<stdio.h>
#include<math.h>
#define PI 3.1416

double distanceKm(double, double, double, double);
double radianConversion(double);
double overallDistance(double*, double*, int);

int main()
{
	double lats[] = { 53.557029,53.557166,53.557274,53.560288,53.561306,53.562015,53.558241,53.557900,53.557203 };
	double lons[] = { 10.022918,10.021343,10.020297,10.014906,10.015426,10.016568,10.023244,10.022142,10.022632 };

	printf("Overall Distance: %lf", overallDistance(lats,lons,sizeof(lats)/sizeof(lats[0])));
}

double overallDistance(double *lats,double *lons, int arrsize) 
{
	double distance = 0.0;

	for (int i = 0; i < arrsize-1; i++)
	{
		printf("%d %lf\n", i, lats[i]);
		distance = distance + distanceKm(lats[i], lats[i + 1], lons[i], lons[i + 1]);

	}
	return distance;
}

double distanceKm(double lat1, double lat2, double lon1, double lon2)
{
	//reusing from last lab
	lat1 = radianConversion(lat1);
	lon1 = radianConversion(lon1);
	lat2 = radianConversion(lat2);
	lon2 = radianConversion(lon2);

	return 6378.388 * acos(sin((lat1)) * sin(lat2) + cos(lat1) * cos(lat2) * cos((lon2 - lon1)));
}

double radianConversion(double value)
{
	//reusing from last lab
	return value * (PI / 180.0);
}