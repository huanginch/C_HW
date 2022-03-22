#ifndef MYIO_H
#define MYIO_H

#define _print(algoName) printf("%s: ", #algoName); _print_relation();

/***************************************
 * _build_map: build relation map	   *
 ***************************************/
void _build_map(void);


/***************************************
 * _print_relation: print the relation *
 ***************************************/
void _print_relation(void);


/***************************************
 * _check_argument: check the argument *
 ***************************************/
void _check_argument(int argc, char **argv);

/***************************************
 * _err_message: show error message	   *
 ***************************************/
void _err_message(int condition);
#endif
