//
//  lbs_mindist_search.h
//  
//
//  Created by Yangyang Hsu on 8/15/16.
//
//

#ifndef lbs_mindist_search_h
#define lbs_mindist_search_h

void fix_up_min_heap( int arr[], int n, int len, int i )
{
	int j = ( i - 1 ) / 2;	// parent index
	int tmp = arr[i];
	while( j >= 0 && tmp < arr[j] )
	{
		arr[i] = arr[j]; i = j; 
		if( j > 0 )
			j = ( j - 1 ) / 2;
		else
			break;
	}
	arr[i] = tmp;
}

void fix_down_min_heap( int arr[], int n, int len, int i ) // n 为数组容量，len为当前长度
{
	int j = 2 * i + 1;
	int tmp = arr[i];
	while( j < len )
	{
		if( j < len - 1 && arr[j + 1] < arr[j] ) 
			++j;
		if( arr[j] < tmp )
		{
			arr[i] = arr[j]; 
			i = j; 
			j = 2 * i + 1;
		}
		else
		{
			break;
		}
	}
	arr[i] = tmp;
}

int insert_min_heap( int arr[], int n, int * len, int x )
{
	if( n == *len ) return -1;
	arr[(*len)++] = x;
	fix_up_min_heap( arr, n, *len, *len - 1 );
	return 1;
}

int top_min_heap( int arr[], int n )
{
	return arr[0];
}

void pop_min_heap( int arr[], int n, int * len )
{
	// assert( *len > 0 );
	arr[0] = arr[--*len];
	fix_down_min_heap( arr, n, *len, 0 );
}


#endif /* lbs_mindist_search_h */
