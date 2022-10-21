#include<stdio.h>
#include<stdlib.h>

int main()
{
	char STR[100], PAT[100], REP[100], ans[100];
	
	int i, j, c, m, k, flag =0;
	
	printf("Enter the main string: \n");
	fflush(stdin);
	gets(STR);
	printf("Enter the pattern \n");
	gets(PAT);

	printf("Enter the replace string \n");
	gets(STR);
	
	i=j=m=c=0;
	
	while(STR[c] != '\0')
	{
		if(STR[m] == PAT[i])
		{
			i++;
			m++;
			if(PAT[i] == '\0')
			{
				for(k =0; REP[k] != '\0'; k++, j++)
				{
					ans[j] = REP[k];
					flag = 1;
				}
				
				i =0;
				c = m;
			}
		}
		
		else
		{
			ans[j] = STR[c];
			j++;
			c++;
			m = c;
			i = 0;
		}
	}
	
	if(flag ==0)
		printf("\npattern doesn't exist\n");
	else
	{
		ans[j] = '\0';
		printf(" \n resultant string is %s \n", ans);
	}
}