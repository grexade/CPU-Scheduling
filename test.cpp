//clang 6.0.0

#include <iostream>
using namespace std;

int main()
{
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