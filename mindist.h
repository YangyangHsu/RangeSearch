//
//  mindist.h
//  
//
//  Created by Yangyang Hsu on 8/15/16.
//
//

#ifndef lbs_mindist_h
#define lbs_mindist_h

#include "server/grid/lbs_defs.h"
#include "server/grid/lbs_distance.h"

#define CAPACITY 1000000

typedef struct lbs_heapnode_s {
    double distance;
    uint8_t is_grid;
    int cell_id;
    lbs_mov_node_t *node;
} lbs_heapnode_t;

typedef struct lbs_nnheap_s {
    uint32_t capacity;
    uint32_t size;
    lbs_heapnode_t *heap_nodes;
} lbs_nnheap_t;

int lbs_nnheap_init(lbs_nnheap_t *lbs_nnheap);

int lbs_nnheap_insert(lbs_heapnode_t *lbs_nnheap,lbs_mov_node_t *lbs_mov_node, int cell_id,uint8_t is_grid,double distance);

lbs_heapnode_t *lbs_nnheap_top(lbs_heapnode_t* lbs_nnheap);

void lbs_nnheap_pop(lbs_nnheap_t *lbs_nnheap);

#endif /* lbs_mindist_h */
