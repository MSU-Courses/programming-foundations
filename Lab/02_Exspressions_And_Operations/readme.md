# Lab 2. Expressions and Operations

## Objective

Learn to write calculations as C++ expressions, choose the right types for variables, take into account the order of operations and how integer division works, and check a program on several sets of data.

## Note

Tasks marked `[extra]` are optional and count toward a higher grade.

## What to submit

1. Five C++ programs, one for each task you chose. Each program is stored in its own file: `task_1.cpp`, `task_8.cpp`, and so on, named after the task number.
2. A Word report (`.docx`) based on the template [`report-template-en.docx`](./report-template-en.docx).

Submit the `.cpp` files and the report together in one `.zip` archive.

## Choosing your tasks

The tasks are split into three levels. You need to complete 5 tasks in total:

| Level                                       | Tasks | How many to choose |
| ------------------------------------------- | :---: | :----------------: |
| Level 1. Calculations                       |  1-7  |     at least 1     |
| Level 2. Division, remainder, and types     | 8-14  |     at least 2     |
| Level 3. Comparisons and logical operations | 15-20 |     at least 1     |

The fifth task can come from any level.

## What you can use

In this lab the program runs strictly from top to bottom, with no choices and no repetition. You can use only what was covered in Lectures 3 and 4:

- variables and constants (`const`);
- the types `int`, `double`, `char`, and `bool`;
- input with `std::cin` and output with `std::cout`;
- the arithmetic operations `+`, `-`, `*`, `/`, `%`, and parentheses;
- assignment, compound assignment (`+=`, `-=`, and the others), increment `++`, and decrement `--`;
- the comparison operations `>`, `<`, `>=`, `<=`, `==`, `!=`;
- the logical operations `&&`, `||`, `!`.

You cannot use `if`, `else`, `switch`, the `?:` operation, loops, or ready-made functions such as `std::max`. Conditions and loops come in the next lab.

> [!NOTE]
> In some tasks the program gives a result that makes no sense in the game for certain data, such as negative health. You do not need to fix this, because it is impossible without conditions. These cases are discussed in the "Think about it" questions.

## How to read a task

Every task has the same layout:

- **Situation** describes what happens in the game.
- **Formula** shows a ready-made calculation. You do not need to derive it.
- **Output** lists what the program prints and in which order.
- **Example** shows the correct result for one set of data. The input values come first, followed by the program's output.
- **Think about it** contains two questions. Your answers go into the report.

`std::cout` prints a logical value as a number: `1` means true and `0` means false. Logical values are entered the same way: `1` means "yes" and `0` means "no".

All values are non-negative whole numbers unless a task says otherwise.

## Procedure

Do Steps 1-4 for each of your five tasks.

### Step 1. Analyze the problem

1. Find the inputs and give them names.
2. Choose a type for each variable: `int`, `double`, `char`, or `bool`. Explain your choice in one phrase.
3. If a task has values that do not change while the program runs, make them constants.

Write variable names in `camelCase` (`enemyHealth`) and constant names in `UPPER_SNAKE_CASE` (`MAX_HEALTH`), as agreed in Lecture 3.

### Step 2. The program

Write the program in C++. Use this skeleton:

```cpp
#include <iostream>

int main() {
    // 1. Declare variables and constants.

    // 2. Read the input.

    // 3. Calculate the result.

    // 4. Print the result.

    return 0;
}
```

Before each input, print a short prompt, for example `std::cout << "Attack: ";`. Write prompts and output labels in English: the Windows console often displays non-Latin letters incorrectly.

> [!TIP]
> Each line of the program should do one thing. It is better to split a long expression into several steps with intermediate variables: this makes it easier to check and to find mistakes.

### Step 3. Testing

1. Prepare three sets of input data:
   - the example from the task;
   - a _boundary case_, for example exactly on the edge of a comparison or an exact multiple for division;
   - a _special case_, for example with a zero value.
2. For each data set, work out the expected result by hand _before running the program_.
3. Run the program and compare the actual result with the expected one.
4. Take a screenshot of one of the runs.

If the results differ, find the expression where the mistake happened, fix it, and test again. Briefly describe the mistake in the report. A mistake that you found and fixed does not lower your grade.

> [!WARNING]
> Do not choose a special case that makes the program divide by zero. The program will crash. If division by zero is possible in a task, state in the report which data cause it.

