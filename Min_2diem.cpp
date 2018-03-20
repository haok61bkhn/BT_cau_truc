#include<bits/stdc++.h>
#define oxy pair<float,float>
#define Nmax int(1e5)
using namespace std;
oxy a[Nmax],Res_1,Res_2;
float Res;
int n;
void Init(){
freopen("int.txt","r",stdin);
int x,y;
	cout<<"Nhap so diem"<<"\n";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		a[i]=make_pair(x,y);
		
	}
}

void Qsort(oxy a[],int f,int l){
int mid=a[(f+l)/2].first;
int i=f,j=l;
	while(i<=j){
		while(a[i].first<mid ) i++;
		while(a[j].first>mid) j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
		
	}
if(i<l) Qsort(a,i,l);
if(j>f) Qsort(a,f,j);
}

float Distance(oxy x,oxy y){

	return (sqrt(pow((x.first-y.first),2)+pow((x.second-y.second),2)));
	
}

void Save_Min(oxy x,oxy y){	
	Res_1=x;
	Res_2=y;
	Res=Distance(Res_1,Res_2);
}
float Find_Min(oxy a[],int f,int l){
int mid=(f+l)/2;
	if(l-f+1==2){
		if(Distance(a[l],a[f])<Res)
			Save_Min(a[l],a[f]);
	
		return Distance(a[l],a[f]);
		
	}
	if(l-f+1==1) return Nmax;
	float D_Min=min(Find_Min(a,f,mid),Find_Min(a,mid,l));
	for(int i=mid-1;i>=0;i-- ){
		if((-a[i].first+a[mid].first)>D_Min) break;
		else{
			for(int j=mid+1;j<n;j++)
				if((a[j].first-a[mid].first)>D_Min) break;
				 else{				 	
				 	if(Distance(a[i],a[j])<Res) Save_Min(a[i],a[j]);
				 }
			
			
		}
	}	
	return Res;
	
}
main(){
Init();
Qsort(a,0,n-1);
Res=Nmax;
cout<<Find_Min(a,0,n-1)<<endl;
cout<<Res_1.first<<" "<< Res_1.second<<endl;
cout<<Res_2.first<<" "<<Res_2.second<<endl;

}

