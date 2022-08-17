#include "stdio.h"

int main()
{
	unsigned char cases, data;
	scanf("%hhu", &cases);
	while(cases--)
	{
		scanf("%hhu", &data);
		printf("%hhu %hhu\n",(data > 10)? data - 10 : 0, (data > 10)? 10: data);
	}
}
