#include "project.hpp"
#include <iostream>

using namespace std;

int main() {

    // Array that stores all vocabulary words.
    VocabularyWord words[MAX_WORDS];

    // Load the vocabulary words from the data file.
    int count = loadVocabularyFromFile(
        "data/vocabulary.txt",
        words,
        MAX_WORDS
    );

    // Head pointer for the linked study list.
    StudyNode* studyHead = nullptr;

    int choice;

    // Keep showing the menu until the user chooses 0.
    do {
        printMenu();
        cin >> choice;

        // Make sure the menu choice is valid.
        if (!isValidMenuChoice(choice)) {
            cout << "Invalid menu choice." << endl;
            continue;
        }

        switch (choice) {

            // View all vocabulary words.
            case 1: {
                cout << endl;
                cout << "Vocabulary List" << endl;

                printVocabulary(words, count);

                break;
            }

            // Add a new vocabulary word.
            case 2: {
                if (count >= MAX_WORDS) {
                    cout << "Vocabulary list is full." << endl;
                    break;
                }

                VocabularyWord newWord;

                cout << "Japanese word: ";
                cin >> newWord.japanese;

                cout << "English meaning: ";
                cin >> newWord.english;

                cout << "Study level (1-5): ";
                cin >> newWord.studyLevel;

                // Study level must be between 1 and 5.
                if (!isValidStudyLevel(newWord.studyLevel)) {
                    cout << "Invalid study level." << endl;
                    break;
                }

                newWord.studied = false;

                // Add the new word to the array.
                words[count] = newWord;
                count++;

                cout << "Vocabulary word added." << endl;

                break;
            }

            // Search for a Japanese word.
            case 3: {
                string japanese;

                cout << "Enter Japanese word to search: ";
                cin >> japanese;

                int index = findWord(
                    words,
                    count,
                    japanese
                );

                if (index == -1) {
                    cout << "Word not found." << endl;
                } else {
                    printWord(words[index]);
                }

                break;
            }

            // Sort vocabulary from lowest to highest study level.
            case 4: {
                sortByStudyLevel(words, count);

                cout << "Vocabulary sorted by study level."
                     << endl;

                break;
            }

            // Search for a word and add it to the linked study list.
            case 5: {
                string japanese;

                cout << "Enter Japanese word to study: ";
                cin >> japanese;

                int index = findWord(
                    words,
                    count,
                    japanese
                );

                if (index == -1) {
                    cout << "Word not found." << endl;
                } else {
                    insertStudyWord(
                        studyHead,
                        words[index]
                    );

                    cout << "Word added to study list."
                         << endl;
                }

                break;
            }

            // Display all words currently in the study list.
            case 6: {
                cout << endl;
                cout << "Study List" << endl;

                if (studyHead == nullptr) {
                    cout << "Study list is empty." << endl;
                } else {
                    printStudyList(studyHead);
                }

                break;
            }

            // Show study statistics.
            case 7: {
                double average =
                    calculateAverageStudyLevel(
                        words,
                        count
                    );

                cout << "Average study level: "
                     << average
                     << endl;

                cout << "Words in study list: "
                     << countStudyWords(studyHead)
                     << endl;

                break;
            }

            // Exit the program.
            case 0: {
                cout << "Goodbye!" << endl;
                break;
            }
        }

    } while (choice != 0);

    // Delete the dynamically allocated study list nodes.
    clearStudyList(studyHead);

    return 0;
}