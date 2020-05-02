#include <iostream>
#include <string>
#include <conio.h>

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

    int getScience() {
        return science;
    }

    int getEnglish() {
        return english;
    }

    int getMaths() {
        return maths;
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

int operation(string input)
{
    /*
    ==, >, >=, <, <=, !=, &&, ||

    ==      =1
    >       =2
    >=      =3
    <       =4
    <=      =5
    !=      =6
    &&      =7
    ||      =8
    invalid =9
    */

    if ( input == "==" )
    {
        return 1;
    }

    else if ( input == ">" )
    {
        return 2;
    }

    else if ( input == ">=" )
    {
        return 3;
    }

    else if ( input == "<" )
    {
        return 4;
    }

    else if ( input == "<=" )
    {
        return 5;
    }

    else if ( input == "!=" )
    {
        return 6;
    }

    else if ( input == "&&" )
    {
        return 7;
    }

    else if ( input == "||" )
    {
        return 8;
    }
    else
    {
        return 9;
    }
}

void viewCase(int op, int x, MarkSheet m[], int c)
{
    /*
    for c:
        1 = roll number
        2 = science
        3 = english
        4 = maths
        5 = total
    */

    int i, m1[20], temp = 0;

    if(c == 1)
    {
        for(i=0 ; i<20 ; i++)
        {
            m1[i] = m[i].getRoll();
        }
    }
    else if(c == 2)
    {
        for(i=0 ; i<20 ; i++)
        {
            m1[i] = m[i].getScience();
        }
    }
    else if(c == 3)
    {
        for(i=0 ; i<20 ; i++)
        {
            m1[i] = m[i].getEnglish();
        }
    }
    else if(c == 4)
    {
        for(i=0 ; i<20 ; i++)
        {
            m1[i] = m[i].getMaths();
        }
    }
    else if(c == 5)
    {
        for(i=0 ; i<20 ; i++)
        {
            m1[i] = m[i].totalMarks();
        }
    }

    // ==
    if(op == 1)
    {
        for(i=0 ; i<20 ; i++) {
            if(m1[i] == x) {
                m[i].view();
                break;
            }
        }

        if (i > 19)
            cout << "\nInvalid roll number!!! No entries available." << endl << endl;
    }

    // >
    else if(op == 2)
    {
        temp = 0;
        for(i=0 ; i<20 ; i++) {
            if(m1[i] > x) {
                m[i].view();
                temp--;
            }
            temp++;
        }

        if (temp > 19)
            cout << "\nInvalid roll number!!! No entries available." << endl << endl;
    }

    // >=
    else if(op == 3)
    {
        temp = 0;
        for(i=0 ; i<20 ; i++) {
            if(m1[i] >= x) {
                m[i].view();
                temp--;
            }
            temp++;
        }

        if (temp > 19)
            cout << "\nInvalid roll number!!! No entries available." << endl << endl;
    }

    // <
    else if(op == 4)
    {
        temp = 0;
        for(i=0 ; i<20 ; i++) {
            if(m1[i] < x && m1[i] != 0) {
                m[i].view();
                temp--;
            }
            temp++;
        }

        if (temp > 19)
            cout << "\nInvalid roll number!!! No entries available." << endl << endl;
    }

    // <=
    else if(op == 5)
    {
        temp = 0;
        for(i=0 ; i<20 ; i++) {
            if(m1[i] <= x && m1[i] != 0) {
                m[i].view();
                temp--;
            }
            temp++;
        }

        if (temp > 19)
            cout << "\nInvalid roll number!!! No entries available." << endl << endl;
    }

    // !=
    else if(op == 6)
    {
        temp = 0;
        for(i=0 ; i<20 ; i++) {
            if(m1[i] != x && m1[i] != 0) {
                m[i].view();
                temp--;
            }
            temp++;
        }

        if (temp > 19)
            cout << "\nInvalid roll number!!! No entries available." << endl << endl;
    }

    else
    {
        cout << "Invalid Operator... Displaying all entries" << endl;
    }
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
            {
            cout << "You want to view 1. All, or with a 2. Specificity: ";
            int x,y;
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
                {
                string op; // operator
                int sm, em, mm, tm; // all marks
                int op1; // operator's integer value
                cout << endl << "1. Roll number \n2. Science marks \n3. English marks \n4. Maths marks \n5. Total Marks" ;
                cout << endl << "Choose your option: ";
                cin >> y;
                cout << endl << endl;
                switch(y)
                {
                /*
                for c:
                    1 = roll number
                    2 = science
                    3 = english
                    4 = maths
                    5 = total

                for op1:
                    ==, >, >=, <, <=, !=, &&, ||

                    ==      =1
                    >       =2
                    >=      =3
                    <       =4
                    <=      =5
                    !=      =6
                    invalid =9
                */

                // roll number
                case 1:
                    cout << "E.g.: > 10 \t{separated by a [space]} \nOperators you can input: {==, >, >=, <, <=, !=} " << endl;
                    cout << "\n\nInput your query for roll number : ";
                    cin.ignore(100, '\n');
                    cin >> op;
                    op1 = operation(op);
                    cin >> rno;
                    viewCase(op1, rno, m, 1);
                    break;

                // science marks
                case 2:
                    cout << "E.g.: > 10 \t{separated by a [space]} \nOperators you can input: {==, >, >=, <, <=, !=} " << endl;
                    cout << "\n\nInput your query for science marks : ";
                    cin.ignore(100, '\n');
                    cin >> op;
                    op1 = operation(op);
                    cin >> sm;
                    viewCase(op1, sm, m, 2);
                    break;

                // english marks
                case 3:
                    cout << "E.g.: > 10 \t{separated by a [space]} \nOperators you can input: {==, >, >=, <, <=, !=} " << endl;
                    cout << "\n\nInput your query for english marks : ";
                    cin.ignore(100, '\n');
                    cin >> op;
                    op1 = operation(op);
                    cin >> em;
                    viewCase(op1, em, m, 3);
                    break;

                // maths marks
                case 4:
                    cout << "E.g.: > 10 \t{separated by a [space]} \nOperators you can input: {==, >, >=, <, <=, !=} " << endl;
                    cout << "\n\nInput your query for maths marks : ";
                    cin.ignore(100, '\n');
                    cin >> op;
                    op1 = operation(op);
                    cin >> mm;
                    viewCase(op1, mm, m, 4);
                    break;

                // total marks
                case 5:
                    cout << "E.g.: > 10 \t{separated by a [space]} \nOperators you can input: {==, >, >=, <, <=, !=} " << endl;
                    cout << "\n\nInput your query for total marks : ";
                    cin.ignore(100, '\n');
                    cin >> op;
                    op1 = operation(op);
                    cin >> tm;
                    viewCase(op1, tm, m, 5);
                    break;

                default:
                    cout << "Invalid choice.";
                    break;
                }
                break;
                }

            default:
                cout << "Invalid choice.";
                break;
            }
            break;
            }


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

    cout << "Thank you for using the system!" << endl;
    getch();

    return 0;
}
