# Lab 4. Functions and Arrays

## Objective

Learn to split a small game system into functions, keep values of the same kind in arrays, and pass arrays to functions. Check every function on its own, then build a program out of them in which `main` reads like a plan.

## What to submit

1. Two C++ programs, one for each task you chose. Each program is stored in its own file named after the task number: `task_2.cpp`, `task_7.cpp`.
2. Flowcharts for each task: `.drawio` files from [draw.io](https://app.diagrams.net) or photos of drawings on paper. Each file name starts with the task number: `flowchart_2_main.drawio`, `flowchart_2_buyItem.jpg`.
3. A Word report (`.docx`) based on the template [`report-template-en.docx`](./report-template-en.docx).

Submit all files together in one `.zip` archive.

## Choosing your tasks

The tasks in this lab are bigger than in Lab 3. Each one describes a small game system, and its program consists of several functions.

| Level                             | Tasks | How many to choose |
| --------------------------------- | :---: | :----------------: |
| Level 1. The functions are given  |  1-4  |         1          |
| Level 2. You design the functions |  5-8  |         1          |

At Level 1, the list of functions, their parameters, and what they do are already given, and one function is already written, but with mistakes. At Level 2, you decide yourself how to split the program into functions.

Tasks marked `[extra]` are optional and earn a higher grade.

## What you can use

You can use everything from Lab 3, and also:

- your own functions, including `void` functions, function declarations, and several `return` statements in one function (Lecture 7);
- `const` constants, including ones declared outside functions (Lecture 8);
- fixed-size arrays such as `int health[SQUAD_SIZE];` and `char level[LENGTH];`, including initial values in braces (Lecture 9).

You cannot use global variables that change, `std::string`, `std::vector`, `std::array`, references `&`, or pointers `*`. These topics come later or are not needed here.

You also cannot include `<algorithm>` or `<cmath>` or use ready-made functions such as `std::min`, `std::max`, `std::abs`, `std::sort`, or `std::find`.

## An array in a function

In Lecture we saw that `void heal(int health)` gets a copy of the number, so the variable in `main` does not change. Arrays behave differently. A function gets access to _the same_ array that was created in `main`, not to a copy of it:

```cpp
void damageAll(int health[], int size, int damage) {
    for (int i = 0; i < size; i++) {
        health[i] = health[i] - damage;
    }
}

int main() {
    int health[3] = {50, 30, 40};
    damageAll(health, 3, 10);
    std::cout << health[0] << '\n';    // 40, the array in main has changed
    return 0;
}
```

This gives two rules that apply to the whole lab:

- A function does not know the size of the array it receives. So the size is always passed as a separate parameter: `int health[], int size`.
- If a function changes the elements of an array, `main` sees the change. You do not need to return the array with `return`, and you cannot.

> [!IMPORTANT]
>
> Ordinary variables are still passed as copies. If a function has to change both an array and a number, for example the number of coins, it changes the array directly and returns the new number with `return`, and the calling code saves it: `coins = buyItem(..., coins);`.

## The main rule: plan first, code second

> [!IMPORTANT]
>
> For every task, first make the list of functions and draw the flowcharts, and only then write the program.
>
> - Every function from the decomposition table appears in the program with the same name, the same parameters, and the same result.
> - Every flowchart matches the code of its function: the same conditions, the same loops, the same order of actions.
> - A function cannot be added to `main` until it has been checked on its own.

Why this order? A program of eight functions no longer fits in your head at once. If you start straight from code, it is easy to write two functions that do the same thing, or one function that does too much. The function table shows the whole program on one page. And a function that has already been checked on its own is not a suspect when the whole program gives a wrong result.

## How to read a task

Every task has the same layout:

- **Situation** describes what happens in the game.
- **Data** lists the arrays and constants of the program.
- **Rules** list everything the program must take into account.
- **Functions** (Level 1 only) give the functions you have to write.
- **Example** shows the input and the output of the program. The input prompts are not shown, only the results.
- **Think about it** contains two questions. Your answers go into the report.

All input values are non-negative whole numbers unless a task says otherwise. The numbers of enemies, items, and cards that the player sees start at 1, while array indexes start at 0. Convert a number into an index in one place of the program.

## Procedure

Do Steps 1-6 for each of your two tasks.

### Step 1. Analyze the problem

1. List all arrays of the program: the name, the element type, the size, and what the element with index `i` means. For example: "`health`, `int`, 5 elements, `health[i]` is the health of enemy number `i + 1`; 0 means the enemy is dead".
2. List the other variables and constants with their types.
3. Write down what the program prints and when it ends.

### Step 2. Decomposition

1. Make a table of functions. For each function, give:
   - its C++ header, for example `int countAlive(int health[], int size)`;
   - what it does, in one phrase;
   - whether it changes an array;
   - where it is called from.
2. Draw a call tree: `main` at the top, the functions it calls below it, and the functions they call below them.

At Level 1 the functions are given: copy them into the table and describe them in your own words. If you need another helper function, add it.

At Level 2 you design the functions yourself. The requirements are:

- at least six functions besides `main`;
- at least two functions change an array passed to them;
- at least two functions calculate and return a value from an array: a count, a sum, the index of a found element, or a yes/no answer;
- no function except `main` is longer than 30 lines;
- `main` mostly consists of function calls and reads like the plan of the game.

> [!TIP]
>
> A good function does one thing and can be named with a verb: `countAlive`, `findWeakest`, `removeCard`. If the name gets long, with "and" in the middle (`moveAndShootAndPrint`), the function should be split.

### Step 3. Flowcharts

Draw flowcharts for `main` and for at least three other functions. Among them there must be at least one function that changes an array and at least one function that searches or counts elements in an array.

The rules are the same as in Lab 3, plus two more:

- The flowchart of a function starts with an oval containing its header, for example `countAlive(health, size)`, and ends with an oval `return alive`, or `End` for a `void` function.
- A function call in the flowchart of `main` is an ordinary rectangle: `alive = countAlive(health, 5)`. The inside of the called function is not drawn in the flowchart of `main`; it has its own flowchart.

### Step 4. Program

Write the program one function at a time:

1. Write the function from its flowchart.
2. Check it on its own right away: call it temporarily from `main` with a prepared array and print the result. For example:

   ```cpp
   int test[5] = {0, 15, 0, 0, 30};
   std::cout << countAlive(test, 5) << '\n';    // we expect 2
   ```

3. When the function works on all the cases from its checking table (Step 5), remove the temporary code and move on to the next function.
4. When all functions are checked, build `main`.

Format the code as in Lab 3. Write names of functions and variables in `camelCase` and constants in capital letters: `SQUAD_SIZE`. Always set the size of an array with a constant, not with a number repeated in several places. Before each input, print a short prompt, for example `std::cout << "Target: ";`.

### Step 5. Testing

1. **Checking functions.** For each function that returns a value or changes an array, make a table of at least three cases: normal, boundary, and special. For functions with arrays, the special cases are almost always these: the element you need is the first or the last one, there is no such element, all elements are equal.
2. **Checking the program.** Run the program on the example from the task and on two data sets of your own. Together, the data sets must reach every ending of the game described in the rules. Work out the expected result by hand _before running the program_.
3. **Trace.** For one function with a loop over an array, fill in a trace table: one row for each check of the loop condition, with columns `i`, `array[i]`, and the variables that change. Use an array of 4-6 elements.
4. **Call stack.** Put a breakpoint inside a function that is called not by `main` but by another function (for example, `damageEnemy` inside `damageAll`). Take a screenshot of the _Call Stack_ window that shows at least three levels of calls.
5. Take a screenshot of one run of the program.

If the results differ, find the function where the mistake happened, fix both its flowchart and its code, and check the function again. Briefly describe the mistake in the report. A mistake that you found and fixed does not lower your grade.

> [!WARNING]
>
> The compiler does not stop you from using an element outside the array, for example `health[5]` for an array of five elements. The program may print a random number, damage a neighboring variable, or crash, and it may do something different every time. If the program behaves strangely, check the loop boundaries first: `i < size`, not `i <= size`.

### Step 6. Answer the questions

Answer the two questions under "Think about it". If a question asks you to calculate something, show the calculation.

## Level 1. The functions are given

Use functions with exactly the headers from the table. You may add helper functions of your own.

In each task, one function is already written, but with mistakes. Copy it into your program, find the mistakes, fix them, and describe them in the mistakes section of the report: on which line, what was wrong, and how you found it.

### Task 1. Enemy squad

**Situation.** The player fights a squad of five enemies. The player has a sword, two fireballs, and eight turns.

**Data.**

- `const int SQUAD_SIZE = 5;`
- `int health[SQUAD_SIZE];` stores the health of the enemies. Enemy number 1 is stored in `health[0]`. Health 0 means the enemy is dead.

**Rules.**

- At the start, the health of each of the five enemies is entered. It is greater than 0.
- At the start of each turn, the program prints the turn number and the health of the squad. A dead enemy is printed as `x`.
- The player chooses an action by number:
  - `1` is a sword strike. The player enters the number of an enemy, and that enemy loses 20 health. If the number is not from 1 to 5 or the enemy is already dead, the program prints `Invalid target` and asks for the number again.
  - `2` is a fireball. Every living enemy loses 10 health. There are only two fireballs. When they run out, the program prints `No fireballs left`, and the turn is lost.
  - `3` is an auto strike: a sword strike at the weakest living enemy. If there are several, the one with the smaller number is chosen. The program prints `Auto strike at enemy` and the number of the enemy.
  - For any other number, the program prints `Unknown action`, and the turn is lost.
- An enemy's health cannot drop below 0.
- The game ends when all enemies are dead (`Victory in N turns`) or when 8 turns have passed (`Out of turns. Enemies left:` and the number of living enemies).

**Functions.**

| Header                                                  | What it does                                                                                     |
| ------------------------------------------------------- | ------------------------------------------------------------------------------------------------ |
| `void readSquad(int health[], int size)`                | Reads the health of all enemies.                                                                 |
| `void printSquad(int health[], int size)`               | Prints the health of the squad on one line, dead enemies as `x`.                                 |
| `int countAlive(int health[], int size)`                | Returns the number of living enemies.                                                            |
| `void damageEnemy(int health[], int index, int damage)` | Deals damage to one enemy; health does not drop below 0.                                         |
| `void damageAll(int health[], int size, int damage)`    | Deals damage to all living enemies by calling `damageEnemy`.                                     |
| `int findWeakest(int health[], int size)`               | Returns the index of the weakest living enemy, or `-1` if no enemy is alive.                     |
| `int readTarget(int health[], int size)`                | Asks for an enemy number until the number of a living enemy is entered, and returns its _index_. |

**The function with mistakes.** With this function the game never ends in victory: even when all enemies are printed as `x`, the program keeps playing turns, and at the end it reports more enemies left than there were in the squad. The function has two mistakes.

```cpp
int countAlive(int health[], int size) {
    int alive = 0;
    for (int i = 0; i <= size; i++) {
        if (health[i] >= 0) {
            alive++;
        }
    }
    return alive;
}
```

**Example.** Input: health `40 25 60 15 30`, then the actions `2`, `3`, `1` with the numbers `4` and `2`, `2`, `2`, `3`, `1` with the number `1`, `3`. Output:

```text
Turn 1: 40 25 60 15 30
Turn 2: 30 15 50 5 20
Auto strike at enemy 4
Turn 3: 30 15 50 x 20
Invalid target
Turn 4: 30 x 50 x 20
Turn 5: 20 x 40 x 10
No fireballs left
Turn 6: 20 x 40 x 10
Auto strike at enemy 5
Turn 7: 20 x 40 x x
Turn 8: x x 40 x x
Auto strike at enemy 3
Out of turns. Enemies left: 1
```

**Think about it.**

1. `readTarget` gets a number from 1 to 5 from the player and returns an index from 0 to 4. Why is it better to convert the number into an index in one function? What breaks if the number instead of the index is passed to `damageEnemy` by mistake for enemy 5?
2. `damageEnemy` returns nothing, but the enemy's health in `main` changes. Why did `heal(int health)` from Lecture 7 not change the variable in `main`, while `damageEnemy` changes the array?

**[extra]** Every enemy now has armor: an array `int armor[SQUAD_SIZE]` that is entered together with the health. A sword strike deals `20 - armor[i]` damage, but at least 1. A fireball ignores armor. Write a separate function for the sword damage and decide which functions from the table have to change.

### Task 2. Inventory

**Situation.** The character buys and sells items at a merchant. The bag holds at most 20 items.

**Data.**

- `const int ITEM_TYPES = 5;` and `const int BAG_CAPACITY = 20;`
- `int prices[ITEM_TYPES] = {15, 2, 25, 40, 100};` stores the item prices.
- `int counts[ITEM_TYPES] = {0, 0, 0, 0, 0};` stores how many items of each kind are in the bag.
- Item numbers: 1 is Potion, 2 is Arrow, 3 is Bomb, 4 is Key, 5 is Gem. Item number 1 is stored at index 0 in both arrays.

**Rules.**

- At the start, the number of coins the character has is entered.
- Then the program keeps reading commands: `1` buys, `2` sells, `3` shows the inventory, `0` exits. For any other command, it prints `Unknown command`.
- For buying and selling, an item number and a quantity (greater than 0) are entered. If the number is not from 1 to 5, the program prints `Unknown item`.
- A purchase costs `price * quantity`. If the bag would hold more than 20 items after the purchase, the program prints `Bag is full`. Otherwise, if there are not enough coins, it prints `Not enough coins`. Otherwise the items are added, the coins are paid, and it prints, for example, `Bought 3 Potion for 45 coins`.
- When selling, each item brings half its price, rounded down. If there are fewer items than the player wants to sell, the program prints `You don't have that many`. Otherwise it prints, for example, `Sold 6 Arrow for 6 coins`.
- Command `3` prints a line for each item in the bag (`Arrow x9`), then `Items:` and how full the bag is (`Items: 12/20`), then `Value:` and the selling value of the whole inventory. If the bag is empty, it prints `Inventory is empty`.
- After exiting, the program prints `Coins:` and the number of coins, and then `Most common item:` and the item the bag holds most of (if there is a tie, the one with the smaller number), or `Inventory is empty`.

**Functions.**

| Header                                                                                  | What it does                                                                        |
| --------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------- |
| `void printItemName(int index)`                                                         | Prints the name of the item with the given index using `switch`.                    |
| `int countItems(int counts[], int size)`                                                | Returns the total number of items in the bag.                                       |
| `int inventoryValue(int counts[], int prices[], int size)`                              | Returns the selling value of the whole inventory.                                   |
| `void printInventory(int counts[], int prices[], int size)`                             | Prints the inventory as described for command `3`.                                  |
| `int buyItem(int counts[], int prices[], int size, int index, int quantity, int coins)` | Buys the items if possible, prints a message, and returns the new number of coins.  |
| `int sellItem(int counts[], int prices[], int index, int quantity, int coins)`          | Sells the items if possible, prints a message, and returns the new number of coins. |
| `int findMostCommon(int counts[], int size)`                                            | Returns the index of the item the bag holds most of, or `-1` if the bag is empty.   |

**The function with mistakes.** This function does not compile. When you fix the compile error, it turns out that the inventory value is still calculated wrong. The function has two mistakes.

```cpp
int inventoryValue(int counts[], int prices[], int size) {
    for (int i = 1; i < size; i++) {
        int total = 0;
        total = total + prices[i] / 2 * counts[i];
    }
    return total;
}
```

**Example.** Input: coins `120`, then the commands: buy item `1`, quantity `3`; buy `2`, quantity `15`; buy `5`, quantity `1`; sell `2`, quantity `6`; command `3`; buy `2`, quantity `10`; buy `3`, quantity `1`; command `0`. Output:

```text
Bought 3 Potion for 45 coins
Bought 15 Arrow for 30 coins
Not enough coins
Sold 6 Arrow for 6 coins
Potion x3
Arrow x9
Items: 12/20
Value: 30
Bag is full
Bought 1 Bomb for 25 coins
Coins: 26
Most common item: Arrow
```

**Think about it.**

1. `buyItem` changes the number of items right in the `counts` array but returns the coins with `return`. Why can't the coins be changed the same way as the array? What does the program print for the example if `main` calls `buyItem(...);` without `coins =`?
2. The arrays `prices` and `counts` are linked: index 2 means a bomb in both. Where else in the program is this order of items used? What happens if you swap the first two prices in `prices`?

**[extra]** Add a sixth item, a Shield for 60 coins. List all the places in the program you had to change. Then add command `4`, which sells all arrows at once using `sellItem`.

### Task 3. High score table

**Situation.** After each game, the player's score can get into a table of the five best scores. At the end of the session, the program prints the table and statistics for all games.

**Data.**

- `const int TABLE_SIZE = 5;` and `const int MAX_GAMES = 20;`
- `int scores[TABLE_SIZE] = {0, 0, 0, 0, 0};` is the score table from best to worst. 0 means an empty place.
- `int games[MAX_GAMES];` stores the scores of all games played, in order. Only part of the array is filled: as many elements as there were games.

**Rules.**

- At the start, the number of games from 1 to 20 is entered. For any other number, the program prints `Enter from 1 to 20` and asks again.
- Then the score of each game is entered, one by one.
- A score gets into the table if it is greater than at least one score in it. It takes its place, all scores below it move one place down, and the last one drops out of the table. The program prints, for example, `Game 3: 600, new record! Place 1`.
- If the scores are equal, the new score goes _below_ the old one: the record reached earlier stays higher.
- If the score does not get into the table, the program prints, for example, `Game 8: 300, not in the table`.
- After all games, the program prints the table (`1. 900`, an empty place as `4. -`), then `Average:` and the average of all games rounded down, `Games above average:` and the number of games above the average, and `Longest growth:` and the longest series of consecutive games in which each game is better than the previous one. One game is a series of length 1.

**Functions.**

| Header                                                              | What it does                                                                           |
| ------------------------------------------------------------------- | -------------------------------------------------------------------------------------- |
| `int readGamesCount(int maxGames)`                                  | Asks for the number of games until it is from 1 to `maxGames`, and returns it.         |
| `int findPlace(int scores[], int size, int newScore)`               | Returns the index where the new score goes, or `-1` if it does not get into the table. |
| `void insertScore(int scores[], int size, int place, int newScore)` | Moves the scores down starting from `place` and writes the new score.                  |
| `void printTable(int scores[], int size)`                           | Prints the score table.                                                                |
| `int sumValues(int values[], int count)`                            | Returns the sum of the first `count` elements.                                         |
| `int countAbove(int values[], int count, int limit)`                | Returns how many of the first `count` elements are greater than `limit`.               |
| `int longestGrowth(int values[], int count)`                        | Returns the length of the longest growth series.                                       |

**The function with a mistake.** After the second score gets into the table, all places below the new record are filled with the same number. The function has one mistake.

```cpp
void insertScore(int scores[], int size, int place, int newScore) {
    for (int i = place; i < size - 1; i++) {
        scores[i + 1] = scores[i];
    }
    scores[place] = newScore;
}
```

**Example.** Input: `30`, then `8`, then the scores `400`, `250`, `600`, `650`, `100`, `600`, `900`, `300`. Output:

```text
Enter from 1 to 20
Game 1: 400, new record! Place 1
Game 2: 250, new record! Place 2
Game 3: 600, new record! Place 1
Game 4: 650, new record! Place 1
Game 5: 100, new record! Place 5
Game 6: 600, new record! Place 3
Game 7: 900, new record! Place 1
Game 8: 300, not in the table
1. 900
2. 650
3. 600
4. 600
5. 400
Average: 475
Games above average: 4
Longest growth: 3 games
```

**Think about it.**

1. Why does the correct shift in `insertScore` go from the end of the table towards the insertion place and not the other way round? Use a trace table to show what the function with the mistake does to the table `900 650 600 400 250` with the new score `620`.
2. The `games` array has room for 20 games, but 8 were played. What is stored in `games[8]`-`games[19]`? Why is the number of games passed to `sumValues` and not `MAX_GAMES`?

**[extra]** Remember in which game each record was set: a second array `int recordGame[TABLE_SIZE]` and the output `1. 900 (game 7)`. Change `insertScore` so that it moves both arrays in the same way.

### Task 4. Dungeon corridor

**Situation.** The character walks along a narrow dungeon corridor to the exit. On the way there are coins, traps, and hearts, and some cells are taken by a wall that can only be jumped over.

**Data.**

- `const int LENGTH = 15;`
- `char level[LENGTH] = {'#', '.', 'C', '.', 'T', '.', '#', 'C', '.', 'H', 'T', 'C', '#', 'C', 'E'};`
- Symbols: `.` is floor, `#` is wall, `C` is a coin, `T` is a trap, `H` is a heart, `E` is the exit.
- The character starts in the cell with index 1 with 100 health.

**Rules.**

- At the start, the program prints `Coins on level:` and the number of coins in the corridor.
- Each turn, the program prints the corridor on one line with `@` in place of the character, followed by the health and the coins: `#@C.T.#C.HTC#CE HP 100 Coins 0`.
- Commands are entered as characters: `a` is a step left, `d` is a step right, `j` is a jump two cells to the right (over one cell, even over a wall or a trap), `q` quits the game. For any other character, the program prints `Unknown command`.
- If the target cell is a wall or outside the corridor, the program prints `Blocked`, and the character stays in place.
- The character steps on a coin: the coins go up by one, and the cell becomes floor. On a trap: health goes down by 30, but not below 0, and the trap stays. On a heart: health goes up by 25, but not above 100, and the heart disappears.
- The game ends at the exit (`Exit reached! Coins: 4/4`), when health reaches 0 (`You died`), or with the command `q` (`Quit`).

**Functions.**

| Header                                                     | What it does                                                                  |
| ---------------------------------------------------------- | ----------------------------------------------------------------------------- |
| `void printLevel(char level[], int length, int playerPos)` | Prints the corridor with `@` in place of the character, without a line break. |
| `bool canMoveTo(char level[], int length, int pos)`        | Returns `true` if the cell is inside the corridor and is not a wall.          |
| `int countSymbol(char level[], int length, char symbol)`   | Returns how many times the symbol appears in the corridor.                    |
| `int findSymbol(char level[], int length, char symbol)`    | Returns the index of the first such symbol, or `-1`.                          |
| `int targetPosition(char command, int pos)`                | Returns the cell that the command `a`, `d`, or `j` leads to.                  |
| `int pickUpCoin(char level[], int pos)`                    | If the cell has a coin, removes it and returns 1; otherwise returns 0.        |
| `int applyCell(char level[], int pos, int health)`         | Applies a trap or a heart and returns the new health.                         |

Find the index of the exit once at the start of the program with `findSymbol`.

**The function with a mistake.** If the character jumps from the cell right before the exit, the character disappears from the screen and the game does not end. The function has one mistake.

```cpp
bool canMoveTo(char level[], int length, int pos) {
    if (pos < 0 && pos >= length) {
        return false;
    }
    return level[pos] != '#';
}
```

**Example.** Input: `d`, `d`, `d`, `d`, `d`, `j`, `d`, `d`, `d`, `d`, `s`, `d`, `j`, `d`. Output:

```text
Coins on level: 4
#@C.T.#C.HTC#CE HP 100 Coins 0
#.@.T.#C.HTC#CE HP 100 Coins 1
#..@T.#C.HTC#CE HP 100 Coins 1
#...@.#C.HTC#CE HP 70 Coins 1
#...T@#C.HTC#CE HP 70 Coins 1
Blocked
#...T@#C.HTC#CE HP 70 Coins 1
#...T.#@.HTC#CE HP 70 Coins 2
#...T.#.@HTC#CE HP 70 Coins 2
#...T.#..@TC#CE HP 95 Coins 2
#...T.#...@C#CE HP 65 Coins 2
#...T.#...T@#CE HP 65 Coins 3
Unknown command
#...T.#...T@#CE HP 65 Coins 3
Blocked
#...T.#...T@#CE HP 65 Coins 3
#...T.#...T.#@E HP 65 Coins 4
Exit reached! Coins: 4/4
```

**Think about it.**

1. A coin and a trap are handled by two different functions, `pickUpCoin` and `applyCell`. Why can't you write one function that both adds a coin and changes the health? What is missing for that?
2. Why must `canMoveTo` check the boundaries _before_ reading `level[pos]`? What happens with `pos = 15` if there is no check?

**[extra]** Add a key `K` and a door `D` to the corridor. The door behaves like a wall while the character has no key. When a character with a key walks into the door, the door turns into floor. Decide which functions have to change and whether you need new ones.

## Level 2. You design the functions

The tasks at this level have no function table. The requirements for the decomposition are described in Step 2. The hint in each task points to the place where students most often make mistakes.

### Task 5. Squad against squad

**Situation.** Three heroes fight four enemies. The player chooses the heroes' tactic, and then the battle runs by itself, round after round.

**Data.**

```cpp
const int HEROES = 3;
const int ENEMIES = 4;

int heroHealth[HEROES] = {40, 60, 30};
int heroAttack[HEROES] = {12, 8, 15};
int enemyHealth[ENEMIES] = {35, 50, 20, 70};
int enemyAttack[ENEMIES] = {10, 14, 8, 16};
```

The hero with index `i` is described by two elements: `heroHealth[i]` and `heroAttack[i]`. The same goes for the enemies.

**Rules.**

- At the start, the tactic is entered: `1` means all heroes hit the first living enemy, `2` means each hero hits the weakest living enemy. For any other number, the program prints `Choose 1 or 2` and asks again.
- In each round, the living heroes attack one by one first, and then the living enemies attack one by one. The target is chosen again before _every_ attack.
- An enemy always hits the living hero with the most health. If there is a tie, the one with the smaller index is chosen. The same tie rule applies to tactic `2`.
- An attack lowers the target's health by the attack value. Health cannot drop below 0.
- If all enemies die in the middle of a round, the remaining heroes and enemies do nothing in that round.
- After each round, the program prints the health of both squads, the dead as `x`.
- The battle lasts at most 15 rounds. At the end, the program prints `Heroes win in N rounds`, `Enemies win in N rounds`, or `Draw`, and then `Heroes alive:` and the number of living heroes.

**Example.** Input: `3`, then `2`. Output:

```text
Choose 1 or 2
Round 1: heroes 24 36 30 | enemies 20 50 x 70
Round 2: heroes 24 22 14 | enemies x 35 x 70
Round 3: heroes 8 22 14 | enemies x x x 70
Round 4: heroes 8 6 14 | enemies x x x 35
Round 5: heroes 8 6 14 | enemies x x x x
Heroes win in 5 rounds
Heroes alive: 3
```

**Hint.** The functions that look for a target return an index, or `-1` if there is no one to find. Check the result of the search before attacking: if the enemies have run out, `enemyHealth[-1]` is outside the array.

**Think about it.**

1. Run the program with tactic `1`. Who wins, and in which round? Explain from a game design point of view why tactic `2` is stronger here.
2. Why is the target chosen again before every attack and not once at the start of the round? Use round 1 of the example to show what changes if the heroes choose their target once.

**[extra]** The third hero becomes a healer: instead of attacking, they heal the living hero with the least health by 10, but not above that hero's starting health. You need one more array for this. Compare the result of the battle with the example.

### Task 6. Tower defense

**Situation.** Enemies walk along a road of 10 cells towards the base. The player places three towers along the road, and the towers shoot at the enemies every turn.

**Data.**

```cpp
const int LANE = 10;
const int WAVE_LENGTH = 10;
const int TOWERS = 3;

int wave[WAVE_LENGTH] = {30, 30, 30, 0, 50, 50, 0, 70, 0, 30};
int lane[LANE];      // lane[i] is the health of the enemy in cell i, 0 means the cell is empty
int towers[TOWERS];  // the cells where the towers stand
```

`wave[t]` is the health of the enemy that enters the road on turn `t + 1`. 0 means that no one enters on that turn.

**Rules.**

- At the start, the cells of the three towers are entered, from 0 to 9. If a cell is outside the road or already has a tower, the program prints `Invalid cell` and asks again. Then it prints the road with the towers: `Towers: . . T . . T . . T .`.
- At the start of the game, the road is empty, and the base has 3 lives.
- Each turn goes in this order:
  1. If there is an enemy in the last cell (9), it reaches the base: the base loses one life, and the program prints `Enemy reached the base!`.
  2. All enemies move one cell forward, towards the base.
  3. While the wave is not over, the next enemy from `wave` enters cell 0.
  4. The towers shoot one by one, in the order they were entered. A tower in cell `p` sees the cells `p - 1`, `p`, and `p + 1` and shoots once at the enemy _closest to the base_, that is, the one with the largest index. A shot takes 10 health. An enemy with 0 health dies.
  5. The program prints the road and the lives: `Turn 2: 30 20 . . . . . . . . | lives 3`.
- The game goes on while the base has lives and while the wave is not over or there are enemies on the road. At the end, the program prints `Wave defeated! Lives left:` and the number of lives, or `Base destroyed on turn` and the turn number, and then `Kills:` and the number of enemies killed.

**Example.** Input: `2`, `12`, `5`, `8`. Output:

```text
Invalid cell
Towers: . . T . . T . . T .
Turn 1: 30 . . . . . . . . . | lives 3
Turn 2: 30 20 . . . . . . . . | lives 3
Turn 3: 30 30 10 . . . . . . . | lives 3
Turn 4: . 30 30 . . . . . . . | lives 3
Turn 5: 50 . 30 20 . . . . . . | lives 3
Turn 6: 50 50 . 20 10 . . . . . | lives 3
Turn 7: . 50 40 . 20 . . . . . | lives 3
Turn 8: 70 . 50 30 . 10 . . . . | lives 3
Turn 9: . 70 . 40 30 . . . . . | lives 3
Turn 10: 30 . 60 . 40 20 . . . . | lives 3
Turn 11: . 30 . 50 . 40 10 . . . | lives 3
Turn 12: . . 20 . 50 . 30 . . . | lives 3
Turn 13: . . . 10 . 40 . 20 . . | lives 3
Turn 14: . . . . 10 . 30 . 10 . | lives 3
Turn 15: . . . . . . . 30 . . | lives 3
Turn 16: . . . . . . . . 20 . | lives 3
Turn 17: . . . . . . . . . 10 | lives 3
Enemy reached the base!
Turn 18: . . . . . . . . . . | lives 2
Wave defeated! Lives left: 2
Kills: 6
```

**Hint.** Moving the enemies forward means changing the `lane` array in place. Think about which end of the array to start from so that the enemies do not "multiply".

**Think about it.**

1. Place the towers in cells `3`, `4`, and `5`. How many lives does the base have left? Why do three towers next to each other work better here than three towers at equal distances?
2. What happens if the enemies are moved starting from the beginning of the array towards the end? Show on the road `30 30 . . . . . . . .` what it looks like after one move.

**[extra]** Add a second type of tower, the cannon: it deals 25 damage, but it sees only its own cell. The type of each tower is entered together with its cell and stored in a second array. Find a placement in which the base loses no lives.

### Task 7. Cards against the boss

**Situation.** The player fights a boss in a card game. Each card costs as much mana as the number written on it and deals three times as much damage.

**Data.**

```cpp
const int DECK_SIZE = 10;
const int HAND_SIZE = 5;

int deck[DECK_SIZE] = {3, 1, 4, 2, 5, 1, 3, 2, 4, 2};  // the deck, cards are drawn in order
int hand[HAND_SIZE];                                   // the cards in the hand
```

The hand can hold from 0 to 5 cards. How many cards are in the hand right now is stored in a separate variable. Which card of the deck comes next is stored in a separate variable too.

**Rules.**

- The boss has 60 health. At the start, the player draws 3 cards from the deck.
- The game lasts at most 6 turns. On turn number `t`, the player has `t` mana, but no more than 5. Mana that is not spent during the turn is lost.
- At the start of a turn, the player draws one card. If the deck is empty, the program prints `Deck is empty`. If the hand already holds 5 cards, the card burns, and the program prints, for example, `Hand full, card 4 burned`.
- Then the program prints `Turn 1, mana 1, boss 60`.
- While the hand has a card that can be paid for with the remaining mana, the program prints the hand (`Hand: 3 1 4 2`) and asks for the position of a card in the hand, starting from 1. Entering `0` ends the turn early.
  - A position outside the hand: `No such card`.
  - A card that costs more than the remaining mana: `Not enough mana`.
  - Otherwise the card is played: the mana goes down by the card's cost, the boss loses `cost * 3` health, but not below 0, the card is removed from the hand, and the cards to its right move left. The program prints, for example, `Played 3, boss 48`.
- The game ends with `Boss defeated on turn N` or, if the turns run out, `Boss survived with N health`.

**Example.** Input: `2`, `3`, `1`, `7`, `1`, `1`, `2`, `2`. Output:

```text
Turn 1, mana 1, boss 60
Hand: 3 1 4 2
Played 1, boss 57
Turn 2, mana 2, boss 57
Hand: 3 4 2 5
Played 2, boss 51
Turn 3, mana 3, boss 51
Hand: 3 4 5 1
Played 3, boss 42
Turn 4, mana 4, boss 42
Hand: 4 5 1 3
No such card
Hand: 4 5 1 3
Played 4, boss 30
Turn 5, mana 5, boss 30
Hand: 5 1 3 2
Played 5, boss 15
Turn 6, mana 5, boss 15
Hand: 1 3 2 4
Played 3, boss 6
Hand: 1 2 4
Played 2, boss 0
Boss defeated on turn 6
```

**Hint.** The functions that add or remove a card change the `hand` array, but the number of cards in the hand is an ordinary variable. Such a function has to return the new number of cards, and `main` has to save it.

**Think about it.**

1. A played card is removed by moving the other cards left. Why can't you simply write 0 in its place? What would the functions that print the hand and look for a playable card have to take into account then?
2. For the first three turns, the player enters only `0`. Which cards are in the hand when the program first asks for a card on turn 4? Which cards have burned by then? Check your answer by running the program.

**[extra]** Add a combo: each next card played in the same turn deals 2 more damage than the previous one. Find an input with which the boss dies already on turn 5.

### Task 8. Farm

**Situation.** The player has six garden plots and seven days. They plant seeds, water the sprouts, and harvest the crops to earn as many coins as possible by the end of the week.

**Data.**

```cpp
const int PLOTS = 6;
const int DAYS = 7;

int stage[PLOTS] = {0, 0, 0, 0, 0, 0};  // 0 empty, 1 seed, 2 sprout, 3 crop
int water[PLOTS] = {0, 0, 0, 0, 0, 0};  // for how many nights the water lasts
```

**Rules.**

- At the start, the player has 15 coins.
- At the start of each day, the program prints the day number, the plots, and the coins: `Day 2: g g g . . . | coins 0`. An empty plot is printed as `.`, a seed as `s`, a sprout as `g`, and a crop as `R`.
- Each day the player chooses one action:
  - `1` plants seeds in all empty plots from left to right while there are enough coins. A seed costs 5 coins. The soil is wet after planting: the water lasts for one night. The program prints, for example, `Planted 3 seeds`.
  - `2` waters all plots with seeds and sprouts: the water lasts for two nights. The program prints, for example, `Watered 3 plots`.
  - `3` harvests all crops. Each plot with a crop brings 20 coins and becomes empty. The program prints, for example, `Harvested 3 plots`.
  - `0` does nothing. For any other number, the program prints `Unknown action`.
- At night, each plot with a seed or a sprout is checked in turn. If it has water, the plant grows by one stage, and the water lasts one night less. If it has no water, the plant withers, the plot becomes empty, and the program prints, for example, `Plot 2 withered`. A crop does not change at night.
- After the seventh day, the program prints `Final coins:` and the coins, and then `Ripe plots left:` and the number of plots with crops that were not harvested.

**Example.** Input: `1`, `2`, `1`, `3`, `1`, `2`, `3`. Output:

```text
Day 1: . . . . . . | coins 15
Planted 3 seeds
Day 2: g g g . . . | coins 0
Watered 3 plots
Day 3: R R R . . . | coins 0
Planted 0 seeds
Day 4: R R R . . . | coins 0
Harvested 3 plots
Day 5: . . . . . . | coins 60
Planted 6 seeds
Day 6: g g g g g g | coins 30
Watered 6 plots
Day 7: R R R R R R | coins 30
Harvested 6 plots
Final coins: 150
Ripe plots left: 0
```

**Hint.** The night check changes two arrays at once. It is convenient to make it one function that gets both arrays and goes through them in one loop.

**Think about it.**

1. In the example, the player waters the plots on day 6. What does the program print for night 6 and day 7 if the player enters `0` instead? What is the final result?
2. Why is the amount of water stored separately for each plot and not in one variable for the whole farm? Give an example of a day when different plots have different amounts of water.

**[extra]** A crop that has not been harvested for two nights in a row rots: the plot becomes empty, and the program prints `Plot N rotted`. For this you need one more array or a new value in one of the existing ones. Explain what you chose and why.

## Report

Write the report in Microsoft Word using the template [`report-template-en.docx`](./report-template-en.docx). Fill in the title page. Text in square brackets in the template is a hint: replace it with your own text and delete the hints.

For each of your two tasks, the report contains, in this order:

1. The task number, its title, and its text.
2. The problem analysis: a table of arrays and a table of the other variables and constants.
3. The decomposition: the table of functions and the call tree.
4. The flowcharts of `main` and at least three functions.
5. The program code. Paste it as text, not as an image.
6. Testing: the function checking tables, a testing table for the program on three data sets, a trace table for one function, a screenshot of the _Call Stack_ window, and a screenshot of one run.
7. A description of the mistakes you found and fixed. For the Level 1 task, this includes the analysis of the function with mistakes.
8. Answers to the "Think about it" questions.

The conclusions go at the end of the report.

## Grading criteria

- The function table and the call tree match the program: the same names, parameters, and results.
- The flowcharts were drawn before the code and match it.
- The programs compile and give the correct result for all data sets.
- Each function does one thing, `main` reads like a plan, and the requirements of Step 2 are met.
- Array sizes are set with constants, and loops do not go outside the arrays.
- The minimum, the maximum, searching, counting, and shifting elements are written by hand, without ready-made functions from the standard library.
- The function checking tables include boundary and special cases.
- In the Level 1 task, all mistakes in the given function are found and explained.
- The answers to the "Think about it" questions are correct.

## Review questions

1. What is decomposition? Use the call tree of your program to show how a big task is split into small ones.
2. Why does a function that changes an `int` parameter not change the variable in `main`, while a function that changes an element of an array changes the array in `main`?
3. Why is the size of an array passed to a function together with the array? What happens if you pass a size larger than the real one?
4. How is the index of an element different from its value? How is the number of an enemy that the player sees different from its index in the array?
5. Why does a search function return the index and not the value of the element it found? What does it return if it finds nothing, and why can't that value be a real index?
6. How do you check a function separately from the rest of the program? Why is it faster than looking for a mistake in the whole program at once?
7. What does the _Call Stack_ window show? How can you tell from it which function called the current one?
