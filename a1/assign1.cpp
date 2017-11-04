#include "assign1.h"
#include <math.h>

Spatial pathLength(Point path[], int numPoints){
 Spatial lengthOfPath = 0;
	if(numPoints == 1)
	{
		return 0;
	}
	else
	{
		for(int i = 0; i < numPoints-1; i++)
		{
		 lengthOfPath += sqrt(pow((path[i+1].x - path[i].x),2) + pow((path[i+1].y - path[i].y),2));
		}
		return lengthOfPath;
	}
}
