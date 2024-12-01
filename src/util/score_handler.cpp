//
// Created by Harikeshav R on 12/1/24.
//

#include "src/util/score_handler.h"

#include <fstream>
#include <iostream>
#include <vector>


namespace game
{
    ScoreHandler::ScoreHandler(const std::string& filename) : filename(filename) {}

    ScoreHandler::~ScoreHandler() = default;

    void ScoreHandler::save_score(const unsigned int score) const
    {
        std::ofstream outFile(filename, std::ios::binary | std::ios::app);
        if (!outFile)
        {
            std::cerr << "Error opening file for writing." << std::endl;
            return;
        }
        outFile.write(reinterpret_cast<const char *>(&score), sizeof(score));
        outFile.close();
    }

    std::vector<unsigned int> ScoreHandler::load_scores() const
    {
        std::ifstream inFile(filename, std::ios::binary);
        if (!inFile)
        {
            std::cerr << "Error opening file for reading." << std::endl;
            return {};
        }
        std::vector<unsigned int> scores;
        int score;
        while (inFile.read(reinterpret_cast<char *>(&score), sizeof(score)))
        {
            scores.push_back(score);
        }
        inFile.close();
        return scores;
    }

    std::vector<unsigned int> ScoreHandler::get_last_three_scores() const
    {
        std::vector<unsigned int> scores = load_scores();
        if (scores.size() <= 3)
        {
            return scores; // If there are 3 or fewer scores, return all of them
        }
        return {scores.end() - 3, scores.end()}; // Get the last three scores
    }

    unsigned int ScoreHandler::get_high_score() const
    {
        std::vector<unsigned int> scores = load_scores();
        if (scores.empty())
        {
            return 0; // Return 0 if no scores are available
        }
        return *std::ranges::max_element(scores);
    }
} // game
