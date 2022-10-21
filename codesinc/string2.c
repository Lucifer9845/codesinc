#include<stdio.h>

void replacestr(char str[], char pat[], char rep[])
{
    char ans[100];
    int i, j, k, l = 0, flag = 0;

    for(i = 0;str[i] != '\0'; i++)
    {
        for(j = 0; pat[j] != '\0'; j++)
        {
            if(str[i+j] != pat[j])
                break;
        }

        if(pat[j] == '\0')
        {
            flag = 1;
            i = i+j-1;
            for(k = 0; rep[k] != '\0'; k++)
                ans[l++] = rep[k];
        }
        else
            ans[l++] = str[i];
    }

    ans[l] = '\0';
    if(flag == 1)
    {
        printf("Answer = ");
        for(i = 0; ans[i] != '\0'; i++)
            printf("%c", ans[i]);
    }
    else
        printf("pattern not found \n");
}

int main()
{
    char str[100], pat[100], rep[100];
    printf("Enter string: \n");
    gets(str);
    printf("Enter pattern: \n");
    gets(pat);
    printf("Enter string to replace with \n");
    gets(rep);
    replacestr(str, pat, rep);
    return 0;
}