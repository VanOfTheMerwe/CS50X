# The Playlist Helper
#### Video Demo: (https://youtu.be/9MeYWDBuK6A)
#### Description:
Playlist Helper is a Python application that assists in managing music playlists by identifying new songs that need to be added to an existing playlist.

## Features:
- Scans a directory for files that the user has on their computer.
- Lists the scanned files into a txt file. (already_in_playlist.txt)
- Compares the list (already_in_playlist.txt) with another list (to_be_added.txt) to see what songs are missing.
- Creates another list (songs_to_add.txt) and appends the names of the missing songs to that list.
- A popup which notifies the user that the creation of the list is complete.
- Automatically opens the (songs_to_add.txt) for the user.

## Libraries used:
- os
- sys
- tkinter

## Requirements:
- Python 3.x
- tkinter (usually already installed with Python.)

## Functions:

### show_popup(message, root)
This function creates and displays a popup window that notifies the user that the program has finished running, and how many songs were appended to the list.
The function takes two parameters:
- 'message' : This is a variable which displays when the program has finished, there are two possible messages depending on the outcome of the if statement wherein it is.
- 'root : The root Tkinter window

### add_names_to_txt(directory, in_playlist)
This function scans through the specified directory and appends the names of the files to the txt file (already_in_playlist.txt) without any of the extensions.
The function takes two parameters:
- 'directory' : This is the file path to the music directory where all of the music files have been stored.
- 'in_playlist' : This is the name of the txt file where all of the names will be appended to.

### compare_text_files(file1, file2)
This function is not present in the main flow of the program but can be useful when debugging. It compares the files line by line and prints to the terminal what the differences are.
This function takes two parameters:
- 'file1' : Path to the first file.
- 'file2' : Path to the second file.

### compare_files(file1, file2)
This function compares the two files to see which songs from file1 are not present in file2.
This function takes two parameters:
- 'file1' : The path to the file which contains the list of all of the songs to be added.
- 'file2' : The path to the file which contains the list of the songs already in the playlist.

### clear_text_file(file)
This function clears the contents of the specified file. This is useful when we rerun the program several times to avoid incorrect information.
This function only takes one parameter:
- 'file' : The path to the file to be cleared.

### append_songs_to_file(songs, filename)
This function appends teh given list of songs to the specified file.
This function takes two parameters:
- 'songs' : The list of songs to be appended.
- 'filename' : The path to the file where the songs will be appended to.

### open_file(filename)
This function opens the file of the songs that need to be added after all of the other comparisons and appending.
This function only takes one parameter:
- 'filename' : The path to the file to be opened.

## Notes:
The program does not run in codespace. It only works locally.

## Contributing:
I received some help from ChatGPT, and Claude AI in this project to explain how to do certain things. The implementation was done mainly by myself.

