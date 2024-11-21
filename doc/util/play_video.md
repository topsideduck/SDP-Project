# Play Video

## 1. Purpose:

- `play_video` simulates video playback by displaying a sequence of PNG image frames from a specified folder on an LCD
  screen.

## 2. Code Highlights:

- **play_video.cpp** handles the logic for loading, displaying, and updating frames.
- **play_video.h** declares the play_video function and includes the necessary standard headers.

## 3. Workflow:

- Each frame file is named using a base name followed by a numerical index and ".png".
- The function constructs the file path for each frame, clears the screen, loads the image using `FEHImage`, draws it at
  the top-left corner (0, 0), and updates the LCD to display the image.

## 4. Design Notes:

- Uses `std::filesystem` for file path management.
- Ensures sequential display of frames by incrementing a counter.