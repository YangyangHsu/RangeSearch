//
//  lbs_grid.hpp
//  
//
//  Created by Yangyang Hsu on 8/13/16.
//
//

#ifndef lbs_grid_hpp
#define lbs_grid_hpp

#include <pthread.h>

#include "server/grid/lbs_defs.h"
#include "server/grid/lbs_hashtable.h"

typedef struct lbs_cell_s {
    lbs_mov_mode_t dammy_node;
    
    pthread_mutex_t mutex;
} lbs_cell_t;

typedef struct lbs_grid_s {
    int row_num;
    int col_num;
    double cell_width;
    double cell_height;
    double lon_min;
    double lat_min;
    lbs_hashtable_t hash_table;
    lbs_cell_t *cell;
} lbs_grid_t ;

int lbs_grid_init(lbs_grid_t *lbs_grid, double lon1,double lon2,double lat1,double lat2);

int lbs_grid_update(lbs_grid_t *lbs_grid,double lon,double lat,uint64_t timestamp);

int lbs_grid_cell_row(lbs_grid_t *lbs_grid,double lat);

int lbs_grid_cell_col(lbs_grid_t *lbs_grid,double lon);

int lbs_grid_cell_id(lbs_grid_t *lbs_grid,int cell_row,int cell_col);

void lbs_grid_cell_row_col(lbs_grid_t *lbs_grid, int cell_id, int *cell_row, int *cell_col);

lbs_grid_t *lbs_grid_cell(lbs_grid_t *lbs_grid, int cell_id);

#endif /* lbs_grid_hpp */

