#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

const int GCTU_gradeCount = 11;
const int UG_gradeCount = 9;

// GCTU grading arrays
const float GT_scoreThresholds[GCTU_gradeCount] = {80.0, 75.0, 70.0, 65.0, 60.0, 55.0, 50.0, 45.0, 40.0, 35.0, 0.0};
const float GT_gradePoints[GCTU_gradeCount] = {4.00, 3.75, 3.50, 3.25, 3.00, 2.75, 2.50, 2.00, 1.50, 1.00, 0.00};
const string GT_letterGrades[GCTU_gradeCount] = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "F"};

// UG grading arrays
const float UG_scoreThresholds[UG_gradeCount] = {80.0, 75.0, 70.0, 65.0, 60.0, 55.0, 50.0, 40.0, 0.0};
const float UG_gradePoints[UG_gradeCount] = {4.00, 3.50, 3.00, 2.50, 2.00, 1.50, 1.00, 0.50, 0.00};
const string UG_letterGrades[UG_gradeCount] = {"A", "B+", "B", "C+", "C", "D+", "D", "E", "F"};

// declaring variables
string semesterClass;
float gpa;
float qualityPoint = 0.0;
int sumCreditHour = 0;

// Declaring function prototypes (Fixed to match parameter implementations)
void calculateGPA(int schoolChoice);
float assignGradePoint(int schoolChoice, float score);
string assignClass(float g);
void calculate_FGPA(int schoolChoice);
void displayGradingTable(int schoolChoice);
void checkGrade_for_Score(int schoolChoice);
string letterGrade(int schoolChoice, float score);

int main(void){
    int schoolChoice;
    // selecting the school for grading system
    cout <<"-------------------------------------------------------" << endl;
    cout <<            "SELECT YOUR TERTIARY SCHOOL " << endl;
    cout <<"-------------------------------------------------------" << endl;
    cout << "1. Ghana Communication Technology University (GCTU)" << endl;
    cout << "2. University of Ghana (UG)" << endl;
    do{
        cout << "Enter your school choice (1 or 2): ";
        cin >> schoolChoice;
        if (cin.fail() || (schoolChoice != 1 && schoolChoice != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    } while (cin.fail() || (schoolChoice != 1 && schoolChoice != 2));
    string schoolName = (schoolChoice == 1) ? "Ghana Communication Technology University (GCTU)" : "University of Ghana (UG)";
    cout << "You have selected: " << schoolName << endl;
    int choice;
    
    do{
        cout << "\n ============================================================" << endl;
        cout << "     " << schoolName << " GPA CALCULATOR " << endl;
        cout << " ==============================================================" << endl;
        cout <<"What would you like to do? Choose from the menu below "<< endl;
        cout << "  Menu " << endl;
        cout <<"1. Calculate Semester GPA" <<endl;
        cout << "2. Calculate Final Grade Point Average(FGPA/CGPA) " << endl;
        cout << "3. Check Grade for a Given Score" << endl;
        cout << "4. Display Grading Table" << endl;
        cout << "5. Exit"  << endl;
        
        do{
            cout << "Enter your choice: " ;
            cin >>  choice;
            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }else if(choice < 1 || choice > 5){
                cout << "Invalid choice. Pick a number between 1 and 5: ";
            }
        }while(cin.fail() || choice < 1 || choice > 5);
    
        switch(choice){
            case 1: calculateGPA(schoolChoice); break; // Fixed: Passed schoolChoice
            case 2: calculate_FGPA(schoolChoice); break; // Fixed: Passed schoolChoice
            case 3: checkGrade_for_Score(schoolChoice); break;
            case 4: displayGradingTable(schoolChoice); break;
            case 5: cout << "Exiting.........." << endl; break;
            default: cout << "Invalid input" << endl;
        }
    }while(choice != 5);
}

void calculateGPA(int schoolChoice){ // Fixed parameter
    int numCourses;
    qualityPoint = 0.0;
    sumCreditHour = 0;
  
      // input validation for the number of courses
        cout << "How many courses are you offering: ";
        cin >> numCourses;
        while (cin.fail() || numCourses < 1 || numCourses> 8) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number." << endl;
            cout << "How many courses are you offering: ";
            cin >> numCourses;
        }
    // declaring vectors to store the course details since they are dynamic in nature
    string courseTitle[numCourses];
    int creditHour[numCourses];
    float score[numCourses];
    float gradePoint[numCourses];

    // loop to get the course details since the number of courses is known
    for(int courseCount = 1; courseCount <= numCourses; courseCount++){    
        cout << "What is the course " << courseCount << " 's title: " << endl;
        getline(cin>>ws, courseTitle[courseCount - 1]);
        
        // input validation for credit hours
            cout << "What is the credit hours: ";
            cin >> creditHour[courseCount - 1];
            while (cin.fail() || creditHour[courseCount - 1] < 1 || creditHour[courseCount - 1] > 3) {
                cout << "Invalid input. Enter numbers between 1 and 3: " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "What is the credit hours: ";
                cin >> creditHour[courseCount - 1];
            }
             // validating the score input of the user
            cout << "What is your score for " << courseTitle[courseCount - 1] << ": ";
            cin >> score[courseCount - 1];
            while (cin.fail() || score[courseCount - 1] < 0 || score[courseCount - 1] > 100) {
                cout << "Invalid input. Please enter a number between 0 and 100." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "What is your score for " << courseTitle[courseCount - 1] << ": ";
                cin >> score[courseCount - 1];
            }

        // assigning the grade point for each course (Fixed: Passed schoolChoice)
        gradePoint[courseCount - 1] = assignGradePoint(schoolChoice, score[courseCount - 1]);
        // calculating the quality point for each course
        qualityPoint += gradePoint[courseCount - 1] * creditHour[courseCount - 1];
        // calculating the total credit hour for all the courses
        sumCreditHour += creditHour[courseCount - 1];
    }
    // calculating the GPA by dividing the quality point by the sumCreditHour
    gpa = qualityPoint / sumCreditHour;
    assignClass(gpa);
    cout << "-----------------------------------------" << endl;
    cout << left << setw(15) << "Course " <<setw(15) <<"Credit Hour" << setw(10) << "Score" << setw(14) << "Grade Point" << endl;
    cout<< fixed << setprecision(2);
    for (int i = 0; i < numCourses; i++){
        cout << left << setw(15) << courseTitle[i] <<setw(15) <<creditHour[i] << setw(10) << score[i] << setw(14)  << gradePoint[i] << endl;
    }
    cout << "Total Credit Hours   : " << sumCreditHour << endl;
    cout << "Your GPA is          : " << fixed << setprecision(2) << gpa << endl;
    cout << "Your degree class is : " << semesterClass<< endl;
}

