import os
import sys
import tkinter as tk
from tkinter import messagebox

directory = r'C:\Users\Drikus\Music\USB'

in_playlist = 'already_in_playlist.txt'
need_to_add = 'to_be_added.txt'
songs_to_really_add = 'songs_to_add.txt'

message_complete = f'All outstanding songs were added to {songs_to_really_add}.'
message_none_to_add = f'There were no new entries.'

def show_popup(message, root):
    popup = tk.Toplevel(root)
    popup.title('The Playlist Helper')
    popup.geometry('300x200')
    popup.config(bg='green')

    label = tk.Label(popup, text=message, font=('Helvitica', 14), fg='darkgreen', bg='lightgreen', wraplength=250)
    label.pack(pady=20)

    close_button = tk.Button(popup, text='Close', font=('Helvitica', 12), command=root.destroy)
    close_button.pack(pady=10)

    popup.protocol('WM_DELETE_WINDOW', root.destroy)

    return popup

def add_names_to_txt(directory, in_playlist):
    files = os.listdir(directory)
    with open(in_playlist, 'a') as file:
        for filename in files:
            filename = filename.replace('.mp3', '').replace('.wav', '').replace('.m4a', '')
            file.write(filename + '\n')

def compare_text_files(file1, file2):
    with open(file1, 'r') as file1, open(file2, 'r') as file2:
        lines1 = file1.readlines()
        lines2 = file2.readlines()
    for line_num, (line1, line2) in enumerate(zip(lines1, lines2), start=1):
        if line1 != line2:
            print(f'Difference found in line {line_num}:')
            print(f'Line 1: {line1.strip()}')
            print(f'Line 2: {line2.strip()}')
            print()
    if len(lines1) > len(lines2):
        print(f'File {file1} is longer than {file2}')
        for i, line in enumerate(lines1[len(lines2):], start=len(lines2)+1):
            print(f'Extra line {i} in File 1: {line.strip()}')
    elif len(lines2) > len(lines1):
        print(f'File {file2} is longer than {file1}')
        for i, line in enumerate(lines2[len(lines1):], start=len(lines1)+1):
            print(f'Extra line {i} in File 2: {line.strip()}')

def compare_files(file1, file2):
    def find_songs(search_terms,filename):
        results = {}
        with open(filename, 'r') as file:
            lines = file.readlines()
            for term in search_terms:
                term = term.strip()
                results[term] = [i+1 for i, line in enumerate(lines) if term.lower() in line.lower()]
        return results
    with open(file1, 'r') as file:
        search_terms = file.readlines()
    matches = find_songs(search_terms, file2)
    return matches

def clear_text_file(file):
    with open(file, 'w') as file:
        file.truncate(0)

def append_songs_to_file(songs, filename):
    with open(filename, 'a') as file:
        for song in songs:
            file.write(song + '\n')
    # print(f"{len(songs)} songs appended to {filename}")

def open_file(filename):
    try:
        os.startfile(filename)
    except AttributeError:
        import subprocess
        opener = 'open' if sys.platform == 'darwin' else 'xdg-open'
        subprocess.call([opener, filename])

def main():
    root = tk.Tk()
    root.withdraw()

    clear_text_file(in_playlist)
    clear_text_file(songs_to_really_add)
    add_names_to_txt(directory, in_playlist)
    
    results = compare_files(need_to_add, in_playlist)
    not_in_playlist = [term.strip() for term, lines in results.items() if not lines]
    
    if not_in_playlist:
        # print("Songs not yet added to playlist:")
        popup = show_popup(message_complete, root)
        for song in not_in_playlist:
            # Append songs to a new file
            append_songs_to_file(not_in_playlist, songs_to_really_add)
    
    else:
        popup = show_popup(message_none_to_add, root)


    open_file(songs_to_really_add)
    root.mainloop()
    

if __name__ == "__main__":
    main()