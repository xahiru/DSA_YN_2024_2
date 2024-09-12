#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10 // Define the size of the maze

// Define types for position and stack elements
typedef struct {
    int x, y; // Position in the maze
} PosType;

typedef struct {
    PosType seat; // Current position in the maze
    int step;     // Current step number
    int di;       // Direction (1 = East, 2 = South, 3 = West, 4 = North)
} StackElement;

typedef struct {
    StackElement data[MAXSIZE * MAXSIZE]; // Stack to hold the path elements
    int top;
} Stack;

// Stack operations
void InitStack(Stack *S) {
    S->top = -1;
}

bool StackEmpty(Stack *S) {
    return S->top == -1;
}

void Push(Stack *S, StackElement e) {
    if (S->top < MAXSIZE * MAXSIZE - 1) {
        S->data[++S->top] = e;
    }
}

bool Pop(Stack *S, StackElement *e) {
    if (!StackEmpty(S)) {
        *e = S->data[S->top--];
        return true;
    }
    return false;
}

// Maze-specific functions
bool Pass(int maze[MAXSIZE][MAXSIZE], PosType pos) {
    // Check if the position is passable (0 = open path)
    if (pos.x >= 0 && pos.x < MAXSIZE && pos.y >= 0 && pos.y < MAXSIZE) {
        return maze[pos.y][pos.x] == 0;
    }
    return false;
}

void FootPrint(int maze[MAXSIZE][MAXSIZE], PosType pos) {
    // Mark the position as visited (e.g., 2 = visited)
    maze[pos.y][pos.x] = 2;
}

void MarkPrint(int maze[MAXSIZE][MAXSIZE], PosType pos) {
    // Mark the position as a dead end (e.g., 3 = dead end)
    maze[pos.y][pos.x] = 3;
}

PosType NextPos(PosType pos, int direction) {
    // Move to the next position based on the direction
    // 1 = East, 2 = South, 3 = West, 4 = North
    PosType next = pos;
    switch (direction) {
        case 1: next.x += 1; break; // East
        case 2: next.y += 1; break; // South
        case 3: next.x -= 1; break; // West
        case 4: next.y -= 1; break; // North
    }
    return next;
}

void PrintMaze(int maze[MAXSIZE][MAXSIZE]) {
    for (int i = 0; i < MAXSIZE; i++) {
        for (int j = 0; j < MAXSIZE; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// MazePath function
bool MazePath(int maze[MAXSIZE][MAXSIZE], PosType start, PosType end) {
    Stack S;
    InitStack(&S);
    PosType curpos = start;
    int curstep = 1;
    StackElement e;

    do {
        if (Pass(maze, curpos)) { // Current position is passable
            FootPrint(maze, curpos); // Mark current position as visited (2)
            e.seat = curpos;
            e.step = curstep;
            e.di = 1; // Start with direction East
            Push(&S, e); // Add to path
            PrintMaze(maze); // Print the maze after each move
            if (curpos.x == end.x && curpos.y == end.y) {
                printf("Path found!\n");
                return true; // Reached end
            }
            curpos = NextPos(curpos, 1); // Go to next position (East)
            curstep++;
        } else if (!StackEmpty(&S)) {
            Pop(&S, &e); // Backtrack
            while (e.di == 4 && !StackEmpty(&S)) {
                MarkPrint(maze, e.seat); // Mark as dead end (3)
                PrintMaze(maze); // Print the maze after marking a dead end
                Pop(&S, &e);
            }
            if (e.di < 4) { // Try next direction
                e.di++;
                Push(&S, e);
                curpos = NextPos(e.seat, e.di);
            }
        }
    } while (!StackEmpty(&S));

    printf("No path found.\n");
    return false; // No path found
}

int main() {
    // Define a 10x10 maze: 0 = open, 1 = wall
    int maze[MAXSIZE][MAXSIZE] = {
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0}
    };

    PosType start = {0, 0}; // Starting position (top-left corner)
    PosType end = {9, 9};   // Ending position (bottom-right corner)

    MazePath(maze, start, end); // Find and print the path

    return 0;
}
