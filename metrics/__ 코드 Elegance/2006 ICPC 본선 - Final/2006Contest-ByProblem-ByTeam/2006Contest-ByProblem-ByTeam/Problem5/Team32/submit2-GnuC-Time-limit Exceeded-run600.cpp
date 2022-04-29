#include<iostream>
using namespace std;


struct F{
int kind,l;
};

F JJ[300];
F YY[300];
int J,Y;

int DP[300][300];


int find(int j ,int y){

	if(j!=-1 && y!=-1)if(DP[j][y]!=-1) return DP[j][y];

	int lj=0;
	int ly=0;
	int maxx=0;
	while(true){
		if(lj==ly){
			if(y!=Y-1){
				y++;
				ly+=YY[y].l;
			}else if(j!=J-1){
				j++;
				lj+=JJ[j].l;
			}
			else {
				if(j!=-1 && y!=-1) DP[j][y]=maxx;
				return maxx;
			}
		}
		else if(lj>ly){
			if(y==Y-1){
				for(int i=j+1;i<J;i++){
					maxx+=JJ[i].l;
				}
				if(j!=-1 && y!=-1) DP[j][y]=maxx;
				return maxx;
			}
			else{
				y++;
				ly+=YY[y].l;
//cout<<"1:"<<endl;
//cout<<"lj="<<lj<<" ly="<<ly<<endl;
//cout<<"j="<<j<<" y="<<y<<" Y="<<Y<<" J="<<J<<endl;

				if(j!=-1 && YY[y].kind==JJ[j].kind) break;
			}
		}
		else if(lj<ly){
			if(j==J-1){
				for(int i=y+1;i<Y;i++){
					maxx+=YY[i].l;
				}
				if(j!=-1 && y!=-1) DP[j][y]=maxx;
				return maxx;
			}
			else{
				j++;
				lj+=JJ[j].l;
//cout<<"2:"<<endl;
//cout<<"lj="<<lj<<" ly="<<ly<<endl;
//cout<<"j="<<j<<" y="<<y<<" Y="<<Y<<" J="<<J<<endl;
				if(y!= -1 && JJ[j].kind==YY[y].kind) break;
			}
		}
		if(ly>maxx) maxx=ly;
		if(lj>maxx) maxx=lj;
	}//end while


	int mj=lj+find(j,y-1);
	int my=ly+find(j-1,y);

	if(mj>my) {
		if(j!=-1 && y!=-1) DP[j][y]=my;
		return my;
	}
	else {
		if(j!=-1 && y!=-1) DP[j][y]=mj;
		return mj;
	}
}	



int main(){




	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		for(int i=0;i<300;i++){
			for(int j=0;j<300;j++){
			DP[i][j]=-1;
			}
		}

		int n;
		cin>>n;
		int J_time[100];
		int Y_time[100];
		for(int i=0;i<n;i++) cin>>J_time[i];
		for(int i=0;i<n;i++) cin>>Y_time[i];
	
		cin>>J>>Y;
	
		for(int i=0;i<J;i++){
			int tmp;
			cin>>tmp;
			JJ[i].kind=tmp-1;
			JJ[i].l=J_time[JJ[i].kind];
		}
		for(int i=0;i<Y;i++){
			int tmp;
			cin>>tmp;
			YY[i].kind=tmp-1;
			YY[i].l=Y_time[YY[i].kind];
		}
	cout<<find(-1,-1)<<endl;
	}
	return 0;
}
