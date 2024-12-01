// score_handler.cpp

#include "src/util/score_handler.h"

#include <fstream>
#include <iostream>
#include <vector>

namespace game
{
    /**
     * @brief Constructor for the ScoreHandler class.
     *
     * Initializes the score handler by checking if the file exists.
     * If the file does not exist, it creates a new file and writes default scores to it.
     *
     * @param filename The name of the file to manage scores.
     */
    ScoreHandler::ScoreHandler(const std::string &filename) : filename(filename)
    {
        if (std::ifstream in_file(filename, std::ios::binary); !in_file)
        {
            // File does not exist, create and initialize it
            if (std::ofstream out_file(filename, std::ios::binary); out_file)
            {
                int default_scores[3] = {0, 0, 0};
                out_file.write(reinterpret_cast<const char *>(default_scores), sizeof(default_scores));
                out_file.close();
            }
            else
            {
                std::cerr << "Error creating file." << std::endl;
            }
        }
        else
        {
            std::cout << "File already exists." << std::endl;
        }
    }

    /**
     * @brief Destructor for the ScoreHandler class.
     *
     * Cleans up resources associated with the ScoreHandler instance.
     */
    ScoreHandler::~ScoreHandler() = default;

    /**
     * @brief Saves a single score to the file.
     *
     * Appends the given score to the score file in binary format.
     *
     * @param score The score to save.
     */
    void ScoreHandler::save_score(const unsigned int score) const
    {
        std::ofstream out_file(filename, std::ios::binary | std::ios::app);
        if (!out_file)
        {
            std::cerr << "Error opening file for writing." << std::endl;
            return;
        }
        out_file.write(reinterpret_cast<const char *>(&score), sizeof(score));
        out_file.close();
    }

    /**
     * @brief Loads all scores from the file.
     *
     * Reads all stored scores from the file and returns them in a vector.
     *
     * @return A vector of unsigned integers representing the stored scores.
     */
    std::vector<unsigned int> ScoreHandler::load_scores() const
    {
        std::ifstream in_file(filename, std::ios::binary);
        if (!in_file)
        {
            std::cerr << "Error opening file for reading." << std::endl;
            return {};
        }
        std::vector<unsigned int> scores;
        int score;
        while (in_file.read(reinterpret_cast<char *>(&score), sizeof(score)))
        {
            scores.push_back(score);
        }
        in_file.close();
        return scores;
    }

    /**
     * @brief Retrieves the last three scores.
     *
     * Returns the last three scores stored in the file. If there are fewer than
     * three scores, all available scores are returned.
     *
     * @return A vector containing the last three scores.
     */
    std::vector<unsigned int> ScoreHandler::get_last_three_scores() const
    {
        std::vector<unsigned int> scores = load_scores();
        if (scores.size() <= 3)
        {
            return scores; // If there are 3 or fewer scores, return all of them
        }
        return {scores.end() - 3, scores.end()}; // Get the last three scores
    }

    /**
     * @brief Retrieves the highest score.
     *
     * Finds and returns the highest score from the scores stored in the file.
     * If no scores are available, it returns 0.
     *
     * @return The highest score as an unsigned integer.
     */
    unsigned int ScoreHandler::get_high_score() const
    {
        std::vector<unsigned int> scores = load_scores();
        if (scores.empty())
        {
            return 0; // Return 0 if no scores are available
        }
        return *std::ranges::max_element(scores);
    }
} // namespace game
