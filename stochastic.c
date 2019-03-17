#include "mavg.h"


/*********************************************************
 *							 *
 *		Stochastic Oscillator Formula		 *
 *							 *
 *********************************************************/


double stoch_form(double c, double max, double min) {

	double K = STOCH_FORM(c, max, min);

	return K;
}
