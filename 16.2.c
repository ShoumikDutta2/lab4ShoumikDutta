#include<stdio.h>
#include<math.h>
#define PI 3.1416
double distanceKm(double , double , double , double);
double radianConversion(double);
double * longestDistance( double coordinates[7][2]);

int main()
{
	double coordinates[7][2] = { {53.557078,10.023109}, {48.858363,2.294481},{39.562553,2.661947},{ 36.156214, -115.148736},{-22.971177 , -43.182543},{21.281004 , -157.837456},{-28.002695,153.431781} };
	char *names[][100] = {"HAW Hamburg", "Eiffel Tower", "Palma de Mallorca", "Las Vegas", "Copacabana" , "Waikiki Beach", "Surfer's Paradise"};
	double* result = longestDistance(coordinates);
	printf("%s and %s have the largest distance %lf Km.\nYou'd better not walk. Take a flight, instead",names[0][(int)result[1]], names[0][(int)result[2]], result[0]);
	

	

	return 0;
}

double * longestDistance(double coordinates[7][2])
{
	//i need aa 2d array where 0=distance,1=index for 1st place, 2= index of 2nd place
	//sample {{distance,location1,location2}}
	double result[3]; //this result will have the largest distance at 0th index ,2nd and 3rd index is for the index of coordinates
	result[0] = 0.0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			double distance = distanceKm(coordinates[i][0], coordinates[j][0], coordinates[i][1], coordinates[j][1]);

			if (distance > result[0])
			{
				result[0] = distance;
				result[1] = i;
				result[2] = j;
			}
		}


	}

	return result;

}
double distanceKm(double lat1, double lat2, double lon1, double lon2)
{
	lat1 = radianConversion(lat1);
	lon1 = radianConversion(lon1);
	lat2 = radianConversion(lat2);
	lon2 = radianConversion(lon2);

	return 6378.388 * acos(sin((lat1)) * sin(lat2) + cos(lat1) * cos(lat2) * cos((lon2 - lon1)));
}

double radianConversion(double value)
{
	return value * (PI / 180.0);
}