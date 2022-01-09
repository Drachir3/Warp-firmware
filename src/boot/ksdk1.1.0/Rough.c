
	
	
/*
To do:
	Calibrate sensor.
	Button interrupt at end of set, to trigger graph
	Second interrupt to start new set.
	Calculate time between first and last measurement.
	Get clip for barbell.
	Evaluate power consumption and measurement accuracy
	Write OLED driver part.
*/

#include <math.h>

// Start of big loop, triggered by user input (capacitive touch sensor)
while (1)
{
	double 	dt = 1/800;   // May need to change this to vary with the gap between reads, could work out total time and divide by n_samples to get dt.
	int		time = 0;
	double		v0 = 0;
	int		n_samples = 5000;
	int		index = 0;

	int16_t	sensorData[3] = {0};
	double		g_acc[3] = {0};

	double		acc_x_arr[n_samples] = {0};		// Probably too much memory; use pointers to use same memory for later arrays.
	double		acc_y_arr[n_samples] = {0};
	double		acc_z_arr[n_samples] = {0};
	double		vel_x_arr[n_samples] = {0};
	double		vel_y_arr[n_samples] = {0};
	double		vel_z_arr[n_samples] = {0};
	double		vel_arr[n_samples] = {0};

	double		maxVelocityPositive[50] = {0};
	double		maxVelocitynegative[50] = {0};		// Probably find a more elegant way to choose the length.
	double		currentMaxVelocityPos = 0;
	double		currentMaxVelocityNeg = 0;
	double		thresh = 0.2;					// Need to decide what this should be
	int8_t		isPos = 1;





	g_acc = fetchSensorDataMMA8451Q();			// Offsets due to gravity, to be removed from later readings. 


	while(index < n_samples)				// Maybe a for loop if outside warp menu, but no need otherwise.
	{
		sensorData = fetchSensorDataMMA8451Q();	// Similar to printSensorData function
		
		// Need to convert accelerometer values to SI units
		
		acc_x_arr[index] = sensorData[0] - g_acc[0];
		acc_y_arr[index] = sensorData[1] - g_acc[1];
		acc_z_arr[index] = sensorData[2] - g_acc[2];
		
		index++;
		
		if(//user input)
		{
			break;
		}
	}

	n_samples = index;
	index = 0;


	while(index < n_samples - 1)				// Should be a for loop
	{

		vel_x_arr[index+1] = vel_x_arr[index] + acc_x_arr[index]*dt;
		vel_y_arr[index+1] = vel_y_arr[index] + acc_y_arr[index]*dt;
		vel_z_arr[index+1] = vel_z_arr[index] + acc_z_arr[index]*dt;
		
		// Use angle instead, so velocity isn't a vector
		vel_arr[index+1] = sqrt(pow(vel_x_arr[index+1],2) + pow(vel_y_arr[index+1],2) + pow(vel_z_arr[index+1],2))	// Combined velocity vector
		
		index++
	}

	// Process to identify max velocities
	for(int i=0; i < n_samples; i++)
	{
		if((vel_arr[i] > currentMaxVelocityPos) & (vel_arr[i] > thresh))
			{
				currentMaxVelocityPos = vel_arr[i]
				
			}
			
		else if((vel_arr[i] < currentMaxVelocityNeg) & (vel_arr[i] < -thresh))
			{
				currentMaxVelocityNeg = vel_arr[i]
			}
	}	



	// Display graph or numbers on OLED
	drawGraph();

	// Interrupt to restart set
	while(1)
	{
		if(//user input)
		{
			break;
		}
	}
}	
