#include<bits/stdc++.h>
#define Pair pair<float,float>
#define Nmax int(1e4)
using namespace std;
Pair mypair[Nmax];
int n,Count;
Pair A[Nmax][Nmax];
int B[Nmax];


void   Init(){
float x,y;	
//	freopen("int.txt","r",stdin);
	cout<<"Nhap so luong cuoc hop"<<endl;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		mypair[i]=make_pair(x,y);
		
	}
}


void  Sort(int f,int l){
int mid=(f+l)/2;
int i=f,j=l;
	
	while(i<=j){
		while(mypair[i].first<mypair[mid].first) i++;
		while(mypair[j].first>mypair[mid].first) j--;
		if(i<=j){
			swap(mypair[i],mypair[j]);
			i++;
			j--;
		}
	 
	}
 if(i<l) Sort(i,l);
 if(j>f) Sort(f,j);
}

void Ouput(){
	for(int i=1;i<=Count;i++){
		cout<<"Phong thu "<<i<<" gom cac cuoc hop : ";
			for(int j=1;j<=B[i];j++)
				cout<<A[i][j].first<<"-"<<A[i][j].second<<"    ";
			cout<<endl;
	}
}

void  Program(){
int j;
Count=1;

B[1]=1;
A[1][1]=mypair[1];
	for(int i=2;i<=n;i++){
		for( j=1;j<=Count;j++)
			if(A[j][B[j]].second<mypair[i].first){
				B[j]++;A[j][B[j]]=mypair[i];break;
			}
		if(j>Count){
			Count++;
			B[Count]=1;
			A[Count][1]=mypair[i];
		}
	}
}

main(){
Init();
Sort(1,n);
Program();
Ouput();

}

