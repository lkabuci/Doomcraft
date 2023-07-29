//
// Created by redone on 7/29/23.
//

#include "cray.h"

/*
 *
 * 1 -> only 6 possible characters (0, 1, N, S, E, W) and \0
 * 2 -> only one player position
 * 3 -> surrounded by walls (1)
 * 4 -> each space should be surrounded by walls (1) or spaces
 *
 */

bool is_map_valid(char **pString) {
    int i;
    int j;
    bool isPlayerFound;

    isPlayerFound = false;
    i = -1;
    while (pString[++i]) {
        j = -1;
        while (pString[i][++j]) {
            if (ft_strchr("01NEWS ", pString[i][j]) == NULL)
                return (false);
            if (ft_strchr("NEWS", pString[i][j]) != NULL) {
                if (isPlayerFound == true)
                    return (false);
                isPlayerFound = true;
            }
        }
    }
    return true;
}
