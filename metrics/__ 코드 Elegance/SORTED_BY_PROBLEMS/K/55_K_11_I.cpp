#include <stdio.h>
#include <math.h>
#include <queue>

#define MAXN 100

using namespace std;

struct rgb{
    int r, g, b;
};

int n, k;
rgb p[MAXN];
queue<int> q1, q2, q_;

void case1();
void case2();
double D(rgb p1, int n1, rgb p2);
void Plus(rgb &p1, rgb p2);
void Minus(rgb &p1, rgb p2);
void Set(rgb &p1);

int main()
{
    int i, j;

    freopen("input", "r", stdin);

    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++) scanf("%d %d %d", &p[i].r, &p[i].g, &p[i].b);

    if(k == 1) case1();
    else case2();

    return 0;
}

void case1()
{
    int i;
    rgb sum;
    double ans=0;

    sum.r = sum.g = sum.b = 0;
    for(i=0; i<n; i++){
        Plus(sum, p[i]);
    }

    for(i=0; i<n; i++){
        ans += D(sum,n,p[i]);
    }

    printf("%lf", ans);
}

void case2()
{
    if(n == 2){
        printf("0.000000");
        return;
    }

    int i, n1=1, n2=1;
    rgb p1, p2;
    double d1, d2;

    p1.r = p[0].r;
    p1.g = p[0].g;
    p1.b = p[0].b;
    p2.r = p[1].r;
    p2.g = p[1].g;
    p2.b = p[1].b;
    q1.push(0);
    q2.push(1);

    for(i=2; i<n; i++){
        d1 = D(p1, n1, p[i]);
        d2 = D(p2, n2, p[i]);

        if(d1 < d2){
            n1++;
            Plus(p1, p[i]);
            q1.push(i);
        }
        else{
            n2++;
            Plus(p2, p[i]);
            q2.push(i);
        }
    }

    for(int z=0; z<100; z++){
        while(!q1.empty()){
            i = q1.front(); q1.pop();
            d1 = D(p1, n1, p[i]);
            d2 = D(p2, n2, p[i]);

            if(d1 < d2 || (q_.empty() && q1.empty())){
                q_.push(i);
            }
            else{
                n2++;
                Plus(p2, p[i]);
                q2.push(i);
                n1--;
                Minus(p1, p[i]);
            }
        }
        while(!q_.empty()){
            i = q_.front(); q_.pop();
            q1.push(i);
        }


        while(!q2.empty()){
            i = q2.front(); q2.pop();
            d1 = D(p1, n1, p[i]);
            d2 = D(p2, n2, p[i]);

            if(d2 < d1 || (q_.empty() && q2.empty())){
                q_.push(i);
            }
            else{
                n1++;
                Plus(p1, p[i]);
                q1.push(i);
                n2--;
                Minus(p2, p[i]);
            }
        }
        while(!q_.empty()){
            i = q_.front(); q_.pop();
            q2.push(i);
        }
    }


    double ans=0;

    while(!q1.empty()){
        i = q1.front(); q1.pop();
        ans += D(p1,n1,p[i]);
    }
    while(!q2.empty()){
        i = q2.front(); q2.pop();
        ans += D(p2,n2,p[i]);
    }

    printf("%lf", ans);
}

double D(rgb p1, int n1, rgb p2)
{
    double d;

    d = pow(p1.r/(double)n1 - p2.r,2);
    d += pow(p1.g/(double)n1 - p2.g,2);
    d += pow(p1.b/(double)n1 - p2.b,2);

    return d;
}

void Plus(rgb &p1, rgb p2)
{
    p1.r += p2.r;
    p1.g += p2.g;
    p1.b += p2.b;
}

void Minus(rgb &p1, rgb p2)
{
    p1.r -= p2.r;
    p1.g -= p2.g;
    p1.b -= p2.b;
}
