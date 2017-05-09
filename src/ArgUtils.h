#ifndef ARGUTILS_H
#define ARGUTILS_H
#include <vector>
#include <string>

namespace ArgUtils {
std::vector<std::string>getArgs(int    argc,
                                char **argv);

bool                    helpRequested(int    argc,
                                      char **argv);
}
#endif // ifndef ARGUTILS_H
