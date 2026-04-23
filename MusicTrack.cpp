//HabibaElsayedHemayed20255110_ReemMohamedBehairy20246053
#include "MusicTrack.h"

int MusicTrack::total_playlists_created = 0;

MusicTrack::MusicTrack() {
    capacity = 5;
    playlist_size = 0;
    playlist = new Song[capacity];
    total_playlists_created++;
}

MusicTrack::MusicTrack(const MusicTrack& other) {
    capacity = other.capacity;
    playlist_size = other.playlist_size;
    playlist = new Song[capacity];
    for (int i = 0; i < playlist_size; i++)
        playlist[i] = other.playlist[i];
    total_playlists_created++;
}

MusicTrack::~MusicTrack() {
    delete[] playlist;
}

MusicTrack& MusicTrack::operator=(const MusicTrack& other) {
    if (this != &other) {
        delete[] playlist;
        capacity = other.capacity;
        playlist_size = other.playlist_size;
        playlist = new Song[capacity];
        for (int i = 0; i < playlist_size; i++)
            playlist[i] = other.playlist[i];
    }
    return *this;
}

void MusicTrack::resize(int newCap) {
    Song* temp = new Song[newCap];
    for (int i = 0; i < playlist_size; i++)
        temp[i] = playlist[i];
    delete[] playlist;
    playlist = temp;
    capacity = newCap;
}

void MusicTrack::addNewSongs(Song arr[], int count) {
    if (playlist_size + count > capacity)
        resize(capacity + count);
    for (int i = 0; i < count; i++)
        playlist[playlist_size++] = arr[i];
}

int MusicTrack::size() const {
    return playlist_size;
}

Song& MusicTrack::operator[](int index) {
    return playlist[index];
}

const Song& MusicTrack::operator[](int index) const {
    return playlist[index];
}

int MusicTrack::totalPlaylistsCreated() {
    return total_playlists_created;
}

Song MusicTrack::longestSongInAllPlaylists(MusicTrack arr[], int count) {
    Song longest;
    longest.title = "";
    longest.duration = 0.0;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < arr[i].playlist_size; j++) {
            if (arr[i].playlist[j].duration > longest.duration)
                longest = arr[i].playlist[j];
        }
    }
    return longest;
}

bool operator>=(const MusicTrack& a, const MusicTrack& b) {
    return a.playlist_size >= b.playlist_size;
}

MusicTrack MusicTrack::operator+(const MusicTrack& other) const {
    MusicTrack result;
    for (int i = 0; i < playlist_size; i++) {
        for (int j = 0; j < other.playlist_size; j++) {
            if (playlist[i].title == other.playlist[j].title &&
                playlist[i].duration == other.playlist[j].duration) {
                result.addNewSongs(&playlist[i], 1);
            }
        }
    }
    return result;
}

MusicTrack MusicTrack::operator-(const MusicTrack& other) const {
    MusicTrack result;
    for (int i = 0; i < playlist_size; i++) {
        bool found = false;
        for (int j = 0; j < other.playlist_size; j++) {
            if (playlist[i].title == other.playlist[j].title &&
                playlist[i].duration == other.playlist[j].duration) {
                found = true;
                break;
            }
        }
        if (!found)
            result.addNewSongs(&playlist[i], 1);
    }
    return result;
}

MusicTrack MusicTrack::operator--(int) {
    MusicTrack temp = *this;
    if (playlist_size > 0)
        playlist_size--;
    return temp;
}

ostream& operator<<(ostream& os, const MusicTrack& mt) {
    os << "Playlist (" << mt.playlist_size << " songs):\n";
    for (int i = 0; i < mt.playlist_size; i++) {
        os << i + 1 << ". " << mt.playlist[i].title
           << " (" << mt.playlist[i].duration << " min)\n";
    }
    return os;
}