### Step 4. Answer the questions

Answer the two questions under "Think about it". If a question asks you to calculate something, show the calculation, not only the answer.

## Level 1. Calculations

### Task 1. Hitting an enemy

**Situation.** The character hits an enemy. The enemy's defense absorbs part of the attack.

**Formula.**

```text
damage = attack - defense
enemy health = enemy health - damage
```

Write the second calculation with compound assignment.

**Output.** The damage, then the enemy's health.

**Example.** Input: attack `25`, defense `8`, enemy health `100`. Output: `17`, `83`.

**Think about it.**

1. Attack `5`, defense `10`, health `100`. What will the program print? What happened to the enemy in game terms?
2. Find the expression in the statement `enemyHealth -= damage;`. What changes in the program if you delete this statement?

### Task 2. Buying potions

**Situation.** The character buys several identical potions from a merchant.

**Formula.**

```text
purchase cost = price of one potion * quantity
coins = coins - purchase cost
```

**Output.** The purchase cost, then the coins left.

**Example.** Input: coins `200`, potion price `35`, quantity `4`. Output: `140`, `60`.

**Think about it.**

1. Coins `100`, price `30`, quantity `4`. What will the program print? What went wrong in game terms?
2. Both calculations can be written in one line: `coins = coins - potionPrice * count;`. Are parentheses needed here? Why?

### Task 3. Level score

**Situation.** After a level, the game counts the score. Each defeated enemy gives 10 points, each coin gives 5 points, and each hidden stash found gives 50 points.

**Formula.**

```text
score = enemies * 10 + coins * 5 + stashes * 50
```

Make the numbers 10, 5, and 50 constants.

**Output.** The score.

**Example.** Input: enemies `12`, coins `30`, stashes `2`. Output: `370`.

**Think about it.**

1. In which order are the operations in this formula carried out? Write down the intermediate results for the example.
2. A student wrote `(enemies * 10 + coins) * 5 + stashes * 50`. What score does this give for the example? What is the mistake?

### Task 4. Fix the code: average damage

**Situation.** The character made three hits. The game shows the average damage per hit. A programmer wrote the code, but it calculates incorrectly:

```cpp
#include <iostream>

int main() {
    int hit1 = 0;
    int hit2 = 0;
    int hit3 = 0;

    std::cout << "Hit 1: ";
    std::cin >> hit1;
    std::cout << "Hit 2: ";
    std::cin >> hit2;
    std::cout << "Hit 3: ";
    std::cin >> hit3;

    double average = hit1 + hit2 + hit3 / 3;

    std::cout << "Average damage: " << average << '\n';

    return 0;
}
```

This line contains two different mistakes. Find and fix both.

**Formula.**

```text
average damage = (hit 1 + hit 2 + hit 3) / 3
```

**Output.** The average damage.

**Example.** Input: `10`, `15`, `16`. Output: `13.6667`.

**Think about it.**

1. What does the original program print for the input `10`, `15`, `20`? Explain where this number comes from.
2. Another student fixed only the parentheses: `(hit1 + hit2 + hit3) / 3`. For the input `10`, `15`, `20`, the program prints the correct answer `15`. Why is this test not enough? What does the program print for `10`, `15`, `16`?

### Task 5. Resting by the campfire

**Situation.** The character rests by a campfire. Every second, some health and mana are restored.

**Formula.**

```text
health = health + health regeneration per second * seconds
mana = mana + mana regeneration per second * seconds
```

Write both calculations with compound assignment.

**Output.** Health, then mana.

**Example.** Input: health `40`, health regeneration `3`, mana `10`, mana regeneration `2`, seconds `10`. Output: `70`, `30`.

**Think about it.**

1. The character's maximum health is `100`. Health `90`, regeneration `5` per second, resting for `4` seconds. What will the program print? Which game rule is broken here?
2. How do `health += healthRegen * seconds;` and `health = health + healthRegen * seconds;` differ?

### Task 6. Character movement

**Situation.** The character moves across the map. Its position is given by two coordinates: `x` horizontally and `y` vertically. The speed along each axis is given in map units per second. In this task, coordinates, speeds, and time can be fractional, and speeds can be negative.

**Formula.**

```text
x = x + speed along x * time
y = y + speed along y * time
```

