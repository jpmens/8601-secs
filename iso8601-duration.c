#include <stdio.h>
#include "duration.h"

/*
 * by Jan-Piet Mens, March 2025
 * Convert ISO8601 durations in argv[] to seconds, printing those to stdout
 * examples:
 *		"P1D"
 *		"PT2H5S"
 *		"P1Y"
 *		"P4H10M5S"
 */

int main(int argc, char **argv)
{
	time_t t;
	duration_type *d;
	char **p;

	for (p = argv + 1; p && *p; p++) {
		d = duration_create_from_string(*p);
		t = duration2time(d);

		// printf("%-10s %ld\n", *p, t);
		printf("%ld\n", t);
	}
	return 0;
}
