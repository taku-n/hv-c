#import "hv.dll"
void hv(const double &CLOSE[], double &hv[], const int N, const int PERIOD,
		const int TIMEFRAME);
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
#property indicator_width1 1

double hv[];

int OnInit()
{
	SetIndexBuffer(0, hv, INDICATOR_DATA);
	PlotIndexSetString(0, PLOT_LABEL, "HV(" + PERIOD + ")");
	// Data Window

	IndicatorSetString(INDICATOR_SHORTNAME, "HV(" + PERIOD + ")");
	// Chart

	return INIT_SUCCEEDED;
}

int OnCalculate(const int       rates_total,
		const int       prev_calculated,
		const datetime &time[],
		const double   &open[],
		const double   &high[],
		const double   &low[],
		const double   &close[],
		const long     &tick_volume[],
		const long     &volume[],
		const int      &spread[])
{
	hv(close, hv, rates_total, PERIOD, Period());

	return rates_total;
}
