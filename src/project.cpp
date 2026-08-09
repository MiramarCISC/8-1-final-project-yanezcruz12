#include "project.hpp"
#include <fstream>
#include <iostream>

using namespace std;

// Checks if study level is between 1 and 5.
bool isValidStudyLevel(int studyLevel) {
    return studyLevel >= 1 && studyLevel <= 5;
}

// Calculates the average study level.
double calculateAverageStudyLevel(
    const VocabularyWord words[],
    int count
) {
    if (count <= 0) {
        return 0.0;
    }

    int total = 0;

    for (int i = 0; i < count; i++) {
        total += words[i].studyLevel;
    }

    return static_cast<double>(total) / count;
}

// Searches for a Japanese vocabulary word.
int findWord(
    const VocabularyWord words[],
    int count,
    string japanese
) {
    for (int i = 0; i < count; i++) {
        if (words[i].japanese == japanese) {
            return i;
        }
    }

    return -1;
}

// Sorts vocabulary by study level.
void sortByStudyLevel(
    VocabularyWord words[],
    int count
) {
    for (int start = 0; start < count - 1; start++) {
        int minIndex = start;

        for (int i = start + 1; i < count; i++) {
            if (words[i].studyLevel < words[minIndex].studyLevel) {
                minIndex = i;
            }
        }

        VocabularyWord temp = words[start];
        words[start] = words[minIndex];
        words[minIndex] = temp;
    }
}

// Prints one vocabulary word.
void printWord(const VocabularyWord& word) {
    cout << word.japanese
         << " - "
         << word.english
         << " | Study Level: "
         << word.studyLevel;

    if (word.studied) {
        cout << " | Studied";
    }

    cout << endl;
}

// Prints all vocabulary words.
void printVocabulary(
    const VocabularyWord words[],
    int count
) {
    for (int i = 0; i < count; i++) {
        printWord(words[i]);
    }
}

// Adds a vocabulary word to the study list.
void insertStudyWord(
    StudyNode*& head,
    VocabularyWord word
) {
    StudyNode* newNode = new StudyNode;

    newNode->data = word;
    newNode->next = head;

    head = newNode;
}

// Searches the study list.
StudyNode* findStudyWord(
    StudyNode* head,
    string japanese
) {
    StudyNode* current = head;

    while (current != nullptr) {
        if (current->data.japanese == japanese) {
            return current;
        }

        current = current->next;
    }

    return nullptr;
}

// Counts words in the study list.
int countStudyWords(const StudyNode* head) {
    int count = 0;

    const StudyNode* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

// Prints the study list.
void printStudyList(const StudyNode* head) {
    const StudyNode* current = head;

    while (current != nullptr) {
        printWord(current->data);
        current = current->next;
    }
}

// Deletes all nodes from the study list.
void clearStudyList(StudyNode*& head) {
    StudyNode* current = head;

    while (current != nullptr) {
        StudyNode* nextNode = current->next;

        delete current;

        current = nextNode;
    }

    head = nullptr;
}

// Loads vocabulary from a file.
int loadVocabularyFromFile(
    string filename,
    VocabularyWord words[],
    int maxWords
) {
    ifstream input(filename);

    if (!input.is_open()) {
        return 0;
    }

    int count = 0;

    while (
        count < maxWords &&
        input >> words[count].japanese
              >> words[count].english
              >> words[count].studyLevel
    ) {
        if (isValidStudyLevel(words[count].studyLevel)) {
            words[count].studied = false;
            count++;
        }
    }

    return count;
}

// Checks if the menu choice is valid.
bool isValidMenuChoice(int choice) {
    return choice >= 0 && choice <= 7;
}

// Prints the main menu.
void printMenu() {
    cout << endl;
    cout << "Japanese Vocabulary Study Manager" << endl;
    cout << "1. View vocabulary" << endl;
    cout << "2. Add vocabulary word" << endl;
    cout << "3. Search vocabulary" << endl;
    cout << "4. Sort by study level" << endl;
    cout << "5. Choose existing word to study" << endl;
    cout << "6. View study list" << endl;
    cout << "7. Show average study level" << endl;
    cout << "0. Exit" << endl;
    cout << "Choice: ";
}