#ifndef MYALGO_H
#define MYALGO_H
#define MAX_algorithm 2

extern char algo_name[MAX_algorithm][10];
extern int relation_map[MAX_person][MAX_person];

/************************************
 * _map_init: init the relatopn map  *
*************************************/
void _map_init(void);

/************************************
 * algo_init: init the variable     *
 *            use for algo          *
*************************************/
void algo_init(void);

/************************************
 * _DFS: use Depth First Search     *
 *       to find the relation       *
*************************************/
BOOL _DFS(int now_person, int to_find);

/************************************
 * _DFS: use Breadth First Search   *
 *       to find the relation       *
*************************************/
BOOL _BFS(int now_person, int to_find);

#endif