**Output.** The new `x` coordinate, then the new `y` coordinate.

**Example.** Input: `x` = `2.5`, `y` = `4`, speed along `x` = `1.5`, speed along `y` = `-0.5`, time `3`. Output: `7`, `2.5`.

**Think about it.**

1. Why are coordinates and speeds of type `double` and not `int`? Name the values from the example that cannot be stored in an `int` without loss.
2. In which direction does the character move if the speed along `x` is negative?

### Task 7. Hit combo

**Situation.** The character makes three hits in a row. Before each hit, the combo counter goes up by 1. The damage of each hit depends on the current value of the counter.

**Formula.** For each of the three hits in turn:

```text
combo counter = combo counter + 1
hit damage = base damage + combo counter * 5
total damage = total damage + hit damage
```

Write the counter increase with the increment `++`. Total damage starts at 0.

**Output.** The damage of each of the three hits, the total damage, and the final value of the counter.

**Example.** Input: base damage `10`, combo counter `0`. Output: `15`, `20`, `25`, `60`, `3`.

**Think about it.**

1. The program has three almost identical blocks. What would you have to do if there were 100 hits?
2. A student decided to shorten the code to `int hit1 = baseDamage + combo++ * 5;`. What damage does the first hit get for the example? Why is it different from the correct one?

## Level 2. Division, remainder, and types

### Task 8. Completion time

**Situation.** The game stores the time it took to complete a level in seconds, but it has to show it as `hours:minutes:seconds`, for example `1:02:05`.

**Formula.** An hour has 3600 seconds, and a minute has 60 seconds.

```text
hours = total seconds / 3600
minutes = (total seconds % 3600) / 60
seconds = total seconds % 60
```

Minutes and seconds are always printed with two digits. To do this, print the tens and the ones separately: for minutes, these are `minutes / 10` and `minutes % 10`.

**Output.** The time in the format `H:MM:SS`.

**Example.** Input: `3725`. Output: `1:02:05`.

**Think about it.**

1. Check the formula for minutes on the example: what is `3725 % 3600`? And `125 / 60`?
2. How will the program print the time if you print minutes and seconds simply as numbers, without splitting them into tens and ones? Why is this inconvenient for the player?

### Task 9. Splitting the loot

**Situation.** A party of players found a chest of coins. The coins are split equally, and each player gets the same whole number of coins. Coins that cannot be split equally stay in the chest.

**Formula.**

```text
each = coins / players
left in chest = coins % players
check = (each * players + left in chest == coins)
```

Store the check in a variable of type `bool`.

**Output.** How much each player gets, how much is left in the chest, and the result of the check.

**Example.** Input: coins `100`, players `3`. Output: `33`, `1`, `1`.

**Think about it.**

1. What does a check result of `1` mean? Can it be `0` if the formulas are correct?
2. Which input makes the program crash? Why?

### Task 10. Inventory and stacks

**Situation.** Identical items in the inventory are grouped into stacks. A stack holds at most 64 items, and each stack takes one slot.

**Formula.**

```text
full stacks = items / 64
items in the partial stack = items % 64
slots used = (items + 63) / 64
```

Make the number 64 a constant named `STACK_SIZE`, and write 63 through it as `STACK_SIZE - 1`.

**Output.** The number of full stacks, the number of items in the partial stack, and the number of slots used.

**Example.** Input: `150`. Output: `2`, `22`, `3`.

**Think about it.**

1. Work out the number of slots for `128` and for `129` items. Why is 63 added in the formula? What happens without it?
2. The stack size in the game changed from 64 to 16. How many lines of the program do you need to change? Why?

### Task 11. Level from experience

**Situation.** Each new level requires 1000 experience. The game stores the character's total experience and uses it to show the level and a progress bar.

**Formula.**

```text
level = experience / 1000 + 1
experience in current level = experience % 1000
to next level = 1000 - experience in current level
bar percent = experience in current level * 100 / 1000
```

Make the number 1000 a constant.

**Output.** The level, the experience in the current level, how much experience is left to the next level, and the bar percentage.

**Example.** Input: `4350`. Output: `5`, `350`, `650`, `35`.

**Think about it.**

1. A student wrote the percentage as `xpInLevel / 1000 * 100`. What does this give for the example? Why?
2. What level does a new character with `0` experience have? Why is there a `+ 1` in the formula?

