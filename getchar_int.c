#include <stdio.h>

int main(void)
{
	// 読みこむパート
	int a[1000];
	int end = 0;
	while(1) {
		int get = getchar();
		if (get == '\n') break;
		a[end] = get - (int)'0';
		end++;
	}

	// 確認用パート
	printf("%d\n", a[0] + 1);
	int i;
	for (i = 0; i < end; i++) printf("%d", a[i]);
	printf("\n");
	return 0;
}
