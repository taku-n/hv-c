#include <math.h>

void hv(const double CLOSE[], double hv[], const int START, const int END,
		const int PERIOD);
// Historical Volatility

double sd(const double CLOSE[], const int PERIOD, const int I);
// Standard Deviation

double variance(const double CLOSE[], const int PERIOD, const int I);
double average(const double CLOSE[], const int PERIOD, const int I);

void hv(const double CLOSE[], double hv[], const int START, const int END,
		const int PERIOD)
{
	for (int i = START; i <= END; i++) {
		hv[i] = sd(CLOSE, PERIOD, i);
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
