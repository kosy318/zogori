#include<iostream>
#include <stdio.h>
using namespace std;

int N;
double x[1000];
double y[1000];
double height[1000];

double gety(double x1,double y1,double x2,double y2,double x){
	return y1+(y2-y1)*(x-x1)/(x2-x1); 

}

struct _pos{
	double xp,yp;

};	

double det(double a1,double b1,double a2,double b2){
	return a1*b2-a2*b1;

}

void sol(double a1,double b1,double c1,double a2,double b2,double c2,double& s,double& t ){
	double delta=det(a1,b1,a2,b2);
	double delx=det(c1,b1,c2,b2);
	double dely=det(a1,c1,a2,c2);
	s=delx/delta;
	t=dely/delta;
	return;
}


//0 not to consider
int inter(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4,_pos& intersec){
	if((y2-y1)*(y4-y3)>=0)return 0;
	else {
		double s,t;
		sol(x2-x1,x3-x4,x3-x1,y2-y1,y3-y4,y3-y1,s,t);
		intersec.xp=x1+(x2-x1)*s;
		intersec.yp=y1+(y2-y1)*s;
		return 1;

	}

}

int main(){
	/*
	cout<<det(1.1,1.2,1.3,1.4)<<endl;
	double ss,tt;
	
	sol(1,1,1,2,3,5,ss,tt);
	cout<<ss<<" "<<tt<<endl;

	_pos tmp;
	inter(-11,-11,1,1,0,1,2,0,tmp);
	cout<<tmp.xp<<" "<<tmp.yp<<endl;

	*/


	int caN;
	cin>>caN;
	for(int ca=0;ca<caN;ca++){
		
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>x[i]>>y[i];
		}
		double ans=1000000;
		for(int x_i=0;x_i<N;x_i++){
		//	cout<<"for x_i = "<<x_i<<endl;
			double max_y=y[x_i];
			for(int ff=0;ff<=N-2;ff++){
				height[ff]=gety(x[ff],y[ff],x[ff+1],y[ff+1],x[x_i]);
		//		cout<<"heiight "<<ff<<" is "<<height[ff]<<endl;

			}	
			for(int ff=0;ff<=N-2;ff++){
				if(height[ff]>max_y)max_y=height[ff];	
			}	
			if(max_y-y[x_i]<ans)ans=max_y-y[x_i];
		}
		
		
		
		int plane[1000][3];// record start and end and height
		int p_size=0;
		int state=0;//0 find true ,1 find false


		bool flat[1000];
		for(int i=0;i<N;i++)flat[i]=false;
		for(int i=0;i<N-1;i++){
			if(y[i]==y[i+1])flat[i]=true;
		}
		for(int i=0;i<N-1;i++){
			if(state==0){
				if(flat[i]==true){
					plane[p_size][0]=i;
					plane[p_size][2]=y[i];
					state=1;
				}

			}	
			else if(state==1){
				if(flat[i]==false){
					plane[p_size][1]=i;
					p_size++;
					state=0;
				}
			}

		}

		for(int i=0;i<p_size;i++){
		//	cout<<plane[i][0]<<" "<<plane[i][1]<<" "<<plane[i][2]<<endl;
			double inside_max=0;
			for(int j=0;j<N-1;j++){
				for(int k=0;k<N-1;k++){
					_pos point;
					int findpoint=inter(x[j],y[j],x[j+1],y[j+1],x[k],y[k],x[k+1],y[k+1],point);
					if(findpoint==1){
						
						if(x[plane[i][0]]<point.xp&&x[plane[i][1]]>point.xp){
							if(point.yp>inside_max)inside_max=point.yp;
							

						}
					}

				}
			}
			if(inside_max-plane[i][2]<ans)ans=inside_max-plane[i][2];
		}


		if(ans>1000){
			cout<<"IMPOSSIBLE"<<endl;
		}
		else	printf("%.1lf\n",ans);

	}
	return 0;

}
