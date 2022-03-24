#ifndef MYDS_H
#define MYDS_H

/*************************************
 * _stack_push: add element to stack *
 *************************************/
void _stack_push(int value);


/*************************************
 * _queue_push: add element to queue *
 *************************************/
void _queue_push(int value);


/*************************************
 * _stack_pop: remove element		 *
 *			   from stack 			 *
 *************************************/
void _stack_pop(void);


/*************************************
 * _stack_pop: remove element		 *
 *			   from queue 			 *
 *************************************/
void _queue_pop(void);


/*************************************
 * _stack_top: get elements from	 *
 *			   stack 			 	 *
 *************************************/
int _stack_top(void);


/*************************************
 * _queue_front: get elements from	 *
 *			     queue	 			 *
 *************************************/
int _queue_front(void);


/*************************************
 * _stack_empty: check the stack 	 *
 *			     state	 			 *
 *************************************/
BOOL _stack_empty(void);


/*************************************
 * _queue_empty: check the queue 	 *
 *			     state	 			 *
 *************************************/
BOOL _queue_empty(void);

#endif
