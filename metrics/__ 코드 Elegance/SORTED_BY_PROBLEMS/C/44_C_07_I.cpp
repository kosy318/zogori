#include<cstdio>
using namespace std;
int i,j,k,l,m,n,x1,y1,x2,y2;
int a[500001],b[500001],c[500001];
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i+n]=a[i];
        a[i+2*n]=a[i];
    }
    for(i=1;i<=n;i++){
        scanf("%d",&b[i]);
        b[i+n]=b[i];
        b[i+2*n]=b[i];
    }
    for(i=n+1;i<=2*n;i++) if(b[i]==a[1]) break;
    c[1]=a[1];
    k=1;
    x1=n;
    x2=n+2;
    y1=i-1;
    y2=i+1;
    for(i=2;i<=n;i++){
        if(a[x1]==b[y1]){
            c[++k]=a[x1];
            x1--;
            y1--;

        }
        else if(a[x1]==b[y2]){
            c[++k]=a[x1];
            x1--;
            y2++;
        }
        else if(a[x2]==b[y1]){
            c[++k]=a[x2];
            x2++;
            y1--;
        }
        else if(a[x2]==b[y2]){
            c[++k]=a[x2];
            x2++;
            y2++;
        }
        else{
            printf("-1\n");
            return 0;
        }
    }
    for(i=1;i<n;i++) printf("%d ",c[i]); printf("%d\n",c[n]);
    return 0;
}
