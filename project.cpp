#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Examination
{
    string questions[10];
    string options[10][4];
    char correctAnswers[10];
    char studentAnswers[10];

    int totalQuestions;
    int marks;

public:

    Examination()
    {
        totalQuestions = 0;
        marks = 0;
    }

    // MODULE 1: Add and Manage Questions

    void addQuestions()
    {
        cout << "\n--- MODULE 1: ADD AND MANAGE QUESTIONS ---\n";

        cout << "Enter number of questions: ";
        cin >> totalQuestions;

        if (totalQuestions < 1 || totalQuestions > 10)
        {
            cout << "Please enter questions between 1 and 10.\n";
            totalQuestions = 0;
            return;
        }

        for (int i = 0; i < totalQuestions; i++)
        {
            cout << "\nEnter Question " << i + 1 << ": ";
            cin.ignore();
            getline(cin, questions[i]);

            cout << "Enter Option A: ";
            getline(cin, options[i][0]);

            cout << "Enter Option B: ";
            getline(cin, options[i][1]);

            cout << "Enter Option C: ";
            getline(cin, options[i][2]);

            cout << "Enter Option D: ";
            getline(cin, options[i][3]);

            cout << "Enter Correct Answer (A/B/C/D): ";
            cin >> correctAnswers[i];
        }

        cout << "\nQuestions Added Successfully!\n";
    }


    // MODULE 2: Conduct Exam and Record Answers

    void conductExam()
    {
        cout << "\n--- MODULE 2: CONDUCT EXAM ---\n";

        if (totalQuestions == 0)
        {
            cout << "Please add questions first!\n";
            return;
        }

        for (int i = 0; i < totalQuestions; i++)
        {
            cout << "\nQ" << i + 1 << ". " << questions[i] << endl;

            cout << "A. " << options[i][0] << endl;
            cout << "B. " << options[i][1] << endl;
            cout << "C. " << options[i][2] << endl;
            cout << "D. " << options[i][3] << endl;

            cout << "Enter Your Answer: ";
            cin >> studentAnswers[i];
        }

        cout << "\nExam Completed Successfully!\n";
    }


    // MODULE 3: Evaluate Answers and Calculate Marks

    void evaluateAnswers()
    {
        cout << "\n--- MODULE 3: EVALUATE ANSWERS ---\n";

        if (totalQuestions == 0)
        {
            cout << "Please add questions first!\n";
            return;
        }

        marks = 0;

        for (int i = 0; i < totalQuestions; i++)
        {
            if (toupper(studentAnswers[i]) == toupper(correctAnswers[i]))
            {
                marks++;
            }
        }

        cout << "\nEvaluation Completed!\n";
        cout << "Total Questions: " << totalQuestions << endl;
        cout << "Correct Answers: " << marks << endl;
        cout << "Wrong Answers: " << totalQuestions - marks << endl;
    }


    // MODULE 4: Display Results and Generate Scorecard

    void displayResult()
    {
        cout << "\n--- MODULE 4: DISPLAY RESULT AND SCORECARD ---\n";

        if (totalQuestions == 0)
        {
            cout << "Please add questions first!\n";
            return;
        }

        cout << "\n========== SCORECARD ==========\n";

        cout << "Total Questions : " << totalQuestions << endl;
        cout << "Correct Answers : " << marks << endl;
        cout << "Wrong Answers   : " << totalQuestions - marks << endl;
        cout << "Total Marks     : " << totalQuestions << endl;
        cout << "Obtained Marks  : " << marks << endl;

        float percentage = (marks * 100.0) / totalQuestions;

        cout << "Percentage      : " << percentage << "%" << endl;

        if (percentage >= 40)
        {
            cout << "Result          : PASS" << endl;
        }
        else
        {
            cout << "Result          : FAIL" << endl;
        }

        cout << "================================\n";
    }

};


int main()
{
    Examination exam;
    int choice;

    do
    {
        cout << "\n===== ONLINE EXAMINATION SYSTEM =====\n";

        cout << "1. Add Questions\n";
        cout << "2. Conduct Exam\n";
        cout << "3. Evaluate Answers\n";
        cout << "4. Display Result\n";
        cout << "5. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                exam.addQuestions();
                break;

            case 2:
                exam.conductExam();
                break;

            case 3:
                exam.evaluateAnswers();
                break;

            case 4:
                exam.displayResult();
                break;

            case 5:
                cout << "\nThank You for Using Online Examination System!";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 5);

    return 0;
}
