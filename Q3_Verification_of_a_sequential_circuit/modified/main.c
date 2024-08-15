#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

// Equivalance function
bdd bdd_eque(bdd_manager bddm, bdd p1, bdd p2){
    return bdd_and(bddm, bdd_or(bddm, p1, bdd_not(bddm, p2)), bdd_or(bddm, p2, bdd_not(bddm, p1)));
}

int main (int argc, char* argv[])
{
	bdd_manager bddm = bdd_init();	

    // State machine : A
    // Inputs : for x(k) r(k) k[0:4]
	bdd x0 = bdd_new_var_last(bddm);
	bdd x1 = bdd_new_var_last(bddm);
	bdd x2 = bdd_new_var_last(bddm);
	bdd x3 = bdd_new_var_last(bddm);
	bdd x4 = bdd_new_var_last(bddm);

	bdd r0 = bdd_new_var_last(bddm);
	bdd r1 = bdd_new_var_last(bddm);
	bdd r2 = bdd_new_var_last(bddm);
	bdd r3 = bdd_new_var_last(bddm);
	bdd r4 = bdd_new_var_last(bddm);
    /*******************************/

    bdd x0_not = bdd_not(bddm, x0);
    bdd x1_not = bdd_not(bddm, x1);
    bdd x2_not = bdd_not(bddm, x2);
    bdd x3_not = bdd_not(bddm, x3);
    bdd x4_not = bdd_not(bddm, x4);

    bdd r0_not = bdd_not(bddm, r0);
    bdd r1_not = bdd_not(bddm, r1);
    bdd r2_not = bdd_not(bddm, r2);
    bdd r3_not = bdd_not(bddm, r3);
    bdd r4_not = bdd_not(bddm, r4);

    // for K = 0 
    // states at K=0
    bdd s01 = bdd_one(bddm);
    bdd s11 = bdd_zero(bddm);
    bdd s21 = bdd_zero(bddm);
    bdd s31 = bdd_one(bddm);

    // output at K=0
    bdd f0 = bdd_zero(bddm);

    // for K = 1
    // bdd s02 = bdd_or(bddm, r1, bdd_and(bddm,r1_not,bdd_or(bddm, bdd_and(bddm, x1, s31), bdd_and(bddm, x1_not, s11)))); 
    // bdd s12 = bdd_and(bddm, r1_not, bdd_or(bddm, bdd_and(bddm, x1, s01), bdd_and(bddm, x1_not, s21))); 
    // bdd s22 = bdd_and(bddm, r1_not, bdd_or(bddm, bdd_and(bddm, x1, s11), bdd_and(bddm, x1_not, s31))); 
    // bdd s32 = bdd_and(bddm, r1_not, bdd_or(bddm, bdd_and(bddm, x1, s21), bdd_and(bddm, x1_not, s01)));
    // bdd f1  = bdd_and(bddm, r1_not, bdd_or(bddm, bdd_and(bddm, x1, s31), bdd_and(bddm, x1_not, s11)));

    // for K = 1
    // states at K=1
    bdd s02 = bdd_or(bddm, r1, bdd_and(bddm,r1_not,bdd_or(bddm, bdd_and(bddm, x1, s31), bdd_and(bddm, x1_not, s11)))); 
    bdd s12 = bdd_and(bddm, r1_not, bdd_or(bddm, bdd_and(bddm, x1, s01), bdd_and(bddm, x1_not, s21))); 
    bdd s22 = bdd_and(bddm, r1_not, bdd_or(bddm, bdd_and(bddm, x1, s11), bdd_and(bddm, x1_not, s31))); 
    bdd s32 = bdd_or(bddm, r1, bdd_and(bddm, r1_not, bdd_or(bddm, bdd_and(bddm, x1, s21), bdd_and(bddm, x1_not, s01))));
    // output at K=1
    bdd f1  = bdd_and(bddm, r1_not, bdd_or(bddm, bdd_and(bddm, x1, s31), bdd_and(bddm, x1_not, s11))); 

    // for K = 2
    // states at K=2
    bdd s03 = bdd_or(bddm, r2, bdd_and(bddm,r2_not,bdd_or(bddm, bdd_and(bddm, x2, s32), bdd_and(bddm, x2_not, s12)))); 
    bdd s13 = bdd_and(bddm, r2_not, bdd_or(bddm, bdd_and(bddm, x2, s02), bdd_and(bddm, x2_not, s22))); 
    bdd s23 = bdd_and(bddm, r2_not, bdd_or(bddm, bdd_and(bddm, x2, s12), bdd_and(bddm, x2_not, s32))); 
    bdd s33 = bdd_or(bddm, r2, bdd_and(bddm, r2_not, bdd_or(bddm, bdd_and(bddm, x2, s22), bdd_and(bddm, x2_not, s02))));
    // output at K=2
    bdd f2  = bdd_and(bddm, r2_not, bdd_or(bddm, bdd_and(bddm, x2, s32), bdd_and(bddm, x2_not, s12))); 

    // for K = 3
    // states at K=3
    bdd s04 = bdd_or(bddm, r3, bdd_and(bddm,r3_not,bdd_or(bddm, bdd_and(bddm, x3, s33), bdd_and(bddm, x3_not, s13)))); 
    bdd s14 = bdd_and(bddm, r3_not, bdd_or(bddm, bdd_and(bddm, x3, s03), bdd_and(bddm, x3_not, s23))); 
    bdd s24 = bdd_and(bddm, r3_not, bdd_or(bddm, bdd_and(bddm, x3, s13), bdd_and(bddm, x3_not, s33))); 
    bdd s34 = bdd_or(bddm, r3, bdd_and(bddm, r3_not, bdd_or(bddm, bdd_and(bddm, x3, s23), bdd_and(bddm, x3_not, s03))));
    // output at K=3
    bdd f3  = bdd_and(bddm, r3_not, bdd_or(bddm, bdd_and(bddm, x3, s33), bdd_and(bddm, x3_not, s13))); 

    // for K = 4
    // states at K=4
    // bdd s05 = bdd_or(bddm, r4, bdd_and(bddm,r4_not,bdd_or(bddm, bdd_and(bddm, x4, s34), bdd_and(bddm, x4_not, s14)))); 
    // bdd s15 = bdd_and(bddm, r4_not, bdd_or(bddm, bdd_and(bddm, x4, s04), bdd_and(bddm, x4_not, s24))); 
    // bdd s25 = bdd_and(bddm, r4_not, bdd_or(bddm, bdd_and(bddm, x4, s14), bdd_and(bddm, x4_not, s34))); 
    // bdd s35 = bdd_and(bddm, r4_not, bdd_or(bddm, bdd_and(bddm, x4, s24), bdd_and(bddm, x4_not, s04)));
    // output at K=4
    bdd f4  = bdd_and(bddm, r4_not, bdd_or(bddm, bdd_and(bddm, x4, s34), bdd_and(bddm, x4_not, s14))); 


    // State Machine -B
    // t - state variable g output 
    // for K = 0
    bdd t01 = bdd_zero(bddm);
    bdd t11 = bdd_zero(bddm);
    bdd g0  = bdd_zero(bddm);

    // // for K = 1
    // bdd t02 = bdd_and(bddm, r1_not, bdd_not(bddm, t01));
    // bdd t12 = bdd_and(bddm, r1_not, bdd_or(bddm, bdd_and(bddm, x1, bdd_xor(bddm, t11, t01)), bdd_and(bddm, x1_not,bdd_eque(bddm, t11, t01))));
    // bdd g1  = bdd_and(bddm, r1_not, bdd_or(bddm, bdd_and(bddm,x1, bdd_eque(bddm, t11, t01)), bdd_and(bddm, x1_not, bdd_xor(bddm, t11, t01))));

    bdd t02 = bdd_and(bddm, r1_not, bdd_not(bddm, t01));
    bdd t12 = bdd_and(bddm, r1_not, bdd_or(bddm, bdd_and(bddm, x1, bdd_xor(bddm, t11, t01)), bdd_and(bddm, x1_not,bdd_eque(bddm, t11, t01))));
    bdd g1  = bdd_and(bddm, r1_not, bdd_or(bddm, bdd_and(bddm,x1, bdd_eque(bddm, t11, t01)), bdd_and(bddm, x1_not, bdd_xor(bddm, t11, t01))));
    
    bdd t03 = bdd_and(bddm, r2_not, bdd_not(bddm, t02));
    bdd t13 = bdd_and(bddm, r2_not, bdd_or(bddm, bdd_and(bddm, x2, bdd_xor(bddm, t12, t02)), bdd_and(bddm, x2_not,bdd_eque(bddm, t12, t02))));
    bdd g2  = bdd_and(bddm, r2_not, bdd_or(bddm, bdd_and(bddm,x2, bdd_eque(bddm, t12, t02)), bdd_and(bddm, x2_not, bdd_xor(bddm, t12, t02))));

    bdd t04 = bdd_and(bddm, r3_not, bdd_not(bddm, t03));
    bdd t14 = bdd_and(bddm, r3_not, bdd_or(bddm, bdd_and(bddm, x3, bdd_xor(bddm, t13, t03)), bdd_and(bddm, x3_not,bdd_eque(bddm, t13, t03))));
    bdd g3  = bdd_and(bddm, r3_not, bdd_or(bddm, bdd_and(bddm,x3, bdd_eque(bddm, t13, t03)), bdd_and(bddm, x3_not, bdd_xor(bddm, t13, t03))));

    // bdd t05 = bdd_and(bddm, r4_not, bdd_not(bddm, t04));
    // bdd t15 = bdd_and(bddm, r4_not, bdd_or(bddm, bdd_and(bddm, x4, bdd_xor(bddm, t14, t04)), bdd_and(bddm, x4_not,bdd_eque(bddm, t14, t04))));
    bdd g4  = bdd_and(bddm, r4_not, bdd_or(bddm, bdd_and(bddm,x4, bdd_eque(bddm, t14, t04)), bdd_and(bddm, x4_not, bdd_xor(bddm, t14, t04))));

    // Checking the output is same in for each k up-till k 0 -> 4 
    bdd y = bdd_or(bddm, bdd_or(bddm, bdd_xor(bddm, f1,g1), bdd_xor(bddm, f2,g2)), bdd_or(bddm, bdd_xor(bddm, f3,g3), bdd_xor(bddm, f4,g4)));

    bdd_print_bdd(bddm,y,NULL, NULL,NULL, stdout);
	return(0);
}

