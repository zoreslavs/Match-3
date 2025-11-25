# Match-3

Small Match-3 prototype implemented in C++ as part of a technical test for King (2020).

## Gameplay

- 8x8 grid of coloured gems
- Swap adjacent gems horizontally or vertically (drag or click)
- If a swap creates a line of 3+ same-colour gems, they are removed
- Columns collapse and new gems spawn from the top to refill the board
- 60-second session, score is based on the number of cleared gems

## Notes

This repository contains the core game logic and rendering code used for the test submission.
It was built using the minimal framework provided with the assignment (simple 2D rendering and input).
