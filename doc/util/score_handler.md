# Score Handler README

## Overview

The Score Handler module is responsible for managing game scores. It provides functionality to save scores, load scores
from a file, retrieve the highest score, and get the last three scores. The scores are stored in a binary file for
efficient reading and writing.

## Features

- **Save Score**: Saves a new score to the binary file.
- **Load Scores**: Loads all stored scores from the file.
- **Get Last Three Scores**: Retrieves the last three scores from the file.
- **Get High Score**: Retrieves the highest score from the stored scores.

## File Structure

The Score Handler consists of two main files:

- `score_handler.cpp`: Implements the `ScoreHandler` class and its methods.
- `score_handler.h`: Declares the `ScoreHandler` class and its methods.

## Classes

### ScoreHandler

The `ScoreHandler` class provides methods to interact with the score data. It is initialized with a file path and
handles the following tasks:

- **Constructor**: Initializes the score file. If the file does not exist, it creates the file with default scores set
  to zero.
- **Destructor**: Default destructor (no specific cleanup required).
- **save_score()**: Saves a new score to the file.
- **load_scores()**: Loads all scores from the file and returns them as a vector.
- **get_last_three_scores()**: Retrieves the last three scores from the file. If there are fewer than three scores, it
  returns all of them.
- **get_high_score()**: Retrieves the highest score from the file.

## Functions

### Constructor: `ScoreHandler(const std::string &filename)`

Initializes the `ScoreHandler` with the specified file path. If the file doesn't exist, it creates the file and
initializes it with default values (three zero scores).

### Method: `save_score(unsigned int score) const`

Saves a score to the binary file. This method appends the score to the existing data in the file.

### Method: `load_scores() const`

Loads all scores from the file and returns them as a vector of unsigned integers. If the file cannot be opened, it
returns an empty vector.

### Method: `get_last_three_scores() const`

Returns the last three scores from the file. If there are fewer than three scores, it returns all the scores. It returns
a vector of unsigned integers.

### Method: `get_high_score() const`

Returns the highest score from the file. If the file is empty or no scores are available, it returns zero.

## Example Usage

```cpp
#include "score_handler.h"
#include <iostream>

int main()
{
    game::ScoreHandler score_handler("scores.dat");

    // Save a new score
    score_handler.save_score(500);

    // Load all scores
    std::vector<unsigned int> scores = score_handler.load_scores();
    for (unsigned int score : scores)
    {
        std::cout << "Score: " << score << std::endl;
    }

    // Get last three scores
    std::vector<unsigned int> last_three = score_handler.get_last_three_scores();
    std::cout << "Last three scores:" << std::endl;
    for (unsigned int score : last_three)
    {
        std::cout << score << std::endl;
    }

    // Get the high score
    unsigned int high_score = score_handler.get_high_score();
    std::cout << "High score: " << high_score << std::endl;

    return 0;
}
```