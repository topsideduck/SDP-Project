#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <string>
#include "src/lib/miniaudio.h"

namespace game
{
    /**
     * @class AudioManager
     * @brief Handles audio playback for a specified audio file, using the miniaudio library.
     *
     * The AudioManager class supports initializing audio from a file, starting and stopping playback,
     * retrieving the total audio duration, and checking if playback has completed.
     */
    class AudioManager
    {
    public:
        /**
         * @brief Constructor to initialize the AudioManager with an audio file.
         *
         * @param file_path The path to the audio file to be loaded.
         */
        explicit AudioManager(const std::string &file_path);

        /**
         * @brief Destructor to release all resources used by the AudioManager.
         */
        ~AudioManager();

        /**
         * @brief Starts audio playback.
         */
        void play();

        /**
         * @brief Stops audio playback.
         */
        void stop();

        /**
         * @brief Retrieves the total duration of the audio file in seconds.
         *
         * @return The duration of the audio in seconds.
         */
        double get_audio_length_in_seconds() const;

        /**
         * @brief Checks if the playback has completed.
         *
         * @return True if playback is complete, false otherwise.
         */
        bool is_playback_complete() const;

    private:
        // Audio decoder used for decoding the audio file.
        ma_decoder m_decoder;

        // Playback device for audio output.
        ma_device m_device;

        // Indicates whether the AudioManager was successfully initialized.
        bool m_is_initialized = false;

        // Indicates whether the playback is complete.
        bool m_playback_complete = false;

        /**
         * @brief Static callback function for processing audio data during playback.
         *
         * @param device Pointer to the playback device.
         * @param output Pointer to the output buffer.
         * @param input Pointer to the input buffer (unused).
         * @param frame_count The number of audio frames to process.
         */
        static void data_callback(ma_device *device, void *output, const void *input, ma_uint32 frame_count);
    };
}

#endif // AUDIO_MANAGER_H
