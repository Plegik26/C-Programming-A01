# Hungry Monkey – Final Project

This repository contains my submission for the **Hungry Monkey** final project.  
The project implements a simple game where a monkey tries to catch as many falling treats as possible, controlled by a **greedy movement algorithm**.

---

## Overview
- The game is represented as a **matrix**.  
- Treats are randomly generated on the **top row**.  
- The monkey moves on the **bottom row**, one step at a time (`left`, `right`, or `stay`).  
- Each step:
  - The matrix shifts down.
  - A new row is generated.
  - If a treat falls on the monkey’s position then the score increases.  
- The simulation runs for a fixed number of steps (e.g., 100).

---

## How to run

Console (printf version)

`gcc hungry_monkey_printf.c move_monkey.c -o hungry_monkey`

`./hungry_monkey`


No GUI – Performance Test
Runs for 100 iterations and outputs the average score:

`gcc hungry_monkey_nogui.c move_monkey.c -o hungry_monkey`

`./hungry_monkey`
