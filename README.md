# nLastTemps
Project that measures 10 last temperatures, giving info about average and checking last 'n' measurements to set correct color on the lpc diode.
Variables important in code :
  const uint8_t TAB_SIZE = 10; - Size of the table with temps.
	const uint8_t LAST_TEMPS = 4; - We can set numbers of measurments to be checked with average
	uint8_t table[TAB_SIZE]; - Our table with temps.
	
If temperature of LAST_TEMPS is above the average, diode red will be launched on the lpc.
If temperature of LAST_TEMPS is below the average, diode blue will be launched on the lpc.
If temperature of LAST_TEMPS is as the average, diode green will be launched on the lpc.
	
To run Unity tests, add flag TEST to quick settings of the project.
