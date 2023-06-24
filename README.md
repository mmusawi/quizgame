# quizgame
Create text files named "splash.txt", "login.txt", "easy.txt", "moderate.txt", "hard.txt", "easyanswer.txt", "moderateanswer.txt" and "hardanswer.txt" in the same directory as the program. Additionally, ensure that an ASCII art image stored in the "splash.txt" file for the splash screen.
This program provides options to create a user, log in with existing credentials, select a difficulty level (easy, moderate, or hard), answer 10 math questions, and display and save scores based on the chosen difficulty level.

it is just some simple files to read/write questions and answers.
In this code, the loadQuestions function has been created to accept two parameters: the filename of the questions file and the answerFilename of the corresponding answers file. The questions and answers are read from their respective files, and the user's input is compared to the correct answer. The score is updated accordingly.
you can use any cipher to make it nicer.

Before the start of the while loop in main, the answerFilename variable has been added to store the filename of the answer file corresponding to the selected level. Inside the switch statement, the appropriate answer filename is assigned based on the level choice.

The loadQuestions function is then called with the levelFilename and answerFilename to load and display the questions, compare the user's answers, and update the score. Finally, the displayScores function is called to show the username and score.


main():
in the main() fuction if the use selectes the easy/hard/moderate level then the the program will print the questions from the scelected level at easy.txt/hard.txt/moderate.txt starting from 0. then it will prompt the user to get the answer. 
Then if the qustions are from easy level then it will check whether the question number from easy.txt matches the answer number from easyanswer.txt. 
If those are equal then it compares the user given answer with the answers given in the easyanswer.txt. if those are equal then it updates the score by 1. 
Then it keeps repeating the same procedure for the rest 9 questions. 
After it prints the user name and score. 
Then it quits.
