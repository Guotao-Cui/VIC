#include <vic_def.h>
#include <vic_run.h>
#include <vic_driver_classic.h>

all_vars_struct
make_all_vars(size_t nveg)

/**********************************************************************
        read_all_vars	Keith Cherkauer		May 21, 1996

   This routine creates an array of structures that contain information
   about a cell's states and fluxes.

   modifications:
   11-18-02 Modified to allocate vegetation variables for the
           wetland vegetation class.                             LCB
   01-Nov-04 Updated arglist to make_energy_bal() as part of fix for
            QUICK_FLUX state file compatibility.		TJB
   2006-Nov-07 Removed LAKE_MODEL option.  TJB
   2009-Jul-31 Removed extra lake/wetland tile.			TJB
   2014-Mar-28 Removed DIST_PRCP option.					TJB
**********************************************************************/
{
    all_vars_struct      temp;
    size_t               Nitems;

    Nitems = nveg + 1;

    temp.snow = make_snow_data(Nitems);
    temp.energy = make_energy_bal(Nitems);
    temp.veg_var = make_veg_var(Nitems);
    temp.cell = make_cell_data(Nitems);

    return (temp);
}
