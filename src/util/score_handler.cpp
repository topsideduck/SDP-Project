#include "src/util/score_handler.h"
#include <fstream>
#include <iostream>
#include <vector>

namespace game
{
    /**
     * @brief Constructs a ScoreHandler instance and initializes the score file.
     *
     * Checks if the specified file exists. If not, creates the file and initializes it
     * with default scores.
     *
     * @param filename The name of the file used for storing scores.
     */
    ScoreHandler::ScoreHandler(const std::string &filename) : filename(filename)
    {
        if (std::ifstream in_file(filename, std::ios::binary); !in_file)
        {
            // Create and initialize file with default scores if it doesn't exist
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
     * @brief Default destructor for the ScoreHandler class.
     */
    ScoreHandler::~ScoreHandler() = default;

    /**
     * @brief Appends a new score to the file.
     *
     * Writes the given score to the file in binary format.
     *
     * @param score The score to append to the file.
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
     * @brief Reads all scores from the file.
     *
     * Loads all scores stored in the binary file into a vector.
     *
     * @return A vector containing all stored scores.
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
     * @brief Retrieves the last three scores stored in the file.
     *
     * If fewer than three scores are available, all scores are returned.
     *
     * @return A vector containing the last three scores.
     */
    std::vector<unsigned int> ScoreHandler::get_last_three_scores() const
    {
        std::vector<unsigned int> scores = load_scores();
        if (scores.size() <= 3)
        {
            return scores;
        }
        return {scores.end() - 3, scores.end()};
    }

    /**
     * @brief Finds and returns the highest score in the file.
     *
     * If no scores are stored, returns 0.
     *
     * @return The highest score as an unsigned integer.
     */
    unsigned int ScoreHandler::get_high_score() const
    {
        std::vector<unsigned int> scores = load_scores();
        if (scores.empty())
        {
            return 0;
        }
        return *std::ranges::max_element(scores);
    }
} // namespace game
