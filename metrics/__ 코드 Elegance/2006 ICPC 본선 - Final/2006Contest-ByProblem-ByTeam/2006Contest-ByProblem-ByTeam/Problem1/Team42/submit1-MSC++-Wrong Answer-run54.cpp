#include<stdio.h>

void main()
{
	int T;
	int s_hh,s_mm,s_ss;
	int e_hh,e_mm,e_ss;
	int s_temp,e_temp;
	int output,temp;
	int x;

	scanf("%d",&T);
	
	for( x = 0 ; x < T ; x ++ )
	{
		scanf("%d:%d:%d", &s_hh,&s_mm,&s_ss);

		scanf("%d:%d:%d", &e_hh,&e_mm,&e_ss);

		if( s_hh <= e_hh )
		{
			e_temp = e_hh * 3600 + e_mm * 60 + e_ss;
			s_temp = s_hh * 3600 + s_mm * 60 + s_ss;

			output = ( e_temp - s_temp ) / 3;
		
			temp = ( e_temp - s_temp ) % 3;

			if( temp != 0 )
				output ++;
		}
		else
		{
			e_temp = ( e_hh + 24 ) * 3600 + e_mm * 60 + e_ss;
			s_temp = s_hh * 3600 + s_mm * 60 + s_ss;

			output = ( e_temp - s_temp ) / 3;
		
			temp = ( e_temp - s_temp ) % 3;

			if( temp != 0 )
				output ++;
		}

		printf("%d\n",output);
	}
}