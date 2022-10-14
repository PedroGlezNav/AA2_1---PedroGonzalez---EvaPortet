#pragma once
#include "Includes.h"

#include "ConsoleControl.h"

class InputManager {
private:
	std::vector<int>* inputMovementRead = new std::vector<int>();
	std::vector<int>* inputActionsRead = new std::vector<int>();
public:
	std::mutex* inputsReadMutex = new std::mutex();

	void startListening() {
		while (true) {
			int key = ConsoleControl::WaithForReadNextKey();

			inputsReadMutex->lock();
			switch (key) {
			case KB_UP:
			case KB_LEFT:
			case KB_RIGHT:
			case KB_DOWN:
			{
				inputMovementRead->push_back(key);
				break;
			}
			case KB_SPACE:
			case KB_ESCAPE:
			{
				inputActionsRead->push_back(key);
				break;
			}
			}
			inputsReadMutex->unlock();
		}
	}

	int lastMovementInput() {
		inputsReadMutex->lock();
		int lastInput = 0;
		if (!inputMovementRead->empty()) {
			lastInput = inputMovementRead->back();
			inputMovementRead->clear();
		}
		inputsReadMutex->unlock();

		return lastInput;
	}

	int lastActionInput() {
		inputsReadMutex->lock();
		int lastInput = 0;
		if (!inputActionsRead->empty()) {
			lastInput = inputActionsRead->back();
			inputActionsRead->clear();
		}
		inputsReadMutex->unlock();

		return lastInput;
	}
};