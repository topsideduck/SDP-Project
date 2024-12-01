//
// Created by Harikeshav R on 12/1/24.
//

#ifndef SCORE_HANDLER_H
#define SCORE_HANDLER_H

#include <string>
#include <vector>

namespace game
{
    class ScoreHandler
    {
    public:
        explicit ScoreHandler(const std::string& filename);

        ~ScoreHandler();

        // Save scores to the file
        void save_score(unsigned int score) const;

        std::vector<unsigned int> load_scores() const;

        std::vector<unsigned int> get_last_three_scores() const;

        unsigned int get_high_score() const;

    private:
        std::string filename;
    };

} // game

#endif //SCORE_HANDLER_H
