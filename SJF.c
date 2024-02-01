//Non pre-emptive

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int p[n],a[n],b[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
        p[i] = i+1;
    }
    
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]= temp;
                temp = b[j];
                b[j] = b[j+1];
                b[j+1]= temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1]= temp;
            }
        }
    }
    int ct[n],trt[n],wt[n];
    int current = a[0];
    int max_val = 100000;
    int maxi = 100000;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(maxi>b[j] && b[j]!=i && current>=a[i]){
                max_val = b[i];
                maxi = i;
            }
        }
        ct[maxi] = current+max_val;
        trt[maxi] = ct[maxi]-a[maxi];
        wt[maxi] = trt[maxi] - b[maxi];
        
        
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[maxi], a[maxi], b[maxi], ct[maxi], trt[maxi], wt[maxi]);
        
        current+=b[i];
        b[maxi] = -1;
    }

    return 0;
}

