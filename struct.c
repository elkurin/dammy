#include <stdio.h>

struct P {
	int first;
	int second;
};

int main(void)
{
	struct P p = {1, 2};
	printf("%d %d\n", p.first, p.second);
	return 0;
}
