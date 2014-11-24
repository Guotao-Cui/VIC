#include <vic_def.h>
#include <vic_run.h>
#include <vic_driver_classic.h>

cell_data_struct **
make_cell_data(size_t veg_type_num)

/**********************************************************************
        make_cell_data	Keith Cherkauer		July 9, 1997

   This subroutine makes an array of type cell, which contains soil
   column variables for a single grid cell.

**********************************************************************/
{
    extern option_struct options;

    size_t               i;
    cell_data_struct   **temp;

    temp = (cell_data_struct**) calloc(veg_type_num,
                                       sizeof(cell_data_struct*));
    for (i = 0; i < veg_type_num; i++) {
        temp[i] = (cell_data_struct*) calloc(options.SNOW_BAND,
                                             sizeof(cell_data_struct));
    }
    return temp;
}
