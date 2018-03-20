#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;

struct Node{
	char value;
	Node* pNext;
	Node* pChild;
	bool Check;
}; typedef Node Node;
   typedef Node* Tree;

void Init_Tree(Tree &tr){
	tr=NULL;
}

Node* CreatNode(int k){
Node* p=new Node;
	p->value=s[k];
	if(k==s.length()-1)
	p->Check=true;else p->Check=false;			// neu la phan tu cuoi cung cua xau s thi ket thuc tu= true
	p->pChild=NULL;
	p->pNext=NULL;
	return p;
}

void Insert_Node(Node* tr,int k){												// them vao vao phan tu thu k
char value=s[k];
Node* p=tr;
if(k>=s.length()) return;														// neu het xau thi dung lai
	if(p->pChild==NULL) 
	{p->pChild=CreatNode(k);Insert_Node(p->pChild,k+1);}				// neu chua co con thi tao con = Node moi co gia tri s[k];
	 else{
		 p=p->pChild;															// neu co con thi cho p tro toi con
		 
		 while(p!=NULL){
		 	if(p->value==value) {if(k==s.length()-1) p->Check=true;Insert_Node(p,k+1);break;}						// neu da co node co khoa la value roi thi them ki tu tiep theo vao con cua node do
		 		  else{
		 		  		if(p->pNext==NULL) {									//neu k tôn tai con nao == value thi them vao con sau cung 
		 	  				p->pNext=CreatNode(k);
		 	  				Insert_Node(p->pNext,k+1);
		 	  				break;
				   		}
						else p=p->pNext;
			  	 }	
		 }	
	}
}

Node* Search(Node* tr,int k){													
	if(k<s.length()) {														
	if(tr==NULL) return NULL;														// return NULL neu khong co tu nao thoa man
	if(tr->value==s[k] and k==s.length()-1) return tr ;								
		else{
	
		if(tr->value==s[k]) Search(tr->pChild,k+1);
		   else Search(tr->pNext,k);
		}
	}
}

void Output(Node* tr,string s1){	// tai tr va truoc do co s1

Node* p=tr;	
	if(p->Check) cout<<s1<<p->value<<"\n";
	if(p->pChild!=NULL or p->pNext!=NULL){
			if(p->pChild!=NULL){
			
			string x=s1;
			x.push_back(p->value);
			Output(p->pChild,x);
			}
			if(p->pNext!=NULL) Output(p->pNext,s1); 
		
	}
	
}

Tree tree;
void InPut(){

	Init_Tree(tree);
	tree=CreatNode(0);
	ifstream cin1;
	cin1.open("dictionary.txt");
	while( !cin1.eof()){
		cin1>>s;
		Insert_Node(tree,0);
		
	}
	cout<<"Nhap tu can tim"<<"\n";
	cin>>s;	
}

void Program(){
Node* p= Search(tree->pChild,0);

	if(p==NULL) cout<<"Khong co goi y nao"<<"\n";
	else{
	cout<<"cac tu goi y la:\n";	

	if(p->Check) cout<<s<<"\n";
	Output(p->pChild,s);
	}
}

main(){
InPut();
Program();

}

