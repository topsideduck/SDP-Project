#define MINIAUDIO_IMPLEMENTATION
#include "src/util/audio_manager.h"

#include <cstring>
#include <iostream>
#include "src/lib/miniaudio.h"

namespace game
{
    /**
     * @brief Constructs the AudioManager object and initializes the audio decoder and playback device.
     *
     * @param file_path The path to the audio file to be loaded.
     */
    AudioManager::AudioManager(const std::string &file_path)
    {
        // Initialize the audio decoder for the specified file.
        if (ma_decoder_init_file(file_path.c_str(), nullptr, &m_decoder) != MA_SUCCESS)
        {
            std::cerr << "Failed to initialize decoder." << std::endl;
            return;
        }

        // Configure the playback device with properties matching the decoder output.
        ma_device_config device_config = ma_device_config_init(ma_device_type_playback);
        device_config.playback.format = m_decoder.outputFormat;
        device_config.playback.channels = m_decoder.outputChannels;
        device_config.sampleRate = m_decoder.outputSampleRate;
        device_config.dataCallback = data_callback;
        device_config.pUserData = this;

        // Initialize the playback device.
        if (ma_device_init(nullptr, &device_config, &m_device) != MA_SUCCESS)
        {
            std::cerr << "Failed to initialize playback device." << std::endl;
            ma_decoder_uninit(&m_decoder);
            return;
        }

        // Mark the manager as initialized.
        m_is_initialized = true;
    }

    /**
     * @brief Destructor that releases all allocated resources, including the decoder and playback device.
     */
    AudioManager::~AudioManager()
    {
        if (m_is_initialized)
        {
            // Uninitialize the playback device and decoder.
            ma_device_uninit(&m_device);
            ma_decoder_uninit(&m_decoder);
        }
    }

    /**
     * @brief Starts playback of the loaded audio file.
     */
    void AudioManager::play()
    {
        if (m_is_initialized)
        {
            // Start the playback device.
            if (ma_device_start(&m_device) != MA_SUCCESS)
            {
                std::cerr << "Failed to start playback." << std::endl;
            }
        }
    }

    /**
     * @brief Stops playback of the audio file.
     */
    void AudioManager::stop()
    {
        if (m_is_initialized)
        {
            // Stop the playback device.
            ma_device_stop(&m_device);
        }
    }

    /**
     * @brief Retrieves the total duration of the audio file in seconds.
     *
     * @return The audio duration in seconds, or 0.0 if initialization failed.
     */
    double AudioManager::get_audio_length_in_seconds() const
    {
        if (!m_is_initialized)
        {
            std::cerr << "AudioManager is not properly initialized." << std::endl;
            return 0.0;
        }

        // Get the total number of PCM frames in the audio file.
        ma_uint64 total_frames = 0;
        if (ma_decoder_get_length_in_pcm_frames(const_cast<ma_decoder *>(&m_decoder), &total_frames) != MA_SUCCESS)
        {
            std::cerr << "Failed to get the total number of PCM frames." << std::endl;
            return 0.0;
        }

        // Calculate the audio duration in seconds.
        return static_cast<double>(total_frames) / m_decoder.outputSampleRate;
    }

    /**
     * @brief Checks whether the playback of the audio file has completed.
     *
     * @return True if playback is complete, false otherwise.
     */
    bool AudioManager::is_playback_complete() const
    {
        return m_playback_complete;
    }

    /**
     * @brief Callback function to handle audio data during playback.
     *
     * @param device Pointer to the playback device.
     * @param output Pointer to the output buffer.
     * @param input Pointer to the input buffer (not used).
     * @param frame_count The number of audio frames to process.
     */
    void AudioManager::data_callback(ma_device *device, void *output, const void *input, ma_uint32 frame_count)
    {
        // Retrieve the AudioManager instance from the device user data.
        AudioManager *manager = reinterpret_cast<AudioManager *>(device->pUserData);

        ma_uint64 frames_read = 0;
        // Read audio frames from the decoder.
        ma_result result = ma_decoder_read_pcm_frames(&manager->m_decoder, output, frame_count, &frames_read);

        // If not enough frames are read, fill the remaining buffer with silence.
        if (result != MA_SUCCESS || frames_read < frame_count)
        {
            manager->m_playback_complete = true;

            memset(static_cast<unsigned char *>(output) + (frames_read * ma_get_bytes_per_frame(
                                                               device->playback.format, device->playback.channels)),
                   0,
                   (frame_count - frames_read) * ma_get_bytes_per_frame(
                       device->playback.format, device->playback.channels));
        }

        (void) input; // Suppress unused parameter warning.
    }
}
