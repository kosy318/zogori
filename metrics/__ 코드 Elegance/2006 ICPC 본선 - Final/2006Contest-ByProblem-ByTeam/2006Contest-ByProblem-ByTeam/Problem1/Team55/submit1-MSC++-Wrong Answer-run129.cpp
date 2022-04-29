#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int parser(char* data)
{
	char buf[8];
	int time;
	int min;
	int sec;
	int total;
	//----------------------------------
	memcpy(buf, &data[0], 2);
	buf[2] = '\0';
	time = atoi(buf);

	memcpy(buf, &data[3], 2);
	buf[2] = '\0';
	min = atoi(buf);

	memcpy(buf, &data[6], 2);
	buf[2] = '\0';
	sec = atoi(buf);
	//----------------------------------

	total = (time * 3600) + (min * 60) + sec;

	return total;
}


void Process()
{
	char data1[126];
	char data2[126];

	int result1;
	int result2;

	int t1;
	int t2;

	scanf("%s %s", data1, data2);

	result1 = parser(data1);
	result2 = parser(data2);

	result1 -=1;
	//result2 -=1;
	//result1 +=1;
	//result2 +=1;

	if (result1 > result2)
		result2 += ((24* 60 * 60)-1); // 24 * 60

	t1 = result1 / 3;
	t2 = result2 / 3;

	//printf("%d %d %d\n", result1, result2, t2 - t1);
	printf("%d\n", t2 - t1);
}


void main()
{
	int nNTC;
	int i;
	scanf("%d", &nNTC);

	for(i = 0; i < nNTC; ++i)
	{
		Process();
	}
}
