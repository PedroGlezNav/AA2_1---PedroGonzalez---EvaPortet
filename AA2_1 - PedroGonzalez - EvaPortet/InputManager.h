#pragma once
#include "Includes.h"

#include "ConsoleControl.h"

class InputManager {
private:
	std::vector<int>* inputRead = new std::vector<int>();
public:
	std::mutex* inputsReadMutex = new std::mutex();

	void startListening() {
		while (true) {
			int key = ConsoleControl::WaithForReadNextKey();

			inputsReadMutex->lock();
			switch (key) {
			case KB_SPACE:
			case KB_UP:
			case KB_LEFT:
			case KB_RIGHT:
			case KB_DOWN:
			{
				inputRead->push_back(key);
				break;
			}
			}
			inputsReadMutex->unlock();
		}
	}

	int lastInput() {
		inputsReadMutex->lock();
		int lastInput = 0;
		if (!inputRead->empty()) {
			lastInput = inputRead->back();
			inputRead->clear();
		}
		inputsReadMutex->unlock();

		return lastInput;
	}

	void passingTime() {

	}

	bool getKey(int keyCode) {
		inputsReadMutex->lock();
		bool isDetected = false;

		if (!inputRead->empty()) {
			for (int iter = 0; iter < inputRead->size(); iter++) {
				if ((*inputRead)[iter] == keyCode) {
					inputRead->erase(inputRead->begin() + iter);
					isDetected = true;
					iter--;
				}
			}
		}
		inputsReadMutex->unlock();
		return isDetected;
	}
};