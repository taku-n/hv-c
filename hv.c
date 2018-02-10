#include <math.h>

void hv(const double CLOSE[], double hv[], const int N, const int PERIOD,
		const int TIMEFRAME);
// Historical Volatility

double sd(const double CLOSE[], const int PERIOD, const int I);
// Standard Deviation

double variance(const double CLOSE[], const int PERIOD, const int I);
double average(const double CLOSE[], const int PERIOD, const int I);

void hv(const double CLOSE[], double hv[], const int N, const int PERIOD,
		const int TIMEFRAME)
{
	static int last_timeframe  = 0;
	static int last_calculated = 0;
	       int i;

	if (last_timeframe != TIMEFRAME) {
		last_calculated = 0;

		last_timeframe = TIMEFRAME;
	}

	if (last_calculated > PERIOD - 1) {
		i = last_calculated;
	} else {
		i = PERIOD - 1;
	}

	for (; i < N; i++) {
		hv[i] = sd(CLOSE, PERIOD, i);

		last_calculated = i;
	}
}

double sd(const double CLOSE[], const int PERIOD, const int I)
{
	return sqrt(variance(CLOSE, PERIOD, I));
}

double variance(const double CLOSE[], const int PERIOD, const int I)
{
	const double ave = average(CLOSE, PERIOD, I);
	      double sum = 0.0;

	for (int j = I - (PERIOD - 1); j <= I; j++) {
		sum += (CLOSE[j] - ave) * (CLOSE[j] - ave);
	}

	return sum / PERIOD;
}

double average(const double CLOSE[], const int PERIOD, const int I)
{
	double sum = 0.0;

	for (int j = I - (PERIOD - 1); j <= I; j++) {
		sum += CLOSE[j];
	}

	return sum / PERIOD;
}
