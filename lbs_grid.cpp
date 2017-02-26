//
//  lbs_grid.cpp
//  
//
//  Created by Yangyang Hsu on 8/13/16.
//
//

#include "lbs_grid.hpp"

#define LBS_LON_MIN 116
#define LBS_LON_MAX 117
#define LBS_LAT_MIN 39
#define LBS_LAT_MAX 41

#define LBS_ROW_NUM 200
#define LBS_COL_NUM 100



int lbs_grid_init(lbs_grid_t *lbs_grid){
    lbs_grid->row_num= LBS_ROW_NUM;
    lbs_grid->col_num= LBS_COL_NUM;
    lbs_grid->cell_width=(LBS_LON_MAX-LBS_LON_MIN)/LBS_COL_NUM;
    lbs_grid->cell_height=(LBS_LAT_MAX-LBS_LAT_MIN)/LBS_ROW_NUM;
    lbs_grid->lon_min=LBS_LON_MIN;
    lbs_grid->lat_min=LBS_LAT_MIN;
    
    lbs_hashtable_init(&lbs_grid->hash_table);
    
    lbs_grid->cell = (lbs_cell_t *)malloc(lbs_grid->row_num * lbs_grid->col_num * sizeof(lbs_cell_t));
    
    int i;
    for(i = 0; i < lbs_grid->row_num * lbs_grid->col_num; i++)
    {
        lbs_cell_t *head = lbs_grid->cell + i;
        
        lbs_queue_init(&(head->dammy_node.queue));
        pthread_mutex_init(&head->mutex,NULL);
    }
    
    return 0;
};

int lbs_grid_update(lbs_grid_t *lbs_grid,double lon,double lat,uint64_t timestamp);

int lbs_grid_cell_row(lbs_grid_t *lbs_grid,double lat){
    int cell_row=(lat-*lbs_grid.lat_min)*(*lbs_grid.row_num);
    return cell_row;
};

int lbs_grid_cell_col(lbs_grid_t *lbs_grid,double lon){
    int cell_col=(lon-*lbs_grid.lon_min)*(*lbs_grid.cell_col);
    return cell_col;
};

int lbs_grid_cell_id(lbs_grid_t *lbs_grid,int cell_row,int cell_col){
    *lbs_grid.row_num=lbs_grid_cell_row(*lbs_grid,cell_row);
    *lbs_grid.col_num=lbs_grid_cell_col(*lbs_grid,cell_col);
    int cell_id=*lbs_grid.row_num + *lbs_grid.col_num;
    return cell_id;
    
};

void lbs_grid_cell_row_col(lbs_grid_t *lbs_grid, int cell_id, int *cell_row, int *cell_col);

lbs_grid_t *lbs_grid_cell(lbs_grid_t *lbs_grid, int cell_id){
    return hashtable(cell_id);
};
