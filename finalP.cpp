#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <sstream> 
#include <string>
#include <string.h>

#define LINE_MAX 1024

using namespace std;

    // Given below is the code for compilation.
    // gcc -o finalP *.cpp -lstdc++
    
struct node * createNode(int, int, int, int);
struct node * insertBack(struct node *, int, int, int, int);
struct node * insertFront(struct node *, int, int, int, int);
struct node * deleteFront(struct node *);
struct node * deleteBack(struct node *);
struct node * deletAfter(struct node *,int);
struct node *sortList (struct node *);
struct node * bubbleSortPriority(struct node *);
struct node * bubbleSortArrival(struct node *);
struct node * bubbleSortBurst(struct node *);
struct node * addProcessManually(struct node *);
struct node * readInputFile(struct node *);

void writeToOutputFile(string outF);
void readOutputFile();
void display(struct node *);
void nodeSwap(struct node *, struct node *);
void firstComeFirstServe(struct node *);
void shortestJobFirstNPM(struct node *);
void shortestJobFirstPM(struct node *);
void priorityNPM(struct node *);
void priorityPM(struct node *);
void roundRobin(struct node *, int);

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


	int choice;

	while(true)
	{
    

        cout<<" "<<endl;
    	cout<<"CPU Scheduler Simulator"<<endl;
    	cout<<"1) Scheduling Method (None)"<<endl;
    	cout<<"2) Preemptive Mode"<<endl;
    	cout<<"3) Non-Preemptive Mode"<<endl;
    	cout<<"4) Show Result"<<endl;
    	cout<<"5) End Program"<<endl;
    	cout<<"Option >"<<endl;
        cin>>choice;


		
		switch(choice)
		{
			case 1:
				{
					int secondChoice;


					cout<<" \n 1-> First Come, First Served Scheduling";
    				cout<<"\n 2-> Shortest-Job-First Scheduling";
					cout<<"\n 3-> Priority Scheduling";
					cout<<"\n 4-> Round-Robin Scheduling ";
					cout<<"\n please select you Scheduling Method : ";


					cin>>secondChoice;
				
					switch(secondChoice)
					{
						case 1:
							{

									struct node *header=NULL;
									header=readInputFile(header);
									header=addProcessManually(header);
									firstComeFirstServe(header);
				
							}
				
						break;
						case 2:
							{	
                                cout<<"\n Shortest Job First Scheduling";
								cout<<"\n 1-> Non Preemtive Method";
								cout<<"\n 2-> preemtive method";
								int n;
								
									cout<<"\n please make a method selection: ";
									cin>>n;
									
									switch(n)
									{
										case 1:
											{
												struct node *header=NULL;
												header=readInputFile(header);
												header=addProcessManually(header);
												//display(header);
												shortestJobFirstNPM(header);
											}
											break;
										case 2:
											{
												struct node *header=NULL;
												header=readInputFile(header);
												header=addProcessManually(header);
												//display(head);
												shortestJobFirstPM(header);							
											}
											break;
											default:
												{
													cout<<"You should either select 1 or 2";
												}
												break;
							
									}
						}
								
						break;
						case 3:
							{	
                                cout<<"\n Priority Scheduling Method";
								cout<<"\n 1-> Non Preemtive Method";
								cout<<"\n 2-> preemtive method";
								int n;
								
									cout<<"\n please make a method selection: ";
									cin>>n;
								
									switch(n)
									{
										case 1:
											{
													struct node *header=NULL;
													header=readInputFile(header);
													header=addProcessManually(header);
													//display(header);
													priorityNPM(header);
											}
											break;
										case 2:
											{
												struct node *header=NULL;
													header=readInputFile(header);
													header=addProcessManually(header);
													//display(header);
													priorityPM(header);					
											}
											break;
											default:
												{
													cout<<"You should either select 1 or 2";
												}
												break;
							
									}
							
							}
								
						break;
						case 4:
							{
                                 cout<<"\n Round Robin Scheduling Method";

                                 int quantumNumber;

								struct node *header=NULL;
								header=readInputFile(header);
								header=addProcessManually(header);
                                cin>>quantumNumber;
								//display(header);
								roundRobin(header, quantumNumber);
							}
							
						break;
						default:
							{
								cout<<" you have made a wrong choice, selction should be between 1-4";
							}
							break;
						
					}
				}
			break;
			case 2:
				{
						cout<<"\n 1-> These are all Preemptive Methods";
                        cout<<"\n 1-> Shortest Job First Scheduling";
						cout<<"\n 2-> Priority Scheduling";
						int n;
						cout<<"\n please select a method : ";
						cin>>n;
					
						switch(n)
						{
							case 1:
									{
										struct node *header=NULL;
										header=readInputFile(header);
										header=addProcessManually(header);
										//display(header);
										shortestJobFirstPM(header);
									}
									break;
									case 2:
									{
										struct node *header=NULL;
										header=readInputFile(header);
										header=addProcessManually(header);
										//display(header);
										priorityPM(header);							
									}
									break;
									default:
									{
										cout<<" Selection should be 1 or 2";
									}
									break;
							
									}
					
				}
			break;
			case 3:
				{
                    cout<<"\n 1-> These are non Preemptive Methods";
					cout<<"\n 1-> Shortest Job First Scheduling";
                   
						cout<<"\n 2-> Priority Scheduling";
						int n;
						cout<<"\n please select a method : ";
						cin>>n;
					
						switch(n)
						{
							case 1:
									{
										struct node *header=NULL;
										header=readInputFile(header);
										header=addProcessManually(header);
										//display(header);
										shortestJobFirstNPM(header);
									}
									break;
									case 2:
									{
										struct node *header=NULL;
										header=readInputFile(header);
										header=addProcessManually(header);
										//display(header);
										priorityNPM(header);							
									}
									break;
									default:
									{
										cout<<" Selection should be 1 or 2";
									}
									break;
							
									}
				}
			break;
			case 4:
				{
					readOutputFile();
				}
			break;
			case 5:
				{
					//readOutputFile();
					return 0;
				}
			break;
			default:
				break;
			
		}
	}
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
struct node * insertBack(struct node *header, int arrivalT, int burstT, int priorityT,int index)
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
struct node * insertFront(struct node *header, int arrivalT, int burstT, int priorityT,int index)
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

