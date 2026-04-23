#ifndef MUSICTRACK_H
#define MUSICTRACK_H

#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    double duration;
};

class MusicTrack {
private:
    Song* playlist;
    int playlist_size;
    int capacity;

    void resize(int newCap);

public:
    static int total_playlists_created;

    MusicTrack();
    MusicTrack(const MusicTrack& other);
    ~MusicTrack();
    MusicTrack& operator=(const MusicTrack& other);

    void addNewSongs(Song arr[], int count);
    int size() const;
    Song& operator[](int index);
    const Song& operator[](int index) const;

    static int totalPlaylistsCreated();
    static Song longestSongInAllPlaylists(MusicTrack arr[], int count);

    friend bool operator>=(const MusicTrack& a, const MusicTrack& b);
    MusicTrack operator+(const MusicTrack& other) const;
    MusicTrack operator-(const MusicTrack& other) const;
    MusicTrack operator--(int);

    friend ostream& operator<<(ostream& os, const MusicTrack& mt);
};

#endif
