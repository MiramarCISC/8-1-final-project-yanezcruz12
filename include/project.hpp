#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <string>

const int MAX_WORDS = 100;

// Stores information for one vocabulary word.
struct VocabularyWord {
    std::string japanese;
    std::string english;
    int studyLevel;
    bool studied;
};

// Node used for the study list.
struct StudyNode {
    VocabularyWord data;
    StudyNode* next;
};

// Vocabulary functions.
bool isValidStudyLevel(int studyLevel);

double calculateAverageStudyLevel(
    const VocabularyWord words[],
    int count
);

int findWord(
    const VocabularyWord words[],
    int count,
    std::string japanese
);

void sortByStudyLevel(
    VocabularyWord words[],
    int count
);

void printWord(const VocabularyWord& word);

void printVocabulary(
    const VocabularyWord words[],
    int count
);

// Study list functions.
void insertStudyWord(
    StudyNode*& head,
    VocabularyWord word
);

StudyNode* findStudyWord(
    StudyNode* head,
    std::string japanese
);

int countStudyWords(const StudyNode* head);

void printStudyList(const StudyNode* head);

void clearStudyList(StudyNode*& head);

// Loads vocabulary from a file.
int loadVocabularyFromFile(
    std::string filename,
    VocabularyWord words[],
    int maxWords
);

// Menu functions.
bool isValidMenuChoice(int choice);
void printMenu();

#endif