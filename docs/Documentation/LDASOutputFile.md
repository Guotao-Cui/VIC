# LDAS Output File

The LDAS project output file format is designed to output a limited number of variables into the most compressed file format available. Most of the output variables are stored as short int values in a binary file. Short int values require only 2 bytes for storage but do not allow the range of values normally stored so most variables are modified by a constant before storage. Details of the file storage format are discussed on this page.

Each output file contains model output from one grid cell. The files use the naming convention "fluxes_xx.xx_yy.yy", where xx.xx is the latitude, and yy.yy is the longitude. The number of decimal places in the output filename is determined by GRID_DECIMAL in the [global parameter file](GlobalParam.md), while the latitude and longitude values come from the [soil parameter file](SoilParam.md).

## LDAS Output File

## Binary Format

Data is in an Binary column format. To make VIC output in this format, paste the contents of the file output.LDAS_OUTPUT.template, which is included with the VIC Source Code on the [download page](../SourceCode/Code.md), into the bottom of your [global parameter file](GlobalParam.md).

| Column                                                       	| Variable Name 	| Units    	| Type               	| Multiplier 	| Description                                                                                                                                               	|
|--------------------------------------------------------------	|---------------	|----------	|--------------------	|------------	|-----------------------------------------------------------------------------------------------------------------------------------------------------------	|
| 1                                                            	| year          	| year     	| unsigned short int 	| 1          	| Year of current record                                                                                                                                    	|
| 2                                                            	| month         	| month    	| char               	| 1          	| Month of current record                                                                                                                                   	|
| 3                                                            	| day           	| day      	| char               	| 1          	| Day of current record                                                                                                                                     	|
| 4                                                            	| hour          	| hour     	| char               	| 1          	| Hour of current record. Hour is present only if model is run at a sub-daily time step.                                                                    	|
| 5                                                            	| prec          	| mm       	| unsigned short int 	| 100        	| Precipitation                                                                                                                                             	|
| 6                                                            	| evap          	| mm       	| short int          	| 100        	| Evaporation                                                                                                                                               	|
| 7                                                            	| runoff        	| mm       	| float              	| 1          	| Runoff                                                                                                                                                    	|
| 8                                                            	| baseflow      	| mm       	| float              	| 1          	| Baseflow                                                                                                                                                  	|
| 9:(8+Nlayer)                                                 	| moist         	| mm       	| unsigned short int 	| 10         	| Layer moisture content (unfrozen)                                                                                                                         	|
| (9+Nlayer)                                                   	| swq           	| mm       	| unsigned short int 	| 100        	| Snowpack water equivalence                                                                                                                                	|
| (10+Nlayer)                                                  	| net_short     	| W/m2     	| short int          	| 10         	| Net shortwave radiation                                                                                                                                   	|
| (11+Nlayer)                                                  	| in_long       	| W/m2     	| short int          	| 10         	| Incoming longwave radiation                                                                                                                               	|
| (12+Nlayer)                                                  	| r_net         	| W/m2     	| short int          	| 10         	| Net surface radiation                                                                                                                                     	|
| (13+Nlayer)                                                  	| latent        	| W/m2     	| short int          	| 10         	| Latent heat flux                                                                                                                                          	|
| (14+Nlayer)                                                  	| sensible      	| W/m2     	| short int          	| 10         	| Sensible heat flux                                                                                                                                        	|
| (15+Nlayer)                                                  	| grnd_flux     	| W/m2     	| short int          	| 10         	| Ground heat flux                                                                                                                                          	|
| (16+Nlayer)                                                  	| albedo        	| fraction 	| unsigned short int 	| 10000      	| Surface albedo                                                                                                                                            	|
| (17+Nlayer)                                                  	| surf_temp     	| C        	| short int          	| 100        	| Surface temperature                                                                                                                                       	|
| (18+Nlayer)                                                  	| rel_humid     	| %        	| unsigned short int 	| 100        	| Relative humidity                                                                                                                                         	|
| (19+Nlayer)                                                  	| air_temp      	| C        	| short int          	| 100        	| Air temperature                                                                                                                                           	|
| (20+Nlayer)                                                  	| wind          	| m/s      	| unsigned short int 	| 100        	| Wind speed                                                                                                                                                	|
| (21+Nlayer):(20+2\*Nlayer)                                    	| ice           	| mm       	| unsigned short int 	| 10         	| Ice content. Present only if FROZEN_SOIL is TRUE                                                                                                          	|
| (21+2\*Nlayer),(23+2\*Nlayer),...,((19+MAX_FRONTS\*2)+2\*Nlayer) 	| fdepth        	| m        	| unsigned short int 	| 100        	| Depth of frost ( < 0C above this depth ). Frost depth values alternate with thaw depth values for all defined fronts. Present only if FROZEN_SOIL is TRUE 	|
| (22+2\*Nlayer),(24+2\*Nlayer),...,((20+MAX_FRONTS\*2)+2\*Nlayer) 	| tdepth        	| m        	| unsigned short int 	| 100        	| Depth of thaw ( > 0C above this depth ). Thaw depth values alternate with frost depth values for all defined fronts. Present only if FROZEN_SOIL is TRUE  	|