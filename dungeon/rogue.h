#pragma once

#include "dungeon.h"
#include <vector>
#include <stdexcept>
#include <string>
#include <unordered_set>

void FillAllKeys(const Room* current, std::unordered_set<std::string>& keys) {
    for (size_t ind = 0U; ind < current->NumKeys(); ++ind) {
        keys.insert(current->GetKey(ind));
    }
}

const Room* FindFinalRoom(const Room* starting_room) {
    std::unordered_set<std::string> keys;
    std::unordered_set<const Room*> visited;
    std::unordered_set<const Room*> queue;
    std::unordered_set<Door*> locked;
    queue.insert(starting_room);
    while (!queue.empty()) {
        const Room* current = *queue.begin();
        if (current->IsFinal()) {
            return current;
        }
        visited.insert(current);
        queue.erase(queue.begin());
        FillAllKeys(current, keys);
        for (size_t ind = 0U; ind < current->NumDoors(); ++ind) {
            Door* door = current->GetDoor(ind);
            if (door->IsOpen() && !visited.count(door->GoThrough())) {
                queue.insert(door->GoThrough());
            } else {
                locked.insert(door);
            }
        }
        for (const auto& door : locked) {
            for (const auto& key : keys) {
                if (door->TryOpen(key) && !visited.count(door->GoThrough())) {
                    queue.insert(door->GoThrough());
                }
            }
        }
    }
    return nullptr;
}
