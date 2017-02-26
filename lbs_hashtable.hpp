//
//  lbs_hashtable.hpp
//  
//
//  Created by Yangyang Hsu on 8/14/16.
//
//

#ifndef lbs_hashtable_hpp
#define lbs_hashtable_hpp

#include <pthread.h>
#include "server/grid/lbs_defs.h"

typedef struct lbs_hashnode_s {
    lbs_queue_t queue;
    lbs_mov_node_t *mov_node;
    int cell_id;
} lbs_hashnode_t;

typedef struct lbs_hashtable_s {
    pthread_mutex_t mute;
    int size;
    int capacity;
    lbs_hashnode_t *hash_nodes;
} lbs_hashtable_t;

int lbs_hashtable_init( lbs_hashtable_t *lbs_hashtable);

int lbs_hashtable_destroy(*lbs_hash_table);

int lbs_hashtable_set(lbs_hashtable_t *lbs_hashtable, uint32_t id, lbs_mov_node_t * lbs_hashnode_t);

lbs_hashnode_t *lbs_hashtable_get(lbs_hashtable_t *lbs_hash_table,uint32_t id);

#endif /* lbs_hashtable_hpp */
