#include<bits/stdc++.h>
#include<string>
using namespace std;
struct Node{
	Node* pLeft;
	Node* pRight;
	string value;
	short int bal;
};typedef Node Node;
  typedef Node* Tree;

void Init_tree(Tree & tr){
	tr=NULL;
}

Node* CreateNode(string value){
Node* p=new Node;
	p->value= value;
	p->pLeft=NULL;
	p->pRight=NULL;
	p->bal =0;
	return p;
}

void Leftrotate(Node * &p){
Node* q= p->pRight;
	p->pRight=q->pLeft;
	q->pLeft=p;
	p=q;
	
}

void Rightrotate(Node *&p){
Node *q=p->pLeft;
	p->pLeft=q->pRight;
	q->pRight=p;
	p=q;
}
  
void  Leftplance(Tree &p){
   	switch(p->pLeft->bal){
		case 1:	Rightrotate(p); 				
			  	 p->bal=0;
			 	 p->pRight->bal=0;
			 	 break;
		case 2: Leftrotate(p->pLeft);
				Rightrotate(p);
				switch(p->bal){
						case 0: p->pLeft->bal=0;
								p->pRight->bal=0;
								break;
						case 1:p->pLeft->bal=0;
							   p->pRight->bal=2;
							   break;
						case 2:p->pRight->bal=0;
							   p->pLeft->bal=1;                           
							   break;
					
					}
				p->bal=0;
				break;
				
		}
}

void  Righplance(Tree &p){
   	switch(p->pRight->bal){
		case 2: Leftrotate(p); 					
			  	 p->bal=0;
			 	 p->pLeft->bal=0;
			 	 break;
		case 1: Rightrotate(p->pRight);
				Leftrotate(p);
				switch(p->bal){
						case 0: p->pLeft->bal=0;
								p->pRight->bal=0;
								break;
						case 1:p->pLeft->bal=0;
							   p->pRight->bal=2;
							   break;
						case 2:p->pRight->bal=0;
							   p->pLeft->bal=1;
							   break;
					
					}
				p->bal=0;       
				break;
				
		}
}
		
int InsertNode(Node* &tree,string x)
{
int res;
	if(tree==NULL){ 
			 tree = CreateNode(x);
			 if(tree==NULL){ return -1;} else return 2;
			 }
	else {
	    if(tree->value>x){
			
			res = InsertNode(tree->pLeft,x);
			if(res < 2) {return res;}
			switch(tree->bal){ 
					 case 0:tree->bal = 1;return 2;
					 case 1: Leftplance(tree);return 1;
					 case 2:tree->bal = 0;return 1;
					}
			}		
		else{
			res = InsertNode(tree->pRight,x);
			if(res<2){return res;}
			switch(tree->bal){
					case 0:tree->bal=2;return 2;
					case 1:tree->bal = 0;return 1;
					case 2: Righplance(tree);return 1;
					}		
			}
		}
}

int Check(string x,string y){//  x==s.y== Node
int m=min(x.length(),y.length());
	for(int i=0;i<m;i++)
		if(x[i]>y[i]) return 1;else if(x[i]<y[i]) return -1;// s>node k=1;
	if(m==x.length()) {
		cout<<y<<"\n"; return 0;} ;
	return 1;
}

void Search(Node* p,string x){
	if(p==NULL) return;
int k=Check(x,p->value);
	if(k==-1){ Search(p->pLeft,x);return;} else
	if(k==1){Search(p->pRight,x);return;}
	Search(p->pRight,x);
	Search(p->pLeft,x);
}

Tree tre;
void Input(){
ifstream cin1("dictionary.txt");
string x;
while(!cin1.eof()){
	 cin1>>x;
	 InsertNode(tre,x);
	}
	cout<<"Nhap khoa can tim"<<"\n";
	cin>>x;
	cout<<"\n\n";
	Search(tre,x);
	
}

main(){
Input();



}

