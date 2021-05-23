#include <math.h>
#include <stdio.h>
/*
 * rule A:
 *  if @t is greater than @trin
 *      1 + (@root + 1) * (@root + 1) - t
 *  else
 *     @root + 1
 *  is the position on applicable axis
 */
#define RULE_A ((t > trin) ? 1 + (root + 1) * (root + 1) - t : root + 1)

/*
* rule B:
*  if @t is greater than @trin
*      @root + 1
*  else
*     @t - @root * @root
*  is the position on applicable axis
*/
#define RULE_B ((t > trin) ? root + 1 : t - root * root)

int main()
{
	unsigned N, n;
	unsigned long t;
	scanf("%d", &N);
	for (n = 1; n <= N; n++)
	{
		scanf("%lu", &t);

		// nearest square root <= @t
		unsigned long root = (unsigned long)sqrt(t);

		// find triangular number for @root
		unsigned long trin = (root * root + (root + 1) * (root + 1) + 1) / 2;

		printf("Case %d: ", n);
		// Case: @t is a perfect square
		if (root * root == t)
			printf((root % 2 == 0) ? "%lu 1" : "1 %lu", root);
		else
			/*
			Case: @t is not a perfect square
				if @root is even, #RULE_A is applicable to X, else #RULE_B
				it's reversed for Y
			*/
			printf("%lu %lu", (root % 2 == 0) ? RULE_A : RULE_B, (root % 2 == 0) ? RULE_B : RULE_A);
		printf("\n");
	}
	return 0;
}
