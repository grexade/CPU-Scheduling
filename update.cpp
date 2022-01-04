#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream> 

using namespace std;

//void cpu(process,)
struct node * createNode(int, int, int, int);
struct node * insertBack(struct node *, int);
struct node * insertFront(struct node *, int);
struct node * deleteFront(struct node *);
struct node * deleteBack(struct node *);
struct node * deletAfter(struct node *,int);
struct node *sort_list (struct node *);
struct node * bubbleSortPriority(struct node *);
struct node * bubbleSortArrival(struct node *);
struct node * addProcessManually(struct node *);
struct node * readInputFile(struct node *);

void writeToOutputFile(string outF);
void readOutputFile();
void display(struct node *);
void nodeSwap(struct node *, struct node *);
void firstComeFirstServe(struct node *);

int sizeOfNode(struct node *);

 //Creation and declaration of Linked list 
struct node
{
	
    int arrivalTime;
    int burstTime;
	int priorityTime;
	int indexT;
	struct node *next;
};

string toString(double x) {
   stringstream ss;
   ss << x;
   return ss.str();
}

int main(void){

}

// Code for creating a linked List
struct node * createnode(int arrivalT, int burstT, int priorityT, int index)
{
	struct node *temp=NULL;
	temp=(struct node *)malloc(sizeof(node));
	temp->arrivalTime=arrivalT;
    temp->burstTime=burstT;
	temp->priorityTime=priorityT;
	temp->indexT=index;
	temp->next=NULL;
	return temp;
}


//Code for inserting to the back of the Linked list
struct node * insertback(struct node *header, int arrivalT, int burstT, int priorityT,int index)
{
	struct node * temp=(createnode(arrivalT, burstT, priorityT, index));
	struct node * findback;
	if(header==NULL)
		{
			header=temp;
			return header;
		}
	findback=header;
	while(findback->next!=NULL)
		findback=findback->next;
	findback->next=temp;
	return header;
}

//Code for inserting to the front of the Linked List
struct node * insertfront(struct node *header, int arrivalT, int burstT, int priorityT,int index)
{
	struct node * temp=createnode(arrivalT, burstT, priorityT, index);
	temp->next=header;
	header=temp;
	return header;
}

struct node * deleteFront(struct node *header)
{
	struct node *temp;
	if(header==NULL)
	{
		cout<<" The list is empty\n";
		return header;
	}
	temp=header;
	header=header->next;
	free(temp);
	return header;
}

struct node *deleteBack(struct node *header){
	struct node *temp,*headertemp;
	
	if(header==NULL){

        cout<<"The list is Empty";
        return header;
    }
		headertemp = header;
	
	while(headertemp->next->next!=NULL){
		headertemp=headertemp->next;
		temp=headertemp->next;
		headertemp->next=NULL;
		free(temp);
		return header;
	}
	
}

struct node * deleteAfter(struct node *header,int x)
{
	struct node *temp;
	struct node *headertemp;
	if(header==NULL)
	{
		cout<<" The list is empty\n";
		return header;
	}
	headertemp=header;
	while(headertemp->burstTime == x){
        headertemp=headertemp->next;
        temp = headertemp->next;
        headertemp->next=headertemp->next;
        free(temp); }
        return header;
		
}

struct node* sort_list(struct node* head)
{
    struct node* temp=head;
    struct node* tempNode = NULL;
    struct node* tempHead = temp;
    struct node* tempNext = temp->next;
	int c =sizeOfNode(head);

	for(int i=0; i<c;i++)
	{
		while(tempNext!=NULL) {

       if(tempHead->arrivalTime > tempNext->arrivalTime) {
       	
           tempNode = tempHead;
           tempNode->next=NULL;
           tempHead = tempNext;
           tempNode->next = tempHead->next;
           
           tempHead->next = tempNode;
           
          // tempNext = tempHead->next;
           //tempHead=tempHead->next;
          //print_list(tempHead);

        }
        else {  
            tempHead = tempHead->next;
            tempNext = tempNext->next;

        }
    }
	}

    return head;
}


struct node * bubbleSortPriority(struct node *head)
{
	int swapped;

	struct node *leftPtr; // for the beginning of the list
	struct node *rightPtr = NULL; // indicating the end of the list
	do
	{	
		swapped = 0;
		leftPtr = head;
		while(leftPtr->next != rightPtr)
		{
			if (leftPtr->priorityTime> leftPtr->next->priorityTime) 
			{
				nodeSwap(leftPtr, leftPtr->next); 
                swapped = 1; 
			}
			leftPtr = leftPtr->next;
		}

		rightPtr = leftPtr;

	}while(swapped);
}


struct node * bubbleSortArrival(struct node *head)
{
	int swapped;

	struct node *leftPtr; // for the beginning of the list
	struct node *rightPtr = NULL; // indicating the end of the list
	do
	{	
		swapped = 0;
		leftPtr = head;
		while(leftPtr->next != rightPtr)
		{
			if (leftPtr->arrivalTime> leftPtr->next->arrivalTime) 
			{
				nodeSwap(leftPtr, leftPtr->next); 
                swapped = 1; 
			}
			leftPtr = leftPtr->next;
		}

		rightPtr = leftPtr;

	}while(swapped);
}

