*This project has been created as part of the 42 curriculum by danielad.*

# so_long

## Description
**so_long** is a functional 2D game engine developed using the **MiniLibX** graphics library. The project focuses on handling window management, keyboard events, and sprite rendering while enforcing strict memory management.

The player must navigate a character through a map, collect all treasures, and reach the exit. The engine includes a custom parser that validates map files for geometry, required components, and path accessibility.



## Features
- **Movement:** W, A, S, D or Arrow keys to move the player.
- **Move Counter:** Step count is tracked and printed to the terminal.
- **Map Validation:** - Validates `.ber` file extension.
  - Checks for rectangular shape and closed walls.
  - Verifies the presence of 1 Player, 1 Exit, and at least 1 Collectible.
- **Flood Fill:** A recursive algorithm checks if all collectibles and the exit are reachable.
- **Memory Safety:** Every heap allocation is tracked and freed, ensuring 0 leaks.

## Instructions

### Compilation
Build the executable using the provided Makefile:
```bash
make
```

### Execution
Run the code with one of the files in ./maps/
```bash
./so_long maps/filename.ber
```

### Valgrind check
Run 
```bash
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/filename.ber
```


## Resources
* **MiniLibX:** [42Docs - MiniLibX Library](https://harm-smits.github.io/42docs/libs/minilibx)
* **Pathfinding Guide:** [Youtube - Flood Fill ](https://www.youtube.com/watch?v=VuiXOc81UDM)
* **Minilibix:** [Introduction to the minilibX : a simple X-Window programming API in C](https://www.youtube.com/watch?v=bYS93r6U0zg)
* **Algorithm Basics:** [Wikipedia - Flood Fill](https://en.wikipedia.org/wiki/Flood_fill)
