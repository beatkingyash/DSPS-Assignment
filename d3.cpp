//DSPS Assignment No 3

/* Write c++ program to store Name, Roll no. and Address of the students in array who attended the training program in random order. Write the function for...
     1. Searching whether particular student attended training program or not using linear search.
     2. Searching whether particular student attended training program or not using binary search */

#include<iostream>
using namespace std;

int i, n;

class student
{
public:
	int rno;
	string name, add;


	void accept();
	void display();
	void Lsearch();
	void Bsearch();
	
}a[100];

void student::accept()
{
	cout<<"\nEnter the student name: ";
	cin>>name;
	cout<<"Enter the student roll no.: ";
	cin>>rno;
	cout<<"Enter the student address.: ";
	cin>>add;
}

void student::display()
{
	cout << "\n" << name << "\t" << rno << "\t" << add ;
}


void student::Lsearch() 
{
    int r;
    bool found = 0;
    cout << "Enter the roll no. you want to search: ";
    cin >> r;

    for (i = 0; i < n; i++) 
    {
        if (a[i].rno == r) 
        { 
            found = 1;
            cout << "\nRoll No. " << r << " is present in training program.";
            
            break;
        }
    }

    if (!found) 
    {
        cout << "\nRoll No. " << r << " is not present in training program. ";;
    }
}


void student::Bsearch()
{
	int r;
	cout << "Enter the roll no. you want to search: ";
    	cin >> r;
    	
    	for(i = 0; i < n-1; i++)
    	{
    	  for(int j = 0; j < n; j++)
    	  {
    	    if(a[i].rno > a[j].rno)
    	    {
    	    student temp = a[j];
    	    a[j] = a[i];
    	    a[i] = temp;
    	    }
    	  }
    	}
    	
    	int mid, low = 0, high = n-1;
    	bool found = 0;
    	
    	while(low <= high)
    	{
    	   mid = (low+high) / 2;
    	   
    	   if(a[mid].rno == r)
    	   {
    	     found = 1;
    	     cout <<"\nRoll No. " << r << " is present in training program.";
    	     
    	     break;
    	   }
    	   
    	   else if(a[mid].rno > r)
    	   {
    	    high = mid-1;
    	   }
    	   
    	   else
    	   {
    	    low = mid+1;
    	   }
    	 }
    	 
    	 if(!found)
    	 {
    	  cout << "\nRoll No. " << r << " is not present in training program. ";;
    	 }
    	  
 }
 
 
int main()
{
    int choice=1;

    while(choice != 5)
    {
        cout << "\n\nMenu.\n1.Accept the record.\n2.Display the record.\n3.Find Element (L Search).\n4.Find Element  (B Search).\n5.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "Enter the number of records you want to create: ";
            cin >> n;
            for(i = 0; i < n; i++)
            {
                a[i].accept();
            }
            break;

        case 2:
            cout << "\nName\tRollNo\tAddress";
            for(i = 0; i < n; i++)
            {
                a[i].display();
            }
            break;
            
        case 3:
        	a[0].Lsearch();
        	break;
        	
        case 4:
        	a[i].Bsearch();
        	break;
        	
        case 5:
        	
            	choice=5;
            	break;

            default:
                cout << "Invalid choice\n";
                break;
            
            }
    }

    return 0;
}



	
