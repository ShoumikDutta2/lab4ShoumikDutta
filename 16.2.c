#include<stdio.h>
#include<math.h>
#define PI 3.1416

// function prototypes
double distanceKm(double , double , double , double);
double radianConversion(double);
double longestDistance(double[7][2], int*, int*);

int main()
{
	double coordinates[7][2] = { {53.557078,10.023109}, {48.858363,2.294481},{39.562553,2.661947},{ 36.156214, -115.148736},{-22.971177 , -43.182543},{21.281004 , -157.837456},{-28.002695,153.431781} };
	char *names[][100] = {"HAW Hamburg", "Eiffel Tower", "Palma de Mallorca", "Las Vegas", "Copacabana" , "Waikiki Beach", "Surfer's Paradise"};
	int locationA, locationB;
	//calling longestDistance function to get the longest distance and update the values of locationA and locationB
	double result = longestDistance(coordinates,&locationA,&locationB);

	printf("%s and %s have the largest distance %lf Km.\nYou'd better not walk. Take a flight, instead",names[0][locationA], names[0][locationB], result);

	return 0;
}

double longestDistance(double coordinates[7][2], int *locationA,int *locationB)
{
	double result=0.0; 
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			double distance = distanceKm(coordinates[i][0], coordinates[j][0], coordinates[i][1], coordinates[j][1]);

			if (distance > result)
			{
				result = distance;
				*locationA = i;
				*locationB = j; 
			}
		}
	}
	return result;
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