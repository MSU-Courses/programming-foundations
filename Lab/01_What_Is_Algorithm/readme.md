# Lab 1. An Algorithm in Pseudocode and a Flowchart

## Objective

Learn to turn a description of a game situation into an algorithm, write the algorithm as pseudocode and a flowchart, and check that it is correct by executing it by hand with a trace table.

## Note

Tasks marked `[extra]` are optional and count toward a higher grade.

## What to submit

A Word report (`.docx`) that solves two tasks: one from Part A and one from Part B. Use the template [`report-template-en.docx`](./report-template-en.docx).

## Choosing your tasks

Your task numbers depend on the last digit of your number in the group list.

| Last digit of your number | Part A | Part B |
| :-----------------------: | :----: | :----: |
|             1             |   1    |   11   |
|             2             |   2    |   12   |
|             3             |   3    |   13   |
|             4             |   4    |   14   |
|             5             |   5    |   15   |
|             6             |   6    |   16   |
|             7             |   7    |   17   |
|             8             |   8    |   18   |
|             9             |   9    |   19   |
|             0             |   10   |   20   |

## How to read a task

Every task has the same layout:

- **Situation** describes what happens in the game.
- **Formula** appears only in Part B. It is a ready-made calculation, and you do not need to derive it.
- **Rules** list everything the algorithm must take into account.
- **Output** says which values the algorithm prints at the end.
- **Example** shows the correct result for one set of data. Use it to check that you understood the task.
- **Think about it** contains two questions. Your answers go into the report.

These general rules apply to all tasks:

1. The inputs are not listed in the tasks, so you need to find them yourself. If a value is given in the text as a number, such as "the trap deals 40 damage", it is a game rule and is not an input. If a value is not given as a number, such as "the character's health", it is an input.
2. All input values are non-negative whole numbers. You do not need to handle invalid input.
3. A yes-or-no answer is entered as a number: `1` means "yes" and `0` means "no".
4. Messages are printed in the order in which they appear in the rules. The values listed under "Output" are printed at the very end.

## Procedure

Do Steps 1-4 for each of your two tasks.

### Step 1. Analyze the problem

1. Find the inputs. Give each value a variable name and explain in one phrase what it means.
2. List what the algorithm prints.
3. Answer the questions under "Think about it". One or two sentences per question are enough.

Use these variable names in all the steps that follow.

### Step 2. Pseudocode

Write the algorithm in pseudocode. Each line should describe one action, and the executor must not have to guess anything.

Use the commands from Lecture 2 or you can create your own as long as they are clear and unambiguous.

- `INPUT` to read a value.
- `OUTPUT` to print a value or a message.
- `SET` for assignment.
- `+`, `-`, `*` for arithmetic, and parentheses for the order of operations.
- `IF ... ELSE ... END IF` for branching. You can leave out `ELSE` when you do not need it.

You can place one condition inside another. If two conditions must both be true, write one `IF` inside the other.

This lab does not require loops.

> [!TIP]
> The rules in a task are listed so that they are easy to read. This is not necessarily the order in which they must be carried out. You decide the order of the steps.

### Step 3. Flowchart

Draw a flowchart of the same algorithm. Use the four blocks from Lecture 2:

- An oval for start and end.
- A rectangle for an action.
- A parallelogram for input and output.
- A diamond for a condition. A diamond has exactly two exits: "Yes" and "No".

Every path through the flowchart must reach the "End" block. The variable names and the order of actions must match the pseudocode.

