#  GPA Calculator — C++

A console-based **GPA and FGPA Calculator** written in C++. This project allows students to calculate their semester GPA, calculate their Final Grade Point Average (FGPA/CGPA), check the grade and grade point associated with a score, and view the grading system for their selected university.

The calculator currently supports grading systems for:

* **Ghana Communication Technology University (GCTU)**
* **University of Ghana (UG)**

---

##  Features

### 1. Semester GPA Calculator

Calculate your GPA for a semester by entering:

* Number of courses
* Course title
* Credit hours
* Score for each course

The program calculates the grade point for each course and uses the credit hours to determine the weighted GPA.

The formula used is:

```text
GPA = Total Quality Points / Total Credit Hours
```

Where:

```text
Quality Point = Grade Point × Credit Hour
```

The program also displays:

* Course title
* Credit hours
* Score
* Grade point
* Total credit hours
* Semester GPA
* Degree classification

---

### 2. FGPA/CGPA Calculator

The program can calculate your overall **Final Grade Point Average (FGPA)** across multiple semesters.

For each semester, you enter the course information, and the program calculates the semester GPA and quality points.

The overall FGPA is calculated using:

```text
FGPA = Total Quality Points / Total Credit Hours
```

This approach ensures that semesters are weighted according to their total credit hours rather than simply averaging semester GPAs.

---

### 3. Grade Checker

Enter a score between **0 and 100** to determine:

* Letter grade
* Grade point

For example:

```text
Score 75 → Grade: A-, Grade Point: 3.75
```

The result depends on the university grading system selected.

---

### 4. Grading Table

The application can display the complete grading table for the selected university.

This includes:

* Score range
* Letter grade
* Interpretation
* Grade point

---

### 5. Input Validation

The program includes input validation to prevent invalid entries.

Examples include:

* Invalid university selection
* Invalid menu choices
* Invalid number of courses
* Invalid credit hours
* Scores outside the range of 0–100
* Invalid numeric input

The program uses C++ input stream functions such as:

```cpp
cin.fail()
cin.clear()
cin.ignore()
```

to handle invalid input.

---

## Supported Grading Systems

### Ghana Communication Technology University (GCTU)

| Score  | Grade | Grade Point | Interpretation |
| ------ | ----- | ----------: | -------------- |
| 80–100 | A     |        4.00 | Outstanding    |
| 75–79  | A-    |        3.75 | Excellent      |
| 70–74  | B+    |        3.50 | Very Good      |
| 65–69  | B     |        3.25 | Good           |
| 60–64  | B-    |        3.00 | Fairly Good    |
| 55–59  | C+    |        2.75 | Above Average  |
| 50–54  | C     |        2.50 | Average        |
| 45–49  | C-    |        2.00 | Below Average  |
| 40–44  | D+    |        1.50 | Pass           |
| 35–39  | D     |        1.00 | Pass           |
| 0–34   | F     |        0.00 | Fail           |

---

### University of Ghana (UG)

| Score  | Grade | Grade Point | Interpretation |
| ------ | ----- | ----------: | -------------- |
| 80–100 | A     |        4.00 | Outstanding    |
| 75–79  | B+    |        3.50 | Very Good      |
| 70–74  | B     |        3.00 | Good           |
| 65–69  | C+    |        2.50 | Fairly Good    |
| 60–64  | C     |        2.00 | Average        |
| 55–59  | D+    |        1.50 | Pass           |
| 50–54  | D     |        1.00 | Marginal/Pass  |
| 40–49  | E     |        0.50 | Marginal Fail  |
| 0–39   | F     |        0.00 | Fail           |

> **Note:** The grading scales in this project are based on the grading values currently implemented in the source code. Students should verify their institution's current official grading regulations before using the calculator for academic decisions.

---

## 🎯 Degree Classification

The program classifies the GPA/FGPA using the following scale:

|         GPA | Degree Classification |
| ----------: | --------------------- |
| 3.60 – 4.00 | First Class           |
| 3.00 – 3.59 | Second Class Upper    |
| 2.50 – 2.99 | Second Class Lower    |
| 1.50 – 2.49 | Third Class           |
| 1.00 – 1.49 | Pass                  |
|  Below 1.00 | Fail                  |

---

##  Technologies Used

* **C++**
* Standard C++ Library
* `iostream`
* `string`
* `iomanip`
* `limits`

The project is completely console-based and does not require an external database or third-party library.

---

##  Project Structure

```text
GPA-Calculator/
│
├── gpa_calculator.cpp
└── README.md
```

---

##  How It Works

When the program starts, the user selects their university:

```text
SELECT YOUR TERTIARY SCHOOL

1. Ghana Communication Technology University (GCTU)
2. University of Ghana (UG)
```

After selecting a university, the main menu is displayed:

```text
1. Calculate Semester GPA
2. Calculate Final Grade Point Average (FGPA/CGPA)
3. Check Grade for a Given Score
4. Display Grading Table
5. Exit
```

The selected university determines which grading scale is used throughout the calculation.

---

## 🧮 GPA Calculation Example

Suppose a student takes three courses:

| Course      | Credit Hours | Score | Grade Point |
| ----------- | -----------: | ----: | ----------: |
| Mathematics |            3 |    80 |        4.00 |
| Programming |            3 |    75 |        3.75 |
| English     |            2 |    65 |        3.25 |

The quality points would be:

```text
Mathematics:
4.00 × 3 = 12.00

Programming:
3.75 × 3 = 11.25

English:
3.25 × 2 = 6.50
```

