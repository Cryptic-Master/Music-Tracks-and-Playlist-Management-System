#include "MusicTrack.h"
#include <iostream>
using namespace std;

int main() {
    MusicTrack playlists[20];
    int playlistCount = 0;
    int choice = 0;

    while (choice != 13) {
        cout << "\n=== Music Tracks and Playlist Management System ===\n";
        cout << "1. Create a new playlist\n";
        cout << "2. Add new songs to a playlist\n";
        cout << "3. Remove a playlist\n";
        cout << "4. Copy a playlist\n";
        cout << "5. Display total playlists created\n";
        cout << "6. Show the longest song among all playlists\n";
        cout << "7. Compare two playlists\n";
        cout << "8. Play a song by index\n";
        cout << "9. Display common songs\n";
        cout << "10. Display unique songs\n";
        cout << "11. Remove last song\n";
        cout << "12. Print all songs\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (playlistCount < 20) {
                playlists[playlistCount] = MusicTrack();
                cout << "Playlist " << playlistCount << " created.\n";
                playlistCount++;
            } else {
                cout << "Maximum number of playlists reached.\n";
            }
        }

        else if (choice == 2) {
            int p;
            cout << "Enter playlist number (0-" << playlistCount - 1 << "): ";
            cin >> p;

            if (p >= 0 && p < playlistCount) {
                int n;
                cout << "How many songs to add? ";
                cin >> n;
                Song* arr = new Song[n];
                for (int i = 0; i < n; i++) {
                    cout << "Enter title of song " << i + 1 << ": ";
                    cin.ignore();
                    getline(cin, arr[i].title);
                    cout << "Enter duration: ";
                    cin >> arr[i].duration;
                }
                playlists[p].addNewSongs(arr, n);
                delete[] arr;
            } else {
                cout << "Invalid playlist.\n";
            }
        }

        else if (choice == 3) {
            if (playlistCount > 0) {
                playlistCount--;
                cout << "Last playlist removed.\n";
            } else {
                cout << "No playlist to remove.\n";
            }
        }

        else if (choice == 4) {
            int src;
            cout << "Enter source playlist number: ";
            cin >> src;
            if (src >= 0 && src < playlistCount && playlistCount < 20) {
                playlists[playlistCount] = playlists[src];
                cout << "Playlist copied as " << playlistCount << ".\n";
                playlistCount++;
            } else {
                cout << "Invalid operation.\n";
            }
        }

        else if (choice == 5) {
            cout << "Total playlists created: " << MusicTrack::totalPlaylistsCreated() << endl;
        }

        else if (choice == 6) {
            if (playlistCount == 0)
                cout << "No playlists.\n";
            else {
                Song s = MusicTrack::longestSongInAllPlaylists(playlists, playlistCount);
                if (s.title == "")
                    cout << "No songs found.\n";
                else
                    cout << "Longest song: " << s.title << " (" << s.duration << " min)\n";
            }
        }

        else if (choice == 7) {
            int a, b;
            cout << "Enter two playlist numbers: ";
            cin >> a >> b;
            if (a >= 0 && a < playlistCount && b >= 0 && b < playlistCount) {
                if (playlists[a] >= playlists[b])
                    cout << "Playlist " << a << " has more or equal songs.\n";
                else
                    cout << "Playlist " << b << " has more songs.\n";
            } else {
                cout << "Invalid playlists.\n";
            }
        }

        else if (choice == 8) {
            int p, i;
            cout << "Enter playlist number: ";
            cin >> p;
            if (p >= 0 && p < playlistCount) {
                cout << "Enter song index: ";
                cin >> i;
                if (i >= 0 && i < playlists[p].size())
                    cout << "Playing: " << playlists[p][i].title << endl;
                else
                    cout << "Invalid song index.\n";
            } else {
                cout << "Invalid playlist.\n";
            }
        }

        else if (choice == 9) {
            int a, b;
            cout << "Enter two playlist numbers: ";
            cin >> a >> b;
            if (a >= 0 && b >= 0 && a < playlistCount && b < playlistCount) {
                MusicTrack common = playlists[a] + playlists[b];
                cout << "Common songs:\n" << common;
            } else {
                cout << "Invalid playlists.\n";
            }
        }

        else if (choice == 10) {
            int a, b;
            cout << "Enter two playlist numbers: ";
            cin >> a >> b;
            if (a >= 0 && b >= 0 && a < playlistCount && b < playlistCount) {
                MusicTrack unique = playlists[a] - playlists[b];
                cout << "Unique songs in playlist " << a << ":\n" << unique;
            } else {
                cout << "Invalid playlists.\n";
            }
        }

        else if (choice == 11) {
            int p;
            cout << "Enter playlist number: ";
            cin >> p;
            if (p >= 0 && p < playlistCount) {
                playlists[p]--;
                cout << "Last song removed.\n";
            } else {
                cout << "Invalid playlist.\n";
            }
        }

        else if (choice == 12) {
            int p;
            cout << "Enter playlist number: ";
            cin >> p;
            if (p >= 0 && p < playlistCount)
                cout << playlists[p];
            else
                cout << "Invalid playlist.\n";
        }

        else if (choice == 13) {
            cout << "Exiting program...\n";
        }

        else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
