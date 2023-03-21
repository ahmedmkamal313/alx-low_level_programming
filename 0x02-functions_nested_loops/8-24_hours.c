#include "main.h"

/**
 * jack_bauer - prints every minute of the day of Jack Bauer.
 *
 */

void jack_bauer(void)
{
	int hr, min;

	for (hr =0 ; hr <= 23 ; hr++)
	{
		for(min = 0 ; min <= 59 ; min++)
		{
			_putchar((
