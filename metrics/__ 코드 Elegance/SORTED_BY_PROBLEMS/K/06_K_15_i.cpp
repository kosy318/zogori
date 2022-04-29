#include <bits/stdc++.h>

using namespace std;

typedef tuple<double, double, double> dot;

int n, k, r[105], g[105], b[105];
dot dots[105];

dot mean_in_vector(vector<dot>& a){
    double lr = 0, lg = 0, lb = 0;
    for(dot z:a){
        lr += get<0>(z);
        lg += get<1>(z);
        lb += get<2>(z);
    }
    int size = a.size();
    return make_tuple(lr/size, lg/size, lb/size);
}


double dist_in_dot(dot a, dot b){
    double r = get<0>(a) - get<0>(b);
    double g = get<1>(a) - get<1>(b);
    double bb = get<2>(a) - get<2>(b);
    return r*r+g*g+bb*bb;
}


double eval(vector<dot>& a){
    dot mean = mean_in_vector(a);
    double res= 0;
    for(dot z: a){
        res += dist_in_dot(z, mean);
    }
    return res;
}

double eval_with_dot(vector<dot>& a, dot b){
    a.push_back(b);
    double res = eval(a);
    a.erase(a.end()-1);
    return res;
}

double go_through(){
    double dist_val = -5;
    int cluster_1 = 0, cluster_2 = 0;
    int clustered[105] = {0};
    vector<dot> c1, c2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            double tmp = dist_in_dot(dots[i],dots[j]);
            if(tmp> dist_val)
            {
                dist_val = tmp;
                cluster_1 = i;
                cluster_2 = j;
            }
        }
    }
    c1.push_back(dots[cluster_1]);
    c2.push_back(dots[cluster_2]);
    clustered[cluster_1] = 1;
    clustered[cluster_2] = 1;
    while(c1.size()+c2.size()<n){
        dot c1_mean = mean_in_vector(c1);
        dot c2_mean = mean_in_vector(c2);
        double c2_eval = INT_MAX, c1_eval = INT_MAX;
        int c1_min = -1, c2_min = -1;
        double org_eval_c1 = eval(c1), org_eval_c2 = eval(c2);
        for(int i=0;i<n;i++){
            if(clustered[i]) continue;
            double rp = eval_with_dot(c1, dots[i])+org_eval_c2;
            if(rp<c1_eval){
                c1_eval = rp;
                c1_min = i;
            }
            rp = eval_with_dot(c2, dots[i])+org_eval_c1;
            if(rp<c2_eval){
                c2_eval = rp;
                c2_min = i;
            }
        }
        if(c1_eval<c2_eval)
        {
            c1.push_back(dots[c1_min]);
            clustered[c1_min] = 1;
        }else{
            c2.push_back(dots[c2_min]);
            clustered[c2_min] = 1;
        }
    }
    return eval(c1) + eval(c2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>r[i]>>g[i]>>b[i];
    }
    cout<<setprecision(7);
    if(n==1) {
        cout<<0;
        return 0;
    }
    if(k==1){
        int r_sum = 0, g_sum=0, b_sum = 0;
        for(int i=0;i<n;i++){
            r_sum+=r[i];
            g_sum+=g[i];
            b_sum+=b[i];
        }
        double res = 0;
        double r_res = (double)r_sum/n, g_res = (double)g_sum/n, b_res = (double)b_sum/n;
        for(int i=0;i<n;i++){
            res += (r[i]-r_res)*(r[i]-r_res) + (g[i]-g_res)*(g[i]-g_res) + (b[i]-b_res)*(b[i]-b_res);
        }
        cout<<res;
    }
    else{

        for (int i = 0; i < n; i++)
            dots[i] = make_tuple((double) r[i], (double) g[i], (double) b[i]);
        cout<<go_through();
    }
    return 0;
}