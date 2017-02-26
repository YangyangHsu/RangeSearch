//
//  lbs_mindist_search.cpp
//  
//
//  Created by Yangyang Hsu on 8/15/16.
//
//

#include "lbs_grid.h"
#include "lbs_mindist_search.h"


lbs_res_node_t *mindist_search(lbs_grid_t *lbs_grid,double lon,double lat){
    int cell_row,cell_col,cell_id;
    cell_row = lbs_grid_cell_row(lbs_grid,lon);
    cell_col = lbs_grid_cell_col(lbs_grid,lat);
    cell_id = lbs_grid_cell_id(lbs_grid,cell_row,cell_col);
    
}