### Task 12. Map cells

**Situation.** A level map is made of cells. The cells are numbered in order from left to right, row by row, starting from 0. The map width is given in cells. Row and column numbers also start from 0.

**Formula.**

```text
row = cell number / width
column = cell number % width
cell to the right = cell number + 1
cell below = cell number + width
number check = row * width + column
```

**Output.** The row, the column, the number of the cell to the right, the number of the cell below, and the number check.

**Example.** Input: width `8`, cell number `21`. Output: `2`, `5`, `22`, `29`, `21`.

**Think about it.**

1. Draw a map 4 cells wide and 3 cells high and label the numbers of all cells. Use the drawing to check the formulas for cell `6`.
2. Width `8`, cell number `23`. Where on the map is the "cell to the right" with number `24`? Does "number + 1" always give the neighbor to the right?

### Task 13. Fix the code: health percentage

**Situation.** A health bar 200 pixels wide is drawn above the character. A programmer wrote code for the calculation, but for most data the program prints `0`:

```cpp
#include <iostream>

int main() {
    int health = 0;
    int maxHealth = 0;

    std::cout << "Health: ";
    std::cin >> health;
    std::cout << "Max health: ";
    std::cin >> maxHealth;

    double percent = health / maxHealth * 100;
    int barWidth = percent * 2;

    std::cout << "Health percent: " << percent << '\n';
    std::cout << "Bar width: " << barWidth << '\n';

    return 0;
}
```

Find the mistake and fix it so that the percentage keeps its fractional part.

**Formula.**

```text
percent = health * 100 / maximum health
bar width = percent * 2
```

The bar width is stored in an `int`, because pixels are whole.

**Output.** The health percentage, then the bar width.

**Example.** Input: `50`, `60`. Output: `83.3333`, `166`.

**Think about it.**

1. Why does the original program print `0` for `50` and `60`, but the correct answer `100` for `60` and `60`?
2. Where did the fractional part go when calculating the bar width in the example? Why is that acceptable here?

### Task 14. Critical hit

**Situation.** On a critical hit, the attack is multiplied by a fractional multiplier, such as `1.5`. But health in the game is stored as whole numbers, so damage has to be whole as well.

**Formula.**

```text
exact damage = attack * multiplier
damage without fraction = attack * multiplier
loss = exact damage - damage without fraction
rounded damage = attack * multiplier + 0.5
```

Store the exact damage and the loss in `double`, and the damage without fraction and the rounded damage in `int`.

**Output.** The exact damage, the damage without fraction, the loss, and the rounded damage.

**Example.** Input: attack `25`, multiplier `1.5`. Output: `37.5`, `37`, `0.5`, `38`.

**Think about it.**

1. In the formula, "damage without fraction" is written exactly like "exact damage". Why are the results different?
2. Explain why adding `0.5` turns dropping the fractional part into rounding. Check it on an exact damage of `37.2` and `37.8`.

## Level 3. Comparisons and logical operations

### Task 15. Enough coins

**Situation.** The character wants to buy several identical items. The game shows in advance whether there are enough coins and how many items can be bought at most.

**Formula.**

```text
cost = price * quantity
enough = coins >= cost
maximum items = coins / price
```

Store the result of the comparison in a variable of type `bool`.

**Output.** The cost, whether there are enough coins, and the maximum number of items.

**Example.** Input: coins `100`, price `30`, quantity `3`. Output: `90`, `1`, `3`.

**Think about it.**

1. The character has exactly as many coins as the purchase costs. What will the program print? What changes if you replace `>=` with `>`?
2. Why is the maximum number of items in the example `3` and not `3.33`?

### Task 16. Chest

**Situation.** A chest can be opened in two ways. First: the character has a key, and their strength is at least 10. Second: the character is a thief, and their agility is at least 15.

**Formula.**

```text
can open = (has key AND strength >= 10) OR (is thief AND agility >= 15)
```

Use the operations `&&` and `||`. Whether the character has a key and whether the character is a thief are entered as `1` or `0`.

**Output.** Whether the chest can be opened.

**Example.** Input: key `1`, strength `8`, thief `1`, agility `20`. Output: `1`.

**Think about it.**

1. Give two different sets of data for which the chest cannot be opened. For each, explain which part of the expression was false.
2. Does the result change if you remove the parentheses? Why is it still worth keeping them?

