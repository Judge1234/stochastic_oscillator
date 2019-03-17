#include "mavg.h"


/*********************************************************
 *							 *
 *		Interface for K Moving Average		 *
 *							 *
 *********************************************************/


void mavg_init(mavg_ctx *ctx, size_t wsize, size_t dsize) {

	ctx->size = dsize;
	ctx->frame = wsize;
    	ctx->sum = RESET;
    	ctx->arr = calloc(wsize, sizeof(double));
    	ctx->ndata = calloc(dsize, sizeof(double));
	ctx->mavg = calloc(dsize, sizeof(double));
    	assert((ctx->arr) && (ctx->ndata));
}


void mavg_update(mavg_ctx *ctx, const double *data, size_t dsize) {

	double min = data[RESET];
 	double max = data[RESET];
	double K;

	for (int i=0; i<MAVG_RANGE(dsize, ctx->frame); i++) {

		for (int j=0; j<(ctx->frame); j++) {

			ctx->arr[j] = data[i+j];
		}

		min = data[i];
		max = data[i];

		for (int k=0; k<(ctx->frame); k++) { 

			if (ctx->arr[k] <= min) min = ctx->arr[k];

			if (ctx->arr[k] >= max) max = ctx->arr[k];
		}

		K = stoch_form(*(data + i), max, min);
		ctx->ndata[i] = K;
	}

	for (int i=0; i<MAVG_RANGE(dsize, ctx->frame); i++) {

		for (int j=0; j<(ctx->frame); j++) {

			ctx->arr[j] = *(ctx->ndata+(i+j));
			ctx->sum += ctx->arr[j];
		}

		ctx->mavg[i] = (ctx->sum / ctx->frame);
		ctx->sum = RESET;
	}
}


void mavg_display(mavg_ctx *ctx) {
	
	for (int i=0; i<MAVG_RANGE(ctx->size, ctx->frame); i++) {
		printf("%f\n", ctx->mavg[i]);
	}
}


void mavg_destroy(mavg_ctx *ctx) {

	free(ctx->arr);
	free(ctx->ndata);
	free(ctx->mavg); 
}



