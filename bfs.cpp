#include<iostream>
#include<stdlib.h>

using namespace std;

class Node{

public:
Node * next;
int vertexName;
char visited;
};

class llist{

public:

Node * head;

llist(){
	head = NULL;
}

Node * createnode(int vertexname,char visit);
void addElement(int vertexname,char visit);
void addatbeg(int vertexname,char visit);
void display();
void addingElementFromAlltoQueue();
};



llist allVerticeList,listQueue;
int finalSequenceIndex = 0;

int main(){
	
int v;
cout<<"Enter Number of vertices you have in your graph : ";
cin>>v;

int verticeVisited[v];
int arr[v+1][v+1];
int j=0,i;
arr[0][0] = 0;
for(i=1;i<v+1;i++){
	arr[j][i] = i;
	arr[i][j] = i;
}

for(int i=1;i<v+1;i++){
for(int j=1;j<v+1;j++){
    if(i==j){
    arr[i][j] = 0;
    }else{
	
	cout<<"Is there any edge from "<<arr[i][0]<<" to "<<arr[0][j]<<" (y/n) : ";
	char ans;
	cin>>ans;

	if(ans == 'Y' || ans == 'y'){
		arr[i][j] = 1;
		arr[j][i] = 1;
	}else if(ans == 'N' || ans == 'n'){
		arr[i][j] = 0;
		arr[j][i] = 0;
	}else{
		cout<<"In valid Input Detected !";
		exit(0);
	}
    
    }
}
}
//PRINTING ADJACENCY MATRIX
cout<<"\n\nMATRIX IS : \n\n";
for(i=0;i<v+1;i++){
	for(j=0;j<v+1;j++){
		cout<<arr[i][j]<<"     ";
	}
cout<<"\n\n";
}

//SOURCE VERTEX INFO
int sourceVertex;
cout<<"Enter the source vertex from 1 to "<<v<<" : ";
cin>>sourceVertex;
while( !(sourceVertex>=1 && sourceVertex<=v) ){
cout<<"Source Vertex is Out of Range !\nEnter Again : ";
cin>>sourceVertex;
}
cout<<"\n\nSource Vertex is : "<<sourceVertex<<"\n\n";
//SOURCE VERTEX INFO ENDS

for(int i=1;i<=v;i++){
	if(i == sourceVertex){
		allVerticeList.addElement(i,'v');

	}else{
		allVerticeList.addElement(i,'u');
	}	
}

allVerticeList.addingElementFromAlltoQueue();

while(listQueue.head != NULL){



if(listQueue.head == NULL){
	cout<<"No Vertice in List Queue !";
//	return 0;
}else{
	Node * ptr = listQueue.head;
	listQueue.head = ptr->next;
	verticeVisited[finalSequenceIndex] = ptr->vertexName;
	finalSequenceIndex++;
	if(allVerticeList.head == NULL){
		cout<<"ALL VERTICE LIST IS EMPTY !";
//		return 0;
	}else{
		Node * ptrAll = allVerticeList.head;
		while(ptrAll != NULL){
			if(arr[ptr->vertexName][ptrAll->vertexName] > 0){
				ptrAll->visited = 'v';
			}
			ptrAll = ptrAll->next;
		}
	}	
}

allVerticeList.addingElementFromAlltoQueue();

cout<<"\n\nALL VERTICES LIST : \n\n";
allVerticeList.display();

cout<<"\n\nLIST QUEUE : \n\n";
listQueue.display();
}
cout<<"\n\nFINAL SEQUENCE PRINT ARRAY :\n\n";
for(int i=0;i<finalSequenceIndex;i++){
	if(i == v-1){
		cout<<verticeVisited[i];
	}else{
		cout<<verticeVisited[i]<<" -> ";
	}
}

if(allVerticeList.head != NULL){
	cout<<"\n\nNot All Vertices Could Be Reached !\n\n";
}

return 0;
}


//CREATING THE NODE !
Node* llist::createnode(int vertexname,char visit){
    Node* temp =new Node;
    temp->vertexName = vertexname;
	temp->visited = visit;
    return temp;
}

//ADDING ELEMENT IN THE LIST !
void llist::addElement(int vertexname,char visit){

if(head == NULL){
    Node* temp = createnode(vertexname,visit);
    temp->next = head;
    head = temp;
}else{
    Node* temp = createnode(vertexname,visit);
    Node* ptr =head;
    while(ptr->next!=NULL){
    ptr=ptr->next;
    }
    temp->next=NULL;
    ptr->next=temp;
}
}


//ADD ELEMENT AT BEGINNING !
void llist::addatbeg(int vertexname,char visit){
Node * temp = createnode(vertexname,visit);
temp->next = head;
head = temp;
}



//PRINTING THE LINKED LIST !
void llist::display(){
Node* ptr = head;
if(head==NULL){
cout<<"\n List does not Exist !\n";
return;
}
while(ptr!=NULL){
cout<<"Vertex Name : "<<ptr->vertexName<<endl;
cout<<"Vertex Visited Status : "<<ptr->visited<<endl<<"\n";
ptr = ptr->next;
}
cout<<"\n\n";
}

//ADDING ELEMENT FROM ALL TO QUEUE


void llist::addingElementFromAlltoQueue(){
	Node * ptr;
	Node * prev;
	//int position = 1;
	if(head == NULL){
		return;
	}else{
		if(head->visited == 'v'){
			ptr = head;
			listQueue.addElement(ptr->vertexName,ptr->visited);
			head = ptr->next;
			addingElementFromAlltoQueue();
		}else{
			ptr = head->next;
			prev = head;
			while(ptr != NULL){
				if(ptr->visited == 'v'){
					listQueue.addElement(ptr->vertexName,ptr->visited);	
					prev->next = ptr->next;
				}
				prev = ptr;
				ptr = ptr->next;
			}

		}
	}
	
}