struct node * addProcessManually(struct node *header)
{
	int i=sizeOfNode(header);
	while(true)
	{
		char c;
		cout<<"\n Would you like to add a process Manually?\n press Y to access and any key to decline: ";
		cin>>c;
		if(c=='Y'||c=='y')
		{
			i+=1;
			int b,a,p;
			cout<<"Enter burst Time: ";
			cin>>b;
			cout<<"Arival time: ";
			cin>>a;
			cout<<"Enter Priority: ";
			cin>>p;
			header=insertback(header,b,a,p,i);	
		}
		else
		{
			display(header);
			return header;
			
		}	
		
	}
}

struct node * readInputFile(struct node *header)//reading file
{
	

	FILE *fp;
	char line[LINE_MAX];
	
	
	if ((fp = fopen("input.txt", "r")) == NULL)
	        {
	        	cout<<" could not read file !"<<endl;
	        	return 0;
			}
	int x=1;        
	while (fgets(line, LINE_MAX, fp) != NULL) {
		 int num[3];
	        sscanf(line,"%d:%d:%d\n",&num[0],&num[1],&num[2]);
	        //printf("num1=%u num2=%u num3=%u\n",num[0],num[1],num[2]);
	       // cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<" \n";
	    	header=insertback(header,num[0],num[1],num[2],x);
	    	x=x+1;
	    		
	}
	fclose(fp);
	
	return header;
		
}


void writeToOutputFile(string outF){
	ofstream write_file("output.txt");

	if (!write_file) {
			write_file.open("output.txt");
			write_file <<outF<<endl;
		
		write_file.close(); 
		cout<<"file has been updated ! \n";
	}
	else {
		write_file <<outF<<endl;
		write_file.close(); 
		cout<<"file has been updated ! \n";
	}
}

void readOutputFile(void)
{
	string containt;
	ifstream read("output.txt");
	if (read.is_open())
{
	string line;
	while (getline(read, line))
    {

    	cout << line << endl;
    }
}
	read.close();
	cout<<containt;

}



void display(struct node *header)
{
    struct node *temp;
	if(header==NULL)
	{
		cout<<" The Linked-List is empty \n";	
	}
	
	temp=header;
	while(temp!=NULL)
	{
		cout<<temp->burstTime<<" "<<temp->arrivalTime<<" "<<temp->priorityTime<<" index "<<temp->indexT<<" --> ";
		temp=temp->next;
	}
	cout<<endl;
}


void nodeSwap (struct node * node_1, struct node *node_2)
{
	int b,a,p,i;
	b= node_1->burstTime;
	a=node_1->arrivalTime;
	p=node_1->priorityTime;
	i=node_1->indexT;
	
	node_1->burstTime= node_2 -> burstTime;
	node_1->arrivalTime= node_2 -> arrivalTime;
	node_1->priorityTime= node_2 -> priorityTime;
	node_1->indexT= node_2 -> indexT;
	node_2 -> burstTime= b;
	node_2 -> arrivalTime= a;
	node_2 -> priorityTime= p;
	node_2 -> indexT= i;
}

void firstComeFirstServe(struct node *header)
{
    int waitTime =0;
	int trackTime =0;
	double sum=0;
	double avgTime;
	int size=sizeOfNode(header);
	struct node * temp=NULL;
	temp=bubbleSortArrival(header);
	//display(header);
	
	std::string output="  \nScheduling Method: First Come First Served \n Processes Waiting Times: \n";
	
	
	
	int x=1;
	while(header!=NULL)
	{
		
			if(x==1)
			{
			
				if( header->next!=NULL)
				
				{	
					
					output=output+"P" +toString(header->indexT) +": " + toString(trackTime) + " ms \n";
					trackTime+=header->burstTime;
					waitTime+=header->burstTime-header->arrivalTime;
					sum+=waitTime;
					x=0;
				}
			}
			else if( header->next!=NULL)
				{
				
					output=output+"P" +toString(header->indexT) +": " + toString(trackTime-header->arrivalTime) + " ms \n";
					trackTime+=header->burstTime;
					waitTime+=header->burstTime-header->arrivalTime;
					sum+=waitTime;
				}
			else if(header->next==NULL)
				{
					output=output+"P" +toString(header->indexT)+": " + toString(trackTime-header->arrivalTime) + " ms \n";
					trackTime+=header->burstTime;
					waitTime+=header->burstTime-header->arrivalTime;
					
				}
				header=header->next;
		
	}

	avgTime=sum/size;
	output=output+ "Average Waiting Time:  "+ toString(avgTime)+" ms \n";
	cout<<output;
	writeToOutputFile(output);
}


int sizeOfNode(struct node *header)
{
	int x=0;
	while(header!=NULL)
	{
		x++;
		header=header->next;
	}
	return x;	
}

