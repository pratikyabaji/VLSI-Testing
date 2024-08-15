#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main (int argc, char* argv[])
{
	bdd_manager bddm = bdd_init();	

	// Initilize variables u0, u1, u2, u3
	bdd u0 = bdd_new_var_last(bddm);
	bdd u1 = bdd_new_var_last(bddm);
	bdd u2 = bdd_new_var_last(bddm);
	bdd u3 = bdd_new_var_last(bddm);
    /********************************************/

    // Negation of all the variables
    bdd u0_not = bdd_not(bddm, u0);
    bdd u1_not = bdd_not(bddm, u1);
    bdd u2_not = bdd_not(bddm, u2);
    bdd u3_not = bdd_not(bddm, u3);
    /********************************************/

    // Care-combinations : c = ~u3.~u2.~u0 + ~u0.~u1.~u2 + ~u2.~u3.~u1 + ~u0.~u1.~u3
    // Care-combinations : c = ~u1.~u0.(~u2 + ~u3) + ~u2.~u3.(~u1+~u0)
    bdd a1 = bdd_or(bddm, u2_not, u3_not);
    bdd a2 = bdd_and(bddm, u1_not, u0_not);
    bdd a3 = bdd_and(bddm, a1, a2);

    bdd a4 = bdd_or(bddm, u1_not, u0_not);
    bdd a5 = bdd_and(bddm, u2_not, u3_not);
    bdd a6 = bdd_and(bddm, a4, a5);

    bdd c = bdd_or(bddm, a3, a6); 
    /********************************************/


    // c1 - Specification = c1 = c.(u3 + ~u3.u2)
    bdd f1 = bdd_and(bddm, u3_not, u2);

    bdd f = bdd_or(bddm, f1, u3);
    bdd c1_spec = bdd_and(bddm, f, c);
    /********************************************/

	printf("----------------------------------------------------\n");

	bdd_print_bdd(bddm,c1_spec,NULL, NULL,NULL, stdout);

	printf("----------------------------------------------------\n");

    // c1 - Implementation = c1 = c.(u3 + u2)
    bdd g  = bdd_or(bddm, u3, u2); 
    bdd c1_imp = bdd_and(bddm, g, c);
    /********************************************/

    printf("----------------------------------------------------\n");

	bdd_print_bdd(bddm,g,NULL, NULL,NULL, stdout);

	printf("----------------------------------------------------\n");

    if(c1_spec == c1_imp){
        printf("Implementation == Specification\n");
    }
    else{
        printf("Implementation != Specification\n");
    }
	return(0);
}

