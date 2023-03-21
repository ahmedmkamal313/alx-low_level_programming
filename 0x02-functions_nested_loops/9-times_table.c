#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0.
 */

void times_table(void)
{
	for (int i = 0 ; i <= 9 ; i++)
	{
		for (int j = 0 ; j <= 9 ; j++)
		{
			_putchar("%d,", i * j);
		}
		_putchar('\n');
	}

}
