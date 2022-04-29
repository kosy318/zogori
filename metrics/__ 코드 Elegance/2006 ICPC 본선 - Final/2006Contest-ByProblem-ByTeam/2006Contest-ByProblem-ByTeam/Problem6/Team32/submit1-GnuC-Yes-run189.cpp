#include<iostream>
using namespace std;

struct ratio{
	long long d,n;
};


ratio add(ratio A,ratio B){
	
	ratio C;
	C.n=A.n*B.n;
	C.d=A.n*B.d + A.d*B.n;

	bool sign=(C.n*C.d <= 0);

	if(C.n <0) C.n*=-1;
	if(C.d <0) C.d*=-1;

	long long tmp1,tmp2;
	tmp1=C.n;
	tmp2=C.d;
	while(tmp1 !=0 && tmp2 !=0){
		if(tmp1>=tmp2) tmp1%=tmp2;
		else tmp2%=tmp1;
	}
	if(tmp1==0){
		C.n/=tmp2;
		C.d/=tmp2;
	}
	else{
		C.n/=tmp1;
		C.d/=tmp1;
	}

	if(sign==1) C.d *= -1;
	return C;
}


int main(){
	/*
	ratio A;
	A.d=1; A.n=6;
	ratio B;
	B.d=1; B.n=3;
	ratio C;
	C=add(A,B);
	cout<<C.d<<" "<<C.n<<endl;
	*/
	int T;
	cin>>T;
	int N,M;
	int AA[20];
	int BB[20];
	for(int t=0;t<T;t++){
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>AA[i]>>BB[i];
		}
		cin>>M;
		ratio A;
		A.d=1;
		A.n=1;
		ratio B;
		B.d=0;
		B.n=1;
		
		for(int i=1;i<N;i++){
			
			ratio tmp;
			tmp.d=AA[0];
			tmp.n=AA[i];
			A = add(A,tmp);
			tmp.d=BB[0]-BB[i];
			tmp.n=AA[i];
//			cout<<B.d<<" "<<B.n<<" "<<tmp.d<<" "<<tmp.n<<endl;
			B = add(B,tmp);
//cout<<"here!!"<<endl;
		}
		int x;
		bool okay = true;
		if( (M*A.n*B.n-B.d*A.n)%(A.d*B.n)==0){
			x =(M*A.n*B.n-B.d*A.n)/(A.d*B.n);

		}else{
			okay =0;
			cout<<"0"<<endl;
			continue;
		}

		for(int i=1;i<N;i++){
			if((AA[0]*x+BB[0]-BB[i])%AA[i] != 0){
				okay = 0;
				break;
			}
		}

		if(okay){
			cout<<AA[0]*x+BB[0]<<endl;
		}
		else{
			cout<<"0"<<endl;		
		}
	}
	return 0;
}
