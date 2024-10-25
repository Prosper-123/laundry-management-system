#ifndef FIREBASE_H
#define FIREBASE_H

// Firebase configuration and initialization functions

void initializeFirebase();
bool loginUser(const std::string &email, const std::string &password);

#endif
