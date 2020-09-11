#ifndef FILEREADING_H
#define FILEREADING_H

#include "Dictionary.h"

namespace FileReading {
// reads the file at path and returns a constructed dictionary object
// (where path is the full path including filename of the file)
Dictionary read(std::string path);
}  // namespace FileReading
#endif  // ifndef FILEREADING_H
