//
// Created by laura on 7/05/25.
//

#include "SequenceFinder.h"

void SequenceFinder::start() {
    isRunning = true;
    thread = std::jthread([this](){alive();});
}

void SequenceFinder::stop() {
    isRunning = false;
}

void SequenceFinder::setNextModule(IModule *next) {
    nextModule = next;
}

void SequenceFinder::receivedData(const std::vector<uint8_t> &data) {
std::vector<uint8_t> buffer;

}

void SequenceFinder::alive() {
    while (isRunning) {

    }
}
