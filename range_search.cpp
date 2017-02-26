//
//  range_search.cpp
//  
//
//  Created by Yangyang Hsu on 8/15/16.
//
//

#include "lbs_grid.h"

Last login: Mon Aug 15 11:08:00 on ttys004
Yangyangs-MacBook-Pro:~ Yangyang$ ssh sx8@123.57.237.171
sx8@123.57.237.171's password:
Last login: Mon Aug 15 11:08:00 2016 from 159.226.43.94
-bash: warning: setlocale: LC_CTYPE: cannot change locale (UTF-8): No such file or directory
perl: warning: Setting locale failed.
perl: warning: Please check that your locale settings:
LANGUAGE = (unset),
LC_ALL = (unset),
LC_CTYPE = "UTF-8",
LANG = "en_US.UTF-8"
are supported and installed on your system.
perl: warning: Falling back to the standard locale ("C").
[sx8@iZ25ebhj8ufZ ~]$ cd lbs/server/grid
[sx8@iZ25ebhj8ufZ grid]$ ls
Makefile        lbs_grid.h              lbs_index.cpp         mf.cpp
lbs_defs.h      lbs_hashtable.cpp       lbs_index.h
lbs_distance.h  lbs_hashtable.h         lbs_queue.h
lbs_grid.cpp    lbs_hashtable_test.cpp  lbs_range_search.cpp
[sx8@iZ25ebhj8ufZ grid]$ vim lbs_defs.h
[sx8@iZ25ebhj8ufZ grid]$ vim lbs_index,h
[sx8@iZ25ebhj8ufZ grid]$ vim lbs_index.h
[sx8@iZ25ebhj8ufZ grid]$ vim lbs_defs.h
[sx8@iZ25ebhj8ufZ grid]$ vim lbs_index.h
[sx8@iZ25ebhj8ufZ grid]$ vim lbs_rangesearch.cpp
[sx8@iZ25ebhj8ufZ grid]$ vim lbs_range_search.cpp

16           int cell_id_search;
17           cell_id_search = lbs_grid_cell_id(lbs_grid,lon_search,lat_search);
18
19           lbs_cell_t *head = lbs_grid->cell + cell_id_search;
20           lbs_cell_t *p = (lbs_cell_t *)head->dammy_node.queue.next;
21           for (p != head){
    22             if ( p->lon >= lon1 && p->lon <= lon2 && p->lat >= lat1 && p->la    t <= lat2){
        23               lbs_res_node_t *insert_p;
        24               insert_p = (lbs_res_node_t *)malloc (sizeof(lbs_res_node_t));
        25               insert_p->lon = p->dammy_node.lon;
        26               insert_p->lat = p->dammy_node.lat;
        27               insert_p->id = p->dammy_node.id;
        28               insert_p->timestamp = p->dammy_node.timestamp;
        29               lbs_queue_insert_head(lbs_res_node,insert_p);
        30             }
    31             p = (lbs_grid_t *)p->dammy_node.queue.next;
    32           }
33         }
34       }
35
36       return lbs_res_node;
"lbs_range_search.cpp" 37L, 1735C                             36,7          93%
