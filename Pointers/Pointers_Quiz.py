quiz = [
    {
        "question": "What is a pointer in C++?",
        "options": ["A variable that stores memory address", "A variable that stores value", "A function", "None of the above"],
        "answer": 0
    },
    {
        "question": "What is a dangling pointer?",
        "options": ["A pointer that points to an existing object", "A pointer that points to a non-existing object", "A pointer that points to null", "None of the above"],
        "answer": 1
    },
    {
        "question": "What does the 'new' keyword do in C++?",
        "options": ["Creates a new variable", "Allocates memory dynamically", "Creates a new function", "None of the above"],
        "answer": 1
    },
    {
        "question": "What does the 'delete' keyword do in C++?",
        "options": ["Removes a variable", "Deallocates memory", "Deletes a function", "None of the above"],
        "answer": 1
    },
    {
        "question": "What is the output of the following code?\nint x = 5;\nint* p = &x;\nstd::cout << *p;",
        "options": ["5", "The address of x", "The address of p", "None of the above"],
        "answer": 0
    },
    {
        "question": "What is the output of the following code?\nint x = 5;\nint* p = &x;\nstd::cout << p;",
        "options": ["5", "The address of x", "The address of p", "None of the above"],
        "answer": 1
    },
    {
        "question": "What is a reference in C++?",
        "options": ["A type of variable", "An alias for another variable", "A type of function", "None of the above"],
        "answer": 1
    },
    {
        "question": "What is the output of the following code?\nint y = 5;\nint &ref = y;\nref = 10;\nstd::cout << y;",
        "options": ["5", "10", "The address of y", "None of the above"],
        "answer": 1
    },
    {
        "question": "What is the output of the following code?\nint z = 5;\nint a = 10;\nint *ptr1 = &z;\nint* &ref1 = ptr1;\nref1 = &a;\nstd::cout << *ptr1;",
        "options": ["5", "10", "The address of z", "None of the above"],
        "answer": 1
    },
    {
        "question": "What is the output of the following code?\nint a = 5;\nint *p = &a;\n*p = 10;\nstd::cout << a;",
        "options": ["5", "10", "The address of a", "None of the above"],
        "answer": 1
    },
    {
        "question": "What is the output of the following code?\nint a = 5;\nint *p = nullptr;\np = &a;\nstd::cout << *p;",
        "options": ["5", "10", "The address of a", "None of the above"],
        "answer": 0
    },
    {
        "question": "What is the output of the following code?\nint a = 5;\nint *p = &a;\n*p = 10;\nstd::cout << *p;",
        "options": ["5", "10", "The address of a", "None of the above"],
        "answer": 1
    },
    {
        "question": "What is the output of the following code?\nint a = 5;\nint *p = &a;\nstd::cout << &p;",
        "options": ["5", "10", "The address of p", "None of the above"],
        "answer": 2
    },
    {
        "question": "What is the output of the following code?\nint a = 5;\nint *p = &a;\nstd::cout << *&a;",
        "options": ["5", "10", "The address of a", "None of the above"],
        "answer": 0
    },
    {
        'question': 'What does the & operator do in C++?',
        'options': ['Creates a new variable', 
                    'Returns the address of a variable', 
                    'Compares two variables', 
                    'None of the above'],
        'answer': 1
    },
    {
        'question': 'What happens when you try to access a deleted pointer in C++?',
        'options': ['The program crashes', 
                    'The program continues to run normally', 
                    'The pointer is automatically set to nullptr', 
                    'None of the above'],
        'answer': 0
    },
    {
        'question': 'Can a reference be re-assigned to a different variable after it is initialized in C++?',
        'options': ['Yes', 
                    'No'],
        'answer': 1
    },
    {
        'question': 'What is a heap overflow in C++?',
        'options': ['When a program writes more data into the allocated memory than it can hold', 
                    'When a program uses more memory than it needs', 
                    'When a program cannot access certain parts of memory', 
                    'None of the above'],
        'answer': 0
    },
    {
        'question': 'What is memory corruption in C++?',
        'options': ['When a program writes more data into the allocated memory than it can hold', 
                    'When a program overwrites the allocated memory', 
                    'When a program cannot access certain parts of memory', 
                    'None of the above'],
        'answer': 1
    }
]

def ask_question(question, options, answer):
    print(question)
    for i, option in enumerate(options):
        print(f"{i}. {option}")
    user_answer = int(input("Your answer: "))
    if user_answer == answer:
        print("Correct!\n")
        return 1
    else:
        print(f"Wrong! The correct answer is: {options[answer]}\n")
        return 0

def start_quiz(quiz):
    score = 0
    for q in quiz:
        score += ask_question(q["question"], q["options"], q["answer"])
        time.sleep(2)  # Wait for 2 seconds between questions for better readability
    print(f"Your score: {score}/{len(quiz)}")

# Start the quiz
start_quiz(quiz)