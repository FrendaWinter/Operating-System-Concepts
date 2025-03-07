#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

#define LENGTH 30
#define FRAME_SIZE 7 

void printFrames(const vector<int>& frames) {
    for (int page : frames) {
        if (page == -1) cout << "- ";
        else cout << page << " ";
    }
    cout << endl;
}

// FIFO (First-Come-First-Serve) Algorithm
int fifo(const string &input, vector<int> frames) {
    int pageFaults = 0, framePointer = 0;
    for (char page : input) {
        int num = page - '0';
        if (find(frames.begin(), frames.end(), num) != frames.end()) continue;
        
        frames[framePointer] = num;
        framePointer = (framePointer + 1) % FRAME_SIZE;
        pageFaults++;
        // printFrames(frames);
    }
    cout << "FIFO Page Faults: " << pageFaults << endl;
    return pageFaults;
}

// LRU (Least Recently Used) Algorithm
int lru(const string &input, vector<int> frames) {
    int pageFaults = 0;
    unordered_map<int, int> lastUsed;
    for (int i = 0; i < input.size(); i++) {
        int num = input[i] - '0';
        auto it = find(frames.begin(), frames.end(), num);
        
        if (it == frames.end()) { // Page fault
            if (find(frames.begin(), frames.end(), -1) != frames.end()) {
                *find(frames.begin(), frames.end(), -1) = num;
            } else {
                int lruPage = *min_element(frames.begin(), frames.end(), [&](int a, int b) {
                    return lastUsed[a] < lastUsed[b];
                });
                replace(frames.begin(), frames.end(), lruPage, num);
            }
            pageFaults++;
            // printFrames(frames);
        }
        lastUsed[num] = i;
    }
    cout << "LRU Page Faults: " << pageFaults << endl;
    return pageFaults;
}

// Optimal Page Replacement Algorithm
int optimal(const string &input, vector<int> frames) {
    int pageFaults = 0;
    for (int i = 0; i < input.size(); i++) {
        int num = input[i] - '0';
        if (find(frames.begin(), frames.end(), num) != frames.end()) continue;

        if (find(frames.begin(), frames.end(), -1) != frames.end()) {
            *find(frames.begin(), frames.end(), -1) = num;
        } else {
            int farthest = -1, replaceIndex = -1;
            for (int j = 0; j < FRAME_SIZE; j++) {
                int nextUse = find(input.begin() + i, input.end(), frames[j]) - input.begin();
                if (nextUse > farthest) {
                    farthest = nextUse;
                    replaceIndex = j;
                }
            }
            frames[replaceIndex] = num;
        }
        pageFaults++;
        // printFrames(frames);
    }
    cout << "Optimal Page Faults: " << pageFaults << endl;
    return pageFaults;
}

int main() {
    string refString;
    refString.reserve(LENGTH);
    
    mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, 9);
    
    for (int i = 0; i < LENGTH; i++) {
        refString += '0' + dist(rng);
    }
    
    cout << "Generated string: " << refString << endl;
    
    vector<int> frames(FRAME_SIZE, -1);
    fifo(refString, frames);
    frames.assign(FRAME_SIZE, -1);
    lru(refString, frames);
    frames.assign(FRAME_SIZE, -1);
    optimal(refString, frames);
    
    return 0;
}
