

1 #include "lbs/server/grid/heapsort.h"
2 #include "lbs/server/grid/lbs_index.h"
3 int lbs_nnheap_init(lbs_nnheap_t* lbs_nnheap, uint32_t capacity){
    4     lbs_nnheap->capacity = capacity;
    5     lbs_nnheap->size = 0;
    6     lbs_nnheap->heap_node = (lbs_heapnode_t*)malloc(sizeof(lbs_heapnode_t)*capacity);
    7
    8     return 0 ;
    9 }
10
11 int lbs_nnheap_insert(lbs_nnheap_t* lbs_nnheap,lbs_mov_node_t* lbs_mov_node,int cell_id,uint8_t is_grid,double distance,uint32_t* ca    pacity){
    12     int j,i;//j?~M?~H??~J~B?~B??~K?| ~G?~Li为?~P?~J~B?~B??~K?| ~G
    13     double  temp,dad_distance;
    14     lbs_nnheap->size = lbs_nnheap->size + 1;
    15     if(lbs_nnheap->size >= capacity){
        16             *capacity = *capacity * 2;
        17             lbs_nnheap->heap_node = (lbs_heapnode_t*)realloc(lbs_nnheap->heap_node,sizeof(lbs_heapnode_t)*(*capacity));
        18     }
    19     i = lbs_nnheap->size;
    20     (lbs_nnheap->heap_node + i)->node = lbs_mov_node;
    21     (lbs_nnheap->heap_node + i)->cell_id = cell_id;
    22     (lbs_nnheap->heap_node + i)->is_grid = is_grid;
    23     (lbs_nnheap->heap_node + i)->distance = distance;
    24
    25     lbs_heap_adjustment_insert(lbs_nnheap,i);
    26    return 0;
    27 }
28
29 /**?~N??~O~V?~]离?~\~@?~O?~Z~Dlbs_heapnode_t */
30 lbs_heapnode_t* lbs_nnheap_top(lbs_nnheap_t* lbs_nnheap){
    31     return (lbs_nnheap->heap_node + 1);
    32 }
33
34 /


    void lbs_heap_adjustment_insert(lbs_nnheap_t* lbs_nnheap, uint32_t i){
        54     temp =(lbs_nnheap->heap_node + i)->distance;
        55     j = lbs_nnheap->size/2;     //?~H??~S?~B?
        56     dad_distance = ( lbs_nnheap->heap_node + j )->distance;  //?~H??~J~B?~B??~Z~D?~]离
        57     while ( j >=0 && i!=0 )
            58     {
                59         if (dad_distance <= temp) //?~H??~J~B?~B??~T?~O??~P?~J~B?~B??~]离?~[??~_?
                    60             break;
                61         lbs_swap(lbs_nnheap->heap_node+i,lbs_nnheap->heap_node+j);
                62         i=j;
                63         j = i/ 2;
                64     }
        65 }
    66
    67 void lbs_swap(lbs_heapnode_t* lbs_heapnode1, lbs_heapnode_t* lbs_heapnode2){
        68     lbs_heapnode_t swap;
        69     swap = *lbs_heapnode1;
        70     *lbs_heapnode1 = *lbs_heapnode2;
        71     *lbs_heapnode2 = swap;
        72 }



    void lbs_nnheap_pop(lbs_nnheap_t* lbs_nnheap){
        36     ( lbs_nnheap->heap_node + 1 ) = lbs_nnheap->heap_node + lbs_nnheap->size;
        37     lbs_nnheap->size = lbs_nnheap->size - 1;
        38     int child, i = 1, temp;
        39     for(temp = (( lbs_nnheap->heap_node + 1 )->distance); 2*i < lbs_nnheap->size ; i=child)
            40     {
                41          child=2*i;
                42          if(child<(lbs_nnheap->size - 1)&&((lbs_nnheap->heap_node+child+1)->distance)>((lbs_nnheap->heap_node + child)->distance )){    //?~T?~C?~S?个孩?~P大
                    43               child++;
                    44          }
                45          if(temp<( lbs_nnheap->heap_node + child)->distance )){//?~B?~^~\?~T?~G?己?~Z~D?~\~@大?~Z~D孩?~P?~O?~L就交?~M?
                    46               lbs_swap(lbs_nnheap->heap_node+child,lbs_nnheap->heap_node+i)
                    47          }
                48          else//?~B?~^~\?~T?~\~@大?~Z~D孩?~P?~X大?~L就?~M交?~M?               
                    49              break;  
                50     }  
        51 }