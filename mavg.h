#ifndef __MAVG__
#define __MAVG__


/*********************************************************
 *							 *
 *	    Stochastic Oscillator Header File 		 *
 *							 *
 *    Prototypes for mavg_interface.c & stochastic.c	 *
 *							 *
 *********************************************************/


#define RESET 0
#define MAVG_RANGE(dlen, wframe) ((dlen)-(wframe-1))
#define STOCH_FORM(c, max, min) (((c-min) / (max-min)) *100)


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct __mavg_ctx__ {	

	size_t size;	// Length of mavg_ctx->ndata
	size_t frame;	// Window size
	double sum; 	// Sum of windowed K values
	double *arr;	// Array for moving window
	double *ndata;	// Array of K values
	double *mavg;	// Moving average of K values

} mavg_ctx;


double stoch_form(double c, double max, double min);
void mavg_init(mavg_ctx *ctx, size_t wsize, size_t dsize);
void mavg_update(mavg_ctx *ctx, const double *data, size_t dsize);
void mavg_display(mavg_ctx *ctx);
void mavg_destroy(mavg_ctx *ctx);


#endif