You can draw the flowchart in [draw.io](https://app.diagrams.net) and export it as PNG, or draw it by hand on paper and take a photo. The photo must be sharp, with every label readable.

### Step 4. Check the algorithm

1. Prepare at least three sets of input data:
   - a _normal case_ with typical values;
   - a _boundary case_, where a value sits exactly on the edge of a condition, for example exactly 25 for the rule "25 or more";
   - a _special case_, for example with a zero value.

   Together, the data sets must go through every branch of the algorithm at least once. If there are many branches, three sets will not be enough.

2. For each data set, work out the expected result before tracing, using only the text of the task.
3. Execute the pseudocode by hand and fill in a trace table.
4. Compare the traced result with the expected one.

You can use the example from the task as the normal case, but make up the other data sets yourself.

If the results differ, find the step where they started to differ, fix the pseudocode and the flowchart, and check again. Briefly describe the mistake in the report. A mistake that you found and fixed does not lower your grade.

### Step 5. Change the rules `[extra]`

Do this for one of your two tasks.

1. Swap two steps of the algorithm so that the result changes. Use a trace table to show which input data now give a wrong result.
2. Invent one new rule for the task, for example "on Mondays the merchant gives a 5-coin discount". Describe it in one sentence and update the pseudocode and the flowchart.

## Worked example

This example uses a task that is not in the list. It is simpler than the listed tasks and only shows how to lay out the work.

> **Coin purse**
>
> **Situation.** The character finds coins and puts them in a purse.
>
> **Rules.**
>
> - The purse holds at most 999 coins.
> - If there would be more, the extra coins are lost and the game prints "Purse is full".
>
> **Output.** The number of coins in the purse.
>
> **Example.** The purse holds 990 coins, and 20 coins are found. Output: "Purse is full", 999.
>
> **Think about it.**
>
> 1. Is there a message if the purse ends up with exactly 999 coins?
> 2. What comes first: adding the coins or checking the limit?

**Problem analysis.**

Inputs: `coins` - how many coins were in the purse, `found` - how many coins were found. The number 999 is given in the text, so it is a game rule, not an input.

Output: the message "Purse is full" if the purse overflowed, and the final value of `coins`.

Answers to the questions:

1. No. The message is printed only if there are more than 999 coins, and 999 is not more than 999.
2. Adding comes first. Until the coins are added, we do not know whether the purse overflowed.

**Pseudocode.**

```text
INPUT coins
INPUT found

SET coins = coins + found

IF coins > 999
    SET coins = 999
    OUTPUT "Purse is full"
END IF

OUTPUT coins
```

**Flowchart.**

<img src="https://imgur.com/mLCTH5p.png" alt="Flowchart for coin purse example" />

**Data sets.**

| Case     | `coins` | `found` | Expected result        |
| -------- | ------: | ------: | ---------------------- |
| Normal   |     100 |      50 | `150`                  |
| Boundary |     980 |      19 | `999`, no message      |
| Overflow |     990 |      20 | "Purse is full", `999` |
| Special  |       0 |       0 | `0`                    |

**Trace for `coins = 990`, `found = 20`.** A dash means nothing has been stored in the variable yet.

| Step | Instruction                 | `coins` | `found` | Output        |
| ---: | --------------------------- | ------: | ------: | ------------- |
|    1 | `INPUT coins`               |     990 |       - |               |
|    2 | `INPUT found`               |     990 |      20 |               |
|    3 | `SET coins = coins + found` |    1010 |      20 |               |
|    4 | `IF coins > 999`: true      |    1010 |      20 |               |
|    5 | `SET coins = 999`           |     999 |      20 |               |
|    6 | `OUTPUT "Purse is full"`    |     999 |      20 | Purse is full |
|    7 | `OUTPUT coins`              |     999 |      20 | 999           |

The result matches the expected one. Your report needs a table like this for every data set.

## Part A. Game mechanics

### Task 1. Healing potion

**Situation.** The character drinks a healing potion. An enemy may have poisoned the character earlier in the fight, so the character has a poison level.

**Rules.**

- A small potion restores 20 health and a large one restores 50. The player chooses the potion: `1` for small, `2` for large.
- If the poison level is greater than 0, the potion cures the poison: the poison level becomes 0, but the potion restores 10 less health.
- Health cannot go above the maximum.
- If the character's health is 0, the potion has no effect: the game prints "The potion has no effect", and health and poison do not change.

**Output.** Health and the poison level.

**Example.** Health 40, maximum health 100, poison level 3, large potion. Output: 80, 0.

**Think about it.**

1. Which rule has to be checked before all the others, and why?
2. Health is 95 out of 100, no poison, small potion. How much health will the character have?

### Task 2. Merchant

**Situation.** The character buys an item from a merchant.

**Rules.**

- A regular customer who has made 5 or more purchases from this merchant gets a 10-coin discount.
- The discounted price cannot drop below 1 coin.
- If the character has enough coins, the price is paid and the game prints "Purchase complete". If no coins are left after the purchase, the game prints "Purse is empty".
- If the character does not have enough coins, the game prints "Not enough coins", and the coins do not change.

**Output.** The number of coins.

**Example.** 50 coins, item price 45, 7 past purchases. Output: "Purchase complete", 15.

**Think about it.**

1. The item costs 8, and the character has made 5 purchases. How many coins will the character pay?
2. The character has exactly as many coins as the item costs. Which messages will the game print?

### Task 3. Hitting an enemy

**Situation.** The character hits an enemy and rolls a twenty-sided die. The player enters the result, a number from 1 to 20. When the hit starts, the enemy's health is greater than 0.

**Rules.**

- Damage equals the character's attack minus the enemy's defense, but is at least 1.
- If the die shows 20, damage is doubled and the game prints "Critical hit".
- If the die shows 1, the hit misses: damage is 0 and the game prints "Miss".
- Damage is subtracted from the enemy's health. The enemy's health cannot drop below 0. If it becomes 0, the game prints "Enemy defeated".

**Output.** The enemy's health.

**Example.** Attack 12, defense 5, enemy health 30, die shows 20. Output: "Critical hit", 16.

**Think about it.**

1. Attack 3, defense 8, die shows 20. How much damage will the enemy take?
2. On a miss, do you need to calculate damage as "attack minus defense"?

### Task 4. Experience and level

**Situation.** The character receives an experience reward.

**Rules.**

- The maximum level is 10. If the character is already at level 10, the reward is not added and the game prints "Maximum level".
- In all other cases, the reward is added to experience.
- To reach a new level, experience must be at least the current level multiplied by 100.
- If there is enough experience, the level goes up by 1, this threshold is subtracted from experience, and the game prints "Level up". One reward can give only one level.

**Output.** Level and experience.

**Example.** Level 3, experience 250, reward 80. Output: "Level up", 4, 30.

**Think about it.**

1. Should the threshold be calculated from the level before or after the level-up? Show with an example what would change.
2. Level 2, experience 150, reward 50. Will the character reach a new level?

### Task 5. Spike trap

**Situation.** The character steps on a spike trap.

**Rules.**

- The trap deals 40 damage.
- If the character's armor is 25 or more, the damage is reduced to 20.
- If the character drank a protection potion, the damage is reduced by another 10.
- Damage is subtracted from health. Health cannot drop below 0. If it becomes 0, the game prints "Character died".

**Output.** Health.

**Example.** Health 50, armor 30, protection potion taken. Output: 40.

**Think about it.**

1. Which damage values are possible for this trap? List all of them.
2. Armor is exactly 25 and there is no potion. How much damage will the character take?

### Task 6. Locked door

**Situation.** The character wants to go through a locked door.

**Rules.**

- The character tries the options strictly in order: first a key, then coins.
- If the character has at least one key, one key is used and the game prints "Door opened with a key".
- If there is no key, a guard opens the door for 50 coins. If the character has enough coins, 50 coins are spent and the game prints "Door opened for coins".
- If neither option works, the game prints "Door is locked".

**Output.** The number of keys and the number of coins.

**Example.** 0 keys, 70 coins. Output: "Door opened for coins", 0, 20.

**Think about it.**

1. The character has 2 keys and 100 coins. What will the character spend?
2. Why can't the coin check come before the key check in the algorithm?

### Task 7. Fireball

**Situation.** The character tries to cast the Fireball spell.

**Rules.**

- The spell costs 30 mana and deals 45 damage to the enemy.
- If the enemy resists fire, the damage is reduced to 15.
- If there is enough mana, the mana is spent and the damage is subtracted from the enemy's health. The enemy's health cannot drop below 0. If it becomes 0, the game prints "Enemy defeated".
- If there is not enough mana, the spell fails: the game prints "Not enough mana" and the character regains 10 mana. Mana cannot go above 100.

**Output.** The character's mana and the enemy's health.

**Example.** Mana 40, enemy health 60, no fire resistance. Output: 10, 15.

**Think about it.**

1. Can mana go above 100 when the spell works? Why?
2. Mana is exactly 30. Will the spell work?

### Task 8. Round timer

**Situation.** A round counts down time. The character may pick up an hourglass and then performs an action that takes time.

**Rules.**

- If the character picked up an hourglass, 15 seconds are added to the remaining time. The time cannot go above 120 seconds.
- The action happens after the hourglass is picked up and takes the given number of seconds.
- If the character's health is below 30, the character is wounded and the action takes twice as long.
- The time cannot drop below 0. If it becomes 0, the game prints "Time is up". If 1 to 10 seconds remain, the game prints "Hurry up".

**Output.** The remaining time.

**Example.** 110 seconds left, hourglass picked up, the action takes 20 seconds, health 25. Output: 80.

**Think about it.**

1. Calculate the example again, but check the "at most 120" limit after the action. Is the result the same as the correct one?
2. Can the game print both "Time is up" and "Hurry up" at once? Why?

### Task 9. Level reward

**Situation.** The player finished a level and gets a chest.

**Rules.**

- If the player finished the level without taking damage, a 200-point bonus is added to the score.
- The chest depends on the final score: 1000 or more gives a gold chest, 500 or more gives a silver chest, and anything else gives a wooden chest. The game prints "Gold chest", "Silver chest", or "Wooden chest".
- If the final score is higher than the high score, the high score becomes the final score and the game prints "New high score".

**Output.** The high score.

**Example.** Score 850, level finished without damage, high score 900. Output: "Gold chest", "New high score", 1050.

**Think about it.**

1. Score 1000, high score 1000. Is there a new high score?
2. Why must the "1000 or more" check come before the "500 or more" check?

### Task 10. Falling

**Situation.** The character falls from a height given in meters.

**Rules.**

- A fall from 3 meters or less deals no damage.
- From a greater height, damage equals the difference between the height and 3 meters, multiplied by 10.
- If the character lands in water, this difference is multiplied by 2 instead of 10.
- Damage is subtracted from health. Health cannot drop below 0. If it becomes 0, the game prints "Character died".
- If the character is alive and the damage is greater than 50, the game prints "Character stunned".

**Output.** Health.

**Example.** Height 10, not into water, health 100. Output: "Character stunned", 30.

**Think about it.**

1. Height 3 meters, into water. How much damage will the character take?
2. Height 9, not into water, health 60. Which messages will the game print?

## Part B. Game calculations

In these tasks the game calculates a value using a ready-made formula. You do not need to understand where the formula comes from. You need to carry it out correctly and follow the rules.

The formulas use only addition, subtraction, and multiplication. As in math, parentheses come first, then multiplication, then addition and subtraction. For example, `20 + 4 * 5` equals `40`, not `120`.

### Task 11. Falling object

**Situation.** A game recalculates the position of an object many times per second. One such update is called a _frame_. Describe one frame of a falling object.

**Formula.** The new height equals the height minus the falling speed:

```text
height = height - speed
```

**Rules.**

- Height cannot drop below 0.
- If height becomes 0, speed also becomes 0 and the game prints "Object landed".

**Output.** Height and speed.

**Example.** Height 50, speed 20. Output: 30, 20.

**Think about it.**

1. Height 15, speed 20. What will the game print?
2. How many frames does an object need to fall from a height of 50 at speed 20?

### Task 12. Car braking

**Situation.** The player released the gas, and the car is braking. Describe one frame.

**Formulas.** First, friction reduces speed. Then the car travels at the new speed:

```text
speed = speed - friction
distance = distance + speed
```

**Rules.**

- Speed cannot drop below 0.
- If speed becomes 0, the game prints "The car stopped".

**Output.** Speed and distance.

**Example.** Speed 25, friction 4, distance 100. Output: 21, 121.

**Think about it.**

1. What distance would you get in the example if you swapped the two formulas?
2. Speed 3, friction 5. What will the game print?

### Task 13. Health regeneration

**Situation.** The character is resting, and health recovers every second.

**Formula.** Regeneration shows how much health recovers in one second:

```text
health = health + regeneration * seconds
```

**Rules.**

- If health was 0, the character is dead and regeneration does not work. The game prints "Character died", and health does not change.
- Health cannot go above the maximum.
- If health becomes equal to the maximum, the game prints "Health restored".

**Output.** Health.

**Example.** Health 40, maximum health 100, regeneration 3, resting for 10 seconds. Output: 70.

**Think about it.**

1. What result would you get in the example if you calculated from left to right and ignored the order of operations?
2. Health 90 out of 100, regeneration 5, resting for 4 seconds. Which messages and values will the game print?

### Task 14. Bulk purchase

**Situation.** The character buys several identical items from a merchant at once.

**Formula.**

```text
total price = price of one item * quantity
```

**Rules.**

- If 10 or more items are bought, the total price is reduced by 20 coins. The total price cannot drop below 0.
- If the character has enough coins, the total price is paid and the game prints "Purchase complete".
- If the character does not have enough coins, the game prints "Not enough coins", and the coins do not change.

**Output.** The total price and coins.

**Example.** One item costs 7, quantity 10, 60 coins. Output: "Purchase complete", 50, 10.

**Think about it.**

1. Make up data for which the total price would become negative without the "not below 0" rule.
2. The character buys 9 items at 10 coins each and has 80 coins. What will the game print?

### Task 15. Level score

**Situation.** After a level, the game counts the score and rates the result.

**Formula.**

```text
score = enemies * 10 + coins * 5
```

**Rules.**

- If the player found the secret room, 50 is added to the score.
- If the score is 150 or more, the game prints "Excellent". If the score is 80 or more, the game prints "Good". Otherwise the game prints "Try again".

**Output.** The score.

**Example.** 8 enemies defeated, 12 coins collected, secret room not found. Output: "Good", 140.

**Think about it.**

1. 5 enemies defeated, 14 coins collected, secret room found. What rating will the player get?
2. What goes wrong if you check "80 or more" before "150 or more"?

### Task 16. Race

**Situation.** The character runs along a track at a constant speed.

**Formula.**

```text
distance = speed * time
```

**Rules.**

- If the distance is greater than or equal to the track length, the game prints "Finish".
- Otherwise the game prints "Remaining" and the remaining distance, which is the track length minus the distance.

**Output.** The distance covered.

**Example.** Speed 6, time 15, track length 100. Output: "Remaining", 10, 90.

**Think about it.**

1. Speed is 0. Can the character reach the finish?
2. Choose a speed and time so that the distance is exactly equal to a track length of 100. Which message will the game print?

### Task 17. Spell series

**Situation.** A mage wants to cast the same spell several times in a row.

**Formula.**

```text
mana needed = spell cost * quantity
```

**Rules.**

- If there is enough mana for the whole series, mana decreases by the amount needed and the game prints "Series complete". If less than 10 mana is left after the series, the game prints "Low mana".
- If there is not enough mana for the whole series, the mage casts no spells at all. The game prints "Not enough mana", and mana does not change.

**Output.** Mana.

**Example.** Mana 100, spell cost 15, quantity 4. Output: "Series complete", 40.

**Think about it.**

1. Mana 50, cost 20, quantity 3. What will the game print?
2. The quantity is 0. What will the game print, and why?

### Task 18. Hitting armor

**Situation.** The character hits an armored enemy. Each point of armor absorbs 2 points of damage.

**Formula.**

```text
damage = attack - armor * 2
```

**Rules.**

- Damage cannot be less than 1.
- If the enemy has no armor, the game prints "Enemy has no armor".
- Damage is subtracted from the enemy's health. Health cannot drop below 0. If it becomes 0, the game prints "Enemy defeated".

**Output.** Damage and the enemy's health.

**Example.** Attack 30, armor 8, enemy health 50. Output: 14, 36.

**Think about it.**

1. What damage would you get in the example if you mistakenly subtracted first and multiplied second? What would the formula mean then?
2. Attack 10, armor 6. How much damage will the enemy take?

### Task 19. Selling loot

**Situation.** The character sells identical items collected in a dungeon to a merchant.

**Formula.**

```text
coins = coins + number of items * price of one item
```

**Rules.**

- If more than 10 items are sold, the merchant pays 1 coin less for each item. The price of one item cannot drop below 1.
- If the character has 500 coins or more after the sale, the game prints "Rich".

**Output.** Coins.

**Example.** 120 coins, 12 items sold at a price of 5. Output: 168.

**Think about it.**

1. Exactly 10 items are sold. Does the merchant lower the price?
2. For which data does the "price not below 1" rule change the result? Give an example.

### Task 20. Battle experience

**Situation.** After a battle, the character gains experience for the defeated opponents.

**Formula.** A regular enemy gives 20 experience, and a boss gives 100:

```text
experience = experience + enemies * 20 + bosses * 100
```

**Rules.**

- A new level requires 500 experience. If experience is 500 or more, the level goes up by 1, 500 is subtracted from experience, and the game prints "Level up". One battle can give only one level.
- If at least one boss was defeated, the game prints "Boss defeated".

**Output.** Level and experience.

**Example.** Level 2, experience 300, 6 enemies and 1 boss defeated. Output: "Level up", "Boss defeated", 3, 20.

**Think about it.**

1. Experience 480, 1 enemy defeated, no bosses. Will there be a new level?
2. How can you check "at least one boss" in pseudocode with a comparison?

## Report

Write the report in Microsoft Word using the template [`report-template-en.docx`](./report-template-en.docx) and submit it as a single `.docx` file. Fill in the title page. Text in square brackets in the template is a hint: replace it with your own text and delete the hints.

For each of your two tasks, the report contains:

1. The task number, its title, and its text.
2. The problem analysis: inputs, output, and answers to the "Think about it" questions.
3. The pseudocode.
4. The flowchart.
5. The data sets with expected results and the trace tables.
6. A description of any mistakes you found and fixed.

Any completed `[extra]` tasks and the conclusions go at the end of the report.

## Grading criteria

- The algorithm gives the correct result for all data sets.
- The inputs are identified correctly.
- The answers to the "Think about it" questions are correct.
- The pseudocode and the flowchart match each other, with the same order of steps and the same names.
- The data sets go through every branch of the algorithm and include boundary cases.
- The trace tables are filled in correctly.

## Review questions

1. Which properties of an algorithm does the instruction "deal enough damage to the enemy" break?
2. Why can the assignment `SET health = health - damage` not be read as a mathematical equation?
3. How can you tell inputs apart from game rules when reading a task?
4. How is a boundary case different from a normal case, and why should it be checked separately?
5. How can a trace table help you find the step where an algorithm started to go wrong?
6. Pick two steps in one of your tasks whose order matters. What changes if you swap them?