Total Quality Points:

```text
12.00 + 11.25 + 6.50 = 29.75
```

Total Credit Hours:

```text
3 + 3 + 2 = 8
```

Therefore:

```text
GPA = 29.75 / 8
    = 3.72
```

The resulting classification would be:

```text
First Class
```

according to the classification implemented in this project.

---

## 🚀 Getting Started

### Prerequisites

You need a C++ compiler installed on your computer.

Examples include:

* GCC / MinGW
* MSYS2 MinGW
* Clang
* Visual Studio

You can check whether GCC is installed by running:

```bash
g++ --version
```

---

##  Compilation

Clone the repository:

```bash
git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY.git
```

Navigate into the project directory:

```bash
cd YOUR-REPOSITORY
```

Compile the program:

```bash
g++ gpa_calculator.cpp -o gpa_calculator
```

---

##  Running the Program

### Windows

```bash
gpa_calculator.exe
```

### Linux/macOS

```bash
./gpa_calculator
```

---

##  Usage

### Step 1 — Select University

Choose either:

```text
1. GCTU
2. UG
```

### Step 2 — Select an Operation

Choose from:

```text
1. Calculate Semester GPA
2. Calculate FGPA/CGPA
3. Check Grade
4. Display Grading Table
5. Exit
```

### Step 3 — Enter Course Information

For GPA calculations, provide:

```text
Course title
Credit hours
Score
```

The program processes the information and displays the calculated result.

---

##  Input Limits

The current implementation uses the following limits:

| Input               | Allowed Range |
| ------------------- | ------------- |
| Number of courses   | 1–8           |
| Credit hours        | 1–3           |
| Score               | 0–100         |
| Number of semesters | 1–16          |
| Menu choice         | 1–5           |
| University choice   | 1–2           |

---

## 🧠 Concepts Demonstrated

This project was built to practice several important C++ programming concepts, including:

### Functions

The program is divided into multiple functions, including:

```cpp
calculateGPA()
calculate_FGPA()
assignGradePoint()
assignClass()
letterGrade()
checkGrade_for_Score()
displayGradingTable()
```

This makes the program easier to organize and maintain.

### Arrays

Arrays are used to store:

* Grade thresholds
* Grade points
* Letter grades
* Course information
* Semester information

### Conditional Statements

The project uses:

```cpp
if
else if
else
switch
```

to make decisions throughout the program.

### Loops

The project uses:

```cpp
for
while
do...while
```

for repeated operations and input validation.

### Input Validation

Invalid user input is handled using:

```cpp
cin.fail()
cin.clear()
cin.ignore()
```

### Formatting

The `<iomanip>` library is used to format output:

```cpp
setw()
setprecision()
fixed
```

---

##  Future Improvements

The current version is a console-based implementation. Possible improvements include:

* [ ] Add support for more universities
* [ ] Allow users to save GPA calculations
* [ ] Add a graphical user interface
* [ ] Store student records
* [ ] Export results to PDF
* [ ] Add course grade letters to the GPA result table
* [ ] Add semester-by-semester academic history
* [ ] Add a GPA target calculator
* [ ] Add a "What GPA do I need?" calculator
* [ ] Add support for different credit-hour systems
* [ ] Improve the user interface
* [ ] Replace variable-length arrays with `std::vector`
* [ ] Separate grading data from application logic
* [ ] Add automated tests
* [ ] Add support for persistent student profiles

---

##  Current Limitations

This version has some limitations that are worth knowing:

1. **Console only**
   The program currently runs through the command line and does not have a graphical interface.

2. **No data persistence**
   Course and semester information is not saved after the program closes.

3. **Limited university support**
   Only GCTU and UG grading systems are implemented.

4. **Course limit**
   The semester GPA calculator currently accepts between 1 and 8 courses.

5. **Credit-hour limit**
   Each course is currently restricted to 1–3 credit hours.

6. **Grading information is hard-coded**
   University grading scales are stored directly in the C++ source code.

---

##  Contributing

Contributions are welcome.

If you would like to improve the project:

1. Fork the repository.
2. Create a new branch.

```bash
git checkout -b feature/new-feature
```

3. Make your changes.
4. Commit your changes.

```bash
git add .
git commit -m "Add new feature"
```

5. Push the branch.

```bash
git push origin feature/new-feature
```

6. Open a Pull Request.

---

##  Reporting Issues

If you find a bug or have an idea for improving the calculator, feel free to open an issue.

When reporting a bug, include:

* What you were trying to do
* The input you entered
* What you expected to happen
* What actually happened
* Any error message displayed

---

##  License

This project is currently available for educational and personal use.

If you intend to publish the project publicly, consider adding an explicit open-source license such as the MIT License.

---

##  Author

**Bismark Eli Kudjo**

Computer Science Student | Aspiring Software Engineer

This project was created as part of my journey to strengthen my C++ programming, problem-solving, and software development skills.

---

##  Acknowledgement

This project was developed as a practical C++ programming project to apply concepts such as:

* Functions
* Arrays
* Loops
* Conditional statements
* Input validation
* Mathematical calculations
* Modular programming

---

##  Project Status

**Current Status:**  Functional

The current version supports:

* ✅ GCTU grading system
* ✅ UG grading system
* ✅ Semester GPA calculation
* ✅ FGPA/CGPA calculation
* ✅ Grade checking
* ✅ Grading table display
* ✅ Degree classification
* ✅ Input validation

More features and improvements can be added as the project develops.

---

### Made with C++ 
