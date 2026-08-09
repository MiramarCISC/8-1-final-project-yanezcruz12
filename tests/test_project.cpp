#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include "project.hpp"

using namespace std;

bool nearlyEqual(double actual, double expected, double tolerance = 0.0001) {
    return fabs(actual - expected) <= tolerance;
}

// Week 1: Program Basics
void testAverageStudyLevelCalculation() {
    VocabularyWord words[2];

    words[0] = {"勉強", "study", 4, false};
    words[1] = {"学校", "school", 2, false};

    double average = calculateAverageStudyLevel(words, 2);

    assert(nearlyEqual(average, 3.0));
}

// Week 2: Decisions and Loops
void testStudyLevelValidation() {
    assert(isValidStudyLevel(1) == true);
    assert(isValidStudyLevel(5) == true);
    assert(isValidStudyLevel(0) == false);
    assert(isValidStudyLevel(6) == false);
}

// Week 3: Functions and Program Design
void testCountStudyWords() {
    StudyNode* head = nullptr;

    VocabularyWord word1 = {"話す", "speak", 3, false};
    VocabularyWord word2 = {"読む", "read", 2, false};

    insertStudyWord(head, word1);
    insertStudyWord(head, word2);

    assert(countStudyWords(head) == 2);

    clearStudyList(head);
}

// Week 4: Arrays, Searching, and Sorting
void testArraySearchAndSort() {
    VocabularyWord words[3];

    words[0] = {"学校", "school", 5, false};
    words[1] = {"食べる", "eat", 2, false};
    words[2] = {"話す", "speak", 4, false};

    assert(findWord(words, 3, "食べる") == 1);
    assert(findWord(words, 3, "見る") == -1);

    sortByStudyLevel(words, 3);

    assert(words[0].studyLevel == 2);
    assert(words[1].studyLevel == 4);
    assert(words[2].studyLevel == 5);
}

// Week 5: Strings and Structures
void testVocabularyStructure() {
    VocabularyWord word;

    word.japanese = "先生";
    word.english = "teacher";
    word.studyLevel = 5;
    word.studied = false;

    assert(word.japanese == "先生");
    assert(word.english == "teacher");
    assert(word.studyLevel == 5);
}

// Week 6: Pointers, Dynamic Memory, and Linked Lists
void testLinkedStudyList() {
    StudyNode* head = nullptr;

    VocabularyWord word = {"勉強", "study", 4, false};

    insertStudyWord(head, word);

    assert(head != nullptr);
    assert(head->data.japanese == "勉強");
    assert(findStudyWord(head, "勉強") != nullptr);
    assert(findStudyWord(head, "学校") == nullptr);

    clearStudyList(head);

    assert(head == nullptr);
}

// Week 7: File I/O and Integration
void testVocabularyFileLoad() {
    ofstream output("tests/resources/sample_vocabulary.txt");

    output << "勉強 study 4" << endl;
    output << "学校 school 5" << endl;
    output.close();

    VocabularyWord words[10];

    int count = loadVocabularyFromFile(
        "tests/resources/sample_vocabulary.txt",
        words,
        10
    );

    assert(count == 2);
    assert(words[0].japanese == "勉強");
    assert(words[1].english == "school");
    assert(words[1].studyLevel == 5);
}

int main() {
    testAverageStudyLevelCalculation();
    testStudyLevelValidation();
    testCountStudyWords();
    testArraySearchAndSort();
    testVocabularyStructure();
    testLinkedStudyList();
    testVocabularyFileLoad();

    cout << "All final project tests passed!" << endl;

    return 0;
}