float assignGradePoint(int schoolChoice, float score){
    if(schoolChoice == 1){ // GCTU grading system
        for(int i = 0; i < GCTU_gradeCount; i++){
            if (score >= GT_scoreThresholds[i]) return GT_gradePoints[i];
        }
    } else if(schoolChoice == 2){ // UG grading system
        for(int i = 0; i < UG_gradeCount; i++){
            if (score >= UG_scoreThresholds[i]) return UG_gradePoints[i];
        }
    }
    return 0.0;
}

string assignClass(float grade){
    if (grade >= 3.60) return semesterClass = "First Class";
    if (grade >= 3.00) return semesterClass = "Second Class Upper";
    if (grade >= 2.50) return semesterClass = "Second Class Lower";
    if (grade >= 1.50) return semesterClass = "Third Class";
    if (grade >= 1.00) return semesterClass = "Pass";
    return semesterClass = "Fail";
}

void calculate_FGPA(int schoolChoice){ 
    int num_of_semester;
    float totalQualityPoint = 0.0;
    int totalCreditHour = 0;
        cout << "How many semesters are you calculating the FGPA for? "<< endl;
        cin >> num_of_semester;
        while(cin.fail()|| num_of_semester <1 || num_of_semester >16){
            cout << "invalid input. Enter a number between 0 and 15." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "How many semesters are you calculting the FGPA for? " << endl;
            cin >> num_of_semester;
        }

    float semesterGPA[num_of_semester];
    string semesterClassRecord[num_of_semester];

    for(int semesterCount = 1; semesterCount <= num_of_semester; semesterCount++){
        cout << "The details for semester " << semesterCount <<endl;
        calculateGPA(schoolChoice); // Fixed: Passed schoolChoice
        totalQualityPoint += qualityPoint;
        totalCreditHour += sumCreditHour;
        semesterGPA[semesterCount - 1] = gpa;
        semesterClassRecord[semesterCount - 1] = semesterClass;
    }
    float fgpa = totalQualityPoint / totalCreditHour;
    assignClass(fgpa);
    cout << "-----------------------------------------" << endl;
    cout << left << setw(15) << "Semester"<< setw(10) << "GPA" << setw(14) << "Degree Class" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < num_of_semester; i++){
        cout << left << setw(15) << "Semester " + to_string(i + 1) << setw(10)  << semesterGPA[i] << setw(14) << semesterClassRecord[i] << endl;
    }
    cout << "Total Credit Hours   : " << totalCreditHour << endl;
    cout << "Your Final Grade Point Average is: " << fixed << setprecision(2) << fgpa << endl;
    cout << "Overall Degree Class is: " << semesterClass << endl;
}