struct node* sortList(struct node* head)
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

struct node * bubbleSortBurst(struct node *head)
{
	int swapped;

	struct node *leftPtr; // beginning
	struct node *rightPtr = NULL; // end
	do
	{	
		swapped = 0;
		leftPtr = head;
		while(leftPtr->next != rightPtr)
		{
			if (leftPtr->burstTime > leftPtr->next->burstTime) 
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
		
			display(header);
			return header;
			
			
		
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

void shortestJobFirstNPM(struct node * header)
{
    int waitTime=0;
	int trackTime=0;
	double sum=0;
	double avgT;
	int size=sizeOfNode(header);
	struct node * temp=NULL;
	struct node * temp1=NULL;
	temp=bubbleSortBurst(header);


	std::string output="  \nScheduling Method: Shortest Job First Non-Premptive \n Process Waiting Times: \n";
	
	
	
	while(header!=NULL)
	{
			
			output=output+"P" +toString(header->indexT) +": " + toString(trackTime) + " ms \n";
			trackTime+=header->burstTime-header->arrivalTime;
			waitTime+=header->burstTime-header->arrivalTime;
			sum+=waitTime;
			break;

	}
	header=header->next;
	temp1=bubbleSortBurst(header);
	
	
	cout<<"\n"<<sum;
	while(header!=NULL)		
		{
		
			 if( header->next!=NULL  )
			{
				sum-=header->arrivalTime;
				output=output+"P" +toString(header->indexT) +": " + toString(trackTime-header->arrivalTime) + " ms \n";
				trackTime+=header->burstTime ;
				waitTime+=header->burstTime;
				sum+=waitTime;
						
			}
			else if(header->next==NULL)
			{
				sum-=header->arrivalTime;
				output=output+"P" +toString(header->indexT)+": " + toString(trackTime-header->arrivalTime) + " ms \n";
				trackTime+=header->burstTime;
				waitTime+=header->burstTime-header->arrivalTime;
						
			}
		
			header=header->next;
	}

	avgT=sum/size;
	output=output+ "Average Waiting Time:  "+ toString(avgT)+" ms \n";
	cout<<output;
	writeToOutputFile(output);
	
}


void shortestJobFirstPM(struct node *header)
{
	int size=sizeOfNode(header);
	struct node * temp=NULL;
	struct node * temp1=NULL;
	temp=bubbleSortBurst(header);
	

	std::string output="  \nScheduling Method: Shortest Job First Preemptive \n Process Waiting Times: \n";
	
	int waitTime=0;
	int trackTime=0;
	double sum=0;
	double avgT;
	int time=0;
	int a,b,c,p,i;
	a=header->arrivalTime;
	b=header->burstTime;
	p=header->priorityTime;
	i=header->indexT;
	header=header->next;
	//display(header);

   //processEV for process Evaluation.
	bool processEV=true;
	do
	{
		
		if(time==header->arrivalTime && b>header->burstTime)
		{
			processEV=false;

		}
		else if(b==0)
		{
			output=output+"P" +toString(i) +": " + toString(0) + " ms \n";
			processEV=false;
		}
		else
		{
			time+=1;
			b-=1;
			trackTime+=time;
			//display(header);
			
		}
	

	}while(processEV==true);
	sum+=time;
	
	temp=bubbleSortBurst(header);
	//cout<<time<<" "<<b<<"\n";
	if(b!=0)
		header=insertBack(header,b,a,p,i);
	
	int burstTemp;
	while(header!=NULL)
	{
		
		burstTemp=header->burstTime;
		
		if(burstTemp!=-1)
		{
			cout<<header->burstTime;
			if(time==header->arrivalTime && b>header->burstTime)
			{
				
				header=insertBack(header,header->burstTime,header->arrivalTime,header->priorityTime,header->indexT);
				header=header->next;
				burstTemp=0;
	
			}
			else if(header->burstTime==0)
			{
				output=output+"P" +toString(header->indexT) +": " + toString(time-header->arrivalTime) + " ms \n";
				display(header);
				
				burstTemp=0;
				header=header->next;
			}
			else
			{
				time+=1;
				header->burstTime-=1;
				trackTime+=time;
				//display(header);
				
				burstTemp-=1;
				//cout<<burstTemp<<" ";
			}
		}


		sum+=time;

	}
	

	avgT=sum/size;
	output=output+ "Average Waiting Time:  "+ toString(avgT)+" ms \n";
	cout<<output;
	writeToOutputFile(output);
}

void priorityNPM(struct node *header)
{
	int size=sizeOfNode(header);
	struct node * temp=NULL;
	struct node * temp1=NULL;
	temp=bubbleSortArrival(header);
	
	
	int waitTime=0;
	int trackTime=0;
	double sum=0;
	//double tsum=0;
	double avgT;
	std::string output="  \n Scheduling Method: Priority Scheduling Non-Preemptive \n Process Waiting Times: \n";
	int x=1;
	while(header!=NULL)
	{
			
			output=output+"P" +toString(header->indexT) +": " + toString(trackTime) + " ms \n";
			trackTime+=header->burstTime-header->arrivalTime;
			waitTime+=header->burstTime-header->arrivalTime;
			sum+=waitTime;
			break;

	}
	header=header->next;
	temp1=bubbleSortPriority(header);
	//display(header);
	
	while(header!=NULL)		
		{
		
			 if( header->next!=NULL  )
			{
				sum-=header->arrivalTime;
				output=output+"P" +toString(header->indexT) +": " + toString(trackTime-header->arrivalTime) + " ms \n";
				trackTime+=header->burstTime ;
				waitTime+=header->burstTime;
				sum+=waitTime;
						
			}
			else if(header->next==NULL)
			{
				sum-=header->arrivalTime;
				output=output+"P" +toString(header->indexT)+": " + toString(trackTime-header->arrivalTime) + " ms \n";
				trackTime+=header->burstTime;
				waitTime+=header->burstTime-header->arrivalTime;
						
			}
		
			header=header->next;
	}
	//cout<<"sum"<<sum<<" "<<wait;
	avgT=sum/size;
	output=output+ "Average Waiting Time:  "+ toString(avgT)+" ms \n";
	cout<<output;
	writeToOutputFile(output);
}

void priorityPM(struct node *header)
{
	int size=sizeOfNode(header);
	struct node * temp=NULL;
	struct node * temp1=NULL;
	temp=bubbleSortArrival(header);
	
	
	int waitTime=0;
	int trackTime=0;
    int time = 0;
    int a, b, i ,p;
	double sum=0;
	//double tsum=0;
	double avgT;
	std::string output="  \n Scheduling Method: Priority Scheduling Non-Preemptive \n Process Waiting Times: \n";
	int x=1;
	while(header!=NULL)
	{
			
			output=output+"P" +toString(header->indexT) +": " + toString(trackTime) + " ms \n";
			trackTime+=header->burstTime-header->arrivalTime;
			waitTime+=header->burstTime-header->arrivalTime;
			sum+=waitTime;
			break;

	}
	header=header->next;
	temp1=bubbleSortPriority(header);
	//display(header);
	
	
    bool processEV=true;
	do
	{
		
		if(time==header->arrivalTime && b>header->burstTime)
		{
			processEV=false;

		}
		else if(b==0)
		{
			output=output+"P" +toString(i) +": " + toString(0) + " ms \n";
			processEV=false;
		}
		else
		{
			time+=1;
			b-=1;
			trackTime+=time;
			//display(header);
			
		}
	

	}while(processEV==true);
    
        while(header!=NULL)		
		{
		
			 if( header->next!=NULL  )
			{
				sum-=header->arrivalTime;
				output=output+"P" +toString(header->indexT) +": " + toString(trackTime-header->arrivalTime) + " ms \n";
				trackTime+=header->burstTime ;
				waitTime+=header->burstTime;
				sum+=waitTime;
						
			}
			else if(header->next==NULL)
			{
				sum-=header->arrivalTime;
				output=output+"P" +toString(header->indexT)+": " + toString(trackTime-header->arrivalTime) + " ms \n";
				trackTime+=header->burstTime;
				waitTime+=header->burstTime-header->arrivalTime;
						
			}
		
			header=header->next;
	}
	//cout<<"sum"<<sum<<" "<<wait;
	avgT=sum/size;
	output=output+ "Average Waiting Time:  "+ toString(avgT)+" ms \n";
	cout<<output;
	writeToOutputFile(output);
}

void roundRobin(struct node *header, int quantum)
{
	int size= sizeOfNode(header);
    int proQuantum = quantum;

	struct node * temp=header;
	temp=bubbleSortArrival(header);
	//display(header);
	
	
	int waitTime=0;
	int trackTime=0;
	double sum=0;
	double tsum=0;
	double avgT;
    int t;
	std::string output="  \n Scheduling Method: Round Robin \n Process Waiting Times: \n";
	int x;
	int y;
	int i=0;
	int j=0;
	
		
	while(header!=NULL)
		{
			
                if (header->burstTime > proQuantum)
                {
                    // Increase the value of t i.e. shows
                    // how much time a process has been processed
                    trackTime+= proQuantum;
 
                    // Decrease the burst_time of current process
                    // by quantum
                    header->burstTime -= quantum;
                }


			if(header->indexT==y)
			{
				break;
			}
			y=header->indexT;
			
			
			
			if(header->burstTime !=0)
			{
				
				x=header->burstTime;
				if(x > 2)
				{
					x=x-2;
					insertBack(header,x,header->arrivalTime,header->priorityTime,header->indexT);
					tsum+=2;
					
				}
				else if(x==2)
				{
					x=x-2;
					sum+=tsum-header->arrivalTime-(2*i);
					output=output+"P" +toString(header->indexT) +": " + toString(tsum-header->arrivalTime-(2*i)) + " ms \n";
					tsum+=2;
					
			
				}
				else if(x==1)
				{
					x=x-1;
					sum+=tsum-header->arrivalTime-(2*i);
					output=output+"P" +toString(header->indexT) +": " + toString(tsum-header->arrivalTime-(2*i)) + " ms \n";
					tsum+=1;
			
					
				}
				if(header->indexT==5)
					i++;
	
				
			}
			header=header->next;
		
			
			
		}
	//	cout<<"sum"<<sum<<" "<<wait;
		avgT=sum/size;
		output=output+ "Quatum number = "+ toString(proQuantum) +" Average Waiting Time:  "+ toString(avgT)+" ms \n";
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