### Task 17. Inside the zone

**Situation.** The game has a rectangular zone, such as a trap zone. A position on the screen is given by two numbers: `x` is counted from the left edge to the right, and `y` from the top edge down. The top-left corner of the zone is at `left` and `top`, the zone's width is `width`, and its height is `height`.

**Formula.** A point is inside the zone if all four conditions are true:

```text
x >= left
x <= left + width
y >= top
y <= top + height
```

**Output.** Whether the point is inside the zone.

**Example.** Input: `left` = `100`, `top` = `50`, `width` = `120`, `height` = `40`, point `x` = `150`, `y` = `70`. Output: `1`.

**Think about it.**

1. Point `x` = `90`, `y` = `70`, the zone from the example. Which of the four conditions is false?
2. A point lies exactly on the right edge of the zone, `x` = `220`. Does it count as inside the zone? What would you change in the expression so that the edge does not count?

### Task 18. Enemy waves

**Situation.** Enemies attack in waves. Wave numbers start from 1. Every fifth wave is a boss wave. Every even wave that is not a boss wave is a bonus wave.

**Formula.**

```text
number of enemies = wave number * 3 + 5
boss wave = wave number % 5 == 0
even wave = wave number % 2 == 0
bonus wave = even wave AND NOT boss wave
```

**Output.** The number of enemies, whether it is a boss wave, and whether it is a bonus wave.

**Example.** Input: `10`. Output: `35`, `1`, `0`.

**Think about it.**

1. List the wave numbers from 1 to 15 that are bonus waves.
2. How can you write "every third wave" with `%`? Check it on waves 3, 4, and 6.

### Task 19. Game over

**Situation.** The game ends if the character runs out of health or time runs out. The player wins if no enemies are left and the game is not over.

**Formula.**

```text
character died = health <= 0
time is up = time left <= 0
game over = character died OR time is up
win = enemies left == 0 AND NOT game over
```

Store each intermediate value in a separate variable of type `bool`.

**Output.** Whether the game is over, and whether the player won.

**Example.** Input: health `50`, time `30`, enemies `0`. Output: `0`, `1`.

**Think about it.**

1. Health `20`, time `0`, enemies `0`. What will the program print? Is this fair to the player from a game design point of view?
2. A student mistakenly wrote `enemiesLeft = 0` instead of `enemiesLeft == 0`. Will the program compile? What will it print for the example, and why?

### Task 20. Checkered floor

**Situation.** The castle floor is laid with tiles of two colors, like a chessboard. Rows and columns are numbered from 0. The tile in row 0 and column 0 is light, and neighboring tiles always have different colors.

**Formula.**

```text
dark tile = (row + column) % 2 == 1
light tile = NOT dark tile
```

**Output.** Whether the tile is dark, and whether it is light.

**Example.** Input: row `2`, column `3`. Output: `1`, `0`.

**Think about it.**

1. Draw a 4 by 4 piece of the floor and mark the dark tiles. Does the drawing match the formula for the tile in row `1` and column `1`?
2. Why does the formula add the row and the column? What happens if you check only `column % 2 == 1`?

## Report

Write the report in Microsoft Word using the template [`report-template-en.docx`](./report-template-en.docx). Fill in the title page. Text in square brackets in the template is a hint: replace it with your own text and delete the hints.

For each of your five tasks, the report contains:

1. The task number, its title, and its text.
2. A table of variables with their types and an explanation of each choice.
3. The program code. Paste it as text, not as an image.
4. A testing table for three data sets and a screenshot of one run.
5. A description of any mistakes you found and fixed.
6. Answers to the "Think about it" questions.

The conclusions go at the end of the report.

## Review questions

1. How is an expression different from a statement? Give an example from your program.
2. Why is `7 / 2` equal to `3` in C++? How do you get `3.5`?
3. What does the `%` operation calculate? Give an example of its use in a game.
4. Why can `double average = a / b;` lose the fractional part for whole numbers `a` and `b`, even though `average` is a fractional variable?
5. How do `=` and `==` differ? Why is a mistake with them hard to notice?
6. How do `&&` and `||` differ? Give an example of a game condition for each.
7. In which of your tasks does the program give a result that makes no sense in the game? Which tool will you need to fix it?
