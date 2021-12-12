#pragma once
#ifndef SPEAK_H  // change depending on your class
#define SPEAK_H  // change depending on your class

#include <TaskManager.h>

class Speak : public Task::Base {
    int num {0};

public:
    Speak(const String& name)
    : Base(name) {
        Serial.begin(115200);
    }

    virtual ~Speak() {}

    // You can set paramters like builder pattern
    Speak* number(const int n) {
        num = n;
        return this;
    }

    // optional (you can remove this method)
    virtual void begin() override {
        Serial.print("Task ");
        Serial.print(num);
        Serial.println(" begin()");
    }

    // optional (you can remove this method)
    virtual void enter() override {
        Serial.print("Task ");
        Serial.print(num);
        Serial.println(" enter()");
    }

    virtual void update() override {
        Serial.print("Task ");
        Serial.print(num);
        Serial.print(" update() at frame = ");
        Serial.print(frame());
        Serial.print(", time = ");
        Serial.println(millis());
    }
};

#endif  // SPEAK_H
