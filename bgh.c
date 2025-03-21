#include <stdio.h>
#include<string.h>
int main()
{
    
        int n;
        scanf("%d",&n);
        char X[n+1],Y[n+1];
        scanf("%s",X);
        scanf("%s",Y);
        int c_o=0,d_o=0;
        for(int i=0;i<n;i++)
        {
            if(X[i]=='1'&&Y[i]=='1'){
                c_o++;
            }
            else if(X[i]=='0'&&Y[i]=='0')
            {
                d_o++;
            }
        }
        int reee=n-c_o-d_o;
        if(c_o%2==0&&reee==0){
            printf("NO\n");
            
        }
        else
        {
            printf("YES\n");
        }
    }