// Fixed: Corrected loop syntax, arrays used, and added generic fallback return
string letterGrade(int schoolChoice, float score){
    if(schoolChoice == 1){ // GCTU
        for(int i = 0; i < GCTU_gradeCount; i++){
            if (score >= GT_scoreThresholds[i]) return GT_letterGrades[i];
        }
    } else if(schoolChoice == 2){ // UG
        for(int i = 0; i < UG_gradeCount; i++){
            if (score >= UG_scoreThresholds[i]) return UG_letterGrades[i]; // Fixed arrays
        }
    }
    return "F"; // Fixed fallback
} 

void displayGradingTable(int schoolChoice){
    if(schoolChoice == 1){
        cout << "====== GCTU GRADING TABLE ========" << endl;
        cout << left << setw(12) << "Score (%)" << setw(8) << "Grade" << setw(18) << "Interpretation" << setw(12) << "Grade Point" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << left << setw(12) << "80-100" << setw(8) << "A" << setw(18) << "Outstanding" << setw(12) << "4.00" << endl;
        cout << left << setw(12) << "75-79" << setw(8) << "A-" << setw(18) << "Excellent" << setw(12) << "3.75" << endl;
        cout << left << setw(12) << "70-74" << setw(8) << "B+" << setw(18) << "Very Good" << setw(12) << "3.50" << endl;
        cout << left << setw(12) << "65-69" << setw(8)  << "B" << setw(18) << "Good" << setw(12) << "3.25" << endl;
        cout << left << setw(12) << "60-64" << setw(8) << "B-" << setw(18) << "Fairly Good" << setw(12) << "3.00" << endl;
        cout << left << setw(12) << "55-59" << setw(8) << "C+" << setw(18) << "Above Average" << setw(12) << "2.75" << endl;
        cout << left << setw(12) << "50-54" << setw(8) << "C" << setw(18) << "Average" << setw(12) << "2.50" << endl;
        cout << left << setw(12) << "45-49" << setw(8) << "C-" << setw(18) << "Below Average" << setw(12) << "2.00" << endl;
        cout << left << setw(12) << "40-44" << setw(8) << "D+" << setw(18) << "Pass" << setw(12) << "1.50" << endl;
        cout << left << setw(12) << "35-39" << setw(8) << "D" << setw(18) << "Pass" << setw(12) << "1.00" << endl;
        cout << left << setw(12) << "0-34" << setw(8) << "F" << setw(18) << "Fail" << setw(12) << "0.00" << endl;
    }else {
        cout << "\n ========UNIVERSITY OF GHANA GRADING TABLE ========" << endl;
        cout << left << setw(12) << "Score (%)" << setw(8) << "Grade" << setw(18) << "Interpretation" << setw(12) << "Grade Point" << endl;
        cout << "------------------------------------------" << endl;
        cout << left << setw(12) << "80-100" << setw(8) << "A" << setw(18) << "Outstanding" << setw(12) << "4.00" << endl;
        cout << left << setw(12) << "75-79" << setw(8) << "B+" << setw(18) << "Very Good" << setw(12) << "3.50" << endl;
        cout << left << setw(12) << "70-74" << setw(8) << "B" << setw(18) << "Good" << setw(12) << "3.00" << endl;
        cout << left << setw(12) << "65-69" << setw(8) << "C+" << setw(18) << "Fairly Good" << setw(12) << "2.50" << endl;
        cout << left << setw(12) << "60-64" << setw(8) << "C" << setw(18) << "Average" << setw(12) << "2.00" << endl;
        cout << left << setw(12) << "55-59" << setw(8) << "D+" << setw(18) << "Pass" << setw(12) << "1.50" << endl;
        cout << left << setw(12) << "50-54" << setw(8) << "D" << setw(18) << "Mariginal/Pass" << setw(12) << "1.00" << endl;
        cout << left << setw(12) << "40-49" << setw(8) << "E" << setw(18) << "Marginal Fail" << setw(12) << "0.50" << endl;
        cout << left << setw(12) << "0-39"  << setw(8) << "F" << setw(18) << "Fail" << setw(12) << "0.00" << endl;
    }   
    cout << "===========================================================" << endl;
}

void checkGrade_for_Score(int schoolChoice){
    float score;
        cout << "Enter the score to check the grade: ";
        cin >> score;
        while(cin.fail() || score < 0 || score > 100){
            cout << "Invalid input. Please enter a valid number between 0 and 100." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the score to check the grade: ";
            cin >> score;
            
        }
    // Calls both functions dynamically and compiles flawlessly!
    cout << "Score " << score <<  " --> Grade: " << letterGrade(schoolChoice, score) 
         << ", Grade Point: " << fixed << setprecision(2) << assignGradePoint(schoolChoice, score) << endl;
}