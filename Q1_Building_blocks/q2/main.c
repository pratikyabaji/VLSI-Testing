#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main (int argc, char* argv[])
{
	// f (x1 , x2 , x3 , x4 ) = (¬(x1 .x2 )).(¬(x3 .x4 )).(¬(x5 .x6 ))
	bdd_manager bddm = bdd_init();	

	// Initilize variables x1, x2, x3, x4, x5, x6
	bdd x1 = bdd_new_var_last(bddm);
	bdd x2 = bdd_new_var_last(bddm);
	bdd x3 = bdd_new_var_last(bddm);
	bdd x4 = bdd_new_var_last(bddm);
	bdd x5 = bdd_new_var_last(bddm);
	bdd x6 = bdd_new_var_last(bddm);

	// f1 = (¬(x1 .x2 )) f2 = (¬(x3 .x4 )) f3 = (¬(x5 .x6 ))
    bdd f1 = bdd_nand(bddm, x1, x2);
    bdd f2 = bdd_nand(bddm, x3, x4);
    bdd f3 = bdd_nand(bddm, x5, x6);
	
	// g = (¬(x1 .x2 )).(¬(x3 .x4 ))
    bdd g = bdd_and(bddm, f1, f2);

	// f (x1 , x2 , x3 , x4 ) = (¬(x1 .x2 )).(¬(x3 .x4 )).(¬(x5 .x6 ))
    bdd f = bdd_and(bddm, g, f3);

	printf("----------------------------------------------------\n");

	bdd_print_bdd(bddm,f,NULL, NULL,NULL, stdout);

	printf("----------------------------------------------------\n");

	return(0);
}