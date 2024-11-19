// DSPS assignment No. 9

/*  Implement c++ program for Music Library system about music name , their artist and year using doubly linked list.
       - Accept the above record.
       - Display the record.
       - Search the particular record.
       - Modify the particular record.
       - Remove / Delete the particular record.		  */

#include <iostream>
#include <string>
using namespace std;

class LMS 
{
    int year;
    string name, artist;
    LMS *next, *prev;

public:
    static LMS *start, *END; // Head and tail pointers for the doubly linked list.

    void accept();
    void display();
    void rdisplay();
    void search();
    void modify();
    void remove();
};

LMS *LMS::start = nullptr;
LMS *LMS::END = nullptr;

void LMS::accept() 
{
    LMS *nnode = new LMS;

    cout << "\nEnter the Music Name: ";
    cin >> nnode->name;

    cout << "Enter the Artist Name: ";
    cin >> nnode->artist;

    cout << "Enter the Year: ";
    cin >> nnode->year;

    nnode->next = nullptr;
    nnode->prev = nullptr;

    if (start == nullptr) 
    {
        start = nnode;
        END = nnode;
    } 
    else 
    {
        END->next = nnode;
        nnode->prev = END;
        END = nnode;
    }
    cout << "\nRecord added successfully.\n";
}

void LMS::display() 
{
    LMS *temp = start;
    int cnt = 0;

    cout << "\nName\t\tArtist\t\tYear\n";
    cout << "-----------------------------------\n";

    if (temp == nullptr) 
    {
        cout << "No records available.\n";
        return;
    }

    while (temp != nullptr) 
    {
        cout << temp->name << "\t\t" << temp->artist << "\t\t" << temp->year << "\n";
        temp = temp->next;
        cnt++;
    }

    cout << "\nTotal Records: " << cnt << "\n";
}

void LMS::rdisplay() 
{
    LMS *temp = END;

    cout << "\nName\t\tArtist\t\tYear\n";
    cout << "-----------------------------------\n";

    if (temp == nullptr) 
    {
        cout << "No records available.\n";
        return;
    }

    while (temp != nullptr) 
    {
        cout << temp->name << "\t\t" << temp->artist << "\t\t" << temp->year << "\n";
        temp = temp->prev;
    }
}

void LMS::search() 
{
    string nn;
    cout << "\nEnter the Music Name to Search: ";
    cin >> nn;

    LMS *temp = start;

    while (temp != nullptr) 
    {
        if (temp->name == nn) 
        
        {
            cout << "\nRecord Found:\n";
            cout << "Name: " << temp->name << ", Artist: " << temp->artist << ", Year: " << temp->year << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "\nRecord not found.\n";
}

void LMS::modify() 
{
    string nn;
    cout << "\nEnter the Music Name to Modify: ";
    cin >> nn;

    LMS *temp = start;

    while (temp != nullptr) 
    {
        if (temp->name == nn) 
        {
            cout << "\nRecord Found:\n";
            cout << "Name: " << temp->name << ", Artist: " << temp->artist << ", Year: " << temp->year << "\n";

            // Accept new details
            cout << "\nEnter the New Music Name: ";
            cin >> temp->name;

            cout << "Enter the New Artist Name: ";
            cin >> temp->artist;

            cout << "Enter the New Year: ";
            cin >> temp->year;

            cout << "\nRecord modified successfully.\n";
            return;
        }
        temp = temp->next;
    }

    cout << "\nRecord not found.\n";
}


void LMS::remove() 
{
    string nn;
    cout << "\nEnter the Music Name to Remove: ";
    cin >> nn;

    LMS *temp = start;

    while (temp != nullptr) 
    {
        if (temp->name == nn) 
        {
            if (temp == start) 
            {
                start = temp->next;
                if (start != nullptr)
                    start->prev = nullptr;
            } 
            else if (temp == END) 
            {
                END = temp->prev;
                if (END != nullptr)
                    END->next = nullptr;
            } 
            else 
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            delete temp;
            cout << "\nRecord deleted successfully.\n";
            return;
        }
        temp = temp->next;
    }

    cout << "\nRecord not found.\n";
}

int main() 
{
    LMS lms;
    int choice;

    while(true)
    {
        cout << "\nMenu:\n";
        cout << "1. Accept Record\n";
        cout << "2. Display Records\n";
        cout << "3. Display Records in Reverse Order\n";
        cout << "4. Search Record\n";
        cout<<  "5. Modify Record\n";
        cout << "6. Remove Record\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                lms.accept();
                break;
            case 2:
                lms.display();
                break;
            case 3:
                lms.rdisplay();
                break;
            case 4:
                lms.search();
                break;
            case 5:
                lms.modify();
                break;
            case 6:
                lms.remove();
                break;
            case 7:
                return 0;
               
            default:
                cout << "\nInvalid choice! Please try again.\n";
                 break;
        }
    } 
    

    return 0;
}

