
	
	
	/*
	To do:
		Button interrupt at end of set, to trigger graph
		Second interrupt to start new set.
		Calculate time between first and last measurement.
		Get clip for barbell.
		Evaluate power consumption and measurement accuracy
		Write OLED driver part.
	*/
	double 	dt = 1/800;   // May need to change this to vary with the gap between reads, could work out total time and divide by n_samples to get dt.
	int		time = 0;
	double		v0 = 0;
	int		n_samples = 1000;
	int		index = 0;
	
	int16_t	sensorData[3] = {0};
	
	double		acc_x_arr[n_samples] = {0};
	double		acc_y_arr[n_samples] = {0};
	double		acc_z_arr[n_samples] = {0};
	double		vel_x_arr[n_samples] = {0};
	double		vel_y_arr[n_samples] = {0};
	double		vel_z_arr[n_samples] = {0};

	

	while(index < n_samples)				// Maybe a for loop if outside warp menu, but no need otherwise.
	{
		sensorData = fetchSensorDataMMA8451Q();	// Similar to printSensorData function
		
		acc_x_arr[index] = sensorData[0];
		acc_y_arr[index] = sensorData[1];
		acc_z_arr[index] = sensorData[2];
		
		index++;
	}
	
	// Interrupt to trigger following stage
	
	index = 0;
	
	
	while(index < n_samples - 1)				// Should be a for loop
	{
	
		// Work out which way gravity is and subtract/add to acc values accordingly
	
		vel_x_arr[index+1] = vel_x_arr[index] + acc_x_arr[index]*dt;
		vel_y_arr[index+1] = vel_y_arr[index] + acc_y_arr[index]*dt;
		vel_z_arr[index+1] = vel_z_arr[index] + acc_z_arr[index]*dt;
		
		index++
	}
				
	// Display graph or numbers on OLED
	

	// Interrupt to restart set
	
