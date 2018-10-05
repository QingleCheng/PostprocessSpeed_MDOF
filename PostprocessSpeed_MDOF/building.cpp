#include "building.h"

Building::Building()
{

}
void Building::getDrift()
{
	double **InterStory;
	double *MaxInter;
	InterStory = new double*[nStory];
	MaxInter = new double[nStory];
	for (int i = 0; i < nStory; i++)
		MaxInter[i] = 0.0;
	for (int i = 0; i < nStory; i++)
	{ 
		InterStory[i] = new double[Ntime];
		for (int j=0;j<Ntime;j++)
		{
			if (i==0)
			{
				InterStory[i][j] = abs(dispX[i][j])/storyheight;
			}
			else {
				InterStory[i][j] = abs(dispX[i][j]- dispX[i-1][j])/storyheight;
			}	
			if (MaxInter[i]<InterStory[i][j])
			{
				MaxInter[i] = InterStory[i][j];
			}

			if (i == 0)
			{
				InterStory[i][j] = abs(dispY[i][j]) / storyheight;
			}
			else {
				InterStory[i][j] = abs(dispY[i][j] - dispY[i - 1][j]) / storyheight;
			}
			if (MaxInter[i] < InterStory[i][j])
			{
				MaxInter[i] = InterStory[i][j];
			}
			
		}
		edps.IDR.push_back(MaxInter[i]);
	}
}
void Building::getPFA()
{
	double *MaxPFA;
	MaxPFA = new double[nStory];
	for (int i = 0; i < nStory; i++)
		MaxPFA[i] = 0.0;
	PGAX < PGAY ? edps.PFA.push_back(PGAY) : edps.PFA.push_back(PGAX);
	for (int i = 0; i < nStory; i++)
	{
		for (int j = 0; j < Ntime; j++)
		{
			if (MaxPFA[i] < abs(accX[i][j]))
			{
				MaxPFA[i] = abs(accX[i][j]);
			}
			if (MaxPFA[i] < abs(accY[i][j]))
			{
				MaxPFA[i] = abs(accY[i][j]);
			}
			
		}
		edps.PFA.push_back(MaxPFA[i]);
	}
}





