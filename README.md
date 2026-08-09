# Japanese Vocabulary Study Manager

## Overview

For my CISC 192 final project, I decided to create a Japanese Vocabulary Study Manager. I wanted to 
create something related to my major which is Japanese. The program allows the user to view Japanese vocabulary words, add new words, search for words, sort vocabulary by study level, add words to a study list, and view study information.

Vocabulary words are loaded from a file when the program starts.

## Build and Run

```bash
make
./main
```

## Run Tests

```bash
make test
```

## Clean Build Files

```bash
make clean
```

## Project Features

The program allows the user to:

- View vocabulary words
- Add new vocabulary words
- Search for a Japanese word
- Sort vocabulary by study level
- Choose word to study list
- View the study list
- Calculate the average study level
- Load vocabulary from `data/vocabulary.txt`

Study levels range from 1 to 5:

- 1 = New
- 2 = Learning
- 3 = Familiar
- 4 = Good
- 5 = Know very well

## Course Topics Integrated and Tested

1. Week 1 Program Basics
   - Code location: `src/main.cpp` and `calculateAverageStudyLevel()` in `src/project.cpp`
   - Uses variables, data types, arithmetic, input, and output.
   - Test location: `testAverageStudyLevelCalculation()` in `tests/test_project.cpp`

2. Week 2 Decisions and Loops
   - Code location: `src/main.cpp` and `isValidStudyLevel()` in `src/project.cpp`
   - Uses a `do-while` loop, `switch`, `if` statements, and input validation.
   - Test location: `testStudyLevelValidation()` in `tests/test_project.cpp`

3. Week 3 Functions and Program Design
   - Code location: `include/project.hpp` and `src/project.cpp`
   - Uses separate functions with parameters and return values.
   - Test location: `testCountStudyWords()` in `tests/test_project.cpp`

4. Week 4 Arrays, Searching, and Sorting
   - Code location: `findWord()` and `sortByStudyLevel()` in `src/project.cpp`
   - Uses an array of vocabulary words with searching and sorting.
   - Test location: `testArraySearchAndSort()` in `tests/test_project.cpp`

5. Week 5 Strings and Structures
   - Code location: `VocabularyWord` structure in `include/project.hpp`
   - Uses `std::string` to store Japanese words and English meanings.
   - Test location: `testVocabularyStructure()` in `tests/test_project.cpp`

6. Week 6 Pointers, Dynamic Memory, and Linked Lists
   - Code location: `StudyNode`, `insertStudyWord()`, `findStudyWord()`, and `clearStudyList()`
   - Uses pointers and dynamically allocated linked-list nodes with `new`.
   - Uses `delete` when the study list is cleared.
   - Test location: `testLinkedStudyList()` in `tests/test_project.cpp`

7. Week 7 File I/O and Integration
   - Code location: `loadVocabularyFromFile()` in `src/project.cpp`
   - Loads vocabulary data from `data/vocabulary.txt`.
   - Test location: `testVocabularyFileLoad()` in `tests/test_project.cpp`

## Known Limitations

- English meanings should be entered as one word.
- The program can store a maximum of 100 vocabulary words.
- New vocabulary added while the program is running is not saved back to the file.
- Study levels must be between 1 and 5.

## Final Submission Checklist

- [x] My project compiles with `make`.
- [x] My project runs with `./main`.
- [x] My tests run with `make test`.
- [x] I deleted or replaced the sample project code.
- [x] My project integrates all 7 course topics in reachable code.
- [x] My project includes at least one unit test per course topic.
- [x] My README explains where each topic appears.
- [x] My README explains which test verifies each topic.
- [ ] My code is committed and pushed to GitHub Classroom.