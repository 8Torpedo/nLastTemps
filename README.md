# nLastTemps
Project that measures 10 last temperatures, giving info about average and checking last 'n' measurements to set correct color on the lpc diode.
#Variables important in code :
<br>const uint8_t TAB_SIZE; - Size of the table with temps.
<br>const uint8_t LAST_TEMPS; - We can set numbers of measurments to be checked with average
<br>uint8_t table[TAB_SIZE]; - Our table with temps.
#How it works
<br>If temperature of LAST_TEMPS is above the average, diode red will be launched on the lpc.
<br>If temperature of LAST_TEMPS is below the average, diode blue will be launched on the lpc.
<br>If temperature of LAST_TEMPS is as the average, diode green will be launched on the lpc.
<br>To run Unity tests, add flag TEST to quick settings of the project.
