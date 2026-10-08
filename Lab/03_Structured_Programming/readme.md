# Lab 3. Branching and Loops

## Objective

Learn to break a task into sequence, branching, and repetition, draw the algorithm as a flowchart, and only then turn the flowchart into a C++ program with `if`, `switch`, and loops. Check the program on several data sets and trace how its variables change from one loop iteration to the next.

## What to submit

1. Five C++ programs, one for each task you chose. Each program is stored in its own file: `task_1.cpp`, `task_8.cpp`, and so on, named after the task number.
2. Five flowcharts, one for each task: a `.drawio` file from [draw.io](https://app.diagrams.net) or a photo of a drawing on paper. Name them after the task number: `flowchart_1.drawio`, `flowchart_8.jpg`, and so on.
3. A Word report (`.docx`) based on the template [`report-template-en.docx`](./report-template-en.docx).

Submit all files together in one `.zip` archive.

## Choosing your tasks

The tasks are split into three levels. You need to complete 5 tasks in total:

| Level                           | Tasks | How many to choose |
| ------------------------------- | :---: | :----------------: |
| Level 1. Branching              |  1-7  |     at least 1     |
| Level 2. Loops                  | 8-14  |     at least 1     |
| Level 3. Branching inside loops | 15-20 |     at least 2     |

The fifth task can come from any level.

## What you can use

You can use everything from Lab 2 and the constructs from Lecture 5:

- `if`, `else`, and `else if`;
- `switch` with `case`, `default`, and `break`;
- the ternary operator `?:`;
- the loops `while`, `do while`, and `for`;
- one construct inside another (nesting).

You cannot use arrays, `std::string`, your own functions other than `main`, `goto`, `continue`, or ready-made functions such as `std::max`. These topics come later in the course.

Use `break` only inside `switch`. To stop a loop, use its condition: a loop has one entry and one exit, as we discussed in Lecture 5. If a loop has to stop for two reasons, combine them in the condition with `&&` or `||`.

## The main rule: algorithm first, program second

> [!IMPORTANT]
>
> For every task, first draw the flowchart and only then write the program. The program is written _from_ the flowchart, not the other way around.
>
> - Every diamond in the flowchart becomes a condition in the program: in an `if`, `else if`, `case`, or loop.
> - Every arrow that leads back becomes a loop.
> - The program and the flowchart must match: the same conditions, the same order of actions, the same variable names.
>
> A flowchart that does not match the program, or a program with a loop or branch that the flowchart does not show, is graded as a mistake.

Why this order? In Lab 2 the program simply ran from top to bottom. Now it can choose a path and go back. It is very easy to get lost in nested conditions and loops if you start straight from code. A flowchart shows the whole structure at once, including where each loop ends, before you have to think about braces and semicolons.

## How to read a task

Every task has the same layout:

- **Situation** describes what happens in the game.
- **Rules** list everything the program must take into account.
- **Output** says what the program prints.
- **Example** shows the input values and what the program prints for them. The input prompts are not shown, only the results.
- **Think about it** contains two questions. Your answers go into the report.

All input values are non-negative whole numbers unless a task says otherwise. A yes-or-no answer is entered as a number: `1` means "yes" and `0` means "no".

## Procedure

Do Steps 1-5 for each of your five tasks.

### Step 1. Analyze the problem

1. Find the inputs and give them names. Choose a type for each variable and explain your choice in one phrase.
2. List what the program prints.
3. Answer the three questions from Lecture 5:
   - _What happens in sequence?_
   - _Where does the program make a decision?_ Write down each condition.
   - _What repeats?_ Write down the exit condition of each loop.

The answers to these questions are the skeleton of your flowchart.

### Step 2. Flowchart

Draw the flowchart with the four blocks from Lecture 2.

Every path through the flowchart must reach the "End" block.

A few more rules:

- A `switch` is drawn as a chain of diamonds: one diamond for each `case`.
- For `do while`, the diamond comes _after_ the body, and the arrow back leads to the start of the body.
- A nested construct is drawn entirely inside the outer one: a branch inside a loop sits between the loop's diamond and its arrow back.

> [!TIP]
>
> Draw a rough version by hand first, check it on the example from the task by following the arrows with your finger, and only then redraw it neatly in draw.io.

### Step 3. Program

Write the program in C++ by going through your flowchart from top to bottom.

Format the code as agreed in Lecture 5:

- the body of a block is indented by four spaces;
- the opening brace stays at the end of the line with `if`, `while`, or `for`;
- the closing brace is on its own line, at the same level as the start of the construct;
- braces are always used, even if the body has only one statement.

Before each input, print a short prompt, for example `std::cout << "Health: ";`.

### Step 4. Testing

1. Prepare three sets of input data:
   - the example from the task;
   - a _boundary case_, for example exactly on the edge of a condition or a loop that runs exactly once;
   - a _special case_, for example a loop that does not run at all.

   Together, the data sets must go through every branch of the program at least once. If there are many branches, three sets will not be enough.

2. For each data set, work out the expected result by hand _before running the program_.
3. Run the program and compare the actual result with the expected one.
4. For tasks with a loop, fill in a trace table for one data set. Write one row for each check of the loop condition, as in Lecture 5. Choose data for which the loop runs no more than six times.
5. Take a screenshot of one of the runs.

If the results differ, find the step where the mistake happened, fix _both_ the flowchart and the program, and test again. Briefly describe the mistake in the report. A mistake that you found and fixed does not lower your grade.

> [!WARNING]
>
> If the program stops printing anything and does not finish, it is most likely stuck in an infinite loop. Stop it with `Ctrl+C` or the Stop button in your IDE and check what changes the variable in the loop condition.

### Step 5. Answer the questions

Answer the two questions under "Think about it". If a question asks you to calculate something, show the calculation, not only the answer.

## Level 1. Branching

### Task 1. Health status

**Situation.** Above the character, the game shows their health as a percentage and a short status.

**Rules.**

- Percentage of health: `health * 100 / maxHealth`. Maximum health is always greater than 0, and health is never greater than the maximum.
- If health is 0, the status is "Dead".
- Otherwise the status depends on the percentage: 25 or less is "Critical", 60 or less is "Wounded", less than 100 is "Scratched", and 100 is "Full health".
- If the status is "Critical", the game also prints "Find a healer!".

**Output.** The percentage, the status, and the extra message if there is one.

**Example.** Input: health `45`, maximum health `120`. Output:

```text
Health: 37%
Wounded
```

**Think about it.**

1. Health `1`, maximum `120`. What percentage and status does the program print? Why does the rule check `health == 0` and not `percent == 0`?
2. Why must the "25 or less" check come before the "60 or less" check? What does the program print for health `30` of `120` if you swap them?

### Task 2. Merchant

**Situation.** The character buys an item from a merchant. Regular customers get a discount.

**Rules.**

- A customer with 10 or more past purchases gets a 25-coin discount. A customer with 5 or more purchases gets a 10-coin discount. Others get no discount.
- The final price cannot be less than 1 coin.
- If the character has enough coins, the price is paid and the game prints "Purchase complete".
- Otherwise the game prints "Not enough coins, missing" and how many coins are missing. The coins do not change.

**Output.** The final price, the message, and the coins.

**Example.** Input: coins `50`, item price `45`, past purchases `12`. Output:

```text
Price: 20
Purchase complete
Coins: 30
```

**Think about it.**

1. Item price `20`, past purchases `10`. What is the final price? Which rule decides it?
2. On the flowchart, the purchase check comes after the price calculation. What would go wrong if you checked the coins against the price _before_ applying the discount?

### Task 3. Choosing a class

**Situation.** At the start of the game, the player chooses a character class by number and enters the starting level.

**Rules.**

- Class `1` is Warrior: health 150, attack 12. Class `2` is Mage: health 80, attack 25. Class `3` is Archer: health 100, attack 18.
- For any other number, the game prints "Unknown class, Warrior selected" and uses the Warrior.
- Every level above the first adds 10 health and 2 attack: `health = health + (level - 1) * 10`, and the same with 2 for attack. The level is at least 1.
- Choose the class with `switch`.

**Output.** The class name, health, and attack.

**Example.** Input: class `2`, level `3`. Output:

```text
Class: Mage
Health: 100
Attack: 29
```

**Think about it.**

1. Remove the `break` after `case 1` in your program and run it with class `1`. What happens and why?
2. Why can't `switch` choose the status in Task 1, where the status depends on a range of percentages?

### Task 4. Time of day

**Situation.** The game world has a clock from 0 to 23 hours. The time of day changes the lighting and whether the shops are open.

**Rules.**

- If the hour is greater than 23, the game prints "Invalid hour" and nothing else.
- From 22 to 5 inclusive is "Night", from 6 to 11 is "Morning", from 12 to 17 is "Day", and from 18 to 21 is "Evening".
- Street lights are on at night and in the evening. Print "on" or "off" with the ternary operator.
- Shops are open from 8 to 20 inclusive. Print "open" or "closed" with the ternary operator.

**Output.** The time of day, the lights, and the shops.

**Example.** Input: `19`. Output:

```text
Evening
Lights: on
Shops: open
```

**Think about it.**

1. Write the condition for "Night". Why can't it be written as one comparison, the way `hour >= 6 && hour <= 11` is for "Morning"?
2. On which hours do the lights and the shops both work? List them.

### Task 5. Stars for a level

**Situation.** After a level, the player gets from 0 to 3 stars depending on the time and the number of deaths.

**Rules.**

- If the time is over 300 seconds, the level is failed: the game prints "Level failed" and 0 stars.
- 3 stars: time is 60 seconds or less and there were no deaths. The game also prints "Perfect run!".
- 2 stars: time is 120 seconds or less and there were 2 deaths or fewer.
- In all other cases, 1 star.

**Output.** The number of stars and the extra message if there is one.

**Example.** Input: time `95`, deaths `1`. Output:

```text
Stars: 2
```

**Think about it.**

1. Time `50`, deaths `3`. How many stars does the player get? Is this fair from a game design point of view?
2. What does the program print for time `40` and no deaths if the 2-star check comes before the 3-star check?

### Task 6. Fix the code: shield

**Situation.** Armor protects the character from damage. A programmer wrote the code, but it always prints the same thing:

```cpp
#include <iostream>

int main() {
    int health = 0;
    int damage = 0;
    int armor = 0;

    std::cout << "Health: ";
    std::cin >> health;
    std::cout << "Damage: ";
    std::cin >> damage;
    std::cout << "Armor: ";
    std::cin >> armor;

    if (armor >= 50) {
        damage = damage / 2;
    } else if (armor >= 80) {
        damage = 0;
    }

    health = health - damage;

    if (health < 0);
    {
        health = 0;
    }

    if (health = 0) {
        std::cout << "Game Over\n";
    } else {
        std::cout << "Health left: " << health << '\n';
    }

    return 0;
}
```

The code contains three mistakes. Draw the flowchart of the _correct_ algorithm from the rules first, then compare it with the code to find the mistakes.

**Rules.**

- Armor of 80 or more blocks all damage. Armor of 50 or more halves the damage.
- Health cannot drop below 0.
- If health becomes 0, the game prints "Game Over". Otherwise it prints the remaining health.

**Output.** "Game Over" or the remaining health.

**Example.** Input: health `100`, damage `40`, armor `60`. Output:

```text
Health left: 80
```

**Think about it.**

1. What does the original program print for any input? Explain which of the three mistakes causes it.
2. Armor `90`. Which branch did the original program choose, and which one should it have chosen?

### Task 7. Elements

**Situation.** Each attack and each enemy belongs to one of three elements: fire `F`, water `W`, or nature `N`. Fire beats nature, nature beats water, and water beats fire. Elements are entered as single characters, so use the type `char`.

**Rules.**

- If the attack's element beats the enemy's element, the damage is doubled and the game prints "Super effective!".
- If the enemy's element beats the attack's element, the damage is halved and the game prints "Not very effective".
- If the elements are the same, the damage does not change.
- If at least one of the entered characters is not `F`, `W`, or `N`, the game prints "Unknown element" and the damage does not change.

**Output.** The message if there is one, and the damage.

**Example.** Input: attack element `W`, enemy element `F`, damage `30`. Output:

```text
Super effective!
Damage: 60
```

**Think about it.**

1. How many different pairs "attack element, enemy element" are there? How many of them are strong, weak, and neutral?
2. The player entered a lowercase `f`. What does the program print? How would you change the condition so that both `F` and `f` are accepted?

## Level 2. Loops

### Task 8. Spawning enemies

**Situation.** At the start of a level, the game creates several enemies. Each next enemy is a bit stronger than the previous one.

**Rules.**

- Enemies are numbered from 1.
- An enemy's health: `baseHealth + (number - 1) * 10`.
- After all enemies are created, the game prints their total health.
- Use the `for` loop.

**Output.** One line per enemy, then the total health.

**Example.** Input: number of enemies `3`, base health `50`. Output:

```text
Enemy 1: health 50
Enemy 2: health 60
Enemy 3: health 70
Total health: 180
```

**Think about it.**

1. Number of enemies `0`. What does the program print? How many times is the loop condition checked?
2. A student wrote the condition as `i < count`, with `i` starting at 1. How many enemies are created for the example? What is this kind of mistake called?

### Task 9. Countdown

**Situation.** Before a race, the game counts down. To avoid printing every second, it prints the time with a given step.

**Rules.**

- The countdown starts from the given number of seconds and decreases by the step each time while the time is greater than 0. The step is always greater than 0.
- Each time is printed as `M:SS`, with seconds always in two digits, as in Task 8 of Lab 2.
- After the countdown, the game prints "Go!".

**Output.** The times, one per line, then "Go!".

**Example.** Input: seconds `125`, step `30`. Output:

```text
2:05
1:35
1:05
0:35
0:05
Go!
```

**Think about it.**

1. Seconds `120`, step `30`. How many lines with times are printed? Why is `0:00` not printed, and what would you change in the condition to print it?
2. What happens if the user enters step `0`? Show it with the first three rows of a trace table.

### Task 10. Poison

**Situation.** The character is poisoned. Each turn the poison deals damage, but it gets weaker by 1 every turn.

**Rules.**

- Each turn, the current poison strength is subtracted from health, and then the poison strength decreases by 1.
- Turns continue while the poison strength is greater than 0 and the character is alive.
- After the loop, the game prints "Survived with" and the health, or "Died on turn" and the turn number.

**Output.** The health after each turn, then the result.

**Example.** Input: health `30`, poison strength `5`. Output:

```text
Turn 1: health 25
Turn 2: health 21
Turn 3: health 18
Turn 4: health 16
Turn 5: health 15
Survived with 15 health
```

**Think about it.**

1. Health `5`, poison `7`. What does the last line before the result show? How would you make sure that health never goes below 0? Which construct do you need for that, and where in the flowchart would it go?
2. Without running the program, work out how much total damage poison with strength `5` deals if the character survives. Check it against the example.

### Task 11. Several levels at once

**Situation.** After a big quest, the character gets so much experience that they can gain several levels at once.

**Rules.**

- The reward is added to experience.
- To reach the next level, experience must be at least `level * 100`. If it is, this threshold is subtracted from experience, the level goes up by 1, and the game prints "Level up! Now level" and the new level.
- This repeats while there is enough experience for the next level.

**Output.** A message for each new level, then the final level and experience.

**Example.** Input: level `2`, experience `50`, reward `600`. Output:

```text
Level up! Now level 3
Level up! Now level 4
Level: 4
XP: 150
```

**Think about it.**

1. Why do you need a loop here and not one `if`? What would the program print for the example with an `if`?
2. Level `2`, experience `50`, reward `0`. How many times does the loop body run? How many times is the condition checked?

### Task 12. Choosing difficulty

**Situation.** Before the game starts, the player chooses a difficulty from 1 to 3. If the player enters something else, the game asks again.

**Rules.**

- Ask for the difficulty until the player enters 1, 2, or 3. After each invalid input, print "Invalid choice".
- Count how many attempts it took.
- After a valid choice, the number of enemies is `difficulty * 4 + 2`, and enemy attack is `5 + difficulty * 3`.
- Use the `do while` loop.

**Output.** "Invalid choice" for each invalid input, then the difficulty, enemies, enemy attack, and attempts.

**Example.** Input: `0`, `5`, `2`. Output:

```text
Invalid choice
Invalid choice
Difficulty: 2
Enemies: 10
Enemy attack: 11
Attempts: 3
```

**Think about it.**

1. Why does `do while` fit this task better than `while`? What would you have to do before a `while` loop to make it work?
2. Write the condition "the input is invalid" with `||` and the condition "the input is valid" with `&&`. How are they related to each other?

### Task 13. Savings in the bank

**Situation.** The character keeps coins in the city bank. Each day the bank adds interest.

**Rules.**

- Each day, the coins grow by `coins / 10 + 1`.
- Days pass while the coins are less than the target.
- The game prints the coins after each day and, at the end, how many days it took.

**Output.** The coins after each day, then the number of days.

**Example.** Input: coins `100`, target `150`. Output:

```text
Day 1: 111 coins
Day 2: 123 coins
Day 3: 136 coins
Day 4: 150 coins
Target reached in 4 days
```

**Think about it.**

1. Why is `+ 1` in the formula? What would happen with `5` coins and a target of `10` without it?
2. Coins `200`, target `150`. What does the program print? Is it correct?

### Task 14. Fix the code: combo

**Situation.** The character makes a series of hits. Each next hit is stronger than the previous one. A programmer wrote the code, but it prints one hit too few and a strange total:

```cpp
#include <iostream>

int main() {
    int hits = 0;
    int baseDamage = 0;
    int total;

    std::cout << "Hits: ";
    std::cin >> hits;
    std::cout << "Base damage: ";
    std::cin >> baseDamage;

    for (int i = 1; i < hits; i = i + 1) {
        int damage = baseDamage + i * 2;
        total = total + damage;
        std::cout << "Hit " << i << ": " << damage << '\n';
    }

    std::cout << "Total: " << total << '\n';

    return 0;
}
```

The code contains two mistakes. Draw the flowchart of the correct algorithm from the rules first, then find the mistakes.

**Rules.**

- Hits are numbered from 1. Hit number `i` deals `baseDamage + i * 2`.
- The game prints the damage of each hit and the total damage.

**Output.** The damage of each hit, then the total.

**Example.** Input: hits `3`, base damage `10`. Output:

```text
Hit 1: 12
Hit 2: 14
Hit 3: 16
Total: 42
```

**Think about it.**

1. Why can the original program print a different total each time it runs? What did Lecture 3 say about a variable that was declared without a value?
2. Rewrite your fixed loop as a `while` loop. Where do the three parts of the `for` line end up?

## Level 3. Branching inside loops

### Task 15. Waves of enemies

**Situation.** Enemies attack in waves numbered from 1. Most waves are normal, but some are special.

**Rules.**

- Every tenth wave is a boss wave: it has one enemy, the boss.
- Every fifth wave that is not a boss wave is an elite wave.
- Normal and elite waves have `wave + 3` enemies.
- The game prints each wave, and at the end the total number of enemies and the number of boss waves.

**Output.** One line per wave, then the totals.

**Example.** Input: number of waves `10`. Output:

```text
Wave 1: 4 enemies
Wave 2: 5 enemies
Wave 3: 6 enemies
Wave 4: 7 enemies
Wave 5: elite, 8 enemies
Wave 6: 9 enemies
Wave 7: 10 enemies
Wave 8: 11 enemies
Wave 9: 12 enemies
Wave 10: BOSS
Total enemies: 73
Boss waves: 1
```

**Think about it.**

1. Wave `20` is divisible by both 10 and 5. Which line does your program print for it? What would it print if the check for 5 came first?
2. How does the program count boss waves without remembering each wave? Which variable changes, and in which branch?

### Task 16. Duel

**Situation.** The player fights an enemy in turns. Both attacks are always greater than 0.

**Rules.**

- Each round, the player hits first: the enemy loses health equal to the player's attack.
- If the enemy is still alive after that, the enemy hits back.
- Health cannot drop below 0.
- Rounds continue while both are alive. Do not use `break`: the loop must stop through its condition.
- At the end, the game prints "Victory!" or "Defeat!".

**Output.** Both health values after each round, then the result.

**Example.** Input: player health `50`, player attack `12`, enemy health `40`, enemy attack `15`. Output:

```text
Round 1: player 35, enemy 28
Round 2: player 20, enemy 16
Round 3: player 5, enemy 4
Round 4: player 5, enemy 0
Victory!
```

**Think about it.**

1. What happens in round 4 of the example if the enemy hits back without checking whether it is alive? Who would win then?
2. The loop condition is checked only at the start of each round. How does the loop still stop right after the enemy dies in the middle of a round?

### Task 17. Chests

**Situation.** The character goes through a row of chests. Some contain coins, and some are traps.

**Rules.**

- For each chest, the number of coins inside is entered. If it is 0, the chest is a trap: the character loses 15 health.
- Health cannot drop below 0. If the character dies, the remaining chests are not opened, and the game prints "Character died".
- The game remembers the chest with the most coins and its number. If no coins were found at all, it prints "No coins found" instead.
- Stop the loop through its condition, without `break`.

**Output.** A line for each opened chest, then the coins, the best chest, and the number of traps.

**Example.** Input: health `40`, number of chests `5`, then the coins in the chests: `12`, `0`, `30`, `7`, `0`. Output:

```text
Chest 1: found 12 coins
Chest 2: trap! Health 25
Chest 3: found 30 coins
Chest 4: found 7 coins
Chest 5: trap! Health 10
Coins: 49
Best chest: 3 (30 coins)
Traps: 2
```

**Think about it.**

1. Two chests contain the same largest number of coins, for example `30`, `10`, `30`. Which chest does your program choose as the best? What decides it in your condition?
2. The program finds the best chest without storing the contents of all chests. Which variables are enough for this, and why?

### Task 18. Guess the number

**Situation.** The game master thinks of a number from 1 to 100, and the player tries to guess it. The game gives hints.

**Rules.**

- First, the game master enters the secret number. Then the player enters guesses.
- After each guess, the game prints "Too low", "Too high", or "Correct!".
- The player has at most 10 attempts.
- If the player guessed the number, the game prints the number of attempts and a rating: 3 attempts or fewer is "Excellent!", 7 or fewer is "Good", otherwise "Keep practicing".
- If the attempts run out, the game prints "Out of attempts. The number was" and the number.

**Output.** A hint after each guess, then the result.

**Example.** Input: secret number `42`, guesses `50`, `25`, `42`. Output:

```text
Too high
Too low
Correct!
Attempts: 3
Excellent!
```

**Think about it.**

1. The loop stops for one of two reasons. How does the program find out after the loop which reason it was?
2. What is the smallest number of attempts that is always enough to guess a number from 1 to 100 if the player chooses each guess wisely? Describe the strategy.

### Task 19. Health bar

**Situation.** Above the character, the game draws a text health bar of 10 cells: `#` for a filled cell and `-` for an empty one.

**Rules.**

- Filled cells: `health * 10 / maxHealth`. Maximum health is always greater than 0.
- If the character is alive but the formula gives 0 filled cells, one cell is still filled.
- Draw the bar with a loop that prints one cell at each step.
- Make the bar width 10 a constant.

**Output.** The bar and the health as `health/maxHealth`.

**Example.** Input: health `45`, maximum health `120`. Output:

```text
[###-------] 45/120
```

**Think about it.**

1. Health `5` of `120`. How many cells does the formula give? Why is the rule about one filled cell needed from a game design point of view?
2. The bar needs to be 20 cells wide. How many places in your program do you change? What would you have to change without the constant?

### Task 20. Room map

**Situation.** The game draws a room from characters: `#` for walls, `.` for the floor, `P` for the player, and `E` for the exit. Rows and columns are numbered from 0, rows from top to bottom and columns from left to right.

**Rules.**

- The room is surrounded by walls: these are the first and last rows and the first and last columns.
- The exit is in the cell one step away from the bottom-right corner: in row `height - 2` and column `width - 2`.
- The player stands at the given row and column.
- Draw the room with a loop inside a loop: the outer loop goes over the rows, and the inner loop prints all the cells of one row. After the inner loop, print a line break.

**Output.** The room map.

**Example.** Input: width `6`, height `4`, player column `1`, player row `1`. Output:

```text
######
#P...#
#...E#
######
```

**Think about it.**

1. How many times does the body of the inner loop run for the example? And the body of the outer loop?
2. The player is placed at column `0`, row `0`, inside the wall. What does your program print in that cell? What decides it?

## Report

Write the report in Microsoft Word using the template [`report-template-en.docx`](./report-template-en.docx). Fill in the title page. Text in square brackets in the template is a hint: replace it with your own text and delete the hints.

For each of your five tasks, the report contains, in this order:

1. The task number, its title, and its text.
2. The problem analysis: a table of variables and the answers to the three questions from Step 1.
3. The flowchart.
4. The program code. Paste it as text, not as an image.
5. A testing table for three data sets, a trace table for a task with a loop, and a screenshot of one run.
6. A description of any mistakes you found and fixed.
7. Answers to the "Think about it" questions.

The conclusions go at the end of the report.

## Grading criteria

- A flowchart is drawn for each task, and it matches the program: the same conditions, loops, order of actions, and names.
- The programs compile and give the correct result for all data sets.
- The programs use only the allowed constructs, and loops stop through their condition.
- The data sets go through every branch, and the boundary and special cases are chosen thoughtfully.
- The trace tables are filled in correctly.
- The answers to the "Think about it" questions are correct.
- The code is formatted as agreed in Lecture 5 and is easy to read.

## Review questions

1. What are the three basic constructs of structured programming? Show where each one appears in one of your programs.
2. How are full and partial branching different? Give an example from your tasks.
3. Why does the order of conditions in an `if ... else if` chain matter?
4. How are `while`, `do while`, and `for` different? When would you choose each one?
5. What is an infinite loop? In which of your tasks could it happen with some input, and why?
6. What is an off-by-one error? How does a trace table help to find it?
7. Why is it easier to write a program with nested loops and branches from a flowchart than straight away in code?
