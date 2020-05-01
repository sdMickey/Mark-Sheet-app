#include <iostream>
#include <string>

using namespace std;

class MarkSheet
{
    string name;
    int roll;
    int science;
    int english;
    int maths;

public:

    MarkSheet()
    {
        name = "";
        roll = 0;
        science = 0;
        english = 0;
        maths = 0;
    }

    void add();
    void view();
    void del();
    void update();

    int getRoll() {
        return roll;
    }

    int totalMarks() {
        return science + english + maths;
    }
};

void MarkSheet::add()
{
    cout << "Name: ";
    cin.ignore(100, '\n');
    getline(cin, name);
    cout << "Roll number: ";
    cin >> roll;
    cout << "Science marks: ";
    cin >> science;
    cout << "English marks: ";
    cin >> english;
    cout << "Maths marks: ";
    cin >> maths;
    cout << endl << endl;
}

void MarkSheet::view()
{
    cout << endl;
    cout << "Name: " << name << endl;
    cout << "Roll number: " << roll << endl;
    cout << "Science marks: " << science << endl;
    cout << "English marks: " << english << endl;
    cout << "Maths marks:  " << maths << endl;
    cout << "Total marks:  " << totalMarks() << endl;
    cout << endl << endl;
}

void MarkSheet::del()
{
    name = "";
    roll = 0;
    science = 0;
    english = 0;
    maths = 0;
}

void MarkSheet::update()
{
    cout << "Name: ";
    cin.ignore(100, '\n');
    getline(cin, name);
    cout << "Science marks: ";
    cin >> science;
    cout << "English marks: ";
    cin >> english;
    cout << "Maths marks: ";
    cin >> maths;
    cout << endl << endl;
}

int main()
{
    int i;
    MarkSheet m[20];
    int index = 0;
    int choice, rno;

    do
    {
        cout << "\n ************ Main Menu ************ \n";
        cout << "1. Add" << endl << "2. View" << endl << "3. Delete" << endl << "4. Update" << endl << "5. Exit" << endl;
        cout << "Please choose your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        //Add
        case 1:
            if(index < 20){
                cout << "Enter details of student " << index+1 << ": " <<endl;
                m[index].add();
                for(i=0 ; i<20 ; i++) {
                    if(i == index) {
                        continue;
                    }
                    else if(m[i].getRoll() == m[index].getRoll()) {
                        cout << "Student with roll number " << m[index].getRoll() << " exists" << endl << endl;
                        m[index].del();
                        break;
                    }
                }
                if (i > 19){
                    cout << "Entry added..." << endl << endl;
                    index++;
                }
                break;
            }
            else{
                cout << "Limit exceeded." << endl;
                break;
            }

        //View
        case 2:
            cout << "You want to view 1. All, or with a specific 2. Roll number: ";
            int x;
            cin >> x;
            switch(x)
            {
            case 1:
                for(i=0 ; i<20 ; i++) {
                    if(m[i].getRoll() > 0)
                        m[i].view();
                }
                break;
            case 2:
                cout << "Roll number: ";
                cin >> rno;
                for(i=0 ; i<20 ; i++) {
                    if(m[i].getRoll() == rno) {
                        m[i].view();
                        break;
                    }
                }
                if (i > 19)
                    cout << "Invalid roll number!!!" << endl << endl;
                break;
            default:
                cout << "Invalid choice.";
                break;
            }
            break;

        //Delete
        case 3:
            cout << "Enter roll number of the student whose details you want to delete..." << endl;
            cout << "Roll number: ";
            cin >> rno;
            for(i=0 ; i<20 ; i++) {
                if(m[i].getRoll() == rno) {
                    m[i].del();
                    cout << "Entry deleted... " << endl << endl;
                    break;
                }
            }
            if (i > 19)
                cout << "Invalid roll number!!!" << endl << endl;
            break;

        //Update
        case 4:
            cout << "Enter roll number of the student whose details you want to update..." << endl;
            cout << "Roll number: ";
            cin >> rno;
            for(i=0 ; i<20 ; i++) {
                if(m[i].getRoll() == rno) {
                    m[i].update();
                    cout << "Entry updated... " << endl << endl;
                    break;
                }
            }
            if (i > 19)
                cout << "Invalid roll number!!!" << endl << endl;
            break;

        //Exit
        case 5:
            break;

        default:
            cout << "Invalid Choice...";
            break;
        }
    }while(choice != 5);

    return 0;
}
