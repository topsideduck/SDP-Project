# AudioManager

The `AudioManager` class provides functionality for managing audio playback in a game or application. It uses the `miniaudio` library for decoding and playback.

## Features
- Load audio files for playback.
- Start and stop audio playback.
- Query the duration of audio files in seconds.
- Check if playback has completed.

## Dependencies
- [miniaudio](https://github.com/mackron/miniaudio)

## Class Overview
### AudioManager
- **Constructor**: Initializes the audio manager with a file path.
- **Destructor**: Cleans up all resources.
- **play**: Starts audio playback.
- **stop**: Stops audio playback.
- **get_audio_length_in_seconds**: Returns the total audio duration in seconds.
- **is_playback_complete**: Checks if playback has completed.

## Usage
1. Include the header file: `#include "audio_manager.h"`
2. Create an instance of `AudioManager` by passing the path to the audio file.
3. Use `play` to start playback and `stop` to end it.
4. Call `get_audio_length_in_seconds` to retrieve the audio's duration.

## Example
```cpp
#include "audio_manager.h"

int main() {
    game::AudioManager manager("path/to/audio/file.wav");
    manager.play();

    while (!manager.is_playback_complete()) {
        // Wait for playback to complete.
    }

    manager.stop();
    return 0;
}
```