//
//  mindist.cpp
//  
//
//  Created by Yangyang Hsu on 8/15/16.
//
//

#include <lbs_mindist.h>


int lbs_nnheap_init(lbs_nnheap_t *lbs_nnheap){
    lbs_nnheap->capacity = CAPACITY;
    lbs_nnheap->size = 0;
    lbs_nnheap->head_nodes = (lbs_heapnode_t *)malloc(sizeof(lbs_heapnode_t));
    return 0;
}

int lbs_nnheap_insert(lbs_nnheap_t *lbs_nnheap,lbs_mov_node_t *lbs_mov_node, int cell_id,uint8_t is_grid,double distance){
    lbs_nnheap->size += 1;
    
    lbs_heapnode_t *node = (lbs_heapnode_t *)malloc(sizeof(lbs_heapnode_t));
    
    lbs_nnheap->heap_node = (lbs_heapnode_t*)malloc(lbs_nnheap->heap_node,sizeof(lbs_heapnode_t)*(*capacity));
    
    int i = lbs_nnheap->size;
    (lbs_nnheap->heap_node + i)->node = lbs_mov_node;
    (lbs_nnheap->heap_node + i)->cell_id = cell_id;
    (lbs_nnheap->heap_node + i)->is_grid = is_grid;
    (lbs_nnheap->heap_node + i)->distance = distance;
    
    lbs_nnheap->(lbs_nnheap->heap_node + size) = node;
    
    //int i = lbs_nnheap->size;
    int j = ( i - 1 ) / 2;
    int tmp = (lbs_nnheap->heap_nodes + i).distance;
    while( j >= 0 && tmp < (lbs_nnheap->heap_nodes + j).distance )
    {
        (lbs_nnheap->heap_nodes + i).distance = (lbs_nnheap->heap_nodes + j).distance;
        i = j;
        if( j > 0 )
            j = ( j - 1 ) / 2;
        else
            break;
    }
    (lbs_nnheap->heap_nodes + i).distance = tmp;
    
    return 0;
}

lbs_heapnode_t *lbs_nnheap_top(lbs_nnheap_t* lbs_nnheap){
    lbs_heapnode_t *top = (lbs_nnheap->heap_nodes + 1);
    return top;
}

void lbs_nnheap_pop(lbs_nnheap_t *lbs_nnheap){
    (lbs_nnheap->heap_node + 1) = lbs_nnheap->heap_node + lbs_nnheap->size;
    lbs_nnheap->size = lbs_nnheap->size - 1;
    
    int j = 2 * i + 1;
    int tmp = (lbs_nnheap->heap_nodes + i).distance;
    while( j < lbs_nnheap->size )
    {
        if( j < lbs_nnheap->size - 1 && (lbs_nnheap->heap_nodes + j+1).distance  < (lbs_nnheap->heap_nodes + j).distance )
            ++j;
        if( (lbs_nnheap->heap_nodes + j).distance < tmp )
        {
            (lbs_nnheap->heap_nodes + i).distance  = (lbs_nnheap->heap_nodes + j).distance;
            i = j;
            j = 2 * i + 1;
        }
        else
        {
            break;
        }
    }
    lbs_nnheap->heap_nodes[i] = tmp;

}


 lbs_queue_insert_head(&out->queue,&insert_p->queue);

