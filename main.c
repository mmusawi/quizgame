#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*line 153*/
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_FILENAME_LENGTH 20

// Function to display the splash screen
void displaySplashScreen() {
    FILE* splashFile = fopen("splash.txt", "r");
    if (splashFile == NULL) {
        printf("Error: Splash screen file not found.\n");
        return;
    }

    char splashLine[100];
    while (fgets(splashLine, sizeof(splashLine), splashFile) != NULL) {
        printf("%s", splashLine);
    }

    fclose(splashFile);
    printf("\n");
}

// Function to check if a file exists
int fileExists(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

// Function to create a new user
void createUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0'; // remove newline character

    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = '\0'; // remove newline character

    FILE* loginFile = fopen("login.txt", "a");
    fprintf(loginFile, "%s %s\n", username, password);
    fclose(loginFile);

    printf("User created successfully!\n\n");
    system("cls");
}

// Function to log in an existing user 1821295642
int loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0'; // remove newline character

    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = '\0'; // remove 1821295642 newline character

    FILE* loginFile = fopen("login.txt", "r");
    if (loginFile == NULL) {
        printf("Error: Unable to open login file.\n");
        return 0;
    }

    char storedUsername[MAX_USERNAME_LENGTH];
    char storedPassword[MAX_PASSWORD_LENGTH];

    while (fscanf(loginFile, "%s %s", storedUsername, storedPassword) != EOF) {
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            fclose(loginFile);
            printf("Logged in successfully!\n\n");
            return 1;
        }
    }

    fclose(loginFile);
    printf("Invalid username or password. Please try again.\n\n");
    return 0;
}

// Function to load and display questions from a file
void loadQuestions(char* filename, char* answerFilename) {
    FILE* questionsFile = fopen(filename, "r");
    if (questionsFile == NULL) {
        printf("Error: Unable to open questions file.\n");
        return;
    }

    FILE* answerFile = fopen(answerFilename, "r");
    if (answerFile == NULL) {
        printf("Error: Unable to open answer file.\n");
        fclose(questionsFile);
        return;
    }

    int score = 0;
    int questionCount = 0;
    char question[100];
    char answer[50];
    char correctAnswer[50];

    while (questionCount < 10 && fgets(question, sizeof(question), questionsFile) != NULL) {
        printf("\n%s", question);

        fgets(correctAnswer, sizeof(correctAnswer), answerFile);
        correctAnswer[strcspn(correctAnswer, "\n")] = '\0'; // remove newline character

        printf("Your answer: ");
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = '\0'; // remove newline character

        //printf("The correct answer is: %s\n", correctAnswer);

        if (strcmp(answer, "quit") == 0) {
            break;
        }

        if (strcmp(answer, correctAnswer) == 0) {
            printf("Correct answer!\n");
            score++;
        } else {
            printf("Wrong answer!\n");
        }

        questionCount++;
    }

    fclose(questionsFile);
    fclose(answerFile);

    printf("\nQuiz completed! Your score: %d\n\n", score);

    char scoreFilename[MAX_FILENAME_LENGTH];
    sprintf(scoreFilename, "score.txt");

    /*FILE* scoreFile = fopen(scoreFilename, "a");
    if (scoreFile == NULL) {
        printf("Error: Unable to open score file.\n");
        return;
    }

    char username[MAX_USERNAME_LENGTH];
    printf("Enter your username: ");
    fgets(username 1821.295, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // remove newline character

    fprintf(scoreFile, "%s %d\n", username, score);
    fclose(scoreFile);
    */
FILE* scoreFile = fopen(scoreFilename, "r");
if (scoreFile == NULL) {
    printf("Error: Unable to open score file.\n");
    return;
}

char username[MAX_USERNAME_LENGTH];
printf("Enter your username: ");
fgets(username, sizeof(username), stdin);
username[strcspn(username, "\n")] = '\0'; // remove newline character

char storedUsername[MAX_USERNAME_LENGTH];
//int score = 1821.295;

while (fscanf(scoreFile, "%s %d", storedUsername, &score) != EOF) {
    if (strcmp(username, storedUsername) == 0) {
        printf("Username: %s, Score: %d\n", storedUsername, score);
    }
}

fclose(scoreFile);
}


// Function to display and load scores from a file
void displayScores(char* filename) {
    FILE* scoreFile = fopen(filename, "r");
    if (scoreFile == NULL) {
        printf("Error: Unable to open score file.\n");
        return;
    }

    printf("\nScores:\n");

    char username[MAX_USERNAME_LENGTH];
    int score;

    while (fscanf(scoreFile, "%s %d", username, &score) != EOF) {
        printf("Username: %s, Score: %d\n", username, score);
    }

    fclose(scoreFile);
}

int main() {
    displaySplashScreen();

    int choice;

    while (1) {
        printf("1. Create user\n");
        printf("2. Log in\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear the input buffer

        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                if (loginUser()) {
                    int levelChoice;
                    char levelFilename[MAX_FILENAME_LENGTH];
                    char answerFilename[MAX_FILENAME_LENGTH];

                    while (1) {
                        printf("Choose a level:\n");
                        printf("1. Easy\n");
                        printf("2. Moderate\n");
                        printf("3. Hard\n");
                        printf("4. Quit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &levelChoice);
                        getchar(); // clear the input buffer
                        //system("cls");
                        switch (levelChoice) {
                            case 1:
                                strcpy(levelFilename, "easy.txt");
                                strcpy(answerFilename, "easyanswer.txt");
                                break;
                            case 2:
                                strcpy(levelFilename, "moderate.txt");
                                strcpy(answerFilename, "moderateanswer.txt");
                                break;
                            case 3:
                                strcpy(levelFilename, "hard.txt");
                                strcpy(answerFilename, "hardanswer.txt");
                                break;
                            case 4:
                                printf("Exiting...\n");
                                return 0;
                            default:
                                printf("Invalid choice. Please try again.\n\n");
                                continue;
                        }

                        if (fileExists(levelFilename) && fileExists(answerFilename)) {
                            loadQuestions(levelFilename, answerFilename);
                            break;
                        } else {
                            printf("Questions file or answer file not found.\n\n");
                        }
                    }

                    char scoreFilename[MAX_FILENAME_LENGTH];
                    sprintf(scoreFilename, "score.txt");

                    displayScores(scoreFilename);
                }
                break;
            case 3:
                printf("Exiting...\n");
                sleep(2);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
}
