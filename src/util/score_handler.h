// score_handler.h

#ifndef SCORE_HANDLER_H
#define SCORE_HANDLER_H

#include <string>
#include <vector>

namespace game
{
    /**
     * @brief Class for managing game scores.
     *
     * The ScoreHandler class allows for storing, retrieving, and managing scores
     * in a binary file. It provides methods for saving new scores, retrieving all scores,
     * fetching the last three scores, and finding the highest score.
     */
    class ScoreHandler
    {
    public:
        /**
         * @brief Constructor that initializes the score handler.
         *
         * @param filename The name of the file used to store scores.
         */
        explicit ScoreHandler(const std::string &filename);

        /**
         * @brief Destructor for cleaning up resources.
         */
        ~ScoreHandler();

        /**
         * @brief Saves a new score to the file.
         *
         * @param score The score to save.
         */
        void save_score(unsigned int score) const;

        /**
         * @brief Loads all stored scores from the file.
         *
         * @return A vector of unsigned integers representing the scores.
         */
        std::vector<unsigned int> load_scores() const;

        /**
         * @brief Gets the last three scores from the file.
         *
         * @return A vector of the last three scores.
         */
        std::vector<unsigned int> get_last_three_scores() const;

        /**
         * @brief Finds and returns the highest score.
         *
         * @return The highest score as an unsigned integer.
         */
        unsigned int get_high_score() const;

    private:
        std::string filename; /**< The name of the file storing scores. */
    };
} // namespace game

#endif // SCORE_HANDLER_H
