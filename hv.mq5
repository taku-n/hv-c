#import "hv.dll"
void hv(const double &CLOSE[], double &hv[], const int START, const int END,
		const int PERIOD);
#import

input int PERIOD = 12;

#property indicator_separate_window
#property indicator_minimum         0

#property indicator_buffers 1
#property indicator_plots   1

#property indicator_label1 "HV"
#property indicator_type1  DRAW_LINE
#property indicator_color1 clrLime
#property indicator_style1 STYLE_SOLID
#property indicator_width1 2

double hv[];

int OnInit()
{
	SetIndexBuffer(0, hv, INDICATOR_DATA);
	PlotIndexSetString(0, PLOT_LABEL, "HV(" + IntegerToString(PERIOD)
			+ ")");
	// Data Window

	IndicatorSetString(INDICATOR_SHORTNAME, "HV("
			+ IntegerToString(PERIOD) + ")");
	// Chart Window

	return INIT_SUCCEEDED;
}

int OnCalculate(const int       RATES_TOTAL,
		const int       PREV_CALCULATED,
		const datetime &TIME[],
		const double   &OPEN[],
		const double   &HIGH[],
		const double   &LOW[],
		const double   &CLOSE[],
		const long     &TICK_VOLUME[],
		const long     &VOLUME[],
		const int      &SPREAD[])
{
	static int start = PERIOD - 1;

	hv(CLOSE, hv, start, RATES_TOTAL - 1, PERIOD);

	start = RATES_TOTAL - 1;

	return RATES_TOTAL;
}
