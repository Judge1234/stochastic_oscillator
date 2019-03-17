#include "mavg.h"


/*********************************************************
 *							 *
 *		   Implementation Demo		 	 *
 *							 *
 *********************************************************/


int main(int argc, char *argv[]) {
	
	mavg_ctx	ctx;
	size_t		wframe = 7; 
	int		dlen = 35;
	const double	sample_data[]; = {2.31, 3.45, 4.09, 5.15, 6.25, 5.01, 3.10, 2.23, 0.98, 2.40, 3.11, 4.90, 5.67, 7.56, 8.99, 12.0, 9.55, 7.9, 6.1, 5.01, 4.44, 3.44, 6.09, 2.43, 5.09, 8.91, 10.09, 12.91, 10.00, 9.08, 7.55, 5.43, 3.34, 2.23, 8.10};

	mavg_init(&ctx, wframe, dlen);
	mavg_update(&ctx, sample_data, dlen);
	mavg_display(&ctx); 
	mavg_destroy(&ctx); 

	return (EXIT_SUCCESS);
}
