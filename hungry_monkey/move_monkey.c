#include <stdlib.h> 
#include <stdio.h>  
#include "hungry_monkey.h" 

// struct to hold monkey current position and target column
struct monkeyInfo {
    int position;  
    int target;
};

struct monkey_action move_monkey(int field[][FIELD_WIDTH], void *monkey_state) {
    struct monkeyInfo *state;  
    int move = MOVE_FWD;      

    // If this is the first call initialize monkey's state
    if (monkey_state == NULL) {
        state = malloc(sizeof(struct monkeyInfo));
        state->position = FIELD_WIDTH / 2;
        state->target = -1;
    } 
    else {
        state = (struct monkeyInfo *)monkey_state;
    }

    int current_pos = state->position;
    int target_col = -1;
    int min_distance = FIELD_WIDTH;

    // for every row
    for (int rows = 1; rows <= FIELD_HEIGHT - 2; rows++) {
        int current_row = FIELD_HEIGHT - 1 - rows; 

        // for every column
        for (int column = 0; column < FIELD_WIDTH; column++) {
            // if column has a treat in it
            if (field[current_row][column] == TREAT_VAL) {
                // calculate distance of treat from monkey
                int distance = abs(column - current_pos);

                // if distance from treat is equal to the height of the row we are checking, go for it
                if (distance == rows) {
                    if (distance < min_distance) {
                        min_distance = distance;
                        target_col = column;
                        break;
                    }
                }
            }
        }

        // If a target was found break
        if (target_col != -1) break;
    }

    // Update the state with the new target column
    state->target = target_col;

    // find movement direction
    if (target_col != -1) {
        if (current_pos < target_col) {
            move = MOVE_RIGHT;
            state->position++;
        } else if (current_pos > target_col) {
            move = MOVE_LEFT;
            state->position--;
        }
    }

    // Create the action structure to return
    struct monkey_action action;
    action.move = move;
    action.state = state;

    return action;
}
