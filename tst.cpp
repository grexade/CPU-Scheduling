#include <iostream>
#include <cstlib>
using namespace std;


 struct node
 {
     int data;
     struct node *next;
 };

 struct node * createNode(int);
 struct node * insertBack(struct node *, int);
 struct node * insertFront(struct node *, int);
 struct node * insertAfter(struct node * );
 struct node * deleteFront(struct node *);
 void display(struct node *);
 struct node * deleteBack(struct node *);
 void deleteAfter(struct node *);

 
    void FirstComeFirstServe(int process);
    void ShortestJobFirst(int process);
    void ShortestJobFirstPremptive(int process);
    void PriorityNonPremptive(int process);
    void PriorityPremptive(int process);
    void RoundRobin(int quantum, int process);




    void FirstComeFirstServe(int process){
    FILE *fp;
    if ((fp = fopen("input.txt", "r")) == NULL)
        return 0 ;
    while (fgets(line, LINE_MAX, fp) != NULL) {
      
    
    sscanf(line,"%d:%d:%d\n",insertBack(header1, line),&insertBack(header2, line) );


   int processes[] = { 1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
 
    int  burst_time[] = {10, 5, 8};
 
    findavgTime(processes, n,  burst_time);
   }

   void findWaitingTime(int processes[], int n,int bt[], int wt[])
    {
    
    wt[0] = 0;
 

    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}
 
void findTurnAroundTime( int processes[], int n,int bt[], int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
 
void findavgTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 

    findWaitingTime(processes, n, bt, wt);
 
    
    findTurnAroundTime(processes, n, bt, wt, tat);
 
    
    cout << "Processes  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";
 

    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

int main()
{
    struct node *header = NULL;
    header = (struct node *) malloc(sizeof (node));
    
    int choice;

    cout<<" "<<endl;
    	cout<<"CPU Scheduler Simulator"<<endl;
    	cout<<"1) Scheduling Method (None)"<<endl;
    	cout<<"2) Preemptive Mode"<<endl;
    	cout<<"3) Non-Preemptive Mode"<<endl;
    	cout<<"4) Show Result"<<endl;
    	cout<<"5) End Program"<<endl;
    	cout<<"Option >"<<endl;


    cin>>choice;
    	switch(choice){
    		case 1:
                cout<<"1) None: None of scheduling method chosen"<<endl;
    			cout<<"2) First come, First Served Scheduling"<<endl;
    			cout<<"3) Shortest-Job-First Scheduling"<<endl;
    			cout<<"4) Priority Scheduling"<<endl;
    			cout<<"5) Round-Robin Scheduling:"<<endl;

    			cout<<"option"<<endl;
    			 int option;
    			 cin>>option;
                if(option == 1){
                    cout<<"You have not make any scheduling method selectiion"<<endl;
                    
                }
    			else if(option == 2){
                    cout<<"output for Firstcome First Served Scheduling is writen in file"<<endl;

				}
				else if(option == 3){
                    cout<<"output for Shortest-Job First Scheduling is writen in file"<<endl;

				}
				else if(option == 4){
                    cout<<"output for Priority Scheduling is writen in file"<<endl;

				}
				else if(option == 5){
                    int quantum;
                    cout<<"Please Provide the quantum Number";
                    cin>>quantum;

                    cout<<"output for Round Robin Scheduling is writen in file"<<endl;

				}


    			break;
        }



    return 0;
    }

    struct node * createNode(int item){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(node));
	temp->data= item;
	temp->next=NULL;
	return temp;
}

struct node *insertFront(struct node *header, int item){
	struct node *temp = createNode(item);
	
	temp->next=header;
	header=temp;
	return header;
}
struct node *insertBack(struct node *header, int item){
	struct node *temp,*headertemp ;
	temp = createNode(item);
	
	if(header==NULL){
		header=temp;
		return header;
	}
	headertemp=header;
	while(headertemp->next!=NULL)
		headertemp=headertemp->next;
		headertemp->next=temp;
		return header;	
}


void insertAfter(struct node *afterNode, int item){

	struct node *temp = createNode(item);
	temp->next=afterNode->next;
	afterNode->next=temp;
}


void display(struct node *header){
	if(header==NULL)
		cout<<"list is empty"<<endl;
		
	
	struct node *temp = header;
	while(temp!=NULL){
		cout<<temp->data<<"-->";
		temp=temp->next;
	}
	cout<<endl;
}


struct node * deleteFront(struct node *header)
{
	struct node *temp;
if(header==NULL)
	return header;
temp=header;
	header= header->next;
free(temp);
return header;
}


struct node *deleteBack(struct node *header){
	struct node *temp,*headertemp;
	
	if(header==NULL)
		return header;
		headertemp = header;
	
	while(headertemp->next->next!=NULL){
		headertemp=headertemp->next;
		temp=headertemp->next;
		headertemp->next=NULL;
		free(temp);
		return header;
	}
	
}
void deleteAfter(struct node *afterNode){
	struct node *temp;
	if(afterNode->next==NULL||afterNode==NULL)
	return;
	temp=afterNode->next;
	afterNode->next=temp->next;
	free(temp);
}
