#ifndef SCORE_HANDLER_H
#define SCORE_HANDLER_H

#include <string>
#include <vector>

namespace game
{
    /**
     * @brief Manages game scores by storing and retrieving them from a file.
     *
     * Provides methods to save scores, load all scores, retrieve the last three scores,
     * and determine the highest score.
     */
    class ScoreHandler
    {
    public:
        /**
         * @brief Constructs a ScoreHandler instance with the specified file.
         *
         * @param filename The name of the file for score management.
         */
        explicit ScoreHandler(const std::string &filename);

        /**
         * @brief Destructor for the ScoreHandler class.
         */
        ~ScoreHandler();

        /**
         * @brief Saves a new score to the file.
         *
         * @param score The score to be added to the file.
         */
        void save_score(unsigned int score) const;

        /**
         * @brief Loads all scores stored in the file.
         *
         * @return A vector containing all stored scores.
         */
        std::vector<unsigned int> load_scores() const;

        /**
         * @brief Retrieves the last three scores from the file.
         *
         * @return A vector of the last three scores.
         */
        std::vector<unsigned int> get_last_three_scores() const;

        /**
         * @brief Finds and returns the highest score from the file.
         *
         * @return The highest score as an unsigned integer.
         */
        unsigned int get_high_score() const;

    private:
        std::string filename; /**< The name of the file used for storing scores. */
    };
} // namespace game

#endif // SCORE_HANDLER_H
