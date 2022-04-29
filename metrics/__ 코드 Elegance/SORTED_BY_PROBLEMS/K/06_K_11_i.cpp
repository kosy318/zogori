#include <bits/stdc++.h>

using namespace std;

int n, k, r[105], g[105], b[105];

double mean_in_vector(vector<int>& a){
    int sum = 0;
    for(int z:a){
        sum+=z;
    }
    return (double)sum/a.size();
}

double eval(vector<int>& a){
    double m = mean_in_vector(a);
    double sum = 0;
    for(int z: a){
        sum += (m-z) * (m-z);
    }
    return sum;
}

double go_through(int k[105]){
    int min_val = INT_MAX, max_val = INT_MIN;
    sort(k, k+n);
    double cluster_1, cluster_2;
    int clustered[105] = {0};
    vector<int> dot_1, dot_2;
    clustered[0] = 1; clustered[n-1] = 1;
    dot_1.push_back(k[0]); dot_2.push_back(k[n-1]);
    while(dot_1.size()+dot_2.size()<n){
        //get cluster_1
        int sum = 0;
        for(int z: dot_1){
            sum+=z;
        }
        cluster_1 = mean_in_vector(dot_1);
        cluster_2 = mean_in_vector(dot_2);
        int min_for_cl_1 = -1;
        int min_for_cl_2 = -1;
        for(int i=0;i<n;i++){
            if(clustered[i]) continue;
            double dist_from_cl1 = (cluster_1-k[min_for_cl_1]) * (cluster_1-k[min_for_cl_1]);
            double dist_from_cl2 = (cluster_2-k[min_for_cl_2]) * (cluster_2-k[min_for_cl_2]);

            if(dist_from_cl1 > (cluster_1-k[i])*(cluster_1-k[i]))
                min_for_cl_1 = i;

            if(dist_from_cl2 > (cluster_2-k[i])*(cluster_2-k[i]))
                min_for_cl_2 = i;

        }
        double dist_from_cl1, dist_from_cl2;
        if(min_for_cl_1 == -1) dist_from_cl1 = 5000*5000;
        else dist_from_cl1 = (cluster_1-k[min_for_cl_1]) * (cluster_1-k[min_for_cl_1]);

        if(min_for_cl_2 == -1) dist_from_cl2 = 5000*5000;
        else dist_from_cl2 = (cluster_2-k[min_for_cl_2]) * (cluster_2-k[min_for_cl_2]);
        if(dist_from_cl1<dist_from_cl2) {
            dot_1.push_back(k[min_for_cl_1]);
            clustered[min_for_cl_1] = 1;
        }
        else {
            dot_2.push_back(k[min_for_cl_2]);
            clustered[min_for_cl_2] = 1;
        }
    }

    return eval(dot_1) + eval(dot_2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>r[i]>>g[i]>>b[i];
    }
    cout<<setprecision(7);
    if(n==1) cout<<0;
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
        double res_r = go_through(r);
        double res_b = go_through(b);
        double res_g = go_through(g);
        cout<<res_r+res_b+res_g;
    }


    return 0;
}